/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SFC_data.c
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

#include "SFC.h"

/* Block parameters (default storage) */
P_SFC_T SFC_P = {
  /* Variable: A
   * Referenced by: '<S2>/Ad matrix'
   */
  { 1.0, 0.0, 0.0, 0.0, 7.3224643522684754E-5, 1.0001284970444464,
    0.1458837528944967, 0.25628099735655946, 0.00099262597854620914,
    -7.2402155041414309E-6, 0.98529984216505562, -0.014424512823771628,
    -2.3889496742960521E-6, 0.00099580776817540439, -0.004734946297734524,
    0.99168175215451071 },

  /* Variable: B
   * Referenced by: '<S2>/Bd matrix'
   */
  { 0.0049160143025272574, 0.0048268103360942886, 9.8001052232962511,
    9.6163418825144209 },

  /* Variable: C
   * Referenced by: '<S2>/Cd matrix'
   */
  { 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0 },

  /* Variable: D
   * Referenced by: '<S2>/Dd matrix'
   */
  { 0.0, 0.0 },

  /* Variable: L
   * Referenced by: '<S2>/Ld matrix'
   */
  { 0.545325962859484, -0.014931522901586954, 70.564069295623554,
    -7.3977629223846453, -0.0031346642240524356, 0.52178412850467293,
    -1.7246424096744069, 66.2192123717253 },

  /* Variable: ts
   * Referenced by:
   *   '<S5>/Step'
   *   '<S5>/Step1'
   */
  0.001,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S7>/Constant'
   */
  20.0,

  /* Mask Parameter: LuenbergerObserver_x0
   * Referenced by: '<S2>/Unit Delay'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Computed Parameter: Vm_Y0
   * Referenced by: '<S6>/Vm'
   */
  0.0,

  /* Expression:   -4.8658e-04
   * Referenced by: '<S6>/Gain'
   */
  -0.00048658,

  /* Expression: [-0.0005    0.0656   -0.0020    0.0034]
   * Referenced by: '<S6>/Gain1'
   */
  { -0.0005, 0.0656, -0.002, 0.0034 },

  /* Expression: 1
   * Referenced by: '<S6>/Gain2'
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

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S1>/Constant'
   */
  0.5,

  /* Expression: 1
   * Referenced by: '<S1>/Pulse Generator2'
   */
  1.0,

  /* Computed Parameter: PulseGenerator2_Period
   * Referenced by: '<S1>/Pulse Generator2'
   */
  2.0,

  /* Computed Parameter: PulseGenerator2_Duty
   * Referenced by: '<S1>/Pulse Generator2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Pulse Generator2'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S10>/SPI WriteRead'
   */
  10.0,

  /* Computed Parameter: encoder0_Y0
   * Referenced by: '<S10>/encoder0'
   */
  0.0,

  /* Computed Parameter: encoder1_Y0
   * Referenced by: '<S10>/encoder1'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S10>/+- 10V'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S10>/+- 10V'
   */
  -10.0,

  /* Expression: 0
   * Referenced by: '<Root>/RED'
   */
  0.0,

  /* Expression: 0
   * Referenced by:
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
   * Referenced by: '<S5>/Reset_manual'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Step'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S5>/Step'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S5>/Step1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S5>/Step1'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S5>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S5>/Pulse Generator1'
   */
  1.0,

  /* Computed Parameter: PulseGenerator1_Period_k
   * Referenced by: '<S5>/Pulse Generator1'
   */
  2.0,

  /* Computed Parameter: PulseGenerator1_Duty_m
   * Referenced by: '<S5>/Pulse Generator1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S5>/Pulse Generator1'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S4>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S3>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<Root>/Motor Enable'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Protection'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S11>/Gain'
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
