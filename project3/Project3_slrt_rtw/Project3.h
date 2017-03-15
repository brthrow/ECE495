/*
 * Project3.h
 *
 * Code generation for model "Project3".
 *
 * Model version              : 1.89
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Wed Mar 15 17:53:18 2017
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Project3_h_
#define RTW_HEADER_Project3_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef Project3_COMMON_INCLUDES_
# define Project3_COMMON_INCLUDES_
#include <xpcimports.h>
#include <xpcdatatypes.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* Project3_COMMON_INCLUDES_ */

#include "Project3_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->ModelData.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->ModelData.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->ModelData.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->ModelData.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)
#define rtModel_Project3               RT_MODEL_Project3_T

/* Definition for use in the target main file */
#define Project3_rtModel               RT_MODEL_Project3_T

/* user code (top of export header file) */
#include "xpcdatatypes.h"

/* Block signals (auto storage) */
typedef struct {
  real_T Setpoint;                     /* '<S1>/gain' */
  real_T Integrator6;                  /* '<S4>/Integrator6' */
  real_T Product2;                     /* '<S9>/Product2' */
  real_T Channel0ofEncoderInputs;      /* '<S3>/Channel 0 of  Encoder Inputs ' */
  real_T angular_positionrelative_countC;/* '<S3>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees' */
  real_T Product3;                     /* '<S9>/Product3' */
  real_T Sum2;                         /* '<S9>/Sum2' */
  real_T ErrorSignal;                  /* '<S1>/Sum1' */
  real_T Derivative1;                  /* '<S1>/Derivative1' */
  real_T Gain[3];                      /* '<S1>/Gain' */
  real_T Integrator1;                  /* '<S1>/Integrator1' */
  real_T Kd;                           /* '<S1>/Kd' */
  real_T Ki;                           /* '<S1>/Ki' */
  real_T Kp;                           /* '<S1>/Kp' */
  real_T Sum4;                         /* '<S1>/Sum4' */
  real_T Product1;                     /* '<S6>/Product1' */
  real_T Saturation;                   /* '<S3>/Saturation' */
  real_T Integrator5;                  /* '<S4>/Integrator5' */
  real_T BackemfKe1;                   /* '<S4>/Back emf Ke1' */
  real_T Dampingb1;                    /* '<S4>/Damping b1' */
  real_T Integrator1_h;                /* '<S4>/Integrator1' */
  real_T GainKt2;                      /* '<S4>/Gain Kt2' */
  real_T Sum2_e;                       /* '<S4>/Sum2' */
  real_T GainKt3;                      /* '<S4>/Gain Kt3' */
  real_T Product;                      /* '<S6>/Product' */
  real_T ResistanceR1;                 /* '<S4>/Resistance R1' */
  real_T Sum1;                         /* '<S4>/Sum1' */
  real_T Inductance;                   /* '<S4>/Inductance' */
  boolean_T complementtheinput1;       /* '<S9>/complement the input1' */
  boolean_T complementtheinput;        /* '<S6>/complement the input' */
} B_Project3_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T TimeStampA;                   /* '<S1>/Derivative1' */
  real_T LastUAtTimeA;                 /* '<S1>/Derivative1' */
  real_T TimeStampB;                   /* '<S1>/Derivative1' */
  real_T LastUAtTimeB;                 /* '<S1>/Derivative1' */
  real_T Channel0Controlsignaltomotorthr[16];/* '<S3>/Channel 0 -Control signal to  motor through amplifier ' */
  int_T Channel0ofEncoderInputs_IWORK[3];/* '<S3>/Channel 0 of  Encoder Inputs ' */
  struct {
    int_T AcquireOK;
  } SFunction_IWORK;                   /* '<S2>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_i;                 /* '<S5>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_it;                /* '<S7>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_n;                 /* '<S8>/S-Function' */

  int_T Channel0Controlsignaltomotort_l;/* '<S3>/Channel 0 -Control signal to  motor through amplifier ' */
} DW_Project3_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator6_CSTATE;           /* '<S4>/Integrator6' */
  real_T Integrator1_CSTATE;           /* '<S1>/Integrator1' */
  real_T Integrator5_CSTATE;           /* '<S4>/Integrator5' */
  real_T Integrator1_CSTATE_i;         /* '<S4>/Integrator1' */
} X_Project3_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator6_CSTATE;           /* '<S4>/Integrator6' */
  real_T Integrator1_CSTATE;           /* '<S1>/Integrator1' */
  real_T Integrator5_CSTATE;           /* '<S4>/Integrator5' */
  real_T Integrator1_CSTATE_i;         /* '<S4>/Integrator1' */
} XDot_Project3_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator6_CSTATE;        /* '<S4>/Integrator6' */
  boolean_T Integrator1_CSTATE;        /* '<S1>/Integrator1' */
  boolean_T Integrator5_CSTATE;        /* '<S4>/Integrator5' */
  boolean_T Integrator1_CSTATE_i;      /* '<S4>/Integrator1' */
} XDis_Project3_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T setpoint_Out;                 /* '<Root>/setpoint_Out' */
  real_T errorSignal_Out;              /* '<Root>/errorSignal_Out' */
  real_T motorPos_Out;                 /* '<Root>/motorPos_Out' */
} ExtY_Project3_T;

/* Backward compatible GRT Identifiers */
#define rtB                            Project3_B
#define BlockIO                        B_Project3_T
#define rtX                            Project3_X
#define ContinuousStates               X_Project3_T
#define rtXdot                         Project3_XDot
#define StateDerivatives               XDot_Project3_T
#define tXdis                          Project3_XDis
#define StateDisabled                  XDis_Project3_T
#define rtY                            Project3_Y
#define ExternalOutputs                ExtY_Project3_T
#define rtP                            Project3_P
#define Parameters                     P_Project3_T
#define rtDWork                        Project3_DW
#define D_Work                         DW_Project3_T

/* Parameters (auto storage) */
struct P_Project3_T_ {
  real_T Constant_Value;               /* Expression: -5.1612
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<S1>/gain'
                                        */
  real_T Integrator6_IC;               /* Expression: 0
                                        * Referenced by: '<S4>/Integrator6'
                                        */
  real_T Usesimulatedmotor0Userealmotor_;/* Expression: 0
                                          * Referenced by: '<S1>/1 - Use simulated motor 0 - Use real motor'
                                          */
  real_T Channel0ofEncoderInputs_P1_Size[2];/* Computed Parameter: Channel0ofEncoderInputs_P1_Size
                                             * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                             */
  real_T Channel0ofEncoderInputs_P1;   /* Expression: boardtype
                                        * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                        */
  real_T Channel0ofEncoderInputs_P2_Size[2];/* Computed Parameter: Channel0ofEncoderInputs_P2_Size
                                             * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                             */
  real_T Channel0ofEncoderInputs_P2;   /* Expression: channel
                                        * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                        */
  real_T Channel0ofEncoderInputs_P3_Size[2];/* Computed Parameter: Channel0ofEncoderInputs_P3_Size
                                             * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                             */
  real_T Channel0ofEncoderInputs_P3;   /* Expression: initialCount
                                        * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                        */
  real_T Channel0ofEncoderInputs_P4_Size[2];/* Computed Parameter: Channel0ofEncoderInputs_P4_Size
                                             * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                             */
  real_T Channel0ofEncoderInputs_P4;   /* Expression: prescale
                                        * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                        */
  real_T Channel0ofEncoderInputs_P5_Size[2];/* Computed Parameter: Channel0ofEncoderInputs_P5_Size
                                             * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                             */
  real_T Channel0ofEncoderInputs_P5;   /* Expression: quadrature
                                        * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                        */
  real_T Channel0ofEncoderInputs_P6_Size[2];/* Computed Parameter: Channel0ofEncoderInputs_P6_Size
                                             * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                             */
  real_T Channel0ofEncoderInputs_P6;   /* Expression: mode
                                        * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                        */
  real_T Channel0ofEncoderInputs_P7_Size[2];/* Computed Parameter: Channel0ofEncoderInputs_P7_Size
                                             * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                             */
  real_T Channel0ofEncoderInputs_P7;   /* Expression: synchronousIndex
                                        * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                        */
  real_T Channel0ofEncoderInputs_P8_Size[2];/* Computed Parameter: Channel0ofEncoderInputs_P8_Size
                                             * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                             */
  real_T Channel0ofEncoderInputs_P8;   /* Expression: indexPolarity
                                        * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                        */
  real_T Channel0ofEncoderInputs_P9_Size[2];/* Computed Parameter: Channel0ofEncoderInputs_P9_Size
                                             * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                             */
  real_T Channel0ofEncoderInputs_P9;   /* Expression: preserveCounts
                                        * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                        */
  real_T Channel0ofEncoderInputs_P10_Siz[2];/* Computed Parameter: Channel0ofEncoderInputs_P10_Siz
                                             * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                             */
  real_T Channel0ofEncoderInputs_P10;  /* Expression: sampleTime
                                        * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                        */
  real_T Channel0ofEncoderInputs_P11_Siz[2];/* Computed Parameter: Channel0ofEncoderInputs_P11_Siz
                                             * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                             */
  real_T Channel0ofEncoderInputs_P11;  /* Expression: pciBus
                                        * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                        */
  real_T Channel0ofEncoderInputs_P12_Siz[2];/* Computed Parameter: Channel0ofEncoderInputs_P12_Siz
                                             * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                             */
  real_T Channel0ofEncoderInputs_P12;  /* Expression: pciSlot
                                        * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                        */
  real_T angular_positionrelative_countC;/* Expression: -360/1600
                                          * Referenced by: '<S3>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees'
                                          */
  real_T Gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator1'
                                        */
  real_T Kd_Gain;                      /* Expression: .011
                                        * Referenced by: '<S1>/Kd'
                                        */
  real_T Ki_Gain;                      /* Expression: .026/2
                                        * Referenced by: '<S1>/Ki'
                                        */
  real_T Kp_Gain;                      /* Expression: .5*5
                                        * Referenced by: '<S1>/Kp'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 10
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -10
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Channel0Controlsignaltomotorthr[2];/* Computed Parameter: Channel0Controlsignaltomotorthr
                                             * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
                                             */
  real_T Channel0Controlsignaltomotort_m;/* Expression: boardtype
                                          * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
                                          */
  real_T Channel0Controlsignaltomotort_h[2];/* Computed Parameter: Channel0Controlsignaltomotort_h
                                             * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
                                             */
  real_T Channel0Controlsignaltomotort_k;/* Expression: channel
                                          * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
                                          */
  real_T Channel0Controlsignaltomotort_e[2];/* Computed Parameter: Channel0Controlsignaltomotort_e
                                             * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
                                             */
  real_T Channel0Controlsignaltomotort_c;/* Expression: range
                                          * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
                                          */
  real_T Channel0Controlsignaltomotor_e1[2];/* Computed Parameter: Channel0Controlsignaltomotor_e1
                                             * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
                                             */
  real_T Channel0Controlsignaltomotort_d;/* Expression: simul
                                          * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
                                          */
  real_T Channel0Controlsignaltomotor_cz[2];/* Computed Parameter: Channel0Controlsignaltomotor_cz
                                             * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
                                             */
  real_T Channel0Controlsignaltomotort_n;/* Expression: reset
                                          * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
                                          */
  real_T Channel0Controlsignaltomotort_l[2];/* Computed Parameter: Channel0Controlsignaltomotort_l
                                             * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
                                             */
  real_T Channel0Controlsignaltomotort_g;/* Expression: initValue
                                          * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
                                          */
  real_T Channel0Controlsignaltomotort_b[2];/* Computed Parameter: Channel0Controlsignaltomotort_b
                                             * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
                                             */
  real_T Channel0Controlsignaltomotort_f;/* Expression: sampleTime
                                          * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
                                          */
  real_T Channel0Controlsignaltomotort_a[2];/* Computed Parameter: Channel0Controlsignaltomotort_a
                                             * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
                                             */
  real_T Channel0Controlsignaltomotor_gv;/* Expression: pciBus
                                          * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
                                          */
  real_T Channel0Controlsignaltomotor_lv[2];/* Computed Parameter: Channel0Controlsignaltomotor_lv
                                             * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
                                             */
  real_T Channel0Controlsignaltomotor_gp;/* Expression: pciSlot
                                          * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
                                          */
  real_T Integrator5_IC;               /* Expression: 0
                                        * Referenced by: '<S4>/Integrator5'
                                        */
  real_T BackemfKe1_Gain;              /* Expression: 0.0274
                                        * Referenced by: '<S4>/Back emf Ke1'
                                        */
  real_T Dampingb1_Gain;               /* Expression: 3.5077E-6
                                        * Referenced by: '<S4>/Damping b1'
                                        */
  real_T Integrator1_IC_j;             /* Expression: 0
                                        * Referenced by: '<S4>/Integrator1'
                                        */
  real_T GainKt2_Gain;                 /* Expression: 0.0274
                                        * Referenced by: '<S4>/Gain Kt2'
                                        */
  real_T GainKt3_Gain;                 /* Expression: 1/(3.2284E-6)
                                        * Referenced by: '<S4>/Gain Kt3'
                                        */
  real_T ResistanceR1_Gain;            /* Expression: 4
                                        * Referenced by: '<S4>/Resistance R1'
                                        */
  real_T Inductance_Gain;              /* Expression: 1/(1E-2)
                                        * Referenced by: '<S4>/Inductance'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Project3_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[2];
    SimStruct childSFunctions[2];
    SimStruct *childSFunctionPtrs[2];
    struct _ssBlkInfo2 blkInfo2[2];
    struct _ssSFcnModelMethods2 methods2[2];
    struct _ssSFcnModelMethods3 methods3[2];
    struct _ssStatesInfo2 statesInfo2[2];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[12];
      mxArray *params[12];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[1];
      uint_T attribs[9];
      mxArray *params[9];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn1;
  } NonInlinedSFcns;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
  } DataMapInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    void *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    void *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[4];
    real_T odeF[3][4];
    ODE3_IntgData intgData;
    void *dwork;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Project3_T Project3_P;

/* Block signals (auto storage) */
extern B_Project3_T Project3_B;

/* Continuous states (auto storage) */
extern X_Project3_T Project3_X;

/* Block states (auto storage) */
extern DW_Project3_T Project3_DW;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_Project3_T Project3_Y;

/* Model entry point functions */
extern void Project3_initialize(void);
extern void Project3_output(void);
extern void Project3_update(void);
extern void Project3_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern Project3_rtModel *Project3(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_Project3_T *const Project3_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Project3'
 * '<S1>'   : 'Project3/Subsystem'
 * '<S2>'   : 'Project3/Subsystem/Data Display'
 * '<S3>'   : 'Project3/Subsystem/Real motor'
 * '<S4>'   : 'Project3/Subsystem/Simulated motor'
 * '<S5>'   : 'Project3/Subsystem/error signal'
 * '<S6>'   : 'Project3/Subsystem/input side switching logic'
 * '<S7>'   : 'Project3/Subsystem/motor position'
 * '<S8>'   : 'Project3/Subsystem/setpoint'
 * '<S9>'   : 'Project3/Subsystem/switching logic'
 */
#endif                                 /* RTW_HEADER_Project3_h_ */
