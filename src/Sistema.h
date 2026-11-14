#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include "estructuras/TablaHash.h"
// #include "estructuras/ArbolBicicletas.h"
// #include "estructuras/ListaViajes.h"
// #include "estructuras/RedCiclovias.h"
// #include "estructuras/HeapTaller.h"
using namespace std;

class Sistema
{
    private:
        TablaHash estaciones;

        void cargarEstaciones(string ruta);
        int valorParaOrdenar(Estacion* estacion, bool porCapacidad);

    public:
        Sistema();

        // Carga de Datos
        void cargarDatos(string carpeta);

        // Estaciones
        void mostrarEstacion(string codigo);
        void agregarEstacion(string codigo, string nombre, string barrio, 
                                int capacidad, int bicisDisponibles);
        void eliminarEstacion(string codigo);
        void listarEstacionesOrdenadas(bool porCapacidad);
        void listarBajaOcupacion();

        // TablaHash
        void mostrarTablaHash();

};


#endif