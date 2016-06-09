/* 
 * File:   AleatorioExponencial.h
 * Author: braully
 *
 * Created on 12 de Dezembro de 2014, 07:17
 */

#ifndef ALEATORIOEXPONENCIAL_H
#define	ALEATORIOEXPONENCIAL_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LAMBDA_DISTRIBUICAO_PADRAO 0.7

//Referência:
//http://www.cplusplus.com/reference/random/exponential_distribution/
//http://www.pamvotis.org/vassis/RandGen.htm

double aleatorioExponencial(double lambda) {
    double R;
    R = (double) rand() / ((double) (RAND_MAX) + 1);
    return -lambda * log(R);
}

double aleatorioExponencialPadrao() {
    return aleatorioExponencial(LAMBDA_DISTRIBUICAO_PADRAO);
}

#endif	/* ALEATORIOEXPONENCIAL_H */

