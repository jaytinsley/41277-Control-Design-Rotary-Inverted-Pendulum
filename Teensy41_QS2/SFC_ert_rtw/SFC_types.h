/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SFC_types.h
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

#ifndef SFC_types_h_
#define SFC_types_h_
#include "rtwtypes.h"
#ifndef struct_tag_Dgc2TRVrL59PoNFLix7UcE
#define struct_tag_Dgc2TRVrL59PoNFLix7UcE

struct tag_Dgc2TRVrL59PoNFLix7UcE
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_Dgc2TRVrL59PoNFLix7UcE */

#ifndef typedef_c_arduinodriver_ArduinoSPI_SF_T
#define typedef_c_arduinodriver_ArduinoSPI_SF_T

typedef struct tag_Dgc2TRVrL59PoNFLix7UcE c_arduinodriver_ArduinoSPI_SF_T;

#endif                             /* typedef_c_arduinodriver_ArduinoSPI_SF_T */

#ifndef struct_tag_zHYKd6eVDXgY5o2Fkt87RC
#define struct_tag_zHYKd6eVDXgY5o2Fkt87RC

struct tag_zHYKd6eVDXgY5o2Fkt87RC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T slaveSelectPin_;
  c_arduinodriver_ArduinoSPI_SF_T SPIDriverObj;
};

#endif                                 /* struct_tag_zHYKd6eVDXgY5o2Fkt87RC */

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_zHYKd6eVDXgY5o2Fkt87RC codertarget_arduinobase_inter_T;

#endif                             /* typedef_codertarget_arduinobase_inter_T */

/* Parameters (default storage) */
typedef struct P_SFC_T_ P_SFC_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_SFC_T RT_MODEL_SFC_T;

#endif                                 /* SFC_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
