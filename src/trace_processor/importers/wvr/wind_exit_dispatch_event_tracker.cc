#include "src/trace_processor/importers/wvr/wind_exit_dispatch_event_tracker.h"

#include <cstddef>
#include <cstdint>
#include <limits>
#include <optional>

#include "perfetto/base/logging.h"
#include "perfetto/ext/base/string_view.h"
#include "perfetto/public/compiler.h"
#include "src/trace_processor/importers/common/args_tracker.h"
#include "src/trace_processor/importers/common/event_tracker.h"
#include "src/trace_processor/importers/common/process_tracker.h"
#include "src/trace_processor/importers/common/sched_event_state.h"
#include "src/trace_processor/importers/common/sched_event_tracker.h"
#include "src/trace_processor/importers/common/system_info_tracker.h"
#include "src/trace_processor/importers/common/thread_state_tracker.h"
#include "src/trace_processor/importers/ftrace/ftrace_descriptors.h"
#include "src/trace_processor/storage/stats.h"
#include "src/trace_processor/storage/trace_storage.h"
#include "src/trace_processor/tables/metadata_tables_py.h"
#include "src/trace_processor/types/task_state.h"
#include "src/trace_processor/types/trace_processor_context.h"
#include "src/trace_processor/types/variadic.h"

namespace perfetto::trace_processor {

WindExitDispatchTracker::WindExitDispatchTracker(TraceProcessorContext* context)
    : context_(context) {}

WindExitDispatchTracker::~WindExitDispatchTracker() = default;

void WindExitDispatchTracker::PushSchedSwitch(uint32_t cpu,
                                              int64_t ts,
                                              uint32_t next_tid,
                                              uint32_t next_pid,
                                              int32_t next_prio) {
  UniqueTid next_utid =
      context_->process_tracker->UpdateThread(next_tid, next_pid);

  // If we're processing the first compact event for this cpu, don't start a
  // slice since we're missing the "prev_*" fields. The successive events will
  // create slices as normal, but the first per-cpu switch is effectively
  // discarded.
  auto* pending_sched = sched_event_state_.GetPendingSchedInfoForCpu(cpu);
  if (pending_sched->last_utid == std::numeric_limits<UniqueTid>::max()) {
    context_->storage->IncrementStats(stats::compact_sched_switch_skipped);

    pending_sched->last_pid = next_pid;
    pending_sched->last_utid = next_utid;
    pending_sched->last_prio = next_prio;
    // Note: no pending slice, so leave |pending_slice_storage_idx| in its
    // invalid state.
    return;
  }

  // Close the pending slice if any (we won't have one when processing the first
  // two compact events for a given cpu).
  uint32_t pending_slice_idx = pending_sched->pending_slice_storage_idx;

  StringId prev_state_str_id = StringId::Raw(0);

  if (pending_slice_idx != std::numeric_limits<uint32_t>::max()) {
    context_->sched_event_tracker->ClosePendingSlice(pending_slice_idx, ts,
                                                     prev_state_str_id);
  }

  // Use the previous event's values to infer this event's "prev_*" fields.
  // There are edge cases, but this assumption should still produce sensible
  // results in the absence of data loss.
  UniqueTid prev_utid = pending_sched->last_utid;

  // Do a fresh task name lookup in case it was updated by a task_rename while
  // scheduled.
  context_->storage->thread_table()[prev_utid].name().value_or(kNullStringId);

  // Update the info for the next sched switch on this CPU.
  pending_sched->last_pid = next_pid;
  pending_sched->last_utid = next_utid;
  pending_sched->last_prio = next_prio;

  // Update per-cpu Sched table.
  auto new_slice_idx = context_->sched_event_tracker->AddStartSlice(
      cpu, ts, next_utid, next_prio);
  pending_sched->pending_slice_storage_idx = new_slice_idx;

  // Update the per-thread ThreadState table.
  ThreadStateTracker::GetOrCreate(context_)->PushSchedSwitchEvent(
      ts, cpu, prev_utid, prev_state_str_id, next_utid);
}

}  // namespace perfetto::trace_processor
