/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Teensy41_QS2.h
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

#ifndef Teensy41_QS2_h_
#define Teensy41_QS2_h_
#ifndef Teensy41_QS2_COMMON_INCLUDES_
#define Teensy41_QS2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SPIwriteRead.h"
#endif                                 /* Teensy41_QS2_COMMON_INCLUDES_ */

#include "Teensy41_QS2_types.h"
#include "multiword_types.h"
#include "rt_zcfcn.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  uint8_T uv[17];
  uint8_T data_out[17];
  uint64m_T r;
  real_T Gain;                         /* '<S3>/Gain' */
  real_T Gain_b;                       /* '<S2>/Gain' */
  real_T alpha_rad;                    /* '<S4>/alpha' */
  real_T encoder0;                     /* '<S117>/MATLAB Function' */
  real_T encoder1;                     /* '<S117>/MATLAB Function' */
  real_T y;                            /* '<S4>/MATLAB Function1' */
  real_T y_b;                          /* '<S4>/MATLAB Function' */
  real_T Sum;                          /* '<S5>/Sum' */
  real_T R_LED;
  real_T PulseGenerator1_a;            /* '<S1>/Pulse Generator1' */
  real_T UdiffTsProdOut;               /* '<S91>/Udiff*Ts Prod Out' */
  boolean_T TmpRTBAtQS2Inport2;
} B_Teensy41_QS2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S117>/SPI WriteRead' */
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<Root>/Unit Delay1' */
  real_T Filter_DSTATE;                /* '<S37>/Filter' */
  real_T UD_DSTATE;                    /* '<S89>/UD' */
  real_T RateTransition2_Buffer;       /* '<S4>/Rate Transition2' */
  real_T count_startup;                /* '<S117>/MATLAB Function1' */
  real_T count_stop;                   /* '<S117>/MATLAB Function1' */
  int32_T clockTickCounter;            /* '<S4>/Pulse Generator1' */
  int32_T clockTickCounter_p;          /* '<S1>/Pulse Generator1' */
  int8_T QS2_SubsysRanBC;              /* '<S4>/QS2' */
  int8_T TriggeredSubsystem_SubsysRanBC;/* '<S1>/Triggered Subsystem' */
  boolean_T TmpRTBAtQS2Inport2_Buffer0;/* synthesized block */
  boolean_T stop;                      /* '<S117>/MATLAB Function1' */
} DW_Teensy41_QS2_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState QS2_Trig_ZCE;             /* '<S4>/QS2' */
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S1>/Triggered Subsystem' */
} PrevZCX_Teensy41_QS2_T;

/* Parameters (default storage) */
struct P_Teensy41_QS2_T_ {
  real_T ts;                           /* Variable: ts
                                        * Referenced by:
                                        *   '<S4>/Step'
                                        *   '<S4>/Step1'
                                        */
  real_T PIDController1_D;             /* Mask Parameter: PIDController1_D
                                        * Referenced by: '<S35>/Derivative Gain'
                                        */
  real_T PIDController2_D;             /* Mask Parameter: PIDController2_D
                                        * Referenced by: '<S87>/Derivative Gain'
                                        */
  real_T PIDController2_DifferentiatorIC;
                              /* Mask Parameter: PIDController2_DifferentiatorIC
                               * Referenced by: '<S89>/UD'
                               */
  real_T PIDController1_InitialCondition;
                              /* Mask Parameter: PIDController1_InitialCondition
                               * Referenced by: '<S37>/Filter'
                               */
  real_T PIDController1_N;             /* Mask Parameter: PIDController1_N
                                        * Referenced by: '<S45>/Filter Coefficient'
                                        */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S47>/Proportional Gain'
                                        */
  real_T PIDController2_P;             /* Mask Parameter: PIDController2_P
                                        * Referenced by: '<S101>/Proportional Gain'
                                        */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S114>/Constant'
                                       */
  real_T Vm_Y0;                        /* Computed Parameter: Vm_Y0
                                        * Referenced by: '<S5>/Vm'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S37>/Filter'
                                        */
  real_T Gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T PulseGenerator1_Amp;          /* Expression: 1
                                        * Referenced by: '<S1>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period;   /* Computed Parameter: PulseGenerator1_Period
                                    * Referenced by: '<S1>/Pulse Generator1'
                                    */
  real_T PulseGenerator1_Duty;       /* Computed Parameter: PulseGenerator1_Duty
                                      * Referenced by: '<S1>/Pulse Generator1'
                                      */
  real_T PulseGenerator1_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<S1>/Pulse Generator1'
                                        */
  real_T SPIWriteRead_slaveSelectPin_; /* Expression: 10
                                        * Referenced by: '<S117>/SPI WriteRead'
                                        */
  real_T encoder0_Y0;                  /* Computed Parameter: encoder0_Y0
                                        * Referenced by: '<S117>/encoder0'
                                        */
  real_T encoder1_Y0;                  /* Computed Parameter: encoder1_Y0
                                        * Referenced by: '<S117>/encoder1'
                                        */
  real_T u0V_UpperSat;                 /* Expression: 10
                                        * Referenced by: '<S117>/+- 10V'
                                        */
  real_T u0V_LowerSat;                 /* Expression: -10
                                        * Referenced by: '<S117>/+- 10V'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay1'
                                        */
  real_T RED_Value;                    /* Expression: 0
                                        * Referenced by: '<Root>/RED'
                                        */
  real_T GREEN_Value;                  /* Expression: 1
                                        * Referenced by: '<Root>/GREEN'
                                        */
  real_T BLUE_Value;                   /* Expression: 0
                                        * Referenced by: '<Root>/BLUE'
                                        */
  real_T Reset_manual_Value;           /* Expression: 0
                                        * Referenced by: '<S4>/Reset_manual'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S4>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * Referenced by: '<S4>/Step'
                                        */
  real_T Step1_Y0;                     /* Expression: 0
                                        * Referenced by: '<S4>/Step1'
                                        */
  real_T Step1_YFinal;                 /* Expression: -1
                                        * Referenced by: '<S4>/Step1'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T PulseGenerator1_Amp_p;        /* Expression: 1
                                        * Referenced by: '<S4>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period_k;
                                 /* Computed Parameter: PulseGenerator1_Period_k
                                  * Referenced by: '<S4>/Pulse Generator1'
                                  */
  real_T PulseGenerator1_Duty_m;   /* Computed Parameter: PulseGenerator1_Duty_m
                                    * Referenced by: '<S4>/Pulse Generator1'
                                    */
  real_T PulseGenerator1_PhaseDelay_m; /* Expression: 0
                                        * Referenced by: '<S4>/Pulse Generator1'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 180/pi
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 180/pi
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T MotorEnable_Value;            /* Expression: 1
                                        * Referenced by: '<Root>/Motor Enable'
                                        */
  real_T Protection_Value;             /* Expression: 1
                                        * Referenced by: '<Root>/Protection'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 180/pi
                                        * Referenced by: '<S118>/Gain'
                                        */
  boolean_T TmpRTBAtQS2Inport2_InitialCondi;
                          /* Computed Parameter: TmpRTBAtQS2Inport2_InitialCondi
                           * Referenced by:
                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_Teensy41_QS2_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Teensy41_QS2_T Teensy41_QS2_P;

/* Block signals (default storage) */
extern B_Teensy41_QS2_T Teensy41_QS2_B;

/* Block states (default storage) */
extern DW_Teensy41_QS2_T Teensy41_QS2_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_Teensy41_QS2_T Teensy41_QS2_PrevZCX;

/* External function called from main */
extern void Teensy41_QS2_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Teensy41_QS2_initialize(void);
extern void Teensy41_QS2_step0(void);  /* Sample time: [0.0005s, 0.0s] */
extern void Teensy41_QS2_step1(void);  /* Sample time: [0.001s, 0.0s] */
extern void Teensy41_QS2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Teensy41_QS2_T *const Teensy41_QS2_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S89>/DTDup' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Teensy41_QS2'
 * '<S1>'   : 'Teensy41_QS2/Controller'
 * '<S2>'   : 'Teensy41_QS2/Radians to Degrees'
 * '<S3>'   : 'Teensy41_QS2/Radians to Degrees1'
 * '<S4>'   : 'Teensy41_QS2/System:    QS2      '
 * '<S5>'   : 'Teensy41_QS2/Controller/Triggered Subsystem'
 * '<S6>'   : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1'
 * '<S7>'   : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2'
 * '<S8>'   : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Anti-windup'
 * '<S9>'   : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/D Gain'
 * '<S10>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/External Derivative'
 * '<S11>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Filter'
 * '<S12>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Filter ICs'
 * '<S13>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/I Gain'
 * '<S14>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Ideal P Gain'
 * '<S15>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Ideal P Gain Fdbk'
 * '<S16>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Integrator'
 * '<S17>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Integrator ICs'
 * '<S18>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/N Copy'
 * '<S19>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/N Gain'
 * '<S20>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/P Copy'
 * '<S21>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Parallel P Gain'
 * '<S22>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Reset Signal'
 * '<S23>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Saturation'
 * '<S24>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Saturation Fdbk'
 * '<S25>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Sum'
 * '<S26>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Sum Fdbk'
 * '<S27>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Tracking Mode'
 * '<S28>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Tracking Mode Sum'
 * '<S29>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Tsamp - Integral'
 * '<S30>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Tsamp - Ngain'
 * '<S31>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/postSat Signal'
 * '<S32>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/preInt Signal'
 * '<S33>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/preSat Signal'
 * '<S34>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Anti-windup/Disabled'
 * '<S35>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/D Gain/Internal Parameters'
 * '<S36>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/External Derivative/Error'
 * '<S37>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S38>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S39>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/I Gain/Disabled'
 * '<S40>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Ideal P Gain/Passthrough'
 * '<S41>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S42>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Integrator/Disabled'
 * '<S43>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Integrator ICs/Disabled'
 * '<S44>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/N Copy/Disabled'
 * '<S45>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/N Gain/Internal Parameters'
 * '<S46>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/P Copy/Disabled'
 * '<S47>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S48>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Reset Signal/Disabled'
 * '<S49>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Saturation/Passthrough'
 * '<S50>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Saturation Fdbk/Disabled'
 * '<S51>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Sum/Sum_PD'
 * '<S52>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Sum Fdbk/Disabled'
 * '<S53>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Tracking Mode/Disabled'
 * '<S54>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S55>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Tsamp - Integral/Disabled'
 * '<S56>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/Tsamp - Ngain/External Ts'
 * '<S57>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/postSat Signal/Forward_Path'
 * '<S58>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/preInt Signal/Internal PreInt'
 * '<S59>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller1/preSat Signal/Forward_Path'
 * '<S60>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Anti-windup'
 * '<S61>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/D Gain'
 * '<S62>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/External Derivative'
 * '<S63>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Filter'
 * '<S64>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Filter ICs'
 * '<S65>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/I Gain'
 * '<S66>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Ideal P Gain'
 * '<S67>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Ideal P Gain Fdbk'
 * '<S68>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Integrator'
 * '<S69>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Integrator ICs'
 * '<S70>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/N Copy'
 * '<S71>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/N Gain'
 * '<S72>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/P Copy'
 * '<S73>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Parallel P Gain'
 * '<S74>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Reset Signal'
 * '<S75>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Saturation'
 * '<S76>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Saturation Fdbk'
 * '<S77>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Sum'
 * '<S78>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Sum Fdbk'
 * '<S79>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Tracking Mode'
 * '<S80>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Tracking Mode Sum'
 * '<S81>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Tsamp - Integral'
 * '<S82>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Tsamp - Ngain'
 * '<S83>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/postSat Signal'
 * '<S84>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/preInt Signal'
 * '<S85>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/preSat Signal'
 * '<S86>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Anti-windup/Disabled'
 * '<S87>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/D Gain/Internal Parameters'
 * '<S88>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/External Derivative/Error'
 * '<S89>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Filter/Differentiator'
 * '<S90>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Filter/Differentiator/Tsamp'
 * '<S91>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Filter/Differentiator/Tsamp/External Ts'
 * '<S92>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Filter ICs/Internal IC - Differentiator'
 * '<S93>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/I Gain/Disabled'
 * '<S94>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Ideal P Gain/Passthrough'
 * '<S95>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S96>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Integrator/Disabled'
 * '<S97>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Integrator ICs/Disabled'
 * '<S98>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S99>'  : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/N Gain/Passthrough'
 * '<S100>' : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/P Copy/Disabled'
 * '<S101>' : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S102>' : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Reset Signal/Disabled'
 * '<S103>' : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Saturation/Passthrough'
 * '<S104>' : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Saturation Fdbk/Disabled'
 * '<S105>' : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Sum/Sum_PD'
 * '<S106>' : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Sum Fdbk/Disabled'
 * '<S107>' : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Tracking Mode/Disabled'
 * '<S108>' : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S109>' : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Tsamp - Integral/Disabled'
 * '<S110>' : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S111>' : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/postSat Signal/Forward_Path'
 * '<S112>' : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/preInt Signal/Internal PreInt'
 * '<S113>' : 'Teensy41_QS2/Controller/Triggered Subsystem/PID Controller2/preSat Signal/Forward_Path'
 * '<S114>' : 'Teensy41_QS2/System:    QS2      /Compare To Constant'
 * '<S115>' : 'Teensy41_QS2/System:    QS2      /MATLAB Function'
 * '<S116>' : 'Teensy41_QS2/System:    QS2      /MATLAB Function1'
 * '<S117>' : 'Teensy41_QS2/System:    QS2      /QS2'
 * '<S118>' : 'Teensy41_QS2/System:    QS2      /Radians to Degrees'
 * '<S119>' : 'Teensy41_QS2/System:    QS2      /alpha'
 * '<S120>' : 'Teensy41_QS2/System:    QS2      /theta'
 * '<S121>' : 'Teensy41_QS2/System:    QS2      /QS2/MATLAB Function'
 * '<S122>' : 'Teensy41_QS2/System:    QS2      /QS2/MATLAB Function1'
 */
#endif                                 /* Teensy41_QS2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
