#ifndef ESTACION_H
#define ESTACION_H

#include <string>
using namespace std;

class Estacion
{
    private:
        string codigo;
        string nombre;
        string barrio;
        int capacidad;
        int bicisDisponibles;

    public:

        // Constructor
        Estacion(string codigo, string nombre, 
                    string barrio, 
                        int capacidad, int bicisDisponibles);
        string getCodigo();
        int getCapacidad();
        int getBicisDisponibles();
        void mostrar();
        bool tieneBajaOcupacion();

};

#endif