#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include "estructuras/TablaHash.h"
// #include "estructuras/ArbolBicicletas.h"
// #include "estructuras/ListaViajes.h"
// #include "estructuras/RedCiclovias.h"
// #include "estructuras/HeapTaller.h"

class Sistema {

    private:
        TablaHash estaciones;

        void cargarEstaciones(std::string ruta);
        int valorParaOrdenar(Estacion* estacion, bool porCapacidad);

    public:
        Sistema();

        // Carga de Datos
        void cargarDatos(std::string carpeta);

        // Estaciones
        void mostrarEstacion(std::string codigo);
        void agregarEstacion(std::string codigo, std::string nombre, std::string barrio, 
                                int capacidad, int bicisDisponibles);
        void eliminarEstacion(std::string codigo);
        void listarEstacionesOrdenadas(bool porCapacidad);
        void listarBajaOcupacion();

        // TablaHash
        void mostrarTablaHash();

};


#endif