/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SFC.c
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
#include <math.h>
#include "SFC_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include <stddef.h>
#include "zero_crossing_types.h"

/* Block signals (default storage) */
B_SFC_T SFC_B;

/* Block states (default storage) */
DW_SFC_T SFC_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_SFC_T SFC_PrevZCX;

/* Real-time model */
static RT_MODEL_SFC_T SFC_M_;
RT_MODEL_SFC_T *const SFC_M = &SFC_M_;
static void rate_monotonic_scheduler(void);
int32_T MultiWord2sLong(const uint32_T u[])
{
  return (int32_T)u[0];
}

void Double2MultiWord(real_T u1, uint32_T y[], int32_T n)
{
  real_T yd;
  real_T yn;
  int32_T currExp;
  int32_T i;
  int32_T msl;
  int32_T prevExp;
  uint32_T cb;
  uint32_T u1i;
  boolean_T isNegative;
  isNegative = (u1 < 0.0);
  yn = frexp(u1, &currExp);
  msl = currExp <= 0 ? -1 : (currExp - 1) / 32;
  cb = 1U;
  for (i = msl + 1; i < n; i++) {
    y[i] = 0U;
  }

  yn = isNegative ? -yn : yn;
  prevExp = msl << 5;
  for (i = msl; i >= 0; i--) {
    yn = ldexp(yn, currExp - prevExp);
    yd = floor(yn);
    yn -= yd;
    if (i < n) {
      y[i] = (uint32_T)yd;
    }

    currExp = prevExp;
    prevExp -= 32;
  }

  if (isNegative) {
    for (i = 0; i < n; i++) {
      u1i = ~y[i];
      cb += u1i;
      y[i] = cb;
      cb = (uint32_T)(cb < u1i);
    }
  }
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void SFC_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(SFC_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(SFC_M, 2));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rates: 1, 2 */
  SFC_M->Timing.RateInteraction.TID0_1 = (SFC_M->Timing.TaskCounters.TID[1] == 0);
  SFC_M->Timing.RateInteraction.TID0_2 = (SFC_M->Timing.TaskCounters.TID[2] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (SFC_M->Timing.TaskCounters.TID[1])++;
  if ((SFC_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.001s, 0.0s] */
    SFC_M->Timing.TaskCounters.TID[1] = 0;
  }

  (SFC_M->Timing.TaskCounters.TID[2])++;
  if ((SFC_M->Timing.TaskCounters.TID[2]) > 999) {/* Sample time: [0.5s, 0.0s] */
    SFC_M->Timing.TaskCounters.TID[2] = 0;
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function for TID0 */
void SFC_step0(void)                   /* Sample time: [0.0005s, 0.0s] */
{
  uint64m_T tmp_0;
  uint64m_T tmp_1;
  uint64m_T tmp_2;
  uint64m_T tmp_3;
  uint64m_T tmp_4;
  real_T tmp_5;
  int32_T i;
  int16_T x;
  uint16_T motor;
  uint8_T tmp_6;
  boolean_T startup;
  boolean_T tmp;
  ZCEventType zcEvent;

  {                                    /* Sample time: [0.0005s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(SFC_DW.TriggeredSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(SFC_DW.QS2_SubsysRanBC);

  /* RateTransition generated from: '<Root>/Controller' incorporates:
   *  RateTransition generated from: '<S2>/Sum2'
   *  RateTransition: '<S5>/Rate Transition2'
   *  RateTransition generated from: '<S5>/QS2'
   */
  tmp = SFC_M->Timing.RateInteraction.TID0_1;
  if (tmp) {
    /* RateTransition generated from: '<Root>/Controller' */
    SFC_B.TmpRTBAtControllerInport1[0] = SFC_DW.TmpRTBAtControllerInport1_Buffe
      [0];
    SFC_B.TmpRTBAtControllerInport1[1] = SFC_DW.TmpRTBAtControllerInport1_Buffe
      [1];
    SFC_B.TmpRTBAtControllerInport1[2] = SFC_DW.TmpRTBAtControllerInport1_Buffe
      [2];
    SFC_B.TmpRTBAtControllerInport1[3] = SFC_DW.TmpRTBAtControllerInport1_Buffe
      [3];
  }

  /* End of RateTransition generated from: '<Root>/Controller' */

  /* Outputs for Atomic SubSystem: '<Root>/Controller' */
  /* DiscretePulseGenerator: '<S1>/Pulse Generator1' */
  SFC_B.PulseGenerator1_a = (SFC_DW.clockTickCounter_p <
    SFC_P.PulseGenerator1_Duty) && (SFC_DW.clockTickCounter_p >= 0) ?
    SFC_P.PulseGenerator1_Amp : 0.0;
  if (SFC_DW.clockTickCounter_p >= SFC_P.PulseGenerator1_Period - 1.0) {
    SFC_DW.clockTickCounter_p = 0;
  } else {
    SFC_DW.clockTickCounter_p++;
  }

  /* End of DiscretePulseGenerator: '<S1>/Pulse Generator1' */

  /* RateTransition generated from: '<S1>/Triggered Subsystem' */
  if (SFC_M->Timing.RateInteraction.TID0_2) {
    /* RateTransition generated from: '<S1>/Triggered Subsystem' */
    SFC_B.TmpRTBAtTriggeredSubsystemInpor =
      SFC_DW.TmpRTBAtTriggeredSubsystemInpor;
  }

  /* End of RateTransition generated from: '<S1>/Triggered Subsystem' */

  /* Outputs for Triggered SubSystem: '<S1>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S6>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &SFC_PrevZCX.TriggeredSubsystem_Trig_ZCE,
                     (SFC_B.PulseGenerator1_a));
  if (zcEvent != NO_ZCEVENT) {
    /* Gain: '<S6>/Gain2' incorporates:
     *  Gain: '<S6>/Gain'
     *  Gain: '<S6>/Gain1'
     *  Sum: '<S6>/Sum'
     */
    SFC_B.Gain2 = (SFC_P.Gain_Gain * SFC_B.TmpRTBAtTriggeredSubsystemInpor -
                   (((SFC_P.Gain1_Gain[0] * SFC_B.TmpRTBAtControllerInport1[0] +
                      SFC_P.Gain1_Gain[1] * SFC_B.TmpRTBAtControllerInport1[1])
                     + SFC_P.Gain1_Gain[2] * SFC_B.TmpRTBAtControllerInport1[2])
                    + SFC_P.Gain1_Gain[3] * SFC_B.TmpRTBAtControllerInport1[3]))
      * SFC_P.Gain2_Gain;
    SFC_DW.TriggeredSubsystem_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S1>/Triggered Subsystem' */
  /* End of Outputs for SubSystem: '<Root>/Controller' */

  /* RateTransition generated from: '<S5>/QS2' */
  if (tmp) {
    /* RateTransition generated from: '<S5>/QS2' */
    SFC_B.TmpRTBAtQS2Inport2 = SFC_DW.TmpRTBAtQS2Inport2_Buffer0;
  }

  /* DiscretePulseGenerator: '<S5>/Pulse Generator1' */
  SFC_B.PulseGenerator1_a = (SFC_DW.clockTickCounter <
    SFC_P.PulseGenerator1_Duty_m) && (SFC_DW.clockTickCounter >= 0) ?
    SFC_P.PulseGenerator1_Amp_p : 0.0;
  if (SFC_DW.clockTickCounter >= SFC_P.PulseGenerator1_Period_k - 1.0) {
    SFC_DW.clockTickCounter = 0;
  } else {
    SFC_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S5>/Pulse Generator1' */

  /* Outputs for Triggered SubSystem: '<S5>/QS2' incorporates:
   *  TriggerPort: '<S10>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,&SFC_PrevZCX.QS2_Trig_ZCE,
                     (SFC_B.PulseGenerator1_a));
  if (zcEvent != NO_ZCEVENT) {
    /* MATLAB Function: '<S10>/MATLAB Function1' incorporates:
     *  Constant: '<Root>/BLUE'
     *  Constant: '<Root>/GREEN'
     *  Constant: '<Root>/RED'
     *  Constant: '<S5>/Constant'
     */
    SFC_B.y = SFC_P.RED_Value;
    SFC_B.b_y = SFC_P.GREEN_Value;
    SFC_B.PulseGenerator1_a = SFC_P.BLUE_Value;
    SFC_DW.stop = ((SFC_P.Constant_Value_p > 0.0) || SFC_DW.stop);
    startup = true;
    if (SFC_DW.count_startup >= 5.0) {
      startup = false;
      SFC_DW.count_startup = 10.0;
    }

    for (i = 0; i < 17; i++) {
      SFC_B.data_out[i] = 0U;
    }

    SFC_B.data_out[0] = 1U;
    SFC_B.data_out[2] = 31U;

    /* Saturate: '<S10>/+- 10V' */
    if (SFC_B.Gain2 > SFC_P.u0V_UpperSat) {
      SFC_B.R_LED = SFC_P.u0V_UpperSat;
    } else if (SFC_B.Gain2 < SFC_P.u0V_LowerSat) {
      SFC_B.R_LED = SFC_P.u0V_LowerSat;
    } else {
      SFC_B.R_LED = SFC_B.Gain2;
    }

    /* MATLAB Function: '<S10>/MATLAB Function1' incorporates:
     *  Saturate: '<S10>/+- 10V'
     */
    SFC_B.R_LED = rt_roundd_snf(SFC_B.R_LED * 41.666666666666664);
    if (SFC_B.R_LED < 32768.0) {
      if (SFC_B.R_LED >= -32768.0) {
        x = (int16_T)SFC_B.R_LED;
      } else {
        x = MIN_int16_T;
      }
    } else {
      x = MAX_int16_T;
    }

    x |= MIN_int16_T;
    memcpy((void *)&motor, (void *)&x, (size_t)1 * sizeof(uint16_T));
    SFC_B.data_out[15] = (uint8_T)(motor >> 8);
    SFC_B.data_out[16] = (uint8_T)(motor & 255U);
    if (!SFC_B.TmpRTBAtQS2Inport2) {
      SFC_B.data_out[2] = 31U;
      SFC_B.data_out[15] = 0U;
      SFC_B.data_out[16] = 0U;
      SFC_B.y = 1.0;
      SFC_B.b_y = 0.0;
      SFC_B.PulseGenerator1_a = 0.0;
    }

    /* Step: '<S5>/Step' incorporates:
     *  Step: '<S5>/Step1'
     */
    SFC_B.R_LED = SFC_M->Timing.taskTime0;
    if (SFC_B.R_LED < SFC_P.ts) {
      tmp_5 = SFC_P.Step_Y0;
    } else {
      tmp_5 = SFC_P.Step_YFinal;
    }

    /* Step: '<S5>/Step1' */
    if (SFC_B.R_LED < 2.0 * SFC_P.ts) {
      SFC_B.R_LED = SFC_P.Step1_Y0;
    } else {
      SFC_B.R_LED = SFC_P.Step1_YFinal;
    }

    /* MATLAB Function: '<S10>/MATLAB Function1' incorporates:
     *  Constant: '<S5>/Reset_manual'
     *  Logic: '<S5>/Logical Operator'
     *  Step: '<S5>/Step'
     *  Step: '<S5>/Step1'
     *  Sum: '<S5>/Sum'
     */
    if ((SFC_P.Reset_manual_Value != 0.0) || (tmp_5 + SFC_B.R_LED != 0.0) ||
        startup) {
      SFC_B.data_out[2] = 127U;
      SFC_B.data_out[15] = 0U;
      SFC_B.data_out[16] = 0U;
      SFC_B.y = 1.0;
      SFC_B.b_y = 1.0;
      SFC_B.PulseGenerator1_a = 1.0;
    }

    if (SFC_DW.stop || (SFC_DW.count_stop > 1.0)) {
      SFC_DW.count_stop++;
      SFC_B.data_out[2] = 31U;
      SFC_B.data_out[15] = 0U;
      SFC_B.data_out[16] = 0U;
      SFC_B.y = 1.0;
      SFC_B.b_y = 0.0;
      SFC_B.PulseGenerator1_a = 0.0;
    }

    SFC_DW.count_startup++;
    if ((SFC_B.y <= 0.0) || rtIsNaN(SFC_B.y)) {
      SFC_B.y = 0.0;
    }

    if (SFC_B.y >= 1.0) {
      SFC_B.y = 1.0;
    }

    SFC_B.R_LED = 999.0 * SFC_B.y;
    if ((SFC_B.b_y <= 0.0) || rtIsNaN(SFC_B.b_y)) {
      SFC_B.b_y = 0.0;
    }

    if (SFC_B.b_y >= 1.0) {
      SFC_B.b_y = 1.0;
    }

    SFC_B.b_y *= 999.0;
    if ((SFC_B.PulseGenerator1_a <= 0.0) || rtIsNaN(SFC_B.PulseGenerator1_a)) {
      SFC_B.PulseGenerator1_a = 0.0;
    }

    if (SFC_B.PulseGenerator1_a >= 1.0) {
      SFC_B.PulseGenerator1_a = 1.0;
    }

    SFC_B.PulseGenerator1_a *= 999.0;
    Double2MultiWord(SFC_B.R_LED, &SFC_B.r.chunks[0U], 2);
    SFC_B.data_out[3] = (uint8_T)(MultiWord2sLong(&SFC_B.r.chunks[0U]) >> 8);
    Double2MultiWord(SFC_B.R_LED, &tmp_0.chunks[0U], 2);
    SFC_B.data_out[4] = (uint8_T)((uint32_T)MultiWord2sLong(&tmp_0.chunks[0U]) &
      255U);
    Double2MultiWord(SFC_B.b_y, &tmp_1.chunks[0U], 2);
    SFC_B.data_out[5] = (uint8_T)(MultiWord2sLong(&tmp_1.chunks[0U]) >> 8);
    Double2MultiWord(SFC_B.b_y, &tmp_2.chunks[0U], 2);
    SFC_B.data_out[6] = (uint8_T)((uint32_T)MultiWord2sLong(&tmp_2.chunks[0U]) &
      255U);
    Double2MultiWord(SFC_B.PulseGenerator1_a, &tmp_3.chunks[0U], 2);
    SFC_B.data_out[7] = (uint8_T)(MultiWord2sLong(&tmp_3.chunks[0U]) >> 8);
    Double2MultiWord(SFC_B.PulseGenerator1_a, &tmp_4.chunks[0U], 2);
    SFC_B.data_out[8] = (uint8_T)((uint32_T)MultiWord2sLong(&tmp_4.chunks[0U]) &
      255U);

    /* MATLABSystem: '<S10>/SPI WriteRead' */
    if (SFC_DW.obj.slaveSelectPin_ != SFC_P.SPIWriteRead_slaveSelectPin_) {
      SFC_DW.obj.slaveSelectPin_ = SFC_P.SPIWriteRead_slaveSelectPin_;
    }

    SFC_B.R_LED = rt_roundd_snf(SFC_DW.obj.slaveSelectPin_);
    if (SFC_B.R_LED < 256.0) {
      if (SFC_B.R_LED >= 0.0) {
        tmp_6 = (uint8_T)SFC_B.R_LED;
      } else {
        tmp_6 = 0U;
      }
    } else {
      tmp_6 = MAX_uint8_T;
    }

    MW_SPIwriteReadLoop(0, tmp_6, &SFC_B.data_out[0], 17.0, 1.0, &SFC_B.uv[0]);

    /* MATLAB Function: '<S10>/MATLAB Function' incorporates:
     *  MATLABSystem: '<S10>/SPI WriteRead'
     */
    SFC_B.encoder0 = ((int32_T)((uint32_T)SFC_B.uv[2] << 16 | (uint32_T)
      SFC_B.uv[3] << 8 | SFC_B.uv[4]) << 8) >> 8;
    i = ((int32_T)((uint32_T)SFC_B.uv[5] << 16 | (uint32_T)SFC_B.uv[6] << 8 |
                   SFC_B.uv[7]) << 8) >> 8;
    i -= (i >> 11) << 11;
    if (i < 0) {
      i += 2048;
    }

    SFC_B.encoder1 = i;

    /* End of MATLAB Function: '<S10>/MATLAB Function' */

    /* Stop: '<S10>/Stop Simulation' incorporates:
     *  MATLAB Function: '<S10>/MATLAB Function1'
     */
    if (SFC_DW.count_stop > 1.0) {
      rtmSetStopRequested(SFC_M, 1);
    }

    /* End of Stop: '<S10>/Stop Simulation' */
    SFC_DW.QS2_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S5>/QS2' */

  /* MATLAB Function: '<S5>/theta' */
  SFC_B.y = -SFC_B.encoder0 / 325.94932345220167;

  /* MATLAB Function: '<S5>/MATLAB Function1' */
  if (fabs(SFC_B.y) > 6.2831853071795862) {
    SFC_B.y = 0.0;
  }

  /* End of MATLAB Function: '<S5>/MATLAB Function1' */

  /* Gain: '<S4>/Gain' */
  SFC_B.Gain = SFC_P.Gain_Gain_m * SFC_B.y;

  /* MATLAB Function: '<S5>/alpha' */
  SFC_B.alpha_rad = SFC_B.encoder1 / 325.94932345220167 - 3.1415926535897931;

  /* MATLAB Function: '<S5>/MATLAB Function' */
  if (SFC_B.alpha_rad > 3.1415926535897931) {
    SFC_B.y_m = SFC_B.alpha_rad - 6.2831853071795862;
  } else {
    SFC_B.y_m = SFC_B.alpha_rad;
  }

  /* End of MATLAB Function: '<S5>/MATLAB Function' */

  /* RateTransition generated from: '<S2>/Sum2' */
  if (tmp) {
    SFC_DW.theta_rad_Buffer[0] = SFC_B.y;
    SFC_DW.theta_rad_Buffer[1] = SFC_B.y_m;
  }

  /* Gain: '<S3>/Gain' */
  SFC_B.Gain_b = SFC_P.Gain_Gain_k * SFC_B.y_m;

  /* RateTransition: '<S5>/Rate Transition2' */
  if (tmp) {
    SFC_DW.RateTransition2_Buffer = SFC_B.y_m;
  }

  /* RateTransition generated from: '<S2>/Dd matrix' */
  if (tmp) {
    SFC_DW.TmpRTBAtDdmatrixInport1_Buffer = SFC_B.Gain2;
    SFC_DW.Vm_Buffer = SFC_B.Gain2;
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  SFC_M->Timing.taskTime0 =
    ((time_T)(++SFC_M->Timing.clockTick0)) * SFC_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void SFC_step1(void)                   /* Sample time: [0.001s, 0.0s] */
{
  real_T tmp[2];
  real_T rtb_UnitDelay_0;
  real_T rtb_UnitDelay_1;
  real_T rtb_UnitDelay_2;
  real_T rtb_UnitDelay_3;
  int32_T i;
  boolean_T rtb_LogicalOperator1;

  /* UnitDelay: '<S2>/Unit Delay' */
  SFC_B.UnitDelay[0] = SFC_DW.UnitDelay_DSTATE[0];
  SFC_B.UnitDelay[1] = SFC_DW.UnitDelay_DSTATE[1];
  SFC_B.UnitDelay[2] = SFC_DW.UnitDelay_DSTATE[2];
  SFC_B.UnitDelay[3] = SFC_DW.UnitDelay_DSTATE[3];

  /* Gain: '<S2>/Cd matrix' */
  rtb_UnitDelay_0 = SFC_B.UnitDelay[1];
  rtb_UnitDelay_1 = SFC_B.UnitDelay[0];
  rtb_UnitDelay_2 = SFC_B.UnitDelay[2];
  rtb_UnitDelay_3 = SFC_B.UnitDelay[3];

  /* Sum: '<S2>/Sum2' incorporates:
   *  Gain: '<S2>/Cd matrix'
   *  Gain: '<S2>/Dd matrix'
   *  RateTransition generated from: '<S2>/Sum2'
   *  Sum: '<S2>/Sum'
   */
  for (i = 0; i < 2; i++) {
    tmp[i] = SFC_DW.theta_rad_Buffer[i] - ((((SFC_P.C[i + 2] * rtb_UnitDelay_0 +
      SFC_P.C[i] * rtb_UnitDelay_1) + SFC_P.C[i + 4] * rtb_UnitDelay_2) +
      SFC_P.C[i + 6] * rtb_UnitDelay_3) + SFC_P.D[i] *
      SFC_DW.TmpRTBAtDdmatrixInport1_Buffer);
  }

  /* End of Sum: '<S2>/Sum2' */

  /* Gain: '<S2>/Ld matrix' */
  rtb_UnitDelay_0 = tmp[1];
  rtb_UnitDelay_1 = tmp[0];
  for (i = 0; i < 4; i++) {
    /* Sum: '<S2>/Sum3' incorporates:
     *  Gain: '<S2>/Ad matrix'
     *  Gain: '<S2>/Bd matrix'
     *  Gain: '<S2>/Ld matrix'
     *  RateTransition generated from: '<S2>/Bd matrix'
     *  Sum: '<S2>/Sum1'
     *  UnitDelay: '<S2>/Unit Delay'
     */
    SFC_DW.UnitDelay_DSTATE[i] = (((SFC_P.A[i + 4] * SFC_B.UnitDelay[1] +
      SFC_P.A[i] * SFC_B.UnitDelay[0]) + SFC_P.A[i + 8] * SFC_B.UnitDelay[2]) +
      SFC_P.A[i + 12] * SFC_B.UnitDelay[3]) + ((SFC_P.L[i + 4] * rtb_UnitDelay_0
      + SFC_P.L[i] * rtb_UnitDelay_1) + SFC_P.B[i] * SFC_DW.Vm_Buffer);

    /* RateTransition generated from: '<Root>/Controller' */
    SFC_DW.TmpRTBAtControllerInport1_Buffe[i] = SFC_B.UnitDelay[i];
  }

  /* Logic: '<S5>/Logical Operator1' incorporates:
   *  Abs: '<S5>/Abs'
   *  Constant: '<Root>/Motor Enable'
   *  Constant: '<Root>/Protection'
   *  Constant: '<S7>/Constant'
   *  Gain: '<S11>/Gain'
   *  Product: '<S5>/Product'
   *  RateTransition: '<S5>/Rate Transition2'
   *  RelationalOperator: '<S7>/Compare'
   */
  rtb_LogicalOperator1 = ((SFC_P.MotorEnable_Value != 0.0) && (fabs
    (SFC_P.Gain_Gain_f * SFC_DW.RateTransition2_Buffer * SFC_P.Protection_Value)
    < SFC_P.CompareToConstant_const));

  /* RateTransition generated from: '<S5>/QS2' */
  SFC_DW.TmpRTBAtQS2Inport2_Buffer0 = rtb_LogicalOperator1;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.001, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  SFC_M->Timing.clockTick1++;
}

/* Model step function for TID2 */
void SFC_step2(void)                   /* Sample time: [0.5s, 0.0s] */
{
  real_T rtb_PulseGenerator2;

  /* Outputs for Atomic SubSystem: '<Root>/Controller' */
  /* DiscretePulseGenerator: '<S1>/Pulse Generator2' */
  rtb_PulseGenerator2 = (SFC_DW.clockTickCounter_g < SFC_P.PulseGenerator2_Duty)
    && (SFC_DW.clockTickCounter_g >= 0) ? SFC_P.PulseGenerator2_Amp : 0.0;
  if (SFC_DW.clockTickCounter_g >= SFC_P.PulseGenerator2_Period - 1.0) {
    SFC_DW.clockTickCounter_g = 0;
  } else {
    SFC_DW.clockTickCounter_g++;
  }

  /* End of DiscretePulseGenerator: '<S1>/Pulse Generator2' */

  /* RateTransition generated from: '<S1>/Triggered Subsystem' incorporates:
   *  Constant: '<S1>/Constant'
   *  Sum: '<S1>/Sum'
   */
  SFC_DW.TmpRTBAtTriggeredSubsystemInpor = rtb_PulseGenerator2 -
    SFC_P.Constant_Value;

  /* End of Outputs for SubSystem: '<Root>/Controller' */

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.5, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  SFC_M->Timing.clockTick2++;
}

/* Model initialize function */
void SFC_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(SFC_M, -1);
  SFC_M->Timing.stepSize0 = 0.0005;

  /* External mode info */
  SFC_M->Sizes.checksums[0] = (3306461836U);
  SFC_M->Sizes.checksums[1] = (3322235231U);
  SFC_M->Sizes.checksums[2] = (2834968020U);
  SFC_M->Sizes.checksums[3] = (765648162U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[11];
    SFC_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&SFC_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = (sysRanDType *)&SFC_DW.QS2_SubsysRanBC;
    systemRan[6] = (sysRanDType *)&SFC_DW.QS2_SubsysRanBC;
    systemRan[7] = (sysRanDType *)&SFC_DW.QS2_SubsysRanBC;
    systemRan[8] = (sysRanDType *)&SFC_DW.QS2_SubsysRanBC;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(SFC_M->extModeInfo,
      &SFC_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(SFC_M->extModeInfo, SFC_M->Sizes.checksums);
    rteiSetTPtr(SFC_M->extModeInfo, rtmGetTPtr(SFC_M));
  }

  {
    real_T tmp;
    uint8_T tmp_0;

    /* Start for RateTransition generated from: '<Root>/Controller' */
    SFC_B.TmpRTBAtControllerInport1[0] = SFC_P.TmpRTBAtControllerInport1_Initi;
    SFC_B.TmpRTBAtControllerInport1[1] = SFC_P.TmpRTBAtControllerInport1_Initi;
    SFC_B.TmpRTBAtControllerInport1[2] = SFC_P.TmpRTBAtControllerInport1_Initi;
    SFC_B.TmpRTBAtControllerInport1[3] = SFC_P.TmpRTBAtControllerInport1_Initi;

    /* Start for RateTransition generated from: '<S5>/QS2' */
    SFC_B.TmpRTBAtQS2Inport2 = SFC_P.TmpRTBAtQS2Inport2_InitialCondi;
    SFC_PrevZCX.TriggeredSubsystem_Trig_ZCE = UNINITIALIZED_ZCSIG;
    SFC_PrevZCX.QS2_Trig_ZCE = UNINITIALIZED_ZCSIG;

    /* InitializeConditions for RateTransition generated from: '<Root>/Controller' */
    SFC_DW.TmpRTBAtControllerInport1_Buffe[0] =
      SFC_P.TmpRTBAtControllerInport1_Initi;
    SFC_DW.TmpRTBAtControllerInport1_Buffe[1] =
      SFC_P.TmpRTBAtControllerInport1_Initi;
    SFC_DW.TmpRTBAtControllerInport1_Buffe[2] =
      SFC_P.TmpRTBAtControllerInport1_Initi;
    SFC_DW.TmpRTBAtControllerInport1_Buffe[3] =
      SFC_P.TmpRTBAtControllerInport1_Initi;

    /* InitializeConditions for RateTransition generated from: '<S5>/QS2' */
    SFC_DW.TmpRTBAtQS2Inport2_Buffer0 = SFC_P.TmpRTBAtQS2Inport2_InitialCondi;

    /* InitializeConditions for UnitDelay: '<S2>/Unit Delay' */
    SFC_DW.UnitDelay_DSTATE[0] = SFC_P.LuenbergerObserver_x0[0];
    SFC_DW.UnitDelay_DSTATE[1] = SFC_P.LuenbergerObserver_x0[1];
    SFC_DW.UnitDelay_DSTATE[2] = SFC_P.LuenbergerObserver_x0[2];
    SFC_DW.UnitDelay_DSTATE[3] = SFC_P.LuenbergerObserver_x0[3];

    /* SystemInitialize for Atomic SubSystem: '<Root>/Controller' */
    /* Start for RateTransition generated from: '<S1>/Triggered Subsystem' */
    SFC_B.TmpRTBAtTriggeredSubsystemInpor =
      SFC_P.TmpRTBAtTriggeredSubsystemInpor;

    /* InitializeConditions for RateTransition generated from: '<S1>/Triggered Subsystem' */
    SFC_DW.TmpRTBAtTriggeredSubsystemInpor =
      SFC_P.TmpRTBAtTriggeredSubsystemInpor;

    /* SystemInitialize for Triggered SubSystem: '<S1>/Triggered Subsystem' */
    /* SystemInitialize for Gain: '<S6>/Gain2' incorporates:
     *  Outport: '<S6>/Vm'
     */
    SFC_B.Gain2 = SFC_P.Vm_Y0;

    /* End of SystemInitialize for SubSystem: '<S1>/Triggered Subsystem' */
    /* End of SystemInitialize for SubSystem: '<Root>/Controller' */

    /* SystemInitialize for Triggered SubSystem: '<S5>/QS2' */
    /* SystemInitialize for MATLAB Function: '<S10>/MATLAB Function1' */
    SFC_DW.count_startup = 1.0;
    SFC_DW.count_stop = 1.0;

    /* Start for MATLABSystem: '<S10>/SPI WriteRead' */
    SFC_DW.obj.matlabCodegenIsDeleted = false;
    SFC_DW.obj.slaveSelectPin_ = SFC_P.SPIWriteRead_slaveSelectPin_;
    SFC_DW.obj.isInitialized = 1;
    tmp = rt_roundd_snf(SFC_DW.obj.slaveSelectPin_);
    if (tmp < 256.0) {
      if (tmp >= 0.0) {
        tmp_0 = (uint8_T)tmp;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    MW_SSpinSetup(tmp_0);
    SFC_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S10>/SPI WriteRead' */

    /* SystemInitialize for Outport: '<S10>/encoder0' */
    SFC_B.encoder0 = SFC_P.encoder0_Y0;

    /* SystemInitialize for Outport: '<S10>/encoder1' */
    SFC_B.encoder1 = SFC_P.encoder1_Y0;

    /* End of SystemInitialize for SubSystem: '<S5>/QS2' */
  }
}

/* Model terminate function */
void SFC_terminate(void)
{
  /* Terminate for Triggered SubSystem: '<S5>/QS2' */
  /* Terminate for MATLABSystem: '<S10>/SPI WriteRead' */
  if (!SFC_DW.obj.matlabCodegenIsDeleted) {
    SFC_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S10>/SPI WriteRead' */
  /* End of Terminate for SubSystem: '<S5>/QS2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
