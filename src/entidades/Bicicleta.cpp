#include <iostream>
#include <string>
#include "entidades/Bicicleta.h"

using namespace std;

// Constructor
Bicicleta::Bicicleta(int idBici, string codigoEstacion, bool electrica, bool averiada, int kilometros) {
    this->idBici = idBici;
    this->codigoEstacion = codigoEstacion;
    this->electrica = electrica;
    this->averiada = averiada;
    this->kilometros = kilometros;
}

// getId() Devuelve el id de la bicicleta.
int Bicicleta::getId() {
    return this->idBici;
}

// getKilometros() Devuelve la cantidad de kilometros que tiene la bicicleta.
int Bicicleta::getKilometros() {
    return this->kilometros;
}

// esElectrica() Devuelve true si la bicicleta es electrica.
bool Bicicleta::esElectrica() {
    return this->electrica;
}

// estaAveriada() Devuelve true si la bicicleta esta averiada.
bool Bicicleta::estaAveriada() {
    return this->averiada;
}

// getPrioridad() Devuelve la prioridad para el taller, de 1 (mas urgente) a 3.
int Bicicleta::getPrioridad() {
    if (this->electrica) {
        return 1;
    }
    if (this->kilometros >= 6000) {
        return 1;
    }
    if (this->kilometros >= 4000) {
        return 2;
    }
    return 3;
}

// mostrar() Muestra por pantalla los datos de la bicicleta.
void Bicicleta::mostrar() {
    cout << "Bicicleta con id: " << this->idBici
         << " - Estacionada en estacion: " << this->codigoEstacion
         << " - Tipo: " << (this->electrica ? "Electrica" : "Mecanica")
         << " - Estado: " << (this->averiada ? "Averiada" : "OK")
         << " - Kilometros totales: " << this->kilometros << endl;
}