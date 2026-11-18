#ifndef REDISTRIBUCION_H
#define REDISTRIBUCION_H

#include "../entidades/Estacion.h"

class Redistribucion
{
    private:

        int capacidadCamion;

        Estacion** estaciones;
        bool* elegidas;

        int cantidad;
        int cargadas;
        int soluciones;

        void explorar(int indice, int suma);
        void mostrarSolucion();

    public:
        Redistribucion(int capacidadCamion, int cantidad);
        ~Redistribucion();

        bool agregarEstacion(Estacion* estacion);
        void resolver();
};


#endif
