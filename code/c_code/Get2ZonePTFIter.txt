void Get2ZonePTFIter(real_T p_prev,
					 real_T Tu_prev,
					 real_T Fu_prev,
					 real_T Ru_prev,
					 real_T uu_prev,
					 real_T Cvu_prev,
					 real_T Tb_prev,
					 real_T Fb_prev,
					 real_T Rb_prev,
					 real_T ub_prev,
					 real_T Cvb_prev,
					 real_T mCyl_prev,
					 real_T mbCyl_prev,
					 real_T VCyl_prev,
					 real_T QCyl_prev,
					 real_T HCyl_prev,
					 real_T WCyl_prev,
					 real_T mu_prev,
					 real_T mub_prev,
					 real_T Vu_prev,
					 real_T VCyl,
					 real_T muTemp,
					 real_T mbTemp,
					 real_T mubTemp,
					 real_T mbbTemp,
					 real_T dVCyl,
					 real_T dWCyl,
					 real_T dQu,
					 real_T dQb,
					 real_T dHu,
					 real_T dHb,
					 real_T fs)
					 real_T *puTemp,
					 real_T *pbTemp,
					 real_T *TuTemp,
					 real_T *TbTemp,
					 real_T *FuTemp,
					 real_T *FbTemp,
					 real_T *VuTemp,
					 real_T *VbTemp,
{
	real_T delP, errP, noIter, dVuCorr, dVbCorr, dVu, dVb, dWu, dWb;
	real_T Ru, hu, su, uu, RF1, RP1, RT1, uF1, uP1, uT1, sF1, sP1, sT1, Cp1, Cv1, K1;
	real_T Rb, hb, sb, ub, RF2, RP2, RT2, uF2, uP2, uT2, sF2, sP2, sT2, Cp2, Cv2, K2;
	real_T TU, TU1;
	real_T EuPrev, EbPrev, EuTemp, EbTemp;
	real_T Vb_prev;

	GetThdynCombGasZachV1(puTemp[0], TuTemp[0], FuTemp[0], fs[0], &Ru, &hu, &su, &uu,
		&RF1, &RP1, &RT1, &uF1, &uP1, &uT1, &sF1, &sP1, &sT1,
		&Cp1, &Cv1, &K1);

	errP = 1;
	noIter = 0;
	dVuCorr = 0;
	dVbCorr = 0;
	EuPrev = mu_prev[0] * uu_prev[0];
	EbPrev = -QCyl_prev[0] + HCyl_prev[0] - WCyl_prev[0] - EuPrev;
	Vb_prev = VCyl_prev[0] - Vu_prev[0];
	while (errP > 0.001 && noIter < 1000){
		++noIter;
		if (Vu_prev[0] < Vb_prev){
			VuTemp[0] = VuTemp[0] + dVuCorr;
			dVu = VuTemp[0] - Vu_prev[0];
			VbTemp[0] = VCyl - VuTemp[0];
			dVb = VbTemp[0] - Vb_prev;
			if (dVCyl == 0){
				dWu = 0;
				dWb = 0;
			}
			else {
				dWu = fabs(dWCyl / dVCyl)*dVu;
				dWb = dWCyl - dWu;
			}
		}
		else {
			VbTemp[0] = VbTemp[0] + dVbCorr;
			dVb = VbTemp[0] - Vb_prev;
			VuTemp[0] = VCyl - VbTemp[0];
			dVu = VuTemp[0] - Vu_prev[0];
			if (dVCyl == 0){
				dWu = 0;
				dWb = 0;
			}
			else {
				dWb = fabs(dWCyl / dVCyl)*dVb;
				dWu = dWCyl - dWb;
			}
		}
		EuTemp = EuPrev - dQu - dWu + dHu;
		EbTemp = EbPrev - dQb - dWb + dHb;
		GetPTF(muTemp, mubTemp, EuTemp, VuTemp[0], Tu_prev[0], Ru_prev[0], uu_prev[0],
			Cvu_prev[0], fs[0], puTemp, TuTemp, FuTemp);
		GetPTF(mbTemp, mbbTemp, EbTemp, VbTemp[0], Tb_prev[0], Rb_prev[0], ub_prev[0],
			Cvb_prev[0], fs[0], pbTemp, TbTemp, FbTemp);
		delP = (puTemp[0] - pbTemp[0]);
		errP = fabs(delP / puTemp[0]);
		if (dVCyl == 0){
			dVuCorr = 0;
			dVbCorr = 0;
		}
		else{
			if (Vu_prev[0] < Vb_prev){
				GetThdynCombGasZachV1(puTemp[0], TuTemp[0], FuTemp[0], fs[0], &Ru, &hu, &su, &uu,
					&RF1, &RP1, &RT1, &uF1, &uP1, &uT1, &sF1, &sP1, &sT1, &Cp1, &Cv1, &K1);
				TU1 = (RP1*sF1 - RF1*sP1) /
					(RP1*(uT1*sF1 - uF1*sT1) + RT1*(uF1*sP1 - uP1*sF1) +
					RF1*(uP1*sT1 - uT1*sP1));
				TU = 1 / uT1;
				dVuCorr = VuTemp[0] * VuTemp[0] * delP / 2 /
					(muTemp*Ru*(VuTemp[0] * TU*fabs(dWCyl / dVCyl) + TuTemp[0]) +
					VuTemp[0] * delP / 2);
				dVbCorr = 0;
			}
			else{
				GetThdynCombGasZachV1(pbTemp[0], TbTemp[0], FbTemp[0], fs[0], &Rb, &hb, &sb, &ub,
					&RF2, &RP2, &RT2, &uF2, &uP2, &uT2, &sF2, &sP2, &sT2, &Cp2, &Cv2, &K2);
				TU1 = (RP2*sF2 - RF2*sP2) /
					(RP2*(uT2*sF2 - uF2*sT2) + RT2*(uF2*sP2 - uP2*sF2) +
					RF2*(uP2*sT2 - uT2*sP2));
				TU = 1 / uT2;
				dVbCorr = -VbTemp[0] * VbTemp[0] * delP / 2 /
					(mbTemp*Rb*(VbTemp[0] * TU*fabs(dWCyl / dVCyl) + TbTemp[0]) +
					VbTemp[0] * delP / 2);
				dVuCorr = 0;
			}
		}
		if (noIter > 1000){

		}
	}
}