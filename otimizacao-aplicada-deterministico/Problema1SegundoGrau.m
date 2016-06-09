function Problema1SegundoGrau
    clc; clear all; warning off;
    x0 = [2.5 2.5]; % chute inicial    
    options = optimset('LargeScale','off');      
    [x,fval] = fminsearch(@Problema1SegundoGrauOtimizacao,x0);
    %[x,fval] = fminunc(@Problema1SegundoGrauOtimizacao,x0, options);
    disp(x);
    
    %superfice optimal
        
end

function [Faval] = Problema1SegundoGrauOtimizacao(X)
    a = 1;
    b = -5;
    c = 4;
    Fx1 = a*X(1,1)^2 + b*X(1,1) + c
    Fx2 = a*X(1,2)^2 + b*X(1,2) + c
    Faval = (abs(Fx1) + abs(Fx2)) / abs((X(1,1) - X(1,2)))
end