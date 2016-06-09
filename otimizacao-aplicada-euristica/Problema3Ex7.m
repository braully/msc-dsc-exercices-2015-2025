%format long
function Problema3Ex7
    clear all; clc; warning off;
    opcoes.numeroMaximoGeracoes=100;
    opcoes.numeroIndividuosPopulacao=20;
    opcoes.limiteSuperior = 50;
    opcoes.limiteInferior = -50;
    opcoes.limiteInferiorEstocastico = 0.8;
    opcoes.limiteSuperiorEstocastico = 20;
    AlgoritmoGenetico(@Problema3Ex7Otimizacao, 2, opcoes)
end


