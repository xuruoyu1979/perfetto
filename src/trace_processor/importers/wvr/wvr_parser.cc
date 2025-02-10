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
#include "src/trace_processor/importers/common/sched_event_tracker.h"
#include "src/trace_processor/importers/common/process_tracker.h"
#include "src/trace_processor/importers/common/slice_tracker.h"
#include "src/trace_processor/importers/common/track_tracker.h"
#include "src/trace_processor/storage/stats.h"
#include "src/trace_processor/storage/trace_storage.h"

namespace perfetto::trace_processor {

using base::StringSplitter;
using namespace wvrlib;

WvrParser::WvrParser(TraceProcessorContext* ctx) : ctx_(ctx) {}
WvrParser::~WvrParser() = default;

base::Status WvrParser::Parse(TraceBlobView blob) {
  // const char* src = reinterpret_cast<const char*>(blob.data());

  int total_events = 0;
  const char* src = reinterpret_cast<const char*>(blob.data());

  // check if is little endian.
  uint8_t magic[2];
  memcpy(magic, src, sizeof(magic));
  bool isLittleEndian = false;
  if (magic[0] == 0x04 && magic[1] == 0x00) {
    isLittleEndian = true;
  }

  WVRFileReader reader(0, blob.size(), isLittleEndian);

  std::map<uint64_t, Event> module_map;

  vector<Event> eventCache;

  bool isFirstTick = true;
  int16_t currentCpuId = 0;
  int64_t currentTicks = 0;
  int64_t firstTicks = 0;
  // int64_t prevTicks = 0;

  while (reader.parseEvent(src)) {
    Event event = reader.getCurrentEvent();
    int64_t ticks = event.getTicks();
    if (ticks != 0 && isFirstTick) {
      firstTicks = ticks;
      isFirstTick = false;
    }
    if (ticks != 0) {
      currentTicks = currentTicks + ticks;
    }

    if (event.getId() == 20) {  // EVENT_MODULE_MAP
      uint64_t rtpId = 0;
      string name = "";
      for (auto param : event.getParams()) {
        vector<uint8_t> payload = param.getPayload();
        if (param.getName() == "fileName") {
          name = string(payload.begin(), payload.end());
        } else if (param.getName() == "RtpId") {
          uint8_t bytes[8];
          memcpy(bytes, payload.data(), 8);
          rtpId = reader.readUINT64(bytes);
        }
      }
      std::cout << "Set RTP Name=" << name << " id=" << rtpId << std::endl;
      ctx_->process_tracker->SetProcessNameIfUnset(
          ctx_->process_tracker->GetOrCreateProcess(rtpId),
          ctx_->storage->InternString(name));
    } else if (event.getId() == 10) {  // EVENT_CPU_ID
      for (auto param : event.getParams()) {
        vector<uint8_t> payload = param.getPayload();
        if (param.getName() == "cpuId") {
          uint8_t bytes[2];
          memcpy(bytes, payload.data(), 2);
          currentCpuId = reader.readUINT16(bytes);
        }
      }
    } else if (event.getId() == 52) {  // EVENT_WIND_EXIT_DISPATCH

      uint64_t tid = 0;
      uint64_t priority = 0;

      for (auto param : event.getParams()) {
        vector<uint8_t> payload = param.getPayload();
        if (param.getName() == "tid") {
          uint8_t bytes[8];
          memcpy(bytes, payload.data(), 8);
          tid = reader.readUINT64(bytes);
        } else if (param.getName() == "priority") {
          uint8_t bytes[8];
          memcpy(bytes, payload.data(), 8);
          priority = reader.readUINT64(bytes);
        }
      }

      ctx_->sched_event_tracker->AddStartSlice(
          currentCpuId, currentTicks, tid, priority);

    } else if (event.getId() == 3) {  // EVENT_TASKNAME
      uint64_t taskId = 0;
      uint64_t rtpId = 0;
      int64_t cpuIndex = 0;
      string name = "";
      for (auto param : event.getParams()) {
        vector<uint8_t> payload = param.getPayload();
        if (param.getName() == "name") {
          name = string(payload.begin(), payload.end());
        } else if (param.getName() == "taskId") {
          uint8_t bytes[8];
          memcpy(bytes, payload.data(), 8);
          taskId = reader.readUINT64(bytes);
        } else if (param.getName() == "rtpId") {
          uint8_t bytes[8];
          memcpy(bytes, payload.data(), 8);
          rtpId = reader.readUINT64(bytes);
        } else if (param.getName() == "cpuIndex") {
          uint8_t bytes[8];
          memcpy(bytes, payload.data(), 8);
          cpuIndex = reader.readUINT64(bytes);
        }
      }

      ctx_->process_tracker->GetOrCreateProcess(rtpId);
      auto utid = ctx_->process_tracker->UpdateThread(taskId, rtpId);

      StringId name_id = ctx_->storage->InternString(name);
      ctx_->process_tracker->UpdateThreadNameByUtid(utid, name_id,
                                                    ThreadNamePriority::kOther);
      TrackId track_id = ctx_->track_tracker->InternThreadTrack(utid);

      ctx_->slice_tracker->Scoped(10, track_id, StringId::Null(), name_id, 200);
    }
    total_events++;
  }

  std::cout << "wvr file size=" << blob.size()
            << " total_events=" << total_events << std::endl;

  return base::OkStatus();
}

// This is called after the last Parse() call. At this point all |jobs_| have
// been populated.
base::Status WvrParser::NotifyEndOfFile() {
  return base::OkStatus();
}

}  // namespace perfetto::trace_processor
