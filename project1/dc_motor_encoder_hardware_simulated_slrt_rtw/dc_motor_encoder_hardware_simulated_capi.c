/*
 * dc_motor_encoder_hardware_simulated_capi.c
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
#include "rtw_capi.h"
#include "dc_motor_encoder_hardware_simulated_private.h"

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, "Derivative1",
    "", 0, 0, 0, 0, 0 },

  { 1, 0, "Gain",
    "", 0, 0, 1, 0, 0 },

  { 2, 0, "Kd",
    "", 0, 0, 0, 0, 0 },

  { 3, 0, "Ki",
    "", 0, 0, 0, 0, 0 },

  { 4, 0, "Kp",
    "", 0, 0, 0, 0, 0 },

  { 5, 0, "gain",
    "Setpoint", 0, 0, 0, 0, 1 },

  { 6, 0, "Integrator1",
    "", 0, 0, 0, 0, 0 },

  { 7, 0, "Sum1",
    "Error Signal", 0, 0, 0, 0, 0 },

  { 8, 0, "Sum4",
    "", 0, 0, 0, 0, 0 },

  { 9, 0,
    "Real motor/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees",
    "", 0, 0, 0, 0, 1 },

  { 10, 0, "Real motor/Saturation",
    "", 0, 0, 0, 0, 0 },

  { 11, 0, "Real motor/Channel 0 of  Encoder Inputs ",
    "", 0, 0, 0, 0, 1 },

  { 12, 0, "Simulated motor/Back emf Ke1",
    "", 0, 0, 0, 0, 0 },

  { 13, 0, "Simulated motor/Damping b1",
    "", 0, 0, 0, 0, 0 },

  { 14, 0, "Simulated motor/Gain Kt2",
    "", 0, 0, 0, 0, 0 },

  { 15, 0, "Simulated motor/Gain Kt3",
    "", 0, 0, 0, 0, 0 },

  { 16, 0, "Simulated motor/Inductance",
    "", 0, 0, 0, 0, 0 },

  { 17, 0, "Simulated motor/Resistance R1",
    "", 0, 0, 0, 0, 0 },

  { 18, 0, "Simulated motor/Integrator1",
    "", 0, 0, 0, 0, 0 },

  { 19, 0, "Simulated motor/Integrator5",
    "", 0, 0, 0, 0, 0 },

  { 20, 0, "Simulated motor/Integrator6",
    "", 0, 0, 0, 0, 0 },

  { 21, 0, "Simulated motor/Sum1",
    "", 0, 0, 0, 0, 0 },

  { 22, 0, "Simulated motor/Sum2",
    "", 0, 0, 0, 0, 0 },

  { 23, 0, "input side switching logic/complement the input",
    "", 0, 1, 0, 0, 1 },

  { 24, 0, "input side switching logic/Product",
    "", 0, 0, 0, 0, 0 },

  { 25, 0, "input side switching logic/Product1",
    "", 0, 0, 0, 0, 0 },

  { 26, 0, "switching logic/complement the input1",
    "", 0, 1, 0, 0, 1 },

  { 27, 0, "switching logic/Product2",
    "", 0, 0, 0, 0, 0 },

  { 28, 0, "switching logic/Product3",
    "", 0, 0, 0, 0, 1 },

  { 29, 0, "switching logic/Sum2",
    "", 0, 0, 0, 0, 0 },

  {
    0, 0, NULL, NULL, 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 30, "1 - Use simulated motor 0 - Use real motor",
    "Value", 0, 0, 0 },

  { 31, "Desired position  in degrees",
    "Value", 0, 0, 0 },

  { 32, "Gain",
    "Gain", 0, 0, 0 },

  { 33, "Kd",
    "Gain", 0, 0, 0 },

  { 34, "Ki",
    "Gain", 0, 0, 0 },

  { 35, "Kp",
    "Gain", 0, 0, 0 },

  { 36, "gain",
    "Gain", 0, 0, 0 },

  { 37, "Integrator1",
    "InitialCondition", 0, 0, 0 },

  { 38,
    "Real motor/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees",
    "Gain", 0, 0, 0 },

  { 39, "Real motor/Saturation",
    "UpperLimit", 0, 0, 0 },

  { 40, "Real motor/Saturation",
    "LowerLimit", 0, 0, 0 },

  { 41, "Real motor/Channel 0 -Control signal to  motor through amplifier ",
    "P1", 0, 0, 0 },

  { 42, "Real motor/Channel 0 -Control signal to  motor through amplifier ",
    "P2", 0, 0, 0 },

  { 43, "Real motor/Channel 0 -Control signal to  motor through amplifier ",
    "P3", 0, 0, 0 },

  { 44, "Real motor/Channel 0 -Control signal to  motor through amplifier ",
    "P4", 0, 0, 0 },

  { 45, "Real motor/Channel 0 -Control signal to  motor through amplifier ",
    "P5", 0, 0, 0 },

  { 46, "Real motor/Channel 0 -Control signal to  motor through amplifier ",
    "P6", 0, 0, 0 },

  { 47, "Real motor/Channel 0 -Control signal to  motor through amplifier ",
    "P7", 0, 0, 0 },

  { 48, "Real motor/Channel 0 -Control signal to  motor through amplifier ",
    "P8", 0, 0, 0 },

  { 49, "Real motor/Channel 0 -Control signal to  motor through amplifier ",
    "P9", 0, 0, 0 },

  { 50, "Real motor/Channel 0 of  Encoder Inputs ",
    "P1", 0, 0, 0 },

  { 51, "Real motor/Channel 0 of  Encoder Inputs ",
    "P2", 0, 0, 0 },

  { 52, "Real motor/Channel 0 of  Encoder Inputs ",
    "P3", 0, 0, 0 },

  { 53, "Real motor/Channel 0 of  Encoder Inputs ",
    "P4", 0, 0, 0 },

  { 54, "Real motor/Channel 0 of  Encoder Inputs ",
    "P5", 0, 0, 0 },

  { 55, "Real motor/Channel 0 of  Encoder Inputs ",
    "P6", 0, 0, 0 },

  { 56, "Real motor/Channel 0 of  Encoder Inputs ",
    "P7", 0, 0, 0 },

  { 57, "Real motor/Channel 0 of  Encoder Inputs ",
    "P8", 0, 0, 0 },

  { 58, "Real motor/Channel 0 of  Encoder Inputs ",
    "P9", 0, 0, 0 },

  { 59, "Real motor/Channel 0 of  Encoder Inputs ",
    "P10", 0, 0, 0 },

  { 60, "Real motor/Channel 0 of  Encoder Inputs ",
    "P11", 0, 0, 0 },

  { 61, "Real motor/Channel 0 of  Encoder Inputs ",
    "P12", 0, 0, 0 },

  { 62, "Simulated motor/Back emf Ke1",
    "Gain", 0, 0, 0 },

  { 63, "Simulated motor/Damping b1",
    "Gain", 0, 0, 0 },

  { 64, "Simulated motor/Gain Kt2",
    "Gain", 0, 0, 0 },

  { 65, "Simulated motor/Gain Kt3",
    "Gain", 0, 0, 0 },

  { 66, "Simulated motor/Inductance",
    "Gain", 0, 0, 0 },

  { 67, "Simulated motor/Resistance R1",
    "Gain", 0, 0, 0 },

  { 68, "Simulated motor/Integrator1",
    "InitialCondition", 0, 0, 0 },

  { 69, "Simulated motor/Integrator5",
    "InitialCondition", 0, 0, 0 },

  { 70, "Simulated motor/Integrator6",
    "InitialCondition", 0, 0, 0 },

  {
    0, NULL, NULL, 0, 0, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 0, NULL, 0, 0, 0 }
};

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &dc_motor_encoder_hardware_simulated_B.Derivative1,/* 0: Signal */
  &dc_motor_encoder_hardware_simulated_B.Gain[0],/* 1: Signal */
  &dc_motor_encoder_hardware_simulated_B.Kd,/* 2: Signal */
  &dc_motor_encoder_hardware_simulated_B.Ki,/* 3: Signal */
  &dc_motor_encoder_hardware_simulated_B.Kp,/* 4: Signal */
  &dc_motor_encoder_hardware_simulated_B.Setpoint,/* 5: Signal */
  &dc_motor_encoder_hardware_simulated_B.Integrator1,/* 6: Signal */
  &dc_motor_encoder_hardware_simulated_B.ErrorSignal,/* 7: Signal */
  &dc_motor_encoder_hardware_simulated_B.Sum4,/* 8: Signal */
  &dc_motor_encoder_hardware_simulated_B.angular_positionrelative_countC,/* 9: Signal */
  &dc_motor_encoder_hardware_simulated_B.Saturation,/* 10: Signal */
  &dc_motor_encoder_hardware_simulated_B.Channel0ofEncoderInputs,/* 11: Signal */
  &dc_motor_encoder_hardware_simulated_B.BackemfKe1,/* 12: Signal */
  &dc_motor_encoder_hardware_simulated_B.Dampingb1,/* 13: Signal */
  &dc_motor_encoder_hardware_simulated_B.GainKt2,/* 14: Signal */
  &dc_motor_encoder_hardware_simulated_B.GainKt3,/* 15: Signal */
  &dc_motor_encoder_hardware_simulated_B.Inductance,/* 16: Signal */
  &dc_motor_encoder_hardware_simulated_B.ResistanceR1,/* 17: Signal */
  &dc_motor_encoder_hardware_simulated_B.Integrator1_h,/* 18: Signal */
  &dc_motor_encoder_hardware_simulated_B.Integrator5,/* 19: Signal */
  &dc_motor_encoder_hardware_simulated_B.Integrator6,/* 20: Signal */
  &dc_motor_encoder_hardware_simulated_B.Sum1,/* 21: Signal */
  &dc_motor_encoder_hardware_simulated_B.Sum2_e,/* 22: Signal */
  &dc_motor_encoder_hardware_simulated_B.complementtheinput,/* 23: Signal */
  &dc_motor_encoder_hardware_simulated_B.Product,/* 24: Signal */
  &dc_motor_encoder_hardware_simulated_B.Product1,/* 25: Signal */
  &dc_motor_encoder_hardware_simulated_B.complementtheinput1,/* 26: Signal */
  &dc_motor_encoder_hardware_simulated_B.Product2,/* 27: Signal */
  &dc_motor_encoder_hardware_simulated_B.Product3,/* 28: Signal */
  &dc_motor_encoder_hardware_simulated_B.Sum2,/* 29: Signal */
  &dc_motor_encoder_hardware_simulated_P.Usesimulatedmotor0Userealmotor_,/* 30: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Desiredpositionindegrees_Value,/* 31: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Gain_Gain,/* 32: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Kd_Gain,/* 33: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Ki_Gain,/* 34: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Kp_Gain,/* 35: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.gain_Gain,/* 36: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Integrator1_IC,/* 37: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.angular_positionrelative_countC,/* 38: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Saturation_UpperSat,/* 39: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Saturation_LowerSat,/* 40: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0Controlsignaltomotort_m,/* 41: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0Controlsignaltomotort_k,/* 42: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0Controlsignaltomotort_c,/* 43: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0Controlsignaltomotort_d,/* 44: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0Controlsignaltomotort_n,/* 45: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0Controlsignaltomotort_g,/* 46: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0Controlsignaltomotort_f,/* 47: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0Controlsignaltomotor_gv,/* 48: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0Controlsignaltomotor_gp,/* 49: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P1,/* 50: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P2,/* 51: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P3,/* 52: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P4,/* 53: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P5,/* 54: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P6,/* 55: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P7,/* 56: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P8,/* 57: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P9,/* 58: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P10,/* 59: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P11,/* 60: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Channel0ofEncoderInputs_P12,/* 61: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.BackemfKe1_Gain,/* 62: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Dampingb1_Gain,/* 63: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.GainKt2_Gain,/* 64: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.GainKt3_Gain,/* 65: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Inductance_Gain,/* 66: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.ResistanceR1_Gain,/* 67: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Integrator1_IC_j,/* 68: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Integrator5_IC,/* 69: Block Parameter */
  &dc_motor_encoder_hardware_simulated_P.Integrator6_IC/* 70: Block Parameter */
};

/* Declare Data Run-Time Dimension Buffer Addresses statically */
static int32_T* rtVarDimsAddrMap[] = {
  (NULL)
};

/* Data Type Map - use dataTypeMapIndex to access this structure */
static const rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 },

  { "unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), SS_BOOLEAN, 0, 0 }
};

/* Structure Element Map - use elemMapIndex to access this structure */
static const rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { NULL, 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static const rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 },

  { rtwCAPI_VECTOR, 2, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  3,                                   /* 2 */
  1                                    /* 3 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.0, 0.001
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { NULL, NULL, rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[0],
    0, 0 },

  { (const void *) &rtcapiStoredFloats[1], (const void *) &rtcapiStoredFloats[0],
    1, 0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { rtBlockSignals, 30 },

  { rtBlockParameters, 41,
    rtModelParameters, 0 },

  { NULL, 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 3955116777U,
    743359880U,
    3136835422U,
    1841411202U },
  NULL
};

/* Cache pointers into DataMapInfo substructure of RTModel */
void dc_motor_encoder_hardware_simulated_InitializeDataMapInfo
  (RT_MODEL_dc_motor_encoder_hardware_simulated_T
   *dc_motor_encoder_hardware_simulated_M
   )
{
  /* Set C-API version */
  rtwCAPI_SetVersion(dc_motor_encoder_hardware_simulated_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(dc_motor_encoder_hardware_simulated_M->DataMapInfo.mmi,
                       &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap
    (dc_motor_encoder_hardware_simulated_M->DataMapInfo.mmi, NULL);

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap
    (dc_motor_encoder_hardware_simulated_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap
    (dc_motor_encoder_hardware_simulated_M->DataMapInfo.mmi, rtVarDimsAddrMap);

  /* Cache C-API rtp Address and size  into the Real-Time Model Data structure */
  dc_motor_encoder_hardware_simulated_M->DataMapInfo.mmi.InstanceMap.rtpAddress =
    rtmGetDefaultParam(dc_motor_encoder_hardware_simulated_M);
  dc_motor_encoder_hardware_simulated_M->DataMapInfo.mmi.staticMap->rtpSize =
    sizeof(P_dc_motor_encoder_hardware_simulated_T);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo
    (dc_motor_encoder_hardware_simulated_M->DataMapInfo.mmi, NULL);

  /* Set Reference to submodels */
  rtwCAPI_SetChildMMIArray
    (dc_motor_encoder_hardware_simulated_M->DataMapInfo.mmi, NULL);
  rtwCAPI_SetChildMMIArrayLen
    (dc_motor_encoder_hardware_simulated_M->DataMapInfo.mmi, 0);
}

/* EOF: dc_motor_encoder_hardware_simulated_capi.c */
