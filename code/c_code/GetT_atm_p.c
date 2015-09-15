/*
 * File: GetT_atm_p.c
 *
 * MATLAB Coder version            : 2.7
 * C/C++ source code generated on  : 14-Sep-2015 17:04:06
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "GetAirDensity.h"
#include "GetAirThermalConduct.h"
#include "GetAirViscosity.h"
#include "GetCompCombGas.h"
#include "GetCorrAirComp.h"
#include "GetDensityHCVapor.h"
#include "GetDiffusivityHCVaporToAir.h"
#include "GetEquilGrill.h"
#include "GetEquilOlikara.h"
#include "GetFuelPropertyN_Dodecane.h"
#include "GetHTCoeffHTX.h"
#include "GetIdealNozzleFlow.h"
#include "GetIdealNozzleFlowPTF.h"
#include "GetMEMbZach.h"
#include "GetPTF.h"
#include "GetPTFV1.h"
#include "GetPTx.h"
#include "GetTFromPhF.h"
#include "GetT_atm_p.h"
#include "GetThdynCombGasZach.h"
#include "GetThdynCombGasZachV1.h"
#include "GetThermalPropertyHCVaporReal.h"
#include "GetThermoDynProp.h"
#include "GetThermoDynPropPartial.h"
#include "GetTotalStaticPT.h"
#include "GetViscosityHCVapor.h"

/* Function Definitions */

/*
 * Calculate the temperature from given enthalpy, F for atmospheric pressure
 *
 *    The calculation of the internal energy is based on the NASA 7
 *    coefficient polynomial and T is found by using Newton-Raphson method.
 *    The gas is assumed to be idea gas.
 *
 *    Input
 *
 *    Output
 *        T : Temperature (K)
 *
 *  Created by Kevin Koosup Yum on 14 March 2014
 * Arguments    : double h
 *                double F
 *                double T_prev
 * Return Type  : double
 */
double GetT_atm_p(double h, double F, double T_prev)
{
  double T;
  double dT;
  double T_err;
  double unusedUa;
  double unusedU9;
  double Cp;
  double unusedU8;
  double unusedU7;
  double unusedU6;
  double unusedU5;
  double unusedU4;
  double unusedU3;
  double unusedU2;
  double unusedU1;

  /* % Check for valid inputs */
  /* % Calculate the temperature */
  T = T_prev;
  dT = 0.0;
  T_err = 1.0;
  while (T_err > 0.0001) {
    T -= dT;
    GetThdynCombGasZach(100000.0, T, F, &dT, &T_err, &unusedU1, &unusedU2,
                        &unusedU3, &unusedU4, &unusedU5, &unusedU6, &unusedU7,
                        &unusedU8, &Cp, &unusedU9, &unusedUa);
    dT = (T_err - h) / Cp;
    T_err = fabs(dT) / T;
  }

  return T;
}

/*
 * File trailer for GetT_atm_p.c
 *
 * [EOF]
 */
