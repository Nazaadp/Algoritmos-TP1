#ifndef TABLAHASH_H
#define TABLAHASH_H

#include <string>
#include <entidades/Estacion.h>

struct NodoHash {

    Estacion* estacion;
    NodoHash* siguiente;
};


class TablaHash {

    private:
        int tamanio;
        int cantidad;
        int colisiones;
        NodoHash** baldes;

        int funcionHash(std::string codigo);

    public:
        TablaHash(int tamanio);
        ~TablaHash();

        bool insertar(Estacion* estacion);
        Estacion* buscar(std::string codigo);

        int getCantidad();
        int getColisiones();
        double factorDeCarga();
        void mostrarBaldes();

};

#endif