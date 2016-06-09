function [fval] = ExemOtim1(x)

fval=100*(x(2)-x(1).^2).^2+(1-x(1)).^2;
