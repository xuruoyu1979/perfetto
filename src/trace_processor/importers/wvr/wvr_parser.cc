/*
 * Copyright (C) 2020 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "src/trace_processor/importers/wvr/wvr_parser.h"
#include "src/trace_processor/importers/wvr/wind_exit_dispatch_event_tracker.h"
#include "src/trace_processor/importers/wvr/wvrLib.h"

#include <algorithm>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>

#include <string.h>
#include "perfetto/base/status.h"
#include "perfetto/ext/base/string_splitter.h"
#include "perfetto/ext/base/string_utils.h"
#include "perfetto/ext/base/string_view.h"
#include "perfetto/trace_processor/trace_blob_view.h"
#include "src/trace_processor/importers/common/cpu_tracker.h"
#include "src/trace_processor/importers/common/process_tracker.h"
#include "src/trace_processor/importers/common/sched_event_tracker.h"
#include "src/trace_processor/importers/common/slice_tracker.h"
#include "src/trace_processor/importers/common/track_tracker.h"
#include "src/trace_processor/storage/stats.h"
#include "src/trace_processor/storage/trace_storage.h"

namespace perfetto::trace_processor {

using base::StringSplitter;
using namespace wvrlib;

WvrParser::WvrParser(TraceProcessorContext* ctx) : ctx_(ctx) {}
WvrParser::~WvrParser() = default;

bool firstParseCall = true;
int total_events = 0;

bool isLittleEndian = false;
uint32_t revisionId = 0;

std::map<uint64_t, Event> module_map;
std::map<uint64_t, uint64_t> tid_pid_map;

vector<uint8_t> cache;

int16_t currentCpuId = 0;
int64_t lastTimeStamp = 0;
uint64_t m_prevTicks = 0;

int32_t timestampFreq = 0;
uint32_t timestampPeriod = 0;
int32_t autoRollover = 0;
int32_t clkRate = 0;

base::Status WvrParser::Parse(TraceBlobView blob) {
  // const char* src = reinterpret_cast<const char*>(blob.data());

  uint32_t readedBytes = 0;
  const char* origSrc = reinterpret_cast<const char*>(blob.data());

  if (firstParseCall) {
    // check if is little endian and get revisionId.
    uint8_t magic[2];
    memcpy(magic, origSrc, sizeof(magic));

    if (magic[0] == 0x04 && magic[1] == 0x00) {
      isLittleEndian = true;
    }

    uint8_t revisionPayload[4];
    memcpy(revisionPayload, origSrc + 2, sizeof(revisionPayload));
    if (isLittleEndian) {
      revisionId = static_cast<uint32_t>(
          (revisionPayload[3] << 24) | (revisionPayload[2] << 16) |
          (revisionPayload[1] << 8) | revisionPayload[0]);
    } else {
      revisionId = static_cast<uint32_t>(
          (revisionPayload[0] << 24) | (revisionPayload[1] << 16) |
          (revisionPayload[2] << 8) | revisionPayload[3]);
    }
    firstParseCall = false;
  }

  // add cache from last parse before blob if have any.
  size_t totalLength = cache.size() + blob.size();
  char* src;
  if (cache.size() > 0) {
    src = new char[totalLength];
    memcpy(src, cache.data(), cache.size());
    for (size_t i = 0; i < blob.size(); ++i) {
      src[cache.size() + i] = origSrc[i];
    }
    cache.clear();
  } else {
    src = const_cast<char*>(origSrc);
  }

  WVRFileReader reader(0, totalLength, isLittleEndian, revisionId);

  while (reader.parseEvent(src)) {
    Event event = reader.getCurrentEvent();
    uint32_t currentEventSize = reader.getCurrentEventSize();
    readedBytes = readedBytes + currentEventSize;

    if (readedBytes > totalLength) {
      int leftBytes = totalLength - (readedBytes - currentEventSize);
      cout << "Readed Bytes " << readedBytes << " is great than " << totalLength
           << " currentEventSize=" << currentEventSize << " put " << leftBytes
           << " into cache." << std::endl;
      for (int i = 0; i < leftBytes; i++) {
        cache.push_back(src[totalLength - leftBytes + i]);
      }
    }

    if (event.hasTimeStamp()) {
      uint64_t ticks = event.getTicks();
      // determine whether the timer has rolled round
      if (ticks >= m_prevTicks) {
        lastTimeStamp = lastTimeStamp + (ticks - m_prevTicks);
      } else {
        lastTimeStamp = lastTimeStamp + ticks + timestampPeriod - m_prevTicks;
      }

      m_prevTicks = ticks;
    }

    if (event.getId() == 20) {  // EVENT_MODULE_MAP
      uint64_t rtpId = 0;
      string name = "";
      for (auto param : event.getParams()) {
        vector<uint8_t> payload = param.getPayload();
        if (param.getName() == "fileName") {
          name = reader.toPrintableString(payload);
        } else if (param.getName() == "RtpId") {
          rtpId = reader.readUINT(param);
        }
      }
      // std::cout << "Set RTP Name=" << name << " id=" << rtpId << std::endl;
      ctx_->process_tracker->SetProcessNameIfUnset(
          ctx_->process_tracker->GetOrCreateProcess(rtpId),
          ctx_->storage->InternString(name));
    } else if (event.getId() == 8) {  // EVENT_TIMESTAMP_CONFIG
      for (auto param : event.getParams()) {
        vector<uint8_t> payload = param.getPayload();
        if (param.getName() == "timestampFreq") {
          timestampFreq = reader.readUINT(param);
        } else if (param.getName() == "timestampPeriod") {
          timestampPeriod = reader.readUINT(param);
        } else if (param.getName() == "autoRollover") {
          autoRollover = reader.readUINT(param);
        } else if (param.getName() == "clkRate") {
          clkRate = reader.readUINT(param);
        }
      }
    } else if (event.getId() == 10) {  // EVENT_CPU_ID
      for (auto param : event.getParams()) {
        vector<uint8_t> payload = param.getPayload();
        if (param.getName() == "cpuId") {
          currentCpuId = reader.readUINT(param);
        }
      }
    } else if (event.getId() == 52) {  // EVENT_WIND_EXIT_DISPATCH

      uint64_t tid = 0;
      uint64_t priority = 0;

      for (auto param : event.getParams()) {
        vector<uint8_t> payload = param.getPayload();
        if (param.getName() == "tid") {
          tid = reader.readUINT(param);
        } else if (param.getName() == "priority") {
          priority = reader.readUINT(param);
        }
      }
      uint64_t time = (static_cast<double>(lastTimeStamp) /
                       static_cast<double>(timestampFreq)) *
                      1000 * 1000;

      WindExitDispatchTracker* wind_exit_dispatch_tracker =
          WindExitDispatchTracker::GetOrCreate(ctx_);
      wind_exit_dispatch_tracker->PushSchedSwitch(currentCpuId, time, tid,
                                                  tid_pid_map[tid], priority);

    } else if (event.getId() == 3) {  // EVENT_TASKNAME
      uint64_t taskId = 0;
      uint64_t rtpId = 0;
      int64_t cpuIndex = 0;
      string name = "";
      vector<uint8_t> taskIdpayload;
      for (auto param : event.getParams()) {
        vector<uint8_t> payload = param.getPayload();
        if (param.getName() == "name") {
          name = reader.toPrintableString(payload);
        } else if (param.getName() == "taskId") {
          taskId = reader.readUINT(param);
        } else if (param.getName() == "rtpId") {
          rtpId = reader.readUINT(param);
        } else if (param.getName() == "cpuIndex") {
          cpuIndex = reader.readUINT(param);
        }
      }
      tid_pid_map[taskId] = rtpId;
      ctx_->process_tracker->GetOrCreateProcess(rtpId);
      auto utid = ctx_->process_tracker->UpdateThread(taskId, rtpId);

      StringId name_id = ctx_->storage->InternString(name);
      ctx_->process_tracker->UpdateThreadNameByUtid(utid, name_id,
                                                    ThreadNamePriority::kOther);
    }
    total_events++;
  }

  std::cout << "trunk size=" << totalLength << " total_events=" << total_events
            << std::endl;

  return base::OkStatus();
}

// This is called after the last Parse() call. At this point all |jobs_| have
// been populated.
base::Status WvrParser::NotifyEndOfFile() {
  return base::OkStatus();
}

}  // namespace perfetto::trace_processor
