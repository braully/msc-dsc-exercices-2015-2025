function [Fx] = avaliacao(Sim)
%Fun��o que avalia o custo dos indiv�duos, ou seja, atribui nota 
%a cada indiv�duo ou solu��o de uma fun��o do segundo grau.


for ia = 1:size(Sim,2)
    Fx(ia) = abs(Sim(1,ia))+ abs(Sim(2,ia)) + 1/abs(Sim(1,ia) - Sim(2,ia)); %metrica para funcao de avaliacao
end

