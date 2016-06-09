function Problema2Ex2
    clc; clear all; warning off;
    A = [];
    b = [];
    Aeq =  [2, 2];
    beq =  [100];
    lb  = zeros(2,1);
    options = gaoptimset('PlotFcns',{@gaplotbestf}, 'Display','iter');  
    [x, fval, exitflag, output] = ga(@AreaTotal, 2, A, b, Aeq, beq, lb, [], [], [], options);
    fprintf('fval: %d\n', fval);
    fprintf('saida %d\n', exitflag);
    disp('dados saida:');
    disp(output)
    fprintf('base: %d e altura: %d\n', x(1), x(2));
end

%soluçao 2
function [fval] = AreaTotal(x)
    fareatotal = x(1)*x(2);
    fval = 100/fareatotal;
end