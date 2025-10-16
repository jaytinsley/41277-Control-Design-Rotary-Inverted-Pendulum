/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Teensy41_QS2_data.c
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

#include "Teensy41_QS2.h"

/* Block parameters (default storage) */
P_Teensy41_QS2_T Teensy41_QS2_P = {
  /* Variable: ts
   * Referenced by:
   *   '<S4>/Step'
   *   '<S4>/Step1'
   */
  0.001,

  /* Mask Parameter: PIDController1_D
   * Referenced by: '<S35>/Derivative Gain'
   */
  2.5,

  /* Mask Parameter: PIDController2_D
   * Referenced by: '<S87>/Derivative Gain'
   */
  -2.0,

  /* Mask Parameter: PIDController2_DifferentiatorIC
   * Referenced by: '<S89>/UD'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S37>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController1_N
   * Referenced by: '<S45>/Filter Coefficient'
   */
  0.5263,

  /* Mask Parameter: PIDController1_P
   * Referenced by: '<S47>/Proportional Gain'
   */
  30.0,

  /* Mask Parameter: PIDController2_P
   * Referenced by: '<S101>/Proportional Gain'
   */
  -2.0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S114>/Constant'
   */
  20.0,

  /* Computed Parameter: Vm_Y0
   * Referenced by: '<S5>/Vm'
   */
  0.0,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S37>/Filter'
   */
  1.0,

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
   * Referenced by: '<S117>/SPI WriteRead'
   */
  10.0,

  /* Computed Parameter: encoder0_Y0
   * Referenced by: '<S117>/encoder0'
   */
  0.0,

  /* Computed Parameter: encoder1_Y0
   * Referenced by: '<S117>/encoder1'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S117>/+- 10V'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S117>/+- 10V'
   */
  -10.0,

  /* Expression: 0
   * Referenced by: '<Root>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Unit Delay1'
   */
  0.0,

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

  /* Expression: 180/pi
   * Referenced by: '<S3>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S2>/Gain'
   */
  57.295779513082323,

  /* Expression: 1
   * Referenced by: '<Root>/Motor Enable'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Protection'
   */
  1.0,

  /* Expression: 180/pi
   * Referenced by: '<S118>/Gain'
   */
  57.295779513082323,

  /* Computed Parameter: TmpRTBAtQS2Inport2_InitialCondi
   * Referenced by:
   */
  false
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
