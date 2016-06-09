%format long
function Problema2Ex4
    clc; clear all; warning off;
    AlgoritmoGenetico(@Problema2Ex4Otimizacao, 3)
end

function [fval] = Problema2Ex4Otimizacao(X)
    ti = 0; % tempo inicial
    tf = 40; % tempo final
    dt = 0.1; % derivada de t
    tpo= ti:dt:tf; % vetor tempo
    x0 = X;
    [t,x]=ode45(@exemplo01,tpo,x0); %metodo de Ruge-Kutta
    x1 = x(:,1);
    x2 = x(:,2);
    x3 = x(:,3);
    
    aval1 = (max(x1) - min(x1))*100;
    aval2 = (max(x2) - min(x2))*100;
    aval3 = (max(x3) - min(x3))*100;
    fval = aval1 + aval2 + aval3;    
end

function [xdot] = exemplo01(t,x) %Função
    xdot = zeros(size(x,1),1);
    xdot(1)=-x(2)+x(1)*x(3);
    xdot(2)=x(1)+x(2)*x(3);
    xdot(3)=-x(3)-x(1)^2+x(3)^2;
end