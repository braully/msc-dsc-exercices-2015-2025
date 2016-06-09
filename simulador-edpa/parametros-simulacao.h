/* 
 * File:   parametros-simulacao.h
 * Author: braully
 *
 * Created on 14 de Dezembro de 2014, 00:00
 */

#ifndef PARAMETROS_SIMULACAO_H
#define	PARAMETROS_SIMULACAO_H

#include "tipo/Tempo.h"


//parametros
bool detalhar = false;
bool detalharCadaMinuto = false;
bool detalharCadaSegundo = false;
bool lerParametrosEntrada = true;

// Fatores em segundos da chegada de uma pessoa
int fatorChegadaPessoasFila101 = 20;
int fatorChegadaPessoasFila102 = 30;
int fatorChegadaPessoasFilaTaxi = 60;

int offsetChegadaPrimeiraPessoaFila101 = 0;
int offsetChegadaPrimeiraPessoaFila102 = 0;
int offsetChegadaPrimeiraPessoaFilaTaxi = 0;

int offsetChegadaPrimeiroOnibus101 = 60;
int offsetChegadaPrimeiroOnibus102 = 60;
int offsetChegadaPrimeiroTaxi = 60;

// Fatores em segundos da chegada de transporte
int fatorChegadaOnibus101 = 5 * OFFSET_MINUTO_SEGUNDOS;
int fatorChegadaOnibus102 = 3 * OFFSET_MINUTO_SEGUNDOS;
int fatorChegadaTaxi = 7 * OFFSET_MINUTO_SEGUNDOS;

void entradaParametrosSimulacao(int limiteInferiorTempoSimulacao, int limiteSuperiorTempoSimulacao) {
    cout << "Entrar com as seguintes informações" << endl;
    cout << "1 - Quantidade média de segundos entre chegadas de pessoas a fila 101: ";
    cin >>fatorChegadaPessoasFila101;
    cout << "2 - Quantidade média de segundos entre chegadas de pessoas a fila 102: ";
    cin >>fatorChegadaPessoasFila102;
    cout << "3 - Quantidade média de segundos entre chegada de grupo pessoas ao ponto de táxi: ";
    cin >>fatorChegadaPessoasFilaTaxi;
    /* */
    cout << "4 - Quantidade média de minutos entre chegadas de ônibus 101: ";
    cin >>fatorChegadaOnibus101;
    cout << "5 - Quantidade média de minutos entre chegadas de ônibus 102: ";
    cin >>fatorChegadaOnibus102;
    cout << "6 - Frequência de chegada de taxis: ";
    cin >>fatorChegadaTaxi;


    int hora, minuto;
    bool valido = false;
    hora = 0;
    minuto = 0;
    while (!valido) {
        cout << "7 - Momento (digitar hora:minuto) de chegada da primeira pessoa no ponto 101: ";
        int sc = scanf("%d:%d", &hora, &minuto);
        offsetChegadaPrimeiraPessoaFila101 = hora * OFFSET_HORA_SEGUNDOS + minuto * OFFSET_MINUTO_SEGUNDOS;
        if (hora < 0 || hora > 23 || minuto < 0 || minuto > 59
                || offsetChegadaPrimeiraPessoaFila101 < limiteInferiorTempoSimulacao
                || offsetChegadaPrimeiraPessoaFila101 > limiteSuperiorTempoSimulacao) {
            cout << "--momento invalido, inserir a informação novamente.\n";
        } else {
            valido = true;
        }
    }
    offsetChegadaPrimeiraPessoaFila101 = offsetChegadaPrimeiraPessoaFila101 - limiteInferiorTempoSimulacao;

    valido = false;
    hora = 0;
    minuto = 0;
    while (!valido) {
        cout << "8 - Momento (digitar hora:minuto) de chegada da primeira pessoa no ponto 102: ";
        int sc = scanf("%d:%d", &hora, &minuto);
        offsetChegadaPrimeiraPessoaFila102 = hora * OFFSET_HORA_SEGUNDOS + minuto * OFFSET_MINUTO_SEGUNDOS;
        if (hora < 0 || hora > 23 || minuto < 0 || minuto > 59
                || offsetChegadaPrimeiraPessoaFila102 < limiteInferiorTempoSimulacao
                || offsetChegadaPrimeiraPessoaFila102 > limiteSuperiorTempoSimulacao) {
            cout << "--momento invalido, inserir a informação novamente.\n";
        } else {
            valido = true;
        }
    }
    offsetChegadaPrimeiraPessoaFila102 = offsetChegadaPrimeiraPessoaFila102 - limiteInferiorTempoSimulacao;

    valido = false;
    hora = 0;
    minuto = 0;
    while (!valido) {
        cout << "9 - Momento (digitar hora:minuto) de chegada da primeira pessoa no ponto taxi: ";
        int sc = scanf("%d:%d", &hora, &minuto);
        offsetChegadaPrimeiraPessoaFilaTaxi = hora * OFFSET_HORA_SEGUNDOS + minuto * OFFSET_MINUTO_SEGUNDOS;
        if (hora < 0 || hora > 23 || minuto < 0 || minuto > 59
                || offsetChegadaPrimeiraPessoaFilaTaxi < limiteInferiorTempoSimulacao
                || offsetChegadaPrimeiraPessoaFilaTaxi > limiteSuperiorTempoSimulacao) {
            cout << "--momento invalido, inserir a informação novamente.\n";
        } else {
            valido = true;
        }
    }
    offsetChegadaPrimeiraPessoaFilaTaxi = offsetChegadaPrimeiraPessoaFilaTaxi - limiteInferiorTempoSimulacao;

    valido = false;
    hora = 0;
    minuto = 0;
    while (!valido) {
        cout << "10 - Momento (digitar hora:minuto) de chegada do primeiro ônibus 101: ";
        int sc = scanf("%d:%d", &hora, &minuto);
        offsetChegadaPrimeiroOnibus101 = hora * OFFSET_HORA_SEGUNDOS + minuto * OFFSET_MINUTO_SEGUNDOS;
        if (hora < 0 || hora > 23 || minuto < 0 || minuto > 59
                || offsetChegadaPrimeiroOnibus101 < limiteInferiorTempoSimulacao
                || offsetChegadaPrimeiroOnibus101 > limiteSuperiorTempoSimulacao) {
            cout << "--momento invalido, inserir a informação novamente.\n";
        } else {
            valido = true;
        }
    }
    offsetChegadaPrimeiroOnibus101 = offsetChegadaPrimeiroOnibus101 - limiteInferiorTempoSimulacao;

    valido = false;
    hora = 0;
    minuto = 0;
    while (!valido) {
        cout << "11 - Momento (digitar hora:minuto) de chegada do primeiro ônibus 102: ";
        int sc = scanf("%d:%d", &hora, &minuto);
        offsetChegadaPrimeiroOnibus102 = hora * OFFSET_HORA_SEGUNDOS + minuto * OFFSET_MINUTO_SEGUNDOS;
        if (hora < 0 || hora > 23 || minuto < 0 || minuto > 59
                || offsetChegadaPrimeiroOnibus102 < limiteInferiorTempoSimulacao
                || offsetChegadaPrimeiroOnibus102 > limiteSuperiorTempoSimulacao) {
            cout << "--momento invalido, inserir a informação novamente.\n";
        } else {
            valido = true;
        }
    }
    offsetChegadaPrimeiroOnibus102 = offsetChegadaPrimeiroOnibus102 - limiteInferiorTempoSimulacao;

    valido = false;
    hora = 0;
    minuto = 0;
    while (!valido) {
        cout << "12 - Momento (digitar hora:minuto) de chegada do primeiro taxi: ";
        int sc = scanf("%d:%d", &hora, &minuto);
        offsetChegadaPrimeiroTaxi = hora * OFFSET_HORA_SEGUNDOS + minuto * OFFSET_MINUTO_SEGUNDOS;
        if (hora < 0 || hora > 23 || minuto < 0 || minuto > 59
                || offsetChegadaPrimeiroTaxi < limiteInferiorTempoSimulacao
                || offsetChegadaPrimeiroTaxi > limiteSuperiorTempoSimulacao) {
            cout << "--momento invalido, inserir a informação novamente.\n";
        } else {
            valido = true;
        }
    }
    offsetChegadaPrimeiroTaxi = offsetChegadaPrimeiroTaxi - limiteInferiorTempoSimulacao;
}

void printParametrosSimulacao(int offsetTempo) {
    cout << endl << "********** PARAMETROS USADOS NA SIMULAÇÃO *********" << endl;
    cout << "01 - Quantidade média de segundos entre: ";
    cout << endl << "\t* Chegadas de pessoas a fila 101: ";
    cout << fatorChegadaPessoasFila101;
    cout << endl << "\t* Chegadas de pessoas a fila 102: ";
    cout << fatorChegadaPessoasFila102;
    cout << endl << "\t* Chegada de grupo pessoas ao ponto de taxi: ";
    cout << fatorChegadaPessoasFilaTaxi;
    /* */

    cout << endl << "02 - Quantidade média de minutos entre: ";
    cout << endl << "\t* Chegadas de ônibus 101: ";
    cout << fatorChegadaOnibus101 / OFFSET_MINUTO_SEGUNDOS;
    cout << endl << "\t* Chegadas de ônibus 102: ";
    cout << fatorChegadaOnibus102 / OFFSET_MINUTO_SEGUNDOS;
    cout << endl << "\t* Chegada de táxis: ";
    cout << fatorChegadaTaxi / OFFSET_MINUTO_SEGUNDOS;

    Tempo temp;
    temp.setOffset(offsetTempo);
    cout << endl << "03 - Momento de chegada:";
    cout << endl << "\t * Primeira pessoa no ponto 101: ";
    temp.setTempo(offsetChegadaPrimeiraPessoaFila101);
    cout << temp;
    cout << endl << "\t * Primeira pessoa no ponto 102: ";
    temp.setTempo(offsetChegadaPrimeiraPessoaFila102);
    cout << temp;
    cout << endl << "\t * Primeira pessoa no ponto táxi: ";
    temp.setTempo(offsetChegadaPrimeiraPessoaFilaTaxi);
    cout << temp;
    cout << endl << "\t * Primeiro ônibus 101: ";
    temp.setTempo(offsetChegadaPrimeiroOnibus101);
    cout << temp;
    cout << endl << "\t * Primeiro ônibus 102: ";
    temp.setTempo(offsetChegadaPrimeiroOnibus102);
    cout << temp;
    cout << endl << "\t * Primeiro táxi: ";
    temp.setTempo(offsetChegadaPrimeiroTaxi);
    cout << temp;
}


#endif	/* PARAMETROS_SIMULACAO_H */

