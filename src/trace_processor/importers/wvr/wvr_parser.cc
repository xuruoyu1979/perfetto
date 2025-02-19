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

std::map<string, uint64_t>
    findedInterruptOnCpu;  // key is int_num/core_num, value is int_num
std::map<uint64_t, ProcessContext> currentContextOnCpu;

std::map<uint64_t, vector<ProcessContext>>
    prevContextOnCpu;  // store the prev context when interrupted, will schedule
                       // to it when int exit.

const uint64_t DEFAULT_INT_PRIORITY = 99;

vector<uint8_t> cache;

int16_t currentCpuId = 0;
int64_t lastTimeStamp = 0;
uint64_t m_prevTicks = 0;

int32_t timestampFreq = 0;
uint32_t timestampPeriod = 0;
int32_t autoRollover = 0;
int32_t clkRate = 0;

uint64_t time = 0;

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

      time = (static_cast<double>(lastTimeStamp) /
              static_cast<double>(timestampFreq)) *
             1000 * 1000;
    }

    if (event.getId() == 16) {  // EVENT_RTPNAME
      uint64_t rtpId = 0;
      string name = "";
      for (auto param : event.getParams()) {
        vector<uint8_t> payload = param.getPayload();
        if (param.getName() == "name") {
          name = reader.toPrintableString(payload);
        } else if (param.getName() == "rtpId") {
          rtpId = reader.readUINT(param);
        }
      }
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

    } else if (event.getId() == 102) {  // EVENT_INT_ENT_
      if (currentContextOnCpu.find(currentCpuId) != currentContextOnCpu.end()) {
        uint64_t intNum = 0;
        for (auto param : event.getParams()) {
          vector<uint8_t> payload = param.getPayload();
          if (param.getName() == "intNum") {
            intNum = reader.readUINT(param);
          }
        }

        string currentIntOnCpu =
            to_string(intNum) + "/" + to_string(currentCpuId);

        // tid use (coreNum + 80000), pid use (intNum + 90000).
        uint64_t rtpId = intNum + 80000;
        uint64_t tid = currentCpuId + 90000;
        tid_pid_map[tid] = rtpId;

        if (findedInterruptOnCpu.find(currentIntOnCpu) ==
            findedInterruptOnCpu.end()) {
          string intName = "Interrupt-" + to_string(intNum);
          ctx_->process_tracker->SetProcessNameIfUnset(
              ctx_->process_tracker->GetOrCreateProcess(rtpId),
              ctx_->storage->InternString(intName));

          auto utid = ctx_->process_tracker->UpdateThread(tid, rtpId);

          StringId name_id = ctx_->storage->InternString(currentIntOnCpu);
          ctx_->process_tracker->UpdateThreadNameByUtid(
              utid, name_id, ThreadNamePriority::kOther);
        } else {  // same intNum enter again before int exit.

          // in case we must have prevContext.size > 0
          vector<ProcessContext> prevCtxStack = prevContextOnCpu[currentCpuId];
          tid = currentCpuId + 90000 + prevCtxStack.size() * 1000;
          auto utid = ctx_->process_tracker->UpdateThread(tid, rtpId);

          StringId name_id = ctx_->storage->InternString(
              currentIntOnCpu + ":" + to_string(prevCtxStack.size()));
          ctx_->process_tracker->UpdateThreadNameByUtid(
              utid, name_id, ThreadNamePriority::kOther);
        }

        vector<ProcessContext> prevCtxStack = prevContextOnCpu[currentCpuId];

        prevCtxStack.push_back(currentContextOnCpu[currentCpuId]);

        findedInterruptOnCpu[currentIntOnCpu] = intNum;

        ProcessContext procCtx = {intNum, DEFAULT_INT_PRIORITY};
        currentContextOnCpu[currentCpuId] = procCtx;

        WindExitDispatchTracker* wind_exit_dispatch_tracker =
            WindExitDispatchTracker::GetOrCreate(ctx_);
        wind_exit_dispatch_tracker->PushSchedSwitch(
            currentCpuId, time, tid, tid_pid_map[tid], DEFAULT_INT_PRIORITY);
      }
    } else if (event.getId() == 101) {  // EVENT_INT_EXIT
      if (prevContextOnCpu.find(currentCpuId) != prevContextOnCpu.end()) {
        vector<ProcessContext> procCtxStack = prevContextOnCpu[currentCpuId];
        if (!procCtxStack.empty()) {
          ProcessContext procCtx = procCtxStack.back();
          currentContextOnCpu[currentCpuId] = procCtx;

          WindExitDispatchTracker* wind_exit_dispatch_tracker =
              WindExitDispatchTracker::GetOrCreate(ctx_);
          wind_exit_dispatch_tracker->PushSchedSwitch(
              currentCpuId, time, procCtx.tid, tid_pid_map[procCtx.tid],
              procCtx.priority);

          procCtxStack.pop_back();
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
      ProcessContext procCtx = {tid, priority};
      currentContextOnCpu[currentCpuId] = procCtx;

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
