/*
 * File: CombGasZach.c
 *
 *
  *
  *   --- THIS FILE GENERATED BY S-FUNCTION BUILDER: 3.0 ---
  *
  *   This file is an S-function produced by the S-Function
  *   Builder which only recognizes certain fields.  Changes made
  *   outside these fields will be lost the next time the block is
  *   used to load, edit, and resave this file. This file will be overwritten
  *   by the S-function Builder block. If you want to edit this file by hand, 
  *   you must change it only in the area defined as:  
  *
  *        %%%-SFUNWIZ_defines_Changes_BEGIN
  *        #define NAME 'replacement text' 
  *        %%% SFUNWIZ_defines_Changes_END
  *
  *   DO NOT change NAME--Change the 'replacement text' only.
  *
  *   For better compatibility with the Simulink Coder, the
  *   "wrapper" S-function technique is used.  This is discussed
  *   in the Simulink Coder's Manual in the Chapter titled,
  *   "Wrapper S-functions".
  *
  *  -------------------------------------------------------------------------
  * | See matlabroot/simulink/src/sfuntmpl_doc.c for a more detailed template |
  *  ------------------------------------------------------------------------- 
 * Created: Thu Sep 18 11:33:31 2014
 * 
 *
 */

#define S_FUNCTION_LEVEL 2
#define S_FUNCTION_NAME CombGasZach
/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
/* %%%-SFUNWIZ_defines_Changes_BEGIN --- EDIT HERE TO _END */
#define NUM_INPUTS          3
/* Input Port  0 */
#define IN_PORT_0_NAME      p
#define INPUT_0_WIDTH       1
#define INPUT_DIMS_0_COL    1
#define INPUT_0_DTYPE       real_T
#define INPUT_0_COMPLEX     COMPLEX_NO
#define IN_0_FRAME_BASED    FRAME_NO
#define IN_0_BUS_BASED      0
#define IN_0_BUS_NAME       
#define IN_0_DIMS           1-D
#define INPUT_0_FEEDTHROUGH 1
#define IN_0_ISSIGNED        0
#define IN_0_WORDLENGTH      8
#define IN_0_FIXPOINTSCALING 1
#define IN_0_FRACTIONLENGTH  9
#define IN_0_BIAS            0
#define IN_0_SLOPE           0.125
/* Input Port  1 */
#define IN_PORT_1_NAME      T
#define INPUT_1_WIDTH       1
#define INPUT_DIMS_1_COL    1
#define INPUT_1_DTYPE       real_T
#define INPUT_1_COMPLEX     COMPLEX_NO
#define IN_1_FRAME_BASED    FRAME_NO
#define IN_1_BUS_BASED      0
#define IN_1_BUS_NAME       
#define IN_1_DIMS           1-D
#define INPUT_1_FEEDTHROUGH 1
#define IN_1_ISSIGNED        0
#define IN_1_WORDLENGTH      8
#define IN_1_FIXPOINTSCALING 1
#define IN_1_FRACTIONLENGTH  9
#define IN_1_BIAS            0
#define IN_1_SLOPE           0.125
/* Input Port  2 */
#define IN_PORT_2_NAME      F
#define INPUT_2_WIDTH       1
#define INPUT_DIMS_2_COL    1
#define INPUT_2_DTYPE       real_T
#define INPUT_2_COMPLEX     COMPLEX_NO
#define IN_2_FRAME_BASED    FRAME_NO
#define IN_2_BUS_BASED      0
#define IN_2_BUS_NAME       
#define IN_2_DIMS           1-D
#define INPUT_2_FEEDTHROUGH 1
#define IN_2_ISSIGNED        0
#define IN_2_WORDLENGTH      8
#define IN_2_FIXPOINTSCALING 1
#define IN_2_FRACTIONLENGTH  9
#define IN_2_BIAS            0
#define IN_2_SLOPE           0.125

#define NUM_OUTPUTS          13
/* Output Port  0 */
#define OUT_PORT_0_NAME      R
#define OUTPUT_0_WIDTH       1
#define OUTPUT_DIMS_0_COL    1
#define OUTPUT_0_DTYPE       real_T
#define OUTPUT_0_COMPLEX     COMPLEX_NO
#define OUT_0_FRAME_BASED    FRAME_NO
#define OUT_0_BUS_BASED      0
#define OUT_0_BUS_NAME       
#define OUT_0_DIMS           1-D
#define OUT_0_ISSIGNED        1
#define OUT_0_WORDLENGTH      8
#define OUT_0_FIXPOINTSCALING 1
#define OUT_0_FRACTIONLENGTH  3
#define OUT_0_BIAS            0
#define OUT_0_SLOPE           0.125
/* Output Port  1 */
#define OUT_PORT_1_NAME      h
#define OUTPUT_1_WIDTH       1
#define OUTPUT_DIMS_1_COL    1
#define OUTPUT_1_DTYPE       real_T
#define OUTPUT_1_COMPLEX     COMPLEX_NO
#define OUT_1_FRAME_BASED    FRAME_NO
#define OUT_1_BUS_BASED      0
#define OUT_1_BUS_NAME       
#define OUT_1_DIMS           1-D
#define OUT_1_ISSIGNED        1
#define OUT_1_WORDLENGTH      8
#define OUT_1_FIXPOINTSCALING 1
#define OUT_1_FRACTIONLENGTH  3
#define OUT_1_BIAS            0
#define OUT_1_SLOPE           0.125
/* Output Port  2 */
#define OUT_PORT_2_NAME      s
#define OUTPUT_2_WIDTH       1
#define OUTPUT_DIMS_2_COL    1
#define OUTPUT_2_DTYPE       real_T
#define OUTPUT_2_COMPLEX     COMPLEX_NO
#define OUT_2_FRAME_BASED    FRAME_NO
#define OUT_2_BUS_BASED      0
#define OUT_2_BUS_NAME       
#define OUT_2_DIMS           1-D
#define OUT_2_ISSIGNED        1
#define OUT_2_WORDLENGTH      8
#define OUT_2_FIXPOINTSCALING 1
#define OUT_2_FRACTIONLENGTH  3
#define OUT_2_BIAS            0
#define OUT_2_SLOPE           0.125
/* Output Port  3 */
#define OUT_PORT_3_NAME      u
#define OUTPUT_3_WIDTH       1
#define OUTPUT_DIMS_3_COL    1
#define OUTPUT_3_DTYPE       real_T
#define OUTPUT_3_COMPLEX     COMPLEX_NO
#define OUT_3_FRAME_BASED    FRAME_NO
#define OUT_3_BUS_BASED      0
#define OUT_3_BUS_NAME       
#define OUT_3_DIMS           1-D
#define OUT_3_ISSIGNED        1
#define OUT_3_WORDLENGTH      8
#define OUT_3_FIXPOINTSCALING 1
#define OUT_3_FRACTIONLENGTH  3
#define OUT_3_BIAS            0
#define OUT_3_SLOPE           0.125
/* Output Port  4 */
#define OUT_PORT_4_NAME      RF
#define OUTPUT_4_WIDTH       1
#define OUTPUT_DIMS_4_COL    1
#define OUTPUT_4_DTYPE       real_T
#define OUTPUT_4_COMPLEX     COMPLEX_NO
#define OUT_4_FRAME_BASED    FRAME_NO
#define OUT_4_BUS_BASED      0
#define OUT_4_BUS_NAME       
#define OUT_4_DIMS           1-D
#define OUT_4_ISSIGNED        1
#define OUT_4_WORDLENGTH      8
#define OUT_4_FIXPOINTSCALING 1
#define OUT_4_FRACTIONLENGTH  3
#define OUT_4_BIAS            0
#define OUT_4_SLOPE           0.125
/* Output Port  5 */
#define OUT_PORT_5_NAME      RP
#define OUTPUT_5_WIDTH       1
#define OUTPUT_DIMS_5_COL    1
#define OUTPUT_5_DTYPE       real_T
#define OUTPUT_5_COMPLEX     COMPLEX_NO
#define OUT_5_FRAME_BASED    FRAME_NO
#define OUT_5_BUS_BASED      0
#define OUT_5_BUS_NAME       
#define OUT_5_DIMS           1-D
#define OUT_5_ISSIGNED        1
#define OUT_5_WORDLENGTH      8
#define OUT_5_FIXPOINTSCALING 1
#define OUT_5_FRACTIONLENGTH  3
#define OUT_5_BIAS            0
#define OUT_5_SLOPE           0.125
/* Output Port  6 */
#define OUT_PORT_6_NAME      RT
#define OUTPUT_6_WIDTH       1
#define OUTPUT_DIMS_6_COL    1
#define OUTPUT_6_DTYPE       real_T
#define OUTPUT_6_COMPLEX     COMPLEX_NO
#define OUT_6_FRAME_BASED    FRAME_NO
#define OUT_6_BUS_BASED      0
#define OUT_6_BUS_NAME       
#define OUT_6_DIMS           1-D
#define OUT_6_ISSIGNED        1
#define OUT_6_WORDLENGTH      8
#define OUT_6_FIXPOINTSCALING 1
#define OUT_6_FRACTIONLENGTH  3
#define OUT_6_BIAS            0
#define OUT_6_SLOPE           0.125
/* Output Port  7 */
#define OUT_PORT_7_NAME      uF
#define OUTPUT_7_WIDTH       1
#define OUTPUT_DIMS_7_COL    1
#define OUTPUT_7_DTYPE       real_T
#define OUTPUT_7_COMPLEX     COMPLEX_NO
#define OUT_7_FRAME_BASED    FRAME_NO
#define OUT_7_BUS_BASED      0
#define OUT_7_BUS_NAME       
#define OUT_7_DIMS           1-D
#define OUT_7_ISSIGNED        1
#define OUT_7_WORDLENGTH      8
#define OUT_7_FIXPOINTSCALING 1
#define OUT_7_FRACTIONLENGTH  3
#define OUT_7_BIAS            0
#define OUT_7_SLOPE           0.125
/* Output Port  8 */
#define OUT_PORT_8_NAME      uP
#define OUTPUT_8_WIDTH       1
#define OUTPUT_DIMS_8_COL    1
#define OUTPUT_8_DTYPE       real_T
#define OUTPUT_8_COMPLEX     COMPLEX_NO
#define OUT_8_FRAME_BASED    FRAME_NO
#define OUT_8_BUS_BASED      0
#define OUT_8_BUS_NAME       
#define OUT_8_DIMS           1-D
#define OUT_8_ISSIGNED        1
#define OUT_8_WORDLENGTH      8
#define OUT_8_FIXPOINTSCALING 1
#define OUT_8_FRACTIONLENGTH  3
#define OUT_8_BIAS            0
#define OUT_8_SLOPE           0.125
/* Output Port  9 */
#define OUT_PORT_9_NAME      uT
#define OUTPUT_9_WIDTH       1
#define OUTPUT_DIMS_9_COL    1
#define OUTPUT_9_DTYPE       real_T
#define OUTPUT_9_COMPLEX     COMPLEX_NO
#define OUT_9_FRAME_BASED    FRAME_NO
#define OUT_9_BUS_BASED      0
#define OUT_9_BUS_NAME       
#define OUT_9_DIMS           1-D
#define OUT_9_ISSIGNED        1
#define OUT_9_WORDLENGTH      8
#define OUT_9_FIXPOINTSCALING 1
#define OUT_9_FRACTIONLENGTH  3
#define OUT_9_BIAS            0
#define OUT_9_SLOPE           0.125
/* Output Port  10 */
#define OUT_PORT_10_NAME      Cp
#define OUTPUT_10_WIDTH       1
#define OUTPUT_DIMS_10_COL    1
#define OUTPUT_10_DTYPE       real_T
#define OUTPUT_10_COMPLEX     COMPLEX_NO
#define OUT_10_FRAME_BASED    FRAME_NO
#define OUT_10_BUS_BASED      0
#define OUT_10_BUS_NAME       
#define OUT_10_DIMS           1-D
#define OUT_10_ISSIGNED        1
#define OUT_10_WORDLENGTH      8
#define OUT_10_FIXPOINTSCALING 1
#define OUT_10_FRACTIONLENGTH  3
#define OUT_10_BIAS            0
#define OUT_10_SLOPE           0.125
/* Output Port  11 */
#define OUT_PORT_11_NAME      Cv
#define OUTPUT_11_WIDTH       1
#define OUTPUT_DIMS_11_COL    1
#define OUTPUT_11_DTYPE       real_T
#define OUTPUT_11_COMPLEX     COMPLEX_NO
#define OUT_11_FRAME_BASED    FRAME_NO
#define OUT_11_BUS_BASED      0
#define OUT_11_BUS_NAME       
#define OUT_11_DIMS           1-D
#define OUT_11_ISSIGNED        1
#define OUT_11_WORDLENGTH      8
#define OUT_11_FIXPOINTSCALING 1
#define OUT_11_FRACTIONLENGTH  3
#define OUT_11_BIAS            0
#define OUT_11_SLOPE           0.125
/* Output Port  12 */
#define OUT_PORT_12_NAME      K
#define OUTPUT_12_WIDTH       1
#define OUTPUT_DIMS_12_COL    1
#define OUTPUT_12_DTYPE       real_T
#define OUTPUT_12_COMPLEX     COMPLEX_NO
#define OUT_12_FRAME_BASED    FRAME_NO
#define OUT_12_BUS_BASED      0
#define OUT_12_BUS_NAME       
#define OUT_12_DIMS           1-D
#define OUT_12_ISSIGNED        1
#define OUT_12_WORDLENGTH      8
#define OUT_12_FIXPOINTSCALING 1
#define OUT_12_FRACTIONLENGTH  3
#define OUT_12_BIAS            0
#define OUT_12_SLOPE           0.125

#define NPARAMS              0

#define SAMPLE_TIME_0        INHERITED_SAMPLE_TIME
#define NUM_DISC_STATES      0
#define DISC_STATES_IC       [0]
#define NUM_CONT_STATES      0
#define CONT_STATES_IC       [0]

#define SFUNWIZ_GENERATE_TLC 1
#define SOURCEFILES "__SFB__GetThdynCombGasZach1.c"
#define PANELINDEX           6
#define USE_SIMSTRUCT        0
#define SHOW_COMPILE_STEPS   0                   
#define CREATE_DEBUG_MEXFILE 0
#define SAVE_CODE_ONLY       0
#define SFUNWIZ_REVISION     3.0
/* %%%-SFUNWIZ_defines_Changes_END --- EDIT HERE TO _BEGIN */
/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
#include "simstruc.h"

extern void CombGasZach_Outputs_wrapper(const real_T *p,
                          const real_T *T,
                          const real_T *F,
                          real_T *R,
                          real_T *h,
                          real_T *s,
                          real_T *u,
                          real_T *RF,
                          real_T *RP,
                          real_T *RT,
                          real_T *uF,
                          real_T *uP,
                          real_T *uT,
                          real_T *Cp,
                          real_T *Cv,
                          real_T *K);

/*====================*
 * S-function methods *
 *====================*/
/* Function: mdlInitializeSizes ===============================================
 * Abstract:
 *   Setup sizes of the various vectors.
 */
static void mdlInitializeSizes(SimStruct *S)
{

    DECL_AND_INIT_DIMSINFO(inputDimsInfo);
    DECL_AND_INIT_DIMSINFO(outputDimsInfo);
    ssSetNumSFcnParams(S, NPARAMS);
     if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
	 return; /* Parameter mismatch will be reported by Simulink */
     }

    ssSetNumContStates(S, NUM_CONT_STATES);
    ssSetNumDiscStates(S, NUM_DISC_STATES);

    if (!ssSetNumInputPorts(S, NUM_INPUTS)) return;
    /*Input Port 0 */
    ssSetInputPortWidth(S,  0, INPUT_0_WIDTH); /* */
    ssSetInputPortDataType(S, 0, SS_DOUBLE);
    ssSetInputPortComplexSignal(S,  0, INPUT_0_COMPLEX);
    ssSetInputPortDirectFeedThrough(S, 0, INPUT_0_FEEDTHROUGH);
    ssSetInputPortRequiredContiguous(S, 0, 1); /*direct input signal access*/

    /*Input Port 1 */
    ssSetInputPortWidth(S,  1, INPUT_1_WIDTH); /* */
    ssSetInputPortDataType(S, 1, SS_DOUBLE);
    ssSetInputPortComplexSignal(S,  1, INPUT_1_COMPLEX);
    ssSetInputPortDirectFeedThrough(S, 1, INPUT_1_FEEDTHROUGH);
    ssSetInputPortRequiredContiguous(S, 1, 1); /*direct input signal access*/

    /*Input Port 2 */
    ssSetInputPortWidth(S,  2, INPUT_2_WIDTH); /* */
    ssSetInputPortDataType(S, 2, SS_DOUBLE);
    ssSetInputPortComplexSignal(S,  2, INPUT_2_COMPLEX);
    ssSetInputPortDirectFeedThrough(S, 2, INPUT_2_FEEDTHROUGH);
    ssSetInputPortRequiredContiguous(S, 2, 1); /*direct input signal access*/


    if (!ssSetNumOutputPorts(S, NUM_OUTPUTS)) return;
    /* Output Port 0 */
    ssSetOutputPortWidth(S, 0, OUTPUT_0_WIDTH);
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 0, OUTPUT_0_COMPLEX);
    /* Output Port 1 */
    ssSetOutputPortWidth(S, 1, OUTPUT_1_WIDTH);
    ssSetOutputPortDataType(S, 1, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 1, OUTPUT_1_COMPLEX);
    /* Output Port 2 */
    ssSetOutputPortWidth(S, 2, OUTPUT_2_WIDTH);
    ssSetOutputPortDataType(S, 2, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 2, OUTPUT_2_COMPLEX);
    /* Output Port 3 */
    ssSetOutputPortWidth(S, 3, OUTPUT_3_WIDTH);
    ssSetOutputPortDataType(S, 3, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 3, OUTPUT_3_COMPLEX);
    /* Output Port 4 */
    ssSetOutputPortWidth(S, 4, OUTPUT_4_WIDTH);
    ssSetOutputPortDataType(S, 4, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 4, OUTPUT_4_COMPLEX);
    /* Output Port 5 */
    ssSetOutputPortWidth(S, 5, OUTPUT_5_WIDTH);
    ssSetOutputPortDataType(S, 5, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 5, OUTPUT_5_COMPLEX);
    /* Output Port 6 */
    ssSetOutputPortWidth(S, 6, OUTPUT_6_WIDTH);
    ssSetOutputPortDataType(S, 6, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 6, OUTPUT_6_COMPLEX);
    /* Output Port 7 */
    ssSetOutputPortWidth(S, 7, OUTPUT_7_WIDTH);
    ssSetOutputPortDataType(S, 7, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 7, OUTPUT_7_COMPLEX);
    /* Output Port 8 */
    ssSetOutputPortWidth(S, 8, OUTPUT_8_WIDTH);
    ssSetOutputPortDataType(S, 8, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 8, OUTPUT_8_COMPLEX);
    /* Output Port 9 */
    ssSetOutputPortWidth(S, 9, OUTPUT_9_WIDTH);
    ssSetOutputPortDataType(S, 9, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 9, OUTPUT_9_COMPLEX);
    /* Output Port 10 */
    ssSetOutputPortWidth(S, 10, OUTPUT_10_WIDTH);
    ssSetOutputPortDataType(S, 10, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 10, OUTPUT_10_COMPLEX);
    /* Output Port 11 */
    ssSetOutputPortWidth(S, 11, OUTPUT_11_WIDTH);
    ssSetOutputPortDataType(S, 11, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 11, OUTPUT_11_COMPLEX);
    /* Output Port 12 */
    ssSetOutputPortWidth(S, 12, OUTPUT_12_WIDTH);
    ssSetOutputPortDataType(S, 12, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 12, OUTPUT_12_COMPLEX);

    ssSetNumSampleTimes(S, 1);
    ssSetNumRWork(S, 0);
    ssSetNumIWork(S, 0);
    ssSetNumPWork(S, 0);
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);

    /* Take care when specifying exception free code - see sfuntmpl_doc.c */
    ssSetOptions(S, (SS_OPTION_EXCEPTION_FREE_CODE |
                     SS_OPTION_USE_TLC_WITH_ACCELERATOR | 
		     SS_OPTION_WORKS_WITH_CODE_REUSE));
}

# define MDL_SET_INPUT_PORT_FRAME_DATA
static void mdlSetInputPortFrameData(SimStruct  *S, 
                                     int_T      port,
                                     Frame_T    frameData)
{
    ssSetInputPortFrameData(S, port, frameData);
}
/* Function: mdlInitializeSampleTimes =========================================
 * Abstract:
 *    Specifiy  the sample time.
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, SAMPLE_TIME_0);
    ssSetOffsetTime(S, 0, 0.0);
}

#define MDL_SET_INPUT_PORT_DATA_TYPE
static void mdlSetInputPortDataType(SimStruct *S, int port, DTypeId dType)
{
    ssSetInputPortDataType( S, 0, dType);
}
#define MDL_SET_OUTPUT_PORT_DATA_TYPE
static void mdlSetOutputPortDataType(SimStruct *S, int port, DTypeId dType)
{
    ssSetOutputPortDataType(S, 0, dType);
}

#define MDL_SET_DEFAULT_PORT_DATA_TYPES
static void mdlSetDefaultPortDataTypes(SimStruct *S)
{
  ssSetInputPortDataType( S, 0, SS_DOUBLE);
 ssSetOutputPortDataType(S, 0, SS_DOUBLE);
}
/* Function: mdlOutputs =======================================================
 *
*/
static void mdlOutputs(SimStruct *S, int_T tid)
{
    const real_T   *p  = (const real_T*) ssGetInputPortSignal(S,0);
    const real_T   *T  = (const real_T*) ssGetInputPortSignal(S,1);
    const real_T   *F  = (const real_T*) ssGetInputPortSignal(S,2);
    real_T        *R  = (real_T *)ssGetOutputPortRealSignal(S,0);
    real_T        *h  = (real_T *)ssGetOutputPortRealSignal(S,1);
    real_T        *s  = (real_T *)ssGetOutputPortRealSignal(S,2);
    real_T        *u  = (real_T *)ssGetOutputPortRealSignal(S,3);
    real_T        *RF  = (real_T *)ssGetOutputPortRealSignal(S,4);
    real_T        *RP  = (real_T *)ssGetOutputPortRealSignal(S,5);
    real_T        *RT  = (real_T *)ssGetOutputPortRealSignal(S,6);
    real_T        *uF  = (real_T *)ssGetOutputPortRealSignal(S,7);
    real_T        *uP  = (real_T *)ssGetOutputPortRealSignal(S,8);
    real_T        *uT  = (real_T *)ssGetOutputPortRealSignal(S,9);
    real_T        *Cp  = (real_T *)ssGetOutputPortRealSignal(S,10);
    real_T        *Cv  = (real_T *)ssGetOutputPortRealSignal(S,11);
    real_T        *K  = (real_T *)ssGetOutputPortRealSignal(S,12);

    CombGasZach_Outputs_wrapper(p, T, F, R, h, s, u, RF, RP, RT, uF, uP, uT, Cp, Cv, K);
}



/* Function: mdlTerminate =====================================================
 * Abstract:
 *    In this function, you should perform any actions that are necessary
 *    at the termination of a simulation.  For example, if memory was
 *    allocated in mdlStart, this is the place to free it.
 */
static void mdlTerminate(SimStruct *S)
{
}
#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif


