/* 
 * File:   Pessoa.h
 * Author: braully
 *
 * Created on 7 de Dezembro de 2014, 10:48
 */

#ifndef PESSOA_H
#define	PESSOA_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "../estrutura-dados/Lista.h"
#include "EventoPessoa.h"
#include "Tempo.h"

#define MAX_CAMINHO_PERCORRER 10;


static int contador_pessoa = 0;

class Pessoa {
public:
    Pessoa();
    Pessoa(const Pessoa& orig);
    Pessoa(const Pessoa* orig);
    virtual ~Pessoa();

    int gerarIdentificacao() {
        if (identificador < 0) {
            identificador = contador_pessoa++;
        }
        return identificador;
    }

    int getIdentificador() {
        return identificador;
    }

    bool isPretendeChegarEmP() {
        return pretendeChegarEmP;
    }

    void setPretendeChegarEmP(bool pretendeChegar) {
        pretendeChegarEmP = pretendeChegar;
    }

    int getGrupo() {
        return grupo;
    }

    void setGrupo(int gp) {
        grupo = gp;
    }

    void printPessoa() {
        printf("(id: %d", identificador);
        if (grupo >= 0) {
            printf(", grupo: %d", grupo);
        }
        if (pretendeChegarEmP) {
            printf(", P");
        }
        printf(")");
    }

    void insereEvento(int m, std::string evento) {
        eventos.insere_fim(new EventoPessoa(evento, m));
    }

    //    void insereEvento(Tempo *momento, std::string evento) {
    //        eventos.insere_fim(new EventoPessoa(evento, momento->getTempoNormalizado()));
    //    }

    void printCaminhoPercorrido() {
        for (int i = 0; i < eventos.tamanho(); i++) {
            EventoPessoa* eventoPessoa = eventos.elemento(i);
            Tempo temp;
            if (eventoPessoa != NULL) {
                int momento = eventoPessoa->GetMomento();
                temp.setTempo(momento);
                std::cout << "\t\t evento " << i + 1 << " - " << temp << " -> " << eventoPessoa->GetEvento() << endl;
            }
        }
    }

    int getTempoChegadaFilaAtual() {
        return tempoChegadaFilaAtual;
    }

    int getTempoChegadaPrimeiraFila() {
        return tempoChegadaPrimeiraFila;
    }

    void setTempoChegadaFilaAtual(int temp) {
        if (tempoChegadaPrimeiraFila < 0) {
            tempoChegadaPrimeiraFila = temp;
        }
        tempoChegadaFilaAtual = temp;
    }
private:
    int identificador;
    int grupo;
    int tempoChegadaPrimeiraFila;
    int tempoChegadaFilaAtual;
    bool pretendeChegarEmP;
    Lista<EventoPessoa> eventos;
};

#endif	/* PESSOA_H */

