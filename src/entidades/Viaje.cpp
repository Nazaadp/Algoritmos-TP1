#include <iostream>
#include "entidades/Viaje.h"

using namespace std;

// Constructor
Viaje::Viaje(int id, int idBici, int dniUsuario, string codigoOrigen, string codigoDestino, int fecha, int duracionMin) {

        this->id = id;
        this->idBici = idBici;
        this->dniUsuario = dniUsuario;
        this->codigoOrigen = codigoOrigen;
        this->codigoDestino = codigoDestino;
        this->fecha = fecha;
        this->duracionMin = duracionMin;
}

// getCodigoOrigen() Devuelve el codigo de la estacion en donde comenzo el viaje.
string Viaje::getCodigoOrigen() {

    return this->codigoOrigen;

}

// getFecha() Devuelve la fecha del viaje.
int Viaje::getFecha() {

    return this->fecha;

}

// getDniUsuario() Devuelve el dni del usuario que viajo.
int Viaje::getDniUsuario() {

    return this->dniUsuario;

}

// getDuracionMin() Devuelve la duracion del viaje en minutos.
int Viaje::getDuracionMin() {

    return this->duracionMin;

}

void Viaje::mostrar() {

    cout << "Viaje ID: " << this->id << " - ID Bici: " << this->idBici << " - Utilizado por usuario ID: " 
    << this->dniUsuario << endl;
    cout << "Desde estacion: " << this->codigoOrigen << " hasta la estacion: " << this->codigoDestino << endl;
    cout << "El dia: " << this->fecha << " con duracion de: "  << this->duracionMin << " minutos." << endl;

}