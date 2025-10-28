/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SFC.h
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

#ifndef SFC_h_
#define SFC_h_
#ifndef SFC_COMMON_INCLUDES_
#define SFC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SPIwriteRead.h"
#endif                                 /* SFC_COMMON_INCLUDES_ */

#include "SFC_types.h"
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
  real_T TmpRTBAtControllerInport1[4]; /* '<Root>/Luenberger Observer' */
  real_T UnitDelay[4];                 /* '<S2>/Unit Delay' */
  uint8_T uv[17];
  uint8_T data_out[17];
  uint64m_T r;
  real_T Gain;                         /* '<S4>/Gain' */
  real_T Gain_b;                       /* '<S3>/Gain' */
  real_T alpha_rad;                    /* '<S5>/alpha' */
  real_T encoder0;                     /* '<S10>/MATLAB Function' */
  real_T encoder1;                     /* '<S10>/MATLAB Function' */
  real_T y;                            /* '<S5>/MATLAB Function1' */
  real_T y_m;                          /* '<S5>/MATLAB Function' */
  real_T TmpRTBAtTriggeredSubsystemInpor;/* '<S1>/Sum' */
  real_T Gain2;                        /* '<S6>/Gain2' */
  real_T R_LED;
  real_T b_y;
  real_T PulseGenerator1_a;            /* '<S1>/Pulse Generator1' */
  boolean_T TmpRTBAtQS2Inport2;
} B_SFC_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S10>/SPI WriteRead' */
  real_T UnitDelay_DSTATE[4];          /* '<S2>/Unit Delay' */
  real_T TmpRTBAtControllerInport1_Buffe[4];/* synthesized block */
  real_T theta_rad_Buffer[2];          /* synthesized block */
  real_T RateTransition2_Buffer;       /* '<S5>/Rate Transition2' */
  real_T TmpRTBAtDdmatrixInport1_Buffer;/* synthesized block */
  real_T Vm_Buffer;                    /* synthesized block */
  real_T count_startup;                /* '<S10>/MATLAB Function1' */
  real_T count_stop;                   /* '<S10>/MATLAB Function1' */
  real_T TmpRTBAtTriggeredSubsystemInpor;/* synthesized block */
  int32_T clockTickCounter;            /* '<S5>/Pulse Generator1' */
  int32_T clockTickCounter_p;          /* '<S1>/Pulse Generator1' */
  int32_T clockTickCounter_g;          /* '<S1>/Pulse Generator2' */
  int8_T QS2_SubsysRanBC;              /* '<S5>/QS2' */
  int8_T TriggeredSubsystem_SubsysRanBC;/* '<S1>/Triggered Subsystem' */
  boolean_T TmpRTBAtQS2Inport2_Buffer0;/* synthesized block */
  boolean_T stop;                      /* '<S10>/MATLAB Function1' */
} DW_SFC_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState QS2_Trig_ZCE;             /* '<S5>/QS2' */
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S1>/Triggered Subsystem' */
} PrevZCX_SFC_T;

/* Parameters (default storage) */
struct P_SFC_T_ {
  real_T A[16];                        /* Variable: A
                                        * Referenced by: '<S2>/Ad matrix'
                                        */
  real_T B[4];                         /* Variable: B
                                        * Referenced by: '<S2>/Bd matrix'
                                        */
  real_T C[8];                         /* Variable: C
                                        * Referenced by: '<S2>/Cd matrix'
                                        */
  real_T D[2];                         /* Variable: D
                                        * Referenced by: '<S2>/Dd matrix'
                                        */
  real_T L[8];                         /* Variable: L
                                        * Referenced by: '<S2>/Ld matrix'
                                        */
  real_T ts;                           /* Variable: ts
                                        * Referenced by:
                                        *   '<S5>/Step'
                                        *   '<S5>/Step1'
                                        */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S7>/Constant'
                                       */
  real_T LuenbergerObserver_x0[4];     /* Mask Parameter: LuenbergerObserver_x0
                                        * Referenced by: '<S2>/Unit Delay'
                                        */
  real_T Vm_Y0;                        /* Computed Parameter: Vm_Y0
                                        * Referenced by: '<S6>/Vm'
                                        */
  real_T Gain_Gain;                    /* Expression:   -4.8658e-04
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T Gain1_Gain[4];   /* Expression: [-0.0005    0.0656   -0.0020    0.0034]
                           * Referenced by: '<S6>/Gain1'
                           */
  real_T Gain2_Gain;                   /* Expression: 1
                                        * Referenced by: '<S6>/Gain2'
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
  real_T TmpRTBAtTriggeredSubsystemInpor;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Constant_Value;               /* Expression: 0.5
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T PulseGenerator2_Amp;          /* Expression: 1
                                        * Referenced by: '<S1>/Pulse Generator2'
                                        */
  real_T PulseGenerator2_Period;   /* Computed Parameter: PulseGenerator2_Period
                                    * Referenced by: '<S1>/Pulse Generator2'
                                    */
  real_T PulseGenerator2_Duty;       /* Computed Parameter: PulseGenerator2_Duty
                                      * Referenced by: '<S1>/Pulse Generator2'
                                      */
  real_T PulseGenerator2_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<S1>/Pulse Generator2'
                                        */
  real_T SPIWriteRead_slaveSelectPin_; /* Expression: 10
                                        * Referenced by: '<S10>/SPI WriteRead'
                                        */
  real_T encoder0_Y0;                  /* Computed Parameter: encoder0_Y0
                                        * Referenced by: '<S10>/encoder0'
                                        */
  real_T encoder1_Y0;                  /* Computed Parameter: encoder1_Y0
                                        * Referenced by: '<S10>/encoder1'
                                        */
  real_T u0V_UpperSat;                 /* Expression: 10
                                        * Referenced by: '<S10>/+- 10V'
                                        */
  real_T u0V_LowerSat;                 /* Expression: -10
                                        * Referenced by: '<S10>/+- 10V'
                                        */
  real_T RED_Value;                    /* Expression: 0
                                        * Referenced by: '<Root>/RED'
                                        */
  real_T TmpRTBAtControllerInport1_Initi;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T GREEN_Value;                  /* Expression: 1
                                        * Referenced by: '<Root>/GREEN'
                                        */
  real_T BLUE_Value;                   /* Expression: 0
                                        * Referenced by: '<Root>/BLUE'
                                        */
  real_T Reset_manual_Value;           /* Expression: 0
                                        * Referenced by: '<S5>/Reset_manual'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S5>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * Referenced by: '<S5>/Step'
                                        */
  real_T Step1_Y0;                     /* Expression: 0
                                        * Referenced by: '<S5>/Step1'
                                        */
  real_T Step1_YFinal;                 /* Expression: -1
                                        * Referenced by: '<S5>/Step1'
                                        */
  real_T Constant_Value_p;             /* Expression: 0
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T PulseGenerator1_Amp_p;        /* Expression: 1
                                        * Referenced by: '<S5>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period_k;
                                 /* Computed Parameter: PulseGenerator1_Period_k
                                  * Referenced by: '<S5>/Pulse Generator1'
                                  */
  real_T PulseGenerator1_Duty_m;   /* Computed Parameter: PulseGenerator1_Duty_m
                                    * Referenced by: '<S5>/Pulse Generator1'
                                    */
  real_T PulseGenerator1_PhaseDelay_m; /* Expression: 0
                                        * Referenced by: '<S5>/Pulse Generator1'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 180/pi
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 180/pi
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T MotorEnable_Value;            /* Expression: 0
                                        * Referenced by: '<Root>/Motor Enable'
                                        */
  real_T Protection_Value;             /* Expression: 0
                                        * Referenced by: '<Root>/Protection'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 180/pi
                                        * Referenced by: '<S11>/Gain'
                                        */
  boolean_T TmpRTBAtQS2Inport2_InitialCondi;
                          /* Computed Parameter: TmpRTBAtQS2Inport2_InitialCondi
                           * Referenced by:
                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_SFC_T {
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
    uint32_T clockTick2;
    struct {
      uint16_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
      boolean_T TID0_2;
    } RateInteraction;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_SFC_T SFC_P;

/* Block signals (default storage) */
extern B_SFC_T SFC_B;

/* Block states (default storage) */
extern DW_SFC_T SFC_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_SFC_T SFC_PrevZCX;

/* External function called from main */
extern void SFC_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void SFC_initialize(void);
extern void SFC_step0(void);           /* Sample time: [0.0005s, 0.0s] */
extern void SFC_step1(void);           /* Sample time: [0.001s, 0.0s] */
extern void SFC_step2(void);           /* Sample time: [0.5s, 0.0s] */
extern void SFC_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SFC_T *const SFC_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'SFC'
 * '<S1>'   : 'SFC/Controller'
 * '<S2>'   : 'SFC/Luenberger Observer'
 * '<S3>'   : 'SFC/Radians to Degrees'
 * '<S4>'   : 'SFC/Radians to Degrees1'
 * '<S5>'   : 'SFC/System:    QS2      '
 * '<S6>'   : 'SFC/Controller/Triggered Subsystem'
 * '<S7>'   : 'SFC/System:    QS2      /Compare To Constant'
 * '<S8>'   : 'SFC/System:    QS2      /MATLAB Function'
 * '<S9>'   : 'SFC/System:    QS2      /MATLAB Function1'
 * '<S10>'  : 'SFC/System:    QS2      /QS2'
 * '<S11>'  : 'SFC/System:    QS2      /Radians to Degrees'
 * '<S12>'  : 'SFC/System:    QS2      /alpha'
 * '<S13>'  : 'SFC/System:    QS2      /theta'
 * '<S14>'  : 'SFC/System:    QS2      /QS2/MATLAB Function'
 * '<S15>'  : 'SFC/System:    QS2      /QS2/MATLAB Function1'
 */
#endif                                 /* SFC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
