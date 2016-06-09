/* 
 * File:   TesteEstruturaDados.cpp
 * Author: braully
 *
 * Created on 11/12/2014, 10:29:11
 */

#include <stdlib.h>
#include <iostream>

#include "estrutura-dados/Heap.h"

/*
 * Simple C++ Test Suite
 */

void testHeap() {
    std::cout << "TesteEstruturaDados: Teste do heap" << std::endl;
    Heap *theHeap = new Heap();

    cout << "Inicializa o heap\n\n";
    double v1 = 1.2;
    double v2 = 1.2;
    double v3 = 1.2;
    double v4 = 1.2;
    double v5 = 1.2;
    double v6 = 1.2;
    double v7 = 1.2;

    cout << "Adiciona itens \n\n";
    theHeap->adiciona(123, &v1);
    theHeap->adiciona(345, &v2);
    theHeap->adiciona(234, &v3);
    theHeap->adiciona(678, &v4);
    theHeap->adiciona(456, &v5);
    theHeap->adiciona(567, &v6);
    theHeap->adiciona(789, &v7);

    cout << "Elementos no Heap.\n";
    theHeap->printAll();


    NoHeap *temp;

    while ((temp = theHeap->remove()) != NULL) {
        cout << "removendo " << temp->getChave() << endl;
        delete temp;
        cout << "Elementos remanescentes no heap.\n";
        theHeap->printAll();
        cout << endl;
    }
}

void test2() {
    std::cout << "TesteEstruturaDados test 2" << std::endl;
    //    std::cout << "%TEST_FAILED% time=0 testname=test2 (TesteEstruturaDados) message=error message sample" << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% TesteEstruturaDados" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (TesteEstruturaDados)" << std::endl;
    testHeap();
    std::cout << "%TEST_FINISHED% time=0 test1 (TesteEstruturaDados)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (TesteEstruturaDados)\n" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2 (TesteEstruturaDados)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;
    return (EXIT_SUCCESS);
}

