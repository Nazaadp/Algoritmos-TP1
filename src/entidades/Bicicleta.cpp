#include "Bicicleta.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor
Bicicleta::Bicicleta(int idBici, string codigoEstacion, TipoBicicleta tipo, EstadoBicicleta estado, int kilometros) {
    this->idBici = idBici;
    this->codigoEstacion = codigoEstacion;
    this->tipo = tipo;
    this->estado = estado;
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

// esElectrica() Devuelve true si la bicicleta es tipo ELECTRICA.
bool Bicicleta::esElectrica() {
    return (this->tipo == ELECTRICA);
}

// estaAveriada() Devuelve true si la bicicleta tiene estado AVERIADA
bool Bicicleta::estaAveriada() {
    return (this->estado == AVERIADA);
}

// mostrar() Muestra por pantalla los datos de la bicicleta.
void Bicicleta::mostrar() {
    cout << "Bicicleta con id: " << this->idBici
         << " - Estacionada en estacion: " << this->codigoEstacion
         << " - Tipo: " << (this->tipo == ELECTRICA ? "Electrica" : "Mecanica")
         << " - Estado: " << (this->estado == AVERIADA ? "Averiada" : "OK")
         << " - Kilometros totales: " << this->kilometros << endl;
}