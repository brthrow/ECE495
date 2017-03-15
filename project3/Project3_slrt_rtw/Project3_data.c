/*
 * Project3_data.c
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

#include "Project3.h"
#include "Project3_private.h"

/* Block parameters (auto storage) */
P_Project3_T Project3_P = {
  -5.1612,                             /* Expression: -5.1612
                                        * Referenced by: '<Root>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Integrator6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/1 - Use simulated motor 0 - Use real motor'
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P1_Size
   * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: boardtype
                                        * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P2_Size
   * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: channel
                                        * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P3_Size
   * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initialCount
                                        * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P4_Size
   * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: prescale
                                        * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P5_Size
   * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  4.0,                                 /* Expression: quadrature
                                        * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P6_Size
   * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: mode
                                        * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P7_Size
   * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: synchronousIndex
                                        * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P8_Size
   * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: indexPolarity
                                        * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P9_Size
   * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: preserveCounts
                                        * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P10_Siz
   * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampleTime
                                        * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P11_Siz
   * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: pciBus
                                        * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P12_Siz
   * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S3>/Channel 0 of  Encoder Inputs '
                                        */
  -0.225,                              /* Expression: -360/1600
                                        * Referenced by: '<S3>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator1'
                                        */
  0.011,                               /* Expression: .011
                                        * Referenced by: '<S1>/Kd'
                                        */
  0.013,                               /* Expression: .026/2
                                        * Referenced by: '<S1>/Ki'
                                        */
  2.5,                                 /* Expression: .5*5
                                        * Referenced by: '<S1>/Kp'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S3>/Saturation'
                                        */
  -10.0,                               /* Expression: -10
                                        * Referenced by: '<S3>/Saturation'
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotorthr
   * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: boardtype
                                        * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotort_h
   * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: channel
                                        * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotort_e
   * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  -10.0,                               /* Expression: range
                                        * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotor_e1
   * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: simul
                                        * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotor_cz
   * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: reset
                                        * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotort_l
   * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initValue
                                        * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotort_b
   * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampleTime
                                        * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotort_a
   * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: pciBus
                                        * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotor_lv
   * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S3>/Channel 0 -Control signal to  motor through amplifier '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Integrator5'
                                        */
  0.0274,                              /* Expression: 0.0274
                                        * Referenced by: '<S4>/Back emf Ke1'
                                        */
  3.5077E-6,                           /* Expression: 3.5077E-6
                                        * Referenced by: '<S4>/Damping b1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Integrator1'
                                        */
  0.0274,                              /* Expression: 0.0274
                                        * Referenced by: '<S4>/Gain Kt2'
                                        */
  309750.96022797673,                  /* Expression: 1/(3.2284E-6)
                                        * Referenced by: '<S4>/Gain Kt3'
                                        */
  4.0,                                 /* Expression: 4
                                        * Referenced by: '<S4>/Resistance R1'
                                        */
  100.0                                /* Expression: 1/(1E-2)
                                        * Referenced by: '<S4>/Inductance'
                                        */
};
