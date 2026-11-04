#include <iostream>
#include "estructuras/Cola.h"

using namespace std;

Cola::Cola() {

    this->frente = nullptr;
    this->fin = nullptr;

}

Cola::~Cola() {

    if (!this->estaVacia())
    {
        while (this->frente != nullptr)
        {
            this->desencolar();
        }
    }
    

}

void Cola::encolar(int valor) {

    NodoCola* newNodo = new NodoCola;

    newNodo->valor = valor;
    newNodo->siguiente = nullptr;

    if (this->estaVacia()) {
        this->frente = newNodo;
    } else {
        this->fin->siguiente = newNodo;
    }

    this->fin = newNodo;
}

bool Cola::estaVacia() {

    if (this->frente == nullptr)
    {
        return true;
    } else
    {
        return false;
    }
}

int Cola::desencolar() {

    NodoCola* nodoAux = this->frente;

    int valor = this->frente->valor;

    this->frente = this->frente->siguiente;

    if (estaVacia())
    {
        this->fin = nullptr;
    }
    delete nodoAux;
    return valor;
};