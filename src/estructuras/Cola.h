#ifndef COLA_H
#define COLA_H

#include "estructuras/Nodo.h"

class Cola
{
    private:
        Nodo<int>* frente;
        Nodo<int>* fin;

    public:
        Cola();
        ~Cola();

        void encolar(int valor);
        int desencolar();
        bool estaVacia();
};

#endif