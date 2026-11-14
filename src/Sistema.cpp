#include <iostream>
#include <fstream>
#include "Sistema.h"
#include "entidades/Estacion.h"
#include "estructuras/TablaHash.h"

using namespace std;

Sistema::Sistema() : estaciones(41) {};

void Sistema::cargarEstaciones(string ruta) {

    ifstream archivo(ruta);

    if(!archivo.is_open()) {
        cout << "No se pudo abrir el archivo " << ruta << endl;
        return;
    }

    string codigo, nombre, barrio;
    int capacidad, bicisDisponibles;

    while ( archivo >> codigo >> nombre >> barrio >> capacidad >> bicisDisponibles ) 
    {

        Estacion* estacionNew = new Estacion(codigo, nombre, barrio, capacidad, bicisDisponibles);

        bool resultado = this->estaciones.insertar(estacionNew);

        if (!resultado)
        {
            delete estacionNew;
        }

    }

    cout << "Carga completada" << endl;
    
    archivo.close();

}

void Sistema::cargarDatos(string carpeta) {

    this->cargarEstaciones(carpeta + "/estaciones.txt");

};

void Sistema::mostrarEstacion(string codigo) {

    Estacion* estacion = this->estaciones.buscar(codigo);

    if(estacion) {
        estacion->mostrar();
    } else
    {
        cout << "Estacion no existe" << endl;
    }
    
}

void Sistema::agregarEstacion(string codigo, string nombre, string barrio, 
                                int capacidad, int bicisDisponibles) {

    Estacion* estacionNew = new Estacion(codigo, nombre, barrio, capacidad, bicisDisponibles);

    if (this->estaciones.insertar(estacionNew)) {

        cout << "Estacion agregada" << endl;

    } else
    {
        delete estacionNew;
        cout << "Estacion ya existe, no se puede agregar" << endl;
    };
    
}

void Sistema::eliminarEstacion(string codigo) {

    if (this->estaciones.eliminar(codigo)) {

        cout << "Estacion eliminada" << endl;

    } else
    {
        cout << "No se encuentra la estacion [" << codigo << "]" << endl;
    };

}

int Sistema::valorParaOrdenar(Estacion* estacion, bool porCapacidad) {

    if (porCapacidad)
    {
        return estacion->getCapacidad();
    } else
    {
        return estacion->getBicisDisponibles();
    }
}

void Sistema::listarEstacionesOrdenadas(bool porCapacidad) {

    int cantidad = this->estaciones.getCantidad();
    Estacion** arrayEstaciones = new Estacion*[cantidad];
    this->estaciones.copiarEstaciones(arrayEstaciones);

    Estacion* estacionAux = nullptr;
    
    for (int i=0; i<cantidad-1; i++)
    {
        for (int j=0; j<cantidad-1-i; j++)
        {
            if (valorParaOrdenar(arrayEstaciones[j], porCapacidad) < 
                    valorParaOrdenar(arrayEstaciones[j+1], porCapacidad))
            {
                estacionAux = arrayEstaciones[j];
                arrayEstaciones[j] = arrayEstaciones[j+1];
                arrayEstaciones[j+1] = estacionAux;
            }
        }
    }

    for (int i = 0; i < cantidad; i++)
    {
        arrayEstaciones[i]->mostrar();
    }
    
    delete[] arrayEstaciones;

}

void Sistema::listarBajaOcupacion() {

    int cantidad = this->estaciones.getCantidad();
    Estacion** arrayEstaciones = new Estacion*[cantidad];

    this->estaciones.copiarEstaciones(arrayEstaciones);

    for (int i=0; i<cantidad; i++) {

        if (arrayEstaciones[i]->tieneBajaOcupacion()) {
            arrayEstaciones[i]->mostrar();
        }

    }

    delete[] arrayEstaciones;
}

void Sistema::mostrarTablaHash() {

    this->estaciones.mostrarBaldes();

    cout << "Cantidad de estaciones: " << this->estaciones.getCantidad() << endl;
    cout << "Colisiones: " << this->estaciones.getColisiones() << endl;
    cout << "Factor de carga: " << this->estaciones.factorDeCarga() << endl;

}