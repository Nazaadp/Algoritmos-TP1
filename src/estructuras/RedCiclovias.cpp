#include <iostream>
#include "RedCiclovias.h"
#include "Cola.h"

using namespace std;

RedCiclovias::RedCiclovias(){

    this->cantidad = 0;
    this->capacidad = 10;

    this->codigos = new string[this->capacidad];
    this->activos = new bool[this->capacidad];
    this->adyacencia = new Nodo<int>*[this->capacidad];

};

RedCiclovias::~RedCiclovias() {
    
    for (int i=0; i < this->cantidad; i++) {

        Nodo<int>* nodo = this->adyacencia[i];

        while (nodo != nullptr)
        {
            Nodo<int>* nodoTemp = nodo->siguiente;
            delete nodo;
            nodo = nodoTemp;
        }
    }

    delete[] this->codigos;
    delete[] this->activos;
    delete[] this->adyacencia;
}

int RedCiclovias::buscarIndice(string codigo) {

    for (int i=0; i < this->cantidad; i++) {
        if (this->activos[i] && this->codigos[i] == codigo) {
            return i;
        }
    }
    return -1;
}

void RedCiclovias::agrandar() {

    int capacidadNew = this->capacidad*2;

    string* codigosNew = new string[capacidadNew];
    bool* activosNew = new bool[capacidadNew];
    Nodo<int>** adyacenciaNew = new Nodo<int>*[capacidadNew];

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

void RedCiclovias::agregarVecino(int vertice, int vecino){

    Nodo<int>* nodoNew = new Nodo<int>;

    nodoNew->dato = vecino;
    nodoNew->siguiente = this->adyacencia[vertice];

    this->adyacencia[vertice] = nodoNew;

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

void RedCiclovias::agregarArista(string a, string b) {
    
    int indiceA = this->buscarIndice(a);
    int indiceB = this->buscarIndice(b);

    if (indiceA == -1 || indiceB == -1) {
        return;
    }

    this->agregarVecino(indiceA, indiceB);
    this->agregarVecino(indiceB, indiceA);
}

void RedCiclovias::eliminarVertice(string codigo) {
    
    int indice = this->buscarIndice(codigo);

    if (indice != -1) {
        this->activos[indice] = false;
    }

}

bool RedCiclovias::mostrarCaminoMasCorto(string origen, string destino) {
    
    int inicio = this->buscarIndice(origen);
    int fin = this->buscarIndice(destino);

    if (inicio == -1 || fin == -1)
    {
        return false;
    }

    bool* visitado = new bool[this->cantidad];
    int* padre = new int[this->cantidad];

    for (int i = 0; i < this->cantidad; i++)
    {
        visitado[i] = false;
        padre[i] = -1;
    }

    Cola porVisitar;
    porVisitar.encolar(inicio);
    visitado[inicio] = true;

    while (!porVisitar.estaVacia())
    {
        int actual = porVisitar.desencolar();

        if (actual == fin) {
            break;
        }

        Nodo<int>* nodo = this->adyacencia[actual];

        while (nodo != nullptr)
        {
            int vecino = nodo->dato;

            if (this->activos[vecino] && !visitado[vecino]) {
                visitado[vecino] = true;
                padre[vecino] = actual;
                porVisitar.encolar(vecino);
            }

            nodo = nodo->siguiente;
        }
    }

    bool encontrado = visitado[fin];

    if (encontrado) {

        int* camino = new int[this->cantidad];
        int largo = 0;

        for (int v = fin; v != -1; v = padre[v]) {
            camino[largo] = v;
            largo++;
        }

        cout << "Tramos: " << largo - 1 << " |";

        for (int i = largo - 1; i >= 0; i--) {
            cout << " " << this->codigos[camino[i]];
        }
        cout << endl;

        delete[] camino;
    }

    delete[] visitado;
    delete[] padre;
    
    return encontrado;
}