function [fareatotal] = AreaTotalOtim(X)
    Aquad = X(1)^2;
    Acirc = 3.14*(X(2)^2);
    fareatotal = (Aquad +  Acirc);
end