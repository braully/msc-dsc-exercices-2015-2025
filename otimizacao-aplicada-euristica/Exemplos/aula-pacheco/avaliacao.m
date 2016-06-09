function [Fx] = avaliacao(Sim)
%Função que avalia o custo dos indivíduos, ou seja, atribui nota 
%a cada indivíduo ou solução de uma função do segundo grau.


for ia = 1:size(Sim,2)
    Fx(ia) = abs(Sim(1,ia))+ abs(Sim(2,ia)) + 1/abs(Sim(1,ia) - Sim(2,ia)); %metrica para funcao de avaliacao
end

