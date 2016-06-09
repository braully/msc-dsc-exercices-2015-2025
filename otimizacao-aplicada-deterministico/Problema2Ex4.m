%format long
function Problema2Ex4
    clc; clear all; warning off;
    x0 = [0.5; -2.0; -2.0]; % chute inicial
    %[x,fval] = fminsearch(@Problema2Ex4Otimizacao,x0)
    [x,fval, exitflag, output] = fminunc(@Problema2Ex4Otimizacao,x0)
    fprintf('fval: %d\n', fval);
    fprintf('saida %d\n', exitflag);
    disp('dados saida:');
    disp(output)
    disp('saida');
    disp(x);
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
    
    %plot(t,x1,'r'); % representação do estado em função do tempo
    %hold on;
    %plot(t,x2,'k');
    %plot(t,x3,'b');
    
    %========================Graficos==========================
    figure(1)
    pause(0.1);
    clf(1)
    subplot(1,2,1)
    plot3(x1,x2, x3, 'LineWidth',1);
    hold on;
    title('Relação entre as Variáveis');
    xlabel('x1'); 
    ylabel('x2');
    zlabel('x3');
    hold off;

    hold on;
    subplot(1,2,2);
    plot(t,x, 'LineWidth',1);
    title('Saída do Sistema');
    xlabel('Tempo [s]'); 
    ylabel('Resposta do Sistema');
    hold off;

end

function [xdot] = exemplo01(t,x) %Função
    xdot = zeros(size(x,1),1);
    xdot(1)=-x(2)+x(1)*x(3);
    xdot(2)=x(1)+x(2)*x(3);
    xdot(3)=-x(3)-x(1)^2+x(3)^2;
end