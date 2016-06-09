/* 
 * File:   visualizacao.h
 * Author: braully
 *
 * Created on 11 de Dezembro de 2014, 10:18
 */

#ifndef VISUALIZACAO_H
#define	VISUALIZACAO_H

#include <cstdio>

#include "tipo/Pessoa.h"

void imprimirSituacaoListaPessoas(const char* nome_lista, Lista<Pessoa> *lista) {
    if (lista != NULL) {
        printf("\n%s -> Contem: %d pessoa(s)", nome_lista, lista->tamanho());
    } else {
        printf("\n%s -> Não Contem pessoas.", nome_lista);
    }
}

void imprimirListaPessoas(const char* nome_lista, Lista<Pessoa> *lista) {
    if (lista != NULL) {
        printf("\n%s -> \n", nome_lista);
        for (int i = 0; i < lista->tamanho(); i++) {
            Pessoa *p = lista->elemento(i);
            printf("\t(%d) -> id pessoa: ", i);
            p->printPessoa();

            //            printf("\t(%d) -> id pessoa: %d", i, p->getIdentificador());
            //            if (p->isPretendeChegarEmP()) {
            //                printf(" - deseja ir para P");
            //            }
            printf("\n");
        }
    } else {
        printf("\n%s -> Não Contem pessoas.", nome_lista);
    }
}

#endif

