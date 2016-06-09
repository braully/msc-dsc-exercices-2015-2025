/* 
 * File:   Tempo.cpp
 * Author: braully
 * 
 * Created on 9 de Dezembro de 2014, 15:08
 */

#include "Tempo.h"

Tempo::Tempo() {
    offsetSegundos = 0;
    tempo = 0;
}

Tempo::Tempo(const Tempo& orig) {
    offsetSegundos = 0;
    tempo = 0;
}

Tempo::Tempo(int offsetseg) {
    offsetSegundos = offsetseg;
    tempo = 0;
}

Tempo::Tempo(int offsetseg, int temp) {
    offsetSegundos = offsetseg;
    tempo = temp;
}

Tempo::~Tempo() {
}
