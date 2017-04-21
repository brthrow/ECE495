/*
 * Project3_capi.c
 *
 * Code generation for model "Project3".
 *
 * Model version              : 1.103
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Apr 17 14:47:16 2017
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Project3.h"
#include "rtw_capi.h"
#include "Project3_private.h"

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, "Subsystem/Constant",
    "", 0, 0, 0, 0, 0 },

  { 1, 0, "Subsystem/Derivative1",
    "", 0, 0, 0, 0, 1 },

  { 2, 0, "Subsystem/Gain",
    "", 0, 0, 1, 0, 1 },

  { 3, 0, "Subsystem/Kd",
    "", 0, 0, 0, 0, 1 },

  { 4, 0, "Subsystem/Ki",
    "", 0, 0, 0, 0, 1 },

  { 5, 0, "Subsystem/Kp",
    "", 0, 0, 0, 0, 1 },

  { 6, 0, "Subsystem/gain",
    "Setpoint", 0, 0, 0, 0, 0 },

  { 7, 0, "Subsystem/Integrator1",
    "", 0, 0, 0, 0, 1 },

  { 8, 0, "Subsystem/Q4 AD",
    "", 0, 0, 0, 0, 0 },

  { 9, 0, "Subsystem/Sum1",
    "Error Signal", 0, 0, 0, 0, 1 },

  { 10, 0, "Subsystem/Sum4",
    "", 0, 0, 0, 0, 1 },

  { 11, 0, "Subsystem/Compare To Constant/Compare",
    "", 0, 1, 0, 0, 0 },

  { 12, 0,
    "Subsystem/Real motor/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees",
    "", 0, 0, 0, 0, 0 },

  { 13, 0, "Subsystem/Real motor/Saturation",
    "", 0, 0, 0, 0, 1 },

  { 14, 0, "Subsystem/Real motor/Channel 0 of  Encoder Inputs ",
    "", 0, 0, 0, 0, 0 },

  { 15, 0, "Subsystem/Simulated motor/Back emf Ke1",
    "", 0, 0, 0, 0, 1 },

  { 16, 0, "Subsystem/Simulated motor/Damping b1",
    "", 0, 0, 0, 0, 1 },

  { 17, 0, "Subsystem/Simulated motor/Gain Kt2",
    "", 0, 0, 0, 0, 1 },

  { 18, 0, "Subsystem/Simulated motor/Gain Kt3",
    "", 0, 0, 0, 0, 1 },

  { 19, 0, "Subsystem/Simulated motor/Inductance",
    "", 0, 0, 0, 0, 1 },

  { 20, 0, "Subsystem/Simulated motor/Resistance R1",
    "", 0, 0, 0, 0, 1 },

  { 21, 0, "Subsystem/Simulated motor/Integrator1",
    "", 0, 0, 0, 0, 1 },

  { 22, 0, "Subsystem/Simulated motor/Integrator5",
    "", 0, 0, 0, 0, 1 },

  { 23, 0, "Subsystem/Simulated motor/Integrator6",
    "", 0, 0, 0, 0, 1 },

  { 24, 0, "Subsystem/Simulated motor/Sum1",
    "", 0, 0, 0, 0, 1 },

  { 25, 0, "Subsystem/Simulated motor/Sum2",
    "", 0, 0, 0, 0, 1 },

  { 26, 0, "Subsystem/input side switching logic/complement the input",
    "", 0, 1, 0, 0, 0 },

  { 27, 0, "Subsystem/input side switching logic/Product",
    "", 0, 0, 0, 0, 1 },

  { 28, 0, "Subsystem/input side switching logic/Product1",
    "", 0, 0, 0, 0, 1 },

  { 29, 0, "Subsystem/switching logic/complement the input1",
    "", 0, 1, 0, 0, 0 },

  { 30, 0, "Subsystem/switching logic/Product2",
    "", 0, 0, 0, 0, 1 },

  { 31, 0, "Subsystem/switching logic/Product3",
    "", 0, 0, 0, 0, 0 },

  { 32, 0, "Subsystem/switching logic/Sum2",
    "", 0, 0, 0, 0, 1 },

  {
    0, 0, NULL, NULL, 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 33, "Constant",
    "Value", 0, 0, 0 },

  { 34, "Subsystem/Compare To Constant",
    "const", 0, 0, 0 },

  { 35, "Subsystem/1 - Use simulated motor 0 - Use real motor",
    "Value", 0, 0, 0 },

  { 36, "Subsystem/Constant",
    "Value", 0, 0, 0 },

  { 37, "Subsystem/Gain",
    "Gain", 0, 0, 0 },

  { 38, "Subsystem/Kd",
    "Gain", 0, 0, 0 },

  { 39, "Subsystem/Ki",
    "Gain", 0, 0, 0 },

  { 40, "Subsystem/Kp",
    "Gain", 0, 0, 0 },

  { 41, "Subsystem/gain",
    "Gain", 0, 0, 0 },

  { 42, "Subsystem/Integrator1",
    "InitialCondition", 0, 0, 0 },

  { 43, "Subsystem/Q4 AD",
    "P1", 0, 0, 0 },

  { 44, "Subsystem/Q4 AD",
    "P2", 0, 0, 0 },

  { 45, "Subsystem/Q4 AD",
    "P3", 0, 0, 0 },

  { 46, "Subsystem/Q4 AD",
    "P5", 0, 0, 0 },

  { 47, "Subsystem/Q4 AD",
    "P6", 0, 0, 0 },

  { 48, "Subsystem/Q4 AD",
    "P7", 0, 0, 0 },

  { 49,
    "Subsystem/Real motor/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees",
    "Gain", 0, 0, 0 },

  { 50, "Subsystem/Real motor/Saturation",
    "UpperLimit", 0, 0, 0 },

  { 51, "Subsystem/Real motor/Saturation",
    "LowerLimit", 0, 0, 0 },

  { 52,
    "Subsystem/Real motor/Channel 0 -Control signal to  motor through amplifier ",
    "P1", 0, 0, 0 },

  { 53,
    "Subsystem/Real motor/Channel 0 -Control signal to  motor through amplifier ",
    "P2", 0, 2, 0 },

  { 54,
    "Subsystem/Real motor/Channel 0 -Control signal to  motor through amplifier ",
    "P3", 0, 2, 0 },

  { 55,
    "Subsystem/Real motor/Channel 0 -Control signal to  motor through amplifier ",
    "P4", 0, 0, 0 },

  { 56,
    "Subsystem/Real motor/Channel 0 -Control signal to  motor through amplifier ",
    "P5", 0, 2, 0 },

  { 57,
    "Subsystem/Real motor/Channel 0 -Control signal to  motor through amplifier ",
    "P6", 0, 2, 0 },

  { 58,
    "Subsystem/Real motor/Channel 0 -Control signal to  motor through amplifier ",
    "P7", 0, 0, 0 },

  { 59,
    "Subsystem/Real motor/Channel 0 -Control signal to  motor through amplifier ",
    "P8", 0, 0, 0 },

  { 60,
    "Subsystem/Real motor/Channel 0 -Control signal to  motor through amplifier ",
    "P9", 0, 0, 0 },

  { 61, "Subsystem/Real motor/Channel 0 of  Encoder Inputs ",
    "P1", 0, 0, 0 },

  { 62, "Subsystem/Real motor/Channel 0 of  Encoder Inputs ",
    "P2", 0, 0, 0 },

  { 63, "Subsystem/Real motor/Channel 0 of  Encoder Inputs ",
    "P3", 0, 0, 0 },

  { 64, "Subsystem/Real motor/Channel 0 of  Encoder Inputs ",
    "P4", 0, 0, 0 },

  { 65, "Subsystem/Real motor/Channel 0 of  Encoder Inputs ",
    "P5", 0, 0, 0 },

  { 66, "Subsystem/Real motor/Channel 0 of  Encoder Inputs ",
    "P6", 0, 0, 0 },

  { 67, "Subsystem/Real motor/Channel 0 of  Encoder Inputs ",
    "P7", 0, 0, 0 },

  { 68, "Subsystem/Real motor/Channel 0 of  Encoder Inputs ",
    "P8", 0, 0, 0 },

  { 69, "Subsystem/Real motor/Channel 0 of  Encoder Inputs ",
    "P9", 0, 0, 0 },

  { 70, "Subsystem/Real motor/Channel 0 of  Encoder Inputs ",
    "P10", 0, 0, 0 },

  { 71, "Subsystem/Real motor/Channel 0 of  Encoder Inputs ",
    "P11", 0, 0, 0 },

  { 72, "Subsystem/Real motor/Channel 0 of  Encoder Inputs ",
    "P12", 0, 0, 0 },

  { 73, "Subsystem/Simulated motor/Back emf Ke1",
    "Gain", 0, 0, 0 },

  { 74, "Subsystem/Simulated motor/Damping b1",
    "Gain", 0, 0, 0 },

  { 75, "Subsystem/Simulated motor/Gain Kt2",
    "Gain", 0, 0, 0 },

  { 76, "Subsystem/Simulated motor/Gain Kt3",
    "Gain", 0, 0, 0 },

  { 77, "Subsystem/Simulated motor/Inductance",
    "Gain", 0, 0, 0 },

  { 78, "Subsystem/Simulated motor/Resistance R1",
    "Gain", 0, 0, 0 },

  { 79, "Subsystem/Simulated motor/Integrator1",
    "InitialCondition", 0, 0, 0 },

  { 80, "Subsystem/Simulated motor/Integrator5",
    "InitialCondition", 0, 0, 0 },

  { 81, "Subsystem/Simulated motor/Integrator6",
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
  &Project3_B.Constant,                /* 0: Signal */
  &Project3_B.Derivative1,             /* 1: Signal */
  &Project3_B.Gain[0],                 /* 2: Signal */
  &Project3_B.Kd,                      /* 3: Signal */
  &Project3_B.Ki,                      /* 4: Signal */
  &Project3_B.Kp,                      /* 5: Signal */
  &Project3_B.Setpoint,                /* 6: Signal */
  &Project3_B.Integrator1,             /* 7: Signal */
  &Project3_B.Q4AD,                    /* 8: Signal */
  &Project3_B.ErrorSignal,             /* 9: Signal */
  &Project3_B.Sum4,                    /* 10: Signal */
  &Project3_B.Compare,                 /* 11: Signal */
  &Project3_B.angular_positionrelative_countC,/* 12: Signal */
  &Project3_B.Saturation,              /* 13: Signal */
  &Project3_B.Channel0ofEncoderInputs, /* 14: Signal */
  &Project3_B.BackemfKe1,              /* 15: Signal */
  &Project3_B.Dampingb1,               /* 16: Signal */
  &Project3_B.GainKt2,                 /* 17: Signal */
  &Project3_B.GainKt3,                 /* 18: Signal */
  &Project3_B.Inductance,              /* 19: Signal */
  &Project3_B.ResistanceR1,            /* 20: Signal */
  &Project3_B.Integrator1_h,           /* 21: Signal */
  &Project3_B.Integrator5,             /* 22: Signal */
  &Project3_B.Integrator6,             /* 23: Signal */
  &Project3_B.Sum1,                    /* 24: Signal */
  &Project3_B.Sum2_e,                  /* 25: Signal */
  &Project3_B.complementtheinput,      /* 26: Signal */
  &Project3_B.Product,                 /* 27: Signal */
  &Project3_B.Product1,                /* 28: Signal */
  &Project3_B.complementtheinput1,     /* 29: Signal */
  &Project3_B.Product2,                /* 30: Signal */
  &Project3_B.Product3,                /* 31: Signal */
  &Project3_B.Sum2,                    /* 32: Signal */
  &Project3_P.Constant_Value,          /* 33: Block Parameter */
  &Project3_P.CompareToConstant_const, /* 34: Block Parameter */
  &Project3_P.Usesimulatedmotor0Userealmotor_,/* 35: Block Parameter */
  &Project3_P.Constant_Value_d,        /* 36: Block Parameter */
  &Project3_P.Gain_Gain,               /* 37: Block Parameter */
  &Project3_P.Kd_Gain,                 /* 38: Block Parameter */
  &Project3_P.Ki_Gain,                 /* 39: Block Parameter */
  &Project3_P.Kp_Gain,                 /* 40: Block Parameter */
  &Project3_P.gain_Gain,               /* 41: Block Parameter */
  &Project3_P.Integrator1_IC,          /* 42: Block Parameter */
  &Project3_P.Q4AD_P1,                 /* 43: Block Parameter */
  &Project3_P.Q4AD_P2,                 /* 44: Block Parameter */
  &Project3_P.Q4AD_P3,                 /* 45: Block Parameter */
  &Project3_P.Q4AD_P5,                 /* 46: Block Parameter */
  &Project3_P.Q4AD_P6,                 /* 47: Block Parameter */
  &Project3_P.Q4AD_P7,                 /* 48: Block Parameter */
  &Project3_P.angular_positionrelative_countC,/* 49: Block Parameter */
  &Project3_P.Saturation_UpperSat,     /* 50: Block Parameter */
  &Project3_P.Saturation_LowerSat,     /* 51: Block Parameter */
  &Project3_P.Channel0Controlsignaltomotort_m,/* 52: Block Parameter */
  &Project3_P.Channel0Controlsignaltomotort_k[0],/* 53: Block Parameter */
  &Project3_P.Channel0Controlsignaltomotort_c[0],/* 54: Block Parameter */
  &Project3_P.Channel0Controlsignaltomotort_d,/* 55: Block Parameter */
  &Project3_P.Channel0Controlsignaltomotort_n[0],/* 56: Block Parameter */
  &Project3_P.Channel0Controlsignaltomotort_g[0],/* 57: Block Parameter */
  &Project3_P.Channel0Controlsignaltomotort_f,/* 58: Block Parameter */
  &Project3_P.Channel0Controlsignaltomotor_gv,/* 59: Block Parameter */
  &Project3_P.Channel0Controlsignaltomotor_gp,/* 60: Block Parameter */
  &Project3_P.Channel0ofEncoderInputs_P1,/* 61: Block Parameter */
  &Project3_P.Channel0ofEncoderInputs_P2,/* 62: Block Parameter */
  &Project3_P.Channel0ofEncoderInputs_P3,/* 63: Block Parameter */
  &Project3_P.Channel0ofEncoderInputs_P4,/* 64: Block Parameter */
  &Project3_P.Channel0ofEncoderInputs_P5,/* 65: Block Parameter */
  &Project3_P.Channel0ofEncoderInputs_P6,/* 66: Block Parameter */
  &Project3_P.Channel0ofEncoderInputs_P7,/* 67: Block Parameter */
  &Project3_P.Channel0ofEncoderInputs_P8,/* 68: Block Parameter */
  &Project3_P.Channel0ofEncoderInputs_P9,/* 69: Block Parameter */
  &Project3_P.Channel0ofEncoderInputs_P10,/* 70: Block Parameter */
  &Project3_P.Channel0ofEncoderInputs_P11,/* 71: Block Parameter */
  &Project3_P.Channel0ofEncoderInputs_P12,/* 72: Block Parameter */
  &Project3_P.BackemfKe1_Gain,         /* 73: Block Parameter */
  &Project3_P.Dampingb1_Gain,          /* 74: Block Parameter */
  &Project3_P.GainKt2_Gain,            /* 75: Block Parameter */
  &Project3_P.GainKt3_Gain,            /* 76: Block Parameter */
  &Project3_P.Inductance_Gain,         /* 77: Block Parameter */
  &Project3_P.ResistanceR1_Gain,       /* 78: Block Parameter */
  &Project3_P.Integrator1_IC_j,        /* 79: Block Parameter */
  &Project3_P.Integrator5_IC,          /* 80: Block Parameter */
  &Project3_P.Integrator6_IC           /* 81: Block Parameter */
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

  { rtwCAPI_VECTOR, 2, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  3,                                   /* 2 */
  1,                                   /* 3 */
  1,                                   /* 4 */
  2                                    /* 5 */
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
  { rtBlockSignals, 33 },

  { rtBlockParameters, 49,
    rtModelParameters, 0 },

  { NULL, 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 3103174712U,
    2920325865U,
    1145539637U,
    671982005U },
  NULL
};

/* Cache pointers into DataMapInfo substructure of RTModel */
void Project3_InitializeDataMapInfo(RT_MODEL_Project3_T *Project3_M
  )
{
  /* Set C-API version */
  rtwCAPI_SetVersion(Project3_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(Project3_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(Project3_M->DataMapInfo.mmi, NULL);

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(Project3_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(Project3_M->DataMapInfo.mmi, rtVarDimsAddrMap);

  /* Cache C-API rtp Address and size  into the Real-Time Model Data structure */
  Project3_M->DataMapInfo.mmi.InstanceMap.rtpAddress = rtmGetDefaultParam
    (Project3_M);
  Project3_M->DataMapInfo.mmi.staticMap->rtpSize = sizeof(P_Project3_T);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(Project3_M->DataMapInfo.mmi, NULL);

  /* Set Reference to submodels */
  rtwCAPI_SetChildMMIArray(Project3_M->DataMapInfo.mmi, NULL);
  rtwCAPI_SetChildMMIArrayLen(Project3_M->DataMapInfo.mmi, 0);
}

/* EOF: Project3_capi.c */
