#include <iostream>
#include "estructuras/TablaHash.h"

using namespace std;

TablaHash::TablaHash(int tamanio) {

    this->tamanio = tamanio;
    this->cantidad = 0;
    this->colisiones = 0;

    this->baldes = new Nodo<Estacion*>*[tamanio];

    for (int i=0; i<tamanio; i++) {

        this->baldes[i] = nullptr;

    };

};

TablaHash::~TablaHash() {

    for(int i=0; i<this->tamanio; i++) {

        Nodo<Estacion*>* nodo = this->baldes[i];

        while (nodo != nullptr)
        {
            
            Nodo<Estacion*>* nodoTemp = nodo->siguiente;

            delete nodo->dato;
            delete nodo;

            nodo = nodoTemp;

        };
    }

    delete[] this->baldes;

}

int TablaHash::funcionHash(string codigo) {

    // se llama pos para hacer referencia a su posicion en el array de baldes
    int pos = 0;

    for ( unsigned char letra : codigo) {

        pos = ( pos * 31 + letra ) % this->tamanio ;

    }

    return pos;

}

int TablaHash::getCantidad() {

    return this->cantidad;

};

int TablaHash::getColisiones() {

    return this->colisiones;

};

double TablaHash::factorDeCarga() {

    return (double)this->cantidad / this->tamanio;

}

Estacion* TablaHash::buscar(string codigo) {

    Nodo<Estacion*>* nodo = this->baldes[funcionHash(codigo)];

    while (nodo != nullptr)
    {
        if( nodo->dato->getCodigo() == codigo ) {
            return nodo->dato;
        } else {
            nodo = nodo->siguiente;
        }
    }
    
    return nullptr;

};

bool TablaHash::insertar(Estacion* estacion) {

    if (!buscar(estacion->getCodigo()) ) {

        int pos = funcionHash(estacion->getCodigo());

        if ( this->baldes[pos] ) {
            colisiones += 1;
        }

        Nodo<Estacion*>* newNodo = new Nodo<Estacion*>;

        newNodo->siguiente = this->baldes[pos];
        newNodo->dato = estacion;

        this->baldes[pos] = newNodo;
        this->cantidad++;

        return true;

    } else {
        return false;
    }

};

bool TablaHash::eliminar(string codigo) {

    int pos = funcionHash(codigo);
    Nodo<Estacion*>* nodo = this->baldes[pos];
    Nodo<Estacion*>* nodoAnterior = nullptr;

    while (nodo != nullptr)
    {
        if (nodo->dato->getCodigo() == codigo)
        {
            if(nodoAnterior == nullptr) {
                this->baldes[pos] = nodo->siguiente;
            } else {
                nodoAnterior->siguiente = nodo->siguiente;
            }
            
            delete nodo->dato;
            delete nodo;
            this->cantidad--;
            return true;
        } else {
            nodoAnterior = nodo;
            nodo = nodo->siguiente;
        }
    }

    return false;

}

void TablaHash::mostrarBaldes() {

    for(int i=0; i<this->tamanio; i++) {

        Nodo<Estacion*>* nodo = this->baldes[i];

        if (nodo != nullptr)
        {
            cout << "[" << i << "]";

            while (nodo != nullptr)
            {

                cout << " -> " << nodo->dato->getCodigo();

                nodo = nodo->siguiente;
                
            }

            cout << endl;
        }
        
        
    }

}

void TablaHash::copiarEstaciones(Estacion** arrayEstaciones) {

    int ingresados = 0;

    for (int i=0; i<this->tamanio; i++) {

        Nodo<Estacion*>* nodo = this->baldes[i];

        while (nodo != nullptr)
        {
            arrayEstaciones[ingresados] = nodo->dato;
            ingresados++;
            
            nodo = nodo->siguiente;
        }

    }

}