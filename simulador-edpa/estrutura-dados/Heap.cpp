/* 
 * File:   Heap.cpp
 * Author: braully
 * 
 * Created on 10 de Dezembro de 2014, 09:18
 */

#include "Heap.h"
#include <stdexcept>

Heap::Heap() {
    listaElementos = new NoHeap[MAX_HEAP_DEFAULT];
    numElementos = 0;
    tamanhoHeap = MAX_HEAP_DEFAULT;
}

Heap::Heap(int size) {
    listaElementos = new NoHeap[size];
    numElementos = 0;
    tamanhoHeap = size;
}

Heap::~Heap() {
    delete[] listaElementos;
}

void Heap::ReheapDown(int root, int bottom) {
    int maxChild;
    int rightChild;
    int leftChild;
    NoHeap temp;

    leftChild = root * 2 + 1; // Get index of root's left child
    rightChild = root * 2 + 2; // Get index of root's right child

    // Check base case in recursive calls.  If leftChild's index is less
    // than or equal to the bottom index we have not finished recursively 
    // reheaping.
    if (leftChild <= bottom) {
        if (leftChild == bottom) // If this root has no right child then 
        {
            maxChild = leftChild; //     leftChild must hold max key
        } else { // Get the one lowest in the tree (highest index in the array)
            if (listaElementos[leftChild].getChave() >= listaElementos[rightChild].getChave())
                maxChild = rightChild;
            else
                maxChild = leftChild;
        }
        if (listaElementos[root].getChave() > listaElementos[maxChild].getChave()) {
            // Swap these two elements
            temp = listaElementos[root];
            listaElementos[root] = listaElementos[maxChild];
            listaElementos[maxChild] = temp;
            // Make recursive call till reheaping completed
            ReheapDown(maxChild, bottom);
        }
    }
}

void Heap::ReheapUp(int root, int bottom) {
    int parent;
    NoHeap temp;

    // Check base case in recursive calls.  If bottom's index is greater
    // than the root index we have not finished recursively reheaping.
    if (bottom > root) {
        parent = (bottom - 1) / 2;
        if (listaElementos[parent].getChave() > listaElementos[bottom].getChave()) {
            // Swap these two elements
            temp = listaElementos[parent];
            listaElementos[parent] = listaElementos[bottom];
            listaElementos[bottom] = temp;
            // Make recursive call till reheaping completed
            ReheapUp(root, parent);
        }
    }
}

bool Heap::adiciona(NoHeap *item) {
    if (numElementos < tamanhoHeap) {
        listaElementos[numElementos] = *item; // Copy item into array
        ReheapUp(0, numElementos);
        numElementos++;
        return true;
    }
    return false;
}

bool Heap::adiciona(int key, void *data) {
    bool retVal;
    NoHeap *temp = new NoHeap(key, data);
    retVal = adiciona(temp);
    delete temp;
    return retVal;
}

NoHeap *Heap::remove() {
    NoHeap *temp = new NoHeap(listaElementos[0].getChave(), listaElementos[0].getData());
    numElementos--;
    // Copy last item into root
    listaElementos[0] = listaElementos[numElementos];
    // Reheap the tree
    ReheapDown(0, numElementos - 1);
    if (numElementos == 0)
        return NULL;
    else
        return temp;
}

NoHeap *Heap::top() {
    if (numElementos == 0)
        return NULL;
    else {
        NoHeap *temp = new NoHeap(listaElementos[0].getChave(), listaElementos[0].getData());
        return temp;
    }
}

void *Heap::topDado() {
    if (numElementos == 0)
        return NULL;
    else {
        return listaElementos[0].getData();
    }
}

int Heap::topChave() {
    if (numElementos == 0)
        throw std::invalid_argument("o heap está vazio!");
    else {
        return listaElementos[0].getChave();
    }
}

int Heap::getNumElements() {
    return numElementos;
}

void Heap::printAll() {
    for (int i = 0; i < numElementos; i++) {
        cout << "Heap element " << i << ". key=" << listaElementos[i].getChave() << "  data=" <<
                listaElementos[i].getData() << endl;
    }
}