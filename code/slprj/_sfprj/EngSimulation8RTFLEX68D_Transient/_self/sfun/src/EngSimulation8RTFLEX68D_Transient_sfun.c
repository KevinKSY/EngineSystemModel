/* Include files */

#include "EngSimulation8RTFLEX68D_Transient_sfun.h"
#include "EngSimulation8RTFLEX68D_Transient_sfun_debug_macros.h"
#include "c2_EngSimulation8RTFLEX68D_Transient.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _EngSimulation8RTFLEX68D_TransientMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void EngSimulation8RTFLEX68D_Transient_initializer(void)
{
}

void EngSimulation8RTFLEX68D_Transient_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_EngSimulation8RTFLEX68D_Transient_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==2) {
    c2_EngSimulation8RTFLEX68D_Transient_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  return 0;
}

unsigned int sf_EngSimulation8RTFLEX68D_Transient_process_check_sum_call( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2133684097U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(483232803U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3405248279U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(95529574U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(823720221U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1987567067U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3321917622U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2841810811U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 2:
        {
          extern void sf_c2_EngSimulation8RTFLEX68D_Transient_get_check_sum
            (mxArray *plhs[]);
          sf_c2_EngSimulation8RTFLEX68D_Transient_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3671716505U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(761638822U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(966005375U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2739926485U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1727881997U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1391704003U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(475778959U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(130350019U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_EngSimulation8RTFLEX68D_Transient_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        if (strcmp(aiChksum, "MQ4WjKjekZ8ESAnRCQh7nG") == 0) {
          extern mxArray
            *sf_c2_EngSimulation8RTFLEX68D_Transient_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c2_EngSimulation8RTFLEX68D_Transient_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int
  sf_EngSimulation8RTFLEX68D_Transient_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        extern const mxArray
          *sf_c2_EngSimulation8RTFLEX68D_Transient_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_EngSimulation8RTFLEX68D_Transient_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_EngSimulation8RTFLEX68D_Transient_third_party_uses_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        if (strcmp(tpChksum, "wwpMjQaf5YlF2hTmsWTirF") == 0) {
          extern mxArray
            *sf_c2_EngSimulation8RTFLEX68D_Transient_third_party_uses_info(void);
          plhs[0] =
            sf_c2_EngSimulation8RTFLEX68D_Transient_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void EngSimulation8RTFLEX68D_Transient_debug_initialize(struct
  SfDebugInstanceStruct* debugInstance)
{
  _EngSimulation8RTFLEX68D_TransientMachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"EngSimulation8RTFLEX68D_Transient","sfun",0,1,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _EngSimulation8RTFLEX68D_TransientMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _EngSimulation8RTFLEX68D_TransientMachineNumber_,0);
}

void EngSimulation8RTFLEX68D_Transient_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_EngSimulation8RTFLEX68D_Transient_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "EngSimulation8RTFLEX68D_Transient", "EngSimulation8RTFLEX68D_Transient");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_EngSimulation8RTFLEX68D_Transient_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
