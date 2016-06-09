/* 
 * File:   Lista.h
 * Author: braully
 *
 * Created on 7 de Dezembro de 2014, 10:47
 */

#ifndef LISTA_H
#define	LISTA_H

#include <iostream>

template <typename Tipo>
class NoLista {
    template<class T> friend class Lista;
public:

    NoLista() {

    }

    NoLista(const Tipo& val) {
        valor = &val;
        proximo = NULL;
    }

    NoLista(Tipo *val) {
        valor = val;
        proximo = NULL;
    }

    ~NoLista() {

    }
private:
    Tipo* valor;
    NoLista *proximo;
};

template <typename Tipo>
class Lista {
public:

    Lista() {
        inicio = fim = NULL;
        tam = 0;
        tamanhoMaximoAtingido = 0;
    }

    Lista(const char * nm) {
        inicio = fim = NULL;
        tam = 0;
        nome = nm;
        tamanhoMaximoAtingido = 0;
    }

    Lista(const Lista& orig) {

    }

    ~Lista() {

    }

    bool vazio() {
        return tam == 0;
    }

    void insere_fim(Tipo *valor) {
        NoLista<Tipo> *novoNo = new NoLista<Tipo>(valor);
        if (fim == NULL) {
            fim = novoNo;
        } else {
            fim->proximo = novoNo;
            fim = novoNo;
        }
        if (inicio == NULL) {
            inicio = novoNo;
        }
        tam++;
        if (tam > tamanhoMaximoAtingido) {
            tamanhoMaximoAtingido = tam;
        }
    }

    Tipo* remove_inicio() {
        Tipo *ret;
        if (tam <= 0) {
            return NULL;
        }
        NoLista<Tipo> *tmp = inicio;
        ret = inicio->valor;
        inicio = inicio->proximo;
        delete tmp;
        if (tam == 1) {
            fim = NULL;
        }
        tam--;
        return ret;
    }

    Tipo* elemento(int posicao) {
        if (posicao < tam) {
            NoLista<Tipo> *p = inicio;
            for (int i = 0; i < posicao; i++) {
                p = p->proximo;
            }
            if (p != NULL)
                return p->valor;
        }
        return NULL;
    }

    Tipo* remove(int posicao) {
        Tipo* tmp = NULL;
        if (posicao == 0) {
            return remove_inicio();
        }
        if (posicao < tam) {
            NoLista<Tipo> *ant = inicio;
            NoLista<Tipo> *p;
            for (int i = 0; i < posicao - 1; i++) {
                ant = ant->proximo;
            }
            if (ant != NULL) {
                p = ant->proximo;
                tmp = p->valor;
                ant->proximo = p->proximo;
                if (p == fim) {
                    fim = ant;
                }
                delete p;
            }
            tam--;
        }
        return tmp;
    }

    int tamanho() {
        return tam;
    }

    const char* getNome() {
        return nome;
    }

    int getTamanhoMaximoAtingido() const {
        return tamanhoMaximoAtingido;
    }
private:
    int tamanhoMaximoAtingido;
    int tam;
    NoLista<Tipo> *inicio;
    NoLista<Tipo> *fim;
    const char *nome;
};
#endif	/* LISTA_H */

