/* 
 * File:   Pessoa.cpp
 * Author: braully
 * 
 * Created on 7 de Dezembro de 2014, 10:48
 */

#include "Pessoa.h"
#include <iostream>

Pessoa::Pessoa() {
    grupo = -1;
    identificador = -1;
    tempoChegadaFilaAtual = -1;
    tempoChegadaPrimeiraFila = -1;
    pretendeChegarEmP = false;

}

Pessoa::Pessoa(const Pessoa& orig) {
    //    identificador = orig.identificador;
    //    grupo = orig.grupo;
    //    pretendeChegarEmP = orig.pretendeChegarEmP;
}

Pessoa::Pessoa(const Pessoa* orig) {
    identificador = orig->identificador;
    grupo = orig->grupo;
    pretendeChegarEmP = orig->pretendeChegarEmP;
}

Pessoa::~Pessoa() {
}
