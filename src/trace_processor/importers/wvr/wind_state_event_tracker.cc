#include "src/trace_processor/importers/wvr/wind_state_event_tracker.h"

#include <cstddef>
#include <cstdint>
#include <limits>
#include <optional>

#include "perfetto/base/logging.h"
#include "perfetto/ext/base/string_view.h"
#include "perfetto/public/compiler.h"
#include "src/trace_processor/importers/common/args_tracker.h"
#include "src/trace_processor/importers/common/event_tracker.h"
#include "src/trace_processor/importers/common/system_info_tracker.h"
#include "src/trace_processor/importers/common/thread_state_tracker.h"
#include "src/trace_processor/storage/stats.h"
#include "src/trace_processor/storage/trace_storage.h"
#include "src/trace_processor/tables/metadata_tables_py.h"
#include "src/trace_processor/types/task_state.h"
#include "src/trace_processor/types/trace_processor_context.h"
#include "src/trace_processor/types/variadic.h"
#include "wind_state_event_tracker.h"

namespace perfetto::trace_processor {

WindStateEventTracker::WindStateEventTracker(TraceProcessorContext* context)
    : context_(context) {}

WindStateEventTracker::~WindStateEventTracker() = default;

StringId WindStateEventTracker::TaskStateToStringId(int64_t task_state_int) {
  const auto state = static_cast<uint8_t>(task_state_int);
  // Mapping for the different wind rtos states with their string description.
  std::map<uint8_t, base::StringView> wind_states_map = {
      {PEND, "Pend"},     // Pend
      {RUNNING, "Running"},         // Running
      {SUSPEND, "Suspend"},        // Suspend
      {DEAD, "Dead"},               // Dead
      {INHERITED, "Inherited"},         // Inherited
      {BREAK, "Break"},      // Break
      {DELAY, "Delay"},  // Delay
  };

  return wind_states_map.find(state) != wind_states_map.end()
             ? context_->storage->InternString(wind_states_map[state])
             : kNullStringId;
}

}

