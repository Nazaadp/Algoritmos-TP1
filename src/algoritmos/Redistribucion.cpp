#include <iostream>
#include "Redistribucion.h"

using namespace std;

// Constructor
Redistribucion::Redistribucion(int capacidadCamion, int cantidad) {

    this->capacidadCamion = capacidadCamion;
    this->cantidad = cantidad;
    this->cargadas = 0;
    this->soluciones = 0;

    this->codigos = new string[this->cantidad];
    this->faltantes = new int[this->cantidad];
    this->elegidas = new bool[this->cantidad];

}

Redistribucion::~Redistribucion() {

}

bool Redistribucion::agregarEstacion(string codigo, int faltante) {

}