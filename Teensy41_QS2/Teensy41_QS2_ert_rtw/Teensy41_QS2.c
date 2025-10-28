/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Teensy41_QS2.c
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
#include <math.h>
#include "Teensy41_QS2_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include <stddef.h>
#include "zero_crossing_types.h"

/* Block signals (default storage) */
B_Teensy41_QS2_T Teensy41_QS2_B;

/* Block states (default storage) */
DW_Teensy41_QS2_T Teensy41_QS2_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Teensy41_QS2_T Teensy41_QS2_PrevZCX;

/* Real-time model */
static RT_MODEL_Teensy41_QS2_T Teensy41_QS2_M_;
RT_MODEL_Teensy41_QS2_T *const Teensy41_QS2_M = &Teensy41_QS2_M_;
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

int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  return (((numerator < 0) != (denominator < 0)) && (numerator % denominator !=
           0) ? -1 : 0) + numerator / denominator;
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Teensy41_QS2_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Teensy41_QS2_M, 1));
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

  /* tid 0 shares data with slower tid rate: 1 */
  Teensy41_QS2_M->Timing.RateInteraction.TID0_1 =
    (Teensy41_QS2_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Teensy41_QS2_M->Timing.TaskCounters.TID[1])++;
  if ((Teensy41_QS2_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.001s, 0.0s] */
    Teensy41_QS2_M->Timing.TaskCounters.TID[1] = 0;
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
void Teensy41_QS2_step0(void)          /* Sample time: [0.0005s, 0.0s] */
{
  uint64m_T tmp;
  uint64m_T tmp_0;
  uint64m_T tmp_1;
  real_T tmp_3;
  real_T y;
  int32_T i;
  uint32_T TriggeredSubsystem_ELAPS_T;
  int16_T x;
  uint16_T motor;
  int8_T rtb_Switch1;
  int8_T tmp_2;
  uint8_T tmp_4;
  boolean_T rtb_RelationalOperator;
  boolean_T startup;
  ZCEventType zcEvent;

  {                                    /* Sample time: [0.0005s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(Teensy41_QS2_DW.TriggeredSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Teensy41_QS2_DW.QS2_SubsysRanBC);

  /* Gain: '<S3>/Gain' incorporates:
   *  UnitDelay: '<Root>/Unit Delay1'
   */
  Teensy41_QS2_B.Gain = Teensy41_QS2_P.Gain_Gain_m *
    Teensy41_QS2_DW.UnitDelay1_DSTATE;

  /* Gain: '<S2>/Gain' incorporates:
   *  UnitDelay: '<Root>/Unit Delay'
   */
  Teensy41_QS2_B.Gain_b = Teensy41_QS2_P.Gain_Gain_k *
    Teensy41_QS2_DW.UnitDelay_DSTATE;

  /* Outputs for Atomic SubSystem: '<Root>/Controller' */
  /* DiscretePulseGenerator: '<S1>/Pulse Generator1' */
  Teensy41_QS2_B.PulseGenerator1_a = (Teensy41_QS2_DW.clockTickCounter_p <
    Teensy41_QS2_P.PulseGenerator1_Duty) && (Teensy41_QS2_DW.clockTickCounter_p >=
    0) ? Teensy41_QS2_P.PulseGenerator1_Amp : 0.0;
  if (Teensy41_QS2_DW.clockTickCounter_p >=
      Teensy41_QS2_P.PulseGenerator1_Period - 1.0) {
    Teensy41_QS2_DW.clockTickCounter_p = 0;
  } else {
    Teensy41_QS2_DW.clockTickCounter_p++;
  }

  /* End of DiscretePulseGenerator: '<S1>/Pulse Generator1' */

  /* Outputs for Triggered SubSystem: '<S1>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S5>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &Teensy41_QS2_PrevZCX.TriggeredSubsystem_Trig_ZCE,
                     (Teensy41_QS2_B.PulseGenerator1_a));
  if (zcEvent != NO_ZCEVENT) {
    if (Teensy41_QS2_DW.TriggeredSubsystem_RESET_ELAPS_) {
      TriggeredSubsystem_ELAPS_T = 0U;
    } else {
      TriggeredSubsystem_ELAPS_T = Teensy41_QS2_M->Timing.clockTick0 -
        Teensy41_QS2_DW.TriggeredSubsystem_PREV_T;
    }

    Teensy41_QS2_DW.TriggeredSubsystem_PREV_T =
      Teensy41_QS2_M->Timing.clockTick0;
    Teensy41_QS2_DW.TriggeredSubsystem_RESET_ELAPS_ = false;

    /* DiscreteIntegrator: '<S44>/Integrator' incorporates:
     *  Constant: '<S5>/Constant4'
     */
    if (Teensy41_QS2_DW.Integrator_SYSTEM_ENABLE == 0) {
      if ((Teensy41_QS2_P.Constant4_Value > 0.0) &&
          (Teensy41_QS2_DW.Integrator_PrevResetState <= 0)) {
        Teensy41_QS2_DW.Integrator_DSTATE =
          Teensy41_QS2_P.PIDController1_InitialConditi_m;
      } else {
        /* DiscreteIntegrator: '<S44>/Integrator' */
        Teensy41_QS2_DW.Integrator_DSTATE += Teensy41_QS2_P.Integrator_gainval *
          (real_T)TriggeredSubsystem_ELAPS_T * Teensy41_QS2_DW.Integrator_PREV_U;
      }
    }

    /* End of DiscreteIntegrator: '<S44>/Integrator' */

    /* DiscreteIntegrator: '<S39>/Filter' incorporates:
     *  Constant: '<S5>/Constant4'
     */
    if (Teensy41_QS2_DW.Filter_SYSTEM_ENABLE == 0) {
      if ((Teensy41_QS2_P.Constant4_Value > 0.0) &&
          (Teensy41_QS2_DW.Filter_PrevResetState <= 0)) {
        Teensy41_QS2_DW.Filter_DSTATE =
          Teensy41_QS2_P.PIDController1_InitialCondition;
      } else {
        /* DiscreteIntegrator: '<S39>/Filter' */
        Teensy41_QS2_DW.Filter_DSTATE += Teensy41_QS2_P.Filter_gainval * (real_T)
          TriggeredSubsystem_ELAPS_T * Teensy41_QS2_DW.Filter_PREV_U;
      }
    }

    /* End of DiscreteIntegrator: '<S39>/Filter' */

    /* Product: '<S47>/NProd Out' incorporates:
     *  Constant: '<S5>/Constant2'
     *  Constant: '<S5>/Constant3'
     *  Math: '<S5>/Math Function'
     *  Product: '<S37>/DProd Out'
     *  Sum: '<S39>/SumD'
     *  UnitDelay: '<Root>/Unit Delay'
     *
     * About '<S5>/Math Function':
     *  Operator: reciprocal
     */
    Teensy41_QS2_DW.Filter_PREV_U = (Teensy41_QS2_DW.UnitDelay_DSTATE *
      Teensy41_QS2_P.Constant2_Value - Teensy41_QS2_DW.Filter_DSTATE) * (1.0 /
      Teensy41_QS2_P.Constant3_Value);

    /* Step: '<S4>/Step1' incorporates:
     *  Constant: '<S5>/Constant'
     *  Product: '<S49>/PProd Out'
     *  Sum: '<S53>/Sum'
     *  UnitDelay: '<Root>/Unit Delay'
     */
    Teensy41_QS2_B.Saturation = (Teensy41_QS2_DW.UnitDelay_DSTATE *
      Teensy41_QS2_P.Constant_Value + Teensy41_QS2_DW.Integrator_DSTATE) +
      Teensy41_QS2_DW.Filter_PREV_U;

    /* DeadZone: '<S36>/DeadZone' */
    if (Teensy41_QS2_B.Saturation >
        Teensy41_QS2_P.PIDController1_UpperSaturationL) {
      /* Step: '<S4>/Step' */
      Teensy41_QS2_DW.Integrator_PREV_U = Teensy41_QS2_B.Saturation -
        Teensy41_QS2_P.PIDController1_UpperSaturationL;
    } else if (Teensy41_QS2_B.Saturation >=
               Teensy41_QS2_P.PIDController1_LowerSaturationL) {
      /* Step: '<S4>/Step' */
      Teensy41_QS2_DW.Integrator_PREV_U = 0.0;
    } else {
      /* Step: '<S4>/Step' */
      Teensy41_QS2_DW.Integrator_PREV_U = Teensy41_QS2_B.Saturation -
        Teensy41_QS2_P.PIDController1_LowerSaturationL;
    }

    /* End of DeadZone: '<S36>/DeadZone' */

    /* RelationalOperator: '<S34>/Relational Operator' incorporates:
     *  Constant: '<S34>/Clamping_zero'
     */
    rtb_RelationalOperator = (Teensy41_QS2_P.Clamping_zero_Value !=
      Teensy41_QS2_DW.Integrator_PREV_U);

    /* Switch: '<S34>/Switch1' incorporates:
     *  Constant: '<S34>/Clamping_zero'
     *  Constant: '<S34>/Constant'
     *  Constant: '<S34>/Constant2'
     *  RelationalOperator: '<S34>/fix for DT propagation issue'
     */
    if (Teensy41_QS2_DW.Integrator_PREV_U > Teensy41_QS2_P.Clamping_zero_Value)
    {
      rtb_Switch1 = Teensy41_QS2_P.Constant_Value_j;
    } else {
      rtb_Switch1 = Teensy41_QS2_P.Constant2_Value_o;
    }

    /* End of Switch: '<S34>/Switch1' */

    /* Step: '<S4>/Step' incorporates:
     *  Constant: '<S5>/Constant1'
     *  Product: '<S41>/IProd Out'
     *  UnitDelay: '<Root>/Unit Delay'
     */
    Teensy41_QS2_DW.Integrator_PREV_U = Teensy41_QS2_DW.UnitDelay_DSTATE *
      Teensy41_QS2_P.Constant1_Value_i;

    /* Saturate: '<S51>/Saturation' */
    if (Teensy41_QS2_B.Saturation >
        Teensy41_QS2_P.PIDController1_UpperSaturationL) {
      /* Step: '<S4>/Step1' incorporates:
       *  Saturate: '<S51>/Saturation'
       */
      Teensy41_QS2_B.Saturation = Teensy41_QS2_P.PIDController1_UpperSaturationL;
    } else if (Teensy41_QS2_B.Saturation <
               Teensy41_QS2_P.PIDController1_LowerSaturationL) {
      /* Step: '<S4>/Step1' incorporates:
       *  Saturate: '<S51>/Saturation'
       */
      Teensy41_QS2_B.Saturation = Teensy41_QS2_P.PIDController1_LowerSaturationL;
    }

    /* End of Saturate: '<S51>/Saturation' */
    /* Gain: '<S5>/Gain' */
    Teensy41_QS2_B.Gain_b5 = Teensy41_QS2_P.Gain_Gain *
      Teensy41_QS2_B.Saturation;

    /* Update for DiscreteIntegrator: '<S44>/Integrator' incorporates:
     *  Constant: '<S5>/Constant4'
     */
    Teensy41_QS2_DW.Integrator_SYSTEM_ENABLE = 0U;
    if (Teensy41_QS2_P.Constant4_Value > 0.0) {
      Teensy41_QS2_DW.Integrator_PrevResetState = 1;
    } else if (Teensy41_QS2_P.Constant4_Value < 0.0) {
      Teensy41_QS2_DW.Integrator_PrevResetState = -1;
    } else if (Teensy41_QS2_P.Constant4_Value == 0.0) {
      Teensy41_QS2_DW.Integrator_PrevResetState = 0;
    } else {
      Teensy41_QS2_DW.Integrator_PrevResetState = 2;
    }

    /* Switch: '<S34>/Switch2' incorporates:
     *  Constant: '<S34>/Clamping_zero'
     *  Constant: '<S34>/Constant3'
     *  Constant: '<S34>/Constant4'
     *  RelationalOperator: '<S34>/fix for DT propagation issue1'
     */
    if (Teensy41_QS2_DW.Integrator_PREV_U > Teensy41_QS2_P.Clamping_zero_Value)
    {
      tmp_2 = Teensy41_QS2_P.Constant3_Value_m;
    } else {
      tmp_2 = Teensy41_QS2_P.Constant4_Value_e;
    }

    /* Switch: '<S34>/Switch' incorporates:
     *  Logic: '<S34>/AND3'
     *  RelationalOperator: '<S34>/Equal1'
     *  Switch: '<S34>/Switch2'
     */
    if (rtb_RelationalOperator && (rtb_Switch1 == tmp_2)) {
      /* Step: '<S4>/Step' incorporates:
       *  Constant: '<S34>/Constant1'
       *  DiscreteIntegrator: '<S44>/Integrator'
       */
      Teensy41_QS2_DW.Integrator_PREV_U = Teensy41_QS2_P.Constant1_Value;
    }

    /* End of Switch: '<S34>/Switch' */

    /* Update for DiscreteIntegrator: '<S39>/Filter' incorporates:
     *  Constant: '<S5>/Constant4'
     */
    Teensy41_QS2_DW.Filter_SYSTEM_ENABLE = 0U;
    if (Teensy41_QS2_P.Constant4_Value > 0.0) {
      Teensy41_QS2_DW.Filter_PrevResetState = 1;
    } else if (Teensy41_QS2_P.Constant4_Value < 0.0) {
      Teensy41_QS2_DW.Filter_PrevResetState = -1;
    } else if (Teensy41_QS2_P.Constant4_Value == 0.0) {
      Teensy41_QS2_DW.Filter_PrevResetState = 0;
    } else {
      Teensy41_QS2_DW.Filter_PrevResetState = 2;
    }

    /* End of Update for DiscreteIntegrator: '<S39>/Filter' */
    Teensy41_QS2_DW.TriggeredSubsystem_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S1>/Triggered Subsystem' */
  /* RateTransition generated from: '<S4>/QS2' incorporates:
   *  RateTransition: '<S4>/Rate Transition2'
   */
  rtb_RelationalOperator = Teensy41_QS2_M->Timing.RateInteraction.TID0_1;
  if (rtb_RelationalOperator) {
    /* RateTransition generated from: '<S4>/QS2' */
    Teensy41_QS2_B.TmpRTBAtQS2Inport2 =
      Teensy41_QS2_DW.TmpRTBAtQS2Inport2_Buffer0;
  }

  /* End of RateTransition generated from: '<S4>/QS2' */

  /* DiscretePulseGenerator: '<S4>/Pulse Generator1' */
  Teensy41_QS2_B.PulseGenerator1_a = (Teensy41_QS2_DW.clockTickCounter <
    Teensy41_QS2_P.PulseGenerator1_Duty_m) && (Teensy41_QS2_DW.clockTickCounter >=
    0) ? Teensy41_QS2_P.PulseGenerator1_Amp_p : 0.0;
  if (Teensy41_QS2_DW.clockTickCounter >=
      Teensy41_QS2_P.PulseGenerator1_Period_k - 1.0) {
    Teensy41_QS2_DW.clockTickCounter = 0;
  } else {
    Teensy41_QS2_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S4>/Pulse Generator1' */

  /* Outputs for Triggered SubSystem: '<S4>/QS2' incorporates:
   *  TriggerPort: '<S119>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,&Teensy41_QS2_PrevZCX.QS2_Trig_ZCE,
                     (Teensy41_QS2_B.PulseGenerator1_a));
  if (zcEvent != NO_ZCEVENT) {
    /* MATLAB Function: '<S119>/MATLAB Function1' incorporates:
     *  Constant: '<Root>/BLUE'
     *  Constant: '<Root>/GREEN'
     *  Constant: '<Root>/RED'
     *  Constant: '<S4>/Constant'
     */
    Teensy41_QS2_B.y = Teensy41_QS2_P.RED_Value;
    Teensy41_QS2_B.b_y = Teensy41_QS2_P.GREEN_Value;
    Teensy41_QS2_B.PulseGenerator1_a = Teensy41_QS2_P.BLUE_Value;
    Teensy41_QS2_DW.stop = ((Teensy41_QS2_P.Constant_Value_p > 0.0) ||
      Teensy41_QS2_DW.stop);
    startup = true;
    if (Teensy41_QS2_DW.count_startup >= 5.0) {
      startup = false;
      Teensy41_QS2_DW.count_startup = 10.0;
    }

    for (i = 0; i < 17; i++) {
      Teensy41_QS2_B.data_out[i] = 0U;
    }

    Teensy41_QS2_B.data_out[0] = 1U;
    Teensy41_QS2_B.data_out[2] = 31U;

    /* Saturate: '<Root>/+- 10V1' */
    if (Teensy41_QS2_B.Gain_b5 > Teensy41_QS2_P.u0V1_UpperSat) {
      y = Teensy41_QS2_P.u0V1_UpperSat;
    } else if (Teensy41_QS2_B.Gain_b5 < Teensy41_QS2_P.u0V1_LowerSat) {
      y = Teensy41_QS2_P.u0V1_LowerSat;
    } else {
      y = Teensy41_QS2_B.Gain_b5;
    }

    /* End of Saturate: '<Root>/+- 10V1' */

    /* Saturate: '<S119>/+- 10V' */
    if (y > Teensy41_QS2_P.u0V_UpperSat) {
      y = Teensy41_QS2_P.u0V_UpperSat;
    } else if (y < Teensy41_QS2_P.u0V_LowerSat) {
      y = Teensy41_QS2_P.u0V_LowerSat;
    }

    /* MATLAB Function: '<S119>/MATLAB Function1' incorporates:
     *  Saturate: '<S119>/+- 10V'
     */
    y = rt_roundd_snf(y * 41.666666666666664);
    if (y < 32768.0) {
      if (y >= -32768.0) {
        x = (int16_T)y;
      } else {
        x = MIN_int16_T;
      }
    } else {
      x = MAX_int16_T;
    }

    x |= MIN_int16_T;
    memcpy((void *)&motor, (void *)&x, (size_t)1 * sizeof(uint16_T));
    Teensy41_QS2_B.data_out[15] = (uint8_T)(motor >> 8);
    Teensy41_QS2_B.data_out[16] = (uint8_T)(motor & 255U);
    if (!Teensy41_QS2_B.TmpRTBAtQS2Inport2) {
      Teensy41_QS2_B.data_out[2] = 31U;
      Teensy41_QS2_B.data_out[15] = 0U;
      Teensy41_QS2_B.data_out[16] = 0U;
      Teensy41_QS2_B.y = 1.0;
      Teensy41_QS2_B.b_y = 0.0;
      Teensy41_QS2_B.PulseGenerator1_a = 0.0;
    }

    /* Step: '<S4>/Step' incorporates:
     *  Step: '<S4>/Step1'
     */
    y = Teensy41_QS2_M->Timing.taskTime0;
    if (y < Teensy41_QS2_P.ts) {
      tmp_3 = Teensy41_QS2_P.Step_Y0;
    } else {
      tmp_3 = Teensy41_QS2_P.Step_YFinal;
    }

    /* Step: '<S4>/Step1' */
    if (y < 2.0 * Teensy41_QS2_P.ts) {
      y = Teensy41_QS2_P.Step1_Y0;
    } else {
      y = Teensy41_QS2_P.Step1_YFinal;
    }

    /* MATLAB Function: '<S119>/MATLAB Function1' incorporates:
     *  Constant: '<S4>/Reset_manual'
     *  Logic: '<S4>/Logical Operator'
     *  Step: '<S4>/Step'
     *  Step: '<S4>/Step1'
     *  Sum: '<S4>/Sum'
     */
    if ((Teensy41_QS2_P.Reset_manual_Value != 0.0) || (tmp_3 + y != 0.0) ||
        startup) {
      Teensy41_QS2_B.data_out[2] = 127U;
      Teensy41_QS2_B.data_out[15] = 0U;
      Teensy41_QS2_B.data_out[16] = 0U;
      Teensy41_QS2_B.y = 1.0;
      Teensy41_QS2_B.b_y = 1.0;
      Teensy41_QS2_B.PulseGenerator1_a = 1.0;
    }

    if (Teensy41_QS2_DW.stop || (Teensy41_QS2_DW.count_stop > 1.0)) {
      Teensy41_QS2_DW.count_stop++;
      Teensy41_QS2_B.data_out[2] = 31U;
      Teensy41_QS2_B.data_out[15] = 0U;
      Teensy41_QS2_B.data_out[16] = 0U;
      Teensy41_QS2_B.y = 1.0;
      Teensy41_QS2_B.b_y = 0.0;
      Teensy41_QS2_B.PulseGenerator1_a = 0.0;
    }

    Teensy41_QS2_DW.count_startup++;
    if ((Teensy41_QS2_B.y <= 0.0) || rtIsNaN(Teensy41_QS2_B.y)) {
      Teensy41_QS2_B.y = 0.0;
    }

    if (Teensy41_QS2_B.y >= 1.0) {
      Teensy41_QS2_B.y = 1.0;
    }

    y = 999.0 * Teensy41_QS2_B.y;
    if ((Teensy41_QS2_B.b_y <= 0.0) || rtIsNaN(Teensy41_QS2_B.b_y)) {
      Teensy41_QS2_B.b_y = 0.0;
    }

    if (Teensy41_QS2_B.b_y >= 1.0) {
      Teensy41_QS2_B.b_y = 1.0;
    }

    Teensy41_QS2_B.b_y *= 999.0;
    if ((Teensy41_QS2_B.PulseGenerator1_a <= 0.0) || rtIsNaN
        (Teensy41_QS2_B.PulseGenerator1_a)) {
      Teensy41_QS2_B.PulseGenerator1_a = 0.0;
    }

    if (Teensy41_QS2_B.PulseGenerator1_a >= 1.0) {
      Teensy41_QS2_B.PulseGenerator1_a = 1.0;
    }

    Teensy41_QS2_B.PulseGenerator1_a *= 999.0;
    Double2MultiWord(y, &Teensy41_QS2_B.r.chunks[0U], 2);
    Teensy41_QS2_B.data_out[3] = (uint8_T)(MultiWord2sLong
      (&Teensy41_QS2_B.r.chunks[0U]) >> 8);
    Double2MultiWord(y, &Teensy41_QS2_B.r1.chunks[0U], 2);
    Teensy41_QS2_B.data_out[4] = (uint8_T)((uint32_T)MultiWord2sLong
      (&Teensy41_QS2_B.r1.chunks[0U]) & 255U);
    Double2MultiWord(Teensy41_QS2_B.b_y, &Teensy41_QS2_B.r2.chunks[0U], 2);
    Teensy41_QS2_B.data_out[5] = (uint8_T)(MultiWord2sLong
      (&Teensy41_QS2_B.r2.chunks[0U]) >> 8);
    Double2MultiWord(Teensy41_QS2_B.b_y, &tmp.chunks[0U], 2);
    Teensy41_QS2_B.data_out[6] = (uint8_T)((uint32_T)MultiWord2sLong
      (&tmp.chunks[0U]) & 255U);
    Double2MultiWord(Teensy41_QS2_B.PulseGenerator1_a, &tmp_0.chunks[0U], 2);
    Teensy41_QS2_B.data_out[7] = (uint8_T)(MultiWord2sLong(&tmp_0.chunks[0U]) >>
      8);
    Double2MultiWord(Teensy41_QS2_B.PulseGenerator1_a, &tmp_1.chunks[0U], 2);
    Teensy41_QS2_B.data_out[8] = (uint8_T)((uint32_T)MultiWord2sLong
      (&tmp_1.chunks[0U]) & 255U);

    /* MATLABSystem: '<S119>/SPI WriteRead' */
    if (Teensy41_QS2_DW.obj.slaveSelectPin_ !=
        Teensy41_QS2_P.SPIWriteRead_slaveSelectPin_) {
      Teensy41_QS2_DW.obj.slaveSelectPin_ =
        Teensy41_QS2_P.SPIWriteRead_slaveSelectPin_;
    }

    y = rt_roundd_snf(Teensy41_QS2_DW.obj.slaveSelectPin_);
    if (y < 256.0) {
      if (y >= 0.0) {
        tmp_4 = (uint8_T)y;
      } else {
        tmp_4 = 0U;
      }
    } else {
      tmp_4 = MAX_uint8_T;
    }

    MW_SPIwriteReadLoop(0, tmp_4, &Teensy41_QS2_B.data_out[0], 17.0, 1.0,
                        &Teensy41_QS2_B.uv[0]);

    /* MATLAB Function: '<S119>/MATLAB Function' incorporates:
     *  MATLABSystem: '<S119>/SPI WriteRead'
     */
    Teensy41_QS2_B.encoder0 = ((int32_T)((uint32_T)Teensy41_QS2_B.uv[2] << 16 |
      (uint32_T)Teensy41_QS2_B.uv[3] << 8 | Teensy41_QS2_B.uv[4]) << 8) >> 8;
    i = ((int32_T)((uint32_T)Teensy41_QS2_B.uv[5] << 16 | (uint32_T)
                   Teensy41_QS2_B.uv[6] << 8 | Teensy41_QS2_B.uv[7]) << 8) >> 8;
    i -= div_nde_s32_floor(i, 2047) * 2047;
    if (i < 0) {
      i += 2047;
    }

    Teensy41_QS2_B.encoder1 = i;

    /* End of MATLAB Function: '<S119>/MATLAB Function' */

    /* Stop: '<S119>/Stop Simulation' incorporates:
     *  MATLAB Function: '<S119>/MATLAB Function1'
     */
    if (Teensy41_QS2_DW.count_stop > 1.0) {
      rtmSetStopRequested(Teensy41_QS2_M, 1);
    }

    /* End of Stop: '<S119>/Stop Simulation' */
    Teensy41_QS2_DW.QS2_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S4>/QS2' */

  /* MATLAB Function: '<S4>/alpha' */
  Teensy41_QS2_B.alpha_rad = Teensy41_QS2_B.encoder1 / 325.94932345220167 -
    3.1415926535897931;

  /* MATLAB Function: '<S4>/MATLAB Function' */
  if (Teensy41_QS2_B.alpha_rad > 3.1415926535897931) {
    Teensy41_QS2_B.y_b = Teensy41_QS2_B.alpha_rad - 6.2831853071795862;
  } else {
    Teensy41_QS2_B.y_b = Teensy41_QS2_B.alpha_rad;
  }

  /* End of MATLAB Function: '<S4>/MATLAB Function' */
  /* RateTransition: '<S4>/Rate Transition2' */
  if (rtb_RelationalOperator) {
    Teensy41_QS2_DW.RateTransition2_Buffer = Teensy41_QS2_B.y_b;
  }

  /* MATLAB Function: '<S4>/theta' */
  Teensy41_QS2_B.y = -Teensy41_QS2_B.encoder0 / 325.94932345220167;

  /* MATLAB Function: '<S4>/MATLAB Function1' */
  if (fabs(Teensy41_QS2_B.y) > 6.2831853071795862) {
    Teensy41_QS2_B.y = 0.0;
  }

  /* End of MATLAB Function: '<S4>/MATLAB Function1' */
  /* Update for UnitDelay: '<Root>/Unit Delay1' */
  Teensy41_QS2_DW.UnitDelay1_DSTATE = Teensy41_QS2_B.y;

  /* Update for UnitDelay: '<Root>/Unit Delay' */
  Teensy41_QS2_DW.UnitDelay_DSTATE = Teensy41_QS2_B.y_b;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Teensy41_QS2_M->Timing.taskTime0 =
    ((time_T)(++Teensy41_QS2_M->Timing.clockTick0)) *
    Teensy41_QS2_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void Teensy41_QS2_step1(void)          /* Sample time: [0.001s, 0.0s] */
{
  boolean_T rtb_LogicalOperator1;

  /* Logic: '<S4>/Logical Operator1' incorporates:
   *  Abs: '<S4>/Abs'
   *  Constant: '<Root>/Motor Enable'
   *  Constant: '<Root>/Protection'
   *  Constant: '<S116>/Constant'
   *  Gain: '<S120>/Gain'
   *  Product: '<S4>/Product'
   *  RateTransition: '<S4>/Rate Transition2'
   *  RelationalOperator: '<S116>/Compare'
   */
  rtb_LogicalOperator1 = ((Teensy41_QS2_P.MotorEnable_Value != 0.0) && (fabs
    (Teensy41_QS2_P.Gain_Gain_f * Teensy41_QS2_DW.RateTransition2_Buffer *
     Teensy41_QS2_P.Protection_Value) < Teensy41_QS2_P.CompareToConstant_const));

  /* RateTransition generated from: '<S4>/QS2' */
  Teensy41_QS2_DW.TmpRTBAtQS2Inport2_Buffer0 = rtb_LogicalOperator1;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.001, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Teensy41_QS2_M->Timing.clockTick1++;
}

/* Model initialize function */
void Teensy41_QS2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(Teensy41_QS2_M, -1);
  Teensy41_QS2_M->Timing.stepSize0 = 0.0005;

  /* External mode info */
  Teensy41_QS2_M->Sizes.checksums[0] = (1616110258U);
  Teensy41_QS2_M->Sizes.checksums[1] = (251356189U);
  Teensy41_QS2_M->Sizes.checksums[2] = (1367474973U);
  Teensy41_QS2_M->Sizes.checksums[3] = (1424765171U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[15];
    Teensy41_QS2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &Teensy41_QS2_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[2] = (sysRanDType *)
      &Teensy41_QS2_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &Teensy41_QS2_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[4] = (sysRanDType *)
      &Teensy41_QS2_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[5] = (sysRanDType *)
      &Teensy41_QS2_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = (sysRanDType *)&Teensy41_QS2_DW.QS2_SubsysRanBC;
    systemRan[10] = (sysRanDType *)&Teensy41_QS2_DW.QS2_SubsysRanBC;
    systemRan[11] = (sysRanDType *)&Teensy41_QS2_DW.QS2_SubsysRanBC;
    systemRan[12] = (sysRanDType *)&Teensy41_QS2_DW.QS2_SubsysRanBC;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Teensy41_QS2_M->extModeInfo,
      &Teensy41_QS2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Teensy41_QS2_M->extModeInfo,
                        Teensy41_QS2_M->Sizes.checksums);
    rteiSetTPtr(Teensy41_QS2_M->extModeInfo, rtmGetTPtr(Teensy41_QS2_M));
  }

  {
    real_T tmp;
    uint8_T tmp_0;

    /* Start for RateTransition generated from: '<S4>/QS2' */
    Teensy41_QS2_B.TmpRTBAtQS2Inport2 =
      Teensy41_QS2_P.TmpRTBAtQS2Inport2_InitialCondi;
    Teensy41_QS2_PrevZCX.TriggeredSubsystem_Trig_ZCE = UNINITIALIZED_ZCSIG;
    Teensy41_QS2_PrevZCX.QS2_Trig_ZCE = UNINITIALIZED_ZCSIG;

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay1' */
    Teensy41_QS2_DW.UnitDelay1_DSTATE =
      Teensy41_QS2_P.UnitDelay1_InitialCondition;

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
    Teensy41_QS2_DW.UnitDelay_DSTATE = Teensy41_QS2_P.UnitDelay_InitialCondition;

    /* InitializeConditions for RateTransition generated from: '<S4>/QS2' */
    Teensy41_QS2_DW.TmpRTBAtQS2Inport2_Buffer0 =
      Teensy41_QS2_P.TmpRTBAtQS2Inport2_InitialCondi;

    /* InitializeConditions for DiscreteIntegrator: '<S44>/Integrator' */
    Teensy41_QS2_DW.Integrator_DSTATE =
      Teensy41_QS2_P.PIDController1_InitialConditi_m;
    Teensy41_QS2_DW.Integrator_PrevResetState = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S39>/Filter' */
    Teensy41_QS2_DW.Filter_DSTATE =
      Teensy41_QS2_P.PIDController1_InitialCondition;
    Teensy41_QS2_DW.Filter_PrevResetState = 2;

    /* SystemInitialize for Gain: '<S5>/Gain' incorporates:
     *  Outport: '<S5>/Vm'
     */
    Teensy41_QS2_B.Gain_b5 = Teensy41_QS2_P.Vm_Y0;

    /* End of SystemInitialize for SubSystem: '<S1>/Triggered Subsystem' */
    /* End of SystemInitialize for SubSystem: '<Root>/Controller' */

    /* SystemInitialize for Triggered SubSystem: '<S4>/QS2' */
    /* SystemInitialize for MATLAB Function: '<S119>/MATLAB Function1' */
    Teensy41_QS2_DW.count_startup = 1.0;
    Teensy41_QS2_DW.count_stop = 1.0;

    /* Start for MATLABSystem: '<S119>/SPI WriteRead' */
    Teensy41_QS2_DW.obj.matlabCodegenIsDeleted = false;
    Teensy41_QS2_DW.obj.slaveSelectPin_ =
      Teensy41_QS2_P.SPIWriteRead_slaveSelectPin_;
    Teensy41_QS2_DW.obj.isInitialized = 1;
    tmp = rt_roundd_snf(Teensy41_QS2_DW.obj.slaveSelectPin_);
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
    Teensy41_QS2_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S119>/SPI WriteRead' */

    /* SystemInitialize for Outport: '<S119>/encoder0' */
    Teensy41_QS2_B.encoder0 = Teensy41_QS2_P.encoder0_Y0;

    /* SystemInitialize for Outport: '<S119>/encoder1' */
    Teensy41_QS2_B.encoder1 = Teensy41_QS2_P.encoder1_Y0;

    /* End of SystemInitialize for SubSystem: '<S4>/QS2' */

    /* Enable for Atomic SubSystem: '<Root>/Controller' */
    /* Enable for Triggered SubSystem: '<S1>/Triggered Subsystem' */
    Teensy41_QS2_DW.TriggeredSubsystem_RESET_ELAPS_ = true;

    /* Enable for DiscreteIntegrator: '<S44>/Integrator' */
    Teensy41_QS2_DW.Integrator_SYSTEM_ENABLE = 1U;

    /* Enable for DiscreteIntegrator: '<S39>/Filter' */
    Teensy41_QS2_DW.Filter_SYSTEM_ENABLE = 1U;

    /* End of Enable for SubSystem: '<S1>/Triggered Subsystem' */
    /* End of Enable for SubSystem: '<Root>/Controller' */
  }
}

/* Model terminate function */
void Teensy41_QS2_terminate(void)
{
  /* Terminate for Triggered SubSystem: '<S4>/QS2' */
  /* Terminate for MATLABSystem: '<S119>/SPI WriteRead' */
  if (!Teensy41_QS2_DW.obj.matlabCodegenIsDeleted) {
    Teensy41_QS2_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S119>/SPI WriteRead' */
  /* End of Terminate for SubSystem: '<S4>/QS2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
