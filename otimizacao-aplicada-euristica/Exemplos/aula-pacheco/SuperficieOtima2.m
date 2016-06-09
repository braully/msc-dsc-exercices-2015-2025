%Teste de superficie de otimalidade

clc; clear all; warning off;


t0 = 0;
tf = 30;
dt = 0.01;
tpo = t0:dt:tf;
X = -14:0.5:14;
Y = X;
%========================Graficos==========================
for ia = 1:size(X,2)
    for ib = 1:size(Y,2)
        [t,x] = ode45('exemplo3b',tpo,[X(ia) Y(ib)]);
        x1 = x(:,1);
        x2 = x(:,2);
        
        aval1 = (max(x1) - min(x1))*100;
        aval2 = (max(x2) - min(x2))*100;
        
        fval(ia,ib) = aval1 + aval2;
    end
end

surf(X,Y,fval)
