%{a
compMapReg.regModel = 'Rational'
compMapReg.noCurve = 6;
compMapReg.coeff = [-0.09582	-1.549	-1.433	-1.036	1.763	5.961; ...
                    0.1847	3.834	5.519	6.898	2.467	-1.258; ...
                    -3.002	-6.602	-8.006	-9.174	-7.175	-5.193; ...
                    2.307	10.23	16.48	23.98	24.72	36.49];
compMapReg.RPMRep = [6410.5	10196.4	11941.6	13356.1	14207.8	15070.5];
compMapReg.PRMin = [1.29738,1.97159,2.48989,3.10844,3.45424,3.97011];
compMapReg.PRMax = [1.48597,2.41392,3.2179,3.90773,4.26018,4.35439];

figure
for i = 1:6
    x = compMapReg.PRMin(i):0.01:compMapReg.PRMax(i);
    y = (compMapReg.coeff(1,i)*x + compMapReg.coeff(2,i))./ ...
        (x.^2 + compMapReg.coeff(3,i)*x + compMapReg.coeff(4,i));
    plot(x,y);
    hold on
end;

RPM = 12500;
p = interp1(compMapReg.RPMRep,compMapReg.coeff',RPM,'pchip');
PRMin = interp1(compMapReg.RPMRep,compMapReg.PRMin,RPM,'pchip');
PRMax = interp1(compMapReg.RPMRep,compMapReg.PRMax,RPM,'pchip');

x = PRMin:0.01:PRMax;
y = (p(1)*x + p(2))./(x.^2 + p(3)*x + p(4));
plot(x,y,'black');
%}
%{a
compMapReg.regModel = 'Cubic';
compMapReg.noCurve = 6;
compMapReg.coeff = [-37.51	-2.733	-0.3846	-0.09203	-0.005389	0.2173; ...
                    148.5	17.62	3.088	0.8577	-0.006937	-2.794; ...
                    -194.1	-37.46	-7.993	-2.455	0.4066	12.08; ...
                    84.54	27	7.404	2.826	-0.3783	-16.79];
compMapReg.RPMRep = [6410.5	10196.4	11941.6	13356.1	14207.8	15070.5];
compMapReg.PRMin = [1.29738,1.97159,2.48989,3.10844,3.45424,3.97011];
compMapReg.PRMax = [1.48597,2.41392,3.2179,3.90773,4.26018,4.35439];
%%
figure
for i = 1:6
    x = compMapReg.PRMin(i):0.01:compMapReg.PRMax(i);
    y = ((compMapReg.coeff(1,i)*x + compMapReg.coeff(2,i)).*x + ...
         compMapReg.coeff(3,i)).*x + compMapReg.coeff(4,i);
    plot(x,y);
    hold on
end;
%%
RPM = 12500;
p = interp1(compMapReg.RPMRep,compMapReg.coeff',RPM,'pchip');
PRMin = interp1(compMapReg.RPMRep,compMapReg.PRMin,RPM,'pchip');
PRMax = interp1(compMapReg.RPMRep,compMapReg.PRMax,RPM,'pchip');

x = PRMin:0.01:PRMax;
y = ((p(1)*x + p(2)).*x + p(3)).*x + p(4);
plot(x,y,'black');
%}