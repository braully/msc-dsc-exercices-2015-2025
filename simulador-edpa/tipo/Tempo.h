/* 
 * File:   Tempo.h
 * Author: braully
 *
 * Created on 9 de Dezembro de 2014, 15:08
 */

#ifndef TEMPO_H
#define	TEMPO_H

#include <iostream>

#define OFFSET_HORA_SEGUNDOS 3600
#define OFFSET_MINUTO_SEGUNDOS 60
#define QUANTIDADE_SEGUNDOS_EM_MINUTOS OFFSET_MINUTO_SEGUNDOS

using namespace std;

class Tempo {
public:
    friend std::ostream& operator<<(std::ostream &out, const Tempo &temp);
    Tempo();
    Tempo(const Tempo& orig);
    Tempo(int offsetsegundos);
    Tempo(int offsetsegundos, int tempo);
    virtual ~Tempo();

    int getOffset() {
        return offsetSegundos;
    }

    void setOffset(int temp) {
        offsetSegundos = temp;
    }

    int getTempo() {
        return tempo;
    }

    int getTempoNormalizado() {
        int temp = tempo + offsetSegundos;
        return temp;
    }

    void setTempo(int temp) {
        tempo = temp;
    }

    int getHora() {
        return (offsetSegundos + tempo) / OFFSET_HORA_SEGUNDOS;
    }

    int getMinuto() {
        return ((offsetSegundos + tempo) % OFFSET_HORA_SEGUNDOS) / OFFSET_MINUTO_SEGUNDOS;
    }

    int getSegundo() {
        return ((offsetSegundos + tempo) % OFFSET_HORA_SEGUNDOS) % OFFSET_MINUTO_SEGUNDOS;
    }

    friend std::ostream & operator<<(std::ostream &out, Tempo &temp) {
        int hora = temp.getHora();
        int minuto = temp.getMinuto();
        int segundo = temp.getSegundo();
        if (hora < 10) {
            out << 0;
        }
        out << hora << "h:";
        if (minuto < 10) {
            out << 0;
        }
        out << minuto << "m:";
        if (segundo < 10) {
            out << 0;
        }
        out << segundo << "s";
        return out;
    }
private:
    /* deslocamento inicial de tempo */
    int offsetSegundos;
    /* Tempo em segundos */
    int tempo;
};

#endif	/* TEMPO_H */

