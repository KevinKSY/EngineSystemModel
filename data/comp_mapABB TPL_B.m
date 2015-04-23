compMapReg.regModel = 'Rational'
compMapReg.noCurve = 6;
compMapReg.coeff = [-0.09582	-1.549	-1.433	-1.036	1.763	5.961; ...
                    0.1847	3.834	5.519	6.898	2.467	-1.258; ...
                    -3.002	-6.602	-8.006	-9.174	-7.175	-5.193; ...
                    2.307	10.23	16.48	23.98	24.72	36.49];
compMapReg.RPMRep = [6410.5	10196.4	11941.6	13356.1	14207.8	15070.5];
compMApReg.PRMin = [1.29738,1.97159,2.48989,3.10844,3.45424,3.97011];
compMApReg.PRMax = [1.48597,2.41392,3.2179,3.90773,4.26018,4.35439];
figure
for i = 1:6
    x = compMApReg.PRMin(i):0.01:compMApReg.PRMax(i);
    y = (compMapReg.coeff(1,i)*x + compMapReg.coeff(2,i))./ ...
        (x.^2 + compMapReg.coeff(3,i)*x + compMapReg.coeff(4,i));
    plot(x,y);
    hold on
end;


                
                
