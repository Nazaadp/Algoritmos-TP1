#include <iostream>
#include "ListaViajes.h"

using namespace std;

// Constructor y destructor.
ListaViajes::ListaViajes()
{

    primero = nullptr;
    ultimo = nullptr;
}

ListaViajes::~ListaViajes()
{

    NodoViaje *auxiliar;

    while (!estaVacia())
    {
        auxiliar = primero;
        primero = primero->siguiente;
        delete auxiliar;
    }

    ultimo = nullptr;
}

void ListaViajes::agregar(Viaje *viaje)
{
    NodoViaje *nuevo = new NodoViaje;
    nuevo->viaje = viaje;
    nuevo->siguiente = nullptr;

    // Funcionamiento cuando la cola esta vacia
    if (estaVacia())
    {
        primero = nuevo;
        ultimo = nuevo;
    }
    else
    {
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
    }
}

bool ListaViajes::estaVacia()
{

    if (this->primero == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int ListaViajes::contarSalidas(string codigo, int desde, int hasta)
{
    int cantidadSalidas = 0;
    NodoViaje *nodoActual = primero;

    // While hasta que se llegue al ultimo nodoViaje
    while (nodoActual != nullptr)
    {
        if (nodoActual->viaje->getCodigoOrigen() == codigo &&
            nodoActual->viaje->getFecha() >= desde &&
            nodoActual->viaje->getFecha() <= hasta)
        {
            cantidadSalidas++;
        }
        nodoActual = nodoActual->siguiente;
    }

    return cantidadSalidas;
};

// Devuelve la cantidad de minutos pedaleados en total, entre todos los viajes.
int ListaViajes::mostrarViajesDeUsuario(int dni) {
    int minutosPedaleadosTotal = 0;
    NodoViaje *nodoActual = primero;

    // While hasta que se llegue al ultimo nodoViaje
    while (nodoActual != nullptr)
    {
        if (nodoActual->viaje->getDniUsuario() == dni)
        {
            minutosPedaleadosTotal += nodoActual->viaje->getDuracionMin();
        }

        nodoActual = nodoActual->siguiente;
    }

    return minutosPedaleadosTotal;
};
