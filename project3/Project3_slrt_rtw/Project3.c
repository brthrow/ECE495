/*
 * Project3.c
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

#include "rt_logging_mmi.h"
#include "Project3_capi.h"
#include "Project3.h"
#include "Project3_private.h"

/* Block signals (auto storage) */
B_Project3_T Project3_B;

/* Continuous states */
X_Project3_T Project3_X;

/* Block states (auto storage) */
DW_Project3_T Project3_DW;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Project3_T Project3_Y;

/* Real-time model */
RT_MODEL_Project3_T Project3_M_;
RT_MODEL_Project3_T *const Project3_M = &Project3_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Project3_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Project3_output();
  Project3_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Project3_output();
  Project3_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void Project3_output(void)
{
  real_T *lastU;
  real_T lastTime;
  real_T u1;
  real_T u2;
  if (rtmIsMajorTimeStep(Project3_M)) {
    /* set solver stop time */
    if (!(Project3_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Project3_M->solverInfo,
                            ((Project3_M->Timing.clockTickH0 + 1) *
        Project3_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Project3_M->solverInfo,
                            ((Project3_M->Timing.clockTick0 + 1) *
        Project3_M->Timing.stepSize0 + Project3_M->Timing.clockTickH0 *
        Project3_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Project3_M)) {
    Project3_M->Timing.t[0] = rtsiGetT(&Project3_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Project3_M)) {
    /* Gain: '<S1>/gain' incorporates:
     *  Constant: '<Root>/Constant'
     */
    Project3_B.Setpoint = Project3_P.gain_Gain * Project3_P.Constant_Value;

    /* Outport: '<Root>/setpoint_Out' */
    Project3_Y.setpoint_Out = Project3_B.Setpoint;
  }

  /* Integrator: '<S4>/Integrator6' */
  Project3_B.Integrator6 = Project3_X.Integrator6_CSTATE;

  /* Product: '<S9>/Product2' incorporates:
   *  Constant: '<S1>/1 - Use simulated motor 0 - Use real motor'
   */
  Project3_B.Product2 = Project3_B.Integrator6 *
    Project3_P.Usesimulatedmotor0Userealmotor_;
  if (rtmIsMajorTimeStep(Project3_M)) {
    /* Logic: '<S9>/complement the input1' incorporates:
     *  Constant: '<S1>/1 - Use simulated motor 0 - Use real motor'
     */
    Project3_B.complementtheinput1 =
      !(Project3_P.Usesimulatedmotor0Userealmotor_ != 0.0);

    /* Level2 S-Function Block: '<S3>/Channel 0 of  Encoder Inputs ' (encquanserq8) */
    {
      SimStruct *rts = Project3_M->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S3>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees' */
    Project3_B.angular_positionrelative_countC =
      Project3_P.angular_positionrelative_countC *
      Project3_B.Channel0ofEncoderInputs;

    /* Product: '<S9>/Product3' */
    Project3_B.Product3 = (real_T)Project3_B.complementtheinput1 *
      Project3_B.angular_positionrelative_countC;
  }

  /* Sum: '<S9>/Sum2' */
  Project3_B.Sum2 = Project3_B.Product2 + Project3_B.Product3;

  /* Sum: '<S1>/Sum1' */
  Project3_B.ErrorSignal = Project3_B.Setpoint - Project3_B.Sum2;

  /* Outport: '<Root>/errorSignal_Out' */
  Project3_Y.errorSignal_Out = Project3_B.ErrorSignal;

  /* Outport: '<Root>/motorPos_Out' */
  Project3_Y.motorPos_Out = Project3_B.Sum2;

  /* ok to acquire for <S2>/S-Function */
  Project3_DW.SFunction_IWORK.AcquireOK = 1;

  /* ok to acquire for <S5>/S-Function */
  Project3_DW.SFunction_IWORK_i.AcquireOK = 1;

  /* ok to acquire for <S7>/S-Function */
  Project3_DW.SFunction_IWORK_it.AcquireOK = 1;
  if (rtmIsMajorTimeStep(Project3_M)) {
    /* ok to acquire for <S8>/S-Function */
    Project3_DW.SFunction_IWORK_n.AcquireOK = 1;
  }

  /* Derivative: '<S1>/Derivative1' */
  if ((Project3_DW.TimeStampA >= Project3_M->Timing.t[0]) &&
      (Project3_DW.TimeStampB >= Project3_M->Timing.t[0])) {
    Project3_B.Derivative1 = 0.0;
  } else {
    lastTime = Project3_DW.TimeStampA;
    lastU = &Project3_DW.LastUAtTimeA;
    if (Project3_DW.TimeStampA < Project3_DW.TimeStampB) {
      if (Project3_DW.TimeStampB < Project3_M->Timing.t[0]) {
        lastTime = Project3_DW.TimeStampB;
        lastU = &Project3_DW.LastUAtTimeB;
      }
    } else {
      if (Project3_DW.TimeStampA >= Project3_M->Timing.t[0]) {
        lastTime = Project3_DW.TimeStampB;
        lastU = &Project3_DW.LastUAtTimeB;
      }
    }

    lastTime = Project3_M->Timing.t[0] - lastTime;
    Project3_B.Derivative1 = (Project3_B.ErrorSignal - *lastU) / lastTime;
  }

  /* End of Derivative: '<S1>/Derivative1' */

  /* Gain: '<S1>/Gain' */
  Project3_B.Gain[0] = Project3_P.Gain_Gain * Project3_B.Setpoint;
  Project3_B.Gain[1] = Project3_P.Gain_Gain * Project3_B.Sum2;
  Project3_B.Gain[2] = Project3_P.Gain_Gain * Project3_B.ErrorSignal;

  /* Integrator: '<S1>/Integrator1' */
  Project3_B.Integrator1 = Project3_X.Integrator1_CSTATE;

  /* Gain: '<S1>/Kd' */
  Project3_B.Kd = Project3_P.Kd_Gain * Project3_B.Derivative1;

  /* Gain: '<S1>/Ki' */
  Project3_B.Ki = Project3_P.Ki_Gain * Project3_B.Integrator1;

  /* Gain: '<S1>/Kp' */
  Project3_B.Kp = Project3_P.Kp_Gain * Project3_B.ErrorSignal;
  if (rtmIsMajorTimeStep(Project3_M)) {
    /* Logic: '<S6>/complement the input' incorporates:
     *  Constant: '<S1>/1 - Use simulated motor 0 - Use real motor'
     */
    Project3_B.complementtheinput = !(Project3_P.Usesimulatedmotor0Userealmotor_
      != 0.0);
  }

  /* Sum: '<S1>/Sum4' */
  Project3_B.Sum4 = (Project3_B.Kp + Project3_B.Kd) + Project3_B.Ki;

  /* Product: '<S6>/Product1' */
  Project3_B.Product1 = (real_T)Project3_B.complementtheinput * Project3_B.Sum4;

  /* Saturate: '<S3>/Saturation' */
  lastTime = Project3_B.Product1;
  u1 = Project3_P.Saturation_LowerSat;
  u2 = Project3_P.Saturation_UpperSat;
  if (lastTime > u2) {
    Project3_B.Saturation = u2;
  } else if (lastTime < u1) {
    Project3_B.Saturation = u1;
  } else {
    Project3_B.Saturation = lastTime;
  }

  /* End of Saturate: '<S3>/Saturation' */
  if (rtmIsMajorTimeStep(Project3_M)) {
    /* Level2 S-Function Block: '<S3>/Channel 0 -Control signal to  motor through amplifier ' (daquanserq8) */
    {
      SimStruct *rts = Project3_M->childSfunctions[1];
      sfcnOutputs(rts, 1);
    }
  }

  /* Integrator: '<S4>/Integrator5' */
  Project3_B.Integrator5 = Project3_X.Integrator5_CSTATE;

  /* Gain: '<S4>/Back emf Ke1' */
  Project3_B.BackemfKe1 = Project3_P.BackemfKe1_Gain * Project3_B.Integrator5;

  /* Gain: '<S4>/Damping b1' */
  Project3_B.Dampingb1 = Project3_P.Dampingb1_Gain * Project3_B.Integrator5;

  /* Integrator: '<S4>/Integrator1' */
  Project3_B.Integrator1_h = Project3_X.Integrator1_CSTATE_i;

  /* Gain: '<S4>/Gain Kt2' */
  Project3_B.GainKt2 = Project3_P.GainKt2_Gain * Project3_B.Integrator1_h;

  /* Sum: '<S4>/Sum2' */
  Project3_B.Sum2_e = Project3_B.GainKt2 - Project3_B.Dampingb1;

  /* Gain: '<S4>/Gain Kt3' */
  Project3_B.GainKt3 = Project3_P.GainKt3_Gain * Project3_B.Sum2_e;

  /* Product: '<S6>/Product' incorporates:
   *  Constant: '<S1>/1 - Use simulated motor 0 - Use real motor'
   */
  Project3_B.Product = Project3_B.Sum4 *
    Project3_P.Usesimulatedmotor0Userealmotor_;

  /* Gain: '<S4>/Resistance R1' */
  Project3_B.ResistanceR1 = Project3_P.ResistanceR1_Gain *
    Project3_B.Integrator1_h;

  /* Sum: '<S4>/Sum1' */
  Project3_B.Sum1 = (Project3_B.Product - Project3_B.BackemfKe1) -
    Project3_B.ResistanceR1;

  /* Gain: '<S4>/Inductance' */
  Project3_B.Inductance = Project3_P.Inductance_Gain * Project3_B.Sum1;
}

/* Model update function */
void Project3_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<S1>/Derivative1' */
  if (Project3_DW.TimeStampA == (rtInf)) {
    Project3_DW.TimeStampA = Project3_M->Timing.t[0];
    lastU = &Project3_DW.LastUAtTimeA;
  } else if (Project3_DW.TimeStampB == (rtInf)) {
    Project3_DW.TimeStampB = Project3_M->Timing.t[0];
    lastU = &Project3_DW.LastUAtTimeB;
  } else if (Project3_DW.TimeStampA < Project3_DW.TimeStampB) {
    Project3_DW.TimeStampA = Project3_M->Timing.t[0];
    lastU = &Project3_DW.LastUAtTimeA;
  } else {
    Project3_DW.TimeStampB = Project3_M->Timing.t[0];
    lastU = &Project3_DW.LastUAtTimeB;
  }

  *lastU = Project3_B.ErrorSignal;

  /* End of Update for Derivative: '<S1>/Derivative1' */
  if (rtmIsMajorTimeStep(Project3_M)) {
    rt_ertODEUpdateContinuousStates(&Project3_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Project3_M->Timing.clockTick0)) {
    ++Project3_M->Timing.clockTickH0;
  }

  Project3_M->Timing.t[0] = rtsiGetSolverStopTime(&Project3_M->solverInfo);

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
    if (!(++Project3_M->Timing.clockTick1)) {
      ++Project3_M->Timing.clockTickH1;
    }

    Project3_M->Timing.t[1] = Project3_M->Timing.clockTick1 *
      Project3_M->Timing.stepSize1 + Project3_M->Timing.clockTickH1 *
      Project3_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Project3_derivatives(void)
{
  XDot_Project3_T *_rtXdot;
  _rtXdot = ((XDot_Project3_T *) Project3_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S4>/Integrator6' */
  _rtXdot->Integrator6_CSTATE = Project3_B.Integrator5;

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = Project3_B.ErrorSignal;

  /* Derivatives for Integrator: '<S4>/Integrator5' */
  _rtXdot->Integrator5_CSTATE = Project3_B.GainKt3;

  /* Derivatives for Integrator: '<S4>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_i = Project3_B.Inductance;
}

/* Model initialize function */
void Project3_initialize(void)
{
  /* Level2 S-Function Block: '<S3>/Channel 0 of  Encoder Inputs ' (encquanserq8) */
  {
    SimStruct *rts = Project3_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* S-Function Block: <S2>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(3)) == 0) {
      if ((i = rl32eDefScope(3,2)) != 0) {
        printf("Error creating scope 3\n");
      } else {
        rl32eAddSignal(3, rl32eGetSignalNo("Subsystem/Gain/s1"));
        rl32eAddSignal(3, rl32eGetSignalNo("Subsystem/Gain/s2"));
        rl32eAddSignal(3, rl32eGetSignalNo("Subsystem/Gain/s3"));
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Subsystem/Gain/s1"),
          "Setpoint        %3.2f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Subsystem/Gain/s2"),
          "Motor Position  %3.2f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Subsystem/Gain/s3"),
          "Error Signal    %3.2f");
        rl32eSetScope(3, 4, 200);
        rl32eSetScope(3, 5, 0);
        rl32eSetScope(3, 6, 10);
        rl32eSetScope(3, 0, 0);
        rl32eSetScope(3, 3, rl32eGetSignalNo("Subsystem/Gain/s1"));
        rl32eSetScope(3, 1, 0.0);
        rl32eSetScope(3, 2, 0);
        rl32eSetScope(3, 9, 0);
        rl32eSetTargetScope(3, 1, 0.0);
        rl32eSetTargetScope(3, 11, 0.0);
        rl32eSetTargetScope(3, 10, 170.0);
        xpceScopeAcqOK(3, &Project3_DW.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(3);
    }
  }

  /* S-Function Block: <S5>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(2)) == 0) {
      if ((i = rl32eDefScope(2,2)) != 0) {
        printf("Error creating scope 2\n");
      } else {
        rl32eAddSignal(2, rl32eGetSignalNo("Subsystem/Sum1"));
        rl32eSetScope(2, 4, 500);
        rl32eSetScope(2, 5, 0);
        rl32eSetScope(2, 6, 10);
        rl32eSetScope(2, 0, 0);
        rl32eSetScope(2, 3, rl32eGetSignalNo("Subsystem/Sum1"));
        rl32eSetScope(2, 1, 0.0);
        rl32eSetScope(2, 2, 0);
        rl32eSetScope(2, 9, 0);
        rl32eSetTargetScope(2, 1, 3.0);
        rl32eSetTargetScope(2, 11, -180.0);
        rl32eSetTargetScope(2, 10, 180.0);
        xpceScopeAcqOK(2, &Project3_DW.SFunction_IWORK_i.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* S-Function Block: <S7>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(7)) == 0) {
      if ((i = rl32eDefScope(7,2)) != 0) {
        printf("Error creating scope 7\n");
      } else {
        rl32eAddSignal(7, rl32eGetSignalNo("Subsystem/switching logic/Sum2"));
        rl32eSetScope(7, 4, 500);
        rl32eSetScope(7, 5, 0);
        rl32eSetScope(7, 6, 10);
        rl32eSetScope(7, 0, 0);
        rl32eSetScope(7, 3, rl32eGetSignalNo("Subsystem/switching logic/Sum2"));
        rl32eSetScope(7, 1, 0.0);
        rl32eSetScope(7, 2, 0);
        rl32eSetScope(7, 9, 0);
        rl32eSetTargetScope(7, 1, 3.0);
        rl32eSetTargetScope(7, 11, -180.0);
        rl32eSetTargetScope(7, 10, 180.0);
        xpceScopeAcqOK(7, &Project3_DW.SFunction_IWORK_it.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(7);
    }
  }

  /* S-Function Block: <S8>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(1)) == 0) {
      if ((i = rl32eDefScope(1,2)) != 0) {
        printf("Error creating scope 1\n");
      } else {
        rl32eAddSignal(1, rl32eGetSignalNo("Subsystem/gain"));
        rl32eSetScope(1, 4, 500);
        rl32eSetScope(1, 5, 0);
        rl32eSetScope(1, 6, 10);
        rl32eSetScope(1, 0, 0);
        rl32eSetScope(1, 3, rl32eGetSignalNo("Subsystem/gain"));
        rl32eSetScope(1, 1, 0.0);
        rl32eSetScope(1, 2, 0);
        rl32eSetScope(1, 9, 0);
        rl32eSetTargetScope(1, 1, 3.0);
        rl32eSetTargetScope(1, 11, -180.0);
        rl32eSetTargetScope(1, 10, 180.0);
        xpceScopeAcqOK(1, &Project3_DW.SFunction_IWORK_n.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* Level2 S-Function Block: '<S3>/Channel 0 -Control signal to  motor through amplifier ' (daquanserq8) */
  {
    SimStruct *rts = Project3_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for Integrator: '<S4>/Integrator6' */
  Project3_X.Integrator6_CSTATE = Project3_P.Integrator6_IC;

  /* InitializeConditions for Derivative: '<S1>/Derivative1' */
  Project3_DW.TimeStampA = (rtInf);
  Project3_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Integrator: '<S1>/Integrator1' */
  Project3_X.Integrator1_CSTATE = Project3_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S4>/Integrator5' */
  Project3_X.Integrator5_CSTATE = Project3_P.Integrator5_IC;

  /* InitializeConditions for Integrator: '<S4>/Integrator1' */
  Project3_X.Integrator1_CSTATE_i = Project3_P.Integrator1_IC_j;
}

/* Model terminate function */
void Project3_terminate(void)
{
  /* Level2 S-Function Block: '<S3>/Channel 0 of  Encoder Inputs ' (encquanserq8) */
  {
    SimStruct *rts = Project3_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/Channel 0 -Control signal to  motor through amplifier ' (daquanserq8) */
  {
    SimStruct *rts = Project3_M->childSfunctions[1];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  Project3_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Project3_update();
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
  Project3_initialize();
}

void MdlTerminate(void)
{
  Project3_terminate();
}

/* Registration function */
RT_MODEL_Project3_T *Project3(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Project3_M, 0,
                sizeof(RT_MODEL_Project3_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Project3_M->solverInfo,
                          &Project3_M->Timing.simTimeStep);
    rtsiSetTPtr(&Project3_M->solverInfo, &rtmGetTPtr(Project3_M));
    rtsiSetStepSizePtr(&Project3_M->solverInfo, &Project3_M->Timing.stepSize0);
    rtsiSetdXPtr(&Project3_M->solverInfo, &Project3_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Project3_M->solverInfo, (real_T **)
                         &Project3_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Project3_M->solverInfo,
      &Project3_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&Project3_M->solverInfo, (&rtmGetErrorStatus
      (Project3_M)));
    rtsiSetRTModelPtr(&Project3_M->solverInfo, Project3_M);
  }

  rtsiSetSimTimeStep(&Project3_M->solverInfo, MAJOR_TIME_STEP);
  Project3_M->ModelData.intgData.y = Project3_M->ModelData.odeY;
  Project3_M->ModelData.intgData.f[0] = Project3_M->ModelData.odeF[0];
  Project3_M->ModelData.intgData.f[1] = Project3_M->ModelData.odeF[1];
  Project3_M->ModelData.intgData.f[2] = Project3_M->ModelData.odeF[2];
  Project3_M->ModelData.contStates = ((real_T *) &Project3_X);
  rtsiSetSolverData(&Project3_M->solverInfo, (void *)
                    &Project3_M->ModelData.intgData);
  rtsiSetSolverName(&Project3_M->solverInfo,"ode3");
  Project3_M->solverInfoPtr = (&Project3_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Project3_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Project3_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Project3_M->Timing.sampleTimes = (&Project3_M->Timing.sampleTimesArray[0]);
    Project3_M->Timing.offsetTimes = (&Project3_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Project3_M->Timing.sampleTimes[0] = (0.0);
    Project3_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    Project3_M->Timing.offsetTimes[0] = (0.0);
    Project3_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Project3_M, &Project3_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Project3_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Project3_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Project3_M, -1);
  Project3_M->Timing.stepSize0 = 0.001;
  Project3_M->Timing.stepSize1 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    Project3_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Project3_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Project3_M->rtwLogInfo, (NULL));
    rtliSetLogT(Project3_M->rtwLogInfo, "tout");
    rtliSetLogX(Project3_M->rtwLogInfo, "");
    rtliSetLogXFinal(Project3_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Project3_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Project3_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(Project3_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(Project3_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &Project3_Y.setpoint_Out,
        &Project3_Y.errorSignal_Out,
        &Project3_Y.motorPos_Out
      };

      rtliSetLogYSignalPtrs(Project3_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
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
        "Project3/setpoint_Out",
        "Project3/errorSignal_Out",
        "Project3/motorPos_Out" };

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

      rtliSetLogYSignalInfo(Project3_M->rtwLogInfo, rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
      rt_LoggedCurrentSignalDimensions[2] = &rt_LoggedOutputWidths[2];
    }

    rtliSetLogY(Project3_M->rtwLogInfo, "yout");
  }

  Project3_M->solverInfoPtr = (&Project3_M->solverInfo);
  Project3_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Project3_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Project3_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Project3_M->ModelData.blockIO = ((void *) &Project3_B);
  (void) memset(((void *) &Project3_B), 0,
                sizeof(B_Project3_T));

  /* parameters */
  Project3_M->ModelData.defaultParam = ((real_T *)&Project3_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Project3_X;
    Project3_M->ModelData.contStates = (x);
    (void) memset((void *)&Project3_X, 0,
                  sizeof(X_Project3_T));
  }

  /* states (dwork) */
  Project3_M->ModelData.dwork = ((void *) &Project3_DW);
  (void) memset((void *)&Project3_DW, 0,
                sizeof(DW_Project3_T));

  /* external outputs */
  Project3_M->ModelData.outputs = (&Project3_Y);
  (void) memset((void *)&Project3_Y, 0,
                sizeof(ExtY_Project3_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  Project3_InitializeDataMapInfo(Project3_M);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &Project3_M->NonInlinedSFcns.sfcnInfo;
    Project3_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(Project3_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &Project3_M->Sizes.numSampTimes);
    Project3_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(Project3_M)[0]);
    Project3_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(Project3_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,Project3_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(Project3_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(Project3_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(Project3_M));
    rtssSetStepSizePtr(sfcnInfo, &Project3_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(Project3_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &Project3_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &Project3_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &Project3_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &Project3_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &Project3_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &Project3_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &Project3_M->solverInfoPtr);
  }

  Project3_M->Sizes.numSFcns = (2);

  /* register each child */
  {
    (void) memset((void *)&Project3_M->NonInlinedSFcns.childSFunctions[0], 0,
                  2*sizeof(SimStruct));
    Project3_M->childSfunctions =
      (&Project3_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    Project3_M->childSfunctions[0] =
      (&Project3_M->NonInlinedSFcns.childSFunctions[0]);
    Project3_M->childSfunctions[1] =
      (&Project3_M->NonInlinedSFcns.childSFunctions[1]);

    /* Level2 S-Function Block: Project3/<S3>/Channel 0 of  Encoder Inputs  (encquanserq8) */
    {
      SimStruct *rts = Project3_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = Project3_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = Project3_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = Project3_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Project3_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, Project3_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Project3_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Project3_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Project3_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Project3_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Project3_B.Channel0ofEncoderInputs));
        }
      }

      /* path info */
      ssSetModelName(rts, "Channel 0 of \nEncoder Inputs ");
      ssSetPath(rts,
                "Project3/Subsystem/Real motor/Channel 0 of  Encoder Inputs ");
      ssSetRTModel(rts,Project3_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Project3_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 12);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Project3_P.Channel0ofEncoderInputs_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Project3_P.Channel0ofEncoderInputs_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Project3_P.Channel0ofEncoderInputs_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Project3_P.Channel0ofEncoderInputs_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Project3_P.Channel0ofEncoderInputs_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Project3_P.Channel0ofEncoderInputs_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       Project3_P.Channel0ofEncoderInputs_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       Project3_P.Channel0ofEncoderInputs_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       Project3_P.Channel0ofEncoderInputs_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       Project3_P.Channel0ofEncoderInputs_P10_Siz);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       Project3_P.Channel0ofEncoderInputs_P11_Siz);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       Project3_P.Channel0ofEncoderInputs_P12_Siz);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &Project3_DW.Channel0ofEncoderInputs_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Project3_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Project3_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Project3_DW.Channel0ofEncoderInputs_IWORK[0]);
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

    /* Level2 S-Function Block: Project3/<S3>/Channel 0 -Control signal to  motor through amplifier  (daquanserq8) */
    {
      SimStruct *rts = Project3_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = Project3_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = Project3_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = Project3_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Project3_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, Project3_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Project3_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Project3_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Project3_M->NonInlinedSFcns.statesInfo2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Project3_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Project3_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &Project3_B.Saturation;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts,
                     "Channel 0 -Control signal to \nmotor through amplifier ");
      ssSetPath(rts,
                "Project3/Subsystem/Real motor/Channel 0 -Control signal to  motor through amplifier ");
      ssSetRTModel(rts,Project3_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Project3_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Project3_P.Channel0Controlsignaltomotorthr);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Project3_P.Channel0Controlsignaltomotort_h);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Project3_P.Channel0Controlsignaltomotort_e);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Project3_P.Channel0Controlsignaltomotor_e1);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Project3_P.Channel0Controlsignaltomotor_cz);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Project3_P.Channel0Controlsignaltomotort_l);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       Project3_P.Channel0Controlsignaltomotort_b);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       Project3_P.Channel0Controlsignaltomotort_a);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       Project3_P.Channel0Controlsignaltomotor_lv);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &Project3_DW.Channel0Controlsignaltomotorthr[0]);
      ssSetIWork(rts, (int_T *) &Project3_DW.Channel0Controlsignaltomotort_l);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Project3_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Project3_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 16);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Project3_DW.Channel0Controlsignaltomotorthr[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &Project3_DW.Channel0Controlsignaltomotort_l);
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
  }

  /* Initialize Sizes */
  Project3_M->Sizes.numContStates = (4);/* Number of continuous states */
  Project3_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  Project3_M->Sizes.numY = (3);        /* Number of model outputs */
  Project3_M->Sizes.numU = (0);        /* Number of model inputs */
  Project3_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Project3_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Project3_M->Sizes.numBlocks = (40);  /* Number of blocks */
  Project3_M->Sizes.numBlockIO = (30); /* Number of block outputs */
  Project3_M->Sizes.numBlockPrms = (83);/* Sum of parameter "widths" */
  return Project3_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
