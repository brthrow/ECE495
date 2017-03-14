/*
 * dc_motor_encoder_hardware_simulated_data.c
 *
 * Code generation for model "dc_motor_encoder_hardware_simulated".
 *
 * Model version              : 1.83
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Mar 13 15:47:55 2017
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "dc_motor_encoder_hardware_simulated.h"
#include "dc_motor_encoder_hardware_simulated_private.h"

/* Block parameters (auto storage) */
P_dc_motor_encoder_hardware_simulated_T dc_motor_encoder_hardware_simulated_P =
  {
  90.0,                                /* Expression: 90
                                        * Referenced by: '<Root>/Desired position  in degrees'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Integrator6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/1 - Use simulated motor 0 - Use real motor'
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P1_Size
   * Referenced by: '<S2>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: boardtype
                                        * Referenced by: '<S2>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P2_Size
   * Referenced by: '<S2>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: channel
                                        * Referenced by: '<S2>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P3_Size
   * Referenced by: '<S2>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initialCount
                                        * Referenced by: '<S2>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P4_Size
   * Referenced by: '<S2>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: prescale
                                        * Referenced by: '<S2>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P5_Size
   * Referenced by: '<S2>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  4.0,                                 /* Expression: quadrature
                                        * Referenced by: '<S2>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P6_Size
   * Referenced by: '<S2>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: mode
                                        * Referenced by: '<S2>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P7_Size
   * Referenced by: '<S2>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: synchronousIndex
                                        * Referenced by: '<S2>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P8_Size
   * Referenced by: '<S2>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: indexPolarity
                                        * Referenced by: '<S2>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P9_Size
   * Referenced by: '<S2>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: preserveCounts
                                        * Referenced by: '<S2>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P10_Siz
   * Referenced by: '<S2>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampleTime
                                        * Referenced by: '<S2>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P11_Siz
   * Referenced by: '<S2>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: pciBus
                                        * Referenced by: '<S2>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P12_Siz
   * Referenced by: '<S2>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S2>/Channel 0 of  Encoder Inputs '
                                        */
  -0.225,                              /* Expression: -360/1600
                                        * Referenced by: '<S2>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  0.011,                               /* Expression: .011
                                        * Referenced by: '<Root>/Kd'
                                        */
  0.026,                               /* Expression: .026
                                        * Referenced by: '<Root>/Ki'
                                        */
  0.5,                                 /* Expression: .5
                                        * Referenced by: '<Root>/Kp'
                                        */
  4.0,                                 /* Expression: 4
                                        * Referenced by: '<S2>/Saturation'
                                        */
  -4.0,                                /* Expression: -4
                                        * Referenced by: '<S2>/Saturation'
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotorthr
   * Referenced by: '<S2>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: boardtype
                                        * Referenced by: '<S2>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotort_h
   * Referenced by: '<S2>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: channel
                                        * Referenced by: '<S2>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotort_e
   * Referenced by: '<S2>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  -10.0,                               /* Expression: range
                                        * Referenced by: '<S2>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotor_e1
   * Referenced by: '<S2>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: simul
                                        * Referenced by: '<S2>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotor_cz
   * Referenced by: '<S2>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: reset
                                        * Referenced by: '<S2>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotort_l
   * Referenced by: '<S2>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initValue
                                        * Referenced by: '<S2>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotort_b
   * Referenced by: '<S2>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampleTime
                                        * Referenced by: '<S2>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotort_a
   * Referenced by: '<S2>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: pciBus
                                        * Referenced by: '<S2>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotor_lv
   * Referenced by: '<S2>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S2>/Channel 0 -Control signal to  motor through amplifier '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Integrator5'
                                        */
  0.0274,                              /* Expression: 0.0274
                                        * Referenced by: '<S3>/Back emf Ke1'
                                        */
  3.5077E-6,                           /* Expression: 3.5077E-6
                                        * Referenced by: '<S3>/Damping b1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Integrator1'
                                        */
  0.0274,                              /* Expression: 0.0274
                                        * Referenced by: '<S3>/Gain Kt2'
                                        */
  309750.96022797673,                  /* Expression: 1/(3.2284E-6)
                                        * Referenced by: '<S3>/Gain Kt3'
                                        */
  4.0,                                 /* Expression: 4
                                        * Referenced by: '<S3>/Resistance R1'
                                        */
  100.0                                /* Expression: 1/(1E-2)
                                        * Referenced by: '<S3>/Inductance'
                                        */
};
