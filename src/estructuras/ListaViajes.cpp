#include <iostream>
#include "estructuras/ListaViajes.h"

using namespace std;

// Constructor y destructor.
ListaViajes::ListaViajes()
{

    primero = nullptr;
    ultimo = nullptr;
}

ListaViajes::~ListaViajes()
{

    Nodo<Viaje*> *auxiliar;

    while (!estaVacia())
    {
        auxiliar = primero;
        primero = primero->siguiente;
        delete auxiliar->dato;
        delete auxiliar;
    }

    ultimo = nullptr;
}

void ListaViajes::agregar(Viaje *viaje)
{
    Nodo<Viaje*> *nuevo = new Nodo<Viaje*>;
    nuevo->dato = viaje;
    nuevo->siguiente = nullptr;

    // Funcionamiento cuando la lista esta vacia
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
    Nodo<Viaje*> *nodoActual = primero;

    // While hasta que se llegue al ultimo nodoViaje
    while (nodoActual != nullptr)
    {
        if (nodoActual->dato->getCodigoOrigen() == codigo &&
            nodoActual->dato->getFecha() >= desde &&
            nodoActual->dato->getFecha() <= hasta)
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
    int cantidadViajes = 0;
    Nodo<Viaje*> *nodoActual = primero;

    // While hasta que se llegue al ultimo nodoViaje
    while (nodoActual != nullptr)
    {
        if (nodoActual->dato->getDniUsuario() == dni)
        {
            nodoActual->dato->mostrar();
            minutosPedaleadosTotal += nodoActual->dato->getDuracionMin();
            cantidadViajes++;
        }

        nodoActual = nodoActual->siguiente;
    }

    if (cantidadViajes == 0)
    {
        return -1;
    }

    return minutosPedaleadosTotal;
};
