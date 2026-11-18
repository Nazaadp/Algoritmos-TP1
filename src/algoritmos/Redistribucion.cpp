#include <iostream>
#include "Redistribucion.h"

using namespace std;

// Constructor
Redistribucion::Redistribucion(int capacidadCamion, int cantidad) {

    this->capacidadCamion = capacidadCamion;
    
    this->cantidad = cantidad;
    this->cargadas = 0;
    this->soluciones = 0;

    this->estaciones = new Estacion*[this->cantidad];
    this->elegidas = new bool[this->cantidad];
}

Redistribucion::~Redistribucion() {
    delete[] this->estaciones;
    delete[] this->elegidas;
}

bool Redistribucion::agregarEstacion(Estacion* estacion) {

    if (this->cargadas == this->cantidad){return false;}

    if (estacion == nullptr) {return false;}

    int bicisFaltantes = estacion->getCapacidad() - estacion->getBicisDisponibles();

    if (bicisFaltantes <= 0)
    {
        return false;
    }

    estaciones[cargadas] = estacion;

    elegidas[cargadas] = false;

    cargadas++;

    return true;
}

void Redistribucion::mostrarSolucion() {

    cout << "Solucion " << soluciones << ": {";

    bool primera = true;

    for (int i=0; i < cargadas; i++)
    {
        if (elegidas[i])
        {
            if (!primera)
            {
                cout << ", ";
            }

            cout << estaciones[i]->getCodigo();
            primera = false;
        }
    }

    cout << "}" << endl;
}

void Redistribucion::explorar(int indice, int suma) {

    if (suma == this->capacidadCamion)
    {
        soluciones++;
        mostrarSolucion();
        return;
    } 
    if (suma > this->capacidadCamion){return;}

    if (indice == cargadas){return;}

    int bicisFaltantes = estaciones[indice]->getCapacidad() - estaciones[indice]->getBicisDisponibles();

    elegidas[indice] = true;
    explorar(indice+1, suma+bicisFaltantes);


    elegidas[indice] = false;
    
    explorar(indice + 1, suma);
}

void Redistribucion::resolver() {
    this->soluciones = 0;
    explorar(0, 0);

    if (this->soluciones == 0)
    {
        cout << "No existen soluciones" << endl;
    }
    
}