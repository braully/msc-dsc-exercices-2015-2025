function AlgoritmoGenetico(funcaoObjetivo, numeroVariaveis, opcoes)
%     Parametros possiveis de ser passados passados nas opções:
%     opcoes.numeroMaximoGeracoes
%     opcoes.numeroIndividuosPopulacao
%     opcoes.numeroIndividuosPopulacao
%     opcoes.limiteSuperior
%     opcoes.limiteInferior
%     opcoes.limiteInferiorEstocastico
%     opcoes.limiteSuperiorEstocastico
    
    clc;
    format;
    warning off;
    
    opcoes.numeroVariaveis = numeroVariaveis;
    
    if ~isfield(opcoes,'numeroMaximoGeracoes')
        opcoes.numeroMaximoGeracoes=50;
    end
    if ~isfield(opcoes,'numeroIndividuosPopulacao')
        opcoes.numeroIndividuosPopulacao=20;
    end
    if ~isfield(opcoes, 'limiteSuperior') 
        opcoes.limiteSuperior = 10;
    end
    if ~isfield(opcoes, 'limiteInferior') 
        opcoes.limiteInferior = -20;
    end
    if ~isfield(opcoes, 'limiteInferiorEstocastico') 
        opcoes.limiteInferiorEstocastico = 0.3;
    end
    if ~isfield(opcoes, 'limiteSuperiorEstocastico') 
        opcoes.limiteSuperiorEstocastico = 10;
    end
    
    %opcoes.limiteSuperior = limiteSuperior;
    %opcoes.limiteInferior = limiteInferior;
    %*************Dados de entrada do algoritmo genetico*******
    m   = opcoes.numeroIndividuosPopulacao;   %numero de individuos na populacao do AG
    n   = numeroVariaveis;    %numero de gene no cromossomodo AG
    Ain = opcoes.limiteInferior;  %assintota inferior do espaço de busca omega
    Asu = opcoes.limiteSuperior;   %assintota superior do espaço de busca omega
    
    Pin = gerar_populacao_inicial(m, n, Ain, Asu);
   
    %********Carrega algumas variaveis do AG*******************
    Mind    = [100 100 100];% melhor individuo
    fx      = 0; %vetor com os valores da funcao de avaliacao
    Ger     = 0; %vetor geracao
    gmax    = opcoes.numeroMaximoGeracoes; %numero maximo de geracao
    ContGer = 0;  %contador de geracao
    Linf    = opcoes.limiteInferiorEstocastico; %valor estocastico inferior dentro da funcao de mutacao
    Lsup    = opcoes.limiteSuperiorEstocastico;  %valor estocastico superior dentro da funcao de mutacao
    
    HistMind = zeros(gmax, numeroVariaveis); %Historico de melhor individuo
    
    while Mind(1,end) >= 1e-3 && ContGer ~= gmax
        ContGer = ContGer+1;
        %*************Chama o simulacao e avaliacao ****************
        Sim = simulacao(Pin,funcaoObjetivo); %simulador
        Fx = Sim;

        %******Ordena a populacao e guarda o melhor individuo******
        [PSordem,Mind] = ordena(Pin,Fx); %ordenada a populacao pela nota
        %PSordem;
        
        %***********Chama a selecao dos pais aleatoria***********
        [PopSel] = selecao(PSordem,m); %esta selecao e aleatoria pai a pai
        
        %PopSel
        %***********Chama o operador de cruzamento*****************
        [NewPop] = cruzamento(PopSel);
        
        % NewPop
        %***********Chama o operador de mutacao********************
        [PopMut,delta] = mutacao(ContGer,NewPop,Linf,Lsup);
        
        % PopMut
        %***********Coloca o melhor individuo na nova populacao*****
        Pin = [PopMut; Mind(1,[1:end-1])];
        
        informar_situacao_iteracao(ContGer, Mind);
        [fx,Ger, HistMind] = graficos(PSordem,ContGer,Mind,fx,Ger, HistMind,opcoes);
    end
    disp('Historico melhores individuos')
    disp(HistMind)
    informar_resultado_final(PSordem, ContGer, Mind);
end

function informar_situacao_iteracao(ContGer, Mind)
 disp('______________________________________________________________________')
 fprintf('Geracao nº: %d\n', ContGer);
 fprintf('\tMelhor individuo: %s\n\t\tFaval(Melhor individuo): %s\n', mat2str(Mind(1:end-1)), num2str(Mind(end-1:end)))
end

function informar_resultado_final(PSordem, ContGer, Mind)
 disp('______________________________________________________________________')
 disp('____________________ Resultado Final _________________________________')
 disp('______________________________________________________________________')
 fprintf('\tPopulacao da ultima geracao:\n')
 disp(PSordem)
 fprintf('\tMelhor individuo: %s\n\t\tFaval(Melhor individuo): %s\n', mat2str(Mind(1:end-1)), num2str(Mind(end:end)))
end

%Gera a populacao inicial baseado na quantiade de individuso, numero de
%gentes, dentro dos limites pres-estabelecidos
function [Pin] = gerar_populacao_inicial(quantidadeIndividuos, numeroGenes, limiteInferior, limiteSuperior)
  aux = rand(quantidadeIndividuos, numeroGenes);
  Pin = (limiteSuperior-limiteInferior).*aux+limiteInferior;
end


function [Fx] = simulacao(Pin,funcaoObjetivo)
    for ia = 1:size(Pin,1)
        X = Pin(ia,:);
        Fx(ia) = funcaoObjetivo(X);
    end
end

%function [Fx] = avaliacao(Sim)
    %Função que avalia o custo dos indivíduos, ou seja, atribui nota 
    %a cada indivíduo ou solução de uma função do segundo grau.
    %for ia = 1:size(Sim,2)
    %    Fx(ia) = abs(Sim(1,ia))+ abs(Sim(2,ia)) + 1/abs(Sim(1,ia) - Sim(2,ia)); %metrica para funcao de avaliacao
    %end
%end

function [PSordem,Mind] = ordena(Pin,Fx)
    %Esta função recebe a população inicial e o valor da nota de cada indivíduo. 
    %Reúne estes valores em uma matriz e ordena de forma decrescente pela função de avaliação. 
    %Separa a melhor solução, ou seja, o melhor indivíduo da população. 
    %Devolve a matriz contendo a população e a função de avaliação ordenada e os valores 
    %dos genes do melhor indivíduo junto com o valor de sua função de avaliação.

    PSimul = [Pin Fx']; %populacao simulada e com funcao de avaliacao
    [Ord,IndOrd]= sort(PSimul(:,end));
    for ia = 1:size(Pin,1)
        PSordem(ia,:) = PSimul(IndOrd(ia),:);
    end
    Mind = PSordem(1,:);
end

function [PopSel] = selecao(PSordem,m)
    %Esta função escolhe aleatoriamente dois indivíduos da população para serem 
    %os pais de indivíduos da nova prole. Cada indivíduo tem a mesma probabilidade 
    %de ser escolhido, pois, não é observado o valor da função de avaliação com 
    %na seleção por torneio.

    Pops = PSordem(:,[1:end-1]);
    for ia = 1:(size(Pops,1) * 2) - 2
        VarSel = randint(1,1,m)+1;
        PopSel(ia,:) = Pops(VarSel,:);
    end
end

function [NewPop] = cruzamento(PopSel)
    cont = 0;
    for ia = 1:2:size(PopSel,1)
        cont = cont+1;
        for ib = 1:size(PopSel,2)
            %mexer aqui para mutar ou n�o mutar
            % tau = 1; %nao cruza ninquem
            % tau = 0; %cruza todo mundo
            tau = randint(1); %50% de chance de cruzar        
            if tau == 1
                NewPop(cont,ib) = PopSel(ia,ib); %se tau ==1 nao cruza
            else
                NewPop(cont,ib) = PopSel(ia+1,ib); %se tau ==0 cruza
            end
        end
    end
end


function [PopMut,delta] = mutacao(ContGer,NewPop,Linf,Lsup)
    for ia = 1:size(NewPop,1)
        for ib = 1:size(NewPop,2)
            %mexer aqui para mutar ou não mutar
    %         tau1 = 1;%não muta ninguem
    %         tau1 = 0;%muta todo mundo
             tau1 = randi(1);%50% de chance de mutar

            delta = (1/ContGer) * (Linf + (Lsup-Linf).*rand(1));
            if tau1 == 0 %se tau1 == 0 muta
                tau2 = randi(1);
                if tau2 == 0 %se tau2 == 0 subtrai
                    PopMut(ia,ib) = NewPop(ia,ib) - delta;
                else %se tau2 ~= 0 soma
                    PopMut(ia,ib) = NewPop(ia,ib) + delta;
                end
            else %se tau1 ~= 0 nao muta
                PopMut(ia,ib) = NewPop(ia,ib);
            end
        end
    end
end

function [fx,Ger, HistMind] = graficos(PSordem,ContGer,Mind,fx,Ger, HistMind, opcoes)

    if ContGer == 1
        fx(1,1) = PSordem(1,end);
        Ger = ContGer;
    else
        fx(1,end+1)  = PSordem(1,end);
        Ger(1,end+1) = ContGer;
    end
   
    HistMind(ContGer,:) = Mind(1:end-1);

    figure(1);
    if opcoes.numeroVariaveis == 2
        clf(1)
        subplot(1,2,1)
        plot(HistMind(:, 1), HistMind(:, 2), '--go');
        if opcoes.numeroMaximoGeracoes == ContGer
            plot(HistMind(:, 1), HistMind(:, 2), '--go', Mind(1, 1), Mind(1,2), '*')
        end
        hold on;        
        title('Histórico de Melhores Individuos');
        xlabel('x1'); 
        ylabel('x2');
    end
   
    if opcoes.numeroVariaveis == 3
        clf(1)
        subplot(1,2,1)
        plot3(HistMind(:, 1), HistMind(:, 2), HistMind(:, 3), '--go')
        if opcoes.numeroMaximoGeracoes == ContGer
            plot3(HistMind(:, 1), HistMind(:, 2), HistMind(:, 3), '--go', Mind(1, 1), Mind(1,2), Mind(1,3), '*')
        end
        hold on;
        title('Histórico de Melhores Individuos');
        xlabel('x1'); 
        ylabel('x2');
        zlabel('x3');
    end
    
    hold off; grid off;

    figure(1); grid on; subplot(1,2,2);
    plot(Ger,fx,'ko-','LineWidth', 1);
    hold on;
    title('Desenvolvimento do GA');
    xlabel('Geração'); ylabel('F(x)')
    axis([1,ContGer+1,-0.1,fx(1)+0.3])
    hold off; grid off;
end
