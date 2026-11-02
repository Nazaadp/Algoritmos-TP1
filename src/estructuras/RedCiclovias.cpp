#include <iostream>
#include "estructuras/RedCiclovias.h"

using namespace std;

RedCiclovias::RedCiclovias(){

    this->activos = new[];
    this->adyacencia = new[];
    this->codigos = new[];

    this->cantidad = 0;
    this->capacidad = 10;

};

void RedCiclovias::agrandar() {

    int capacidadNew = this->capacidad*2;

    string* codigosNew = new string[capacidadNew];
    bool* activosNew = new bool[capacidadNew];
    NodoAdyacencia** adyacenciaNew = new NodoAdyacencia[capacidadNew];

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

