% Deriving equations for IC field for crank mechanism using lagrangian
% mechanism

%% Creating symbols
syms xP;    %Displacement of piston from the rotating axis of crank shaft
syms xCR1;  %Displacement of CoG of connecting rod 
syms xCR2;  %Displacement of CoG of crank rod
syms theta; %Angle of rotation of crank shaft
syms Theta; %Angle of rotation of crank shaft 
syms dtheta;%time derivative of theta 
syms phi;   %Angrle of rotation of connecting rod
syms mP;    %mass of piston
syms mCR1;  %mass of connecting rod
syms mCR2;  %mass of crank rod
syms jCR1;  %mass moment of inertia of the connecting rod
syms jCR2;  %mass moment of inertia of the crank rod
syms t;     %time
syms r;     %length of connecting rod
syms l;     %length of crank rod
syms g;     %gravitational acceleration
theta = symfun(sym('theta(t)'),[t]);
%% Kinematic relations
xP = r*cos(theta) + l*sqrt(1-(r/l)^2*(sin(theta))^2);
xCR1 = r*cos(theta) + 0.5*l*sqrt(1-(r/l)^2*(sin(theta))^2);
xCR2 = 0.5*r*cos(theta);

dxP = diff(xP,t);
dxCR1 = diff(xCR1,t);
dxCR2 = diff(xCR2,t);

dphi_sqr = ((r/l)*cos(theta))^2/(1-((r/l)*sin(theta))^2)*diff(theta,t)^2;
%% Energy equations
T = 0.5*mP*dxP^2 + 0.5*mCR1*dxCR1^2 + 0.5*jCR1*dphi_sqr ...
    + 0.5*jCR2*diff(theta,t)^2;         %Kinetic energy of the system
V = g*(mP*xP + mCR1*xCR1 + mCR2*xCR2);  %Potential energy of the system
T_temp = subs(T,diff(theta,t),dtheta);
T_temp = subs(T_temp,theta,Theta);
V_temp = subs(V,theta,Theta);

p = diff(T_temp,dtheta);                %Momentum of the system
J = simplify(coeffs(dp,dtheta));                  %General inertia of the system
eC = diff(V_temp,Theta);                %Potential effort 

ccode(J)
ccode(eC)


jCR2 + mCR1*(r*sin(Theta) + (r^2*cos(Theta)*sin(Theta))/ (2*l*(1 - (r^2*sin(Theta)^2)/l^2)^(1/2)))^2 ...
     + mP*(r*sin(Theta)   + (r^2*cos(Theta)*sin(Theta))/(l*(1 - (r^2*sin(Theta)^2)/l^2)^(1/2)))^2 ...
    - (jCR1*r^2*cos(Theta)^2)/(l^2*((r^2*sin(Theta)^2)/l^2 - 1));
 
-g*(mCR1*(r*sin(Theta) + (r^2*cos(Theta)*sin(Theta))/(2*l*(1 - (r^2*sin(Theta)^2)/l^2)^(1/2))) + mP*(r*sin(Theta) + (r^2*cos(Theta)*sin(Theta))/(l*(1 - (r^2*sin(Theta)^2)/l^2)^(1/2))) + 
(mCR2*r*sin(Theta))/2);



