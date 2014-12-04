/*
 * File: GetVVLift.c
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
 * Created: Sat Jul 19 10:05:31 2014
 * 
 *
 */

#define S_FUNCTION_LEVEL 2
#define S_FUNCTION_NAME GetVVLift
/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
/* %%%-SFUNWIZ_defines_Changes_BEGIN --- EDIT HERE TO _END */
#define NUM_INPUTS          3
/* Input Port  0 */
#define IN_PORT_0_NAME      phi
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
#define IN_PORT_1_NAME      cAStartNom
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
#define IN_PORT_2_NAME      dCALiftNom
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

#define NUM_OUTPUTS          1
/* Output Port  0 */
#define OUT_PORT_0_NAME      lift
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

#define NPARAMS              10
/* Parameter  1 */
#define PARAMETER_0_NAME      nStroke
#define PARAMETER_0_DTYPE     real_T
#define PARAMETER_0_COMPLEX   COMPLEX_NO
/* Parameter  2 */
#define PARAMETER_1_NAME      liftMax
#define PARAMETER_1_DTYPE     real_T
#define PARAMETER_1_COMPLEX   COMPLEX_NO
/* Parameter  3 */
#define PARAMETER_2_NAME      cAStartRef
#define PARAMETER_2_DTYPE     real_T
#define PARAMETER_2_COMPLEX   COMPLEX_NO
/* Parameter  4 */
#define PARAMETER_3_NAME      dCALiftUp
#define PARAMETER_3_DTYPE     real_T
#define PARAMETER_3_COMPLEX   COMPLEX_NO
/* Parameter  5 */
#define PARAMETER_4_NAME      dCALiftDown
#define PARAMETER_4_DTYPE     real_T
#define PARAMETER_4_COMPLEX   COMPLEX_NO
/* Parameter  6 */
#define PARAMETER_5_NAME      dCALiftTopRef
#define PARAMETER_5_DTYPE     real_T
#define PARAMETER_5_COMPLEX   COMPLEX_NO
/* Parameter  7 */
#define PARAMETER_6_NAME      cAVVUpRef
#define PARAMETER_6_DTYPE     real_T
#define PARAMETER_6_COMPLEX   COMPLEX_NO
/* Parameter  8 */
#define PARAMETER_7_NAME      cAVVDownRef
#define PARAMETER_7_DTYPE     real_T
#define PARAMETER_7_COMPLEX   COMPLEX_NO
/* Parameter  9 */
#define PARAMETER_8_NAME      liftUpRef
#define PARAMETER_8_DTYPE     real_T
#define PARAMETER_8_COMPLEX   COMPLEX_NO
/* Parameter  9 */
#define PARAMETER_9_NAME      liftDownRef
#define PARAMETER_9_DTYPE     real_T
#define PARAMETER_9_COMPLEX   COMPLEX_NO

#define NDWORKS              1
// DWork 1
#define DWORK_0_NAME         exhVVOpen
#define DWORK_0_WIDTH        1
#define DWORK_0_DTYPE        real_T
#define DWORK_0_COMPLEX      COMPLEX_NO

#define SAMPLE_TIME_0        INHERITED_SAMPLE_TIME
#define NUM_DISC_STATES      0
#define DISC_STATES_IC       [0]
#define NUM_CONT_STATES      0
#define CONT_STATES_IC       [0]

#define SFUNWIZ_GENERATE_TLC 1
#define SOURCEFILES "__SFB__"
#define PANELINDEX           6
#define USE_SIMSTRUCT        0
#define SHOW_COMPILE_STEPS   0                   
#define CREATE_DEBUG_MEXFILE 0
#define SAVE_CODE_ONLY       0
#define SFUNWIZ_REVISION     3.0
/* %%%-SFUNWIZ_defines_Changes_END --- EDIT HERE TO _BEGIN */
/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
#include "simstruc.h"
#define PARAM_DEF0(S) ssGetSFcnParam(S, 0)
#define PARAM_DEF1(S) ssGetSFcnParam(S, 1)
#define PARAM_DEF2(S) ssGetSFcnParam(S, 2)
#define PARAM_DEF3(S) ssGetSFcnParam(S, 3)
#define PARAM_DEF4(S) ssGetSFcnParam(S, 4)
#define PARAM_DEF5(S) ssGetSFcnParam(S, 5)
#define PARAM_DEF6(S) ssGetSFcnParam(S, 6)
#define PARAM_DEF7(S) ssGetSFcnParam(S, 7)
#define PARAM_DEF8(S) ssGetSFcnParam(S, 8)
#define PARAM_DEF9(S) ssGetSFcnParam(S, 9)

#define IS_PARAM_DOUBLE(pVal) (mxIsNumeric(pVal) && !mxIsLogical(pVal) &&\
!mxIsEmpty(pVal) && !mxIsSparse(pVal) && !mxIsComplex(pVal) && mxIsDouble(pVal))
#define IS_PARAM_INT8(pVal) (mxIsNumeric(pVal) && !mxIsLogical(pVal) &&\
!mxIsEmpty(pVal) && !mxIsSparse(pVal) && !mxIsComplex(pVal) && mxIsInt8(pVal))

extern void GetExhVVLift_Outputs_wrapper(const real_T *phi,
                          const real_T *cAStartNom,
                          const real_T *dCALiftNom,
                          real_T *lift  , 
                          const real_T *nStroke, const int_T p_width0,
                          const real_T  *liftMax, const int_T  p_width1, 
                          const real_T  *cAStartRef, const int_T  p_width2, 
                          const real_T  *dCALiftUp, const int_T  p_width3, 
                          const real_T  *dCALiftDown, const int_T  p_width4, 
                          const real_T  *dCALiftTopRef, const int_T  p_width5, 
                          const real_T  *cAVVUpRef, const int_T  p_width6, 
                          const real_T  *cAVVDownRef, const int_T  p_width7, 
                          const real_T  *liftUpRef, const int_T  p_width8, 
                          const real_T  *liftDownRef,  const int_T p_width9);

/*====================*
 * S-function methods *
 *====================*/
#define MDL_CHECK_PARAMETERS
 #if defined(MDL_CHECK_PARAMETERS) && defined(MATLAB_MEX_FILE)
   /* Function: mdlCheckParameters =============================================
     * Abstract:
     *    Validate our parameters to verify they are okay.
     */
    static void mdlCheckParameters(SimStruct *S)
    {
     int paramIndex  = 0;
     bool validParam = false;
     /* All parameters must match the S-function Builder Dialog */
     

	 {
	  const mxArray *pVal0 = ssGetSFcnParam(S,0);
	  if (!IS_PARAM_DOUBLE(pVal0)) {
	    validParam = true;
	    paramIndex = 0;
	    goto EXIT_POINT;
	  }
	 }

	 {
	  const mxArray *pVal1 = ssGetSFcnParam(S,1);
	  if (!IS_PARAM_DOUBLE(pVal1)) {
	    validParam = true;
	    paramIndex = 1;
	    goto EXIT_POINT;
	  }
	 }

	 {
	  const mxArray *pVal2 = ssGetSFcnParam(S,2);
	  if (!IS_PARAM_DOUBLE(pVal2)) {
	    validParam = true;
	    paramIndex = 2;
	    goto EXIT_POINT;
	  }
	 }

	 {
	  const mxArray *pVal3 = ssGetSFcnParam(S,3);
	  if (!IS_PARAM_DOUBLE(pVal3)) {
	    validParam = true;
	    paramIndex = 3;
	    goto EXIT_POINT;
	  }
	 }

	 {
	  const mxArray *pVal4 = ssGetSFcnParam(S,4);
	  if (!IS_PARAM_DOUBLE(pVal4)) {
	    validParam = true;
	    paramIndex = 4;
	    goto EXIT_POINT;
	  }
	 }

	 {
	  const mxArray *pVal5 = ssGetSFcnParam(S,5);
	  if (!IS_PARAM_DOUBLE(pVal5)) {
	    validParam = true;
	    paramIndex = 5;
	    goto EXIT_POINT;
	  }
	 }

	 {
	  const mxArray *pVal6 = ssGetSFcnParam(S,6);
	  if (!IS_PARAM_DOUBLE(pVal6)) {
	    validParam = true;
	    paramIndex = 6;
	    goto EXIT_POINT;
	  }
	 }

	 {
	  const mxArray *pVal7 = ssGetSFcnParam(S,7);
	  if (!IS_PARAM_DOUBLE(pVal7)) {
	    validParam = true;
	    paramIndex = 7;
	    goto EXIT_POINT;
	  }
	 }

	 {
	  const mxArray *pVal8 = ssGetSFcnParam(S,8);
	  if (!IS_PARAM_DOUBLE(pVal8)) {
	    validParam = true;
	    paramIndex = 8;
	    goto EXIT_POINT;
	  }
	 }

	 {
	  const mxArray *pVal9 = ssGetSFcnParam(S,9);
	  if (!IS_PARAM_DOUBLE(pVal9)) {
	    validParam = true;
	    paramIndex = 9;
	    goto EXIT_POINT;
	  }
	 }
     
     EXIT_POINT:
      if (validParam) {
          char parameterErrorMsg[1024];
          sprintf(parameterErrorMsg, "The data type and or complexity of parameter  %d does not match the "
                  "information specified in the S-function Builder dialog. "
                  "For non-double parameters you will need to cast them using int8, int16, "
                  "int32, uint8, uint16, uint32 or boolean.", paramIndex + 1);
	  ssSetErrorStatus(S,parameterErrorMsg);
      }
	return;
    }
 #endif /* MDL_CHECK_PARAMETERS */
/* Function: mdlInitializeSizes ===============================================
 * Abstract:
 *   Setup sizes of the various vectors.
 */
static void mdlInitializeSizes(SimStruct *S)
{

    DECL_AND_INIT_DIMSINFO(inputDimsInfo);
    DECL_AND_INIT_DIMSINFO(outputDimsInfo);
    ssSetNumSFcnParams(S, NPARAMS);  /* Number of expected parameters */
      #if defined(MATLAB_MEX_FILE)
	if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {
	  mdlCheckParameters(S);
	  if (ssGetErrorStatus(S) != NULL) {
	    return;
	  }
	 } else {
	   return; /* Parameter mismatch will be reported by Simulink */
	 }
      #endif

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
    ssSetOutputPortWidth(S, 0, OUTPUT_0_WIDTH);
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 0, OUTPUT_0_COMPLEX);
    ssSetNumSampleTimes(S, 1);
    ssSetNumRWork(S, 0);
    ssSetNumIWork(S, 0);
    ssSetNumPWork(S, 0);
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);

    /*initialzation of sizes related to DWork Vectors*/
    ssSetNumDWork(S,NDWORKS);
    /*DWork vector 1*/
    ssSetDWorkWidth(S, 0, DWORK_0_WIDTH);
    ssSetDWorkDataType(S, 0, SS_BOOLEAN);
    
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

#define MDL_INITIALIZE_CONDITIONS
 /* Function: mdlInitializeConditions ========================================
  * Abstract:
  *    Initialize the states
  */
 static void mdlInitializeConditions(SimStruct *S)
 {
   #define MDL_INITIALIZE_CONDITIONS
/* Function: mdlInitializeConditions ============================
* Abstract:
* Initialize both continuous states to zero
*/
    int_T *exhVVOpen = (int_T *) ssGetDWork(S,0);

    /* Initialize the dwork to 0 */
    exhVVOpen[0] = 0;  // Valve open (1-open/0-close)
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
    const real_T   *phi  = (const real_T*) ssGetInputPortSignal(S,0);
    const real_T   *cAStartNom  = (const real_T*) ssGetInputPortSignal(S,1);
    const real_T   *dCALiftNom  = (const real_T*) ssGetInputPortSignal(S,2);
    real_T        *lift  = (real_T *)ssGetOutputPortRealSignal(S,0);
    const int_T   p_width0  = mxGetNumberOfElements(PARAM_DEF0(S));
    const int_T   p_width1  = mxGetNumberOfElements(PARAM_DEF1(S));
    const int_T   p_width2  = mxGetNumberOfElements(PARAM_DEF2(S));
    const int_T   p_width3  = mxGetNumberOfElements(PARAM_DEF3(S));
    const int_T   p_width4  = mxGetNumberOfElements(PARAM_DEF4(S));
    const int_T   p_width5  = mxGetNumberOfElements(PARAM_DEF5(S));
    const int_T   p_width6  = mxGetNumberOfElements(PARAM_DEF6(S));
    const int_T   p_width7  = mxGetNumberOfElements(PARAM_DEF7(S));
    const int_T   p_width8  = mxGetNumberOfElements(PARAM_DEF8(S));
    const int_T   p_width9  = mxGetNumberOfElements(PARAM_DEF9(S));
    const real_T  *nStroke  = (const real_T *)mxGetData(PARAM_DEF0(S));
    const real_T  *liftMax  = (const real_T *)mxGetData(PARAM_DEF1(S));
    const real_T  *cAStartRef  = (const real_T *)mxGetData(PARAM_DEF2(S));
    const real_T  *dCALiftUp  = (const real_T *)mxGetData(PARAM_DEF3(S));
    const real_T  *dCALiftDown  = (const real_T *)mxGetData(PARAM_DEF4(S));
    const real_T  *dCALiftTopRef  = (const real_T *)mxGetData(PARAM_DEF5(S));
    const real_T  *cAVVUpRef  = (const real_T *)mxGetData(PARAM_DEF6(S));
    const real_T  *cAVVDownRef  = (const real_T *)mxGetData(PARAM_DEF7(S));
    const real_T  *liftUpRef  = (const real_T *)mxGetData(PARAM_DEF8(S));
    const real_T  *liftDownRef  = (const real_T *)mxGetData(PARAM_DEF9(S));

    GetVVLift_Outputs_wrapper(phi, cAStartNom, dCALiftNom, lift, nStroke, p_width0, liftMax, p_width1, cAStartRef, p_width2, dCALiftUp, p_width3, dCALiftDown, p_width4, dCALiftTopRef, p_width5, cAVVUpRef, p_width6, cAVVDownRef, p_width7, liftUpRef, p_width8, liftDownRef, p_width9);
}

#define MDL_UPDATE  /* Change to #undef to remove function */
/* Function: mdlUpdate ======================================================
   * Abstract:
   *    This function is called once for every major integration time step.
   *    Discrete states are typically updated here, but this function is useful
   *    for performing any tasks that should only take place once per
   *    integration step.
   */
  static void mdlUpdate(SimStruct *S, int_T tid)
  {
    const real_T  *lift  = (const real_T *)ssGetOutputPortRealSignal(S,0);
    int_T *exhVVOpen = (int_T *)ssGetDWork(S,0);
    
    if (exhVVOpen[0] > 0) {
        exhVVOpen[0] = 1;
    }
    else {
        exhVVOpen[0] = 0;
    }
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


