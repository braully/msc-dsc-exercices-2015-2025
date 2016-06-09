clc; clear all; warning off;

t0 = 0;
tf = 10;
dt = 0.01;
tpo = t0:dt:tf;
x0 = [0.1 0];
[t,x] = ode45('exemplo3b',tpo,x0);
x1 = x(:,1);
x2 = x(:,2);
%========================Graficos==========================

figure(1)
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
