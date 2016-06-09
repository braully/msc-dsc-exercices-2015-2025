function [Faval] = SegundoGrau(X)
%Fun��o que avalia o custo dos indiv�duos, ou seja, atribui nota 
%a cada indiv�duo ou solu��o de uma fun��o do segundo grau.

%X = [4 4];
%Simulador
a = 1;
b = -5;
c = 4;

Fx1 = a*X(1,1)^2 + b*X(1,1) + c
Fx2 = a*X(1,2)^2 + b*X(1,2) + c

%Funcao de avalia��o

Faval = abs(Fx1) + abs(Fx2) + min(abs(X(1,2)/X(1,1)),abs(X(1,1)/X(1,2))) %metrica para funcao de avaliacao
   
