/* Include files */

#include <stddef.h>
#include "blas.h"
#include "EngSimulation8RTFLEX68D_Transient_sfun.h"
#include "c1_EngSimulation8RTFLEX68D_Transient.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(NULL,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c1_EngSimulation8RTFLEX68D_Transient
  (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance);
static void initialize_params_c1_EngSimulation8RTFLEX68D_Transient
  (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance);
static void enable_c1_EngSimulation8RTFLEX68D_Transient
  (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance);
static void disable_c1_EngSimulation8RTFLEX68D_Transient
  (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_EngSimulation8RTFLEX68D_Transient
  (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance);
static void set_sim_state_c1_EngSimulation8RTFLEX68D_Transient
  (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance, const
   mxArray *c1_st);
static void finalize_c1_EngSimulation8RTFLEX68D_Transient
  (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance);
static void sf_c1_EngSimulation8RTFLEX68D_Transient
  (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance);
static void initSimStructsc1_EngSimulation8RTFLEX68D_Transient
  (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance);
static void registerMessagesc1_EngSimulation8RTFLEX68D_Transient
  (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static real_T c1_emlrt_marshallIn
  (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance, const
   mxArray *c1_Tq, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn
  (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static uint8_T c1_c_emlrt_marshallIn
  (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance, const
   mxArray *c1_b_is_active_c1_EngSimulation8RTFLEX68D_Transient, const char_T
   *c1_identifier);
static uint8_T c1_d_emlrt_marshallIn
  (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info
  (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_EngSimulation8RTFLEX68D_Transient
  (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_EngSimulation8RTFLEX68D_Transient = 0U;
}

static void initialize_params_c1_EngSimulation8RTFLEX68D_Transient
  (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance)
{
  real_T c1_dv0[3];
  int32_T c1_i0;
  sf_set_error_prefix_string(
    "Error evaluating data 'coeffProp' in the parent workspace.\n");
  sf_mex_import_named("coeffProp", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      c1_dv0, 0, 0, 0U, 1, 0U, 1, 3);
  for (c1_i0 = 0; c1_i0 < 3; c1_i0++) {
    chartInstance->c1_coeffProp[c1_i0] = c1_dv0[c1_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c1_EngSimulation8RTFLEX68D_Transient
  (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_EngSimulation8RTFLEX68D_Transient
  (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static const mxArray *get_sim_state_c1_EngSimulation8RTFLEX68D_Transient
  (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T *c1_Tq;
  c1_Tq = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(2), FALSE);
  c1_u = *c1_Tq;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_u = chartInstance->c1_is_active_c1_EngSimulation8RTFLEX68D_Transient;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_EngSimulation8RTFLEX68D_Transient
  (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance, const
   mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_Tq;
  c1_Tq = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_u = sf_mex_dup(c1_st);
  *c1_Tq = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
    "Tq");
  chartInstance->c1_is_active_c1_EngSimulation8RTFLEX68D_Transient =
    c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
    "is_active_c1_EngSimulation8RTFLEX68D_Transient");
  sf_mex_destroy(&c1_u);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_EngSimulation8RTFLEX68D_Transient
  (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance)
{
}

static void sf_c1_EngSimulation8RTFLEX68D_Transient
  (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance)
{
  real_T *c1_Tq;
  real_T *c1_omegaE;
  c1_Tq = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_omegaE = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c1_Tq = ((chartInstance->c1_coeffProp[0] * *c1_omegaE +
             chartInstance->c1_coeffProp[1]) * *c1_omegaE +
            chartInstance->c1_coeffProp[2]) * 1000.0;
}

static void initSimStructsc1_EngSimulation8RTFLEX68D_Transient
  (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance)
{
}

static void registerMessagesc1_EngSimulation8RTFLEX68D_Transient
  (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

const mxArray
  *sf_c1_EngSimulation8RTFLEX68D_Transient_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[1];
  c1_ResolvedFunctionInfo (*c1_b_info)[1];
  const mxArray *c1_m0 = NULL;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_b_info = (c1_ResolvedFunctionInfo (*)[1])c1_info;
  (*c1_b_info)[0].context = "";
  (*c1_b_info)[0].name = "mtimes";
  (*c1_b_info)[0].dominantType = "double";
  (*c1_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[0].fileTimeLo = 1289519692U;
  (*c1_b_info)[0].fileTimeHi = 0U;
  (*c1_b_info)[0].mFileTimeLo = 0U;
  (*c1_b_info)[0].mFileTimeHi = 0U;
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 1), FALSE);
  c1_r0 = &c1_info[0];
  sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15, 0U,
    0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo", 0);
  sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
    0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", 0);
  sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
    15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                  "nameCaptureInfo", 0);
  sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
    0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo", 0);
  sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo, 7,
    0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", 0);
  sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi, 7,
    0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", 0);
  sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo, 7,
    0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", 0);
  sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi, 7,
    0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", 0);
  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static real_T c1_emlrt_marshallIn
  (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance, const
   mxArray *c1_Tq, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Tq), &c1_thisId);
  sf_mex_destroy(&c1_Tq);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn
  (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static uint8_T c1_c_emlrt_marshallIn
  (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance, const
   mxArray *c1_b_is_active_c1_EngSimulation8RTFLEX68D_Transient, const char_T
   *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_EngSimulation8RTFLEX68D_Transient), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_EngSimulation8RTFLEX68D_Transient);
  return c1_y;
}

static uint8_T c1_d_emlrt_marshallIn
  (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info
  (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c1_EngSimulation8RTFLEX68D_Transient_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1869494703U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3275635540U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1714412211U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3972177968U);
}

mxArray *sf_c1_EngSimulation8RTFLEX68D_Transient_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("MEmeQLdLc1T9rRfgfJMYsD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_EngSimulation8RTFLEX68D_Transient_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c1_EngSimulation8RTFLEX68D_Transient
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Tq\",},{M[8],M[0],T\"is_active_c1_EngSimulation8RTFLEX68D_Transient\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_EngSimulation8RTFLEX68D_Transient_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "x4hXk3TVX6QpGs3DIBpTTB";
}

static void sf_opaque_initialize_c1_EngSimulation8RTFLEX68D_Transient(void
  *chartInstanceVar)
{
  initialize_params_c1_EngSimulation8RTFLEX68D_Transient
    ((SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct*) chartInstanceVar);
  initialize_c1_EngSimulation8RTFLEX68D_Transient
    ((SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_EngSimulation8RTFLEX68D_Transient(void
  *chartInstanceVar)
{
  enable_c1_EngSimulation8RTFLEX68D_Transient
    ((SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_EngSimulation8RTFLEX68D_Transient(void
  *chartInstanceVar)
{
  disable_c1_EngSimulation8RTFLEX68D_Transient
    ((SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_EngSimulation8RTFLEX68D_Transient(void
  *chartInstanceVar)
{
  sf_c1_EngSimulation8RTFLEX68D_Transient
    ((SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c1_EngSimulation8RTFLEX68D_Transient(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_EngSimulation8RTFLEX68D_Transient
    ((SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c1_EngSimulation8RTFLEX68D_Transient();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c1_EngSimulation8RTFLEX68D_Transient
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c1_EngSimulation8RTFLEX68D_Transient();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_EngSimulation8RTFLEX68D_Transient
    ((SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c1_EngSimulation8RTFLEX68D_Transient(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_EngSimulation8RTFLEX68D_Transient(S);
}

static void sf_opaque_set_sim_state_c1_EngSimulation8RTFLEX68D_Transient
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c1_EngSimulation8RTFLEX68D_Transient(S, st);
}

static void sf_opaque_terminate_c1_EngSimulation8RTFLEX68D_Transient(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_EngSimulation8RTFLEX68D_Transient_optimization_info();
    }

    finalize_c1_EngSimulation8RTFLEX68D_Transient
      ((SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_EngSimulation8RTFLEX68D_Transient
    ((SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_EngSimulation8RTFLEX68D_Transient(SimStruct *
  S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_EngSimulation8RTFLEX68D_Transient
      ((SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct*)(((ChartInfoStruct
          *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_EngSimulation8RTFLEX68D_Transient(SimStruct *S)
{
  /* Actual parameters from chart:
     coeffProp
   */
  const char_T *rtParamNames[] = { "coeffProp" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for coeffProp*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_EngSimulation8RTFLEX68D_Transient_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3829131373U));
  ssSetChecksum1(S,(2581724626U));
  ssSetChecksum2(S,(604074436U));
  ssSetChecksum3(S,(1488447160U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_EngSimulation8RTFLEX68D_Transient(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_EngSimulation8RTFLEX68D_Transient(SimStruct *S)
{
  SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *chartInstance;
  chartInstance = (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct *)
    utMalloc(sizeof(SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc1_EngSimulation8RTFLEX68D_TransientInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_EngSimulation8RTFLEX68D_Transient;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_EngSimulation8RTFLEX68D_Transient;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_EngSimulation8RTFLEX68D_Transient;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_EngSimulation8RTFLEX68D_Transient;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_EngSimulation8RTFLEX68D_Transient;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_EngSimulation8RTFLEX68D_Transient;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_EngSimulation8RTFLEX68D_Transient;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_EngSimulation8RTFLEX68D_Transient;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_EngSimulation8RTFLEX68D_Transient;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c1_EngSimulation8RTFLEX68D_Transient;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_EngSimulation8RTFLEX68D_Transient;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
}

void c1_EngSimulation8RTFLEX68D_Transient_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_EngSimulation8RTFLEX68D_Transient(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_EngSimulation8RTFLEX68D_Transient(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_EngSimulation8RTFLEX68D_Transient(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_EngSimulation8RTFLEX68D_Transient_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
