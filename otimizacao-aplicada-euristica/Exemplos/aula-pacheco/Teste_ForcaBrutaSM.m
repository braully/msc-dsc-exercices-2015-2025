%Algoritmo Forca Bruta sem memoria
clc; warning off; clear all; format long; close all;

N = 2; %Numero de parametro
Cp1 = 1; %Criterio de parada pela função de avaliacao
Cp2 = 100; %Criterio de parada pela iteração
Faval = 1e5; %Inicio do criterio de parada
ContIt = 0; %Contador de iteração
MemFaval = 10;

while Faval(1,end) >= Cp1 && ContIt~= Cp2
    ContIt = ContIt + 1;
    X = rand(1,N);
    [FavalN] = SegundoGrau(X);    
    
    if FavalN < Faval
        Faval = FavalN
    end
    
    MemFaval(end+1) = Faval;
end

MemFaval'