function [fx,Ger,Delta] = graficos(PSordem,ContGer,a,b,c,Mind,fx,Ger,Ain,Asu,delta,Delta)

MinY = -2.5;
MaxY = (a*Asu^2 + b*Asu + c);
X = Ain:0.2:Asu;
y = MinY:1:MaxY;
z = Mind(1,[1:2]);

for ia = 1:size(X,2)
    Y(ia) = a*X(ia)^2 + b*X(ia) + c;
end

figure(1); grid on; subplot(2,2,1);
plot(X,Y,'k-','LineWidth', 1.5); hold on;
% plot(X,zeros(length(X)),'b-','LineWidth', 1.5);
% plot(zeros(length(y)),y,'b-','LineWidth', 1.5);
plot(z,[0 0],'ro','LineWidth', 2);
title('Simulador');
xlabel('Valores das Raizes'); ylabel('Eixo das Ordenadas')
axis([Ain,Asu,MinY,MaxY])
hold off; grid off;

%************************************************************
if ContGer == 1
    fx(1,1) = PSordem(1,end);
    Ger     = ContGer;
else
    fx(1,end+1)  = PSordem(1,end);
    Ger(1,end+1) = ContGer;
end

figure(1); grid on; subplot(2,2,2);
plot(Ger,fx,'ko-','LineWidth', 1.5); hold on;
title('Desenvolvimento do GA');
xlabel('Gerafico'); ylabel('F(x)')
axis([1,ContGer+1,-0.1,fx(1)+0.3])
hold off; grid off;

%************************************************************
% Delta(1,end+1)  = delta;
% Gera1 = 1:1:length(Delta);
% 
% figure(1); grid on; subplot(2,2,3);
% plot(Gera1,Delta,'ko-','LineWidth', 1.5); hold on;
% title('Fun��o de Muta��o');
% xlabel('Gera��o'); ylabel('Delta')
% axis([1,Gera1(end)+1,-0.1,max(Delta)+0.3])
% hold off; grid off;