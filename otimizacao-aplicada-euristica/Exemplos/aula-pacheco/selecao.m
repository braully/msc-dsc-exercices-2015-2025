function [PopSel] = selecao(PSordem,m)
%Esta função escolhe aleatoriamente dois indivíduos da população para serem 
%os pais de indivíduos da nova prole. Cada indivíduo tem a mesma probabilidade 
%de ser escolhido, pois, não é observado o valor da função de avaliação com 
%na seleção por torneio.

Pops = PSordem(:,[1:end-1]);

for ia = 1:(size(Pops,1) * 2) - 2
    VarSel = randint(1,1,m)+1;
    PopSel(ia,:) = Pops(VarSel,:);
end