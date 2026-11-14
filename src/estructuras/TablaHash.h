#ifndef TABLAHASH_H
#define TABLAHASH_H

#include <string>
#include "entidades/Estacion.h"
#include "estructuras/Nodo.h"
using namespace std;

class TablaHash
{
    private:
        int tamanio;
        int cantidad;
        int colisiones;
        Nodo<Estacion*>** baldes;

        int funcionHash(string codigo);

    public:
        TablaHash(int tamanio);
        ~TablaHash();

        bool insertar(Estacion* estacion);
        bool eliminar(string codigo);
        Estacion* buscar(string codigo);

        int getCantidad();
        int getColisiones();
        double factorDeCarga();
        void mostrarBaldes();
        void copiarEstaciones(Estacion** arrayEstaciones);

};

#endif