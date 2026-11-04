#include <iostream>
#include "estructuras/ListaViajes.h"

using namespace std;

ListaViajes::ListaViajes() {
    // Constructor y destructor.

    primero = nullptr;
    ultimo = nullptr;
}

ListaViajes::~ListaViajes() {

    NodoViaje* auxiliar;

    while (!estaVacia()) {
        auxiliar = primero;
        primero = primero->siguiente;
        delete auxiliar;
    }

    ultimo = nullptr;

}

void ListaViajes::agregar(Viaje* viaje) {
    NodoViaje* nuevo = new NodoViaje;
    nuevo->viaje = viaje;
    nuevo->siguiente = nullptr;

    // Funcionamiento cuando la cola esta vacia
    if (estaVacia()) {
        primero = nuevo;
        ultimo = nuevo;
    } else {
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
    }
}

bool ListaViajes::estaVacia() {

    if (this->primero == nullptr)
    {
        return true;
    } else
    {
        return false;
    }
}

int ListaViajes::contarSalidas(string codigo, int desde, int hasta) {

};

int ListaViajes::mostrarViajesDeUsuario(int dni) {

};
