#include <iostream>
#include "estructuras/Cola.h"

using namespace std;

Cola::Cola() {

    this->frente = nullptr;
    this->fin = nullptr;

}

Cola::~Cola() {

    while (!this->estaVacia())
    {
        this->desencolar();
    }

}

void Cola::encolar(int valor) {

    Nodo<int>* newNodo = new Nodo<int>;

    newNodo->dato = valor;
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

    Nodo<int>* nodoAux = this->frente;

    int valor = this->frente->dato;

    this->frente = this->frente->siguiente;

    if (estaVacia())
    {
        this->fin = nullptr;
    }
    delete nodoAux;
    return valor;
};