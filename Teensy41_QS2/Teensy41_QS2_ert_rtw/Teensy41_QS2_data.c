/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Teensy41_QS2_data.c
 *
 * Code generated for Simulink model 'Teensy41_QS2'.
 *
 * Model version                  : 1.108
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Oct 28 19:15:10 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Teensy41_QS2.h"

/* Block parameters (default storage) */
P_Teensy41_QS2_T Teensy41_QS2_P = {
  /* Variable: ts
   * Referenced by:
   *   '<S4>/Step'
   *   '<S4>/Step1'
   */
  0.001,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S39>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialConditi_m
   * Referenced by: '<S44>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_LowerSaturationL
   * Referenced by:
   *   '<S51>/Saturation'
   *   '<S36>/DeadZone'
   */
  -10.0,

  /* Mask Parameter: PIDController1_UpperSaturationL
   * Referenced by:
   *   '<S51>/Saturation'
   *   '<S36>/DeadZone'
   */
  10.0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S116>/Constant'
   */
  20.0,

  /* Computed Parameter: Vm_Y0
   * Referenced by: '<S5>/Vm'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S34>/Constant1'
   */
  0.0,

  /* Expression: 112
   * Referenced by: '<S5>/Constant'
   */
  112.0,

  /* Expression: 1
   * Referenced by: '<S5>/Constant4'
   */
  1.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S44>/Integrator'
   */
  0.0005,

  /* Expression: -3.61
   * Referenced by: '<S5>/Constant2'
   */
  -3.61,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S39>/Filter'
   */
  0.0005,

  /* Expression: 0.188
   * Referenced by: '<S5>/Constant3'
   */
  0.188,

  /* Expression: 0
   * Referenced by: '<S34>/Clamping_zero'
   */
  0.0,

  /* Expression: 57.2
   * Referenced by: '<S5>/Constant1'
   */
  57.2,

  /* Expression: 1
   * Referenced by: '<S5>/Gain'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S1>/Pulse Generator1'
   */
  1.0,

  /* Computed Parameter: PulseGenerator1_Period
   * Referenced by: '<S1>/Pulse Generator1'
   */
  2.0,

  /* Computed Parameter: PulseGenerator1_Duty
   * Referenced by: '<S1>/Pulse Generator1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Pulse Generator1'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S119>/SPI WriteRead'
   */
  10.0,

  /* Computed Parameter: encoder0_Y0
   * Referenced by: '<S119>/encoder0'
   */
  0.0,

  /* Computed Parameter: encoder1_Y0
   * Referenced by: '<S119>/encoder1'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S119>/+- 10V'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S119>/+- 10V'
   */
  -10.0,

  /* Expression: 0
   * Referenced by: '<Root>/Unit Delay1'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S3>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<Root>/Unit Delay'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S2>/Gain'
   */
  57.295779513082323,

  /* Expression: 10
   * Referenced by: '<Root>/+- 10V1'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<Root>/+- 10V1'
   */
  -10.0,

  /* Expression: 0
   * Referenced by: '<Root>/RED'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/GREEN'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/BLUE'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Reset_manual'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Step'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S4>/Step'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Step1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S4>/Step1'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S4>/Pulse Generator1'
   */
  1.0,

  /* Computed Parameter: PulseGenerator1_Period_k
   * Referenced by: '<S4>/Pulse Generator1'
   */
  2.0,

  /* Computed Parameter: PulseGenerator1_Duty_m
   * Referenced by: '<S4>/Pulse Generator1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Pulse Generator1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Motor Enable'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Protection'
   */
  1.0,

  /* Expression: 180/pi
   * Referenced by: '<S120>/Gain'
   */
  57.295779513082323,

  /* Computed Parameter: TmpRTBAtQS2Inport2_InitialCondi
   * Referenced by:
   */
  false,

  /* Computed Parameter: Constant_Value_j
   * Referenced by: '<S34>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value_o
   * Referenced by: '<S34>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value_m
   * Referenced by: '<S34>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value_e
   * Referenced by: '<S34>/Constant4'
   */
  -1
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
