function [NewPop] = cruzamento(PopSel)


cont = 0;

for ia = 1:2:size(PopSel,1)
    cont = cont+1;
    for ib = 1:size(PopSel,2)
        %mexer aqui para mutar ou não mutar
%         tau = 1; %não cruza ninquem
%         tau = 0; %cruza todo mundo
        tau = randint(1); %50% de chance de cruzar
        
        if tau == 1
            NewPop(cont,ib) = PopSel(ia,ib); %se tau ==1 não cruza
        else
            NewPop(cont,ib) = PopSel(ia+1,ib); %se tau ==0 cruza
        end
    end
end
