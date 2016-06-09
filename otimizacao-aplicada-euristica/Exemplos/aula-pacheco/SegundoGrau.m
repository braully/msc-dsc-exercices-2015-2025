function [Faval] = SegundoGrau(X)
%Função que avalia o custo dos indivíduos, ou seja, atribui nota 
%a cada indivíduo ou solução de uma função do segundo grau.

%X = [1 0];
%Simulador
a = 1;
b = -5;
c = 4;

Fx1 = a*X(1,1)^2 + b*X(1,1) + c
Fx2 = a*X(1,2)^2 + b*X(1,2) + c

%Funcao de avaliação

Faval = abs(Fx1)+abs(Fx2) %metrica para funcao de avaliacao
   
