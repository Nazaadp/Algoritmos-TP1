#include <iostream>
#include "estructuras/RedCiclovias.h"

using namespace std;

RedCiclovias::RedCiclovias(){

    this->cantidad = 0;
    this->capacidad = 10;

    this->codigos = new string[this->capacidad];
    this->activos = new bool[this->capacidad];
    this->adyacencia = new NodoAdyacencia*[this->capacidad];

};

RedCiclovias::~RedCiclovias() {
    // FALTA HACER
}

void RedCiclovias::agrandar() {

    int capacidadNew = this->capacidad*2;

    string* codigosNew = new string[capacidadNew];
    bool* activosNew = new bool[capacidadNew];
    NodoAdyacencia** adyacenciaNew = new NodoAdyacencia*[capacidadNew];

    for (int i = 0; i < this->cantidad; i++)
    {
        codigosNew[i] = this->codigos[i];
        activosNew[i] = this->activos[i];
        adyacenciaNew[i] = this->adyacencia[i];
    }
    delete[] this->codigos;
    delete[] this->activos;
    delete[] this->adyacencia;

    this->codigos = codigosNew;
    this->activos = activosNew;
    this->adyacencia = adyacenciaNew;

    this->capacidad = capacidadNew;
}

void RedCiclovias::agregarVertice(string codigo) {

    if (this->capacidad == this->cantidad)
    {
        this->agrandar();
    }

    this->codigos[cantidad] = codigo;
    this->activos[cantidad] = true;
    this->adyacencia[cantidad] = nullptr;

    cantidad++;
}

