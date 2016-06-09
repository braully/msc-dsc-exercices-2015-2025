function Problema2Ex1
    clc; clear all; warning off;
    options = optimset('Algorithm','active-set');
    A = [];
    b = [];
    Aeq =  [4, 2*pi];
    beq =  [10];
    lb = [];
    lb  = zeros(2,1);
    ub = [];
    x0 = [5 5];
    [x, fval, exitflag, output] = fmincon(@AreaTotal, x0, A, b, Aeq, beq, lb, [], [], options);
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

