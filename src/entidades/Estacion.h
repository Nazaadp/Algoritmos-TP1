#ifndef ESTACION_H
#define ESTACION_H

#include <string>


class Estacion {

    private:
        std::string codigo;
        std::string nombre;
        std::string barrio;
        int capacidad;
        int bicisDisponibles;

    public:

        // Constructor
        Estacion(std::string codigo, std::string nombre, 
                    std::string barrio, 
                        int capacidad, int bicisDisponibles);
        std::string getCodigo();
        int getCapacidad();
        int getBicisDisponibles();
        void mostrar();
        bool tieneBajaOcupacion();

};

#endif