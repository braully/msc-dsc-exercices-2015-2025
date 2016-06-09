function [c,ceq] = restrExemOtim2(x)

% Restrições de desigualdade.
R1 = 1.5 + x(1)*x(2) - x(1) - x(2);
R2 = -x(1)*x(2) - 10;
c = [R1; R2];

% Restrições de igualdade.
ceq = [];