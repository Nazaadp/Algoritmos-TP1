#include "Estacion.h"
#include <iostream>

using namespace std;

// Constructor
Estacion::Estacion(string codigo, string nombre, string barrio,
     int capacidad, int bicisDisponibles) {

        this->codigo = codigo;
        this->nombre = nombre;
        this->barrio = barrio;
        this->capacidad = capacidad;
        this->bicisDisponibles = bicisDisponibles;

}

// getCodigo() Devuelve el codigo de la Estacion.
string Estacion::getCodigo() {

    return this->codigo;

}

int Estacion::getCapacidad() {

    return this->capacidad;

}

int Estacion::getBicisDisponibles() {

    return this->bicisDisponibles;

}

bool Estacion::tieneBajaOcupacion() {

    return ( this->bicisDisponibles * 5 ) < this->capacidad;

}

void Estacion::mostrar() {

    cout << this->codigo << " - " << this->nombre << "(" << this->barrio << ")" << endl;
    cout << "bicis: " << this->bicisDisponibles << " | capacidad: "  << this->capacidad << endl;

}