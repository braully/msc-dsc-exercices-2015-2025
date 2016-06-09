clc; clear all; format; warning off;

%*************Dados de entrada do algoritmo Forca bruta*******
%**********************************************************
%**********************************************************
%**********************************************************
%*****************Cria a populacao inicial*****************
m   = 10;   %numero de individuos na populacao do AG
n   = 2;    %numero de gene no cromossomodo AG
Ain = -10;  %assintota inferior do espaço de busca omega
Asu = 10;   %assintota superior do espaço de busca omega
Pin = Ain + (Asu-Ain).*rand(m,n); %populacao inicial
% Pin = randint(m,n,[Ain,Asu]); %populacao inicial
gmax = 50;%numero maximo de geracao
ContGer = 0; %contador de geracao
fxx = 1e-2;

%********Carrega algumas variaveis do ploblema*************
a = 1;
b = -5;
c = 4;

Mind = [100 100 100];
fx  = 0;
Ger = 0;

while Mind(1,end)>=fxx && ContGer ~= gmax
    ContGer = ContGer+1
    %*************Chama o simulador****************************
    [R1,R2] = simulacao(Pin,a,b,c); %simulador
    Sim     = [R1;R2]; %populacao simulada
    
    %*************Chama a funcao de avaliacao******************
    [Fx] = avaliacao(Sim); %funcao de avaliacao
    
    %******Ordena a populacao e guarda o melhor individuo******
    [PSordem,Mind] = ordena(Pin,Fx); %ordenada a populacao pela nota
    PSordem
    
    %*************Força bruta******************
    NewPop = Ain + (Asu-Ain).*rand(m-1,n);
    %     NewPop = randint(m,n,[Ain,Asu]);
    Pin = [NewPop; Mind(1,[1:end-1])];
    %
    %*********************Plota os graficos*******************
    [fx,Ger] = graficos(PSordem,ContGer,a,b,c,Mind,fx,Ger,Ain,Asu);
end

