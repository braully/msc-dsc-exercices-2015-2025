/* 
 * File:   PessoaFila.h
 * Author: braully
 *
 * Created on 11 de Dezembro de 2014, 13:17
 */

#ifndef PESSOAFILA_H
#define	PESSOAFILA_H

#include "Pessoa.h"
#include "../estrutura-dados/Lista.h"

class PessoaFila {
public:
    PessoaFila();
    PessoaFila(const PessoaFila& orig);
    virtual ~PessoaFila();

    PessoaFila(Pessoa* p, Lista<Pessoa>* f) {
        fila = f;
        pessoa = p;
    }

    Lista<Pessoa>* getFila() {
        return fila;
    }

    void setFila(Lista<Pessoa>* fila) {
        this->fila = fila;
    }

    Pessoa* getPessoa() {
        return pessoa;
    }

    void setPessoa(Pessoa* pessoa) {
        this->pessoa = pessoa;
    }

private:
    Pessoa *pessoa;
    Lista<Pessoa> *fila;
};

#endif	/* PESSOAFILA_H */

