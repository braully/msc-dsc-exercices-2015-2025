function Problema2Ex3
    clc; clear all; warning off;
    AlgoritmoGenetico(@Problema2Ex3Otimizacao, 2)
end

function [fval] = Problema2Ex3Otimizacao(X)
    x1(1) = X(1); % Condições iniciais
    x2(1) = X(2); % Condições iniciais
    t = 0:1:100; % Número de instantes a considerar
    for ia = 1:size(t,2)-1 % Início do ciclo, com t(end)-1 iterações
        x1(ia+1)=0.9*x2(ia);
        x2(ia+1)=-x1(ia)-0.1*x2(ia);
    end
    aval1 = (max(x1) - min(x1));
    aval2 = (max(x2) - min(x2));
    fval = aval1 + aval2;
end