#ifndef __new_analog_loopback_q4_XPCOPTIONS_H___
#define __new_analog_loopback_q4_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "new_analog_loopback_q4.h"
#define XPCMDSSUPPORT                  0
#define MDSTASKSNUM                    0
#define FULLMULTITHREAD                0
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(P_new_analog_loopback_q4_T))
#define SIMMODE                        0
#define LOGTET                         1
#define LOGBUFSIZE                     100000
#define PROFILINGFLAG                  0
#define EVENTNUMBER                    5000
#define IRQ_NO                         0
#define IO_IRQ                         0
#define WWW_ACCESS_LEVEL               0
#define CPUCLOCK                       0
#define MAXOVERLOAD                    0
#define MAXOVERLOADLEN                 0
#define XPCMODELSTACKSIZEKB            512
#define XPCSTARTUPFLAG                 1
#define PTLOADPARAMFLAG                0
#define DOUBLEBUFFERING                0

/* Change all stepsize using the newBaseRateStepSize */
void new_analog_loopback_q4_ChangeStepSize(real_T newBaseRateStepSize,
  RT_MODEL_new_analog_loopback_q4_T *const new_analog_loopback_q4_M)
{
  real_T ratio = newBaseRateStepSize / 0.0001;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  new_analog_loopback_q4_M->Timing.stepSize0 =
    new_analog_loopback_q4_M->Timing.stepSize0 * ratio;
  new_analog_loopback_q4_M->Timing.stepSize1 =
    new_analog_loopback_q4_M->Timing.stepSize1 * ratio;
  new_analog_loopback_q4_M->Timing.stepSize2 =
    new_analog_loopback_q4_M->Timing.stepSize2 * ratio;
  new_analog_loopback_q4_M->Timing.stepSize =
    new_analog_loopback_q4_M->Timing.stepSize * ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  new_analog_loopback_q4_ChangeStepSize(stepSize, new_analog_loopback_q4_M);
}

#endif                                 /* __new_analog_loopback_q4_XPCOPTIONS_H___ */
