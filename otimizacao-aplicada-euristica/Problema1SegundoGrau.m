function Problema1SegundoGrau
    clc;
    clear all;
    warning off;    
    
    opcoes.numeroMaximoGeracoes=50;
    opcoes.numeroIndividuosPopulacao=20;
    opcoes.limiteSuperior = 10;
    opcoes.limiteInferior = -20;
    opcoes.limiteInferiorEstocastico = 0.3;
    opcoes.limiteSuperiorEstocastico = 10;
    AlgoritmoGenetico(@Problema1SegundoGrauOtimizacao, 2, opcoes)
end

function [Faval] = Problema1SegundoGrauOtimizacao(X)
    a = 1;
    b = -5;
    c = 4;
    Fx1 = a*X(1,1)^2 + b*X(1,1) + c
    Fx2 = a*X(1,2)^2 + b*X(1,2) + c
    Faval = (abs(Fx1) + abs(Fx2)) / abs((X(1,1) - X(1,2)))
end