/*
 * new_analog_loopback_q4_data.c
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

#include "new_analog_loopback_q4.h"
#include "new_analog_loopback_q4_private.h"

/* Block parameters (auto storage) */
P_new_analog_loopback_q4_T new_analog_loopback_q4_P = {
  2000.0,                              /* Variable: frequency
                                        * Referenced by: '<Root>/Signal Generator'
                                        */
  12566.0,                             /* Variable: rad
                                        * Referenced by: '<Root>/Sine Wave'
                                        */

  /*  Computed Parameter: Q4AD2_P1_Size
   * Referenced by: '<Root>/Q4 AD2'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: boardtype
                                        * Referenced by: '<Root>/Q4 AD2'
                                        */

  /*  Computed Parameter: Q4AD2_P2_Size
   * Referenced by: '<Root>/Q4 AD2'
   */
  { 1.0, 2.0 },

  /*  Expression: channel
   * Referenced by: '<Root>/Q4 AD2'
   */
  { 1.0, 2.0 },

  /*  Computed Parameter: Q4AD2_P3_Size
   * Referenced by: '<Root>/Q4 AD2'
   */
  { 1.0, 2.0 },

  /*  Expression: index03
   * Referenced by: '<Root>/Q4 AD2'
   */
  { 0.0, 1.0 },

  /*  Computed Parameter: Q4AD2_P4_Size
   * Referenced by: '<Root>/Q4 AD2'
   */
  { 0.0, 0.0 },

  /*  Computed Parameter: Q4AD2_P5_Size
   * Referenced by: '<Root>/Q4 AD2'
   */
  { 1.0, 1.0 },
  0.0001,                              /* Expression: sampleTime
                                        * Referenced by: '<Root>/Q4 AD2'
                                        */

  /*  Computed Parameter: Q4AD2_P6_Size
   * Referenced by: '<Root>/Q4 AD2'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: pciBus
                                        * Referenced by: '<Root>/Q4 AD2'
                                        */

  /*  Computed Parameter: Q4AD2_P7_Size
   * Referenced by: '<Root>/Q4 AD2'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<Root>/Q4 AD2'
                                        */

  /*  Computed Parameter: Q4Enc_P1_Size
   * Referenced by: '<Root>/Q4 Enc '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: boardtype
                                        * Referenced by: '<Root>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P2_Size
   * Referenced by: '<Root>/Q4 Enc '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: channel
                                        * Referenced by: '<Root>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P3_Size
   * Referenced by: '<Root>/Q4 Enc '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initialCount
                                        * Referenced by: '<Root>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P4_Size
   * Referenced by: '<Root>/Q4 Enc '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: prescale
                                        * Referenced by: '<Root>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P5_Size
   * Referenced by: '<Root>/Q4 Enc '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: quadrature
                                        * Referenced by: '<Root>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P6_Size
   * Referenced by: '<Root>/Q4 Enc '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: mode
                                        * Referenced by: '<Root>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P7_Size
   * Referenced by: '<Root>/Q4 Enc '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: synchronousIndex
                                        * Referenced by: '<Root>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P8_Size
   * Referenced by: '<Root>/Q4 Enc '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: indexPolarity
                                        * Referenced by: '<Root>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P9_Size
   * Referenced by: '<Root>/Q4 Enc '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: preserveCounts
                                        * Referenced by: '<Root>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P10_Size
   * Referenced by: '<Root>/Q4 Enc '
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampleTime
                                        * Referenced by: '<Root>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P11_Size
   * Referenced by: '<Root>/Q4 Enc '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: pciBus
                                        * Referenced by: '<Root>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P12_Size
   * Referenced by: '<Root>/Q4 Enc '
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<Root>/Q4 Enc '
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */

  /*  Computed Parameter: Q4DA_P1_Size
   * Referenced by: '<Root>/Q4 DA '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: boardtype
                                        * Referenced by: '<Root>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P2_Size
   * Referenced by: '<Root>/Q4 DA '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: channel
                                        * Referenced by: '<Root>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P3_Size
   * Referenced by: '<Root>/Q4 DA '
   */
  { 1.0, 1.0 },
  -5.0,                                /* Expression: range
                                        * Referenced by: '<Root>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P4_Size
   * Referenced by: '<Root>/Q4 DA '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: simul
                                        * Referenced by: '<Root>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P5_Size
   * Referenced by: '<Root>/Q4 DA '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: reset
                                        * Referenced by: '<Root>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P6_Size
   * Referenced by: '<Root>/Q4 DA '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initValue
                                        * Referenced by: '<Root>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P7_Size
   * Referenced by: '<Root>/Q4 DA '
   */
  { 1.0, 1.0 },
  0.0001,                              /* Expression: sampleTime
                                        * Referenced by: '<Root>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P8_Size
   * Referenced by: '<Root>/Q4 DA '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: pciBus
                                        * Referenced by: '<Root>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P9_Size
   * Referenced by: '<Root>/Q4 DA '
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<Root>/Q4 DA '
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Signal Generator'
                                        */

  /*  Computed Parameter: Q4DO_P1_Size
   * Referenced by: '<Root>/Q4 DO '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: boardtype
                                        * Referenced by: '<Root>/Q4 DO '
                                        */

  /*  Computed Parameter: Q4DO_P2_Size
   * Referenced by: '<Root>/Q4 DO '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: channel
                                        * Referenced by: '<Root>/Q4 DO '
                                        */

  /*  Computed Parameter: Q4DO_P3_Size
   * Referenced by: '<Root>/Q4 DO '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: control
                                        * Referenced by: '<Root>/Q4 DO '
                                        */

  /*  Computed Parameter: Q4DO_P4_Size
   * Referenced by: '<Root>/Q4 DO '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: reset
                                        * Referenced by: '<Root>/Q4 DO '
                                        */

  /*  Computed Parameter: Q4DO_P5_Size
   * Referenced by: '<Root>/Q4 DO '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initValue
                                        * Referenced by: '<Root>/Q4 DO '
                                        */

  /*  Computed Parameter: Q4DO_P6_Size
   * Referenced by: '<Root>/Q4 DO '
   */
  { 1.0, 1.0 },
  0.0001,                              /* Expression: sampleTime
                                        * Referenced by: '<Root>/Q4 DO '
                                        */

  /*  Computed Parameter: Q4DO_P7_Size
   * Referenced by: '<Root>/Q4 DO '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: pciBus
                                        * Referenced by: '<Root>/Q4 DO '
                                        */

  /*  Computed Parameter: Q4DO_P8_Size
   * Referenced by: '<Root>/Q4 DO '
   */
  { 1.0, 1.0 },
  -1.0                                 /* Expression: pciSlot
                                        * Referenced by: '<Root>/Q4 DO '
                                        */
};
