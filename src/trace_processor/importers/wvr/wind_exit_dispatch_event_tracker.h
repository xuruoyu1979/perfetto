#ifndef SRC_TRACE_PROCESSOR_IMPORTERS_WVR_WIND_EXIT_DISPATCH_EVENT_TRACKER_H_
#define SRC_TRACE_PROCESSOR_IMPORTERS_WVR_WIND_EXIT_DISPATCH_EVENT_TRACKER_H_

#include <cstdint>

#include <array>

#include "perfetto/ext/base/string_view.h"
#include "src/trace_processor/importers/common/sched_event_state.h"
#include "src/trace_processor/storage/trace_storage.h"
#include "src/trace_processor/types/destructible.h"
#include "src/trace_processor/types/trace_processor_context.h"

namespace perfetto {
namespace trace_processor {

class EventTracker;

// Tracks sched events and stores them into the storage as sched slices.
class WindExitDispatchTracker : public Destructible {
 public:
  explicit WindExitDispatchTracker(TraceProcessorContext*);
  ~WindExitDispatchTracker() override;

  WindExitDispatchTracker(const WindExitDispatchTracker&) = delete;
  WindExitDispatchTracker& operator=(const WindExitDispatchTracker&) = delete;

  static WindExitDispatchTracker* GetOrCreate(TraceProcessorContext* context) {
    if (!context->wind_exit_dispatch_tracker) {
      context->wind_exit_dispatch_tracker.reset(
          new WindExitDispatchTracker(context));
    }
    return static_cast<WindExitDispatchTracker*>(
        context->wind_exit_dispatch_tracker.get());
  }

  // This method is called when a sched_switch event is seen in the trace.
  // Virtual for testing.
  virtual void PushSchedSwitch(uint32_t cpu,
                               int64_t ts,
                               int64_t prev_state,
                               uint32_t next_tid,
                               uint32_t next_pid,
                               int32_t next_prio);

 private:

  TraceProcessorContext* const context_;

  SchedEventState sched_event_state_;
};

}  // namespace trace_processor
}  // namespace perfetto

#endif  // SRC_TRACE_PROCESSOR_IMPORTERS_WVR_WIND_EXIT_DISPATCH_EVENT_TRACKER_H_
