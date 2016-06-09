function [PSordem,Mind] = ordena(Pin,Fx)
%Esta fun��o recebe a popula��o inicial e o valor da nota de cada indiv�duo. 
%Re�ne estes valores em uma matriz e ordena de forma decrescente pela fun��o de avalia��o. 
%Separa a melhor solu��o, ou seja, o melhor indiv�duo da popula��o. 
%Devolve a matriz contendo a popula��o e a fun��o de avalia��o ordenada e os valores 
%dos genes do melhor indiv�duo junto com o valor de sua fun��o de avalia��o.

PSimul = [Pin Fx']; %populacao simulada e com funcao de avaliacao

[Ord,IndOrd]= sort(PSimul(:,end));

for ia = 1:size(Pin,1)
    PSordem(ia,:) = PSimul(IndOrd(ia),:);
end

Mind = PSordem(1,:);
