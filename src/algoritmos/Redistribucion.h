#ifndef REDISTRIBUCION_H
#define REDISTRIBUCION_H

#include <string>
using namespace std;

class Redistribucion
{
    private:
        int capacidadCamion;

        string* codigos;
        int* faltantes;
        bool* elegidas;

        int cantidad;
        int cargadas;
        int soluciones;

    public:
        Redistribucion(int capacidadCamion, int cantidad);
        ~Redistribucion();

        bool agregarEstacion(string codigo, int faltante);
};


#endif
