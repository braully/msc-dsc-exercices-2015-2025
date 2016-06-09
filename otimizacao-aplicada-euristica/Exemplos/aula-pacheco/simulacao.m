function [Fx1,Fx2] = simulacao(Pin,a,b,c)
%Função que simula uma equação do segundo grau. 
%Esta função recebe valores para X, a, b e c. 
%Devolve os valores f(x1) e f(x2) no formato R1 e R2 respectivamente.


for ia = 1:size(Pin,1)
    Fx1(ia) = a*Pin(ia,1)^2 + b*Pin(ia,1) + c;
    Fx2(ia) = a*Pin(ia,2)^2 + b*Pin(ia,2) + c;
end