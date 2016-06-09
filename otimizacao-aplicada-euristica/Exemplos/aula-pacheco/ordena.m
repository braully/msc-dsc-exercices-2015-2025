function [PSordem,Mind] = ordena(Pin,Fx)
%Esta função recebe a população inicial e o valor da nota de cada indivíduo. 
%Reúne estes valores em uma matriz e ordena de forma decrescente pela função de avaliação. 
%Separa a melhor solução, ou seja, o melhor indivíduo da população. 
%Devolve a matriz contendo a população e a função de avaliação ordenada e os valores 
%dos genes do melhor indivíduo junto com o valor de sua função de avaliação.

PSimul = [Pin Fx']; %populacao simulada e com funcao de avaliacao

[Ord,IndOrd]= sort(PSimul(:,end));

for ia = 1:size(Pin,1)
    PSordem(ia,:) = PSimul(IndOrd(ia),:);
end

Mind = PSordem(1,:);
