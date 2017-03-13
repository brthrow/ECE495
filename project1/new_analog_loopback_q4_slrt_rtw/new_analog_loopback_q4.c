/*
 * new_analog_loopback_q4.c
 *
 * Code generation for model "new_analog_loopback_q4".
 *
 * Model version              : 1.11
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Mar 13 14:45:39 2017
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_logging_mmi.h"
#include "new_analog_loopback_q4_capi.h"
#include "new_analog_loopback_q4.h"
#include "new_analog_loopback_q4_private.h"

/* Block signals (auto storage) */
B_new_analog_loopback_q4_T new_analog_loopback_q4_B;

/* Block states (auto storage) */
DW_new_analog_loopback_q4_T new_analog_loopback_q4_DW;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_new_analog_loopback_q4_T new_analog_loopback_q4_Y;

/* Real-time model */
RT_MODEL_new_analog_loopback_q4_T new_analog_loopback_q4_M_;
RT_MODEL_new_analog_loopback_q4_T *const new_analog_loopback_q4_M =
  &new_analog_loopback_q4_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(new_analog_loopback_q4_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(new_analog_loopback_q4_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (new_analog_loopback_q4_M->Timing.TaskCounters.TID[2])++;
  if ((new_analog_loopback_q4_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.001s, 0.0s] */
    new_analog_loopback_q4_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Model output function for TID0 */
static void new_analog_loopback_q4_output0(void) /* Sample time: [0.0s, 0.0s] */
{
  real_T temp;

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Level2 S-Function Block: '<Root>/Q4 AD2' (adquanserq8) */
  {
    SimStruct *rts = new_analog_loopback_q4_M->childSfunctions[0];
    sfcnOutputs(rts, 0);
  }

  /* Outport: '<Root>/Out1' */
  new_analog_loopback_q4_Y.Out1 = new_analog_loopback_q4_B.Q4AD2_o2;

  /* Outport: '<Root>/Out2' */
  new_analog_loopback_q4_Y.Out2 = new_analog_loopback_q4_B.Q4AD2_o1;

  /* ok to acquire for <S1>/S-Function */
  new_analog_loopback_q4_DW.SFunction_IWORK.AcquireOK = 1;

  /* ok to acquire for <S2>/S-Function */
  new_analog_loopback_q4_DW.SFunction_IWORK_d.AcquireOK = 1;

  /* ok to acquire for <S3>/S-Function */
  new_analog_loopback_q4_DW.SFunction_IWORK_g.AcquireOK = 1;

  /* ok to acquire for <S4>/S-Function */
  new_analog_loopback_q4_DW.SFunction_IWORK_k.AcquireOK = 1;

  /* Sin: '<Root>/Sine Wave' */
  new_analog_loopback_q4_B.SineWave = sin(new_analog_loopback_q4_P.rad *
    new_analog_loopback_q4_M->Timing.t[0] +
    new_analog_loopback_q4_P.SineWave_Phase) *
    new_analog_loopback_q4_P.SineWave_Amp +
    new_analog_loopback_q4_P.SineWave_Bias;

  /* Level2 S-Function Block: '<Root>/Q4 DA ' (daquanserq8) */
  {
    SimStruct *rts = new_analog_loopback_q4_M->childSfunctions[2];
    sfcnOutputs(rts, 0);
  }

  /* SignalGenerator: '<Root>/Signal Generator' */
  temp = new_analog_loopback_q4_P.frequency * new_analog_loopback_q4_M->
    Timing.t[0];
  if (temp - floor(temp) >= 0.5) {
    new_analog_loopback_q4_B.SignalGenerator =
      new_analog_loopback_q4_P.SignalGenerator_Amplitude;
  } else {
    new_analog_loopback_q4_B.SignalGenerator =
      -new_analog_loopback_q4_P.SignalGenerator_Amplitude;
  }

  /* End of SignalGenerator: '<Root>/Signal Generator' */

  /* Level2 S-Function Block: '<Root>/Q4 DO ' (doquanserq8) */
  {
    SimStruct *rts = new_analog_loopback_q4_M->childSfunctions[3];
    sfcnOutputs(rts, 0);
  }
}

/* Model update function for TID0 */
static void new_analog_loopback_q4_update0(void) /* Sample time: [0.0s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++new_analog_loopback_q4_M->Timing.clockTick0)) {
    ++new_analog_loopback_q4_M->Timing.clockTickH0;
  }

  new_analog_loopback_q4_M->Timing.t[0] =
    new_analog_loopback_q4_M->Timing.clockTick0 *
    new_analog_loopback_q4_M->Timing.stepSize0 +
    new_analog_loopback_q4_M->Timing.clockTickH0 *
    new_analog_loopback_q4_M->Timing.stepSize0 * 4294967296.0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++new_analog_loopback_q4_M->Timing.clockTick1)) {
    ++new_analog_loopback_q4_M->Timing.clockTickH1;
  }

  new_analog_loopback_q4_M->Timing.t[1] =
    new_analog_loopback_q4_M->Timing.clockTick1 *
    new_analog_loopback_q4_M->Timing.stepSize1 +
    new_analog_loopback_q4_M->Timing.clockTickH1 *
    new_analog_loopback_q4_M->Timing.stepSize1 * 4294967296.0;
}

/* Model output function for TID2 */
static void new_analog_loopback_q4_output2(void) /* Sample time: [0.001s, 0.0s] */
{
  /* Level2 S-Function Block: '<Root>/Q4 Enc ' (encquanserq8) */
  {
    SimStruct *rts = new_analog_loopback_q4_M->childSfunctions[1];
    sfcnOutputs(rts, 2);
  }

  /* Outport: '<Root>/Out3' */
  new_analog_loopback_q4_Y.Out3 = new_analog_loopback_q4_B.Q4Enc;

  /* ok to acquire for <S5>/S-Function */
  new_analog_loopback_q4_DW.SFunction_IWORK_i.AcquireOK = 1;
}

/* Model update function for TID2 */
static void new_analog_loopback_q4_update2(void) /* Sample time: [0.001s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++new_analog_loopback_q4_M->Timing.clockTick2)) {
    ++new_analog_loopback_q4_M->Timing.clockTickH2;
  }

  new_analog_loopback_q4_M->Timing.t[2] =
    new_analog_loopback_q4_M->Timing.clockTick2 *
    new_analog_loopback_q4_M->Timing.stepSize2 +
    new_analog_loopback_q4_M->Timing.clockTickH2 *
    new_analog_loopback_q4_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
static void new_analog_loopback_q4_output(int_T tid)
{
  switch (tid) {
   case 0 :
    new_analog_loopback_q4_output0();
    break;

   case 2 :
    new_analog_loopback_q4_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
static void new_analog_loopback_q4_update(int_T tid)
{
  switch (tid) {
   case 0 :
    new_analog_loopback_q4_update0();
    break;

   case 2 :
    new_analog_loopback_q4_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
static void new_analog_loopback_q4_initialize(void)
{
  /* Level2 S-Function Block: '<Root>/Q4 AD2' (adquanserq8) */
  {
    SimStruct *rts = new_analog_loopback_q4_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* S-Function Block: <S1>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(1)) == 0) {
      if ((i = rl32eDefScope(1,1)) != 0) {
        printf("Error creating scope 1\n");
      } else {
        rl32eAddSignal(1, rl32eGetSignalNo("Q4 AD2/p1"));
        rl32eSetScope(1, 4, 250);
        rl32eSetScope(1, 5, 0);
        rl32eSetScope(1, 6, 1);
        rl32eSetScope(1, 0, 1);
        rl32eSetScope(1, 3, rl32eGetSignalNo("Q4 AD2/p1"));
        rl32eSetScope(1, 1, 0.0);
        rl32eSetScope(1, 2, 0);
        rl32eSetScope(1, 9, 0);
        xpceScopeAcqOK(1, &new_analog_loopback_q4_DW.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* S-Function Block: <S2>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(2)) == 0) {
      if ((i = rl32eDefScope(2,2)) != 0) {
        printf("Error creating scope 2\n");
      } else {
        rl32eAddSignal(2, rl32eGetSignalNo("Q4 AD2/p1"));
        rl32eSetScope(2, 4, 250);
        rl32eSetScope(2, 5, 0);
        rl32eSetScope(2, 6, 1);
        rl32eSetScope(2, 0, 0);
        rl32eSetScope(2, 3, rl32eGetSignalNo("Q4 AD2/p1"));
        rl32eSetScope(2, 1, 0.0);
        rl32eSetScope(2, 2, 0);
        rl32eSetScope(2, 9, 0);
        rl32eSetTargetScope(2, 1, 3.0);
        rl32eSetTargetScope(2, 11, -1.0);
        rl32eSetTargetScope(2, 10, 1.0);
        xpceScopeAcqOK(2, &new_analog_loopback_q4_DW.SFunction_IWORK_d.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* S-Function Block: <S3>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(3)) == 0) {
      if ((i = rl32eDefScope(3,2)) != 0) {
        printf("Error creating scope 3\n");
      } else {
        rl32eAddSignal(3, rl32eGetSignalNo("Q4 AD2/p2"));
        rl32eSetScope(3, 4, 250);
        rl32eSetScope(3, 5, 0);
        rl32eSetScope(3, 6, 1);
        rl32eSetScope(3, 0, 0);
        rl32eSetScope(3, 3, rl32eGetSignalNo("Q4 AD2/p2"));
        rl32eSetScope(3, 1, 0.0);
        rl32eSetScope(3, 2, 0);
        rl32eSetScope(3, 9, 0);
        rl32eSetTargetScope(3, 1, 3.0);
        rl32eSetTargetScope(3, 11, -1.0);
        rl32eSetTargetScope(3, 10, 1.0);
        xpceScopeAcqOK(3, &new_analog_loopback_q4_DW.SFunction_IWORK_g.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(3);
    }
  }

  /* S-Function Block: <S4>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(4)) == 0) {
      if ((i = rl32eDefScope(4,1)) != 0) {
        printf("Error creating scope 4\n");
      } else {
        rl32eAddSignal(4, rl32eGetSignalNo("Q4 AD2/p2"));
        rl32eSetScope(4, 4, 250);
        rl32eSetScope(4, 5, 0);
        rl32eSetScope(4, 6, 1);
        rl32eSetScope(4, 0, 1);
        rl32eSetScope(4, 3, rl32eGetSignalNo("Q4 AD2/p2"));
        rl32eSetScope(4, 1, 0.0);
        rl32eSetScope(4, 2, 0);
        rl32eSetScope(4, 9, 0);
        xpceScopeAcqOK(4, &new_analog_loopback_q4_DW.SFunction_IWORK_k.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(4);
    }
  }

  /* Level2 S-Function Block: '<Root>/Q4 Enc ' (encquanserq8) */
  {
    SimStruct *rts = new_analog_loopback_q4_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* S-Function Block: <S5>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(5)) == 0) {
      if ((i = rl32eDefScope(5,2)) != 0) {
        printf("Error creating scope 5\n");
      } else {
        rl32eAddSignal(5, rl32eGetSignalNo("Q4 Enc "));
        rl32eSetScope(5, 4, 250);
        rl32eSetScope(5, 5, 0);
        rl32eSetScope(5, 6, 1);
        rl32eSetScope(5, 0, 0);
        rl32eSetScope(5, 3, rl32eGetSignalNo("Q4 Enc "));
        rl32eSetScope(5, 1, 0.0);
        rl32eSetScope(5, 2, 0);
        rl32eSetScope(5, 9, 0);
        rl32eSetTargetScope(5, 1, 3.0);
        rl32eSetTargetScope(5, 11, -1.0);
        rl32eSetTargetScope(5, 10, 1.0);
        xpceScopeAcqOK(5, &new_analog_loopback_q4_DW.SFunction_IWORK_i.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(5);
    }
  }

  /* Level2 S-Function Block: '<Root>/Q4 DA ' (daquanserq8) */
  {
    SimStruct *rts = new_analog_loopback_q4_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<Root>/Q4 DO ' (doquanserq8) */
  {
    SimStruct *rts = new_analog_loopback_q4_M->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
static void new_analog_loopback_q4_terminate(void)
{
  /* Level2 S-Function Block: '<Root>/Q4 AD2' (adquanserq8) */
  {
    SimStruct *rts = new_analog_loopback_q4_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<Root>/Q4 Enc ' (encquanserq8) */
  {
    SimStruct *rts = new_analog_loopback_q4_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<Root>/Q4 DA ' (daquanserq8) */
  {
    SimStruct *rts = new_analog_loopback_q4_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<Root>/Q4 DO ' (doquanserq8) */
  {
    SimStruct *rts = new_analog_loopback_q4_M->childSfunctions[3];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  new_analog_loopback_q4_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  new_analog_loopback_q4_update(tid);
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
  new_analog_loopback_q4_initialize();
}

void MdlTerminate(void)
{
  new_analog_loopback_q4_terminate();
}

/* Registration function */
RT_MODEL_new_analog_loopback_q4_T *new_analog_loopback_q4(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)new_analog_loopback_q4_M, 0,
                sizeof(RT_MODEL_new_analog_loopback_q4_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&new_analog_loopback_q4_M->solverInfo,
                          &new_analog_loopback_q4_M->Timing.simTimeStep);
    rtsiSetTPtr(&new_analog_loopback_q4_M->solverInfo, &rtmGetTPtr
                (new_analog_loopback_q4_M));
    rtsiSetStepSizePtr(&new_analog_loopback_q4_M->solverInfo,
                       &new_analog_loopback_q4_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&new_analog_loopback_q4_M->solverInfo,
                          (&rtmGetErrorStatus(new_analog_loopback_q4_M)));
    rtsiSetRTModelPtr(&new_analog_loopback_q4_M->solverInfo,
                      new_analog_loopback_q4_M);
  }

  rtsiSetSimTimeStep(&new_analog_loopback_q4_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&new_analog_loopback_q4_M->solverInfo,"FixedStepDiscrete");
  new_analog_loopback_q4_M->solverInfoPtr =
    (&new_analog_loopback_q4_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = new_analog_loopback_q4_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    new_analog_loopback_q4_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    new_analog_loopback_q4_M->Timing.sampleTimes =
      (&new_analog_loopback_q4_M->Timing.sampleTimesArray[0]);
    new_analog_loopback_q4_M->Timing.offsetTimes =
      (&new_analog_loopback_q4_M->Timing.offsetTimesArray[0]);

    /* task periods */
    new_analog_loopback_q4_M->Timing.sampleTimes[0] = (0.0);
    new_analog_loopback_q4_M->Timing.sampleTimes[1] = (0.0001);
    new_analog_loopback_q4_M->Timing.sampleTimes[2] = (0.001);

    /* task offsets */
    new_analog_loopback_q4_M->Timing.offsetTimes[0] = (0.0);
    new_analog_loopback_q4_M->Timing.offsetTimes[1] = (0.0);
    new_analog_loopback_q4_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(new_analog_loopback_q4_M, &new_analog_loopback_q4_M->Timing.tArray
             [0]);

  {
    int_T *mdlSampleHits = new_analog_loopback_q4_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      new_analog_loopback_q4_M->Timing.perTaskSampleHitsArray;
    new_analog_loopback_q4_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits
      [0]);
    mdlSampleHits[0] = 1;
    new_analog_loopback_q4_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(new_analog_loopback_q4_M, -1);
  new_analog_loopback_q4_M->Timing.stepSize0 = 0.0001;
  new_analog_loopback_q4_M->Timing.stepSize1 = 0.0001;
  new_analog_loopback_q4_M->Timing.stepSize2 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    new_analog_loopback_q4_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(new_analog_loopback_q4_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(new_analog_loopback_q4_M->rtwLogInfo, (NULL));
    rtliSetLogT(new_analog_loopback_q4_M->rtwLogInfo, "tout");
    rtliSetLogX(new_analog_loopback_q4_M->rtwLogInfo, "");
    rtliSetLogXFinal(new_analog_loopback_q4_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(new_analog_loopback_q4_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(new_analog_loopback_q4_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(new_analog_loopback_q4_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(new_analog_loopback_q4_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &new_analog_loopback_q4_Y.Out1,
        &new_analog_loopback_q4_Y.Out2,
        &new_analog_loopback_q4_Y.Out3
      };

      rtliSetLogYSignalPtrs(new_analog_loopback_q4_M->rtwLogInfo,
                            ((LogSignalPtrsType)rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1,
        1,
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL),
        (NULL),
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4,
        4,
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0,
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "",
        "",
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "new_analog_loopback_q4/Out1",
        "new_analog_loopback_q4/Out2",
        "new_analog_loopback_q4/Out3" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          3,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(new_analog_loopback_q4_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
      rt_LoggedCurrentSignalDimensions[2] = &rt_LoggedOutputWidths[2];
    }

    rtliSetLogY(new_analog_loopback_q4_M->rtwLogInfo, "yout");
  }

  new_analog_loopback_q4_M->solverInfoPtr =
    (&new_analog_loopback_q4_M->solverInfo);
  new_analog_loopback_q4_M->Timing.stepSize = (0.0001);
  rtsiSetFixedStepSize(&new_analog_loopback_q4_M->solverInfo, 0.0001);
  rtsiSetSolverMode(&new_analog_loopback_q4_M->solverInfo,
                    SOLVER_MODE_MULTITASKING);

  /* block I/O */
  new_analog_loopback_q4_M->ModelData.blockIO = ((void *)
    &new_analog_loopback_q4_B);
  (void) memset(((void *) &new_analog_loopback_q4_B), 0,
                sizeof(B_new_analog_loopback_q4_T));

  /* parameters */
  new_analog_loopback_q4_M->ModelData.defaultParam = ((real_T *)
    &new_analog_loopback_q4_P);

  /* states (dwork) */
  new_analog_loopback_q4_M->ModelData.dwork = ((void *)
    &new_analog_loopback_q4_DW);
  (void) memset((void *)&new_analog_loopback_q4_DW, 0,
                sizeof(DW_new_analog_loopback_q4_T));

  /* external outputs */
  new_analog_loopback_q4_M->ModelData.outputs = (&new_analog_loopback_q4_Y);
  (void) memset((void *)&new_analog_loopback_q4_Y, 0,
                sizeof(ExtY_new_analog_loopback_q4_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  new_analog_loopback_q4_InitializeDataMapInfo(new_analog_loopback_q4_M);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &new_analog_loopback_q4_M->NonInlinedSFcns.sfcnInfo;
    new_analog_loopback_q4_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(new_analog_loopback_q4_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &new_analog_loopback_q4_M->Sizes.numSampTimes);
    new_analog_loopback_q4_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (new_analog_loopback_q4_M)[0]);
    new_analog_loopback_q4_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (new_analog_loopback_q4_M)[1]);
    new_analog_loopback_q4_M->NonInlinedSFcns.taskTimePtrs[2] = &(rtmGetTPtr
      (new_analog_loopback_q4_M)[2]);
    rtssSetTPtrPtr(sfcnInfo,
                   new_analog_loopback_q4_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(new_analog_loopback_q4_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(new_analog_loopback_q4_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (new_analog_loopback_q4_M));
    rtssSetStepSizePtr(sfcnInfo, &new_analog_loopback_q4_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (new_analog_loopback_q4_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &new_analog_loopback_q4_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &new_analog_loopback_q4_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &new_analog_loopback_q4_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &new_analog_loopback_q4_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &new_analog_loopback_q4_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &new_analog_loopback_q4_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &new_analog_loopback_q4_M->solverInfoPtr);
  }

  new_analog_loopback_q4_M->Sizes.numSFcns = (4);

  /* register each child */
  {
    (void) memset((void *)
                  &new_analog_loopback_q4_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  4*sizeof(SimStruct));
    new_analog_loopback_q4_M->childSfunctions =
      (&new_analog_loopback_q4_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    new_analog_loopback_q4_M->childSfunctions[0] =
      (&new_analog_loopback_q4_M->NonInlinedSFcns.childSFunctions[0]);
    new_analog_loopback_q4_M->childSfunctions[1] =
      (&new_analog_loopback_q4_M->NonInlinedSFcns.childSFunctions[1]);
    new_analog_loopback_q4_M->childSfunctions[2] =
      (&new_analog_loopback_q4_M->NonInlinedSFcns.childSFunctions[2]);
    new_analog_loopback_q4_M->childSfunctions[3] =
      (&new_analog_loopback_q4_M->NonInlinedSFcns.childSFunctions[3]);

    /* Level2 S-Function Block: new_analog_loopback_q4/<Root>/Q4 AD2 (adquanserq8) */
    {
      SimStruct *rts = new_analog_loopback_q4_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        new_analog_loopback_q4_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        new_analog_loopback_q4_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        new_analog_loopback_q4_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &new_analog_loopback_q4_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, new_analog_loopback_q4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &new_analog_loopback_q4_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &new_analog_loopback_q4_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &new_analog_loopback_q4_M->NonInlinedSFcns.statesInfo2
                         [0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &new_analog_loopback_q4_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &new_analog_loopback_q4_B.Q4AD2_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &new_analog_loopback_q4_B.Q4AD2_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "Q4 AD2");
      ssSetPath(rts, "new_analog_loopback_q4/Q4 AD2");
      ssSetRTModel(rts,new_analog_loopback_q4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &new_analog_loopback_q4_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)new_analog_loopback_q4_P.Q4AD2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)new_analog_loopback_q4_P.Q4AD2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)new_analog_loopback_q4_P.Q4AD2_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)new_analog_loopback_q4_P.Q4AD2_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)new_analog_loopback_q4_P.Q4AD2_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)new_analog_loopback_q4_P.Q4AD2_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)new_analog_loopback_q4_P.Q4AD2_P7_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &new_analog_loopback_q4_DW.Q4AD2_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &new_analog_loopback_q4_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &new_analog_loopback_q4_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &new_analog_loopback_q4_DW.Q4AD2_IWORK[0]);
      }

      /* registration */
      adquanserq8(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: new_analog_loopback_q4/<Root>/Q4 Enc  (encquanserq8) */
    {
      SimStruct *rts = new_analog_loopback_q4_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        new_analog_loopback_q4_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        new_analog_loopback_q4_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap =
        new_analog_loopback_q4_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &new_analog_loopback_q4_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, new_analog_loopback_q4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &new_analog_loopback_q4_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &new_analog_loopback_q4_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &new_analog_loopback_q4_M->NonInlinedSFcns.statesInfo2
                         [1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &new_analog_loopback_q4_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &new_analog_loopback_q4_B.Q4Enc));
        }
      }

      /* path info */
      ssSetModelName(rts, "Q4 Enc ");
      ssSetPath(rts, "new_analog_loopback_q4/Q4 Enc ");
      ssSetRTModel(rts,new_analog_loopback_q4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &new_analog_loopback_q4_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 12);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)new_analog_loopback_q4_P.Q4Enc_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)new_analog_loopback_q4_P.Q4Enc_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)new_analog_loopback_q4_P.Q4Enc_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)new_analog_loopback_q4_P.Q4Enc_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)new_analog_loopback_q4_P.Q4Enc_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)new_analog_loopback_q4_P.Q4Enc_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)new_analog_loopback_q4_P.Q4Enc_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)new_analog_loopback_q4_P.Q4Enc_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)new_analog_loopback_q4_P.Q4Enc_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)new_analog_loopback_q4_P.Q4Enc_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       new_analog_loopback_q4_P.Q4Enc_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       new_analog_loopback_q4_P.Q4Enc_P12_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &new_analog_loopback_q4_DW.Q4Enc_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &new_analog_loopback_q4_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &new_analog_loopback_q4_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &new_analog_loopback_q4_DW.Q4Enc_IWORK[0]);
      }

      /* registration */
      encquanserq8(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 2;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: new_analog_loopback_q4/<Root>/Q4 DA  (daquanserq8) */
    {
      SimStruct *rts = new_analog_loopback_q4_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod =
        new_analog_loopback_q4_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset =
        new_analog_loopback_q4_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap =
        new_analog_loopback_q4_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &new_analog_loopback_q4_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, new_analog_loopback_q4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &new_analog_loopback_q4_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &new_analog_loopback_q4_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &new_analog_loopback_q4_M->NonInlinedSFcns.statesInfo2
                         [2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &new_analog_loopback_q4_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &new_analog_loopback_q4_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &new_analog_loopback_q4_B.SineWave;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Q4 DA ");
      ssSetPath(rts, "new_analog_loopback_q4/Q4 DA ");
      ssSetRTModel(rts,new_analog_loopback_q4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &new_analog_loopback_q4_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)new_analog_loopback_q4_P.Q4DA_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)new_analog_loopback_q4_P.Q4DA_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)new_analog_loopback_q4_P.Q4DA_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)new_analog_loopback_q4_P.Q4DA_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)new_analog_loopback_q4_P.Q4DA_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)new_analog_loopback_q4_P.Q4DA_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)new_analog_loopback_q4_P.Q4DA_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)new_analog_loopback_q4_P.Q4DA_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)new_analog_loopback_q4_P.Q4DA_P9_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &new_analog_loopback_q4_DW.Q4DA_RWORK[0]);
      ssSetIWork(rts, (int_T *) &new_analog_loopback_q4_DW.Q4DA_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &new_analog_loopback_q4_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &new_analog_loopback_q4_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 16);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &new_analog_loopback_q4_DW.Q4DA_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &new_analog_loopback_q4_DW.Q4DA_IWORK);
      }

      /* registration */
      daquanserq8(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: new_analog_loopback_q4/<Root>/Q4 DO  (doquanserq8) */
    {
      SimStruct *rts = new_analog_loopback_q4_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod =
        new_analog_loopback_q4_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset =
        new_analog_loopback_q4_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap =
        new_analog_loopback_q4_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &new_analog_loopback_q4_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, new_analog_loopback_q4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &new_analog_loopback_q4_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &new_analog_loopback_q4_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &new_analog_loopback_q4_M->NonInlinedSFcns.statesInfo2
                         [3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &new_analog_loopback_q4_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &new_analog_loopback_q4_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &new_analog_loopback_q4_B.SignalGenerator;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Q4 DO ");
      ssSetPath(rts, "new_analog_loopback_q4/Q4 DO ");
      ssSetRTModel(rts,new_analog_loopback_q4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &new_analog_loopback_q4_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)new_analog_loopback_q4_P.Q4DO_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)new_analog_loopback_q4_P.Q4DO_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)new_analog_loopback_q4_P.Q4DO_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)new_analog_loopback_q4_P.Q4DO_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)new_analog_loopback_q4_P.Q4DO_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)new_analog_loopback_q4_P.Q4DO_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)new_analog_loopback_q4_P.Q4DO_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)new_analog_loopback_q4_P.Q4DO_P8_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &new_analog_loopback_q4_DW.Q4DO_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &new_analog_loopback_q4_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &new_analog_loopback_q4_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &new_analog_loopback_q4_DW.Q4DO_IWORK);
      }

      /* registration */
      doquanserq8(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Initialize Sizes */
  new_analog_loopback_q4_M->Sizes.numContStates = (0);/* Number of continuous states */
  new_analog_loopback_q4_M->Sizes.numY = (3);/* Number of model outputs */
  new_analog_loopback_q4_M->Sizes.numU = (0);/* Number of model inputs */
  new_analog_loopback_q4_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  new_analog_loopback_q4_M->Sizes.numSampTimes = (3);/* Number of sample times */
  new_analog_loopback_q4_M->Sizes.numBlocks = (15);/* Number of blocks */
  new_analog_loopback_q4_M->Sizes.numBlockIO = (5);/* Number of block outputs */
  new_analog_loopback_q4_M->Sizes.numBlockPrms = (115);/* Sum of parameter "widths" */
  return new_analog_loopback_q4_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
