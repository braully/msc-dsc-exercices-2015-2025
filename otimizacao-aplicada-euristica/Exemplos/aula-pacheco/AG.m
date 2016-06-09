clc; clear all; format; warning off;

%*************Dados de entrada do algoritmo genetico*******
%**********************************************************
%**********************************************************
%**********************************************************
%*****************Cria a populacao inicial*****************
m   = 10;   %numero de individuos na populacao do AG
n   = 2;    %numero de gene no cromossomodo AG
Ain = -20;  %assintota inferior do espaço de busca omega
Asu = 10;   %assintota superior do espaço de busca omega
Pin = Ain + (Asu-Ain).*rand(m,n) %populacao inicial

%********Carrega algumas variaveis do ploblema*************
a = 1;
b = -5;
c = 4;

%********Carrega algumas variaveis do AG*******************
Mind    = [100 100 100];% melhor indiv�duo
fx      = 0;%vetor com os valores da funcao de avaliacao
Ger     = 0;%vetor geracao
Delta   = 0;%vetor com a funcao de mutacao
gmax    = 50;%numero maximo de geracao
ContGer = 0; %contador de geracao
Linf    = 0.3;%valor estocastico inferior dentro da funcao de mutacao
Lsup    = 10;%valor estocastico superior dentro da funcao de mutacao

while Mind(1,end)>=1e-3 && ContGer ~= gmax
    ContGer = ContGer+1;
    %*************Chama o simulador****************************
    [R1,R2] = simulacao(Pin,a,b,c); %simulador
    Sim     = [R1;R2]; %populacao simulada
    
    %*************Chama a funcao de avaliacao******************
    [Fx] = avaliacao(Sim); %funcao de avaliacao
    
    %******Ordena a populacao e guarda o melhor individuo******
    [PSordem,Mind] = ordena(Pin,Fx); %ordenada a populacao pela nota
    PSordem;
    %***********Chama a selecao dos pais aleatoria***********
    [PopSel] = selecao(PSordem,m); %esta selecao e aleatoria pai a pai
%     PopSel
    %***********Chama o operador de cruzamento*****************
    [NewPop] = cruzamento(PopSel);
%     NewPop
    %***********Chama o operador de mutacao********************
    [PopMut,delta] = mutacao(ContGer,NewPop,Linf,Lsup);
%     PopMut
    %***********Coloca o melhor indiiduo na nova populacao*****
    Pin = [PopMut; Mind(1,[1:end-1])];
    
    %*********************Ploata os graficos*******************
    [fx,Ger,Delta] = graficos(PSordem,ContGer,a,b,c,Mind,fx,Ger,Ain,Asu,delta,Delta);
    
    
end
PSordem
