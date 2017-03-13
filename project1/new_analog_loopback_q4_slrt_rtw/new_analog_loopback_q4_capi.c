/*
 * new_analog_loopback_q4_capi.c
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
#include "rtw_capi.h"
#include "new_analog_loopback_q4_private.h"

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, "Q4 AD2/p1",
    "", 0, 0, 0, 0, 0 },

  { 1, 0, "Q4 AD2/p2",
    "", 1, 0, 0, 0, 0 },

  { 2, 0, "Q4 Enc ",
    "", 0, 0, 0, 0, 1 },

  { 3, 0, "Signal Generator",
    "", 0, 0, 0, 0, 2 },

  { 4, 0, "Sine Wave",
    "", 0, 0, 0, 0, 2 },

  {
    0, 0, NULL, NULL, 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 5, "Q4 AD2",
    "P1", 0, 0, 0 },

  { 6, "Q4 AD2",
    "P2", 0, 1, 0 },

  { 7, "Q4 AD2",
    "P3", 0, 1, 0 },

  { 8, "Q4 AD2",
    "P5", 0, 0, 0 },

  { 9, "Q4 AD2",
    "P6", 0, 0, 0 },

  { 10, "Q4 AD2",
    "P7", 0, 0, 0 },

  { 11, "Q4 DA ",
    "P1", 0, 0, 0 },

  { 12, "Q4 DA ",
    "P2", 0, 0, 0 },

  { 13, "Q4 DA ",
    "P3", 0, 0, 0 },

  { 14, "Q4 DA ",
    "P4", 0, 0, 0 },

  { 15, "Q4 DA ",
    "P5", 0, 0, 0 },

  { 16, "Q4 DA ",
    "P6", 0, 0, 0 },

  { 17, "Q4 DA ",
    "P7", 0, 0, 0 },

  { 18, "Q4 DA ",
    "P8", 0, 0, 0 },

  { 19, "Q4 DA ",
    "P9", 0, 0, 0 },

  { 20, "Q4 DO ",
    "P1", 0, 0, 0 },

  { 21, "Q4 DO ",
    "P2", 0, 0, 0 },

  { 22, "Q4 DO ",
    "P3", 0, 0, 0 },

  { 23, "Q4 DO ",
    "P4", 0, 0, 0 },

  { 24, "Q4 DO ",
    "P5", 0, 0, 0 },

  { 25, "Q4 DO ",
    "P6", 0, 0, 0 },

  { 26, "Q4 DO ",
    "P7", 0, 0, 0 },

  { 27, "Q4 DO ",
    "P8", 0, 0, 0 },

  { 28, "Q4 Enc ",
    "P1", 0, 0, 0 },

  { 29, "Q4 Enc ",
    "P2", 0, 0, 0 },

  { 30, "Q4 Enc ",
    "P3", 0, 0, 0 },

  { 31, "Q4 Enc ",
    "P4", 0, 0, 0 },

  { 32, "Q4 Enc ",
    "P5", 0, 0, 0 },

  { 33, "Q4 Enc ",
    "P6", 0, 0, 0 },

  { 34, "Q4 Enc ",
    "P7", 0, 0, 0 },

  { 35, "Q4 Enc ",
    "P8", 0, 0, 0 },

  { 36, "Q4 Enc ",
    "P9", 0, 0, 0 },

  { 37, "Q4 Enc ",
    "P10", 0, 0, 0 },

  { 38, "Q4 Enc ",
    "P11", 0, 0, 0 },

  { 39, "Q4 Enc ",
    "P12", 0, 0, 0 },

  { 40, "Signal Generator",
    "Amplitude", 0, 0, 0 },

  { 41, "Sine Wave",
    "Amplitude", 0, 0, 0 },

  { 42, "Sine Wave",
    "Bias", 0, 0, 0 },

  { 43, "Sine Wave",
    "Phase", 0, 0, 0 },

  {
    0, NULL, NULL, 0, 0, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */

  //----skip

  //-----
  { 44, "frequency", 0, 0, 0 },

  //----skip

  //-----
  { 45, "rad", 0, 0, 0 },

  { 0, NULL, 0, 0, 0 }
};

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &new_analog_loopback_q4_B.Q4AD2_o1,  /* 0: Signal */
  &new_analog_loopback_q4_B.Q4AD2_o2,  /* 1: Signal */
  &new_analog_loopback_q4_B.Q4Enc,     /* 2: Signal */
  &new_analog_loopback_q4_B.SignalGenerator,/* 3: Signal */
  &new_analog_loopback_q4_B.SineWave,  /* 4: Signal */
  &new_analog_loopback_q4_P.Q4AD2_P1,  /* 5: Block Parameter */
  &new_analog_loopback_q4_P.Q4AD2_P2[0],/* 6: Block Parameter */
  &new_analog_loopback_q4_P.Q4AD2_P3[0],/* 7: Block Parameter */
  &new_analog_loopback_q4_P.Q4AD2_P5,  /* 8: Block Parameter */
  &new_analog_loopback_q4_P.Q4AD2_P6,  /* 9: Block Parameter */
  &new_analog_loopback_q4_P.Q4AD2_P7,  /* 10: Block Parameter */
  &new_analog_loopback_q4_P.Q4DA_P1,   /* 11: Block Parameter */
  &new_analog_loopback_q4_P.Q4DA_P2,   /* 12: Block Parameter */
  &new_analog_loopback_q4_P.Q4DA_P3,   /* 13: Block Parameter */
  &new_analog_loopback_q4_P.Q4DA_P4,   /* 14: Block Parameter */
  &new_analog_loopback_q4_P.Q4DA_P5,   /* 15: Block Parameter */
  &new_analog_loopback_q4_P.Q4DA_P6,   /* 16: Block Parameter */
  &new_analog_loopback_q4_P.Q4DA_P7,   /* 17: Block Parameter */
  &new_analog_loopback_q4_P.Q4DA_P8,   /* 18: Block Parameter */
  &new_analog_loopback_q4_P.Q4DA_P9,   /* 19: Block Parameter */
  &new_analog_loopback_q4_P.Q4DO_P1,   /* 20: Block Parameter */
  &new_analog_loopback_q4_P.Q4DO_P2,   /* 21: Block Parameter */
  &new_analog_loopback_q4_P.Q4DO_P3,   /* 22: Block Parameter */
  &new_analog_loopback_q4_P.Q4DO_P4,   /* 23: Block Parameter */
  &new_analog_loopback_q4_P.Q4DO_P5,   /* 24: Block Parameter */
  &new_analog_loopback_q4_P.Q4DO_P6,   /* 25: Block Parameter */
  &new_analog_loopback_q4_P.Q4DO_P7,   /* 26: Block Parameter */
  &new_analog_loopback_q4_P.Q4DO_P8,   /* 27: Block Parameter */
  &new_analog_loopback_q4_P.Q4Enc_P1,  /* 28: Block Parameter */
  &new_analog_loopback_q4_P.Q4Enc_P2,  /* 29: Block Parameter */
  &new_analog_loopback_q4_P.Q4Enc_P3,  /* 30: Block Parameter */
  &new_analog_loopback_q4_P.Q4Enc_P4,  /* 31: Block Parameter */
  &new_analog_loopback_q4_P.Q4Enc_P5,  /* 32: Block Parameter */
  &new_analog_loopback_q4_P.Q4Enc_P6,  /* 33: Block Parameter */
  &new_analog_loopback_q4_P.Q4Enc_P7,  /* 34: Block Parameter */
  &new_analog_loopback_q4_P.Q4Enc_P8,  /* 35: Block Parameter */
  &new_analog_loopback_q4_P.Q4Enc_P9,  /* 36: Block Parameter */
  &new_analog_loopback_q4_P.Q4Enc_P10, /* 37: Block Parameter */
  &new_analog_loopback_q4_P.Q4Enc_P11, /* 38: Block Parameter */
  &new_analog_loopback_q4_P.Q4Enc_P12, /* 39: Block Parameter */
  &new_analog_loopback_q4_P.SignalGenerator_Amplitude,/* 40: Block Parameter */
  &new_analog_loopback_q4_P.SineWave_Amp,/* 41: Block Parameter */
  &new_analog_loopback_q4_P.SineWave_Bias,/* 42: Block Parameter */
  &new_analog_loopback_q4_P.SineWave_Phase,/* 43: Block Parameter */
  &new_analog_loopback_q4_P.frequency, /* 44: Model Parameter */
  &new_analog_loopback_q4_P.rad        /* 45: Model Parameter */
};

/* Declare Data Run-Time Dimension Buffer Addresses statically */
static int32_T* rtVarDimsAddrMap[] = {
  (NULL)
};

/* Data Type Map - use dataTypeMapIndex to access this structure */
static const rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 }
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
  1,                                   /* 2 */
  2                                    /* 3 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.0001, 0.0, 0.001
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { NULL, NULL, rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[1],
    1, 0 },

  { (const void *) &rtcapiStoredFloats[2], (const void *) &rtcapiStoredFloats[1],
    2, 0 },

  { (const void *) &rtcapiStoredFloats[1], (const void *) &rtcapiStoredFloats[1],
    0, 0 }
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
  { rtBlockSignals, 5 },

  { rtBlockParameters, 39,
    rtModelParameters, 2 },

  { NULL, 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 878238066U,
    2076473627U,
    1420747037U,
    2904641680U },
  NULL
};

/* Cache pointers into DataMapInfo substructure of RTModel */
void new_analog_loopback_q4_InitializeDataMapInfo
  (RT_MODEL_new_analog_loopback_q4_T *new_analog_loopback_q4_M
   )
{
  /* Set C-API version */
  rtwCAPI_SetVersion(new_analog_loopback_q4_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(new_analog_loopback_q4_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(new_analog_loopback_q4_M->DataMapInfo.mmi, NULL);

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(new_analog_loopback_q4_M->DataMapInfo.mmi,
    rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(new_analog_loopback_q4_M->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache C-API rtp Address and size  into the Real-Time Model Data structure */
  new_analog_loopback_q4_M->DataMapInfo.mmi.InstanceMap.rtpAddress =
    rtmGetDefaultParam(new_analog_loopback_q4_M);
  new_analog_loopback_q4_M->DataMapInfo.mmi.staticMap->rtpSize = sizeof
    (P_new_analog_loopback_q4_T);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(new_analog_loopback_q4_M->DataMapInfo.mmi, NULL);

  /* Set Reference to submodels */
  rtwCAPI_SetChildMMIArray(new_analog_loopback_q4_M->DataMapInfo.mmi, NULL);
  rtwCAPI_SetChildMMIArrayLen(new_analog_loopback_q4_M->DataMapInfo.mmi, 0);
}

/* EOF: new_analog_loopback_q4_capi.c */
