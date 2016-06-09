function Problema2Ex3
    clc; clear all; warning off;
    x0 = [0.2 0.8]; % chute inicial
    [x,fval, exitflag, output] = fminunc(@Problema2Ex3Otimizacao,x0)
    %[x,fval, exitflag, output] = fminsearch(@Problema2Ex3Otimizacao,x0)
    fprintf('fval: %d\n', fval);
    fprintf('saida %d\n', exitflag);
    disp('dados saida:');
    disp(output)
    disp('valores x');
    disp(x);
    disp('favaliacao');
    disp(fval);
end

function [fval] = Problema2Ex3Otimizacao(X)
    %x1(1) = 0.2; % Condições iniciais
    %x2(1) = 0.8; % Condições iniciais
    x1(1) = X(1); % Condições iniciais
    x2(1) = X(2); % Condições iniciais
    t = 0:1:100; % Número de instantes a considerar
    for ia = 1:size(t,2)-1 % Início do ciclo, com t(end)-1 iterações
        x1(ia+1)=0.9*x2(ia);
        x2(ia+1)=-x1(ia)-0.1*x2(ia);
    end

    plot(t,x1,'b');
    hold on;
    plot(t,x2,'r');
    hold off;

    aval1 = (max(x1) - min(x1));
    aval2 = (max(x2) - min(x2));
    fval = aval1 + aval2;
    
    %========================Graficos==========================
    figure(1)
    pause(0.1);
    clf(1)
    subplot(1,2,1)
    plot(x1,x2, 'LineWidth',1);
    hold on;
    title('Relação entre as Variáveis');
    xlabel('x1'); 
    ylabel('x2');
    hold off;

    hold on;
    subplot(1,2,2);
    plot(t,x1, 'LineWidth',1);
    plot(t,x2, 'LineWidth',1);
    title('Saída do Sistema');
    xlabel('Tempo [s]'); 
    ylabel('Resposta do Sistema');
    hold off;    
end