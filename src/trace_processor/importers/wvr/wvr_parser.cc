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

#include <algorithm>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>

#include "perfetto/base/status.h"
#include "perfetto/ext/base/string_splitter.h"
#include "perfetto/ext/base/string_utils.h"
#include "perfetto/ext/base/string_view.h"
#include "perfetto/trace_processor/trace_blob_view.h"
#include "src/trace_processor/importers/common/process_tracker.h"
#include "src/trace_processor/importers/common/slice_tracker.h"
#include "src/trace_processor/importers/common/track_tracker.h"
#include "src/trace_processor/storage/stats.h"
#include "src/trace_processor/storage/trace_storage.h"

namespace perfetto::trace_processor {

using base::StringSplitter;

WvrParser::WvrParser(TraceProcessorContext* ctx) : ctx_(ctx) {}
WvrParser::~WvrParser() = default;

base::Status WvrParser::Parse(TraceBlobView blob) {
  // const char* src = reinterpret_cast<const char*>(blob.data());
  std::cout << "wvr file sizel is" << blob.size() << std::endl;

  ctx_->process_tracker->SetProcessNameIfUnset(
      ctx_->process_tracker->GetOrCreateProcess(100),
      ctx_->storage->InternString("Fake Process"));
  auto utid =
      ctx_->process_tracker->UpdateThread(100001, 100);

  base::StackString<32> name("Fake Thread");
  StringId name_id = ctx_->storage->InternString(name.string_view());
  ctx_->process_tracker->UpdateThreadNameByUtid(utid, name_id,
                                                ThreadNamePriority::kOther);
  TrackId track_id = ctx_->track_tracker->InternThreadTrack(utid);

  ctx_->slice_tracker->Scoped(10, track_id, StringId::Null(),
                                name_id, 200);
  return base::OkStatus();
}

// This is called after the last Parse() call. At this point all |jobs_| have
// been populated.
base::Status WvrParser::NotifyEndOfFile() {
  return base::OkStatus();
}

}  // namespace perfetto::trace_processor
