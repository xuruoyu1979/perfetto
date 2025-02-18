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

#ifndef SRC_TRACE_PROCESSOR_IMPORTERS_WVR_WVR_PARSER_H_
#define SRC_TRACE_PROCESSOR_IMPORTERS_WVR_WVR_PARSER_H_

#include <cstdint>
#include <string>
#include <vector>

#include "perfetto/base/status.h"
#include "src/trace_processor/importers/common/chunked_trace_reader.h"
#include "src/trace_processor/importers/common/trace_parser.h"

namespace perfetto::trace_processor {

class TraceProcessorContext;

// This class parses windriver System Viewer's trace file, aka .wvr file.
class WvrParser : public ChunkedTraceReader {
 public:
  explicit WvrParser(TraceProcessorContext*);
  ~WvrParser() override;
  WvrParser(const WvrParser&) = delete;
  WvrParser& operator=(const WvrParser&) = delete;

  // ChunkedTraceReader implementation
  base::Status Parse(TraceBlobView) override;
  base::Status NotifyEndOfFile() override;

 private:
  TraceProcessorContext* const ctx_;
  // bool header_parsed_ = false;
  std::vector<char> log_;
};

struct ProcessContext {
  uint64_t tid;
  uint64_t priority;
};

}  // namespace perfetto::trace_processor

#endif  // SRC_TRACE_PROCESSOR_IMPORTERS_WVR_WVR_PARSER_H_
