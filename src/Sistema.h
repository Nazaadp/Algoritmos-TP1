#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include "estructuras/TablaHash.h"
#include "estructuras/ArbolBicicletas.h"
#include "estructuras/ListaViajes.h"
#include "estructuras/RedCiclovias.h"
#include "estructuras/HeapTaller.h"
using namespace std;

class Sistema
{
    private:
        TablaHash estaciones;
        RedCiclovias ciclovias;
        ArbolBicicletas bicicletas;
        ListaViajes viajes;
        HeapTaller taller;

        void cargarEstaciones(string ruta);
        void cargarCiclovias(string ruta);
        void cargarBicicletas(string ruta);
        void cargarViajes(string ruta);
        int valorParaOrdenar(Estacion* estacion, bool porCapacidad);

    public:
        Sistema();

        // Carga de Datos
        void cargarDatos(string carpeta);

        // A. Estaciones
        void mostrarEstacion(string codigo);
        void agregarEstacion(string codigo, string nombre, string barrio,
                                int capacidad, int bicisDisponibles);
        void eliminarEstacion(string codigo);
        void listarEstacionesOrdenadas(bool porCapacidad);
        void listarBajaOcupacion();
        void mostrarRecorrido(string origen, string destino);

        // TablaHash
        void mostrarTablaHash();

        // B. Viajes y colas de espera
        void mostrarSalidas(string codigo, int desde, int hasta);
        void mostrarViajesDeUsuario(int dni);
        void listarBicisParaRevision(int km);
        void retirarBici(string codigo, int dni);
        void devolverBici(string codigo);
        void enviarAlTaller(int idBici);
        void repararMasUrgente();

        // C. Bicicletas
        void agregarBici(int id, string codigoEstacion, string tipo,
                            string estado, int kilometros);
        void mostrarBici(int id);
        void listarBicis();
        void mostrarCantidadAveriadas();
        void mostrarAltura();
        void eliminarBici(int id);

        // D. Redistribucion
        void redistribuir(int capacidadCamion);

};


#endif
