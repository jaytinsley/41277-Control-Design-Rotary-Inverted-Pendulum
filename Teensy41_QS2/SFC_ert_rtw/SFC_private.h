/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SFC_private.h
 *
 * Code generated for Simulink model 'SFC'.
 *
 * Model version                  : 1.92
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Oct 23 13:59:37 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef SFC_private_h_
#define SFC_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "SFC_types.h"
#include "SFC.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern real_T rt_roundd_snf(real_T u);
extern int32_T MultiWord2sLong(const uint32_T u[]);
extern void Double2MultiWord(real_T u1, uint32_T y[], int32_T n);

#endif                                 /* SFC_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
