function Problema2Ex1
    clc; clear all; warning off;
    A = [];
    b = [];
    Aeq =  [4, 2*pi];
    beq =  [10];
    lb  = zeros(2,1);
    
    %options = gaoptimset('MutationFcn',@mutationadaptfeasible);
    %options = gaoptimset(options,'PlotFcns',{@gaplotbestf, @gaplotgenealogy}, 'Display','iter');
    options = gaoptimset('PlotFcns',{@gaplotbestf}, 'Display','iter');
    %Funçoes de plotagem: http://www.mathworks.com/help/gads/genetic-algorithm-options.html#f14474
    
    [x, fval, exitflag, output] = ga(@AreaTotal, 2, A, b, Aeq, beq, lb, [], [], [], options);
    fprintf('fval: %d\n', fval);
    fprintf('saida %d\n', exitflag);
    disp('dados saida:');
    disp(output)
    disp('Valores dos lados');
    disp(x);
    disp('cortar em:');
    disp(x(1)*4);
    fprintf('deixar para o quadrado: %d m de corda', (x(1)*4));
    fprintf('deixar para o circulo: %d m de corda\n', (x(2)*2*pi));
end

%soluçao 2
function [fareatotal] = AreaTotal(x)
    Aquad = x(1)^2;
    Acirc = 3.14*(x(2)^2);
    fareatotal = (Aquad +  Acirc);
end

