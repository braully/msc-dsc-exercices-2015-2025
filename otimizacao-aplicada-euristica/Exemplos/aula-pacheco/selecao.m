function [PopSel] = selecao(PSordem,m)
%Esta fun��o escolhe aleatoriamente dois indiv�duos da popula��o para serem 
%os pais de indiv�duos da nova prole. Cada indiv�duo tem a mesma probabilidade 
%de ser escolhido, pois, n�o � observado o valor da fun��o de avalia��o com 
%na sele��o por torneio.

Pops = PSordem(:,[1:end-1]);

for ia = 1:(size(Pops,1) * 2) - 2
    VarSel = randint(1,1,m)+1;
    PopSel(ia,:) = Pops(VarSel,:);
end