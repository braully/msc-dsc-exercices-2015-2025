#include <iostream>
#include <cassert>
#include <cmath>
#include <cfloat>
#include <climits>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdio>
#include <string>
#include <sstream>

#include "AleatorioExponencial.h"
#include "estrutura-dados/Heap.h"
#include "estrutura-dados/Lista.h"
#include "tipo/Pessoa.h"
#include "tipo/PessoaFila.h"
#include "tipo/Tempo.h"
#include "visualizacao.h"
#include "parametros-simulacao.h"

#define TEMPO_SIMULACAO_EM_MINUTOS 90 //Em minutos
#define OFFSET_HORA_INICIAL 7
#define OFFSET_MINUTO_INICIAL 30
#define TEMPO_MAXIMO_ESPERA_FILA101 600
#define TEMPO_MAXIMO_ESPERA_FILA102 600
#define TEMPO_MAXIMO_ESPERA_FILA_TAXI 600
#define MAXIMO_PESSOA_PONTO_ONIBUS 10
#define TEMPO_DESLOCAMENTO_ENTRE_PONTOS 60 //Em segundos
#define TEMPO_DESLOCAMENTO_ENTRE_TAXI_PONTO102 180
#define TEMPO_DESLOCAMENTO_ENTRE_TAXI_PONTO101 120

using namespace std;

// Contadores
int quantidadeEmbarcouEm102eNaoIraParaP = 0;
int tempoMaximoEsperaPessoaQvaiPraPembarcando101 = 0;
int tempoMaximoEsperaPessoaQNaoVaiPraPembarcando102 = 0;
int tempoMaximoEsperaPessoaDecideIrAPe = 0;
int numeroMaximoDePessoasEsperandoEm102QVaoPraP = 0;
int quantidadeEmbarcouTaxieIraParaP = 0;
int quantidadePessoasEm102QuerendoIrParaP = 0;
int totaTempoEsperaPessoasEmbarcaramEm101 = 0;
int quantaidadePessoasEmbarcaramEm101 = 0;


//filas
Lista<Pessoa> filaPonto101 = Lista<Pessoa>("Ponto da Linha 101");
Lista<Pessoa> filaPonto102 = Lista<Pessoa>("Ponto da Linha 102");
Lista<Pessoa> filaPontoTaxi = Lista<Pessoa>("Ponto de Taxi");

//
Lista<Pessoa> listaPessoasPassaram101ComDestinoAP = Lista<Pessoa>("Pessoas que passaram no Ponto da Linha 101 com destino a P.");

//Marca o tempo atual da simulação
Tempo momentoAtualSimulacao = Tempo();
int tempoTotalSimulacao = 0;

//Momento de entradas de pessoas novas nas filas
Heap entradaPessoasFila = Heap();
Heap chegadaOnibus = Heap();
Heap chegadaTaxi = Heap();

/*
 */

void pessoaDecideIrAPe(Pessoa *pessoa) {
    if (pessoa != NULL) {
        int tempoAtual = momentoAtualSimulacao.getTempo();
        int tempoChegadaPrimeiraFila = pessoa->getTempoChegadaPrimeiraFila();
        int tempoEsperaTotal = tempoAtual - tempoChegadaPrimeiraFila;
        if (tempoEsperaTotal > tempoMaximoEsperaPessoaDecideIrAPe) {
            tempoMaximoEsperaPessoaDecideIrAPe = tempoEsperaTotal;
        }
        pessoa->insereEvento(momentoAtualSimulacao.getTempoNormalizado(), "Sai da fila e vai a pé para o local P.");
    }
}

void pessoaChegouNoPonto101(Pessoa *pessoa) {
    if (pessoa != NULL) {
        if (pessoa->isPretendeChegarEmP()) {
            listaPessoasPassaram101ComDestinoAP.insere_fim(pessoa);
            int tempo = momentoAtualSimulacao.getTempoNormalizado();
            pessoa->insereEvento(tempo, "Chegou no ponto 101.");
        }
    }
}

void pessoaChegouNoPonto102(Pessoa *pessoa) {
    if (pessoa != NULL) {
        pessoa->insereEvento(momentoAtualSimulacao.getTempoNormalizado(), "Chegou no ponto 102.");
        if (pessoa->isPretendeChegarEmP()) {
            quantidadePessoasEm102QuerendoIrParaP++;
            if (quantidadePessoasEm102QuerendoIrParaP > numeroMaximoDePessoasEsperandoEm102QVaoPraP) {
                numeroMaximoDePessoasEsperandoEm102QVaoPraP = quantidadePessoasEm102QuerendoIrParaP;
            }
        }
    }
}

void pessoaChegouNoPontoTaxi(Pessoa *pessoa) {
    if (pessoa != NULL) {
        pessoa->insereEvento(momentoAtualSimulacao.getTempoNormalizado(), "Chegou no ponto de táxi.");
    }
}

void pessoaChegouNoPonto(Lista<Pessoa> *ponto, Pessoa *pessoa) {
    if (detalhar && pessoa != NULL && ponto != NULL) {
        cout << momentoAtualSimulacao << " - ";
        printf("\nPessoa: ");
        pessoa->printPessoa();
        printf(" chegou em: %s", ponto->getNome());
    }
    if (ponto == &filaPonto101) {
        pessoaChegouNoPonto101(pessoa);
    } else if (ponto == &filaPonto102) {
        pessoaChegouNoPonto102(pessoa);
    } else {
        pessoaChegouNoPontoTaxi(pessoa);
    }
}

void entradaDePessoasPonto() {
    if (detalhar) {
        cout << momentoAtualSimulacao << " - ";
        printf("Verificando chegada de pessoas nos pontos\n");
    }

    if (entradaPessoasFila.vazio())
        return;

    int tempoAtual = momentoAtualSimulacao.getTempo();
    int proximaEntrada = entradaPessoasFila.topChave();
    //
    while (proximaEntrada == tempoAtual && !entradaPessoasFila.vazio()) {
        PessoaFila *pf = (PessoaFila *) entradaPessoasFila.topDado();
        if (pf != NULL) {
            Pessoa* pessoa = pf->getPessoa();
            Lista<Pessoa>* fila = pf->getFila();
            if (fila != NULL && pessoa != NULL) {
                pessoa->gerarIdentificacao();
                pessoa->setTempoChegadaFilaAtual(tempoAtual);
                fila->insere_fim(pessoa);
                pessoaChegouNoPonto(fila, pessoa);
            }
        }
        entradaPessoasFila.remove();
        proximaEntrada = entradaPessoasFila.topChave();
    }
}

void saidaDePessoasPonto() {

}

void onibus101Passou() {
    cout << momentoAtualSimulacao;
    printf(" - Onibus 101 Passou\n");
    int tempoAtualDaSimulacao = momentoAtualSimulacao.getTempo();
    if (!filaPonto101.vazio()) {
        for (int i = 0; i < filaPonto101.tamanho(); i++) {
            Pessoa* p = filaPonto101.elemento(i);
            if (p != NULL) {
                int tempoChegadaFilaAtual = p->getTempoChegadaFilaAtual();
                int tempoEspera = tempoAtualDaSimulacao - tempoChegadaFilaAtual;
                if (p->isPretendeChegarEmP() && tempoEspera >= TEMPO_MAXIMO_ESPERA_FILA101) {
                    cout << momentoAtualSimulacao << " - ";
                    printf("Pessoa: ");
                    p->printPessoa();
                    printf(" esperando a mais de 10min e quer ir para P - ");

                    int tempEsperMinutos = (tempoEspera / OFFSET_MINUTO_SEGUNDOS);
                    std::stringstream sstm;
                    sstm << "Ônibus 101 passou e esperando a " << tempEsperMinutos << " minutos.";
                    p->insereEvento(momentoAtualSimulacao.getTempoNormalizado(), sstm.str());

                    //Pessoa na fila do ponto 101 que vai para P
                    //e está esperando a mais tempo que o maximo determinado
                    int sorteioSaidaFila = rand() % 2; //50% de chance
                    if (sorteioSaidaFila == 0) {
                        printf("Irá para a fila 102.\n");
                        //Pessoa cansou de esperar e vai para a fila 102
                        p->insereEvento(momentoAtualSimulacao.getTempoNormalizado(), "Sai do ponto da linha 101 e se desloca para o ponto da linha 102.");
                        filaPonto101.remove(i); //Sai da fila 101
                        double tempoDeDeslocamento = aleatorioExponencialPadrao() * TEMPO_DESLOCAMENTO_ENTRE_PONTOS;
                        PessoaFila *pf = new PessoaFila(p, &filaPonto102);
                        int horarioChegadaPonto102 = tempoDeDeslocamento + tempoAtualDaSimulacao;
                        entradaPessoasFila.adiciona(horarioChegadaPonto102, pf);
                    } else {
                        p->insereEvento(momentoAtualSimulacao.getTempoNormalizado(), "Decide continuar esperando.");
                        printf("Continuará esperando.\n");
                    }
                }
            }
        }
    }
}

void onibus102Passou() {
    cout << momentoAtualSimulacao << " - ";
    printf("Onibus 102 Passou\n");
    int tempoAtualDaSimulacao = momentoAtualSimulacao.getTempo();
    if (!filaPonto102.vazio()) {
        for (int i = 0; i < filaPonto102.tamanho(); i++) {
            Pessoa* p = filaPonto102.elemento(i);
            if (p != NULL) {
                int tempoChegadaFilaAtual = p->getTempoChegadaFilaAtual();
                int tempoEspera = tempoAtualDaSimulacao - tempoChegadaFilaAtual;
                if (p->isPretendeChegarEmP() && tempoEspera >= TEMPO_MAXIMO_ESPERA_FILA102) {
                    int tempEsperMinutos = (tempoEspera / OFFSET_MINUTO_SEGUNDOS);
                    std::stringstream sstm;
                    sstm << "Ônibus passou e esperando a " << tempEsperMinutos << " minutos";
                    p->insereEvento(momentoAtualSimulacao.getTempoNormalizado(), sstm.str());
                    cout << momentoAtualSimulacao << " - ";
                    printf("Pessoa: ");
                    p->printPessoa();
                    printf(" esperando a mais de 10min e quer ir para P - ");
                    //Pessoa na fila do ponto 101 que vai para P
                    //e está esperando a mais tempo que o maximo determinado
                    int sorteioSaidaFila = rand() % 5; // 1/5 de chance
                    if (sorteioSaidaFila == 0) {
                        int temDinheiro = rand() % 5; // 1/5 de chance
                        p->insereEvento(momentoAtualSimulacao.getTempoNormalizado(), "Decide sair da fila 102.");
                        if (filaPontoTaxi.tamanho() <= MAXIMO_PESSOA_PONTO_ONIBUS) {
                            if (temDinheiro == 0) {
                                printf("Irá para o ponto de taxi.\n");
                                double tempoDeDeslocamento = aleatorioExponencialPadrao() * TEMPO_DESLOCAMENTO_ENTRE_TAXI_PONTO102;
                                p->insereEvento(momentoAtualSimulacao.getTempoNormalizado(), "Sai da fila 102 e vai para o ponto de táxi.");
                                PessoaFila *pf = new PessoaFila(p, &filaPontoTaxi);
                                int horarioChegadaPontoTaxi = tempoDeDeslocamento + tempoAtualDaSimulacao;
                                entradaPessoasFila.adiciona(horarioChegadaPontoTaxi, pf);
                            } else {
                                p->insereEvento(momentoAtualSimulacao.getTempoNormalizado(), "Não tem dinheiro suficiente para pegar um táxi.");
                                pessoaDecideIrAPe(p);
                            }
                        } else {
                            std::stringstream sstm2;
                            sstm2 << "Existem " << filaPontoTaxi.tamanho() << " pessoas esperando no ponto de táxi.";
                            p->insereEvento(momentoAtualSimulacao.getTempoNormalizado(), sstm2.str());
                            pessoaDecideIrAPe(p);
                        }
                        //Pessoa cansou de esperar e vai para a fila 102
                        filaPonto102.remove(i); //Sai da fila 101
                    } else {
                        p->insereEvento(momentoAtualSimulacao.getTempoNormalizado(), "Decide esperar o próximo onibus 102.");
                        printf("Continuará esperando.\n");
                    }
                }
            }
        }
    }
}

void taxiPassou() {
    cout << momentoAtualSimulacao << " - ";
    printf("Taxi saiu do ponto\n");
    int tempoAtualDaSimulacao = momentoAtualSimulacao.getTempo();
    if (!filaPontoTaxi.vazio()) {
        for (int i = 0; i < filaPontoTaxi.tamanho(); i++) {
            Pessoa* p = filaPontoTaxi.elemento(i);
            if (p != NULL) {
                int tempoChegadaFilaAtual = p->getTempoChegadaFilaAtual();
                int tempoEspera = tempoAtualDaSimulacao - tempoChegadaFilaAtual;
                if (p->isPretendeChegarEmP() && tempoEspera >= TEMPO_MAXIMO_ESPERA_FILA_TAXI) {
                    cout << momentoAtualSimulacao << " - ";
                    printf("Pessoa: ");
                    p->printPessoa();
                    int tempEsperMinutos = (tempoEspera / OFFSET_MINUTO_SEGUNDOS);
                    std::stringstream sstm;
                    sstm << "Taxi acaba de sair, esperando na fila a " << tempEsperMinutos << " minutos.";
                    p->insereEvento(momentoAtualSimulacao.getTempoNormalizado(), sstm.str());
                    printf(" esperando a mais de 10min e quer ir para P - Sai da fila e vai a pé.");
                    pessoaDecideIrAPe(p);
                    filaPontoTaxi.remove(i); //Sai da fila e vai a pé
                }
            }
        }
    }
}

void pessoaEmbarcouTaxi(Pessoa *pessoa) {
    if (pessoa != NULL) {
        if (pessoa->isPretendeChegarEmP()) {
            quantidadeEmbarcouTaxieIraParaP++;
        }
        pessoa->insereEvento(momentoAtualSimulacao.getTempoNormalizado(), "Embarcou no táxi.");
    }
}

void pessoaEmbarcouOnibus101(Pessoa *pessoa) {
    if (pessoa != NULL) {
        int tempoChegadaFilaAtual = pessoa->getTempoChegadaFilaAtual();
        int tempoAtualSimulacao = momentoAtualSimulacao.getTempo();
        int tempoEsperaPessoa = tempoAtualSimulacao - tempoChegadaFilaAtual;
        if (pessoa->isPretendeChegarEmP()) {
            if (tempoEsperaPessoa > tempoMaximoEsperaPessoaQvaiPraPembarcando101) {
                tempoMaximoEsperaPessoaQvaiPraPembarcando101 = tempoEsperaPessoa;
            }
        }
        totaTempoEsperaPessoasEmbarcaramEm101 = totaTempoEsperaPessoasEmbarcaramEm101 + tempoEsperaPessoa;
        quantaidadePessoasEmbarcaramEm101++;
        pessoa->insereEvento(momentoAtualSimulacao.getTempoNormalizado(), "Embarcou no ônibus 101.");
    }
}

void pessoaEmbarcouOnibus102(Pessoa *pessoa) {
    if (pessoa != NULL) {
        if (!pessoa->isPretendeChegarEmP()) {
            int tempoChegadaFilaAtual = pessoa->getTempoChegadaFilaAtual();
            int tempoAtualSimulacao = momentoAtualSimulacao.getTempo();
            int tempoEsperaPessoa = tempoAtualSimulacao - tempoChegadaFilaAtual;
            if (tempoEsperaPessoa > tempoMaximoEsperaPessoaQNaoVaiPraPembarcando102) {
                tempoMaximoEsperaPessoaQNaoVaiPraPembarcando102 = tempoEsperaPessoa;
            }
        } else {
            quantidadePessoasEm102QuerendoIrParaP--;
        }
        pessoa->insereEvento(momentoAtualSimulacao.getTempoNormalizado(), "Embarcou no ônibus 102.");
    }
}

void pessoaEmbarcou(Lista<Pessoa> *pontoOnibus, Pessoa *pessoa) {
    if (pontoOnibus == &filaPonto101) {
        pessoaEmbarcouOnibus101(pessoa);
    } else if (pontoOnibus == &filaPonto102) {
        pessoaEmbarcouOnibus102(pessoa);
    }
}

void onibusPassou(Lista<Pessoa> *pontoOnibus) {
    if (pontoOnibus == &filaPonto101) {
        onibus101Passou();
    } else if (pontoOnibus == &filaPonto102) {
        onibus102Passou();
    }
}

void chegadaDeOnibus() {
    if (detalhar) {
        cout << momentoAtualSimulacao << " - ";
        printf("Verificando chegada de ônibus\n");
    }

    if (chegadaOnibus.vazio())
        return;

    int tempoAtual = momentoAtualSimulacao.getTempo();
    int proximaChegada = chegadaOnibus.topChave();
    //
    while (proximaChegada == tempoAtual && !chegadaOnibus.vazio()) {//Caso ocorra mais de uma chegada ao mesmo tempo
        Lista<Pessoa> *pontoOnibus = (Lista<Pessoa> *) chegadaOnibus.topDado();
        if (pontoOnibus != NULL) {
            int quantidadeVagasOnibus = rand() % 10;
            cout << momentoAtualSimulacao << " - ";
            printf("Onibus chegou em: %s -> com %d vaga(s)\n", pontoOnibus->getNome(), quantidadeVagasOnibus);
            printf("\tlevando a(s) pessoa(s): {");
            for (int i = 0; i < quantidadeVagasOnibus; i++) {
                if (!pontoOnibus->vazio()) {
                    Pessoa * p = pontoOnibus->remove_inicio();
                    if (p != NULL) {
                        pessoaEmbarcou(pontoOnibus, p);
                        p->printPessoa();
                        printf(", ");
                    }
                }
            }
            printf("}\n");
        }
        chegadaOnibus.remove();
        proximaChegada = chegadaOnibus.topChave();
        onibusPassou(pontoOnibus);
    }
}

void chegadaDeTaxi() {
    if (detalhar) {
        cout << momentoAtualSimulacao << " - ";
        printf("Verificando chegada de táxi\n");
    }

    if (chegadaTaxi.vazio())
        return;

    int tempoAtual = momentoAtualSimulacao.getTempo();
    int proximaEntrada = chegadaTaxi.topChave();
    //
    while (proximaEntrada <= tempoAtual && !chegadaTaxi.vazio()) {
        if (proximaEntrada == tempoAtual) {
            cout << momentoAtualSimulacao << " - ";
            printf("Táxi chegou no ponto.");
            if (filaPontoTaxi.vazio()) {
                printf(" - Não existem pessoas esperando, táxi fica em espera.\n");
            }
            printf("\n");
        }

        if (filaPontoTaxi.vazio()) {
            //            printf("Não existem pessoas esperando, táxi fica em espera.\n");
            break;
        }

        //O mesmo taxi transporta pessoas do mesmo grupo
        Pessoa *p = filaPontoTaxi.remove_inicio();

        printf("\tlevando o grupo de pessoa(s): {");
        if (p != NULL && !filaPontoTaxi.vazio()) {
            Pessoa * prox;
            p->printPessoa();
            printf(", ");
            while ((prox = filaPontoTaxi.elemento(0)) != NULL && prox->getGrupo() >= 0 && prox->getGrupo() == p->getGrupo()) {
                p = filaPontoTaxi.remove_inicio();
                pessoaEmbarcouTaxi(p);
                printf(", ");
            }
            printf("}\n");
        }
        chegadaTaxi.remove();
        proximaEntrada = chegadaTaxi.topChave();
        taxiPassou();
    }
}

void chegadaDeTransportes() {
    chegadaDeOnibus();
    chegadaDeTaxi();
}

//http://www.pamvotis.org/vassis/RandGen.htm

int *gerarDistribuicaoAleatoriaExponencial(int numeroMaximo, int quantidadeDistribuicoes) {
    //    std::default_random_engine geradorNumerosAleatorios;
    //    std::exponential_distribution<double> distribuicaoAleatoriaExponencial(LAMBDA_DISTRIBUICAO);
    int *distrib = new int[quantidadeDistribuicoes];

    for (int i = 0; i < quantidadeDistribuicoes; i++) {
        //        double numero = distribuicaoAleatoriaExponencial(geradorNumerosAleatorios);
        double numero = aleatorioExponencialPadrao();
        distrib[i] = int(numeroMaximo * numero);
    }
    //    std::sort(distrib, distrib + quantidadeDistribuicoes);
    return distrib;
}

void gerarMomentoChegadaTransportes() {
    int janelaDeTempoTotalSimulacao = tempoTotalSimulacao - offsetChegadaPrimeiroOnibus101;
    int quantidadeTotalOnibusLinha101 = janelaDeTempoTotalSimulacao / fatorChegadaOnibus101;
    int *momentosChegadaOnibus101 = gerarDistribuicaoAleatoriaExponencial(janelaDeTempoTotalSimulacao, quantidadeTotalOnibusLinha101);
    for (int i = 0; i < quantidadeTotalOnibusLinha101; i++) {
        int tmp = momentosChegadaOnibus101[i] + offsetChegadaPrimeiroOnibus101;
        chegadaOnibus.adiciona(tmp, &filaPonto101);
    }

    janelaDeTempoTotalSimulacao = tempoTotalSimulacao - offsetChegadaPrimeiroOnibus102;
    quantidadeTotalOnibusLinha101 = janelaDeTempoTotalSimulacao / fatorChegadaOnibus102;
    int quantidadeTotalOnibusLinha102 = janelaDeTempoTotalSimulacao / fatorChegadaOnibus102;
    int *momentosChegadaOnibus102 = gerarDistribuicaoAleatoriaExponencial(janelaDeTempoTotalSimulacao, quantidadeTotalOnibusLinha102);
    for (int i = 0; i < quantidadeTotalOnibusLinha102; i++) {
        chegadaOnibus.adiciona(momentosChegadaOnibus102[i] + offsetChegadaPrimeiroOnibus102, &filaPonto102);
    }

    janelaDeTempoTotalSimulacao = tempoTotalSimulacao - offsetChegadaPrimeiroTaxi;
    quantidadeTotalOnibusLinha101 = janelaDeTempoTotalSimulacao / fatorChegadaTaxi;
    int quantidadeTotalOnibusLinhaTaxi = tempoTotalSimulacao / fatorChegadaTaxi;
    int *momentosChegadaOnibusTaxi = gerarDistribuicaoAleatoriaExponencial(tempoTotalSimulacao, quantidadeTotalOnibusLinhaTaxi);
    for (int i = 0; i < quantidadeTotalOnibusLinhaTaxi; i++) {
        chegadaTaxi.adiciona(momentosChegadaOnibusTaxi[i] + offsetChegadaPrimeiroTaxi, &filaPontoTaxi);
    }
}

void gerarMomentoEntradasPessoasNovasFilas() {
    if (detalhar) {
        printf("Gerando momentos de entradas de novas pessoas\n");
    }

    int janelaDeTempoTotalSimulacao = tempoTotalSimulacao - offsetChegadaPrimeiraPessoaFila101;
    int quantidadePessoasGeradasFila101 = janelaDeTempoTotalSimulacao / fatorChegadaPessoasFila101;
    int *momentosChegadaFila101 = gerarDistribuicaoAleatoriaExponencial(tempoTotalSimulacao, quantidadePessoasGeradasFila101);

    janelaDeTempoTotalSimulacao = tempoTotalSimulacao - offsetChegadaPrimeiraPessoaFila102;
    int quantidadePessoasGeradasFila102 = janelaDeTempoTotalSimulacao / fatorChegadaPessoasFila102;
    int *momentosChegadaFila102 = gerarDistribuicaoAleatoriaExponencial(tempoTotalSimulacao, quantidadePessoasGeradasFila102);

    janelaDeTempoTotalSimulacao = tempoTotalSimulacao - offsetChegadaPrimeiroTaxi;
    int quantidadePessoasGeradasFilaTaxi = janelaDeTempoTotalSimulacao / fatorChegadaPessoasFilaTaxi;
    int *momentosChegadaFilaTaxi = gerarDistribuicaoAleatoriaExponencial(tempoTotalSimulacao, quantidadePessoasGeradasFilaTaxi);

    if (detalhar) {
        //Para efeitos de DEBUG
        printf("\nFila 101: {");
        for (int i = 0; i < quantidadePessoasGeradasFila101; i++) {
            printf("%d, ", momentosChegadaFila101[i]);
        }
        printf("}\n");
    }

    for (int i = 0; i < quantidadePessoasGeradasFila101; i++) {
        Pessoa *p = new Pessoa();
        int sorteioDestino = rand() % 3;
        if (sorteioDestino == 1) {
            p->setPretendeChegarEmP(true);
        }
        PessoaFila *pf = new PessoaFila(p, &filaPonto101);
        entradaPessoasFila.adiciona(momentosChegadaFila101[i] + offsetChegadaPrimeiraPessoaFila101, pf);
    }


    for (int i = 0; i < quantidadePessoasGeradasFila102; i++) {
        Pessoa *p = new Pessoa();
        PessoaFila *pf = new PessoaFila(p, &filaPonto102);
        entradaPessoasFila.adiciona(momentosChegadaFila102[i] + offsetChegadaPrimeiraPessoaFila102, pf);
    }

    for (int i = 0; i < quantidadePessoasGeradasFilaTaxi; i++) {
        int quantidadePessoasGrupoTaxi = 1;
        int sorteioQuantidadePessoasGrupo = (rand() % 20) + 1;
        if (sorteioQuantidadePessoasGrupo >= 13 && sorteioQuantidadePessoasGrupo <= 18) {
            quantidadePessoasGrupoTaxi = 2;
        } else if (sorteioQuantidadePessoasGrupo == 19) {
            quantidadePessoasGrupoTaxi = 3;
        } else if (sorteioQuantidadePessoasGrupo == 20) {
            quantidadePessoasGrupoTaxi = 4;
        }
        //Gerar grupo de pessoas
        for (int j = 0; j < quantidadePessoasGrupoTaxi; j++) {
            Pessoa *p = new Pessoa();
            p->setGrupo(i); //Grupo que a pessoa pertence
            PessoaFila *pf = new PessoaFila(p, &filaPontoTaxi);
            entradaPessoasFila.adiciona(momentosChegadaFilaTaxi[i] + offsetChegadaPrimeiraPessoaFilaTaxi, pf);
        }
    }
}

void inicializarSimulacao() {
    if (detalhar) {
        printf("Inicializando a simulação\n");
    }
    srand(time(NULL)); //Semear a aletoriedade

    //Instancia o tempo inicando em hora inicial (7) e minuto inicial (30)
    int tInicio = OFFSET_HORA_INICIAL * OFFSET_HORA_SEGUNDOS + OFFSET_MINUTO_INICIAL * OFFSET_MINUTO_SEGUNDOS;
    tempoTotalSimulacao = TEMPO_SIMULACAO_EM_MINUTOS*OFFSET_MINUTO_SEGUNDOS;
    momentoAtualSimulacao.setOffset(tInicio);
    gerarMomentoEntradasPessoasNovasFilas();
    gerarMomentoChegadaTransportes();
}

void exibirResultadosSimulacao() {
    cout << endl << endl << "************* RESULTADO SIMULAÇÃO *************" << endl;
    Tempo temp;
    cout << "1 - Número máximo de pessoas:" << endl;
    cout << "\t* Esperando no ponto 101: " << filaPonto101.getTamanhoMaximoAtingido() << endl;
    cout << "\t* Esperando no ponto 102: " << filaPonto102.getTamanhoMaximoAtingido() << endl;
    cout << "\t* Esperando no ponto táxi: " << filaPontoTaxi.getTamanhoMaximoAtingido() << endl;
    cout << "\t* Esperando no ponto da linha 102 e que iriam para o local P:" << numeroMaximoDePessoasEsperandoEm102QVaoPraP << endl;
    /* */
    cout << "2 - Tempo máximo de espera de uma pessoa: " << endl;
    temp.setTempo(tempoMaximoEsperaPessoaQNaoVaiPraPembarcando102);
    cout << "\t* Que entrou no ônibus da linha 102 e não iriam para o local P: " << temp << endl;
    temp.setTempo(tempoMaximoEsperaPessoaQvaiPraPembarcando101);
    cout << "\t* Que entrou no ônibus da linha 101 e iriam para o local P: " << temp << endl;

    cout << "\t* Que decidiu ir a pé ao local P: ";
    if (tempoMaximoEsperaPessoaDecideIrAPe > 0) {
        temp.setTempo(tempoMaximoEsperaPessoaDecideIrAPe);
        cout << temp << endl;
    } else {
        cout << "Ninguem foi a pé ao local P." << endl;
    }
    /* */
    cout << "3 - Numero de pessoas que foram de táxi ao local P: " << quantidadeEmbarcouTaxieIraParaP << endl;
    cout << "4 - Tempo médio de espera das pessoas que entraram em um ônibus da linha 101: ";
    if (quantaidadePessoasEmbarcaramEm101 > 0) {
        int tempoMedio = totaTempoEsperaPessoasEmbarcaramEm101 / quantaidadePessoasEmbarcaramEm101;
        temp.setTempo(tempoMedio);
        cout << temp;
    } else {
        cout << "Ninguem embarcou em 101.";
    }
    cout << endl;
}

void rastrearCaminhoPessoa() {
    cout << endl << "**** Rastrear Pessoa ****" << endl;
    int tamanho = listaPessoasPassaram101ComDestinoAP.tamanho();
    if (tamanho > 0) {
        cout << endl << "Numero de pessoas que chegaram ao ponto 101 que queriam ir ao local P: " << tamanho << endl;
        int numPessoa = 0;
        do {
            cout << endl << "Informe um numero de 1 até " << tamanho << " (digite qualquer valor fora do intervalo para sair):" << endl;
            int sc = scanf("%d", &numPessoa);
            if (numPessoa > 0 && numPessoa <= tamanho) {
                Pessoa* pessoa = listaPessoasPassaram101ComDestinoAP.elemento(numPessoa - 1);
                if (pessoa != NULL) {
                    cout << "\tInformações da Pessoa: ";
                    pessoa->printPessoa();
                    cout << ": " << endl;
                    pessoa->printCaminhoPercorrido();
                }
            }
        } while (numPessoa > 0 && numPessoa <= tamanho);
    } else {
        cout << "Nenhuma pessoa que chegou no ponto 101 desejava ir para o local P.";
    }
}

/* SIMULAÇAO PROPRIAMENTE DITA */
int main(int argc, char** argv) {
    /* Coletar os dados inicias da simulação */
    if (lerParametrosEntrada) {
        int limiteInferiorTempoSimulacao = OFFSET_HORA_INICIAL * OFFSET_HORA_SEGUNDOS + OFFSET_MINUTO_INICIAL * OFFSET_MINUTO_SEGUNDOS;
        int limiteSuperiorTempoSimulacao = limiteInferiorTempoSimulacao + TEMPO_SIMULACAO_EM_MINUTOS*OFFSET_MINUTO_SEGUNDOS;
        entradaParametrosSimulacao(limiteInferiorTempoSimulacao, limiteSuperiorTempoSimulacao);
    }

    /* Inicializar os dados da simulação */
    inicializarSimulacao();

    cout << endl << "************* SIMULAÇÃO *************" << endl;

    for (int m = 0; m < TEMPO_SIMULACAO_EM_MINUTOS; m++) {
        for (int s = 0; s < QUANTIDADE_SEGUNDOS_EM_MINUTOS; s++) {
            //Atualizar o tempo atual da simulação
            momentoAtualSimulacao.setTempo(m * OFFSET_MINUTO_SEGUNDOS + s);
            //Entrada de novas pessoas nas filas no tempo t
            entradaDePessoasPonto();
            chegadaDeTransportes();
            saidaDePessoasPonto();
        }
        if (detalharCadaMinuto) {
            cout << endl << "Tempo: ";
            cout << momentoAtualSimulacao;
            cout << endl;
            imprimirSituacaoListaPessoas("Fila do ponto de ônibus da linha 101", &filaPonto101);
            imprimirSituacaoListaPessoas("Fila do ponto de ônibus da linha 102", &filaPonto102);
            imprimirSituacaoListaPessoas("Fila do ponto de ônibus", &filaPontoTaxi);
            //    imprimirListaPessoas("Fila do ponto de onibus da linha 101", &filaPonto101);
            //    imprimirListaPessoas("Fila do ponto de onibus da linha 102", &filaPonto102);
            //    imprimirListaPessoas("Fila do ponto de onibus da linha taxi", &filaPontoTaxi);
        }
    }

    //Detalhar situação ao final
    //    imprimirSituacaoListaPessoas("Fila do ponto de onibus da linha 101", &filaPonto101);
    //    imprimirSituacaoListaPessoas("Fila do ponto de onibus da linha 102", &filaPonto102);
    //    imprimirSituacaoListaPessoas("Fila do ponto de Taxi", &filaPontoTaxi);
    //    imprimirListaPessoas("Fila do ponto de onibus da linha 101", &filaPonto101);
    //    imprimirListaPessoas("Fila do ponto de onibus da linha 102", &filaPonto102);
    //    imprimirListaPessoas("Fila do ponto de onibus da linha taxi", &filaPontoTaxi);

    printParametrosSimulacao(momentoAtualSimulacao.getOffset());
    exibirResultadosSimulacao();
    rastrearCaminhoPessoa();

    cout << endl << endl;
    return 0;
}


