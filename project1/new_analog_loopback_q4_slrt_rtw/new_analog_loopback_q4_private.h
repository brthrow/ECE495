/*
 * new_analog_loopback_q4_private.h
 *
 * Code generation for model "new_analog_loopback_q4".
 *
 * Model version              : 1.11
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Mar 13 15:06:20 2017
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_new_analog_loopback_q4_private_h_
#define RTW_HEADER_new_analog_loopback_q4_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern const serialfifoptr serialfifoground;
extern const bcmsglist1553 bcmsg1553ground;
extern const bcstatus1553 bcstatground;
extern const bmmsglist1553 bmmsg1553ground;
extern const char *getRefMdlPath(const char *refMdl);
extern int getRefMdlSignalNumber(const char *mdlBlock, const char *signalName);
extern void adquanserq8(SimStruct *rts);
extern void encquanserq8(SimStruct *rts);
extern void daquanserq8(SimStruct *rts);
extern void doquanserq8(SimStruct *rts);

#endif                                 /* RTW_HEADER_new_analog_loopback_q4_private_h_ */
