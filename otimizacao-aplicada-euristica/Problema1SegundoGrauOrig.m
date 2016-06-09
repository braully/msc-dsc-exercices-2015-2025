function Problema1SegundoGrau
    clc; clear all; warning off;
    x0 = [2.5 2.5]; % chute inicial    
    options = optimset('LargeScale','off');      
    [x,fval] = fminsearch(@Problema1SegundoGrauOtimizacaoOrig,x0);
    disp(x);
end

function [Faval] = Problema1SegundoGrauOtimizacaoOrig(X)
    a = 1;
    b = -5;
    c = 4;
    Fx1 = a*X(1,1)^2 + b*X(1,1) + c
    Fx2 = a*X(1,2)^2 + b*X(1,2) + c
    Faval = abs(Fx1) + abs(Fx2)
end
