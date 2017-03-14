/*
 * downloaded_from_web.c
 *
 * Code generation for model "downloaded_from_web".
 *
 * Model version              : 1.4
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Mar 13 15:32:11 2017
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_logging_mmi.h"
#include "downloaded_from_web_capi.h"
#include "downloaded_from_web.h"
#include "downloaded_from_web_private.h"

/* Block signals (auto storage) */
B_downloaded_from_web_T downloaded_from_web_B;

/* Block states (auto storage) */
DW_downloaded_from_web_T downloaded_from_web_DW;

/* Real-time model */
RT_MODEL_downloaded_from_web_T downloaded_from_web_M_;
RT_MODEL_downloaded_from_web_T *const downloaded_from_web_M =
  &downloaded_from_web_M_;

/* Model output function */
static void downloaded_from_web_output(void)
{
  /* Constant: '<Root>/Constant' */
  downloaded_from_web_B.Constant = downloaded_from_web_P.Constant_Value;

  /* Level2 S-Function Block: '<Root>/Q4 Enc ' (encquanserq8) */
  {
    SimStruct *rts = downloaded_from_web_M->childSfunctions[0];
    sfcnOutputs(rts, 1);
  }

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  downloaded_from_web_B.PulseGenerator =
    (downloaded_from_web_DW.clockTickCounter <
     downloaded_from_web_P.PulseGenerator_Duty) &&
    (downloaded_from_web_DW.clockTickCounter >= 0) ?
    downloaded_from_web_P.PulseGenerator_Amp : 0.0;
  if (downloaded_from_web_DW.clockTickCounter >=
      downloaded_from_web_P.PulseGenerator_Period - 1.0) {
    downloaded_from_web_DW.clockTickCounter = 0;
  } else {
    downloaded_from_web_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* Level2 S-Function Block: '<Root>/Q4 DA ' (daquanserq8) */
  {
    SimStruct *rts = downloaded_from_web_M->childSfunctions[1];
    sfcnOutputs(rts, 1);
  }

  /* ok to acquire for <S1>/S-Function */
  downloaded_from_web_DW.SFunction_IWORK.AcquireOK = 1;

  /* ok to acquire for <S2>/S-Function */
  downloaded_from_web_DW.SFunction_IWORK_n.AcquireOK = 1;

  /* Level2 S-Function Block: '<Root>/Q4 AD' (adquanserq8) */
  {
    SimStruct *rts = downloaded_from_web_M->childSfunctions[2];
    sfcnOutputs(rts, 1);
  }

  /* Sin: '<Root>/Sine Wave' */
  downloaded_from_web_B.SineWave = sin(downloaded_from_web_P.SineWave_Freq *
    downloaded_from_web_M->Timing.t[0] + downloaded_from_web_P.SineWave_Phase) *
    downloaded_from_web_P.SineWave_Amp + downloaded_from_web_P.SineWave_Bias;
}

/* Model update function */
static void downloaded_from_web_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++downloaded_from_web_M->Timing.clockTick0)) {
    ++downloaded_from_web_M->Timing.clockTickH0;
  }

  downloaded_from_web_M->Timing.t[0] = downloaded_from_web_M->Timing.clockTick0 *
    downloaded_from_web_M->Timing.stepSize0 +
    downloaded_from_web_M->Timing.clockTickH0 *
    downloaded_from_web_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++downloaded_from_web_M->Timing.clockTick1)) {
      ++downloaded_from_web_M->Timing.clockTickH1;
    }

    downloaded_from_web_M->Timing.t[1] =
      downloaded_from_web_M->Timing.clockTick1 *
      downloaded_from_web_M->Timing.stepSize1 +
      downloaded_from_web_M->Timing.clockTickH1 *
      downloaded_from_web_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
static void downloaded_from_web_initialize(void)
{
  /* Level2 S-Function Block: '<Root>/Q4 Enc ' (encquanserq8) */
  {
    SimStruct *rts = downloaded_from_web_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  downloaded_from_web_DW.clockTickCounter = 0;

  /* Level2 S-Function Block: '<Root>/Q4 DA ' (daquanserq8) */
  {
    SimStruct *rts = downloaded_from_web_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* S-Function Block: <S1>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(2)) == 0) {
      if ((i = rl32eDefScope(2,2)) != 0) {
        printf("Error creating scope 2\n");
      } else {
        rl32eAddSignal(2, rl32eGetSignalNo("Pulse Generator"));
        rl32eSetScope(2, 4, 250);
        rl32eSetScope(2, 5, 0);
        rl32eSetScope(2, 6, 1);
        rl32eSetScope(2, 0, 0);
        rl32eSetScope(2, 3, rl32eGetSignalNo("Pulse Generator"));
        rl32eSetScope(2, 1, 0.0);
        rl32eSetScope(2, 2, 0);
        rl32eSetScope(2, 9, 0);
        rl32eSetTargetScope(2, 1, 3.0);
        rl32eSetTargetScope(2, 11, -5.0);
        rl32eSetTargetScope(2, 10, 5.0);
        xpceScopeAcqOK(2, &downloaded_from_web_DW.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* S-Function Block: <S2>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(3)) == 0) {
      if ((i = rl32eDefScope(3,1)) != 0) {
        printf("Error creating scope 3\n");
      } else {
        rl32eAddSignal(3, rl32eGetSignalNo("Q4 AD"));
        rl32eSetScope(3, 4, 250);
        rl32eSetScope(3, 5, 0);
        rl32eSetScope(3, 6, 1);
        rl32eSetScope(3, 0, 0);
        rl32eSetScope(3, 3, rl32eGetSignalNo("Q4 AD"));
        rl32eSetScope(3, 1, 0.0);
        rl32eSetScope(3, 2, 0);
        rl32eSetScope(3, 9, 0);
        xpceScopeAcqOK(3, &downloaded_from_web_DW.SFunction_IWORK_n.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(3);
    }
  }

  /* Level2 S-Function Block: '<Root>/Q4 AD' (adquanserq8) */
  {
    SimStruct *rts = downloaded_from_web_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
static void downloaded_from_web_terminate(void)
{
  /* Level2 S-Function Block: '<Root>/Q4 Enc ' (encquanserq8) */
  {
    SimStruct *rts = downloaded_from_web_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<Root>/Q4 DA ' (daquanserq8) */
  {
    SimStruct *rts = downloaded_from_web_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<Root>/Q4 AD' (adquanserq8) */
  {
    SimStruct *rts = downloaded_from_web_M->childSfunctions[2];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  downloaded_from_web_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  downloaded_from_web_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  downloaded_from_web_initialize();
}

void MdlTerminate(void)
{
  downloaded_from_web_terminate();
}

/* Registration function */
RT_MODEL_downloaded_from_web_T *downloaded_from_web(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)downloaded_from_web_M, 0,
                sizeof(RT_MODEL_downloaded_from_web_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&downloaded_from_web_M->solverInfo,
                          &downloaded_from_web_M->Timing.simTimeStep);
    rtsiSetTPtr(&downloaded_from_web_M->solverInfo, &rtmGetTPtr
                (downloaded_from_web_M));
    rtsiSetStepSizePtr(&downloaded_from_web_M->solverInfo,
                       &downloaded_from_web_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&downloaded_from_web_M->solverInfo,
                          (&rtmGetErrorStatus(downloaded_from_web_M)));
    rtsiSetRTModelPtr(&downloaded_from_web_M->solverInfo, downloaded_from_web_M);
  }

  rtsiSetSimTimeStep(&downloaded_from_web_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&downloaded_from_web_M->solverInfo,"FixedStepDiscrete");
  downloaded_from_web_M->solverInfoPtr = (&downloaded_from_web_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = downloaded_from_web_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    downloaded_from_web_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    downloaded_from_web_M->Timing.sampleTimes =
      (&downloaded_from_web_M->Timing.sampleTimesArray[0]);
    downloaded_from_web_M->Timing.offsetTimes =
      (&downloaded_from_web_M->Timing.offsetTimesArray[0]);

    /* task periods */
    downloaded_from_web_M->Timing.sampleTimes[0] = (0.0);
    downloaded_from_web_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    downloaded_from_web_M->Timing.offsetTimes[0] = (0.0);
    downloaded_from_web_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(downloaded_from_web_M, &downloaded_from_web_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = downloaded_from_web_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    downloaded_from_web_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(downloaded_from_web_M, 10.0);
  downloaded_from_web_M->Timing.stepSize0 = 0.001;
  downloaded_from_web_M->Timing.stepSize1 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    downloaded_from_web_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(downloaded_from_web_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(downloaded_from_web_M->rtwLogInfo, (NULL));
    rtliSetLogT(downloaded_from_web_M->rtwLogInfo, "tout");
    rtliSetLogX(downloaded_from_web_M->rtwLogInfo, "");
    rtliSetLogXFinal(downloaded_from_web_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(downloaded_from_web_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(downloaded_from_web_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(downloaded_from_web_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(downloaded_from_web_M->rtwLogInfo, 1);
    rtliSetLogY(downloaded_from_web_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(downloaded_from_web_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(downloaded_from_web_M->rtwLogInfo, (NULL));
  }

  downloaded_from_web_M->solverInfoPtr = (&downloaded_from_web_M->solverInfo);
  downloaded_from_web_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&downloaded_from_web_M->solverInfo, 0.001);
  rtsiSetSolverMode(&downloaded_from_web_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  downloaded_from_web_M->ModelData.blockIO = ((void *) &downloaded_from_web_B);
  (void) memset(((void *) &downloaded_from_web_B), 0,
                sizeof(B_downloaded_from_web_T));

  /* parameters */
  downloaded_from_web_M->ModelData.defaultParam = ((real_T *)
    &downloaded_from_web_P);

  /* states (dwork) */
  downloaded_from_web_M->ModelData.dwork = ((void *) &downloaded_from_web_DW);
  (void) memset((void *)&downloaded_from_web_DW, 0,
                sizeof(DW_downloaded_from_web_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  downloaded_from_web_InitializeDataMapInfo(downloaded_from_web_M);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &downloaded_from_web_M->NonInlinedSFcns.sfcnInfo;
    downloaded_from_web_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(downloaded_from_web_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &downloaded_from_web_M->Sizes.numSampTimes);
    downloaded_from_web_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (downloaded_from_web_M)[0]);
    downloaded_from_web_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (downloaded_from_web_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,downloaded_from_web_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(downloaded_from_web_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(downloaded_from_web_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (downloaded_from_web_M));
    rtssSetStepSizePtr(sfcnInfo, &downloaded_from_web_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(downloaded_from_web_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &downloaded_from_web_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &downloaded_from_web_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &downloaded_from_web_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &downloaded_from_web_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &downloaded_from_web_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &downloaded_from_web_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &downloaded_from_web_M->solverInfoPtr);
  }

  downloaded_from_web_M->Sizes.numSFcns = (3);

  /* register each child */
  {
    (void) memset((void *)
                  &downloaded_from_web_M->NonInlinedSFcns.childSFunctions[0], 0,
                  3*sizeof(SimStruct));
    downloaded_from_web_M->childSfunctions =
      (&downloaded_from_web_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    downloaded_from_web_M->childSfunctions[0] =
      (&downloaded_from_web_M->NonInlinedSFcns.childSFunctions[0]);
    downloaded_from_web_M->childSfunctions[1] =
      (&downloaded_from_web_M->NonInlinedSFcns.childSFunctions[1]);
    downloaded_from_web_M->childSfunctions[2] =
      (&downloaded_from_web_M->NonInlinedSFcns.childSFunctions[2]);

    /* Level2 S-Function Block: downloaded_from_web/<Root>/Q4 Enc  (encquanserq8) */
    {
      SimStruct *rts = downloaded_from_web_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        downloaded_from_web_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        downloaded_from_web_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = downloaded_from_web_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &downloaded_from_web_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, downloaded_from_web_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &downloaded_from_web_M->
                           NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &downloaded_from_web_M->
                           NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &downloaded_from_web_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &downloaded_from_web_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &downloaded_from_web_B.Q4Enc));
        }
      }

      /* path info */
      ssSetModelName(rts, "Q4 Enc ");
      ssSetPath(rts, "downloaded_from_web/Q4 Enc ");
      ssSetRTModel(rts,downloaded_from_web_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &downloaded_from_web_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 12);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)downloaded_from_web_P.Q4Enc_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)downloaded_from_web_P.Q4Enc_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)downloaded_from_web_P.Q4Enc_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)downloaded_from_web_P.Q4Enc_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)downloaded_from_web_P.Q4Enc_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)downloaded_from_web_P.Q4Enc_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)downloaded_from_web_P.Q4Enc_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)downloaded_from_web_P.Q4Enc_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)downloaded_from_web_P.Q4Enc_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)downloaded_from_web_P.Q4Enc_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)downloaded_from_web_P.Q4Enc_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)downloaded_from_web_P.Q4Enc_P12_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &downloaded_from_web_DW.Q4Enc_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &downloaded_from_web_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &downloaded_from_web_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &downloaded_from_web_DW.Q4Enc_IWORK[0]);
      }

      /* registration */
      encquanserq8(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: downloaded_from_web/<Root>/Q4 DA  (daquanserq8) */
    {
      SimStruct *rts = downloaded_from_web_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        downloaded_from_web_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        downloaded_from_web_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = downloaded_from_web_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &downloaded_from_web_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, downloaded_from_web_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &downloaded_from_web_M->
                           NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &downloaded_from_web_M->
                           NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &downloaded_from_web_M->NonInlinedSFcns.statesInfo2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &downloaded_from_web_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &downloaded_from_web_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &downloaded_from_web_B.PulseGenerator;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Q4 DA ");
      ssSetPath(rts, "downloaded_from_web/Q4 DA ");
      ssSetRTModel(rts,downloaded_from_web_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &downloaded_from_web_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)downloaded_from_web_P.Q4DA_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)downloaded_from_web_P.Q4DA_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)downloaded_from_web_P.Q4DA_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)downloaded_from_web_P.Q4DA_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)downloaded_from_web_P.Q4DA_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)downloaded_from_web_P.Q4DA_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)downloaded_from_web_P.Q4DA_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)downloaded_from_web_P.Q4DA_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)downloaded_from_web_P.Q4DA_P9_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &downloaded_from_web_DW.Q4DA_RWORK[0]);
      ssSetIWork(rts, (int_T *) &downloaded_from_web_DW.Q4DA_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &downloaded_from_web_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &downloaded_from_web_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 16);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &downloaded_from_web_DW.Q4DA_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &downloaded_from_web_DW.Q4DA_IWORK);
      }

      /* registration */
      daquanserq8(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: downloaded_from_web/<Root>/Q4 AD (adquanserq8) */
    {
      SimStruct *rts = downloaded_from_web_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod =
        downloaded_from_web_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset =
        downloaded_from_web_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = downloaded_from_web_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &downloaded_from_web_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, downloaded_from_web_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &downloaded_from_web_M->
                           NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &downloaded_from_web_M->
                           NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &downloaded_from_web_M->NonInlinedSFcns.statesInfo2[2]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &downloaded_from_web_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &downloaded_from_web_B.Q4AD));
        }
      }

      /* path info */
      ssSetModelName(rts, "Q4 AD");
      ssSetPath(rts, "downloaded_from_web/Q4 AD");
      ssSetRTModel(rts,downloaded_from_web_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &downloaded_from_web_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)downloaded_from_web_P.Q4AD_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)downloaded_from_web_P.Q4AD_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)downloaded_from_web_P.Q4AD_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)downloaded_from_web_P.Q4AD_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)downloaded_from_web_P.Q4AD_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)downloaded_from_web_P.Q4AD_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)downloaded_from_web_P.Q4AD_P7_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &downloaded_from_web_DW.Q4AD_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &downloaded_from_web_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &downloaded_from_web_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &downloaded_from_web_DW.Q4AD_IWORK[0]);
      }

      /* registration */
      adquanserq8(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }
  }

  /* Initialize Sizes */
  downloaded_from_web_M->Sizes.numContStates = (0);/* Number of continuous states */
  downloaded_from_web_M->Sizes.numY = (0);/* Number of model outputs */
  downloaded_from_web_M->Sizes.numU = (0);/* Number of model inputs */
  downloaded_from_web_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  downloaded_from_web_M->Sizes.numSampTimes = (2);/* Number of sample times */
  downloaded_from_web_M->Sizes.numBlocks = (9);/* Number of blocks */
  downloaded_from_web_M->Sizes.numBlockIO = (5);/* Number of block outputs */
  downloaded_from_web_M->Sizes.numBlockPrms = (92);/* Sum of parameter "widths" */
  return downloaded_from_web_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
