#ifndef __dc_motor_encoder_hardware_simulated_XPCOPTIONS_H___
#define __dc_motor_encoder_hardware_simulated_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "dc_motor_encoder_hardware_simulated.h"
#define XPCMDSSUPPORT                  0
#define MDSTASKSNUM                    0
#define FULLMULTITHREAD                0
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(P_dc_motor_encoder_hardware_simulated_T))
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
void dc_motor_encoder_hardware_simulated_ChangeStepSize(real_T
  newBaseRateStepSize, RT_MODEL_dc_motor_encoder_hardware_simulated_T *const
  dc_motor_encoder_hardware_simulated_M)
{
  real_T ratio = newBaseRateStepSize / 0.001;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  dc_motor_encoder_hardware_simulated_M->Timing.stepSize0 =
    dc_motor_encoder_hardware_simulated_M->Timing.stepSize0 * ratio;
  dc_motor_encoder_hardware_simulated_M->Timing.stepSize1 =
    dc_motor_encoder_hardware_simulated_M->Timing.stepSize1 * ratio;
  dc_motor_encoder_hardware_simulated_M->Timing.stepSize =
    dc_motor_encoder_hardware_simulated_M->Timing.stepSize * ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  dc_motor_encoder_hardware_simulated_ChangeStepSize(stepSize,
    dc_motor_encoder_hardware_simulated_M);
}

#endif                                 /* __dc_motor_encoder_hardware_simulated_XPCOPTIONS_H___ */
