/* 
 * File:   Heap.h
 * Author: braully
 *
 * Created on 10 de Dezembro de 2014, 09:18
 */

#ifndef HEAP_H
#define	HEAP_H

#include <iostream>

#define MAX_HEAP_DEFAULT 100000

//Referências: 
//http://www.cs.uah.edu/~rcoleman/Common/CodeVault/Code/Code211_Heap.html
//http://www.algolist.net/Data_structures/Binary_heap/Insertion

using namespace std;

class NoHeap {
private:
    int chave;
    void *dado;

public:

    NoHeap() {
        chave = 0;
        dado = NULL;
    }

    NoHeap(int key, void *data) {
        chave = key;
        dado = data;
    }

    ~NoHeap() {

    }

    int getChave() {
        return chave;
    }

    void setChave(int key) {
        chave = key;
    }

    void * getData() {
        return dado;
    }

    void setData(void * data) {
        dado = data;
    }
};

class Heap {
private:
    NoHeap *listaElementos;
    int numElementos;
    int tamanhoHeap;

public:
    Heap();
    Heap(int size);
    ~Heap();
    void ReheapDown(int root, int bottom);
    void ReheapUp(int root, int bottom);
    bool adiciona(NoHeap *item);
    bool adiciona(int key, void *data);
    NoHeap *remove();
    NoHeap *top();
    int topChave();
    void *topDado();
    int getNumElements();
    void printAll();

    bool vazio() {
        return numElementos == 0;
    }
};

#endif	/* HEAP_H */

