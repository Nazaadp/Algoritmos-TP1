#include <iostream>
#include "entidades/Estacion.h"

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

bool Estacion::retirarBici(int dni) {

    if (this->bicisDisponibles > 0) {
        this->bicisDisponibles--;
        return true;
    }

    this->colaEspera.encolar(dni);
    return false;

}

int Estacion::devolverBici() {

    if (!this->colaEspera.estaVacia()) {
        return this->colaEspera.desencolar();
    }

    if (this->bicisDisponibles < this->capacidad) {
        this->bicisDisponibles++;
        return 0;
    }

    return -1;

}