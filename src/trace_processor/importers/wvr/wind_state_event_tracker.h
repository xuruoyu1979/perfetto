// case EVENT_WINDUNDELAY:
// case EVENT_WINDTICKUNDELAY:
// case EVENT_WINDTICKTIMEOUT: {
//   //
//   // clear the pend and delay bits in the context's status word
//   // and stash a STATECHANGE event in the context's eventList to
//   // record the transition.
//   //
//   int newTaskId = event.data[0];
//   m_pParser->stateChangeEventWrite(WIND_DELAY | WIND_PEND, 0, newTaskId,
//                                    event.timeStamp);

//   // Store the event
//   storeEvent(event);
//   break;
// }
// case EVENT_WINDPENDQGET:
// case EVENT_WINDPENDQFLUSH:
// case EVENT_WINDPENDQTERMINATE: {
//   //
//   // create a pseudo event for the task that was made ready
//   // and stash it on the event stack, so the level3 event
//   // will time stamp it and put it in the correct context.
//   // The current state of the context might be unknown,
//   // so we make sure we clear those bits too.
//   //
//   int newTaskId = event.data[0];

//   m_pParser->stateChangeEventWrite(WIND_PEND | WIND_STATE_UNKNOWN, 0, newTaskId,
//                                    event.timeStamp);

//   break;
// }
// case EVENT_WINDPENDQPUT: {
//   // mark the current context as pended

//   UINT32 newState = (stateGet() & ~WIND_PEND) | WIND_PEND;

//   statechangeEventWrite(newState, event.timeStamp);

//   setPendState(true);  // set the flag to indicate WINDPENDQPUT
//   break;
// }

// case EVENT_WINDSPAWN: {
//   UINT32 newTaskId = event.data[0];
//   UINT32 priority = event.data[1];

//   // create a state-change event for the newly spawned task
//   // to let the query mechanism figure out its state, and
//   // stash the pseudo event on the event stack so it will
//   // get time stamped when the WINDEXIT occurs
//   m_pParser->stateChangeEventWrite(WIND_ALL_STATES, WIND_SUSPEND, newTaskId,
//                                    event.timeStamp);

//   break;
// }

// case EVENT_WINDDELETE: {
//   UINT32 newTaskId = event.data[0];

//   // the context will be marked WIND_DEAD when the eventAdd
//   // notices the STATE_CHANGE event. Create a state-change
//   // event for the deleted task to let the query mechanism
//   // figure out its state, and stash it on the event stack
//   // so it will get time stamped when the WINDEXIT occurs.
//   m_pParser->stateChangeEventWrite(WIND_ALL_STATES, WIND_DEAD, newTaskId,
//                                    event.timeStamp);
//   break;
// }

// case EVENT_WINDSUSPEND: {
//   UINT32 newTaskId = event.data[0];

//   // create a state-change event for the suspended task to
//   // let the query mechanism figure out its state, and stash
//   // it on the event stack so it will get time stamped when
//   // the WINDEXIT occurs.
//   m_pParser->stateChangeEventWrite(WIND_SUSPEND, WIND_SUSPEND, newTaskId,
//                                    event.timeStamp);

//   break;
// }

// case EVENT_WINDRESUME: {
//   UINT32 newTaskId = event.data[0];

//   // create a state-change event for the resumed task to let
//   // the query mechanism figure out its state, and stash it
//   // on the event stack so it will get time stamped when the
//   // WINDEXIT occurs.
//   m_pParser->stateChangeEventWrite(WIND_SUSPEND, 0, newTaskId, event.timeStamp);

//   break;
// }

// case EVENT_WINDSTOP: {
//   UINT32 newTaskId = event.data[0];

//   // create a state-change event for the stopped task to
//   // let the query mechanism figure out its state, and stash
//   // it on the event stack so it will get time stamped when
//   // the WINDEXIT occurs.
//   m_pParser->stateChangeEventWrite(WIND_BREAK, WIND_BREAK, newTaskId,
//                                    event.timeStamp);

//   break;
// }

// case EVENT_WINDCONT: {
//   UINT32 newTaskId = event.data[0];

//   // create a state-change event for the continued task to let
//   // the query mechanism figure out its state, and stash it
//   // on the event stack so it will get time stamped when the
//   // WINDEXIT occurs.
//   m_pParser->stateChangeEventWrite(WIND_BREAK, 0, newTaskId, event.timeStamp);

//   break;
// }

// case EVENT_WINDPRIORITYSETRAISE: {
//   UINT32 newTaskId = event.data[0];
//   UINT32 oldPri = event.data[1];
//   UINT32 newPri = event.data[2];

//   /* indicate inherited priority start */

//   m_pParser->stateChangeEventWrite(WIND_INHERITED, WIND_INHERITED, newTaskId,
//                                    event.timeStamp);

//   break;
// }

// case EVENT_WINDPRIORITYSETLOWER: {
//   UINT32 newTaskId = event.data[0];
//   UINT32 oldPri = event.data[1];
//   UINT32 newPri = event.data[2];

//   m_pParser->stateChangeEventWrite(WIND_INHERITED, 0, newTaskId,
//                                    event.timeStamp);

//   break;
// }

// case EVENT_WINDDELAY: {
//   UINT32 newState = (stateGet() & ~WIND_DELAY) | WIND_DELAY;

//   statechangeEventWrite(newState, event.timeStamp);

//   setDelayState(true);  // set the flag to indicate WINDDELAY

//   break;
// }