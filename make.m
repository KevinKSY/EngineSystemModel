cd C:\Users\yum\Documents\GitHub\EngineSystemModel
fprintf('\n Now compiling all the code for c-mex s-functions\n');
currFolder = pwd;
cd code
ans = '';
while ~(strcmp(ans,'y') || strcmp(ans,'n'))
    ans = input('Delete all the mex file? (y/n)','s');
end;
if (ans == 'y') 
    delete '*.mex*';
end;
cd c_code
%{
mex AirWaterCoolerPTF.c AirWaterCoolerPTF_wrapper.c GetHTCoeffHTX.c GetAirViscosity.c GetThdynCombGasZachV1.c GetAirDensity.c GetAirThermalConduct.c ThdynPack_rtwutil.c rt_nonfinite.c rtGetInf.c rtGetNAN.c -outdir ..
mex blower.c blower_wrapper.c GetThdynCombGasZachV1.c -outdir ..
mex blowerFit.c blowerFit_wrapper.c GetThdynCombGasZachV1.c -outdir ..
mex combState.c combState_wrapper.c -outdir ..
mex CombWiebe.c CombWiebe_wrapper.c -outdir ..
mex compressor_calc_PTF.c compressor_calc_PTF_wrapper.c GetThdynCombGasZachV1.c -outdir ..
mex compressor_calc_PTFV1.c compressor_calc_PTFV1_wrapper.c GetThdynCombGasZachV1.c -outdir ..
mex crankMechKinematic.c crankMechKinematic_wrapper.c -outdir ..
mex EngCylHeatTransfer.c EngCylHeatTransfer_wrapper.c -outdir ..
mex EngCylHeatTransferSSTune.c EngCylHeatTransferSSTune_wrapper.c -outdir ..
mex GetExhVVArea.c GetExhVVArea_wrapper.c -outdir ..
mex GetIntakeVVArea.c GetIntakeVVArea_wrapper.c -outdir ..
mex GetExhVVLift.c GetExhVVLift_wrapper.c -outdir ..
mex GetVVLift.c GetVVLift_wrapper.c -outdir ..
mex GetInportArea.c GetInportArea_wrapper.c -outdir ..
mex hysterisis.c hysterisis_wrapper.c -outdir ..

mex IdealNozzlePTF.c IdealNozzlePTF_wrapper.c GetThdynCombGasZachV1.c GetIdealNozzleFlowPTF.c ThdynPack_rtwutil.c rt_nonfinite.c rtGetInf.c rtGetNAN.c sqrt.c power.c rdivide.c -outdir ..
mex interpolateDescend.c interpolateDescend_wrapper.c -outdir ..
mex lowPassFilterBW4.c lowPassFilterBW4_wrapper.c -outdir ..
mex pCompCalc.c pCompCalc_wrapper.c -outdir ..
mex pMaxFinder.c pMaxFinder_wrapper.c -outdir ..

mex SpeedController.c SpeedController_wrapper.c -outdir ..
mex ThdynCV.c ThdynCV_wrapper.c GetPTFV1.c GetThdynCombGasZachV1.c -outdir ..
%}

mex -g ThdynCVConv.c ThdynCVConv_wrapper.c GetThdynCombGasZachV1.c -outdir ..
%{
mex ThdynCVNV.c GetPTFV1.c GetThdynCombGasZachV1.c -outdir ..
mex ThdynCVNVState.c GetPTFV1.c GetThdynCombGasZachV1.c -outdir ..
mex ThdynCV2ZoneConv.c ThdynCV2ZoneConv_wrapper.c GetThdynCombGasZachV1.c -outdir ..
mex ThdynCVNV2Zone.c ThdynCVNV2Zone_wrapper.c GetPTFV1.c GetThdynCombGasZachV1.c Get2ZonePTFIter.c
mex turbine_calc_PTF.c turbine_calc_PTF_wrapper.c GetThdynCombGasZachV1.c -outdir ..
mex turbine_calc_PTFV1.c turbine_calc_PTFV1_wrapper.c GetThdynCombGasZachV1.c -outdir ..
mex turbine_calc_MV_PTF.c turbine_calc_MV_PTF_wrapper.c GetThdynCombGasZachV1.c -outdir ..
mex InCylinderMV.c InCylinderMV_wrapper.c GetThdynCombGasZachV1.c -outdir ..
mex GetThdynCombGasZachSFunc.c GetThdynCombGasZachV1.c -outdir ..
mex crankMechKinematic1.c crankMechKinematic_wrapper1.c -outdir ..
mex workPerCycle.c -outdir ..
mex GetXCombGas.c GetXCombGas_wrapper.c GetCompCombGas.c GetEquilGrill.c GetCompleteComb.c ThdynPack_rtwutil.c rtGetNaN.c rtGetInf.c sum.c rt_nonfinite.c -outdir ..
mex dNOxMol.c dNOxMol_wrapper.c dNOx.c GetThdynCombGasZachV1.c GetCompCombGas.c GetEquilGrill.c GetCompleteComb.c ThdynPack_rtwutil.c rtGetNaN.c rtGetInf.c sum.c rt_nonfinite.c -outdir ..
mex resetCyc.c resetCyc_wrapper.c -outdir ..
mex GetPerCycle.c -outdir ..
mex SFCCyc.c SFCCyc_wrapper.c -outdir ..
mex scavenging1Zone.c scavenging1Zone_wrapper.c GetThdynCombGasZachV1.c GetTFromPhF.c -outdir ..
%}
cd(currFolder);