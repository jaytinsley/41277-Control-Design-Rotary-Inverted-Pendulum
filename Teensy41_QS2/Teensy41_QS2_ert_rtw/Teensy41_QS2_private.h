/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Teensy41_QS2_private.h
 *
 * Code generated for Simulink model 'Teensy41_QS2'.
 *
 * Model version                  : 1.106
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Oct 16 17:23:41 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Teensy41_QS2_private_h_
#define Teensy41_QS2_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "Teensy41_QS2_types.h"
#include "Teensy41_QS2.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern real_T rt_roundd_snf(real_T u);
extern int32_T MultiWord2sLong(const uint32_T u[]);
extern void Double2MultiWord(real_T u1, uint32_T y[], int32_T n);
extern int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator);

#endif                                 /* Teensy41_QS2_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
