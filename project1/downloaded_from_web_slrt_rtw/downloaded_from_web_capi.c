/*
 * downloaded_from_web_capi.c
 *
 * Code generation for model "downloaded_from_web".
 *
 * Model version              : 1.4
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Mar 13 15:32:11 2017
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "downloaded_from_web.h"
#include "rtw_capi.h"
#include "downloaded_from_web_private.h"

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, "Constant",
    "", 0, 0, 0, 0, 0 },

  { 1, 0, "Pulse Generator",
    "", 0, 0, 0, 0, 0 },

  { 2, 0, "Q4 AD",
    "", 0, 0, 0, 0, 0 },

  { 3, 0, "Q4 Enc ",
    "", 0, 0, 0, 0, 0 },

  { 4, 0, "Sine Wave",
    "", 0, 0, 0, 0, 1 },

  {
    0, 0, NULL, NULL, 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 5, "Constant",
    "Value", 0, 0, 0 },

  { 6, "Pulse Generator",
    "Amplitude", 0, 0, 0 },

  { 7, "Pulse Generator",
    "Period", 0, 0, 0 },

  { 8, "Pulse Generator",
    "PulseWidth", 0, 0, 0 },

  { 9, "Pulse Generator",
    "PhaseDelay", 0, 0, 0 },

  { 10, "Q4 AD",
    "P1", 0, 0, 0 },

  { 11, "Q4 AD",
    "P2", 0, 0, 0 },

  { 12, "Q4 AD",
    "P3", 0, 0, 0 },

  { 13, "Q4 AD",
    "P5", 0, 0, 0 },

  { 14, "Q4 AD",
    "P6", 0, 0, 0 },

  { 15, "Q4 AD",
    "P7", 0, 0, 0 },

  { 16, "Q4 DA ",
    "P1", 0, 0, 0 },

  { 17, "Q4 DA ",
    "P2", 0, 0, 0 },

  { 18, "Q4 DA ",
    "P3", 0, 0, 0 },

  { 19, "Q4 DA ",
    "P4", 0, 0, 0 },

  { 20, "Q4 DA ",
    "P5", 0, 0, 0 },

  { 21, "Q4 DA ",
    "P6", 0, 0, 0 },

  { 22, "Q4 DA ",
    "P7", 0, 0, 0 },

  { 23, "Q4 DA ",
    "P8", 0, 0, 0 },

  { 24, "Q4 DA ",
    "P9", 0, 0, 0 },

  { 25, "Q4 Enc ",
    "P1", 0, 0, 0 },

  { 26, "Q4 Enc ",
    "P2", 0, 0, 0 },

  { 27, "Q4 Enc ",
    "P3", 0, 0, 0 },

  { 28, "Q4 Enc ",
    "P4", 0, 0, 0 },

  { 29, "Q4 Enc ",
    "P5", 0, 0, 0 },

  { 30, "Q4 Enc ",
    "P6", 0, 0, 0 },

  { 31, "Q4 Enc ",
    "P7", 0, 0, 0 },

  { 32, "Q4 Enc ",
    "P8", 0, 0, 0 },

  { 33, "Q4 Enc ",
    "P9", 0, 0, 0 },

  { 34, "Q4 Enc ",
    "P10", 0, 0, 0 },

  { 35, "Q4 Enc ",
    "P11", 0, 0, 0 },

  { 36, "Q4 Enc ",
    "P12", 0, 0, 0 },

  { 37, "Sine Wave",
    "Amplitude", 0, 0, 0 },

  { 38, "Sine Wave",
    "Bias", 0, 0, 0 },

  { 39, "Sine Wave",
    "Frequency", 0, 0, 0 },

  { 40, "Sine Wave",
    "Phase", 0, 0, 0 },

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
  &downloaded_from_web_B.Constant,     /* 0: Signal */
  &downloaded_from_web_B.PulseGenerator,/* 1: Signal */
  &downloaded_from_web_B.Q4AD,         /* 2: Signal */
  &downloaded_from_web_B.Q4Enc,        /* 3: Signal */
  &downloaded_from_web_B.SineWave,     /* 4: Signal */
  &downloaded_from_web_P.Constant_Value,/* 5: Block Parameter */
  &downloaded_from_web_P.PulseGenerator_Amp,/* 6: Block Parameter */
  &downloaded_from_web_P.PulseGenerator_Period,/* 7: Block Parameter */
  &downloaded_from_web_P.PulseGenerator_Duty,/* 8: Block Parameter */
  &downloaded_from_web_P.PulseGenerator_PhaseDelay,/* 9: Block Parameter */
  &downloaded_from_web_P.Q4AD_P1,      /* 10: Block Parameter */
  &downloaded_from_web_P.Q4AD_P2,      /* 11: Block Parameter */
  &downloaded_from_web_P.Q4AD_P3,      /* 12: Block Parameter */
  &downloaded_from_web_P.Q4AD_P5,      /* 13: Block Parameter */
  &downloaded_from_web_P.Q4AD_P6,      /* 14: Block Parameter */
  &downloaded_from_web_P.Q4AD_P7,      /* 15: Block Parameter */
  &downloaded_from_web_P.Q4DA_P1,      /* 16: Block Parameter */
  &downloaded_from_web_P.Q4DA_P2,      /* 17: Block Parameter */
  &downloaded_from_web_P.Q4DA_P3,      /* 18: Block Parameter */
  &downloaded_from_web_P.Q4DA_P4,      /* 19: Block Parameter */
  &downloaded_from_web_P.Q4DA_P5,      /* 20: Block Parameter */
  &downloaded_from_web_P.Q4DA_P6,      /* 21: Block Parameter */
  &downloaded_from_web_P.Q4DA_P7,      /* 22: Block Parameter */
  &downloaded_from_web_P.Q4DA_P8,      /* 23: Block Parameter */
  &downloaded_from_web_P.Q4DA_P9,      /* 24: Block Parameter */
  &downloaded_from_web_P.Q4Enc_P1,     /* 25: Block Parameter */
  &downloaded_from_web_P.Q4Enc_P2,     /* 26: Block Parameter */
  &downloaded_from_web_P.Q4Enc_P3,     /* 27: Block Parameter */
  &downloaded_from_web_P.Q4Enc_P4,     /* 28: Block Parameter */
  &downloaded_from_web_P.Q4Enc_P5,     /* 29: Block Parameter */
  &downloaded_from_web_P.Q4Enc_P6,     /* 30: Block Parameter */
  &downloaded_from_web_P.Q4Enc_P7,     /* 31: Block Parameter */
  &downloaded_from_web_P.Q4Enc_P8,     /* 32: Block Parameter */
  &downloaded_from_web_P.Q4Enc_P9,     /* 33: Block Parameter */
  &downloaded_from_web_P.Q4Enc_P10,    /* 34: Block Parameter */
  &downloaded_from_web_P.Q4Enc_P11,    /* 35: Block Parameter */
  &downloaded_from_web_P.Q4Enc_P12,    /* 36: Block Parameter */
  &downloaded_from_web_P.SineWave_Amp, /* 37: Block Parameter */
  &downloaded_from_web_P.SineWave_Bias,/* 38: Block Parameter */
  &downloaded_from_web_P.SineWave_Freq,/* 39: Block Parameter */
  &downloaded_from_web_P.SineWave_Phase/* 40: Block Parameter */
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
  { rtwCAPI_SCALAR, 0, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1                                    /* 1 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.001, 0.0
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

  { rtBlockParameters, 36,
    rtModelParameters, 0 },

  { NULL, 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 2484675802U,
    1804475630U,
    1108869204U,
    181104211U },
  NULL
};

/* Cache pointers into DataMapInfo substructure of RTModel */
void downloaded_from_web_InitializeDataMapInfo(RT_MODEL_downloaded_from_web_T
  *downloaded_from_web_M
  )
{
  /* Set C-API version */
  rtwCAPI_SetVersion(downloaded_from_web_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(downloaded_from_web_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(downloaded_from_web_M->DataMapInfo.mmi, NULL);

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(downloaded_from_web_M->DataMapInfo.mmi,
    rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(downloaded_from_web_M->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache C-API rtp Address and size  into the Real-Time Model Data structure */
  downloaded_from_web_M->DataMapInfo.mmi.InstanceMap.rtpAddress =
    rtmGetDefaultParam(downloaded_from_web_M);
  downloaded_from_web_M->DataMapInfo.mmi.staticMap->rtpSize = sizeof
    (P_downloaded_from_web_T);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(downloaded_from_web_M->DataMapInfo.mmi, NULL);

  /* Set Reference to submodels */
  rtwCAPI_SetChildMMIArray(downloaded_from_web_M->DataMapInfo.mmi, NULL);
  rtwCAPI_SetChildMMIArrayLen(downloaded_from_web_M->DataMapInfo.mmi, 0);
}

/* EOF: downloaded_from_web_capi.c */
