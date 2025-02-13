#ifndef VXWORKS7_32_SMP_XML
#define VXWORKS7_32_SMP_XML

std::string v7_32_smp_apexlib_xml = R"delim(
<?xml version="1.0" encoding="UTF-8"?>
<!--
/* apexlib.xml */

/* Copyright 2003-2005, 2019 Wind River Systems, Inc. */

/*
modification history
====================
31jul19,zli  ported to 32 bit GOS (WB4-9477)
26jul19,zli  fix the order of event parameters(WB4-9461)
25jun19,zli  add 4 events: EVENT_APEX_xxxxMUTEX
11feb05,cjt  update help topic ids
21jan04,tcr  fix params for EVENT_APEX_CREATQPORT
17jan03,tcr  added mod history, add port events
*/
-->
<!DOCTYPE EventDictionary SYSTEM "../../DTDs/EventDictionary.dtd">
<EventDictionary>
    <EventClass key="apex" displayName="Apex Events" helpTopicId="VXWORKSAE653_apex_CLASS_HELP">
        <EventDescription id="10500" name="EVENT_APEX_CREATESEMA" trigger="false" displayName="apexSemCreate" icon="images/apexSemCreate.gif" helpTopicId="VXWORKSAE653_EVENT_APEX_CREATESEMA_EVENT_HELP">
            <EventParam type="UINT32" name="maxValue"/>
            <EventParam type="UINT32" name="currentValue"/>
            <EventParam type="UINT32" name="discipline"/>
            <EventParam type="UINT32" name="semId" formatStr="0x%08x"/>
        </EventDescription>
        <EventDescription id="10501" name="EVENT_APEX_WAITSEMA" trigger="false" displayName="apexSemWait" icon="images/apexSemWait.gif" helpTopicId="VXWORKSAE653_EVENT_APEX_WAITSEMA_EVENT_HELP">
            <EventParam type="UINT32" name="timeout"/>
            <EventParam type="UINT32" name="count"/>
            <EventParam type="UINT32" name="semId" formatStr="0x%08x"/>
        </EventDescription>
        <EventDescription id="10502" name="EVENT_APEX_SIGNALSEMA" trigger="false" displayName="apexSemSignal" icon="images/apexSemSignal.gif" helpTopicId="VXWORKSAE653_EVENT_APEX_SIGNALSEMA_EVENT_HELP">
            <EventParam type="UINT32" name="count"/>
            <EventParam type="UINT32" name="maxCount"/>
            <EventParam type="UINT32" name="semId" formatStr="0x%08x"/>
        </EventDescription>
        <EventDescription id="10503" name="EVENT_APEX_CREATEBUFFER" trigger="false" displayName="apexBufferCreate" icon="images/apexBuffCreate.gif" helpTopicId="VXWORKSAE653_EVENT_APEX_CREATEBUFFER_EVENT_HELP">
            <EventParam type="UINT32" name="discipline"/>
            <EventParam type="UINT32" name="messageSize"/>
            <EventParam type="UINT32" name="bufferSize"/>
            <EventParam type="UINT32" name="bufferId" formatStr="0x%08x"/>
        </EventDescription>
        <EventDescription id="10504" name="EVENT_APEX_SENDBUFFER" trigger="false" displayName="apexBufferSend" icon="images/apexBuffSend.gif" helpTopicId="VXWORKSAE653_EVENT_APEX_SENDBUFFER_EVENT_HELP">
            <EventParam type="UINT32" name="timeout"/>
            <EventParam type="UINT32" name="length"/>
            <EventParam type="UINT32" name="bufferId" formatStr="0x%08x"/>
        </EventDescription>
        <EventDescription id="10505" name="EVENT_APEX_RECEIVEBUFFER" trigger="false" displayName="apexBufferReceive" icon="images/apexBuffReceive.gif" helpTopicId="VXWORKSAE653_EVENT_APEX_RECEIVEBUFFER_EVENT_HELP">
            <EventParam type="UINT32" name="timeout"/>
            <EventParam type="UINT32" name="bufferId" formatStr="0x%08x"/>
        </EventDescription>
        <EventDescription id="10506" name="EVENT_APEX_CREATEEVENT" trigger="false" displayName="apexEventCreate" icon="images/apexEventCreate.gif" helpTopicId="VXWORKSAE653_EVENT_APEX_CREATEEVENT_EVENT_HELP">
            <EventParam type="UINT32" name="state"/>
            <EventParam type="UINT32" name="eventId" formatStr="0x%08x"/>
        </EventDescription>
        <EventDescription id="10507" name="EVENT_APEX_SETEVENT" trigger="false" displayName="apexEventSet" icon="images/apexEventSet.gif" helpTopicId="VXWORKSAE653_EVENT_APEX_SETEVENT_EVENT_HELP">
            <EventParam type="UINT32" name="state"/>
            <EventParam type="UINT32" name="eventId" formatStr="0x%08x"/>
        </EventDescription>
        <EventDescription id="10508" name="EVENT_APEX_RESETEVENT" trigger="false" displayName="apexEventReset" icon="images/apexEventReset.gif" helpTopicId="VXWORKSAE653_EVENT_APEX_RESETEVENT_EVENT_HELP">
            <EventParam type="UINT32" name="state"/>
            <EventParam type="UINT32" name="eventId" formatStr="0x%08x"/>
        </EventDescription>
        <EventDescription id="10509" name="EVENT_APEX_WAITTEVENT" trigger="false" displayName="apexEventWait" icon="images/apexEventWait.gif" helpTopicId="VXWORKSAE653_EVENT_APEX_WAITEVENT_EVENT_HELP">
            <EventParam type="UINT32" name="state"/>
            <EventParam type="UINT32" name="eventId" formatStr="0x%08x"/>
        </EventDescription>
        <EventDescription id="10510" name="EVENT_APEX_CREATEBLACKB" trigger="false" displayName="apexBlackboardCreate" icon="images/apexBlackboardCreate.gif" helpTopicId="VXWORKSAE653_EVENT_APEX_CREATEBLACKB_EVENT_HELP">
            <EventParam type="UINT32" name="msgSize"/>
            <EventParam type="UINT32" name="blackboardId" formatStr="0x%08x"/>
        </EventDescription>
        <EventDescription id="10511" name="EVENT_APEX_DISPLAYBLACKB" trigger="false" displayName="apexBlackboardDisplay" icon="images/apexBlackboardDisplay.gif" helpTopicId="VXWORKSAE653_EVENT_APEX_DISPLAYBLACKB_EVENT_HELP">
            <EventParam type="UINT32" name="msgSize"/>
            <EventParam type="UINT32" name="blackboardId" formatStr="0x%08x"/>
        </EventDescription>
        <EventDescription id="10512" name="EVENT_APEX_READBLACKB" trigger="false" displayName="apexBlackboardRead" icon="images/apexBlackboardRead.gif" helpTopicId="VXWORKSAE653_EVENT_APEX_READBLACKB_EVENT_HELP">
            <EventParam type="UINT32" name="state"/>
            <EventParam type="UINT32" name="timeout"/>
            <EventParam type="UINT32" name="blackboardId" formatStr="0x%08x"/>
        </EventDescription>
        <EventDescription id="10513" name="EVENT_APEX_CLEARBLACKB" trigger="false" displayName="apexBlackboardClear" icon="images/apexBlackboardClear.gif" helpTopicId="VXWORKSAE653_EVENT_APEX_CLEARBLACKB_EVENT_HELP">
            <EventParam type="UINT32" name="state"/>
            <EventParam type="UINT32" name="blackboardId" formatStr="0x%08x"/>
        </EventDescription>
        <EventDescription id="10514" name="EVENT_APEX_TIMEDWAIT" trigger="false" displayName="apexTimedWait" icon="images/apexTimedWait.gif" helpTopicId="VXWORKSAE653_EVENT_APEX_TIMEDWAIT_EVENT_HELP">
            <EventParam type="UINT32" name="ticks"/>
            <EventParam type="UINT32" name="procId" formatStr="0x%08x"/>
        </EventDescription>
        <EventDescription id="10515" name="EVENT_APEX_PERIODICWAIT" trigger="false" displayName="apexPeriodicWait" icon="images/apexPeriodicWait.gif" helpTopicId="VXWORKSAE653_EVENT_APEX_PERIODICWAIT_EVENT_HELP">
            <EventParam type="UINT32" name="procId" formatStr="0x%08x"/>
        </EventDescription>
        <EventDescription id="10516" name="EVENT_APEX_REPLENISH" trigger="false" displayName="apexReplenish" icon="images/apexReplenish.gif" helpTopicId="VXWORKSAE653_EVENT_APEX_REPLENISH_EVENT_HELP">
            <EventParam type="UINT32" name="procId" formatStr="0x%08x"/>
        </EventDescription>
        <EventDescription id="10517" name="EVENT_APEX_CREATEPROC" trigger="false" displayName="apexProcessCreate" icon="images/apexProcessCreate.gif" helpTopicId="VXWORKSAE653_EVENT_APEX_CREATEPROC_EVENT_HELP">
            <EventParam type="UINT32" name="deadline" formatStr="%d"/>
            <EventParam type="UINT32" name="period" formatStr="%d"/>
            <EventParam type="UINT32" name="stack" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="priority" formatStr="%d"/>
            <EventParam type="UINT32" name="procId" formatStr="0x%08x"/>
        </EventDescription>
        <EventDescription id="10518" name="EVENT_APEX_SETPRIORITY" trigger="false" displayName="apexPrioritySet" icon="images/apexProcessPrioritySet.gif" helpTopicId="VXWORKSAE653_EVENT_APEX_SETPRIORITY_EVENT_HELP">
            <EventParam type="UINT32" name="priority" formatStr="%d"/>
            <EventParam type="UINT32" name="procId" formatStr="0x%08x"/>
        </EventDescription>
        <EventDescription id="10519" name="EVENT_APEX_SUSPENDSELF" trigger="false" displayName="apexSuspendSelf" icon="images/apexSuspendSelf.gif" helpTopicId="VXWORKSAE653_EVENT_APEX_SUSPENDSELF_EVENT_HELP">
            <EventParam type="UINT32" name="ticks" formatStr="%d"/>
            <EventParam type="UINT32" name="procId" formatStr="0x%08x"/>
        </EventDescription>
        <EventDescription id="10520" name="EVENT_APEX_SUSPEND" trigger="false" displayName="apexSuspend" icon="images/apexSuspend.gif" helpTopicId="VXWORKSAE653_EVENT_APEX_SUSPEND_EVENT_HELP">
            <EventParam type="UINT32" name="procId" formatStr="0x%08x"/>
        </EventDescription>
        <EventDescription id="10521" name="EVENT_APEX_RESUME" trigger="false" displayName="apexResume" icon="images/apexResume.gif" helpTopicId="VXWORKSAE653_EVENT_APEX_RESUME_EVENT_HELP">
            <EventParam type="UINT32" name="procId" formatStr="0x%08x"/>
        </EventDescription>
        <EventDescription id="10522" name="EVENT_APEX_STOP" trigger="false" displayName="apexStop" icon="images/apexStop.gif" helpTopicId="VXWORKSAE653_EVENT_APEX_STOP_EVENT_HELP">
            <EventParam type="UINT32" name="procId" formatStr="0x%08x"/>
        </EventDescription>
        <EventDescription id="10523" name="EVENT_APEX_STOPSELF" trigger="false" displayName="apexStopSelf" icon="images/apexStopSelf.gif" helpTopicId="VXWORKSAE653_EVENT_APEX_STOPSELF_EVENT_HELP">
            <EventParam type="UINT32" name="procId" formatStr="0x%08x"/>
        </EventDescription>
        <EventDescription id="10524" name="EVENT_APEX_START" trigger="false" displayName="apexStart" icon="images/apexStart.gif" helpTopicId="VXWORKSAE653_EVENT_APEX_START_EVENT_HELP">
            <EventParam type="UINT32" name="procId" formatStr="0x%08x"/>
        </EventDescription>
        <EventDescription id="10525" name="EVENT_APEX_LOCK" trigger="false" displayName="apexLockPreemption" icon="images/apexLock.gif" helpTopicId="VXWORKSAE653_EVENT_APEX_LOCK_EVENT_HELP"> 
            <EventParam type="UINT32" name="newLockLevel"/>
        </EventDescription>
        <EventDescription id="10526" name="EVENT_APEX_UNLOCK" trigger="false" displayName="apexUnlockPreemption" icon="images/apexUnlock.gif" helpTopicId="VXWORKSAE653_EVENT_APEX_UNLOCK_EVENT_HELP">
            <EventParam type="UINT32" name="newLockLevel"/>
            <EventParam type="UINT32" name="procId" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10527" name="EVENT_APEX_CREATSPORT"
            trigger="false" displayName="apexCreateSamplingPort" 
            icon="images/apexSPortCreate.gif" 
            helpTopicId="VXWORKSAE653_EVENT_APEX_CREATE_SAMPLING_PORT_EVENT_HELP">
            <EventParam type="UINT32" name="size" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="period"/>
            <EventParam type="UINT32" name="direction" />
            <EventParam type="UINT32" name="portId" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10528" name="EVENT_APEX_WRITESPORT"
            trigger="false" displayName="apexWriteSamplingPort" 
            icon="images/apexSPortWrite.gif" 
            helpTopicId="VXWORKSAE653_EVENT_APEX_WRITE_SAMPLING_PORT_EVENT_HELP">
            <EventParam type="UINT32" name="length" />
            <EventParam type="UINT32" name="message" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="portId" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10529" name="EVENT_APEX_READSPORT"
            trigger="false" displayName="apexReadSamplingPort" 
            icon="images/apexSPortRead.gif" 
            helpTopicId="VXWORKSAE653_EVENT_APEX_READ_SAMPLING_PORT_EVENT_HELP">
            <EventParam type="UINT32" name="portId" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10530" name="EVENT_APEX_CREATQPORT"
            trigger="false" displayName="apexCreateQueuingPort" 
            icon="images/apexQPortCreate.gif" 
            helpTopicId="VXWORKSAE653_EVENT_APEX_CREATE_QUEUEING_PORT_EVENT_HELP">
            <EventParam type="UINT32" name="maxMsgSize" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="maxMsg" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="discipline" />
            <EventParam type="UINT32" name="direction" />
            <EventParam type="UINT32" name="portId" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10531" name="EVENT_APEX_SENDQPORT"
            trigger="false" displayName="apexSendQueuingPort" 
            icon="images/apexQPortSend.gif" 
            helpTopicId="VXWORKSAE653_EVENT_APEX_SEND_QUEUEING_PORT_EVENT_HELP">
            <EventParam type="UINT32" name="timeout" />
            <EventParam type="UINT32" name="length" />
            <EventParam type="UINT32" name="message" formatStr="0x%08x" />
            <EventParam type="UINT32" name="portId" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10532" name="EVENT_APEX_RECEIVEQPORT"
            trigger="false" displayName="apexReceiveQueuingPort" 
            icon="images/apexQPortReceive.gif" 
            helpTopicId="VXWORKSAE653_EVENT_APEX_RECEIVE_QUEUEING_PORT_EVENT_HELP">
            <EventParam type="UINT32" name="timeout" />
            <EventParam type="UINT32" name="maxLength" />
            <EventParam type="UINT32" name="message" formatStr="0x%08x" />
            <EventParam type="UINT32" name="portId" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10533" name="EVENT_APEX_CREATEMUTEX"
            trigger="false" displayName="apexCreateMutex" 
            icon="images/apexMutexCreate.gif" 
            helpTopicId="VXWORKSAE653_EVENT_APEX_CREATE_MUTEX_EVENT_HELP">
            <EventParam type="UINT32" name="priority" />
            <EventParam type="UINT32" name="discipline" />
            <EventParam type="UINT32" name="mutexId" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10534" name="EVENT_APEX_ACQUIREMUTEX"
            trigger="false" displayName="apexAcquireMutex" 
            icon="images/apexMutexAcquire.gif" 
            helpTopicId="VXWORKSAE653_EVENT_APEX_ACQUIRE_MUTEX_EVENT_HELP">
            <EventParam type="UINT32" name="timeout" />
            <EventParam type="UINT32" name="priority" />
            <EventParam type="UINT32" name="mutexId" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10535" name="EVENT_APEX_RELEASEMUTEX"
            trigger="false" displayName="apexReleaseMutex" 
            icon="images/apexMutexRelease.gif" 
            helpTopicId="VXWORKSAE653_EVENT_APEX_RELEASE_MUTEX_EVENT_HELP">
            <EventParam type="UINT32" name="priority" />
            <EventParam type="UINT32" name="mutexId" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10536" name="EVENT_APEX_RESETMUTEX"
            trigger="false" displayName="apexResetMutex" 
            icon="images/apexMutexReset.gif" 
            helpTopicId="VXWORKSAE653_EVENT_APEX_RESET_MUTEX_EVENT_HELP">
            <EventParam type="UINT32" name="priority" />
            <EventParam type="UINT32" name="mutexId" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10600" name="EVENT_SCHED_MAJORFRAME" trigger="true" displayName="schedulerMajorFrame" icon="images/schedMajorFrame.gif" helpTopicId="EVENT_SCHED_MAJORFRAME_HELP">
            <EventParam type="UINT32" name="schedule" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="newPartition" formatStr="0x%08x"/>
        </EventDescription>
        <EventDescription id="10601" name="EVENT_SCHED_MINORFRAME" trigger="true" displayName="schedulerMinorFrame" icon="images/schedMinorFrame.gif" helpTopicId="EVENT_SCHED_MINORFRAME_HELP">
            <EventParam type="UINT32" name="newPartition" formatStr="0x%08x"/>
        </EventDescription>

    </EventClass>
</EventDictionary>
)delim";


std::string v7_32_smp_dprintf_xml = R"delim(
<?xml version="1.0" encoding="utf-8"?>
<!--
/* dynamic_printf.xml - XML descriptions for dynamic printf */

/* Copyright 2008 Wind River Systems, Inc. */

/*
modification history
01a,31jul08,tcr  created
*/
-->
<!DOCTYPE EventDictionary SYSTEM "../../DTDs/EventDictionary.dtd">
<EventDictionary>
  <EventClass key="dynamicPrintf" displayName="Dynamic Printf Events">
    <EventDescription id="10239" name="DPRINTF"
    displayName="dprintf" icon="color=#FFAFFF,text=dprintf"
    hasTimeStamp="true" isSearchable="true">
      <EventParam type="BLOB" name="text" formatStr="%s" />
    </EventDescription>
  </EventClass>
</EventDictionary>
)delim";


std::string v7_32_smp_edr_xml = R"delim(
<?xml version="1.0" encoding="utf-8"?>
<!--
/* edr.xml - XML descriptions for ED&R */

/* Copyright 2004 Wind River Systems, Inc. */

/*
modification history
01d,20sep04,cjtc prefix help IDs with the os type
01c,26apr04,tcr  renumber events
01b,04mar04,cjtc add attributes to EDR_ERROR_INJECT
01a,04mar04,aim  written
*/
-->
<!DOCTYPE EventDictionary SYSTEM "../../DTDs/EventDictionary.dtd">
<EventDictionary>
  <EventClass key="EDR" displayName="Error Detection Events"
  helpTopicId="VXWORKS6_edr_CLASS_HELP">
    <EventDescription id="10082" name="EDR_ERROR_INJECT"
    displayName="EDR_ERROR_INJECT" icon="images/edrErrorInject.gif"
    hasTimeStamp="true" isSearchable="true"
    helpTopicId="VXWORKS6_EDR_ERROR_INJECT_EVENT_HELP">
      <EventParam type="UINT32" name="kind" formatStr="0x%x"
      formatter="com.windriver.windview.plugins.wv.vxworks6.parmfmt.EdrErrorInjectKind" />

      <EventParam type="UINT32" name="fileNameLen" />

      <EventParam type="STRING" name="fileName" formatStr="%s" />

      <EventParam type="UINT32" name="line" />

      <EventParam type="UINT32" name="address" formatStr="0x%08x" />

      <EventParam type="UINT32" name="textLength" />

      <EventParam type="STRING" name="text" formatStr="%s" />
    </EventDescription>
  </EventClass>
</EventDictionary>
)delim";


std::string v7_32_smp_ioLib_xml = R"delim(
<?xml version="1.0" encoding="UTF-8"?>
<!--
/* ioLib.xml - XML descriptions for vxWorks 6 ioLib events */

/* Copyright 2008 Wind River Systems, Inc. */

/*
modification history
01b,23oct08,tcr  remove incorrect formatter
01a,28jul05,tcr  created from 6.6 version
*/
-->
<!DOCTYPE EventDictionary SYSTEM "../../DTDs/EventDictionary.dtd">
<EventDictionary>
    <EventClass key="io" displayName="I/O Events" helpTopicId="VXWORKS6_IOLIB_CLASS_HELP">
        <EventDescription id="10048" name="EVENT_IOOPEN" trigger="true"
         displayName="open" icon="images/open.gif" helpTopicId="VXWORKS6_EVENT_IOOPEN_EVENT_HELP">
            <EventParam type="UINT32" name="fd" isSearchKey="true"/>
            <EventParam type="UINT32" name="flags" formatStr="0x%x"/>
            <EventParam type="BLOB" name="name" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>

        <EventDescription id="10049" name="EVENT_IOREAD" trigger="true"
         displayName="read" icon="images/read.gif" helpTopicId="VXWORKS6_EVENT_IOREAD_EVENT_HELP">
            <EventParam type="UINT32" name="fd" isSearchKey="true"/>
            <EventParam type="UINT32" name="bytesRead"/>
            <EventParam type="UINT32" name="buffer" formatStr="0x%08x"/>
            <EventParam type="BLOB" name="data" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>

        <EventDescription id="10050" name="EVENT_IOWRITE" trigger="true"
         displayName="write" icon="images/write.gif" helpTopicId="VXWORKS6_EVENT_IOWRITE_EVENT_HELP">
            <EventParam type="UINT32" name="fd" isSearchKey="true"/>
            <EventParam type="UINT32" name="bytesWritten"/>
            <EventParam type="UINT32" name="buffer" formatStr="0x%08x"/>
            <EventParam type="BLOB" name="data" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>

        <EventDescription id="10051" name="EVENT_IOIOCTL" trigger="true"
         displayName="ioctl" icon="images/ioctl.gif" helpTopicId="VXWORKS6_EVENT_IOIOCTL_EVENT_HELP">
            <EventParam type="UINT32" name="arg" />
            <EventParam type="UINT32" name="cmd" />
            <EventParam type="UINT32" name="fd" isSearchKey="true"/>
        </EventDescription>

        <EventDescription id="10052" name="EVENT_IOCLOSE" trigger="true" 
         displayName="close" icon="images/close.gif" helpTopicId="VXWORKS6_EVENT_IOCLOSE_EVENT_HELP">
            <EventParam type="UINT32" name="fd" isSearchKey="true"/>
        </EventDescription>

        <EventDescription id="10053" name="EVENT_IOCREAT" trigger="true"
         displayName="creat" icon="images/creat.gif" helpTopicId="VXWORKS6_EVENT_IOCREAT_EVENT_HELP">
            <EventParam type="UINT32" name="fd"/>
            <EventParam type="UINT32" name="mode" formatStr="%o"/>
            <EventParam type="BLOB" name="name" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>

        <EventDescription id="10054" name="EVENT_IODELETE" trigger="true"
         displayName="remove" icon="images/remove.gif" helpTopicId="VXWORKS6_EVENT_IODELETE_EVENT_HELP">
            <EventParam type="BLOB" name="name" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>
    </EventClass>
</EventDictionary>
)delim";


std::string v7_32_smp_isrlib_xml = R"delim(
<?xml version="1.0" encoding="UTF-8"?>
<!--
/* isrlib.xml - XML descriptions for vxWorks 6 isrLib events */

/* Copyright 2008 Wind River Systems, Inc. */

/*
modification history
01b,26sep08,tcr  change type of isrName
01a,07may08,tcr  created from 6.6 version
*/
-->
<!DOCTYPE EventDictionary SYSTEM "../../DTDs/EventDictionary.dtd">
<EventDictionary>
    <EventClass key="isr" displayName="ISR Events" helpTopicId="VXWORKS6_isr_CLASS_HELP">

        <EventDescription id="9" name="EVENT_ISR_INFO" trigger="false" hasTimeStamp="false" displayName="isrInfo" helpTopicId="VXWORKS6_EVENT_ISR_INFO_EVENT_HELP">
            <EventParam type="UINT32" name="isrId" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="isrHandler" formatStr="0x%08x"/>
            <EventParam type="BLOB" name="name" formatStr="%s"/>
        </EventDescription>

        <EventDescription id="10060" name="EVENT_ISR_DISPATCHER_INVOKE" trigger="true" displayName="isrDispatch" icon="images/isrDispatcherInvoke.gif" helpTopicId="VXWORKS6_EVENT_ISR_DISPATCH_EVENT_HELP">
            <EventParam isSearchKey="true" type="UINT32" name="isrId" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10061" name="EVENT_ISR_DISPATCHER_DONE" trigger="true" displayName="isrDispatchDone" icon="images/isrDispatcherDone.gif" helpTopicId="VXWORKS6_EVENT_ISR_DISPATCH_DONE_EVENT_HELP">
            <EventParam isSearchKey="true" type="UINT32" name="isrId" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10062" name="EVENT_ISR_CREATE" trigger="true" displayName="isrCreate" icon="images/isrCreate.gif" helpTopicId="VXWORKS6_EVENT_ISR_CREATE_EVENT_HELP">
            <EventParam type="UINT32" name="options" formatStr="%d"/>
            <EventParam type="UINT32" name="param" formatStr="%d"/>
            <EventParam type="UINT32" name="rtn" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="tag" formatStr="%d"/>
            <EventParam isSearchKey="true" type="UINT32" name="isrId"
            formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10064" name="EVENT_ISR_DESTROY" trigger="true" displayName="isrDestroy" icon="images/isrDestroy.gif" helpTopicId="VXWORKS6_EVENT_ISR_DESTROY_EVENT_HELP">
            <EventParam isSearchKey="true" type="UINT32" name="isrId" formatStr="0x%08x"/>
        </EventDescription>
    </EventClass>
</EventDictionary>
)delim";


std::string v7_32_smp_memlib_xml = R"delim(
<?xml version="1.0" encoding="UTF-8"?>
<!--
/* vxworks.xml - XML descriptions for vxWorks 6.7 memory events */

/* Copyright 2008, 2016 Wind River Systems, Inc. */

/*
modification history
01c,25jan16,saj  WB4-6490: miss some events.
01a,07may08,tcr  created from VxWorks 6.6 version
*/
-->
<!DOCTYPE EventDictionary SYSTEM "../../DTDs/EventDictionary.dtd">
<EventDictionary>
    <EventClass key="mem" displayName="Memory Events" helpTopicId="VXWORKS6_mem_CLASS_HELP">
        <EventDescription id="10030" name="EVENT_MEMALLOC" trigger="true" displayName="memPartAlignedAlloc" icon="images/memPartAlignedAlloc.gif" helpTopicId="VXWORKS6_EVENT_MEMALLOC_EVENT_HELP">
            <EventParam isSearchKey="true" type="UINT32" name="partId" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="pBlock" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="nBytesPlusHeaderAlign"/>
            <EventParam type="UINT32" name="nBytes"/>
        </EventDescription>
        <EventDescription id="10031" name="EVENT_MEMFREE" trigger="true" displayName="memPartFree" icon="images/memPartFree.gif" helpTopicId="VXWORKS6_EVENT_MEMFREE_EVENT_HELP">
            <EventParam isSearchKey="true" type="UINT32" name="partId" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="pBlock" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="nBytesPlusHeaderAlign"/>
        </EventDescription>
        <EventDescription id="10032" name="EVENT_MEMPARTCREATE" trigger="true" displayName="memPartCreate" icon="images/memPartCreate.gif" helpTopicId="VXWORKS6_EVENT_MEMPARTCREATE_EVENT_HELP">
            <EventParam isSearchKey="true" type="UINT32" name="partId" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="poolSize"/>
        </EventDescription>
        <EventDescription id="10033" name="EVENT_MEMREALLOC" trigger="true" displayName="memPartRealloc" icon="images/memPartRealloc.gif" helpTopicId="VXWORKS6_EVENT_MEMREALLOC_EVENT_HELP">
            <EventParam isSearchKey="true" type="UINT32" name="partId" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="pNewBlock" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="nBytesPlusHeaderAlign"/>
            <EventParam type="UINT32" name="pBlock" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="nBytes"/>
        </EventDescription>
        <EventDescription id="10034" name="EVENT_MEMADDTOPOOL" trigger="true" displayName="memPartAddToPool" icon="images/memPartAddToPool.gif" helpTopicId="VXWORKS6_EVENT_MEMADDTOPOOL_EVENT_HELP">
            <EventParam isSearchKey="true" type="UINT32" name="partId" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="poolSize"/>
        </EventDescription>
        <EventDescription id="15000" name="EVENT_RTP_MEMALLOC" trigger="true" displayName="memPartBlkAlignedAlloc-rtp" icon="images/memPartAlignedAlloc.gif" helpTopicId="VXWORKS6_EVENT_MEMALLOC_EVENT_HELP">
            <EventParam isSearchKey="true" type="UINT32" name="pPartition" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="addr" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="bytesReq"/>
            <EventParam type="UINT32" name="bytesAlloc"/>
        </EventDescription>
        <EventDescription id="15001" name="EVENT_RTP_MEMFREE" trigger="true" displayName="memPartFreeInternal-rtp" icon="images/memPartFree.gif" helpTopicId="VXWORKS6_EVENT_MEMFREE_EVENT_HELP">
            <EventParam isSearchKey="true" type="UINT32" name="pPartition" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="addr" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="bytesFree"/>
        </EventDescription>
        <EventDescription id="15002" name="EVENT_RTP_MEMPARTCREATE" trigger="true" displayName="memPartCreate-rtp" icon="images/memPartCreate.gif" helpTopicId="VXWORKS6_EVENT_MEMPARTCREATE_EVENT_HELP">
            <EventParam isSearchKey="true" type="UINT32" name="pPartition" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="pPool" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="poolSize"/>
        </EventDescription>
        <EventDescription id="15003" name="EVENT_RTP_MEMREALLOC" trigger="true" displayName="memPartReallocInternal-rtp" icon="images/memPartRealloc.gif" helpTopicId="VXWORKS6_EVENT_MEMREALLOC_EVENT_HELP">
            <EventParam isSearchKey="true" type="UINT32" name="partId" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="pNewBlock" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="nBytesPlusHeaderAlign"/>
            <EventParam type="UINT32" name="pBlock" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="nBytes"/>
        </EventDescription>
        <EventDescription id="15004" name="EVENT_RTP_MEMADDTOPOOL" trigger="true" displayName="memPartAddToPool-rtp" icon="images/memPartAddToPool.gif" helpTopicId="VXWORKS6_EVENT_MEMADDTOPOOL_EVENT_HELP">
            <EventParam isSearchKey="true" type="UINT32" name="pPartition" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="pPool" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="poolSize"/>
        </EventDescription>                
    </EventClass>
</EventDictionary>
)delim";


std::string v7_32_smp_netdlib_xml = R"delim(
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE EventDictionary SYSTEM "../../DTDs/EventDictionary.dtd">
<EventDictionary>
    <EventClass key="windnet_dual_stack" displayName="WindNet IPv6/IPv4 Network events" helpTopicId="VXWORKS6_windnet_dual_stack_CLASS_HELP">
        <EventDescription id="20400" name="WV_NETDEVENT_FATAL" displayName ="wvNetFatal" icon="images/wvnet-panic.gif" helpTopicId="VXWORKS6_NETDEVENT_FATAL_ERROR_EVENT_HELP">
	    <EventParam type="UINT32" name="wvEvtInfo" formatter="com.windriver.windview.plugins.wv.windnet.formatters.wvNetDInfoDecoder"/>
	    <EventParam type="UINT32" name="Func" formatStr="0x%08x"/>
	    <EventParam type="UINT32" name="Qualifier" formatter="com.windriver.windview.plugins.wv.windnet.formatters.QualifierDecoder"/>
            <EventParam type="BLOB" name="P1-2" formatter="com.windriver.windview.plugins.wv.windnet.formatters.NetBlobDecoder"/>
        </EventDescription>
        <EventDescription id="20415" name="WV_NETDEVENT_CRITICAL" displayName ="wvNetCritical" icon="images/wvnet-error.gif" helpTopicId="VXWORKS6_NETDEVENT_CRITICAL_ERROR_EVENT_HELP">
	    <EventParam type="UINT32" name="wvEvtInfo" formatter="com.windriver.windview.plugins.wv.windnet.formatters.wvNetDInfoDecoder"/>
	    <EventParam type="UINT32" name="Func" formatStr="0x%08x"/>
	    <EventParam type="UINT32" name="Qualifier" formatter="com.windriver.windview.plugins.wv.windnet.formatters.QualifierDecoder"/>
            <EventParam type="BLOB" name="P1-2" formatter="com.windriver.windview.plugins.wv.windnet.formatters.NetBlobDecoder"/>
        </EventDescription>
        <EventDescription id="20430" name="WV_NETDEVENT_WARNING" displayName ="wvNetWarning" icon="images/wvnet-warning.gif" helpTopicId="VXWORKS6_NETDEVENT_WARNING_EVENT_HELP">
	    <EventParam type="UINT32" name="wvEvtInfo" formatter="com.windriver.windview.plugins.wv.windnet.formatters.wvNetDInfoDecoder"/>
	    <EventParam type="UINT32" name="Func" formatStr="0x%08x"/>
	    <EventParam type="UINT32" name="Qualifier" formatter="com.windriver.windview.plugins.wv.windnet.formatters.QualifierDecoder"/>
            <EventParam type="BLOB" name="P1-2" formatter="com.windriver.windview.plugins.wv.windnet.formatters.NetBlobDecoder"/>
        </EventDescription>
        <EventDescription id="20445" name="WV_NETDEVENT_INFO" displayName ="wvNetInfo" icon="images/wvnet-info.gif" helpTopicId="VXWORKS6_NETDEVENT_INFO_EVENT_HELP">
	    <EventParam type="UINT32" name="wvEvtInfo" formatter="com.windriver.windview.plugins.wv.windnet.formatters.wvNetDInfoDecoder"/>
	    <EventParam type="UINT32" name="Func" formatStr="0x%08x"/>
	    <EventParam type="UINT32" name="SubType" formatter="com.windriver.windview.plugins.wv.windnet.formatters.InfoSubTypeDecoder"/>
            <EventParam type="BLOB" name="P1-2" formatter="com.windriver.windview.plugins.wv.windnet.formatters.NetBlobDecoder"/>
        </EventDescription>
        <EventDescription id="20460" name="WV_NETDEVENT_START" displayName ="wvNetStart" icon="images/wvnet-start.gif" helpTopicId="VXWORKS6_NETDEVENT_START_EVENT_HELP">
	    <EventParam type="UINT32" name="wvEvtInfo" formatter="com.windriver.windview.plugins.wv.windnet.formatters.wvNetDInfoDecoder"/>
	    <EventParam type="UINT32" name="Func" formatStr="0x%08x"/>
	    <EventParam type="UINT32" name="P0" formatStr="0x%08x"/>
            <EventParam type="BLOB" name="P1-2" formatter="com.windriver.windview.plugins.wv.windnet.formatters.NetBlobDecoder"/>
        </EventDescription>
        <EventDescription id="20475" name="WV_NETDEVENT_FINISH" displayName ="wvNetFinish" icon="images/wvnet-finish.gif" helpTopicId="VXWORKS6_NETDEVENT_FINISH_EVENT_HELP">
	    <EventParam type="UINT32" name="wvEvtInfo" formatter="com.windriver.windview.plugins.wv.windnet.formatters.wvNetDInfoDecoder"/>
	    <EventParam type="UINT32" name="Func" formatStr="0x%08x"/>
	    <EventParam type="UINT32" name="P0" formatStr="0x%08x"/>
            <EventParam type="BLOB" name="P1-2" formatter="com.windriver.windview.plugins.wv.windnet.formatters.NetBlobDecoder"/>
        </EventDescription>
     </EventClass>
</EventDictionary>
)delim";


std::string v7_32_smp_objlib_xml = R"delim(
<?xml version="1.0" encoding="UTF-8"?>
<!--
/* isrlib.xml - XML descriptions for vxWorks 6 objLib events */

/* Copyright 2008 Wind River Systems, Inc. */

/*
modification history
01a,12may08,tcr  created from 6.6 version
*/
-->
<!DOCTYPE EventDictionary SYSTEM "../../DTDs/EventDictionary.dtd">
<EventDictionary>
    <EventClass key="obj" displayName="OBJ Events" helpTopicId="VXWORKS6_obj_CLASS_HELP">
        <EventDescription id="10059" name="EVENT_OBJ_OWNERSET" trigger="true" displayName="objOwnerSet" icon="images/objOwnerSet.gif" helpTopicId="VXWORKS6_EVENT_OBJ_OWNERSET_EVENT_HELP">
            <EventParam isSearchKey="true" type="UINT32" name="objId" formatStr="0x%08x"/>
            <EventParam  type="UINT32" name="ownerId" formatStr="0x%08x"/>
        </EventDescription>

    </EventClass>
</EventDictionary>
)delim";


std::string v7_32_smp_pidia_xml = R"delim(
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE EventDictionary SYSTEM "../../DTDs/EventDictionary.dtd">
<EventDictionary>
  <EventClass key="deviceNet" displayName="WIND NET DeviceNet Events" helpTopicId="VXWORKS6_deviceNet_CLASS_HELP">
    <EventDescription id="26001" name="EVENT_DNET_MSG_PROCESS" displayName="dnetMsgProcess" icon="images/dnetMsgProcess.gif" helpTopicId="VXWORKS6_EVENT_DNET_MSG_PROCESS_HELP">
      <EventParam type="UINT32" name="cnxnId" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="descSize" formatStr="%d"/>
      <EventParam type="STRING" name="description" formatStr="%s"/>
    </EventDescription>
    <EventDescription id="26002" name="EVENT_DNET_CNXN_TIMEOUT" displayName="dnetCnxnTimeout" icon="images/dnetCnxnTimeout.gif" helpTopicId="VXWORKS6_EVENT_DNET_CNXN_TIMEOUT_HELP">
      <EventParam type="UINT32" name="instId" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="descSize" formatStr="%d"/>
      <EventParam type="STRING" name="description" formatStr="%s"/>
    </EventDescription>
  </EventClass>
  <EventClass key="windNetOPC" displayName="WIND NET OPC Events" helpTopicId="VXWORKS6_windNetOPC_CLASS_HELP">
    <EventDescription id="26500" name="EVENT_WINDNETOPC_DA" displayName="opcDa" icon="images/opcDa.gif" helpTopicId="VXWORKS6_EVENT_WINDNETOPC_GENERAL_HELP">
      <EventParam type="UINT32" name="messageSize" formatStr="%d"/>
      <EventParam type="STRING" name="Class" formatStr="%s"/>
    </EventDescription>
    <EventDescription id="26501" name="EVENT_WINDNETOPC_ALARMS" displayName="opcAe" icon="images/opcAe.gif" helpTopicId="VXWORKS6_EVENT_WINDNETOPC_ALARMS_HELP">
      <EventParam type="UINT32" name="messageSize" formatStr="%d"/>
      <EventParam type="STRING" name="Class" formatStr="%s"/>
    </EventDescription>
    <EventDescription id="26502" name="EVENT_WINDNETOPC_DX" displayName="opcDx" icon="images/opcDx.gif" helpTopicId="VXWORKS6_EVENT_WINDNETOPC_ALARMS_HELP">
      <EventParam type="UINT32" name="messageSize" formatStr="%d"/>
      <EventParam type="STRING" name="Class" formatStr="%s"/>
    </EventDescription>
  </EventClass>
</EventDictionary>
)delim";


std::string v7_32_smp_powerMng_xml = R"delim(
<?xml version="1.0" encoding="UTF-8"?>
<!--
/* vxworks.xml - XML descriptions for vxWorks 6.9.2 power management events */

/* Copyright 2011 Wind River Systems, Inc. */

/*
modification history
01a,27Jul11,zlo  created from VxWorks 6.9.2 version
*/
-->
<!DOCTYPE EventDictionary SYSTEM "../../DTDs/EventDictionary.dtd">
<EventDictionary>
    <EventClass key="powerMng" displayName="Power Management Events" helpTopicId="VXWORKS6_pwm_CLASS_HELP">
        <EventDescription id="10240" name="EVENT_PPM_SYS_POLICY_SET" trigger="true" displayName="pwrPolicyMgrSysSetProcess" icon="images/powe_set.gif" helpTopicId="VXWORKS6_EVENT_PPM_SYS_POLICY_SET_HELP">
            <EventParam type="UINT32" name="sStateCapability" />
        </EventDescription>
        <EventDescription id="10241" name="EVENT_PPM_CPU_POLICY_SET" trigger="true" displayName="pwrPolicyMgrCpuSetProcess" icon="images/powe_set_c.gif" helpTopicId="VXWORKS6_EVENT_PPM_CPU_POLICY_SET_HELP">
	    <EventParam type="BLOB" name="params"/>
        </EventDescription>
        <EventDescription id="10242" name="EVENT_PPM_DEV_POLICY_SET" trigger="true" displayName="pwrPolicyMgrDevSetProcess" icon="images/powe_set_d.gif" helpTopicId="VXWORKS6_EVENT_PPM_DEV_POLICY_SET_HELP">
            <EventParam type="UINT32" name="unitNum" />
            <EventParam type="UINT32" name="timeout" />
            <EventParam type="UINT32" name="dStateCapability" />
            <EventParam type="BLOB" name="devName" />
        </EventDescription>
        <EventDescription id="10243" name="EVENT_PPM_POLICY_DISABLE" trigger="true" displayName="pwrPolicyMgrStateProcessDisable" icon="images/powe_disable.gif" helpTopicId="VXWORKS6_EVENT_PPM_POLICY_DISABLE_HELP">            
        </EventDescription>
        <EventDescription id="10244" name="EVENT_PPM_POLICY_ENABLE" trigger="true" displayName="pwrPolicyMgrStateProcessEnable" icon="images/powe_enable.gif" helpTopicId="VXWORKS6_EVENT_PPM_POLICY_ENABLE_HELP">
        </EventDescription>
        <EventDescription id="10245" name="EVENT_POWER_DOWN" trigger="true" displayName="windPwrDown" icon="images/powe_down.gif" helpTopicId="VXWORKS6_EVENT_POWER_DOWN_HELP">            
            <EventParam type="UINT32" name="powerMode"/>
            <EventParam type="UINT32" name="waitTicks"/>
        </EventDescription>
        <EventDescription id="10246" name="EVENT_POWER_UP" trigger="true" displayName="windPwrUp" icon="images/powe_up.gif" helpTopicId="VXWORKS6_EVENT_POWER_UP_HELP">
        </EventDescription>
        <EventDescription id="10247" name="EVENT_POWER_PSTATE_SET" trigger="true" displayName="pwrCpuPStateSet" icon="images/powe_P.gif" helpTopicId="VXWORKS6_EVENT_POWER_PSTATE_SET_HELP">
            <EventParam type="UINT32" name="cpuId"/>
            <EventParam type="UINT32" name="newPState"/>
            <EventParam type="UINT32" name="oldPState"/>
        </EventDescription>
        <EventDescription id="10248" name="EVENT_POWER_CSTATE_SET" trigger="true" displayName="pwrCpuCStateSet" icon="images/powe_c.gif" helpTopicId="VXWORKS6_EVENT_POWER_CSTATE_SET_HELP">
            <EventParam type="UINT32" name="newCState"/>
        </EventDescription>
        <EventDescription id="10249" name="EVENT_POWER_DSTATE_SET" trigger="true" displayName="pwrDeviceStateSet" icon="images/powe_d.gif" helpTopicId="VXWORKS6_EVENT_POWER_DSTATE_SET_HELP">
            <EventParam type="UINT32" name="pwrDevId" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="newDState"/>
        </EventDescription>
        <EventDescription id="10250" name="EVENT_POWER_DEV_ENABLE_SET" trigger="true" displayName="pwrDeviceEnableSet" icon="images/powe_pev.gif" helpTopicId="VXWORKS6_EVENT_POWER_DEV_ENABLE_SET_HELP">
            <EventParam type="UINT32" name="pwrDevId" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="flag"/>
        </EventDescription>
        <EventDescription id="10251" name="EVENT_POWER_DEV_CAPABILITY_SET" trigger="true" displayName="pwrDeviceCapabilitySet" icon="images/powe_S.gif" helpTopicId="VXWORKS6_EVENT_POWER_DEV_CAPBILITY_SET_HELP">
            <EventParam type="UINT32" name="pwrDevId" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="flag"/>
        </EventDescription>
        <EventDescription id="10252" name="EVENT_POWER_TIMEOUT_SET" trigger="true" displayName="pwrDeviceTimeoutSet" icon="images/powe_t.gif" helpTopicId="VXWORKS6_EVENT_POWER_TIMEOUT_SET_HELP">
            <EventParam type="UINT32" name="pwrDevId" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="timeOut"/>
        </EventDescription>
        <EventDescription id="10253" name="EVENT_PPM_CPU_LOAD_MON_CONF" trigger="true" displayName="pwrCpuMonConfigure" icon="images/powe_set_m.gif" helpTopicId="VXWORKS6_EVENT_CPU_LOAD_MON_CONF_HELP">
            <EventParam type="UINT32" name="cpuNum" />
	    <EventParam type="BLOB" name="params"/>
        </EventDescription>
    </EventClass>
</EventDictionary>
)delim";


std::string v7_32_smp_rtplib_xml = R"delim(
<?xml version="1.0" encoding="UTF-8"?>
<!--
/* rtplib.xml - XML descriptions for vxWorks 6 RTP events */

/* Copyright 2008 Wind River Systems, Inc. */

/*
 * This file contains descriptions for the RTP events
 */

/*
modification history
01a,12may08,tcr  created from 6.6 version
*/
-->
<!DOCTYPE EventDictionary SYSTEM "../../DTDs/EventDictionary.dtd">
<EventDictionary>
    <EventClass key="rtpLib" displayName="rtpLib Events" helpTopicId="VXWORKS6_RTP_CLASS_HELP">

        <EventDescription id="16" name="EVENT_RTPNAME" hasTimeStamp="false" isSearchable="false" helpTopicId="VXWORKS6_EVENT_RTPNAME_EVENT_HELP">
            <EventParam type="UINT32" name="options" />
            <EventParam type="UINT32" name="ownerId" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="rtpId" formatStr="0x%08x"/>
            <EventParam type="BLOB" name="name" formatStr="%s"/>
        </EventDescription>

        <EventDescription id="10078" name="EVENT_RTP_SPAWN" hasTimeStamp="true"
        trigger="true" displayName="rtpSpawn" isSearchable="true" 
        helpTopicId="VXWORKS6_EVENT_RTP_SPAWN_HELP" icon="images/rtpSpawn.gif">
            <EventParam type="UINT32" name="options" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="stackSize" />
            <EventParam type="UINT32" name="priority" />
            <EventParam type="UINT32" isSearchKey="true" name="rtpId" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10079" name="EVENT_RTP_DELETE" hasTimeStamp="true"
        trigger="true" displayName="rtpDelete" isSearchable="true" 
        helpTopicId="VXWORKS6_EVENT_RTP_DELETE_HELP" icon="images/rtpDelete.gif">
            <EventParam type="UINT32" name="options" formatStr="0x%08x"/>
            <EventParam type="UINT32" isSearchKey="true" name="rtpId" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10080" name="EVENT_RTP_INIT_TASK" hasTimeStamp="true"
        trigger="true" displayName="rtpInitTask" isSearchable="true" 
        helpTopicId="VXWORKS6_EVENT_RTP_INIT_TASK_HELP" icon="images/rtpInitTask.gif">
            <EventParam type="UINT32" name="initialStack" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="pEnv" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="pArgv" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="numArgs" />
            <EventParam type="UINT32" isSearchKey="true" name="rtpId" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10081" name="EVENT_RTP_LOAD" hasTimeStamp="true"
        trigger="true" displayName="rtpLoad" isSearchable="true" 
        helpTopicId="VXWORKS6_EVENT_RTP_LOAD_HELP" icon="images/rtpLoad.gif">
            <EventParam type="UINT32" name="dataSize" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="dataStart" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="textSize" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="textStart" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="entrAddr" formatStr="0x%08x"/>
            <EventParam type="UINT32" isSearchKey="true" name="rtpId" formatStr="0x%08x"/>
        </EventDescription>

    </EventClass>

</EventDictionary>
)delim";


std::string v7_32_smp_rtpSignals_xml = R"delim(
<?xml version="1.0" encoding="UTF-8"?>
<!--
/* vxworks.xml - XML descriptions for vxWorks 6 */

/* Copyright 2004 Wind River Systems, Inc. */

/*
modification history
01e,20sep04,cjt  prefix help IDs with the os type
01d,20aug04,tcr  change duplicated displayName
01c,07may04,tcr  update incorrect parameter name
01b,26apr04,tcr  include code review comments for rtpSigLib.c
01a,18mar04,tcr  created
*/
-->
<!DOCTYPE EventDictionary SYSTEM "../../DTDs/EventDictionary.dtd">
<EventDictionary>
    <EventClass key="rtpSig" displayName="RTP Signal Handling" helpTopicId="VXWORKS6_rtpsig_CLASS_HELP">
        <EventDescription id="10083" name="EVENT_RTPKILL" trigger="true" displayName="rtpKill" icon="images/rtpkill.gif" helpTopicId="VXWORKS6_EVENT_RTPKILL_EVENT_HELP">
            <EventParam isSearchKey="true" type="UINT32" name="rtpId" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="signo"/>
        </EventDescription>

        <EventDescription id="10084" name="EVENT_RTPSIGNAL" trigger="true" displayName="rtpSignal" icon="images/rtpsignal.gif" helpTopicId="VXWORKS6_EVENT_RTPSIGNAL_EVENT_HELP">
            <EventParam isSearchKey="true" type="UINT32" name="rtpId" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="signo"/>
            <EventParam type="UINT32" name="action" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10085" name="EVENT_RTPSUSPEND" trigger="true" displayName="rtpSuspend" icon="images/rtpsigsuspend.gif" helpTopicId="VXWORKS6_EVENT_RTPSUSPEND_EVENT_HELP">
            <EventParam isSearchKey="true" type="UINT32" name="sigset" formatStr="0x%x"/>
        </EventDescription>

        <EventDescription id="10086" name="EVENT_RTPPAUSE" trigger="true" displayName="rtpPause" icon="images/pause.gif" helpTopicId="VXWORKS6_EVENT_RTPPAUSE_EVENT_HELP">
            <EventParam isSearchKey="true" type="UINT32" name="rtpId" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10087" name="EVENT_RTPTASKKILL" trigger="true" displayName="rtpTaskKill" icon="images/rtptaskkill.gif" helpTopicId="VXWORKS6_EVENT_RTPTASKKILL_EVENT_HELP">
            <EventParam isSearchKey="true" type="UINT32" name="tid" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="signal"/>
        </EventDescription>

        <EventDescription id="10088" name="EVENT_RTPSIGQUEUE" trigger="true" displayName="rtpSigqueue" icon="images/rtpsigqueue.gif" helpTopicId="VXWORKS6_EVENT_RTPSIGQUEUE_EVENT_HELP">
            <EventParam isSearchKey="true" type="UINT32" name="rtpId" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="signal"/>
            <EventParam type="UINT32" name="value" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10089" name="EVENT_RTPTASKSIGQUEUE" trigger="true" displayName="rtpTaskSigqueue" icon="images/rtptasksigqueue.gif" helpTopicId="VXWORKS6_EVENT_RTPTASKSIGQUEUE_EVENT_HELP">
            <EventParam isSearchKey="true" type="UINT32" name="taskId" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="signal"/>
            <EventParam type="UINT32" name="value" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10090" name="EVENT_RTPCHILDWAIT" trigger="true" displayName="rtpChildWait" icon="images/rtpchildwait.gif" helpTopicId="VXWORKS6_EVENT_RTPCHILDWAIT_EVENT_HELP">
            <EventParam isSearchKey="true" type="UINT32" name="childRtpId" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="options" formatStr="0x%x"/>
        </EventDescription>

        <EventDescription id="10091" name="EVENT_RTPSIGTIMEDWAIT" trigger="true" displayName="rtpSigtimedwait" icon="images/rtpsigtimedwait.gif" helpTopicId="VXWORKS6_EVENT_RTPSIGTIMEDWAIT_EVENT_HELP">
            <EventParam type="UINT32" isSearchKey="true" name="rtpId" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="pSigset" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="pInfo" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="timeout"/>
        </EventDescription>

        <EventDescription id="10092" name="EVENT_RTPSIGWRAPPER" trigger="true" displayName="rtpSigWrapper" icon="images/rtpsigwrapper.gif" helpTopicId="VXWORKS6_EVENT_RTPSIGWRAPPER_EVENT_HELP">
            <EventParam type="UINT32" isSearchKey="true" name="rtpId" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="type"/>

        </EventDescription>

        <EventDescription id="10093" name="EVENT_RTPSIGWRAPPERDONE" trigger="true" displayName="rtpSigWrapperDone" icon="images/rtpsigwrapperdone.gif" helpTopicId="VXWORKS6_EVENT_RTPSIGWRAPPERDONE_EVENT_HELP">
            <EventParam type="UINT32" isSearchKey="true" name="rtpId" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10094" name="EVENT_RTPSIGPROCMASK" trigger="true" displayName="rtpSigProcMask" icon="images/rtpsigprocmask.gif" helpTopicId="VXWORKS6_EVENT_RTPSIGPROCMASK_EVENT_HELP">
            <EventParam type="UINT32" isSearchKey="true" name="rtpId" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="how"/>
            <EventParam type="UINT32" name="pSet" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="pOSet" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10095" name="EVENT_RTPSIGPENDING" trigger="true" displayName="rtpSigPending" icon="images/rtpsigpending.gif" helpTopicId="VXWORKS6_EVENT_RTPSIGPENDING_EVENT_HELP">
            <EventParam type="UINT32" isSearchKey="true" name="rtpId" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="pSet" formatStr="0x%08x"/>
        </EventDescription>

    </EventClass>
</EventDictionary>
)delim";


std::string v7_32_smp_salLib_xml = R"delim(
<?xml version="1.0" encoding="UTF-8"?>
<!--
/* salLib.xml - XML descriptions for SAL library events */

/*
 * Copyright (c) 2004,2008 Wind River Systems, Inc.
 *
 * The right to copy, distribute, modify or otherwise make use
 * of this software may be licensed only pursuant to the terms
 * of an applicable Wind River license agreement.
 */

/*
modification history
01a,14jul08,tcr  created from 6.6 version 01c
*/
-->
<!DOCTYPE EventDictionary SYSTEM "../../DTDs/EventDictionary.dtd">
<EventDictionary>
    <EventClass key="sal" displayName="Socket Application Events" helpTopicId="VXWORKS6_SAL_CLASS_HELP">
        <EventDescription id="10096" name="EVENT_SAL_OPEN" hasTimeStamp="true"
            isSearchable="true" trigger="true" helpTopicId="VXWORKS6_EVENT_SAL_OPEN_HELP"
            displayName="salOpen" icon="images/salOpen.gif">
            <EventParam type="UINT32" name="sockFd" formatStr="0x%x"/>
            <EventParam type="BLOB" name="name" />
        </EventDescription>

        <EventDescription id="10097" name="EVENT_SALCALL_SENDREQ" hasTimeStamp="true"
            isSearchable="true" trigger="true" helpTopicId="VXWORKS6_EVENT_SALCALL_SENDREQ_HELP"
            displayName="salCall_sendReq" icon="images/salCall_SendReq.gif">
            <EventParam type="UINT32" name="length"/>
            <EventParam type="UINT32" name="buffer" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="sockFd" formatStr="0x%x"/>
        </EventDescription>

        <EventDescription id="10098" name="EVENT_SALCALL_REPLY" hasTimeStamp="true"
            isSearchable="true" trigger="true" helpTopicId="VXWORKS6_EVENT_SALCALL_REPLY_HELP"
            displayName="salCall_reply" icon="images/salCall_Reply.gif">
            <EventParam type="UINT32" name="length"/>
            <EventParam type="UINT32" name="buffer" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="sockFd" formatStr="0x%x"/>
        </EventDescription>

        <EventDescription id="10099" name="EVENT_SALCREATE" hasTimeStamp="true"
            isSearchable="true" trigger="true" helpTopicId="VXWORKS6_EVENT_SALCREATE_HELP"
            displayName="salCreate" icon="images/salCreate.gif">
            <EventParam type="UINT32" isSearchKey="true" name="serverId" formatStr="0x%08x"/>
            <EventParam type="BLOB" name="name" formatStr="%s" />
        </EventDescription>

        <EventDescription id="10100" name="EVENT_SALDELETE" hasTimeStamp="true"
            isSearchable="true" trigger="true" helpTopicId="VXWORKS6_EVENT_SALDELETE_HELP"
            displayName="salDelete" icon="images/salDelete.gif">
            <EventParam type="UINT32" isSearchKey="true" name="serverId" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10101" name="EVENT_SALRUN_WAIT" hasTimeStamp="true"
            isSearchable="true" trigger="true" helpTopicId="VXWORKS6_EVENT_SALRUN_WAIT_HELP"
            displayName="salRun_wait" icon="images/salRun_Wait.gif">
            <EventParam type="UINT32" isSearchKey="true" name="serverId" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10102" name="EVENT_SALRUN_READREQ" hasTimeStamp="true"
            isSearchable="true" trigger="true" helpTopicId="VXWORKS6_EVENT_SALRUN_READREQ_HELP"
            displayName="salRun_readReq" icon="images/salRun_ReadReq.gif">
            <EventParam type="UINT32" name="sockFd" formatStr="0x%x"/>
            <EventParam type="UINT32" isSearchKey="true" name="serverId" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10103" name="EVENT_SALRUN_SOCKCLOSE" hasTimeStamp="true"
            isSearchable="true" trigger="true" helpTopicId="VXWORKS6_EVENT_SALRUN_SOCKCLOSE_HELP"
            displayName="salRun_sockClose" icon="images/salRun_SockClose.gif">
            <EventParam type="UINT32" name="sockFd" formatStr="0x%x"/>
            <EventParam type="UINT32" isSearchKey="true" name="serverId" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10104" name="EVENT_SALRUN_SOCKIGNORE" hasTimeStamp="true"
            isSearchable="true" trigger="true" helpTopicId="VXWORKS6_EVENT_SALRUN_SOCKIGNORE_HELP"
            displayName="salRun_ignore" icon="images/salRun_Ignore.gif">
            <EventParam type="UINT32" name="sockFd" formatStr="0x%x"/>
            <EventParam type="UINT32" isSearchKey="true" name="serverId" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10105" name="EVENT_SALRUN_ACCEPT" hasTimeStamp="true"
            isSearchable="true" trigger="true" helpTopicId="VXWORKS6_EVENT_SALRUN_ACCEPT_HELP"
            displayName="salRun_accept" icon="images/salRun_Accept.gif">
            <EventParam type="UINT32" name="sockFd" formatStr="0x%x"/>
            <EventParam type="UINT32" isSearchKey="true" name="serverId" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10106" name="EVENT_SALRUN_CONNECT" hasTimeStamp="true"
            isSearchable="true" trigger="true" helpTopicId="VXWORKS6_EVENT_SALRUN_CONNECT_HELP"
            displayName="salRun_connect" icon="images/salRun_Connect.gif">
            <EventParam type="UINT32" name="sockFd" formatStr="0x%x"/>
            <EventParam type="UINT32" isSearchKey="true" name="serverId" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10107" name="EVENT_SALRUN_TERMINATE" hasTimeStamp="true"
            isSearchable="true" trigger="true" helpTopicId="VXWORKS6_EVENT_SALRUN_ACCEPT_TERMINATE"
            displayName="salRun_terminate" icon="images/salRun_Terminate.gif">
            <EventParam type="UINT32" isSearchKey="true" name="serverId" formatStr="0x%08x"/>
        </EventDescription>
    </EventClass>
</EventDictionary>
)delim";


std::string v7_32_smp_scopetools_xml = R"delim(
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE EventDictionary SYSTEM "../../DTDs/EventDictionary.dtd">
<EventDictionary>
    <EventClass key="ScopeTools" displayName="ScopeTools Events">
        <EventDescription id="39100" name="EVENT_ST_TRACESCOPE_START" displayName="traceScopeStart" icon="images/traceScopeStart.gif">
            <EventParam type="UINT32" name="bufferSize" formatStr="%d records"/>
            <EventParam type="UINT32" name="stackDepth" formatStr="%d functions"/>
        </EventDescription>
        <EventDescription id="39101" name="EVENT_ST_TRACESCOPE_STOP" displayName="traceScopeStop" icon="images/traceScopeStop.gif">
        </EventDescription>
        <EventDescription id="39102" name="EVENT_ST_TRACESCOPE_OVERFLOW" displayName="traceScopeOverflow" icon="images/traceScopeOverflow.gif">
        </EventDescription>
        <EventDescription id="39103" name="EVENT_ST_TRACESCOPE_ENTRY" displayName="traceScopeEntry" icon="images/traceScopeEntry.gif">
            <EventParam isSearchKey="true" type="UINT32" name="sequenceID"/>
            <EventParam isSearchKey="true" type="UINT32" name="address" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="size"/>
            <EventParam type="STRING" name="name" formatStr="%s"/>
        </EventDescription>
        <EventDescription id="39104" name="EVENT_ST_TRACESCOPE_EXIT" displayName="traceScopeExit" icon="images/traceScopeExit.gif">
            <EventParam isSearchKey="true" type="UINT32" name="sequenceID"/>
            <EventParam isSearchKey="true" type="UINT32" name="address" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="size"/>
            <EventParam type="STRING" name="name" formatStr="%s"/>
        </EventDescription>



        <EventDescription id="39200" name="EVENT_ST_MEMSCOPE_START" displayName="memScopeStart" icon="images/memScopeStart.gif">
            <EventParam type="UINT32" name="bufferSize"/>
            <EventParam type="UINT32" name="stackDepth"/>
            <EventParam type="UINT32" name="useWTX"/>
        </EventDescription>
        <EventDescription id="39201" name="EVENT_ST_MEMSCOPE_STOP" displayName="memScopeStop" icon="images/memScopeStop.gif">
        </EventDescription>
        <EventDescription id="39202" name="EVENT_ST_MEMSCOPE_ALLOC" displayName="memScopeAlloc" icon="images/memScopeAlloc.gif">
            <EventParam isSearchKey="true" type="UINT32" name="address" formatStr="0x%08x"/>
            <EventParam isSearchKey="true" type="UINT32" name="partition" formatStr="0x%08x"/>
            <EventParam isSearchKey="true" type="UINT32" name="size"/>
        </EventDescription>
        <EventDescription id="39203" name="EVENT_ST_MEMSCOPE_FREE" displayName="memScopeFree" icon="images/memScopeFree.gif">
            <EventParam isSearchKey="true" type="UINT32" name="address" formatStr="0x%08x"/>
            <EventParam isSearchKey="true" type="UINT32" name="partition" formatStr="0x%08x"/>
        </EventDescription>
        <EventDescription id="39204" name="EVENT_ST_MEMSCOPE_FAILEDALLOC" displayName="memScopeFailedAlloc" icon="images/memScopeFailedAlloc.gif">
            <EventParam isSearchKey="true" type="UINT32" name="partition" formatStr="0x%08x"/>
            <EventParam isSearchKey="true" type="UINT32" name="size"/>
        </EventDescription>
        <EventDescription id="39205" name="EVENT_ST_MEMSCOPE_OVERFLOW" displayName="memScopeOverflow" icon="images/memScopeOverflow.gif">
        </EventDescription>

    </EventClass>
</EventDictionary>
)delim";


std::string v7_32_smp_sdLib_xml = R"delim(
<?xml version="1.0" encoding="UTF-8"?>
<!--
/* sdLib.xml - XML descriptions for vxWorks 6 sdLib events */

/* Copyright 2008 Wind River Systems, Inc. */

/*
 * This file contains descriptions for the sdLib events
 */

/*
modification history
01a,12may08,tcr  created from 6.6 version
*/
-->
<!DOCTYPE EventDictionary SYSTEM "../../DTDs/EventDictionary.dtd">
<EventDictionary>
    <EventClass key="sdLib" displayName="sdLib (Shared Data) Events" helpTopicId="VXWORKS6_SDLIB_CLASS_HELP">

        <EventDescription id="10200" name="EVENT_SD_CREATE" hasTimeStamp="true"
        trigger="true" displayName="sdCreate" isSearchable="true" 
        helpTopicId="VXWORKS6_EVENT_SD_CREATE_HELP" icon="images/sdCreate.gif">
            <EventParam type="UINT32" isSearchKey="true" name="sdId" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="options" formatStr="0x%x"/>
            <EventParam type="UINT32" name="size" formatStr="0x%x"/>
            <EventParam type="UINT32" name="attr" formatStr="0x%x"/>
            <EventParam type="UINT32" name="virtAddr" formatStr="0x%08x"/>
            <EventParam type="BLOB" name="name"/>
        </EventDescription>

        <EventDescription id="10201" name="EVENT_SD_DELETE" hasTimeStamp="true"
        trigger="true" displayName="sdDelete" isSearchable="true" 
        helpTopicId="VXWORKS6_EVENT_SD_DELETE_HELP" icon="images/sdDelete.gif">
            <EventParam type="UINT32" name="options" formatStr="0x%x"/>
            <EventParam type="UINT32" isSearchKey="true" name="sdId" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10202" name="EVENT_SD_MAP" hasTimeStamp="true"
        trigger="true" displayName="sdMap" isSearchable="true" 
        helpTopicId="VXWORKS6_EVENT_SD_MAP_HELP" icon="images/sdMap.gif">
            <EventParam type="UINT32" name="options" formatStr="0x%x"/>
            <EventParam type="UINT32" name="attr" formatStr="0x%x"/>
            <EventParam type="UINT32" isSearchKey="true" name="sdId"
            formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10203" name="EVENT_SD_UNMAP" hasTimeStamp="true"
        trigger="true" displayName="sdUnmap" isSearchable="true" 
        helpTopicId="VXWORKS6_EVENT_SD_UNMAP_HELP" icon="images/sdUnmap.gif">
            <EventParam type="UINT32" name="options" formatStr="0x%x"/>
            <EventParam type="UINT32" isSearchKey="true" name="sdId" formatStr="0x%08x"/>
        </EventDescription>
    </EventClass>
</EventDictionary>
)delim";


std::string v7_32_smp_sensorpoint_xml = R"delim(
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE EventDictionary SYSTEM "../../DTDs/EventDictionary.dtd">
<EventDictionary>
  <EventClass key="dsm" displayName="Sensorpoint event">
    <EventDescription id="38000" name="Sensorpoint" trigger="false" displayName="Enter" icon="images/isrCreate.gif">
      <EventParam type="STRINGZ" name="enter" formatStr="%s"/>
    </EventDescription>
    <EventDescription id="38001" name="Sensorpoint" trigger="false" displayName="Exit" icon="images/isrDestroy.gif">
      <EventParam type="STRINGZ" name="exit" formatStr="%s"/>
    </EventDescription>
    <EventDescription id="38002" name="Sensorpoint" trigger="false" displayName="Line" icon="images/tick_undelay.gif">
      <EventParam type="STRINGZ" name="line" formatStr="%s"/>
    </EventDescription>
    <EventDescription id="38003" name="Sensorpoint" trigger="false" displayName="Param" icon="images/tick_undelay.gif">
      <EventParam type="STRINGZ" name="param" formatStr="%s"/>
    </EventDescription>
    <EventDescription id="38004" name="Sensorpoint" trigger="false" displayName="User" icon="images/tick_undelay.gif">
      <EventParam type="STRINGZ" name="user" formatStr="%s"/>
    </EventDescription>
    <EventDescription id="38005" name="Sensorpoint" trigger="false" displayName="Task Create" icon="images/taskSpawn.gif">
      <EventParam type="STRINGZ" name="task create" formatStr="%s"/>
    </EventDescription>
    <EventDescription id="38006" name="Sensorpoint" trigger="false" displayName="Task Delete" icon="images/taskDelete.gif">
      <EventParam type="STRINGZ" name="task delete" formatStr="%s"/>
    </EventDescription>
  </EventClass>
</EventDictionary>
)delim";


std::string v7_32_smp_syscalls_syn_xml_part1 = R"delim(
<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<!DOCTYPE EventDictionary SYSTEM "../../DTDs/EventDictionary.dtd">
<EventDictionary>
    <EventClass displayName="syscall Events" helpTopicId="VXWORKS6_SYSCALL_CLASS_HELP" key="syscall">
        <EventDescription displayName="_exit" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._exit" id="21000" isSearchable="true" name="EVENT_SCN__exit" syscallIdent="8,0">
            <EventParam formatStr="%d" name="status" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_open" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._open" id="21001" isSearchable="true" name="EVENT_SCN__open" syscallIdent="8,2">
            <EventParam formatStr="0x%08x" name="name" type="UINT32"/>
            <EventParam formatStr="%d" name="flags" type="UINT32"/>
            <EventParam formatStr="%d" name="mode" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_close" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._close" id="21002" isSearchable="true" name="EVENT_SCN__close" syscallIdent="8,3">
            <EventParam formatStr="%d" name="fd" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_read" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._read" id="21003" isSearchable="true" name="EVENT_SCN__read" syscallIdent="8,4">
            <EventParam formatStr="%d" name="fd" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="buffer" type="UINT32"/>
            <EventParam formatStr="%d" name="maxbytes" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_write" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._write" id="21004" isSearchable="true" name="EVENT_SCN__write" syscallIdent="8,5">
            <EventParam formatStr="%d" name="fd" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="buffer" type="UINT32"/>
            <EventParam formatStr="%d" name="nbytes" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_ioctl" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._ioctl" id="21005" isSearchable="true" name="EVENT_SCN__ioctl" syscallIdent="8,6">
            <EventParam formatStr="%d" name="fd" type="UINT32"/>
            <EventParam formatStr="%d" name="function" type="UINT32"/>
            <EventParam formatStr="%d" name="arg" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_dup" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._dup" id="21006" isSearchable="true" name="EVENT_SCN__dup" syscallIdent="8,7">
            <EventParam formatStr="%d" name="fd" type="UINT32"/>
            <EventParam formatStr="%d" name="startFd" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_dup2" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._dup2" id="21007" isSearchable="true" name="EVENT_SCN__dup2" syscallIdent="8,8">
            <EventParam formatStr="%d" name="fd" type="UINT32"/>
            <EventParam formatStr="%d" name="fd2" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_pipe" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._pipe" id="21008" isSearchable="true" name="EVENT_SCN__pipe" syscallIdent="8,9">
            <EventParam formatStr="0x%08x" name="fildes" type="UINT32"/>
            <EventParam formatStr="%d" name="flags" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_remove" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._remove" id="21009" isSearchable="true" name="EVENT_SCN__remove" syscallIdent="8,10">
            <EventParam formatStr="0x%08x" name="name" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_selectX" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._selectX" id="21010" isSearchable="true" name="EVENT_SCN__selectX" syscallIdent="8,11">
            <EventParam formatStr="%d" name="width" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="readFds" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="writeFds" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="excFds" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="timeout" type="UINT32"/>
            <EventParam formatStr="%d" name="clearSem" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_socket" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._socket" id="21011" isSearchable="true" name="EVENT_SCN__socket" syscallIdent="8,12">
            <EventParam formatStr="%d" name="domain" type="UINT32"/>
            <EventParam formatStr="%d" name="type" type="UINT32"/>
            <EventParam formatStr="%d" name="protocol" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_bind" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._bind" id="21012" isSearchable="true" name="EVENT_SCN__bind" syscallIdent="8,13">
            <EventParam formatStr="%d" name="s" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="name" type="UINT32"/>
            <EventParam formatStr="%d" name="namelen" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_listen" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._listen" id="21013" isSearchable="true" name="EVENT_SCN__listen" syscallIdent="8,14">
            <EventParam formatStr="%d" name="s" type="UINT32"/>
            <EventParam formatStr="%d" name="backlog" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_accept" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._accept" id="21014" isSearchable="true" name="EVENT_SCN__accept" syscallIdent="8,15">
            <EventParam formatStr="%d" name="s" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="addr" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="addrlen" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_connect" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._connect" id="21015" isSearchable="true" name="EVENT_SCN__connect" syscallIdent="8,16">
            <EventParam formatStr="%d" name="s" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="name" type="UINT32"/>
            <EventParam formatStr="%d" name="namelen" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_sendto" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._sendto" id="21016" isSearchable="true" name="EVENT_SCN__sendto" syscallIdent="8,17">
            <EventParam formatStr="%d" name="s" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="buf" type="UINT32"/>
            <EventParam formatStr="%d" name="bufLen" type="UINT32"/>
            <EventParam formatStr="%d" name="flags" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="to" type="UINT32"/>
            <EventParam formatStr="%d" name="tolen" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_send" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._send" id="21017" isSearchable="true" name="EVENT_SCN__send" syscallIdent="8,18">
            <EventParam formatStr="%d" name="s" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="buf" type="UINT32"/>
            <EventParam formatStr="%d" name="bufLen" type="UINT32"/>
            <EventParam formatStr="%d" name="flags" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_sendmsg" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._sendmsg" id="21018" isSearchable="true" name="EVENT_SCN__sendmsg" syscallIdent="8,19">
            <EventParam formatStr="%d" name="s" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="mp" type="UINT32"/>
            <EventParam formatStr="%d" name="flags" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_recvfrom" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._recvfrom" id="21019" isSearchable="true" name="EVENT_SCN__recvfrom" syscallIdent="8,20">
            <EventParam formatStr="%d" name="s" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="buf" type="UINT32"/>
            <EventParam formatStr="%d" name="bufLen" type="UINT32"/>
            <EventParam formatStr="%d" name="flags" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="from" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pFromLen" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_recv" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._recv" id="21020" isSearchable="true" name="EVENT_SCN__recv" syscallIdent="8,21">
            <EventParam formatStr="%d" name="s" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="buf" type="UINT32"/>
            <EventParam formatStr="%d" name="bufLen" type="UINT32"/>
            <EventParam formatStr="%d" name="flags" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_recvmsg" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._recvmsg" id="21021" isSearchable="true" name="EVENT_SCN__recvmsg" syscallIdent="8,22">
            <EventParam formatStr="%d" name="s" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="mp" type="UINT32"/>
            <EventParam formatStr="%d" name="flags" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_setsockopt" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._setsockopt" id="21022" isSearchable="true" name="EVENT_SCN__setsockopt" syscallIdent="8,23">
            <EventParam formatStr="%d" name="s" type="UINT32"/>
            <EventParam formatStr="%d" name="level" type="UINT32"/>
            <EventParam formatStr="%d" name="optname" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="optval" type="UINT32"/>
            <EventParam formatStr="%d" name="optlen" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_getsockopt" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._getsockopt" id="21023" isSearchable="true" name="EVENT_SCN__getsockopt" syscallIdent="8,24">
            <EventParam formatStr="%d" name="s" type="UINT32"/>
            <EventParam formatStr="%d" name="level" type="UINT32"/>
            <EventParam formatStr="%d" name="optname" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="optval" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="optlen" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_getsockname" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._getsockname" id="21024" isSearchable="true" name="EVENT_SCN__getsockname" syscallIdent="8,25">
            <EventParam formatStr="%d" name="s" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="name" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="namelen" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_getpeername" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._getpeername" id="21025" isSearchable="true" name="EVENT_SCN__getpeername" syscallIdent="8,26">
            <EventParam formatStr="%d" name="s" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="name" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="namelen" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_shutdown" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._shutdown" id="21026" isSearchable="true" name="EVENT_SCN__shutdown" syscallIdent="8,27">
            <EventParam formatStr="%d" name="s" type="UINT32"/>
            <EventParam formatStr="%d" name="how" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="mmap" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.mmap" id="21027" isSearchable="true" name="EVENT_SCN_mmap" syscallIdent="8,28">
            <EventParam formatStr="0x%08x" name="addr" type="UINT32"/>
            <EventParam formatStr="%d" name="len" type="UINT32"/>
            <EventParam formatStr="%d" name="prot" type="UINT32"/>
            <EventParam formatStr="%d" name="flags" type="UINT32"/>
            <EventParam formatStr="%d" name="fildes" type="UINT32"/>
            <EventParam formatStr="%d" name="off" type="UINT32"/>
            <EventParam formatStr="%d" name="Invalid_padding" type="UINT32"/>
            <EventParam formatStr="%d" name="Invalid_padding" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="munmap" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.munmap" id="21028" isSearchable="true" name="EVENT_SCN_munmap" syscallIdent="8,29">
            <EventParam formatStr="0x%08x" name="addr" type="UINT32"/>
            <EventParam formatStr="%d" name="len" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="mprotect" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.mprotect" id="21029" isSearchable="true" name="EVENT_SCN_mprotect" syscallIdent="8,30">
            <EventParam formatStr="0x%08x" name="addr" type="UINT32"/>
            <EventParam formatStr="%d" name="len" type="UINT32"/>
            <EventParam formatStr="%d" name="prot" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="kill" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.kill" id="21030" isSearchable="true" name="EVENT_SCN_kill" syscallIdent="8,31">
            <EventParam formatStr="%d" name="rtpId" type="UINT32"/>
            <EventParam formatStr="%d" name="signo" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_pause" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._pause" id="21031" isSearchable="true" name="EVENT_SCN__pause" syscallIdent="8,32"/>
        <EventDescription displayName="sigpending" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.sigpending" id="21032" isSearchable="true" name="EVENT_SCN_sigpending" syscallIdent="8,33">
            <EventParam formatStr="0x%08x" name="pSet" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="sigprocmask" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.sigprocmask" id="21033" isSearchable="true" name="EVENT_SCN_sigprocmask" syscallIdent="8,34">
            <EventParam formatStr="%d" name="how" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pSet" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pOset" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_sigqueue" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._sigqueue" id="21034" isSearchable="true" name="EVENT_SCN__sigqueue" syscallIdent="8,35">
            <EventParam formatStr="%d" name="rtpId" type="UINT32"/>
            <EventParam formatStr="%d" name="signo" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pValue" type="UINT32"/>
            <EventParam formatStr="%d" name="sigCode" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_sigsuspend" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._sigsuspend" id="21035" isSearchable="true" name="EVENT_SCN__sigsuspend" syscallIdent="8,36">
            <EventParam formatStr="0x%08x" name="pSet" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_sigtimedwait" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._sigtimedwait" id="21036" isSearchable="true" name="EVENT_SCN__sigtimedwait" syscallIdent="8,37">
            <EventParam formatStr="0x%08x" name="pSet" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pInfo" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pTime" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_sigaction" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._sigaction" id="21037" isSearchable="true" name="EVENT_SCN__sigaction" syscallIdent="8,38">
            <EventParam formatStr="%d" name="signo" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pAct" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pOact" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="retAddr" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_sigreturn" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._sigreturn" id="21038" isSearchable="true" name="EVENT_SCN__sigreturn" syscallIdent="8,39"/>
        <EventDescription displayName="chdir" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.chdir" id="21039" isSearchable="true" name="EVENT_SCN_chdir" syscallIdent="8,40">
            <EventParam formatStr="0x%08x" name="name" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_getcwd" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._getcwd" id="21040" isSearchable="true" name="EVENT_SCN__getcwd" syscallIdent="8,41">
            <EventParam formatStr="0x%08x" name="buffer" type="UINT32"/>
            <EventParam formatStr="%d" name="length" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="getpid" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.getpid" id="21041" isSearchable="true" name="EVENT_SCN_getpid" syscallIdent="8,43"/>
        <EventDescription displayName="getppid" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.getppid" id="21042" isSearchable="true" name="EVENT_SCN_getppid" syscallIdent="8,44"/>
        <EventDescription displayName="_waitpid" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._waitpid" id="21043" isSearchable="true" name="EVENT_SCN__waitpid" syscallIdent="8,45">
            <EventParam formatStr="%d" name="childRtpId" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pStatus" type="UINT32"/>
            <EventParam formatStr="%d" name="options" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="sysctl" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.sysctl" id="21044" isSearchable="true" name="EVENT_SCN_sysctl" syscallIdent="8,46">
            <EventParam formatStr="0x%08x" name="pName" type="UINT32"/>
            <EventParam formatStr="%d" name="nameLen" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pOld" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pOldLen" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pNew" type="UINT32"/>
            <EventParam formatStr="%d" name="newLen" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_schedPxInfoGet" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._schedPxInfoGet" id="21045" isSearchable="true" name="EVENT_SCN__schedPxInfoGet" syscallIdent="8,47">
            <EventParam formatStr="0x%08x" name="pTimeSlicingOn" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pTimeSlicePeriod" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="sigaltstack" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.sigaltstack" id="21046" isSearchable="true" name="EVENT_SCN_sigaltstack" syscallIdent="8,48">
            <EventParam formatStr="0x%08x" name="ss" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="oss" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_unlink" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._unlink" id="21047" isSearchable="true" name="EVENT_SCN__unlink" syscallIdent="8,49">
            <EventParam formatStr="0x%08x" name="name" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_link" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._link" id="21048" isSearchable="true" name="EVENT_SCN__link" syscallIdent="8,50">
            <EventParam formatStr="0x%08x" name="name" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="newname" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_fsync" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._fsync" id="21049" isSearchable="true" name="EVENT_SCN__fsync" syscallIdent="8,51">
            <EventParam formatStr="%d" name="fd" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_fdatasync" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._fdatasync" id="21050" isSearchable="true" name="EVENT_SCN__fdatasync" syscallIdent="8,52">
            <EventParam formatStr="%d" name="fd" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_rename" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._rename" id="21051" isSearchable="true" name="EVENT_SCN__rename" syscallIdent="8,53">
            <EventParam formatStr="0x%08x" name="oldname" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="newname" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_fpathconf" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._fpathconf" id="21052" isSearchable="true" name="EVENT_SCN__fpathconf" syscallIdent="8,54">
            <EventParam formatStr="%d" name="fd" type="UINT32"/>
            <EventParam formatStr="%d" name="name" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_pathconf" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._pathconf" id="21053" isSearchable="true" name="EVENT_SCN__pathconf" syscallIdent="8,55">
            <EventParam formatStr="0x%08x" name="path" type="UINT32"/>
            <EventParam formatStr="%d" name="name" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_access" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._access" id="21054" isSearchable="true" name="EVENT_SCN__access" syscallIdent="8,56">
            <EventParam formatStr="0x%08x" name="path" type="UINT32"/>
            <EventParam formatStr="%d" name="amode" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_chmod" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._chmod" id="21055" isSearchable="true" name="EVENT_SCN__chmod" syscallIdent="8,57">
            <EventParam formatStr="0x%08x" name="path" type="UINT32"/>
            <EventParam formatStr="%d" name="mode" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="pxTraceCreation" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.pxTraceCreation" id="21056" isSearchable="true" name="EVENT_SCN_pxTraceCreation" syscallIdent="8,58">
            <EventParam formatStr="%d" name="cmd" type="UINT32"/>
            <EventParam formatStr="%d" name="pid" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="attr" type="UINT32"/>
            <EventParam formatStr="%d" name="fd" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="trid" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="pxTraceCtl" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.pxTraceCtl" id="21057" isSearchable="true" name="EVENT_SCN_pxTraceCtl" syscallIdent="8,59">
            <EventParam formatStr="%d" name="cmd" type="UINT32"/>
            <EventParam formatStr="%d" name="trid" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="filter" type="UINT32"/>
            <EventParam formatStr="%d" name="how" type="UINT32"/>
            <EventParam formatStr="%d" name="thread_id" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pc" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="ptr_out" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="pxTraceEvent" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.pxTraceEvent" id="21058" isSearchable="true" name="EVENT_SCN_pxTraceEvent" syscallIdent="8,60">
            <EventParam formatStr="%d" name="cmd" type="UINT32"/>
            <EventParam formatStr="%d" name="id_in" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="data" type="UINT32"/>
            <EventParam formatStr="%d" name="data_len" type="UINT32"/>
            <EventParam formatStr="%d" name="thread_id" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pc" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="id_out" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="pxTraceEventNameQuery" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.pxTraceEventNameQuery" id="21059" isSearchable="true" name="EVENT_SCN_pxTraceEventNameQuery" syscallIdent="8,61">
            <EventParam formatStr="%d" name="cmd" type="UINT32"/>
            <EventParam formatStr="%d" name="trid" type="UINT32"/>
            <EventParam formatStr="%d" name="id_in1" type="UINT32"/>
            <EventParam formatStr="%d" name="id_in2" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="name" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="id_out" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="unavailable" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="pxTraceLog" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.pxTraceLog" id="21060" isSearchable="true" name="EVENT_SCN_pxTraceLog" syscallIdent="8,62">
            <EventParam formatStr="%d" name="cmd" type="UINT32"/>
            <EventParam formatStr="%d" name="trid_in" type="UINT32"/>
            <EventParam formatStr="%d" name="fd" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="trid_out" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="pxTraceEventGet" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.pxTraceEventGet" id="21061" isSearchable="true" name="EVENT_SCN_pxTraceEventGet" syscallIdent="8,63">
            <EventParam formatStr="%d" name="cmd" type="UINT32"/>
            <EventParam formatStr="%d" name="trid" type="UINT32"/>
            <EventParam formatStr="%d" name="num_bytes" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="timeout" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="event" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="data" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="data_len" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="unavailable" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="eventReceiveEx" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.eventReceiveEx" id="21062" isSearchable="true" name="EVENT_SCN_eventReceiveEx" syscallIdent="9,0">
            <EventParam formatStr="%d" name="events" type="UINT32"/>
            <EventParam formatStr="%d" name="options" type="UINT32"/>
            <EventParam formatStr="%d" name="timeout" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pEvtsReceived" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="eventSend" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.eventSend" id="21063" isSearchable="true" name="EVENT_SCN_eventSend" syscallIdent="9,1">
            <EventParam formatStr="%d" name="taskId" type="UINT32"/>
            <EventParam formatStr="%d" name="events" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="eventCtl" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.eventCtl" id="21064" isSearchable="true" name="EVENT_SCN_eventCtl" syscallIdent="9,2">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="%d" name="command" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pArg" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pArgSize" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_msgQSend" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._msgQSend" id="21065" isSearchable="true" name="EVENT_SCN__msgQSend" syscallIdent="9,3">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="buffer" type="UINT32"/>
            <EventParam formatStr="%d" name="nBytes" type="UINT32"/>
            <EventParam formatStr="%d" name="timeout" type="UINT32"/>
            <EventParam formatStr="%d" name="priority" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_msgQReceive" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._msgQReceive" id="21066" isSearchable="true" name="EVENT_SCN__msgQReceive" syscallIdent="9,4">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="buffer" type="UINT32"/>
            <EventParam formatStr="%d" name="maxNBytes" type="UINT32"/>
            <EventParam formatStr="%d" name="timeout" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_msgQOpen" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._msgQOpen" id="21067" isSearchable="true" name="EVENT_SCN__msgQOpen" syscallIdent="9,5">
            <EventParam formatStr="0x%08x" name="name" type="UINT32"/>
            <EventParam formatStr="%d" name="maxMsgs" type="UINT32"/>
            <EventParam formatStr="%d" name="maxMsgLength" type="UINT32"/>
            <EventParam formatStr="%d" name="options" type="UINT32"/>
            <EventParam formatStr="%d" name="mode" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="context" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="objDelete" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.objDelete" id="21068" isSearchable="true" name="EVENT_SCN_objDelete" syscallIdent="9,6">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="%d" name="options" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="objInfoGet" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.objInfoGet" id="21069" isSearchable="true" name="EVENT_SCN_objInfoGet" syscallIdent="9,7">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pInfo" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pInfoSize" type="UINT32"/>
            <EventParam formatStr="%d" name="level" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_semTake" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._semTake" id="21070" isSearchable="true" name="EVENT_SCN__semTake" syscallIdent="9,8">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="%d" name="timeout" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_semGive" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._semGive" id="21071" isSearchable="true" name="EVENT_SCN__semGive" syscallIdent="9,9">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_semOpen" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._semOpen" id="21072" isSearchable="true" name="EVENT_SCN__semOpen" syscallIdent="9,10">
            <EventParam formatStr="0x%08x" name="name" type="UINT32"/>
            <EventParam formatStr="%d" name="type" type="UINT32"/>
            <EventParam formatStr="%d" name="initState" type="UINT32"/>
            <EventParam formatStr="%d" name="options" type="UINT32"/>
            <EventParam formatStr="%d" name="mode" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="context" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_taskOpen" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._taskOpen" id="21074" isSearchable="true" name="EVENT_SCN__taskOpen" syscallIdent="9,12">
            <EventParam formatStr="0x%08x" name="pArgs" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_taskDelay" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._taskDelay" id="21075" isSearchable="true" name="EVENT_SCN__taskDelay" syscallIdent="9,14">
            <EventParam formatStr="%d" name="ticks" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="rtpSpawn" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.rtpSpawn" id="21076" isSearchable="true" name="EVENT_SCN_rtpSpawn" syscallIdent="9,15">
            <EventParam formatStr="0x%08x" name="rtpFileName" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="argv" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="envp" type="UINT32"/>
            <EventParam formatStr="%d" name="priority" type="UINT32"/>
            <EventParam formatStr="%d" name="uStackSize" type="UINT32"/>
            <EventParam formatStr="%d" name="options" type="UINT32"/>
            <EventParam formatStr="%d" name="taskOptions" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="rtpInfoGet" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.rtpInfoGet" id="21077" isSearchable="true" name="EVENT_SCN_rtpInfoGet" syscallIdent="9,16">
            <EventParam formatStr="%d" name="rtpId" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="rtpStruct" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="taskKill" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.taskKill" id="21078" isSearchable="true" name="EVENT_SCN_taskKill" syscallIdent="9,17">
            <EventParam formatStr="%d" name="taskHandle" type="UINT32"/>
            <EventParam formatStr="%d" name="signo" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_taskSigqueue" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._taskSigqueue" id="21079" isSearchable="true" name="EVENT_SCN__taskSigqueue" syscallIdent="9,18">
            <EventParam formatStr="%d" name="taskHandle" type="UINT32"/>
            <EventParam formatStr="%d" name="signo" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pValue" type="UINT32"/>
            <EventParam formatStr="%d" name="sigCode" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_timer_open" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._timer_open" id="21080" isSearchable="true" name="EVENT_SCN__timer_open" syscallIdent="9,19">
            <EventParam formatStr="0x%08x" name="name" type="UINT32"/>
            <EventParam formatStr="%d" name="mode" type="UINT32"/>
            <EventParam formatStr="%d" name="clockId" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="evp" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="context" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="timerCtl" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.timerCtl" id="21081" isSearchable="true" name="EVENT_SCN_timerCtl" syscallIdent="9,20">
            <EventParam formatStr="%d" name="cmdCode" type="UINT32"/>
            <EventParam formatStr="%d" name="timerHandle" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pArgs" type="UINT32"/>
            <EventParam formatStr="%d" name="pArgSize" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="pxOpen" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.pxOpen" id="21082" isSearchable="true" name="EVENT_SCN_pxOpen" syscallIdent="9,21">
            <EventParam formatStr="%d" name="type" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="name" type="UINT32"/>
            <EventParam formatStr="%d" name="objOpenMode" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="attr" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="pxClose" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.pxClose" id="21083" isSearchable="true" name="EVENT_SCN_pxClose" syscallIdent="9,22">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="pxUnlink" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.pxUnlink" id="21084" isSearchable="true" name="EVENT_SCN_pxUnlink" syscallIdent="9,23">
            <EventParam formatStr="%d" name="type" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="name" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="pxCtl" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.pxCtl" id="21085" isSearchable="true" name="EVENT_SCN_pxCtl" syscallIdent="9,24">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="%d" name="cmdCode" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pArgs" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pArgSize" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="pxMqReceive" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.pxMqReceive" id="21086" isSearchable="true" name="EVENT_SCN_pxMqReceive" syscallIdent="9,25">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pMsg" type="UINT32"/>
            <EventParam formatStr="%d" name="msgLen" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pMsgPrio" type="UINT32"/>
            <EventParam formatStr="%d" name="waitOption" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="time_out" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="pxMqSend" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.pxMqSend" id="21087" isSearchable="true" name="EVENT_SCN_pxMqSend" syscallIdent="9,26">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pMsg" type="UINT32"/>
            <EventParam formatStr="%d" name="msgLen" type="UINT32"/>
            <EventParam formatStr="%d" name="msgPrio" type="UINT32"/>
            <EventParam formatStr="%d" name="waitOption" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="time_out" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="pxSemWait" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.pxSemWait" id="21088" isSearchable="true" name="EVENT_SCN_pxSemWait" syscallIdent="9,27">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="%d" name="waitOption" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="time_out" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="pxSemPost" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.pxSemPost" id="21089" isSearchable="true" name="EVENT_SCN_pxSemPost" syscallIdent="9,28">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="pipeDevCreate" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.pipeDevCreate" id="21090" isSearchable="true" name="EVENT_SCN_pipeDevCreate" syscallIdent="9,29">
            <EventParam formatStr="0x%08x" name="name" type="UINT32"/>
            <EventParam formatStr="%d" name="nMessages" type="UINT32"/>
            <EventParam formatStr="%d" name="nBytes" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="pipeDevDelete" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.pipeDevDelete" id="21091" isSearchable="true" name="EVENT_SCN_pipeDevDelete" syscallIdent="9,30">
            <EventParam formatStr="0x%08x" name="name" type="UINT32"/>
            <EventParam formatStr="%d" name="force" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_sdCreate" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._sdCreate" id="21092" isSearchable="true" name="EVENT_SCN__sdCreate" syscallIdent="9,31">
            <EventParam formatStr="0x%08x" name="name" type="UINT32"/>
            <EventParam formatStr="%d" name="options" type="UINT32"/>
            <EventParam formatStr="%d" name="size" type="UINT32"/>
            <EventParam formatStr="%d" name="physAddress" type="UINT32"/>
            <EventParam formatStr="%d" name="attr" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pVirtAddress" type="UINT32"/>
            <EventParam formatStr="%d" name="Invalid_padding" type="UINT32"/>
            <EventParam formatStr="%d" name="Invalid_padding" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_sdOpen" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._sdOpen" id="21093" isSearchable="true" name="EVENT_SCN__sdOpen" syscallIdent="9,32">
            <EventParam formatStr="0x%08x" name="name" type="UINT32"/>
            <EventParam formatStr="%d" name="options" type="UINT32"/>
            <EventParam formatStr="%d" name="mode" type="UINT32"/>
            <EventParam formatStr="%d" name="size" type="UINT32"/>
            <EventParam formatStr="%d" name="physAddress" type="UINT32"/>
            <EventParam formatStr="%d" name="attr" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pVirtAddress" type="UINT32"/>
            <EventParam formatStr="%d" name="Invalid_padding" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="sdDelete" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.sdDelete" id="21094" isSearchable="true" name="EVENT_SCN_sdDelete" syscallIdent="9,33">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="%d" name="options" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="sdMap" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.sdMap" id="21095" isSearchable="true" name="EVENT_SCN_sdMap" syscallIdent="9,34">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="%d" name="attr" type="UINT32"/>
            <EventParam formatStr="%d" name="options" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="sdUnmap" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.sdUnmap" id="21096" isSearchable="true" name="EVENT_SCN_sdUnmap" syscallIdent="9,35">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="%d" name="options" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="sdProtect" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.sdProtect" id="21097" isSearchable="true" name="EVENT_SCN_sdProtect" syscallIdent="9,36">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="%d" name="attr" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_edrErrorInject" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._edrErrorInject" id="21098" isSearchable="true" name="EVENT_SCN__edrErrorInject" syscallIdent="9,37">
            <EventParam formatStr="%d" name="kind" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="fileName" type="UINT32"/>
            <EventParam formatStr="%d" name="lineNumber" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="regset" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="addr" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="msg" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="edrFlagsGet" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.edrFlagsGet" id="21099" isSearchable="true" name="EVENT_SCN_edrFlagsGet" syscallIdent="9,38"/>
        <EventDescription displayName="wvEvent" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.wvEvent" id="21100" isSearchable="true" name="EVENT_SCN_wvEvent" syscallIdent="9,40">
            <EventParam formatStr="%d" name="eventId" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pData" type="UINT32"/>
            <EventParam formatStr="%d" name="dataSize" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="rtpVarAdd" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.rtpVarAdd" id="21101" isSearchable="true" name="EVENT_SCN_rtpVarAdd" syscallIdent="9,41">
            <EventParam formatStr="0x%08x" name="pVar" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="value" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="sdInfoGet" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.sdInfoGet" id="21102" isSearchable="true" name="EVENT_SCN_sdInfoGet" syscallIdent="9,42">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pSdStruct" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_shlOpen" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._shlOpen" id="21103" isSearchable="true" name="EVENT_SCN__shlOpen" syscallIdent="9,43">
            <EventParam formatStr="0x%08x" name="name" type="UINT32"/>
            <EventParam formatStr="%d" name="options" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_shlUnlock" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._shlUnlock" id="21104" isSearchable="true" name="EVENT_SCN__shlUnlock" syscallIdent="9,44">
            <EventParam formatStr="%d" name="shlId" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_shlClose" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._shlClose" id="21105" isSearchable="true" name="EVENT_SCN__shlClose" syscallIdent="9,45">
            <EventParam formatStr="%d" name="shlId" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_shlGet" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._shlGet" id="21106" isSearchable="true" name="EVENT_SCN__shlGet" syscallIdent="9,46">
            <EventParam formatStr="%d" name="shlId" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pInfo" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_shlPut" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._shlPut" id="21107" isSearchable="true" name="EVENT_SCN__shlPut" syscallIdent="9,47">
            <EventParam formatStr="%d" name="shlId" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pInfo" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="objUnlink" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.objUnlink" id="21108" isSearchable="true" name="EVENT_SCN_objUnlink" syscallIdent="9,48">
            <EventParam formatStr="0x%08x" name="name" type="UINT32"/>
            <EventParam formatStr="%d" name="classType" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="getprlimit" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.getprlimit" id="21109" isSearchable="true" name="EVENT_SCN_getprlimit" syscallIdent="9,49">
            <EventParam formatStr="%d" name="idtype" type="UINT32"/>
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="%d" name="resource" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="rlp" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="setprlimit" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.setprlimit" id="21110" isSearchable="true" name="EVENT_SCN_setprlimit" syscallIdent="9,50">
            <EventParam formatStr="%d" name="idtype" type="UINT32"/>
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="%d" name="resource" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="rlp" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_mctl" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._mctl" id="21111" isSearchable="true" name="EVENT_SCN__mctl" syscallIdent="9,51">
            <EventParam formatStr="0x%08x" name="addr" type="UINT32"/>
            <EventParam formatStr="%d" name="len" type="UINT32"/>
            <EventParam formatStr="%d" name="function" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="arg" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_taskOpenWithGuard" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._taskOpenWithGuard" id="21112" isSearchable="true" name="EVENT_SCN__taskOpenWithGuard" syscallIdent="9,52">
            <EventParam formatStr="0x%08x" name="pArgs" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="clockCtl" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.clockCtl" id="21113" isSearchable="true" name="EVENT_SCN_clockCtl" syscallIdent="9,53">
            <EventParam formatStr="%d" name="clock_id" type="UINT32"/>
            <EventParam formatStr="%d" name="cmdCode" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pArgStruct" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pArgSize" type="UINT32"/>
        </EventDescription>
        </EventClass>
</EventDictionary>
)delim";

std::string v7_32_smp_syscalls_syn_xml_part2 = R"delim(
<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<!DOCTYPE EventDictionary SYSTEM "../../DTDs/EventDictionary.dtd">
<EventDictionary>
    <EventClass displayName="syscall Events" helpTopicId="VXWORKS6_SYSCALL_CLASS_HELP" key="syscall">
        <EventDescription displayName="_semRTake" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._semRTake" id="21114" isSearchable="true" name="EVENT_SCN__semRTake" syscallIdent="9,54">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="%d" name="timeout" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_semWTake" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._semWTake" id="21115" isSearchable="true" name="EVENT_SCN__semWTake" syscallIdent="9,55">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="%d" name="timeout" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_semExchange" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._semExchange" id="21116" isSearchable="true" name="EVENT_SCN__semExchange" syscallIdent="9,56">
            <EventParam formatStr="%d" name="giveHandle" type="UINT32"/>
            <EventParam formatStr="%d" name="takeHandle" type="UINT32"/>
            <EventParam formatStr="%d" name="timeout" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="wvRtpEvent" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.wvRtpEvent" id="21117" isSearchable="true" name="EVENT_SCN_wvRtpEvent" syscallIdent="9,57">
            <EventParam formatStr="%d" name="eventId" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pData" type="UINT32"/>
            <EventParam formatStr="%d" name="dataSize" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_taskTcbCurrentGet" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._taskTcbCurrentGet" id="21118" isSearchable="true" name="EVENT_SCN__taskTcbCurrentGet" syscallIdent="9,58"/>
        <EventDescription displayName="_condVarOpen" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._condVarOpen" id="21119" isSearchable="true" name="EVENT_SCN__condVarOpen" syscallIdent="9,59">
            <EventParam formatStr="0x%08x" name="name" type="UINT32"/>
            <EventParam formatStr="%d" name="options" type="UINT32"/>
            <EventParam formatStr="%d" name="mode" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="context" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_condVarWait" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._condVarWait" id="21120" isSearchable="true" name="EVENT_SCN__condVarWait" syscallIdent="9,60">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="%d" name="mtx_handle" type="UINT32"/>
            <EventParam formatStr="%d" name="timeout" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_condVarSignal" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._condVarSignal" id="21121" isSearchable="true" name="EVENT_SCN__condVarSignal" syscallIdent="9,61">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="%d" name="broadcast" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="userAuthenticate" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.userAuthenticate" id="21122" isSearchable="true" name="EVENT_SCN_userAuthenticate" syscallIdent="9,62">
            <EventParam formatStr="0x%08x" name="loginName" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="clearPassword" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pUserId" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pGroupId" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="userPasswordUpdate" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.userPasswordUpdate" id="21123" isSearchable="true" name="EVENT_SCN_userPasswordUpdate" syscallIdent="9,63">
            <EventParam formatStr="0x%08x" name="loginName" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="oldClearPassword" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="newClearPassword" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_getpwuid" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._getpwuid" id="21124" isSearchable="true" name="EVENT_SCN__getpwuid" syscallIdent="15,0">
            <EventParam formatStr="%d" name="userId" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pwd" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="buffer" type="UINT32"/>
            <EventParam formatStr="%d" name="bufsize" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_getpwnam" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._getpwnam" id="21125" isSearchable="true" name="EVENT_SCN__getpwnam" syscallIdent="15,1">
            <EventParam formatStr="0x%08x" name="loginName" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pwd" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="buffer" type="UINT32"/>
            <EventParam formatStr="%d" name="bufsize" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_setuid" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._setuid" id="21126" isSearchable="true" name="EVENT_SCN__setuid" syscallIdent="15,2">
            <EventParam formatStr="%d" name="uid" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_getuid" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._getuid" id="21127" isSearchable="true" name="EVENT_SCN__getuid" syscallIdent="15,3"/>
        <EventDescription displayName="_setgid" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._setgid" id="21128" isSearchable="true" name="EVENT_SCN__setgid" syscallIdent="15,4">
            <EventParam formatStr="%d" name="gid" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_getgid" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._getgid" id="21129" isSearchable="true" name="EVENT_SCN__getgid" syscallIdent="15,5"/>
        <EventDescription displayName="_seteuid" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._seteuid" id="21130" isSearchable="true" name="EVENT_SCN__seteuid" syscallIdent="15,6">
            <EventParam formatStr="%d" name="euid" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_geteuid" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._geteuid" id="21131" isSearchable="true" name="EVENT_SCN__geteuid" syscallIdent="15,7"/>
        <EventDescription displayName="_setegid" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._setegid" id="21132" isSearchable="true" name="EVENT_SCN__setegid" syscallIdent="15,8">
            <EventParam formatStr="%d" name="egid" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_getegid" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._getegid" id="21133" isSearchable="true" name="EVENT_SCN__getegid" syscallIdent="15,9"/>
        <EventDescription displayName="getlogin_r" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.getlogin_r" id="21134" isSearchable="true" name="EVENT_SCN_getlogin_r" syscallIdent="15,10">
            <EventParam formatStr="0x%08x" name="loginName" type="UINT32"/>
            <EventParam formatStr="%d" name="nameSz" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_clock_getres" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._clock_getres" id="21135" isSearchable="true" name="EVENT_SCN__clock_getres" syscallIdent="15,11">
            <EventParam formatStr="%d" name="clock_id" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="res" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_clock_gettime" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._clock_gettime" id="21136" isSearchable="true" name="EVENT_SCN__clock_gettime" syscallIdent="15,12">
            <EventParam formatStr="%d" name="clock_id" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="tp" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_clock_settime" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._clock_settime" id="21137" isSearchable="true" name="EVENT_SCN__clock_settime" syscallIdent="15,13">
            <EventParam formatStr="%d" name="clock_id" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="tp" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_umask" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._umask" id="21138" isSearchable="true" name="EVENT_SCN__umask" syscallIdent="15,14">
            <EventParam formatStr="%d" name="cmask" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_sigtimedwait2" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._sigtimedwait2" id="21139" isSearchable="true" name="EVENT_SCN__sigtimedwait2" syscallIdent="15,15">
            <EventParam formatStr="0x%08x" name="pSet" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pInfo" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pTime" type="UINT32"/>
            <EventParam formatStr="%d" name="version" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_posix_spawn" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._posix_spawn" id="21140" isSearchable="true" name="EVENT_SCN__posix_spawn" syscallIdent="15,16">
            <EventParam formatStr="0x%08x" name="pPid" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="path" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pFile_actions" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pPxSpawnAttr" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="argv" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="envp" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_clock_getres2" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._clock_getres2" id="21141" isSearchable="true" name="EVENT_SCN__clock_getres2" syscallIdent="15,17">
            <EventParam formatStr="%d" name="clock_id" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="res" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_clock_gettime2" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._clock_gettime2" id="21142" isSearchable="true" name="EVENT_SCN__clock_gettime2" syscallIdent="15,18">
            <EventParam formatStr="%d" name="clock_id" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="tp" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_clock_settime2" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._clock_settime2" id="21143" isSearchable="true" name="EVENT_SCN__clock_settime2" syscallIdent="15,19">
            <EventParam formatStr="%d" name="clock_id" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="tp" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_execve" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._execve" id="21144" isSearchable="true" name="EVENT_SCN__execve" syscallIdent="15,20">
            <EventParam formatStr="0x%08x" name="*filename" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="*argv" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="*envp" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_clone" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._clone" id="21145" isSearchable="true" name="EVENT_SCN__clone" syscallIdent="15,21">
            <EventParam formatStr="%d" name="flags" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pArgs" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="randNumGenCtl" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.randNumGenCtl" id="21146" isSearchable="true" name="EVENT_SCN_randNumGenCtl" syscallIdent="16,0">
            <EventParam formatStr="%d" name="command" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pArg" type="UINT32"/>
            <EventParam formatStr="%d" name="pArgSize" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="taskStateCtl" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.taskStateCtl" id="21147" isSearchable="true" name="EVENT_SCN_taskStateCtl" syscallIdent="16,1">
            <EventParam formatStr="%d" name="tid" type="UINT32"/>
            <EventParam formatStr="%d" name="command" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pArg" type="UINT32"/>
            <EventParam formatStr="%d" name="argSize" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="taskParamCtl" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.taskParamCtl" id="21148" isSearchable="true" name="EVENT_SCN_taskParamCtl" syscallIdent="16,2">
            <EventParam formatStr="%d" name="tid" type="UINT32"/>
            <EventParam formatStr="%d" name="command" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pArg" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="taskPriCtl" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.taskPriCtl" id="21149" isSearchable="true" name="EVENT_SCN_taskPriCtl" syscallIdent="16,3">
            <EventParam formatStr="%d" name="tid" type="UINT32"/>
            <EventParam formatStr="%d" name="command" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pArg" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="taskCpuAffCtl" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.taskCpuAffCtl" id="21150" isSearchable="true" name="EVENT_SCN_taskCpuAffCtl" syscallIdent="16,4">
            <EventParam formatStr="%d" name="tid" type="UINT32"/>
            <EventParam formatStr="%d" name="command" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pArg" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="taskVarCtl" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.taskVarCtl" id="21151" isSearchable="true" name="EVENT_SCN_taskVarCtl" syscallIdent="16,5">
            <EventParam formatStr="%d" name="tid" type="UINT32"/>
            <EventParam formatStr="%d" name="command" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pVar" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pValue" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="taskPxAttrCtl" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.taskPxAttrCtl" id="21152" isSearchable="true" name="EVENT_SCN_taskPxAttrCtl" syscallIdent="16,6">
            <EventParam formatStr="%d" name="tid" type="UINT32"/>
            <EventParam formatStr="%d" name="command" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pArg" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_taskWait" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._taskWait" id="21153" isSearchable="true" name="EVENT_SCN__taskWait" syscallIdent="16,7">
            <EventParam formatStr="%d" name="tid" type="UINT32"/>
            <EventParam formatStr="%d" name="timeout" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="atomic32Op" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.atomic32Op" id="21154" isSearchable="true" name="EVENT_SCN_atomic32Op" syscallIdent="16,8">
            <EventParam formatStr="0x%08x" name="target" type="UINT32"/>
            <EventParam formatStr="%d" name="oldValue" type="UINT32"/>
            <EventParam formatStr="%d" name="value" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="returnVal" type="UINT32"/>
            <EventParam formatStr="%d" name="atomicSwitch" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="atomic64Op" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.atomic64Op" id="21155" isSearchable="true" name="EVENT_SCN_atomic64Op" syscallIdent="16,9">
            <EventParam formatStr="0x%08x" name="target" type="UINT32"/>
            <EventParam formatStr="%d" name="oldValue" type="UINT32"/>
            <EventParam formatStr="%d" name="value" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="returnVal" type="UINT32"/>
            <EventParam formatStr="%d" name="atomicSwitch" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_rtpTaskExitRegister" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._rtpTaskExitRegister" id="21156" isSearchable="true" name="EVENT_SCN__rtpTaskExitRegister" syscallIdent="16,10">
            <EventParam formatStr="0x%08x" name="funcPtr" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="vxSysInfoGet" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.vxSysInfoGet" id="21157" isSearchable="true" name="EVENT_SCN_vxSysInfoGet" syscallIdent="16,11">
            <EventParam formatStr="0x%08x" name="pVxSysInfo" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_tick64Get" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._tick64Get" id="21158" isSearchable="true" name="EVENT_SCN__tick64Get" syscallIdent="16,12">
            <EventParam formatStr="0x%08x" name="pTickVal" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="tickRateGet" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.tickRateGet" id="21159" isSearchable="true" name="EVENT_SCN_tickRateGet" syscallIdent="16,13"/>
        <EventDescription displayName="shmVolNameGet" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.shmVolNameGet" id="21160" isSearchable="true" name="EVENT_SCN_shmVolNameGet" syscallIdent="16,14">
            <EventParam formatStr="0x%08x" name="name" type="UINT32"/>
            <EventParam formatStr="%d" name="len" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_selWakeupOp" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._selWakeupOp" id="21161" isSearchable="true" name="EVENT_SCN__selWakeupOp" syscallIdent="16,15">
            <EventParam formatStr="%d" name="tid" type="UINT32"/>
            <EventParam formatStr="%d" name="op" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_umiosFdGet" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._umiosFdGet" id="21162" isSearchable="true" name="EVENT_SCN__umiosFdGet" syscallIdent="16,16"/>
        <EventDescription displayName="_pipeAnonCreate" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._pipeAnonCreate" id="21163" isSearchable="true" name="EVENT_SCN__pipeAnonCreate" syscallIdent="16,17">
            <EventParam formatStr="%d" name="nMessages" type="UINT32"/>
            <EventParam formatStr="%d" name="nBytes" type="UINT32"/>
            <EventParam formatStr="%d" name="flags" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pFd" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="taskDelayEx" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.taskDelayEx" id="21164" isSearchable="true" name="EVENT_SCN_taskDelayEx" syscallIdent="16,18">
            <EventParam formatStr="%d" name="ticks" type="UINT32"/>
            <EventParam formatStr="%d" name="flags" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="clock_getinfo" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.clock_getinfo" id="21165" isSearchable="true" name="EVENT_SCN_clock_getinfo" syscallIdent="16,19">
            <EventParam formatStr="%d" name="clock_id" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="clk_info" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_pathIsAbsolute" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._pathIsAbsolute" id="21166" isSearchable="true" name="EVENT_SCN__pathIsAbsolute" syscallIdent="16,20">
            <EventParam formatStr="0x%08x" name="name" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pNameTail" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_realpath" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._realpath" id="21167" isSearchable="true" name="EVENT_SCN__realpath" syscallIdent="16,21">
            <EventParam formatStr="0x%08x" name="fileName" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="resolvedName" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_dupX" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._dupX" id="21168" isSearchable="true" name="EVENT_SCN__dupX" syscallIdent="16,22">
            <EventParam formatStr="%d" name="fd" type="UINT32"/>
            <EventParam formatStr="%d" name="startFd" type="UINT32"/>
            <EventParam formatStr="%d" name="fdFlags" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_semMTakeByProxy" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._semMTakeByProxy" id="21169" isSearchable="true" name="EVENT_SCN__semMTakeByProxy" syscallIdent="16,23">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="%d" name="semOwnerTaskId" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="semOwnerGet" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.semOwnerGet" id="21170" isSearchable="true" name="EVENT_SCN_semOwnerGet" syscallIdent="16,24">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pSemOwner" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_semFlush" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._semFlush" id="21171" isSearchable="true" name="EVENT_SCN__semFlush" syscallIdent="16,25">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="semMTakeHard" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.semMTakeHard" id="21172" isSearchable="true" name="EVENT_SCN_semMTakeHard" syscallIdent="16,26">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pUserSemOwner" type="UINT32"/>
            <EventParam formatStr="%d" name="timeout" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="semMGiveHard" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.semMGiveHard" id="21173" isSearchable="true" name="EVENT_SCN_semMGiveHard" syscallIdent="16,27">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pUserSemOwner" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pSendEvents" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="semUserExchange" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.semUserExchange" id="21174" isSearchable="true" name="EVENT_SCN_semUserExchange" syscallIdent="16,28">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="%d" name="takeSemId" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pUserGiveSemOwner" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pUserTakeSemOwner" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pSendEvents" type="UINT32"/>
            <EventParam formatStr="%d" name="timeout" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_vxeAbsPathGet" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._vxeAbsPathGet" id="21175" isSearchable="true" name="EVENT_SCN__vxeAbsPathGet" syscallIdent="16,29">
            <EventParam formatStr="%d" name="rtpId" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="path" type="UINT32"/>
            <EventParam formatStr="%d" name="pathlen" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="envAccess" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.envAccess" id="21176" isSearchable="true" name="EVENT_SCN_envAccess" syscallIdent="16,30">
            <EventParam formatStr="0x%08x" name="valsize" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="valueBuf" type="UINT32"/>
            <EventParam formatStr="%d" name="valBufSize" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="name" type="UINT32"/>
            <EventParam formatStr="%d" name="namelen" type="UINT32"/>
            <EventParam formatStr="%d" name="extFlags" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_semUBTake" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._semUBTake" id="21177" isSearchable="true" name="EVENT_SCN__semUBTake" syscallIdent="16,31">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pSemUBState" type="UINT32"/>
            <EventParam formatStr="%d" name="timeout" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_semUBGive" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._semUBGive" id="21178" isSearchable="true" name="EVENT_SCN__semUBGive" syscallIdent="16,32">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pSemUBState" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pSendEvents" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="vxnsCreate" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.vxnsCreate" id="21179" isSearchable="true" name="EVENT_SCN_vxnsCreate" syscallIdent="16,33">
            <EventParam formatStr="%d" name="nsFlags" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="vxnsCtl" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.vxnsCtl" id="21180" isSearchable="true" name="EVENT_SCN_vxnsCtl" syscallIdent="16,34">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="%d" name="command" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="arg" type="UINT32"/>
            <EventParam formatStr="%d" name="argSize" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="clock_getinfo2" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.clock_getinfo2" id="21181" isSearchable="true" name="EVENT_SCN_clock_getinfo2" syscallIdent="16,35">
            <EventParam formatStr="%d" name="clock_id" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="clk_info" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_realpath2" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._realpath2" id="21182" isSearchable="true" name="EVENT_SCN__realpath2" syscallIdent="16,36">
            <EventParam formatStr="0x%08x" name="fileName" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="resolvedName" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_semMConsistent" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._semMConsistent" id="21183" isSearchable="true" name="EVENT_SCN__semMConsistent" syscallIdent="16,37">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_semUCTake" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._semUCTake" id="21184" isSearchable="true" name="EVENT_SCN__semUCTake" syscallIdent="16,38">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pSemUCCount" type="UINT32"/>
            <EventParam formatStr="%d" name="timeout" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_semUCGive" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._semUCGive" id="21185" isSearchable="true" name="EVENT_SCN__semUCGive" syscallIdent="16,39">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pSemUCCount" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pSendEvents" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_oioctl" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._oioctl" id="21186" isSearchable="true" name="EVENT_SCN__oioctl" syscallIdent="16,40">
            <EventParam formatStr="0x%08x" name="name" type="UINT32"/>
            <EventParam formatStr="%d" name="openFlags" type="UINT32"/>
            <EventParam formatStr="%d" name="openMode" type="UINT32"/>
            <EventParam formatStr="%d" name="function" type="UINT32"/>
            <EventParam formatStr="%d" name="arg" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_msgQUSend" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._msgQUSend" id="21187" isSearchable="true" name="EVENT_SCN__msgQUSend" syscallIdent="16,41">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="buffer" type="UINT32"/>
            <EventParam formatStr="%d" name="nBytes" type="UINT32"/>
            <EventParam formatStr="%d" name="timeout" type="UINT32"/>
            <EventParam formatStr="%d" name="priority" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pMsgQUState" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pSendEvents" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_msgQUReceive" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._msgQUReceive" id="21188" isSearchable="true" name="EVENT_SCN__msgQUReceive" syscallIdent="16,42">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="buffer" type="UINT32"/>
            <EventParam formatStr="%d" name="maxNBytes" type="UINT32"/>
            <EventParam formatStr="%d" name="timeout" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pMsgQUState" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pUMsgLength" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_pxMqUReceive" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._pxMqUReceive" id="21189" isSearchable="true" name="EVENT_SCN__pxMqUReceive" syscallIdent="16,43">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pMsg" type="UINT32"/>
            <EventParam formatStr="%d" name="msgLen" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pMsgPrio" type="UINT32"/>
            <EventParam formatStr="%d" name="waitOption" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="time_out" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pMsgQUStatePrio" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pUMsgLength" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="_pxMqUSend" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc._pxMqUSend" id="21190" isSearchable="true" name="EVENT_SCN__pxMqUSend" syscallIdent="16,44">
            <EventParam formatStr="%d" name="handle" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pMsg" type="UINT32"/>
            <EventParam formatStr="%d" name="msgLen" type="UINT32"/>
            <EventParam formatStr="%d" name="msgPrio" type="UINT32"/>
            <EventParam formatStr="%d" name="waitOption" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="time_out" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pMsgQUStatePrio" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="apexQueuingPortCreate" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.apexQueuingPortCreate" id="21191" isSearchable="true" name="EVENT_SCN_apexQueuingPortCreate" syscallIdent="17,0">
            <EventParam formatStr="0x%08x" name="qPortName" type="UINT32"/>
            <EventParam formatStr="%d" name="maxMsgSize" type="UINT32"/>
            <EventParam formatStr="%d" name="maxNumMsg" type="UINT32"/>
            <EventParam formatStr="%d" name="direction" type="UINT32"/>
            <EventParam formatStr="%d" name="discipline" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pObjPortHandle" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="apexQueuingPortSend" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.apexQueuingPortSend" id="21192" isSearchable="true" name="EVENT_SCN_apexQueuingPortSend" syscallIdent="17,1">
            <EventParam formatStr="%d" name="objPortHandle" type="UINT32"/>
            <EventParam formatStr="%d" name="msgAddr" type="UINT32"/>
            <EventParam formatStr="%d" name="msgLen" type="UINT32"/>
            <EventParam formatStr="%d" name="timeout" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="apexQueuingPortReceive" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.apexQueuingPortReceive" id="21193" isSearchable="true" name="EVENT_SCN_apexQueuingPortReceive" syscallIdent="17,2">
            <EventParam formatStr="%d" name="objPortHandle" type="UINT32"/>
            <EventParam formatStr="%d" name="timeout" type="UINT32"/>
            <EventParam formatStr="%d" name="msgAddr" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pMsgLen" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="apexQueuingPortIdGet" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.apexQueuingPortIdGet" id="21194" isSearchable="true" name="EVENT_SCN_apexQueuingPortIdGet" syscallIdent="17,3">
            <EventParam formatStr="0x%08x" name="qPortName" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pObjPortHandle" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="apexQueuingPortStatusGet" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.apexQueuingPortStatusGet" id="21195" isSearchable="true" name="EVENT_SCN_apexQueuingPortStatusGet" syscallIdent="17,4">
            <EventParam formatStr="%d" name="objPortHandle" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="portStatus" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="apexQueuingPortClear" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.apexQueuingPortClear" id="21196" isSearchable="true" name="EVENT_SCN_apexQueuingPortClear" syscallIdent="17,5">
            <EventParam formatStr="%d" name="objPortHandle" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="apexSamplingPortCreate" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.apexSamplingPortCreate" id="21197" isSearchable="true" name="EVENT_SCN_apexSamplingPortCreate" syscallIdent="17,6">
            <EventParam formatStr="0x%08x" name="sPortName" type="UINT32"/>
            <EventParam formatStr="%d" name="maxMsgSize" type="UINT32"/>
            <EventParam formatStr="%d" name="direction" type="UINT32"/>
            <EventParam formatStr="%d" name="refreshPeriod" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pObjPortHandle" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="apexSamplingPortWrite" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.apexSamplingPortWrite" id="21198" isSearchable="true" name="EVENT_SCN_apexSamplingPortWrite" syscallIdent="17,7">
            <EventParam formatStr="%d" name="objPortHandle" type="UINT32"/>
            <EventParam formatStr="%d" name="msgAddr" type="UINT32"/>
            <EventParam formatStr="%d" name="msgLen" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="apexSamplingPortRead" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.apexSamplingPortRead" id="21199" isSearchable="true" name="EVENT_SCN_apexSamplingPortRead" syscallIdent="17,8">
            <EventParam formatStr="%d" name="objPortHandle" type="UINT32"/>
            <EventParam formatStr="%d" name="msgAddr" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pMsgLen" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pValidity" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="apexSamplingPortIdGet" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.apexSamplingPortIdGet" id="21200" isSearchable="true" name="EVENT_SCN_apexSamplingPortIdGet" syscallIdent="17,9">
            <EventParam formatStr="0x%08x" name="sPortName" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pObjPortHandle" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="apexSamplingPortStatusGet" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.apexSamplingPortStatusGet" id="21201" isSearchable="true" name="EVENT_SCN_apexSamplingPortStatusGet" syscallIdent="17,10">
            <EventParam formatStr="%d" name="objPortHandle" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="portStatus" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="apexSamplingPortCurrStatusGet" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.apexSamplingPortCurrStatusGet" id="21202" isSearchable="true" name="EVENT_SCN_apexSamplingPortCurrStatusGet" syscallIdent="17,11">
            <EventParam formatStr="%d" name="objPortHandle" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="portCurrStatus" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="apexSamplingReadUpdatedMsg" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.apexSamplingReadUpdatedMsg" id="21203" isSearchable="true" name="EVENT_SCN_apexSamplingReadUpdatedMsg" syscallIdent="17,12">
            <EventParam formatStr="%d" name="objPortHandle" type="UINT32"/>
            <EventParam formatStr="%d" name="msgAddr" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pMsgLen" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pUpdated" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="apexSamplingReadMsgCond" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.apexSamplingReadMsgCond" id="21204" isSearchable="true" name="EVENT_SCN_apexSamplingReadMsgCond" syscallIdent="17,13">
            <EventParam formatStr="%d" name="objPortHandle" type="UINT32"/>
            <EventParam formatStr="%d" name="refTimeStamp" type="UINT32"/>
            <EventParam formatStr="%d" name="msgAddr" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pMsgLen" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="pTimestamp" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="hmOpen" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.hmOpen" id="21205" isSearchable="true" name="EVENT_SCN_hmOpen" syscallIdent="17,14">
            <EventParam formatStr="0x%08x" name="pTaskPrio" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="hmConnect" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.hmConnect" id="21206" isSearchable="true" name="EVENT_SCN_hmConnect" syscallIdent="17,15"/>
        <EventDescription displayName="hmEventSend" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.hmEventSend" id="21207" isSearchable="true" name="EVENT_SCN_hmEventSend" syscallIdent="17,16">
            <EventParam formatStr="%d" name="hmCode" type="UINT32"/>
            <EventParam formatStr="%d" name="subCode" type="UINT32"/>
            <EventParam formatStr="%d" name="addInfo" type="UINT32"/>
            <EventParam formatStr="%d" name="hmLevel" type="UINT32"/>
            <EventParam formatStr="%d" name="taskId" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="addr" type="UINT32"/>
            <EventParam formatStr="%d" name="msgLen" type="UINT32"/>
            <EventParam formatStr="0x%08x" name="msg" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="hmEventWait" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.hmEventWait" id="21208" isSearchable="true" name="EVENT_SCN_hmEventWait" syscallIdent="17,17">
            <EventParam formatStr="0x%08x" name="buffer" type="UINT32"/>
            <EventParam formatStr="%d" name="maxNBytes" type="UINT32"/>
        </EventDescription>
        <EventDescription displayName="hmClose" hasTimeStamp="true" helpTopicId="VXWORKS6_EVENT_SCN_GENERIC" icon="color=#ff0000,text=sc.hmClose" id="21209" isSearchable="true" name="EVENT_SCN_hmClose" syscallIdent="17,18"/>
    </EventClass>
</EventDictionary>
)delim";


std::string v7_32_smp_syscalls_xml = R"delim(
<?xml version="1.0" encoding="UTF-8"?>
<!--
/* syscalls.xml - XML descriptions for vxWorks 6 system calls from RTPs */

/* Copyright 2008 Wind River Systems, Inc.
 *
 * The right to copy, distribute, modify or otherwise make use
 * of this software may be licensed only pursuant to the terms
 * of an applicable Wind River license agreement.
 */

/*
 * This file contains descriptions for the raw syscalls events in the WindView log.
 */

/*
modification history
01a,12may08,tcr  created from 6.6 version 01i
*/
-->
<!DOCTYPE EventDictionary SYSTEM "../../DTDs/EventDictionary.dtd">
<EventDictionary>
    <EventClass key="syscall" displayName="syscall Events" helpTopicId="VXWORKS6_SYSCALL_CLASS_HELP">

        <EventDescription id="10065" name="EVENT_SYSCALL_0" hasTimeStamp="true" isSearchable="true" helpTopicId="VXWORKS6_EVENT_SYSCALL_0_HELP"
          icon="color=#ff0000,text=syscall (0 params)">
            <EventParam type="UINT16" name="syscallId" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10066" name="EVENT_SYSCALL_1" hasTimeStamp="true" isSearchable="true" helpTopicId="VXWORKS6_EVENT_SYSCALL_1_HELP"
          icon="color=#ff0000,text=syscall (1 param)">
            <EventParam type="UINT16" name="syscallId" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param1" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10067" name="EVENT_SYSCALL_2" hasTimeStamp="true" isSearchable="true" helpTopicId="VXWORKS6_EVENT_SYSCALL_2_HELP"
          icon="color=#ff0000,text=syscall (2 params)">
            <EventParam type="UINT16" name="syscallId" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param1" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param2" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10068" name="EVENT_SYSCALL_3" hasTimeStamp="true" isSearchable="true" helpTopicId="VXWORKS6_EVENT_SYSCALL_3_HELP"
          icon="color=#ff0000,text=syscall (3 params)">
            <EventParam type="UINT16" name="syscallId" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param1" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param2" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param3" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10069" name="EVENT_SYSCALL_4" hasTimeStamp="true" isSearchable="true" helpTopicId="VXWORKS6_EVENT_SYSCALL_4_HELP"
          icon="color=#ff0000,text=syscall (4 params)">
            <EventParam type="UINT16" name="syscallId" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param1" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param2" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param3" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param4" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10070" name="EVENT_SYSCALL_5" hasTimeStamp="true" isSearchable="true" helpTopicId="VXWORKS6_EVENT_SYSCALL_5_HELP"
          icon="color=#ff0000,text=syscall (5 params)">
            <EventParam type="UINT16" name="syscallId" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param1" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param2" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param3" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param4" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param5" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10071" name="EVENT_SYSCALL_6" hasTimeStamp="true" isSearchable="true" helpTopicId="VXWORKS6_EVENT_SYSCALL_6_HELP"
          icon="color=#ff0000,text=syscall (6 params)">
            <EventParam type="UINT16" name="syscallId" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param1" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param2" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param3" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param4" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param5" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param6" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10072" name="EVENT_SYSCALL_7" hasTimeStamp="true" isSearchable="true" helpTopicId="VXWORKS6_EVENT_SYSCALL_7_HELP"   
          icon="color=#ff0000,text=syscall (7 params)">
         <EventParam type="UINT16" name="syscallId" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param1" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param2" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param3" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param4" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param5" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param6" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param7" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10073" name="EVENT_SYSCALL_8" hasTimeStamp="true" isSearchable="true" helpTopicId="VXWORKS6_EVENT_SYSCALL_8_HELP"
          icon="color=#ff0000,text=syscall (8 params)">
            <EventParam type="UINT16" name="syscallId" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param1" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param2" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param3" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param4" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param5" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param6" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param7" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="param8" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10074" name="EVENT_RETURN_OK" hasTimeStamp="true"
            isSearchable="true" displayName="syscallReturn"
            helpTopicId="VXWORKS6_EVENT_SYSCALL_RETURN_OK" icon="images/sc_retok.gif">
            <EventParam type="UINT32" name="result" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10075" name="EVENT_RETURN_ERR" hasTimeStamp="true"
            isSearchable="true" displayName="syscallReturnError"
            helpTopicId="VXWORKS6_EVENT_SYSCALL_RETURN_ERROR" icon="images/sc_retbad.gif">
            <EventParam type="UINT32" name="errno" formatStr="0x%08x"/>
        </EventDescription>

        <EventDescription id="10076" name="EVENT_SYSCALL_BAD_ID"
                hasTimeStamp="true" isSearchable="true"
                helpTopicId="VXWORKS6_EVENT_SYSCALL_BAD_ID" displayName="badSysCallId"
                icon="images/sc_badSyscallId.gif">
            <EventParam type="UINT32" name="group" formatStr="0x%08x"/>
            <EventParam type="UINT32" name="routine" formatStr="0x%08x"/>
        </EventDescription>
    </EventClass>

</EventDictionary>
)delim";


std::string v7_32_smp_tipclib_xml = R"delim(
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE EventDictionary SYSTEM "../../DTDs/EventDictionary.dtd">
<EventDictionary>
    <EventClass key="wind_tipc" displayName="Wind TIPC events">
        <EventDescription id="20500" name="WV_TIPCEVENT_FATAL" displayName ="wvTipcFatal" icon="images/wvtipc-panic.gif">
	    <EventParam type="UINT32" name="wvEvtInfo:" formatter="com.windriver.windview.plugins.wv.windtipc.formatters.WvTipcInfoDecoder"/>
	    <EventParam type="UINT32" name="Function Name" formatter="com.windriver.windview.plugins.wv.windtipc.formatters.FuncDecoder"/>
	    <EventParam type="UINT32" name="Qualifier" formatter="com.windriver.windview.plugins.wv.windtipc.formatters.QualifierDecoder"/>
            <EventParam type="BLOB" name="Passed parameters:" formatter="com.windriver.windview.plugins.wv.windtipc.formatters.TipcBlobDecoder"/>
        </EventDescription>
        <EventDescription id="20505" name="WV_TIPCEVENT_CRITICAL" displayName ="wvTipcCritical" icon="images/wvtipc-error.gif">
	    <EventParam type="UINT32" name="wvEvtInfo:" formatter="com.windriver.windview.plugins.wv.windtipc.formatters.WvTipcInfoDecoder"/>
	    <EventParam type="UINT32" name="Function Name" formatter="com.windriver.windview.plugins.wv.windtipc.formatters.FuncDecoder"/>
	    <EventParam type="UINT32" name="Qualifier" formatter="com.windriver.windview.plugins.wv.windtipc.formatters.QualifierDecoder"/>
            <EventParam type="BLOB" name="Passed parameters:" formatter="com.windriver.windview.plugins.wv.windtipc.formatters.TipcBlobDecoder"/>
        </EventDescription>
        <EventDescription id="20510" name="WV_TIPCEVENT_WARNING" displayName ="wvTipcWarning" icon="images/wvtipc-warning.gif">
	    <EventParam type="UINT32" name="wvEvtInfo:" formatter="com.windriver.windview.plugins.wv.windtipc.formatters.WvTipcInfoDecoder"/>
	    <EventParam type="UINT32" name="Function Name" formatter="com.windriver.windview.plugins.wv.windtipc.formatters.FuncDecoder"/>
	    <EventParam type="UINT32" name="Qualifier" formatter="com.windriver.windview.plugins.wv.windtipc.formatters.QualifierDecoder"/>
            <EventParam type="BLOB" name="Passed parameters:" formatter="com.windriver.windview.plugins.wv.windtipc.formatters.TipcBlobDecoder"/>
        </EventDescription>
        <EventDescription id="20515" name="WV_TIPCEVENT_INFO" displayName ="wvTipcInfo" icon="images/wvtipc-info.gif">
	    <EventParam type="UINT32" name="wvEvtInfo:" formatter="com.windriver.windview.plugins.wv.windtipc.formatters.WvTipcInfoDecoder"/>
	    <EventParam type="UINT32" name="Function Name" formatter="com.windriver.windview.plugins.wv.windtipc.formatters.FuncDecoder"/>
	    <EventParam type="UINT32" name="SubType" formatter="com.windriver.windview.plugins.wv.windtipc.formatters.InfoSubTypeDecoder"/>
            <EventParam type="BLOB" name="Passed parameters:" formatter="com.windriver.windview.plugins.wv.windtipc.formatters.TipcBlobDecoder"/>
        </EventDescription>
        <EventDescription id="20520" name="WV_TIPCEVENT_START" displayName ="wvTipcStart" icon="images/wvtipc-start.gif">
	    <EventParam type="UINT32" name="wvEvtInfo:" formatter="com.windriver.windview.plugins.wv.windtipc.formatters.WvTipcInfoDecoder"/>
	    <EventParam type="UINT32" name="Function Name"  formatter="com.windriver.windview.plugins.wv.windtipc.formatters.FuncDecoder"/>
	    <EventParam type="UINT32" name="Parameter P0" formatStr="0x%08x"/>
            <EventParam type="BLOB" name="Passed parameters:" formatter="com.windriver.windview.plugins.wv.windtipc.formatters.TipcBlobDecoder"/>
        </EventDescription>
        <EventDescription id="20521" name="WV_TIPCEVENT_FINISH" displayName ="wvTipcFinish" icon="images/wvtipc-finish.gif">
	    <EventParam type="UINT32" name="wvEvtInfo:" formatter="com.windriver.windview.plugins.wv.windtipc.formatters.WvTipcInfoDecoder"/>
	    <EventParam type="UINT32" name="Function Name" formatter="com.windriver.windview.plugins.wv.windtipc.formatters.FuncDecoder"/>
	    <EventParam type="UINT32" name="Parameter P0" formatStr="0x%08x"/>
            <EventParam type="BLOB" name="Passed parameters:" formatter="com.windriver.windview.plugins.wv.windtipc.formatters.TipcBlobDecoder"/>
        </EventDescription>
     </EventClass>
</EventDictionary>
)delim";


std::string v7_32_smp_usbHost_xml = R"delim(
<?xml version="1.0" encoding="UTF-8"?>
<!--
/* usbHost.xml - XML descriptions for USB 2.0 Host Stack events */

/*
 * Copyright (c) 2004,2008 Wind River Systems, Inc.
 *
 * The right to copy, distribute, modify or otherwise make use
 * of this software may be licensed only pursuant to the terms
 * of an applicable Wind River license agreement.
 */

/*
 * This file contains descriptions for the USB 2.0 Host Stack events
 */

/*
modification history
01b,11jul08,tcr  add formatter
01a,21Sep04,mta  created
*/
-->
<!DOCTYPE EventDictionary SYSTEM "../../DTDs/EventDictionary.dtd">
<EventDictionary>
    <EventClass key="usbHostStack" displayName="usb Host Stack Events">

        <EventDescription id="10150" name="USB_EHCI_WV_INIT_EXIT" hasTimeStamp="true"
	trigger="true" displayName="usbEhciInitExit" isSearchable="true"
	helpTopicId="USB_EHCI_WV_INIT_EXIT_HELP" icon="images/usb.gif">
	    <EventParam type="BLOB" name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
	</EventDescription>

        <EventDescription id="10151" name="USB_EHCI_WV_EVENT_HANDLER" hasTimeStamp="true"
        trigger="true" displayName="usbEhciEventHandler" isSearchable="true"
        helpTopicId="USB_EHCI_WV_EVENT_HANDLER_HELP" icon="images/usb.gif">
            <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>

	<EventDescription id="10152" name="USB_EHCI_WV_PORT_ROUTE" hasTimeStamp="true"
        trigger="true" displayName="usbEhciPortRoute" isSearchable="true"
        helpTopicId="USB_EHCI_WV_PORT_ROUTE_HELP" icon="images/usb.gif">
            <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>

	
	<EventDescription id="10153" name="USB_EHCI_WV_TRANSFER" hasTimeStamp="true"
        trigger="true" displayName="usbEhciTransfer" isSearchable="true"
        helpTopicId="USB_EHCI_WV_TRANSFER_HELP" icon="images/usb.gif">
            <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>
        
        <EventDescription id="10160" name="USB_OHCI_WV_INIT_EXIT" hasTimeStamp="true"
	trigger="true" displayName="usbOhciInitExit" isSearchable="true"
	helpTopicId="USB_OHCI_WV_INIT_EXIT_HELP" icon="images/usb.gif">
	    <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>
        
        
        <EventDescription id="10161" name="USB_OHCI_WV_EVENT_HANDLER" hasTimeStamp="true"
	trigger="true" displayName="usbOhciEventHandler" isSearchable="true"
	helpTopicId="USB_OHCI_WV_EVENT_HANDLER_HELP" icon="images/usb.gif">
	    <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>
	        
	<EventDescription id="10162" name="USB_OHCI_WV_TRANSFER" hasTimeStamp="true"
        trigger="true" displayName="usbOhciTransfer" isSearchable="true"
        helpTopicId="USB_OHCI_WV_TRANSFER_HELP" icon="images/usb.gif">
            <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>
        
        <EventDescription id="10170" name="USB_UHCI_WV_INIT_EXIT" hasTimeStamp="true"
	trigger="true" displayName="usbUhciInitExit" isSearchable="true"
	helpTopicId="USB_UHCI_WV_INIT_EXIT" icon="images/usb.gif">
	    <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>
	        

        <EventDescription id="10171" name="USB_UHCI_WV_EVENT_HANDLER" hasTimeStamp="true"
	trigger="true" displayName="usbUhciEventHandler" isSearchable="true"
	helpTopicId="USB_UHCI_WV_EVENT_HANDLER_HELP" icon="images/usb.gif">
	    <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
	</EventDescription>
	        

	<EventDescription id="10172" name="USB_UHCI_WV_TRANSFER" hasTimeStamp="true"
        trigger="true" displayName="usbUhciTransfer" isSearchable="true"
        helpTopicId="USB_UHCI_WV_TRANSFER_HELP" icon="images/usb.gif">
            <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>

	        
	<EventDescription id="10180" name="USB_USBD_WV_INIT_EXIT" hasTimeStamp="true"
        trigger="true" displayName="usbUsbdInitExit" isSearchable="true"
        helpTopicId="USB_USBD_WV_INIT_EXIT_HELP" icon="images/usb.gif">
            <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>

	<EventDescription id="10181" name="USB_USBD_WV_REGISTER" hasTimeStamp="true"
        trigger="true" displayName="usbUsbdRegister" isSearchable="true"
        helpTopicId="USB_USBD_WV_REGISTER_HELP" icon="images/usb.gif">
            <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>

	<EventDescription id="10182" name="USB_USBD_WV_DEVICE" hasTimeStamp="true"
        trigger="true" displayName="usbUsbdDevice" isSearchable="true"
        helpTopicId="USB_USBD_WV_DEVICE_HELP" icon="images/usb.gif">
            <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>

	<EventDescription id="10183" name="USB_USBD_WV_REQUEST" hasTimeStamp="true"
        trigger="true" displayName="usbUsbdRequest" isSearchable="true"
        helpTopicId="USB_USBD_WV_REQUEST_HELP" icon="images/usb.gif">
            <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>


	<EventDescription id="10190" name="USB_HUB_WV_INIT_EXIT" hasTimeStamp="true"
        trigger="true" displayName="usbHubInitExit" isSearchable="true"
        helpTopicId="USB_HUB_WV_INIT_EXIT_HELP" icon="images/usb.gif">
            <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>

	<EventDescription id="10191" name="USB_HUB_WV_EVENT_HANDLER" hasTimeStamp="true"
        trigger="true" displayName="usbHubEventHandler" isSearchable="true"
        helpTopicId="USB_HUB_WV_EVENT_HANDLER_HELP" icon="images/usb.gif">
            <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>

	<EventDescription id="10192" name="USB_HUB_WV_DEVICE" hasTimeStamp="true"
        trigger="true" displayName="usbHubDevice" isSearchable="true"
        helpTopicId="USB_HUB_WV_DEVICE_HELP" icon="images/usb.gif">
            <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>

	<EventDescription id="10193" name="USB_HUB_WV_TRANSFER" hasTimeStamp="true"
        trigger="true" displayName="usbHubTransfer" isSearchable="true"
        helpTopicId="USB_HUB_WV_TRANSFER_HELP" icon="images/usb.gif">
            <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>

    </EventClass>

</EventDictionary>
)delim";


std::string v7_32_smp_usbPeripheral_xml = R"delim(
<?xml version="1.0" encoding="UTF-8"?>
<!--
/* usbPeripheral.xml - XML descriptions for USB 2.0 Peripheral Stack events */

/*
 * Copyright (c) 2004,2008 Wind River Systems, Inc.
 *
 * The right to copy, distribute, modify or otherwise make use
 * of this software may be licensed only pursuant to the terms
 * of an applicable Wind River license agreement.
 */

/*
 * This file contains descriptions for the USB 2.0 Peripheral Stack events
 */

/*
modification history
01b,11jul08,tcr  add formatter
01a,14Sep04,mta  created
*/
-->
<!DOCTYPE EventDictionary SYSTEM "../../DTDs/EventDictionary.dtd">
<EventDictionary>
    <EventClass key="usbPeripheralStack" displayName="usb Peripheral Stack Events">

        <EventDescription id="10120" name="USB_TARG_INIT_EXIT" hasTimeStamp="true"
	trigger="true" displayName="usbTargInitExit" isSearchable="true" 
	helpTopicId="USB_TARG_INIT_EXIT_HELP" icon="images/usb.gif">
	    <EventParam type="BLOB" name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
	</EventDescription>

        <EventDescription id="10121" name="USB_TARG_DEFAULT_PIPE" hasTimeStamp="true"
        trigger="true" displayName="usbTargDefaultPipe" 
        helpTopicId="USB_TARG_DEFAULT_PIPE_HELP" icon="images/usb.gif">
            <EventParam type="BLOB" name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>

	<EventDescription id="10122" name="USB_TARG_DEVICE_CONTROL" hasTimeStamp="true"
        trigger="true" displayName="usbTargDeviceControl" 
        helpTopicId="USB_TARG_DEVICE_CONTROL_HELP" icon="images/usb.gif">
            <EventParam type="BLOB" name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>

	
	<EventDescription id="10123" name="USB_TARG_PIPE_FUNC" hasTimeStamp="true"
        trigger="true" displayName="usbTargPipeFunc" isSearchable="true" 
        helpTopicId="USB_TARG_PIPE_FUNC_HELP" icon="images/usb.gif">
            <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>
        
        <EventDescription id="10124" name="USB_HAL_INIT_EXIT" hasTimeStamp="true"
	trigger="true" displayName="usbHalInitExit" isSearchable="true" 
	helpTopicId="USB_HAL_INIT_EXIT_HELP" icon="images/usb.gif">
	    <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>
        
        
        <EventDescription id="10125" name="USB_HAL_INTERRUPT_HANDLER" hasTimeStamp="true"
	trigger="true" displayName="usbHalInterruptHandler" isSearchable="true" 
	helpTopicId="USB_HAL_INTERRUPT_HANDLER_HELP" icon="images/usb.gif">
	    <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>
	        
	<EventDescription id="10126" name="USB_HAL_DEVICE_CNTL" hasTimeStamp="true"
        trigger="true" displayName="usbHalDeviceControl" isSearchable="true" 
        helpTopicId="USB_HAL_DEVICE_CNTL_HELP" icon="images/usb.gif">
            <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>
        
        <EventDescription id="10127" name="USB_HAL_ENDOINT" hasTimeStamp="true"
	trigger="true" displayName="usbHalEndpoint" isSearchable="true" 
	helpTopicId="USB_HAL_ENDOINT_HELP" icon="images/usb.gif">
	    <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>
	        
	
        <EventDescription id="10128" name="USB_TCD_ISP1582_INIT_EXIT" hasTimeStamp="true"
	trigger="true" displayName="usbTcdIsp1582InitExit" isSearchable="true" 
	helpTopicId="USB_TCD_ISP1582_INIT_EXIT_HELP" icon="images/usb.gif">
	    <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
	</EventDescription>
	        

	<EventDescription id="10129" name="USB_TCD_ISP1582_INTERRUPT" hasTimeStamp="true"
        trigger="true" displayName="usbTcdIsp1582Interrupt" isSearchable="true" 
        helpTopicId="USB_TCD_ISP1582_INTERRUPT_HELP" icon="images/usb.gif">
            <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>

	        
	<EventDescription id="10130" name="USB_TCD_ISP1582_ENDPOINT" hasTimeStamp="true"
        trigger="true" displayName="usbTcdIsp1582Endpoint" isSearchable="true" 
        helpTopicId="USB_TCD_ISP1582_ENDPOINT_HELP" icon="images/usb.gif">
            <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>

	<EventDescription id="10131" name="USB_TCD_ISP1582_DEVICE_CONTROL" hasTimeStamp="true"
        trigger="true" displayName="usbTcdIsp1582DeviceControl" isSearchable="true" 
        helpTopicId="USB_TCD_ISP1582_DEVICE_CONTROL_HELP" icon="images/usb.gif">
            <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>

	<EventDescription id="10132" name="USB_TCD_PDIUSBD12_DEVCE_CONTROL" hasTimeStamp="true"
        trigger="true" displayName="usbTcdPdiusbd12DevControl" isSearchable="true" 
        helpTopicId="USB_TCD_PDIUSBD12_DEVCE_CONTROL_HELP" icon="images/usb.gif">
            <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>

	<EventDescription id="10133" name="USB_TCD_PDIUSBD12_ENDPOINT" hasTimeStamp="true"
        trigger="true" displayName="usbTcdPdiusbd12Endpoint" isSearchable="true" 
        helpTopicId="USB_TCD_PDIUSBD12_ENDPOINT_HELP" icon="images/usb.gif">
            <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>


	<EventDescription id="10134" name="USB_TCD_PDIUSBD12_INIT_EXIT" hasTimeStamp="true"
        trigger="true" displayName="usbTcdPdiusbd12InitExit" isSearchable="true" 
        helpTopicId="USB_TCD_PDIUSBD12_INIT_EXIT_HELP" icon="images/usb.gif">
            <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>

	<EventDescription id="10135" name="USB_TCD_PDIUSBD12_INTERRUPT " hasTimeStamp="true"
        trigger="true" displayName="usbTcdPdiusbd12Interrupt" isSearchable="true" 
        helpTopicId="USB_TCD_PDIUSBD12_INTERRUPT_HELP" icon="images/usb.gif">
            <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>

	<EventDescription id="10136" name="USB_TCD_NET2280_INIT_EXIT" hasTimeStamp="true"
        trigger="true" displayName="usbTcdNet2280InitExit" isSearchable="true" 
        helpTopicId="USB_TCD_NET2280_INIT_EXIT_HELP" icon="images/usb.gif">
            <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>

	<EventDescription id="10137" name="USB_TCD_NET2280_INTERRUPT" hasTimeStamp="true"
        trigger="true" displayName="usbTcdNet2280Interrupt" isSearchable="true" 
        helpTopicId="USB_TCD_NET2280_INTERRUPT_HELP" icon="images/usb.gif">
            <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>

	<EventDescription id="10138" name="USB_TCD_NET2280_DEVICE_CONTROL" hasTimeStamp="true"
        trigger="true" displayName="usbTcdNet2280DeviceControl" isSearchable="true" 
        helpTopicId="USB_TCD_NET2280_DEVICE_CONTROL_HELP" icon="images/usb.gif">
            <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>

	<EventDescription id="10139" name="USB_TCD_NET2280_ENDPOINT" hasTimeStamp="true"
        trigger="true" displayName="usbTcdNet2280Endpoint" isSearchable="true" 
        helpTopicId="USB_TCD_NET2280_ENDPOINT_HELP" icon="images/usb.gif">
            <EventParam type="BLOB"  name="Event Descr" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
        </EventDescription>

    </EventClass>

</EventDictionary>
)delim";


std::string v7_32_smp_user_xml = R"delim(
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE EventDictionary SYSTEM "../../DTDs/EventDictionary.dtd">
<EventDictionary>
  <EventClass key="user" displayName="User Events" helpTopicId="VXWORKS6_user_CLASS_HELP">
    <EventRangeDescription eventIdStart="40000" eventIdCount="25536" nameRoot="EVENT_USER" displayNameRoot="user" nameRootSuffixStart="0" icon="text=$id,color=#FFAFFF,textPosition=southeast,icon=images/defaultUser.gif" trigger="true" helpTopicId="VXWORKS6_EVENT_USER_EVENT_HELP" handler="com.windriver.windview.plugins.wv.vxworks.UserEventDescription">
      <EventParam type="UINT32" name="pc" formatStr="0x%08x"/>
      <EventParam type="BLOB" name="data" formatter="com.windriver.windview.agnostic.wv.SmartHexAsciiFormatter"/>
    </EventRangeDescription>
  </EventClass>
</EventDictionary>
)delim";


std::string v7_32_smp_vxdcom_xml = R"delim(
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE EventDictionary SYSTEM "../../DTDs/EventDictionary.dtd">
<EventDictionary>
  <EventClass key="dcom" displayName="DCOM Events" helpTopicId="VXWORKS6_dcom_CLASS_HELP">
    <EventDescription id="25001" name="EVENT_REQUEST" trigger="false" displayName="dcomRequest" icon="images/dcomRequest.gif" helpTopicId="VXWORKS6_EVENT_REQUEST_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="nID" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="25002" name="EVENT_RESPONSE" trigger="false" displayName="dcomResponse" icon="images/dcomResponse.gif" helpTopicId="VXWORKS6_EVENT_RESPONSE_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="nID" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="25003" name="EVENT_FAULT" trigger="false" displayName="dcomFault" icon="images/dcomFault.gif" helpTopicId="VXWORKS6_EVENT_FAULT_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="nID" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="25004" name="EVENT_BIND" trigger="false" displayName="dcomBind" icon="images/dcomBind.gif" helpTopicId="VXWORKS6_EVENT_BIND_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="nID" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="nGuidSize"/>
      <EventParam type="STRING" name="pGuid" formatStr="%s"/>
    </EventDescription>
    <EventDescription id="25005" name="EVENT_BIND_ACK" trigger="false" displayName="dcomBindAck" icon="images/dcomBindAck.gif" helpTopicId="VXWORKS6_EVENT_BIND_ACK_EVENT_HELP"/>
    <EventDescription id="25006" name="EVENT_BIND_NAK" trigger="false" displayName="dcomBindNak" icon="images/dcomBindNak.gif" helpTopicId="VXWORKS6_EVENT_BIND_NAK_EVENT_HELP"/>
    <EventDescription id="25007" name="EVENT_ALTER_CONTEXT" trigger="false" displayName="dcomAlterContext" icon="images/dcomAlterContext.gif" helpTopicId="VXWORKS6_EVENT_ALTER_CONTEXT_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="nID" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="nGuidSize"/>
      <EventParam type="STRING" name="pGuid" formatStr="%s"/>
    </EventDescription>
    <EventDescription id="25008" name="EVENT_ALTER_CONTEXT_RESP" trigger="false" displayName="dcomAlterContextResp" icon="images/dcomAlterContextResp.gif" helpTopicId="VXWORKS6_EVENT_ALTER_CONTEXT_RESP_EVENT_HELP"/>
    <EventDescription id="25009" name="EVENT_AUTH3" trigger="false" displayName="dcomAuth3" icon="images/dcomAuth3.gif" helpTopicId="VXWORKS6_EVENT_AUTH3_EVENT_HELP"/>
    <EventDescription id="25010" name="EVENT_PING_RECEIVED" trigger="false" displayName="dcomPingReceived" icon="images/dcomPingReceived.gif" helpTopicId="VXWORKS6_EVENT_PING_RECEIVED_EVENT_HELP">
      <EventParam type="UINT32" name="nComplexPing" formatStr="0x%1x"/>
    </EventDescription>
    <EventDescription id="25011" name="EVENT_PING_SENT" trigger="false" displayName="dcomPingSent" icon="images/dcomPingSent.gif" helpTopicId="VXWORKS6_EVENT_PING_SENT_EVENT_HELP">
      <EventParam type="UINT32" name="nComplexPing" formatStr="0x%1x"/>
    </EventDescription>
    <EventDescription id="25012" name="EVENT_DCOM_DESTROY" trigger="false" displayName="dcomDestroy" icon="images/dcomDestroy.gif" helpTopicId="VXWORKS6_EVENT_DCOM_DESTROY_EVENT_HELP"/>
  </EventClass>
  <EventClass key="com" displayName="COM Events" helpTopicId="VXWORKS6_com_CLASS_HELP">
    <EventDescription id="25013" name="EVENT_QI" trigger="false" displayName="comQI" icon="images/comQI.gif" helpTopicId="VXWORKS6_EVENT_QI_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="nID" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="nGuidSize"/>
      <EventParam type="STRING" name="pGuid" formatStr="%s"/>
    </EventDescription>
    <EventDescription id="25014" name="EVENT_NOINT" trigger="false" displayName="comNoInterface" icon="images/comNoInterface.gif" helpTopicId="VXWORKS6_EVENT_NOINT_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="nID" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="nGuidSize"/>
      <EventParam type="STRING" name="pGuid" formatStr="%s"/>
    </EventDescription>
    <EventDescription id="25015" name="EVENT_ADDREF" trigger="false" displayName="comAddRef" icon="images/comAddRef.gif" helpTopicId="VXWORKS6_EVENT_ADDREF_EVENT_HELP">
      <EventParam type="UINT32" name="nRefCount"/>
      <EventParam isSearchKey="true" type="UINT32" name="nID" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="25016" name="EVENT_REL" trigger="false" displayName="comRelease" icon="images/comRelease.gif" helpTopicId="VXWORKS6_EVENT_REL_EVENT_HELP">
      <EventParam type="UINT32" name="nRefCount"/>
      <EventParam isSearchKey="true" type="UINT32" name="nID" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="25017" name="EVENT_CREATE" trigger="false" displayName="comCreate" icon="images/comCreate.gif" helpTopicId="VXWORKS6_EVENT_CREATE_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="nID" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="25018" name="EVENT_DESTROY" trigger="false" displayName="comDestroy" icon="images/comDestroy.gif" helpTopicId="VXWORKS6_EVENT_DESTROY_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="nID" formatStr="0x%08x"/>
    </EventDescription>
  </EventClass>
</EventDictionary>
)delim";


std::string v7_32_smp_vxworks_xml = R"delim(
<?xml version="1.0" encoding="UTF-8"?>
<!--
/* vxworks.xml - XML descriptions for vxWorks 6.7 */

/* Copyright 2008,2010, 2019 Wind River Systems, Inc. */

/*
modification history
01h,24sep19,zli  fix locked state description(WB4-9658)
01g,29nov17,sai  fix WB4-7503, remove wrong help id to avoid misunderstood.
01f,23apr14,ryan Add a new "Errno Set Events" event class for "errnoSet" and "task errnoSet"
01e,13may10,vhe  Improve lock level tracking for SV (WIND00209730)
01d,06oct08,cpd  Break becomes Stopped
01c,03oct08,tcr  swap parameters for affinity set event
01b,26sep08,tcr  remove isLegend from spinlock states
01a,07may08,tcr  created from 6.6/vxworks.xml
*/
-->
<!DOCTYPE EventDictionary SYSTEM "../../DTDs/EventDictionary.dtd">
<EventDictionary>
  <EventClass>
    <EventDescription id="0" name="EVENT_BEGIN" hasTimeStamp="false" isSearchable="false">
      <EventParam type="UINT32" name="CPU"/>
      <EventParam type="UINT32" name="taskIdCurrent" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="collectionMode"/>
      <EventParam type="BLOB" name="bspName" formatStr="%s"/>
    </EventDescription>
	<EventDescription id="1" name="EVENT_CALL_STACK" hasTimeStamp="false" isSearchable="false">
      	<EventParam type="UINT32" name="rtpId" formatStr="0x%016llx"/>
      	<EventParam type="UINT32" name="taskId" formatStr="0x%016llx"/>
      	<EventParam type="BLOB" name="callstack" formatStr="%s"/>
    </EventDescription>
    <EventDescription id="2" name="EVENT_TIMER_ROLLOVER" isSearchable="false"/>
    <EventDescription id="3" name="EVENT_TASKNAME" hasTimeStamp="false" isSearchable="false">
      <EventParam type="UINT32" name="status"/>
      <EventParam type="UINT32" name="priority"/>
      <EventParam type="UINT32" name="taskLockCount"/>
      <EventParam type="UINT32" name="taskId" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="entryPoint" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="rtpId" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="cpuIndex" formatStr="0x%08x"/>
      <EventParam type="BLOB" name="name" formatStr="%s"/>
    </EventDescription>
    <EventDescription id="4" name="EVENT_CONFIG" hasTimeStamp="false" isSearchable="false">
      <EventParam type="UINT32" name="revision"/>
    </EventDescription>
    <EventDescription id="5" name="EVENT_STACK_FRAME" hasTimeStamp="false" isSearchable="false">
      <EventParam type="UINT32" name="order"/>
      <EventParam type="UINT64" name="address"/>
      <EventParam type="UINT32" name="symbol"/>
      <EventParam type="UINT32" name="source"/>
      <EventParam type="UINT64" name="lineno"/>
    </EventDescription>	
    <EventDescription id="6" name="EVENT_RESOURCE" hasTimeStamp="false" isSearchable="false">
      <EventParam type="BLOB" name="resource"/>
    </EventDescription>
    <EventDescription id="7" name="EVENT_LOG_COMMENT" hasTimeStamp="false" isSearchable="false">
      <EventParam type="BLOB" name="comment" formatStr="%s"/>
    </EventDescription>
    <EventDescription id="8" name="EVENT_TIMESTAMP_CONFIG" hasTimeStamp="false" isSearchable="false">
      <EventParam type="UINT32" name="timestampFreq"/>
      <EventParam type="UINT32" name="timestampPeriod"/>
      <EventParam type="UINT32" name="autoRollover"/>
      <EventParam type="UINT32" name="clkRate"/>
    </EventDescription>
    <EventDescription id="10" name="EVENT_CPU_ID" hasTimeStamp="false" isSearchable="false">
      <EventParam type="UINT16" name="cpuId"/>
    </EventDescription>
    <EventDescription id="17" name="EVENT_NUM_CPU" hasTimeStamp="false" isSearchable="false">
      <EventParam type="UINT16" name="numCpu"/>
    </EventDescription>
    <EventDescription id="18" name="EVENT_OS_REVISION" hasTimeStamp="false" isSearchable="false">
      <EventParam type="BLOB" name="osRevision" formatStr="%s"/>
    </EventDescription>
    <EventDescription id="19" name="EVENT_IDLE_INFO" 
                      hasTimeStamp="false" isSearchable="false">
      <EventParam type="UINT16" name="CPU"/>
      <EventParam type="UINT32" name="idleTaskId" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="20" name="EVENT_MODULE_MAP"
                      hasTimeStamp="false" isSearchable="false">
      <EventParam type="UINT32" name="RtpId"/>
      <EventParam type="UINT32" name="textAddr"/>
      <EventParam type="UINT32" name="textSize"/>
      <EventParam type="UINT32" name="fileOffset"/>
      <EventParam type="BLOB" name="fileName" formatStr="%s"/>
    </EventDescription>
  </EventClass>
  <EventClass key="krnl" displayName="Kernel Events" helpTopicId="VXWORKS6_krnl_CLASS_HELP">
    <EventDescription id="52" name="EVENT_WIND_EXIT_DISPATCH" displayName="[Exit - Task switch]" isSearchable="false">
      <EventParam type="UINT32" name="tid" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="priority"/>
    </EventDescription>
    <EventDescription id="53" name="EVENT_WIND_EXIT_NODISPATCH"
      displayName="[Exit - No task switch]" isSearchable="false">
      <EventParam type="UINT32" name="tid" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="54" name="EVENT_WIND_EXIT_DISPATCH_PI" displayName="[Exit - Task switch, Priority inversion]" isSearchable="false">
      <EventParam type="UINT32" name="tid" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="priority"/>
    </EventDescription>
    <EventDescription id="55" name="EVENT_WIND_EXIT_NODISPATCH_PI" displayName="[Exit - No task switch, Priority inversion]" isSearchable="false">
      <EventParam type="UINT32" name="tid" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="56" name="EVENT_WIND_EXIT_IDLE" displayName="[Exit to idle]" isSearchable="false"/>
  </EventClass>
  <EventClass key="krnl" displayName="Kernel Events" helpTopicId="VXWORKS6_krnl_CLASS_HELP">
    <EventDescription id="600" name="EVENT_WINDSPAWN" displayName="[Spawn task]" hasTimeStamp="false" isSearchable="false">
      <EventParam isSearchKey="true" type="UINT32" name="pTcb" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="priority"/>
    </EventDescription>
    <EventDescription id="601" name="EVENT_WINDDELETE" displayName="[Delete task]" hasTimeStamp="false" isSearchable="false">
      <EventParam isSearchKey="true" type="UINT32" name="pTcb" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="602" name="EVENT_WINDSUSPEND" displayName="[Suspend task]" hasTimeStamp="false" isSearchable="false">
      <EventParam isSearchKey="true" type="UINT32" name="pTcb" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="603" name="EVENT_WINDRESUME" displayName="[Resume task]" hasTimeStamp="false" isSearchable="false">
      <EventParam isSearchKey="true" type="UINT32" name="pTcb" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="604" name="EVENT_WINDPRIORITYSETRAISE" displayName="[Task priority set - raise]" hasTimeStamp="false" isSearchable="false">
      <EventParam isSearchKey="true" type="UINT32" name="pTcb" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="oldPriority"/>
      <EventParam type="UINT32" name="priority"/>
    </EventDescription>
    <EventDescription id="605" name="EVENT_WINDPRIORITYSETLOWER" displayName="[Task priority set - lower]" hasTimeStamp="false" isSearchable="false">
      <EventParam isSearchKey="true" type="UINT32" name="pTcb" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="oldPriority"/>
      <EventParam type="UINT32" name="priority"/>
    </EventDescription>
    <EventDescription id="606" name="EVENT_WINDSEMDELETE" displayName="[Delete semaphore]" hasTimeStamp="false" isSearchable="false">
      <EventParam isSearchKey="true" type="UINT32" name="semId" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="609" name="EVENT_WINDDELAY" displayName="[Delay task]" hasTimeStamp="false" isSearchable="false">
      <EventParam type="UINT32" name="ticks"/>
    </EventDescription>
    <EventDescription id="610" name="EVENT_WINDUNDELAY" displayName="[Wake delayed task]" hasTimeStamp="false" isSearchable="false" helpTopicId="VXWORKS6_EVENT_WINDUNDELAY_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="pTcb" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="611" name="EVENT_WINDWDSTART" displayName="[Start watchdog]" hasTimeStamp="false" isSearchable="false" helpTopicId="VXWORKS6_EVENT_WINDWDSTART_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="wdId" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="612" name="EVENT_WINDWDCANCEL" displayName="[Cancel watchdog]" hasTimeStamp="false" isSearchable="false" helpTopicId="VXWORKS6_EVENT_WINDWDCANCEL_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="wdId" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="613" name="EVENT_WINDPENDQGET" displayName="[Unpend next task on Q]" hasTimeStamp="false" isSearchable="false">
      <EventParam isSearchKey="true" type="UINT32" name="pTcb" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="614" name="EVENT_WINDPENDQFLUSH" displayName="[Unpend all tasks on Q]" hasTimeStamp="false" isSearchable="false">
      <EventParam isSearchKey="true" type="UINT32" name="pTcb" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="615" name="EVENT_WINDPENDQPUT" displayName="[Pend current task on Q]" hasTimeStamp="false" isSearchable="false"/>
    <EventDescription id="617" name="EVENT_WINDPENDQTERMINATE" displayName="[Unpend all tasks on Q (terminate)]" hasTimeStamp="false" isSearchable="false">
      <EventParam isSearchKey="true" type="UINT32" name="pTcb" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="619" name="EVENT_OBJ_TASK" hasTimeStamp="false" isSearchable="false" helpTopicId="VXWORKS6_EVENT_OBJ_TASK_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="pTcb" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="620" name="EVENT_OBJ_SEMGIVE" hasTimeStamp="false" isSearchable="false" helpTopicId="VXWORKS6_EVENT_OBJ_SEMGIVE_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="semId" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="621" name="EVENT_OBJ_SEMTAKE" hasTimeStamp="false" isSearchable="false" helpTopicId="VXWORKS6_EVENT_OBJ_SEMTAKE_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="semId" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="622" name="EVENT_OBJ_SEMFLUSH" hasTimeStamp="false" isSearchable="false" helpTopicId="VXWORKS6_EVENT_OBJ_SEMFLUSH_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="semId" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="623" name="EVENT_OBJ_MSGSEND" hasTimeStamp="false" isSearchable="false" helpTopicId="VXWORKS6_EVENT_OBJ_MSGSEND_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="msgQId" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="624" name="EVENT_OBJ_MSGRECEIVE" hasTimeStamp="false" isSearchable="false" helpTopicId="VXWORKS6_EVENT_OBJ_MSGRECEIVE_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="msgQId" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="625" name="EVENT_OBJ_MSGDELETE" hasTimeStamp="false" isSearchable="false" helpTopicId="VXWORKS6_EVENT_OBJ_MSGDELETE_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="msgQId" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="626" name="EVENT_OBJ_SIGPAUSE" hasTimeStamp="false" isSearchable="false" helpTopicId="VXWORKS6_EVENT_OBJ_SIGPAUSE_EVENT_HELP">
      <EventParam type="UINT32" name="tid" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="627" name="EVENT_OBJ_SIGSUSPEND" hasTimeStamp="false" isSearchable="false" helpTopicId="VXWORKS6_EVENT_OBJ_SIGSUSPEND_EVENT_HELP">
      <EventParam type="UINT32" name="sigset" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="628" name="EVENT_OBJ_SIGKILL" hasTimeStamp="false" isSearchable="false" helpTopicId="VXWORKS6_EVENT_OBJ_SIGKILL_EVENT_HELP">
      <EventParam type="UINT32" name="tid" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="632" name="EVENT_OBJ_SIGWAIT" hasTimeStamp="false" isSearchable="false">
      <EventParam type="UINT32" name="tid" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="646" name="EVENT_OBJ_WINDROTATE" hasTimeStamp="false" isSearchable="false">
      <EventParam type="UINT32" name="priority" formatStr="%d"/>
    </EventDescription>

    <EventDescription id="647" name="EVENT_OBJ_SEMRTAKE" hasTimeStamp="false" isSearchable="false" helpTopicId="VXWORKS6_EVENT_OBJ_SEMRTAKE_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="semId" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="648" name="EVENT_OBJ_SEMWTAKE" hasTimeStamp="false" isSearchable="false" helpTopicId="VXWORKS6_EVENT_OBJ_SEMWTAKE_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="semId" formatStr="0x%08x"/>
    </EventDescription>

  </EventClass>
  <EventClass key="int" displayName="Interrupt Events" helpTopicId="VXWORKS6_int_CLASS_HELP">
    <EventDescription id="102" name="EVENT_INT_ENT_" trigger="true"
      displayName="intEnt-" icon="images/intEnt.gif"
      helpTopicId="VXWORKS6_EVENT_INT_ENT__EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="intNum" formatStr="0x%08x"/>
    </EventDescription>

    <EventDescription id="598" name="EVENT_HARDWARE_WATCHDOG_INT" trigger="true"
      displayName="HardwareWatchdogInt" icon="images/intEnt.gif"
      helpTopicId="VXWORKS6_EVENT_HARDWARE_WATCHDOG_INT_EVENT_HELP">  
    </EventDescription>

    <EventDescription id="599" name="EVENT_TIMER_INT" trigger="true"
      displayName="TimerInt" icon="images/intEnt.gif"
      helpTopicId="VXWORKS6_EVENT_TIMER_INT_EVENT_HELP">
    </EventDescription>

    <EventDescription id="101" name="EVENT_INT_EXIT" trigger="true"
      displayName="intExit" icon="images/intExit.gif"
      helpTopicId="VXWORKS6_EVENT_INT_EXIT_EVENT_HELP">
    </EventDescription>

    <EventDescription id="100" name="EVENT_INT_EXIT_K" trigger="true"
      displayName="intExitK" icon="images/intExitK.gif"
      helpTopicId="VXWORKS6_EVENT_INT_EXIT_EVENT_HELP">
    </EventDescription>

  </EventClass>
  <EventClass key="task" displayName="Task Events" helpTopicId="VXWORKS6_task_CLASS_HELP">
    <EventDescription id="57" name="EVENT_TASKLOCK" trigger="true"
    displayName="taskLock">
      
</EventDescription>
    <EventDescription id="58" name="EVENT_TASKUNLOCK" trigger="true"
      displayName="taskUnlock">
      
    </EventDescription>

    <EventDescription id="74" name="EVENT_TASKUNLOCK_ZERO" trigger="true"
      displayName="taskUnlock (zero)">
    </EventDescription>

    <EventDescription id="75" name="EVENT_TASKUNLOCK_NONZERO" trigger="true"
      displayName="taskUnlock (non-zero)">
    </EventDescription>
    
    <EventDescription id="76" name="EVENT_QJOB_START" trigger="true"
      displayName="workqueue Job start">
    </EventDescription>

    <EventDescription id="77" name="EVENT_QJOB_END" trigger="true"
      displayName="workqueue Job end">
    </EventDescription>

    <EventDescription id="10000" name="EVENT_TASKSPAWN" trigger="true" displayName="taskSpawn" icon="images/taskSpawn.gif" helpTopicId="VXWORKS6_EVENT_TASKSPAWN_EVENT_HELP">

      <EventParam isSearchKey="true" type="UINT32" name="pTcb" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="priority"/>
      <EventParam type="UINT32" name="stackSize"/>
      <EventParam type="UINT32" name="entryPt" formatStr="0x%08x"/>      
      <EventParam type="UINT32" name="options" formatter="com.windriver.windview.plugins.wv.vxworks6.parmfmt.TaskSpawnOptions"/>
    </EventDescription>
    <EventDescription id="10001" name="EVENT_TASKDESTROY" trigger="true" displayName="taskDelete" icon="images/taskDelete.gif" helpTopicId="VXWORKS6_EVENT_TASKDESTROY_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="pTcb" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="safeCnt"/>
    </EventDescription>
    <EventDescription id="10002" name="EVENT_TASKDELAY" trigger="true" displayName="taskDelay" icon="images/taskDelay.gif" helpTopicId="VXWORKS6_EVENT_TASKDELAY_EVENT_HELP">
      
      <EventParam type="UINT32" name="ticks"/>
    </EventDescription>
    <EventDescription id="10003" name="EVENT_TASKPRIORITYSET" trigger="true" displayName="taskPrioritySet" icon="images/taskPrioritySet.gif" helpTopicId="VXWORKS6_EVENT_TASKPRIORITYSET_EVENT_HELP">
      
      <EventParam isSearchKey="true" type="UINT32" name="pTcb" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="newPri"/>
      <EventParam type="UINT32" name="oldPri"/>
    </EventDescription>
    <EventDescription id="10004" name="EVENT_TASKSUSPEND" trigger="true" displayName="taskSuspend" icon="images/taskSuspend.gif" helpTopicId="VXWORKS6_EVENT_TASKSUSPEND_EVENT_HELP">
      
      <EventParam isSearchKey="true" type="UINT32" name="pTcb" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="10005" name="EVENT_TASKRESUME" trigger="true" displayName="taskResume" icon="images/taskResume.gif" helpTopicId="VXWORKS6_EVENT_TASKRESUME_EVENT_HELP">
      
      <EventParam isSearchKey="true" type="UINT32" name="pTcb" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="priority"/>
    </EventDescription>
    <EventDescription id="10006" name="EVENT_TASKSAFE" trigger="true" displayName="taskSafe" icon="images/taskSafe.gif" helpTopicId="VXWORKS6_EVENT_TASKSAFE_EVENT_HELP">
      
      <EventParam isSearchKey="true" type="UINT32" name="taskId" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="safeCnt"/>
    </EventDescription>
    <EventDescription id="10007" name="EVENT_TASKUNSAFE" trigger="true" displayName="taskUnsafe" icon="images/taskUnsafe.gif" helpTopicId="VXWORKS6_EVENT_TASKUNSAFE_EVENT_HELP">
      
      <EventParam isSearchKey="true" type="UINT32" name="taskId" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="safeCnt"/>
    </EventDescription>
    <EventDescription id="10028" name="EVENT_SAFE_PEND" trigger="true" displayName="safePend" hasTimeStamp="false" icon="images/safePend.gif" helpTopicId="VXWORKS6_EVENT_SAFE_PEND_EVENT_HELP">
      
      <EventParam isSearchKey="true" type="UINT32" name="tid" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="10043" name="EVENT_TASKSTOP" trigger="true" displayName="taskStop" icon="images/taskStop.gif" helpTopicId="VXWORKS6_EVENT_TASKSTOP_EVENT_HELP">
      
      <EventParam isSearchKey="true" type="UINT32" name="taskId" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="10044" name="EVENT_TASKCONT" trigger="true" displayName="taskCont" icon="images/taskCont.gif" helpTopicId="VXWORKS6_EVENT_TASKCONT_EVENT_HELP">
      
      <EventParam isSearchKey="true" type="UINT32" name="taskId" formatStr="0x%08x"/>
      <EventParam isSearchKey="false" type="UINT32" name="priority" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="629" name="EVENT_WINDSTOP" trigger="false" displayName="windStop" hasTimeStamp="false">
      
      <EventParam isSearchKey="true" type="UINT32" name="taskId" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="630" name="EVENT_WINDCONT" hasTimeStamp="false" trigger="false" displayName="windCont">
      
      <EventParam isSearchKey="true" type="UINT32" name="taskId" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="10230" name="EVENT_TASK_CPU_AFFINITY_SET" trigger="true" displayName="taskCpuAffinitySet" icon="images/taskCpuAffinitySet.png" helpTopicId="VXWORKS6_EVENT_TASKCPU_AFFINITY_SET_EVENT_HELP">
      <EventParam type="UINT32" name="affinity" formatStr="0x%08x"/>
      <EventParam type="UINT32" isSearchKey="true" name="taskId" formatStr="0x%08x"/>
    </EventDescription>

    <EventDescription id="10108" name="EVENT_TASKROTATE" trigger="true"
      displayName="taskRotate" icon="images/taskRotate.gif" helpTopicId="VXWORKS6_EVENT_TASK_ROTATE_EVENT_HELP">      
      <EventParam type="UINT32" name="priority" formatStr="%d" />
    </EventDescription>
  </EventClass>
  <EventClass key="errnoset" displayName="Errno Set Events" helpTopicId="VXWORKS6_errnoset_CLASS_HELP">
    <EventDescription id="10254" name="EVENT_SET_ERRNO" trigger="true" displayName="errnoSet" >
      <EventParam type="UINT32" name="errno" formatStr="0x%llx"/>
    </EventDescription>
    <EventDescription id="10255" name="EVENT_SET_TASK_ERRNO" trigger="true" displayName="taskErrnoSet" >
      <EventParam type="UINT32" name="tid" formatStr="0x%llx"/>
      <EventParam type="UINT32" name="errno" formatStr="0x%llx"/>
    </EventDescription>
  </EventClass>
  <EventClass key="sem" displayName="Semaphore Events" helpTopicId="VXWORKS6_sem_CLASS_HELP">
    <EventDescription id="10008" name="EVENT_SEMBCREATE" trigger="true" displayName="semBCreate" icon="images/semBCreate.gif" helpTopicId="VXWORKS6_EVENT_SEMBCREATE_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="semId" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="options" formatter="com.windriver.windview.plugins.wv.vxworks6.parmfmt.SemCreateOptions"/>      
      <EventParam type="UINT32" name="semOwner" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="10009" name="EVENT_SEMCCREATE" trigger="true" displayName="semCCreate" icon="images/semCCreate.gif" helpTopicId="VXWORKS6_EVENT_SEMCCREATE_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="semId" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="options" formatter="com.windriver.windview.plugins.wv.vxworks6.parmfmt.SemCreateOptions"/>
      <EventParam type="UINT32" name="initialCount"/>
    </EventDescription>
    <EventDescription id="10010" name="EVENT_SEMDELETE" trigger="true" displayName="semDelete" icon="images/semDelete.gif" helpTopicId="VXWORKS6_EVENT_SEMDELETE_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="semId" formatStr="0x%08x"/>      
      <EventParam type="UINT32" name="owner"/>
      <EventParam type="UINT32" name="recurse"/>
      <EventParam type="UINT32" name="qHead" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="10011" name="EVENT_SEMFLUSH" trigger="true" displayName="semFlush" icon="images/semFlush.gif" helpTopicId="VXWORKS6_EVENT_SEMFLUSH_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="semId" formatStr="0x%08x"/>      
      <EventParam type="UINT32" name="owner"/>
      <EventParam type="UINT32" name="recurse"/>
      <EventParam type="UINT32" name="qHead" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="10012" name="EVENT_SEMGIVE" trigger="true" displayName="semGive" icon="images/semGive.gif" helpTopicId="VXWORKS6_EVENT_SEMGIVE_EVENT_HELP">
      
      <EventParam isSearchKey="true" type="UINT32" name="semId" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="semOwner" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="recurse"/>
    </EventDescription>
    <EventDescription id="10013" name="EVENT_SEMMCREATE" trigger="true" displayName="semMCreate" icon="images/semMCreate.gif" helpTopicId="VXWORKS6_EVENT_SEMMCREATE_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="semId" formatStr="0x%08x"/>      
      <EventParam type="UINT32" name="options" formatter="com.windriver.windview.plugins.wv.vxworks6.parmfmt.SemMCreateOptions"/>
      <EventParam type="UINT32" name="semOwner" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="10014" name="EVENT_SEMMGIVEFORCE" trigger="true" displayName="semMGiveForce" icon="images/semMGiveForce.gif" helpTopicId="VXWORKS6_EVENT_SEMMGIVEFORCE_EVENT_HELP">
      
      <EventParam isSearchKey="true" type="UINT32" name="semId" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="options" formatter="com.windriver.windview.plugins.wv.vxworks6.parmfmt.SemMCreateOptions"/>
      <EventParam type="UINT32" name="semOwner" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="10015" name="EVENT_SEMTAKE" trigger="true" displayName="semTake" icon="images/semTake.gif" helpTopicId="VXWORKS6_EVENT_SEMTAKE_EVENT_HELP">
      
      <EventParam isSearchKey="true" type="UINT32" name="semId" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="semOwner" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="recurse"/>
    </EventDescription>

    <EventDescription id="10204" name="EVENT_SEMRWCREATE" trigger="true" displayName="semRWCreate" icon="images/semRWCreate.gif" helpTopicId="VXWORKS6_EVENT_SEMRWCREATE_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="semId" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="maxReaders" formatStr="%d"/>
      <EventParam type="UINT32" name="options" formatter="com.windriver.windview.plugins.wv.vxworks6.parmfmt.SemMCreateOptions"/>
      <EventParam type="UINT32" name="semOwner" formatStr="0x%08x"/>
    </EventDescription>

    <EventDescription id="10205" name="EVENT_SEMRTAKE" trigger="true" displayName="semRTake" icon="images/semRTake.gif" helpTopicId="VXWORKS6_EVENT_SEMRTAKE_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="semId" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="owner" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="recurse" formatStr="%d"/>
    </EventDescription>

    <EventDescription id="10206" name="EVENT_SEMWTAKE" trigger="true" displayName="semWTake" icon="images/semWTake.gif" helpTopicId="VXWORKS6_EVENT_SEMWTAKE_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="semId" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="owner" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="recurse" formatStr="%d"/>
    </EventDescription>

  </EventClass>
  <EventClass key="wd" displayName="Watchdog Events" helpTopicId="VXWORKS6_wd_CLASS_HELP">
    <EventDescription id="10016" name="EVENT_WDCREATE" trigger="true" displayName="wdCreate" icon="images/wdCreate.gif" helpTopicId="VXWORKS6_EVENT_WDCREATE_EVENT_HELP">
      
      <EventParam isSearchKey="true" type="UINT32" name="wdId" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="10017" name="EVENT_WDDELETE" trigger="true" displayName="wdDelete" icon="images/wdDelete.gif" helpTopicId="VXWORKS6_EVENT_WDDELETE_EVENT_HELP">
      
      <EventParam isSearchKey="true" type="UINT32" name="wdId" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="10018" name="EVENT_WDSTART" trigger="true" displayName="wdStart" icon="images/wdStart.gif" helpTopicId="VXWORKS6_EVENT_WDSTART_EVENT_HELP">
      
      <EventParam isSearchKey="true" type="UINT32" name="wdId" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="delay"/>
    </EventDescription>
    <EventDescription id="10019" name="EVENT_WDCANCEL" trigger="true" displayName="wdCancel" icon="images/wdCancel.gif" helpTopicId="VXWORKS6_EVENT_WDCANCEL_EVENT_HELP">
      
      <EventParam isSearchKey="true" type="UINT32" name="wdId" formatStr="0x%08x"/>
    </EventDescription>
  </EventClass>
  <EventClass key="msgQ" displayName="Message Queue Events" helpTopicId="VXWORKS6_msgq_CLASS_HELP">
    <EventDescription id="10020" name="EVENT_MSGQCREATE" trigger="true" displayName="msgQCreate" icon="images/msgQCreate.gif" helpTopicId="VXWORKS6_EVENT_MSGQCREATE_EVENT_HELP">
      
      <EventParam isSearchKey="true" type="UINT32" name="msgQId" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="maxMsg"/>
      <EventParam type="UINT32" name="maxMsgLen"/>
      <EventParam type="UINT32" name="options" formatter="com.windriver.windview.plugins.wv.vxworks6.parmfmt.MsgQCreateOptions"/>

    </EventDescription>
    <EventDescription id="10021" name="EVENT_MSGQDELETE" trigger="true" displayName="msgQDelete" icon="images/msgQDelete.gif" helpTopicId="VXWORKS6_EVENT_MSGQDELETE_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="msgQId" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="10022" name="EVENT_MSGQRECEIVE" trigger="true" displayName="msgQReceive" icon="images/msgQReceive.gif" helpTopicId="VXWORKS6_EVENT_MSGQRECEIVE_EVENT_HELP">      
      <EventParam isSearchKey="true" type="UINT32" name="msgQId" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="buffer" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="bufSize"/>
      <EventParam type="UINT32" name="timeout" formatter="com.windriver.windview.plugins.wv.vxworks6.parmfmt.WaitOptions"/>
    </EventDescription>
    <EventDescription id="10023" name="EVENT_MSGQSEND" trigger="true" displayName="msgQSend" icon="images/msgQSend.gif" helpTopicId="VXWORKS6_EVENT_MSGQSEND_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="msgQId" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="buffer" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="bufSize"/>
      <EventParam type="UINT32" name="timeout" formatter="com.windriver.windview.plugins.wv.vxworks6.parmfmt.WaitOptions"/>
      <EventParam type="UINT32" name="priority" formatter="com.windriver.windview.plugins.wv.vxworks6.parmfmt.MsgQPriorityOptions"/>
    </EventDescription>
  </EventClass>
  <EventClass key="sig" displayName="Signals" helpTopicId="VXWORKS6_sig_CLASS_HELP">
    <EventDescription id="60" name="EVENT_EXCEPTION" trigger="true" displayName="exception" icon="images/exception.gif" helpTopicId="VXWORKS6_EVENT_EXCEPTION_EVENT_HELP">
      
      <EventParam type="UINT32" name="exception" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="10024" name="EVENT_SIGNAL" trigger="true" displayName="signal" icon="images/signal.gif" helpTopicId="VXWORKS6_EVENT_SIGNAL_EVENT_HELP">
      
      <EventParam isSearchKey="true" type="UINT32" name="signo" formatStr="0x%x"/>
      <EventParam type="UINT32" name="handler" formatter="com.windriver.windview.plugins.wv.vxworks6.parmfmt.SignalHandlerOptions"/>
    </EventDescription>
    <EventDescription id="10025" name="EVENT_SIGSUSPEND" trigger="true" displayName="sigsuspend" icon="images/sigsuspend.gif" helpTopicId="VXWORKS6_EVENT_SIGSUSPEND_EVENT_HELP">
      
      <EventParam type="UINT32" name="pSet" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="10026" name="EVENT_PAUSE" trigger="true" displayName="pause" icon="images/pause.gif" helpTopicId="VXWORKS6_EVENT_PAUSE_EVENT_HELP">
      
      <EventParam type="UINT32" name="tid" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="10027" name="EVENT_KILL" trigger="true" displayName="kill" icon="images/kill.gif" helpTopicId="VXWORKS6_EVENT_KILL_EVENT_HELP">
      
      <EventParam type="UINT32" name="signo" formatStr="0x%x"/>
      <EventParam type="UINT32" name="tid" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="10029" name="EVENT_SIGWRAPPER" trigger="true" displayName="sigwrapper" icon="images/sigwrapper.gif" helpTopicId="VXWORKS6_EVENT_SIGWRAPPER_EVENT_HELP">
      
      <EventParam isSearchKey="true" type="UINT32" name="tid" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="signo" formatStr="0x%x"/>
    </EventDescription>
    <EventDescription id="10077" name="EVENT_OBJ_VERIFY_FAIL" trigger="true" displayName="OBJ_VERIFY fail" icon="images/obj_verify_fail.gif" helpTopicId="VXWORKS6_EVENT_OBJ_VERIFY_FAILEVENT_HELP">
      
      <EventParam type="UINT32" isSearchKey="true" name="objId" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="classId" formatStr="0x%08x"/>
    </EventDescription>
  </EventClass>
  <EventClass key="tick" displayName="Tick Events" helpTopicId="VXWORKS6_tick_CLASS_HELP">
    <EventDescription id="59" name="EVENT_TICKANNOUNCE" trigger="true"
        displayName="tickAnnounce" icon="images/tick_announce.gif">
      
    </EventDescription>
    <EventDescription id="607" name="EVENT_WINDTICKANNOUNCETMRSLC"
      trigger="true" displayName="[Tick announce timeslice]"
      hasTimeStamp="false" icon="images/tick_timeslice.gif"
      helpTopicId="VXWORKS6_EVENT_WINDTICKANNOUNCETMRSLC_EVENT_HELP">
      
</EventDescription>
    <EventDescription id="608" name="EVENT_WINDTICKANNOUNCETMRWD" trigger="true" displayName="[Tick announce watchdog]" hasTimeStamp="false" icon="images/tick_wd.gif" helpTopicId="VXWORKS6_EVENT_WINDWDSTART_EVENT_HELP">
      <EventParam isSearchKey="true" type="UINT32" name="wdId" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="618" name="EVENT_WINDTICKUNDELAY" trigger="true" displayName="[Wake delayed task]" hasTimeStamp="false" icon="images/tick_undelay.gif" helpTopicId="VXWORKS6_EVENT_WINDTICKUNDELAY_EVENT_HELP">
      
      <EventParam isSearchKey="true" type="UINT32" name="pTcb" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="631" name="EVENT_WINDTICKTIMEOUT" trigger="true" displayName="[Tick timeout]" hasTimeStamp="false" icon="images/tick_timeout.gif" helpTopicId="VXWORKS6_EVENT_WINDTICKTIMEOUT_EVENT_HELP">
      
      <EventParam type="UINT32" name="tid" formatStr="0x%08x"/>
    </EventDescription>
  </EventClass>
  <EventClass key="events" displayName="Event Events" helpTopicId="VXWORKS6_events_CLASS_HELP">
    <EventDescription id="10057" name="EVENT_EVENTSEND" trigger="true" displayName="eventSend" icon="images/eventSend.gif" helpTopicId="VXWORKS6_EVENT_EVENTSEND_EVENT_HELP">
      
      <EventParam isSearchKey="true" type="UINT32" name="taskId" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="events" formatStr="0x%08x"/>
    </EventDescription>
    <EventDescription id="10058" name="EVENT_EVENTRECEIVE" trigger="true" displayName="eventReceive" icon="images/eventReceive.gif" helpTopicId="VXWORKS6_EVENT_EVENTRECEIVE_EVENT_HELP">      
      <EventParam type="UINT32" name="events" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="timeout" formatter="com.windriver.windview.plugins.wv.vxworks6.parmfmt.WaitOptions"/>
      <EventParam type="UINT32" name="flags" formatter="com.windriver.windview.plugins.wv.vxworks6.parmfmt.EventReceiveOptions"/>
    </EventDescription>
    <EventDescription id="635" name="EVENT_OBJ_EVENTSEND" hasTimeStamp="false"
      isSearchable="false"
      helpTopicId="VXWORKS6_EVENT_OBJ_EVENTSEND_EVENT_HELP">
      
    </EventDescription>
    <EventDescription id="636" name="EVENT_OBJ_EVENTRECEIVE"
      hasTimeStamp="false" isSearchable="false"
      helpTopicId="VXWORKS6_EVENT_OBJ_EVENTRECEIVE_EVENT_HELP">
      
    </EventDescription>
  </EventClass>
  <EventClass key="state" displayName="State Change Events" helpTopicId="VXWORKS6_state_CLASS_HELP">
    <EventDescription id="61" name="EVENT_TASK_STATECHANGE" displayName="State change" isSearchable="false">
      <EventParam isSearchKey="true" type="UINT32" name="taskId" formatStr="0x%08x"/>
      <EventParam type="UINT32" name="oldState" formatter="com.windriver.windview.agnostic.wv.StateTypeDecoder"/>
      <EventParam type="UINT32" name="newState" formatter="com.windriver.windview.agnostic.wv.StateTypeDecoder"/>
    </EventDescription>
  </EventClass>
  <StateDescription stateValue="0" brush="images/smm_read.gif" name="Ready" isLegendEntry="true" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="1" brush="images/smm_susp.gif" name="Suspended" isLegendEntry="true" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="2" brush="images/smm_pend.gif" name="Pending" isLegendEntry="true" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="3" brush="images/smm_susp.gif" name="Pending+Suspended" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="4" brush="images/smm_dela.gif" name="Delayed" isLegendEntry="true" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="5" brush="images/smm_susp.gif" name="Delayed+Suspended" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="6" brush="images/smm_pend.gif" name="Delayed+Pending" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="7" brush="images/smm_susp.gif" name="Delayed+Pending+Suspended" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="8" brush="images/smm_dead.gif" name="Dead" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="16" brush="images/smm_lock.gif" name="Locked" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="32" brush="images/smm_read.gif" name="Ready+Inherited" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="33" brush="images/smm_susp.gif" name="Suspended (Inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="34" brush="images/smm_pend.gif" name="Pending (Inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="35" brush="images/smm_susp.gif" name="Pending+Suspended (Inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="36" brush="images/smm_dela.gif" name="Delayed (Inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="37" brush="images/smm_susp.gif" name="Delayed+Suspended (Inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="38" brush="images/smm_pend.gif" name="Delayed+Pending (Inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="39" brush="images/smm_susp.gif" name="Delayed+Pending+Suspended (Inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="64" brush="images/smm_exec.gif" name="Running" isLegendEntry="true" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="65" brush="images/smm_exec.gif" name="Running (Suspended)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="66" brush="images/smm_exec.gif" name="Running (Pending)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="67" brush="images/smm_exec.gif" name="Running (Pending+Suspended)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="68" brush="images/smm_exec.gif" name="Running (Delayed)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="69" brush="images/smm_exec.gif" name="Running (Delayed+Suspended)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="70" brush="images/smm_exec.gif" name="Running (Delayed+Pending)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="71" brush="images/smm_exec.gif" name="Running (Delayed+Pending+Suspended)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="72" brush="images/smm_exec.gif" name="Running (Delayed+Pending+Suspended)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="80" brush="images/smm_lock.gif" name="Running (Locked)" isLegendEntry="true" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="81" brush="images/smm_lock.gif" name="Running (Locked+Suspended)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="82" brush="images/smm_lock.gif" name="Running (Locked+Pending)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="83" brush="images/smm_lock.gif" name="Running (Locked+Pending+Suspended)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="84" brush="images/smm_lock.gif" name="Running (Locked+Delayed)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="85" brush="images/smm_lock.gif" name="Running (Locked+Delayed+Suspended)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="86" brush="images/smm_lock.gif" name="Running (Locked+Delayed+Pending)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="87" brush="images/smm_lock.gif" name="Running (Locked+Delayed+Pending+Suspended)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="96" brush="images/smm_inhe.gif" name="Running (Inherited)" isLegendEntry="true" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="97" brush="images/smm_inhe.gif" name="Running (Inherited+Suspended)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="98" brush="images/smm_inhe.gif" name="Running (Inherited+Pending)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="99" brush="images/smm_inhe.gif" name="Running (Inherited+Pending+Suspended)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="100" brush="images/smm_inhe.gif" name="Running (Inherited+Delayed)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="101" brush="images/smm_inhe.gif" name="Running (Inherited+Delayed+Suspended)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="102" brush="images/smm_inhe.gif" name="Running (Inherited+Delayed+Pending)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="103" brush="images/smm_inhe.gif" name="Running (Inherited+Delayed+Pending+Suspended)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="112" brush="images/smm_lock.gif" name="Running (Locked+Inherited)" isLegendEntry="true" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="113" brush="images/smm_lock.gif" name="Suspended (Locked+Inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="114" brush="images/smm_lock.gif" name="Pending (Locked+Inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="115" brush="images/smm_lock.gif" name="Pending+Suspended (Locked+Inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="116" brush="images/smm_lock.gif" name="Delayed (Locked+Inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="117" brush="images/smm_lock.gif" name="Delayed+Suspended (Locked+Inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="118" brush="images/smm_lock.gif" name="Delayed+Pending (Locked+Inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="119" brush="images/smm_lock.gif" name="Delayed+Pending+Suspended (Locked+Inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="128" brush="images/smm_brak.gif" name="Stopped" isLegendEntry="true" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="129" brush="images/smm_brak.gif" name="Stopped+Suspended" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="130" brush="images/smm_brak.gif" name="Stopped+Pending" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="131" brush="images/smm_brak.gif" name="Stopped+Pending+Suspended" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="132" brush="images/smm_brak.gif" name="Stopped+Delayed" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="133" brush="images/smm_brak.gif" name="Stopped+Delayed+Suspended" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="134" brush="images/smm_brak.gif" name="Stopped+Delayed+Pending" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="135" brush="images/smm_brak.gif" name="Stopped+Delayed+Pending+Suspended" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="144" brush="images/smm_brak.gif" name="Stopped (Locked)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="145" brush="images/smm_brak.gif" name="Stopped+Suspended (Locked)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="146" brush="images/smm_brak.gif" name="Stopped+Pending (Locked)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="147" brush="images/smm_brak.gif" name="Stopped+Pending+Suspended (Locked)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="148" brush="images/smm_brak.gif" name="Stopped+Delayed (Locked)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="149" brush="images/smm_brak.gif" name="Stopped+Delayed+Suspended (Locked)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="150" brush="images/smm_brak.gif" name="Stopped+Delayed+Pending (Locked)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="151" brush="images/smm_brak.gif" name="Stopped+Delayed+Pending+Suspended (Locked)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="160" brush="images/smm_brak.gif" name="Stopped (Inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="161" brush="images/smm_brak.gif" name="Stopped+Suspended (Inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="162" brush="images/smm_brak.gif" name="Stopped+Pending (Inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="163" brush="images/smm_brak.gif" name="Stopped+Pending+Suspended (Inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="164" brush="images/smm_brak.gif" name="Stopped+Delayed (Inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="165" brush="images/smm_brak.gif" name="Stopped+Delayed+Suspended (Inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="166" brush="images/smm_brak.gif" name="Stopped+Delayed+Pending (Inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="167" brush="images/smm_brak.gif" name="Stopped+Delayed+Pending+Suspended (Inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="176" brush="images/smm_brak.gif" name="Stopped (Locked+Inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="177" brush="images/smm_brak.gif" name="Stopped+Suspended (Locked+Inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="178" brush="images/smm_brak.gif" name="Stopped+Pending (Locked+Inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="179" brush="images/smm_brak.gif" name="Stopped+Pending+Suspended (Locked+Inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="180" brush="images/smm_brak.gif" name="Stopped+Delayed (Locked+Inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="181" brush="images/smm_brak.gif" name="Stopped+Delayed+Suspended (Locked+Inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="182" brush="images/smm_brak.gif" name="Stopped+Delayed+Pending (Locked+Inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="183" brush="images/smm_brak.gif" name="Stopped+Delayed+Pending+Suspended (Locked+Inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="192" brush="images/smm_exec.gif" name="Running (Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="193" brush="images/smm_exec.gif" name="Running (Suspended+Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="194" brush="images/smm_exec.gif" name="Running (Pending+Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="195" brush="images/smm_exec.gif" name="Running (Pending+Suspended+Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="196" brush="images/smm_exec.gif" name="Running (Delayed+Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="197" brush="images/smm_exec.gif" name="Running (Delayed+Suspended+Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="198" brush="images/smm_exec.gif" name="Running (Delayed+Pending+Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="199" brush="images/smm_exec.gif" name="Running (Delayed+Pending+Suspended+Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="208" brush="images/smm_lock.gif" name="Running (Locked+Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="209" brush="images/smm_lock.gif" name="Running (Locked+Suspended+Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="210" brush="images/smm_lock.gif" name="Running (Locked+Pending+Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="211" brush="images/smm_lock.gif" name="Running (Locked+Pending+Suspended+Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="212" brush="images/smm_lock.gif" name="Running (Locked+Delayed+Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="213" brush="images/smm_lock.gif" name="Running (Locked+Delayed+Suspended+Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="214" brush="images/smm_lock.gif" name="Running (Locked+Delayed+Pending+Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="215" brush="images/smm_lock.gif" name="Running (Locked+Delayed+Pending+Suspended+Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="224" brush="images/smm_inhe.gif" name="Running (Inherited+Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="225" brush="images/smm_inhe.gif" name="Running (Inherited+Suspended+Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="226" brush="images/smm_inhe.gif" name="Running (Inherited+Pending+Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="227" brush="images/smm_inhe.gif" name="Running (Inherited+Pending+Suspended+Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="228" brush="images/smm_inhe.gif" name="Running (Inherited+Delayed+Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="229" brush="images/smm_inhe.gif" name="Running (Inherited+Delayed+Suspended+Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="230" brush="images/smm_inhe.gif" name="Running (Inherited+Delayed+Pending+Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="231" brush="images/smm_inhe.gif" name="Running (Inherited+Delayed+Pending+Suspended+Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="240" brush="images/smm_lock.gif" name="Running (Locked+Inherited+Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="241" brush="images/smm_lock.gif" name="Running (Locked+Inherited+Suspended+Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="242" brush="images/smm_lock.gif" name="Running (Locked+Inherited+Pending+Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="243" brush="images/smm_lock.gif" name="Running (Locked+Inherited+Pending+Suspended+Stopped )" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="244" brush="images/smm_lock.gif" name="Running (Locked+Inherited+Delayed+Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="245" brush="images/smm_lock.gif" name="Running (Locked+Inherited+Delayed+Suspended+Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="246" brush="images/smm_lock.gif" name="Running (Locked+Inherited+Delayed+Pending+Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>
  <StateDescription stateValue="247" brush="images/smm_lock.gif" name="Running (Locked+Inherited+Delayed+Pending+Suspended+Stopped)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>


<!-- wind_pend wind_running wind_spinlock_wait - transient state -->
  <StateDescription stateValue="322" brush="images/smm_spinwait.gif" 
    name="Running (waiting spinlock, will pend)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>

<!-- wind_pend wind_running wind_spinlock_held - transient state -->
  <StateDescription stateValue="578" brush="images/smm_spinheld.gif" 
    name="Running (holding spinlock, will pend)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>

<!-- waiting for spinlock, not running (e.g. interrupted) -->
  <StateDescription stateValue="256" brush="images/smm_read.gif" 
    name="Ready  (waiting spinlock)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>

<!-- waiting for spinlock, running  -->
  <StateDescription stateValue="320" brush="images/smm_spinwait.gif" 
    name="Running (waiting spinlock)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>

<!-- waiting for spinlock, running, locked  -->
  <StateDescription stateValue="336" brush="images/smm_spinwait.gif" 
    name="Running (waiting spinlock, locked)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>

<!-- holding spinlock, not running (e.g. interrupted) -->
  <StateDescription stateValue="512" brush="images/smm_read.gif" 
    name="Ready (holding spinlock)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>

<!-- holding spinlock, running  -->
  <StateDescription stateValue="576" brush="images/smm_spinheld.gif"
    name="Running (holding spinlock)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>

<!-- holding spinlock, running, locked  -->
  <StateDescription stateValue="592" brush="images/smm_spinheld.gif" 
    name="Running (holding spinlock, locked)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>

<!-- holding spinlock, pending - application error?  -->
  <StateDescription stateValue="514" brush="images/smm_inhe.gif" 
    name="Running (holdingspinlock, pending)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>

<!-- holding spinlock, running, inherited -->
  <StateDescription stateValue="608" brush="images/smm_inhe.gif" 
    name="Running (holding spinlock, inherited)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>

<!-- holding spinlock, inherited, not running -->
  <StateDescription stateValue="544" brush="images/smm_inhe.gif" 
    name="Ready (waiting spinlock, locked)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>

<!-- pending, locked, running, spinlock held - parser transient state?  -->
  <StateDescription stateValue="594" brush="images/smm_inhe.gif" 
    name="Running (waiting spinlock, locked, running, pend)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>

<!-- stopped, spinlock held -->
  <StateDescription stateValue="640" brush="images/smm_brak.gif" 
    name="Stopped (spinlock held)" helpTopicId="VXWORKS6_STATE_STIPPLE_HELP"/>

</EventDictionary>
)delim";


std::string v7_32_smp_wrsvCoreEvents_xml = R"delim(
<?xml version="1.0" encoding="UTF-8"?>
<!--
/* wrsv_core.xml - core XML descriptions for all System Viewer */

/* Copyright 2008 Wind River Systems, Inc. */

/*
modification history
01a,20nov08,cjtc created
*/
-->
<!DOCTYPE EventDictionary SYSTEM "../../DTDs/EventDictionary.dtd">
<EventDictionary>
  <EventClass key="wrsv_core_events">
    <!-- declares the range 950-998 inclusive -->
    <EventRangeDescription eventIdStart="950" eventIdCount="49"
      nameRoot="WRSV_CORE_EVENT_" displayNameRoot="wrsvCoreEvent-"
      nameRootSuffixStart="0" trigger="false" isSearchable="false">
    </EventRangeDescription>
    
    <EventDescription id="999"
		      name="EVENT_DYNAMIC_EVENT_DESCRIPTION"
		      hasTimeStamp="false"
		      isSearchable="false">
      <EventParam type="UINT32"  name="id"/>
      <EventParam type="STRINGZ" name="name"/>
      <EventParam type="STRINGZ" name="xml"/>
    </EventDescription>
  
  </EventClass>
</EventDictionary>
)delim";

#endif