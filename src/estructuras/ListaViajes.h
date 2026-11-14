#ifndef LISTAVIAJES_H
#define LISTAVIAJES_H

#include "entidades/Viaje.h"
#include "estructuras/Nodo.h"
using namespace std;

class ListaViajes
{
    private:
        Nodo<Viaje*>* primero;
        Nodo<Viaje*>* ultimo;

    public:
        ListaViajes();
        ~ListaViajes();

        void agregar(Viaje* viaje);
        bool estaVacia();

        int contarSalidas(string codigo, int desde, int hasta);
        int mostrarViajesDeUsuario(int dni);
};

#endif