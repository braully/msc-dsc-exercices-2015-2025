function [fval] = ExemOtim3(X)

x0 = X;
t0 = 0;
tf = 30;
dt = 0.01;
tpo = t0:dt:tf;
[t,x] = ode45('exemplo3b',tpo,x0);
x1 = x(:,1);
x2 = x(:,2);
%========================Graficos==========================

figure(1)
pause(0.1);
clf(1)
subplot(1,2,1)
plot(x1,x2,'LineWidth',1);
hold on;
title('Relação entre as Variáveis');
xlabel('x1'); 
ylabel('x2');
hold off;

hold on;
subplot(1,2,2);
plot(t,x,'LineWidth',2);
title('Saída do Sistema');
xlabel('Tempo [s]'); 
ylabel('Resposta do Sistema');
hold off;

aval1 = (max(x1) - min(x1))*100;
aval2 = (max(x2) - min(x2))*100;

fval = aval1 + aval2;




