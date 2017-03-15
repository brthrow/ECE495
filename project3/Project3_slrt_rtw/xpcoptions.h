#ifndef __Project3_XPCOPTIONS_H___
#define __Project3_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "Project3.h"
#define XPCMDSSUPPORT                  0
#define MDSTASKSNUM                    0
#define FULLMULTITHREAD                0
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(P_Project3_T))
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
void Project3_ChangeStepSize(real_T newBaseRateStepSize, RT_MODEL_Project3_T *
  const Project3_M)
{
  real_T ratio = newBaseRateStepSize / 0.001;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  Project3_M->Timing.stepSize0 = Project3_M->Timing.stepSize0 * ratio;
  Project3_M->Timing.stepSize1 = Project3_M->Timing.stepSize1 * ratio;
  Project3_M->Timing.stepSize = Project3_M->Timing.stepSize * ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  Project3_ChangeStepSize(stepSize, Project3_M);
}

#endif                                 /* __Project3_XPCOPTIONS_H___ */
