/* 
 * File:   newsimpletest.cpp
 * Author: braully
 *
 * Created on 11/12/2014, 15:14:32
 */

#include <stdlib.h>
#include <iostream>
#include <iomanip>
//#include <random>
#include <map>
#include <iostream>
#include <math.h>

#define LAMBDA_DISTRIBUICAO_PADRAO 0.7
//#include "AleatorioExponencial.h"

/*
 * Simple C++ Test Suite
 */

double aleatorioExponencialTest(double lambda) {
    double R;
    R = (double) rand() / ((double) (RAND_MAX) + 1);
    return -lambda * log(R);
}

double aleatorioExponencialPadraoTest() {
    return aleatorioExponencialTest(LAMBDA_DISTRIBUICAO_PADRAO);
}

void testExpnencial1() {
    const int nrolls = 10000; // number of experiments
    const int nstars = 100; // maximum number of stars to distribute
    const int nintervals = 10; // number of intervals

    //    std::default_random_engine generator;
    //    std::exponential_distribution<double> distribution(3.5);

    int p[nintervals] = {};

    for (int i = 0; i < nrolls; ++i) {
        //        double number = distribution(generator);
        double number = aleatorioExponencialPadraoTest();
        if (number < 1.0)
            ++p[int(nintervals * number)];
    }

    std::cout << "exponential_distribution (3.5):" << std::endl;
    std::cout << std::fixed;
    std::cout.precision(1);

    for (int i = 0; i < nintervals; ++i) {
        std::cout << float(i) / nintervals << "-" << float(i + 1) / nintervals << ": ";
        std::cout << std::string(p[i] * nstars / nrolls, '*') << std::endl;
    }
}

void testExponencial2() {
    //    double const exp_dist_mean = 1;
    //    double const exp_dist_lambda = 1 / exp_dist_mean;
    //
    //    std::random_device rd;
    //    std::exponential_distribution<> rng(exp_dist_lambda);
    //    std::mt19937 rnd_gen(rd());
    //
    //    std::map<int, int> result_set;
    //
    //    for (int i = 0; i < 100000; ++i)
    //        ++result_set[rng(rnd_gen) * 4];
    //
    //    for (auto& v : result_set) {
    //        std::cout << std::setprecision(2) << std::fixed;
    //        std::cout << v.first / 4.f << " - " << (v.first + 1) / 4.f << " -> ";
    //        std::cout << std::string(v.second / 400, '.') << std::endl;
    //        if (v.second / 400 == 0)
    //            break;
    //    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testExpnencial1 (distribuicaoExponencial)" << std::endl;
    testExpnencial1();
    std::cout << "%TEST_FINISHED% time=0 testExpnencial1 (distribuicaoExponencial)" << std::endl << std::endl;

    std::cout << "%TEST_STARTED% testExpnencial2 (distribuicaoExponencial)" << std::endl;
    testExponencial2();
    std::cout << "%TEST_FINISHED% time=0 testExpnencial2 (distribuicaoExponencial)" << std::endl << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;
    return (EXIT_SUCCESS);
}

