%%
fprintf('\n Now compiling all the code for c-mex s-functions\n');
currFolder = pwd;
cd code
delete '*.mex*'
cd c_code

mex AirWaterCoolerPTF.c AirWaterCoolerPTF_wrapper.c GetHTCoeffHTX.c GetAirViscosity.c GetThdynCombGasZach.c GetAirDensity.c GetAirThermalConduct.c GetCompCombGas_rtwutil.c rt_nonfinite.c rtGetInf.c rtGetNAN.c -outdir ..
mex blower.c blower_wrapper.c GetThdynCombGasZach.c -outdir ..
mex combState.c combState_wrapper.c -outdir ..
mex CombWiebe.c CombWiebe_wrapper.c -outdir ..
mex compressor_calc_PTF.c compressor_calc_PTF_wrapper.c GetThdynCombGasZach.c -outdir ..
mex crankMechKinematic.c crankMechKinematic_wrapper.c -outdir ..
mex EngCylHeatTransfer.c EngCylHeatTransfer_wrapper.c -outdir ..
mex EngCylHeatTransferSSTune.c EngCylHeatTransferSSTune_wrapper.c -outdir ..
mex EngineControlSystem.c -outdir ..
mex GetExhVVArea.c GetExhVVArea_wrapper.c -outdir ..
mex GetIntakeVVArea.c GetIntakeVVArea_wrapper.c -outdir ..
mex GetExhVVLift.c GetExhVVLift_wrapper.c -outdir ..
mex GetVVLift.c GetVVLift_wrapper.c -outdir ..
mex GetInportArea.c GetInportArea_wrapper.c -outdir ..
mex hysterisis.c hysterisis_wrapper.c -outdir ..
mex IdealNozzlePTF.c IdealNozzlePTF_wrapper.c GetThdynCombGasZach.c GetIdealNozzleFlow.c GetCompCombGas_rtwutil.c rt_nonfinite.c rtGetInf.c rtGetNAN.c -outdir ..
mex interpolateDescend.c interpolateDescend_wrapper.c -outdir ..
mex lowPassFilterBW4.c lowPassFilterBW4_wrapper.c -outdir ..
mex pCompCalc.c pCompCalc_wrapper.c -outdir ..
mex pMaxFinder.c pMaxFinder_wrapper.c -outdir ..
mex SpeedController.c -outdir ..
mex ThdynCV.c ThdynCV_wrapper.c GetPTF.c GetThdynCombGasZach.c -outdir ..
mex ThdynCVNV.c GetPTF.c GetThdynCombGasZach.c -outdir ..
mex turbine_calc_PTF.c turbine_calc_PTF_wrapper.c GetThdynCombGasZach.c -outdir ..
mex turbine_calc_MV_PTF.c turbine_calc_MV_PTF_wrapper.c GetThdynCombGasZach.c -outdir ..
mex InCylinderMV.c InCylinderMV_wrapper.c GetThdynCombGasZach.c -outdir ..
cd(currFolder);