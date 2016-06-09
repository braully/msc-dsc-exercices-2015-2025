function [PopMut,delta] = mutacao(ContGer,NewPop,Linf,Lsup)

for ia = 1:size(NewPop,1)
    for ib = 1:size(NewPop,2)
        %mexer aqui para mutar ou não mutar
%         tau1 = 1;%não muta ninguem
%         tau1 = 0;%muta todo mundo
         tau1 = randint(1);%50% de chance de mutar
         
        delta = (1/ContGer) * (Linf + (Lsup-Linf).*rand(1));
        if tau1 == 0 %se tau1 == 0 muta
            tau2 = randint(1);
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
