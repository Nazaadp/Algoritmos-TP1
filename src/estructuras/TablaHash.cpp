#include <iostream>
#include "estructuras/TablaHash.h"

using namespace std;

TablaHash::TablaHash(int tamanio) {

    this->tamanio = tamanio;
    this->cantidad = 0;
    this->colisiones = 0;

    this->baldes = new NodoHash*[tamanio];

    for (int i=0; i<tamanio; i++) {

        this->baldes[i] = nullptr;

    };

};

TablaHash::~TablaHash() {

    for(int i=0; i<this->tamanio; i++) {

        NodoHash* nodo = this->baldes[i];

        while (nodo != nullptr)
        {
            
            NodoHash* nodoTemp = nodo->siguiente;

            delete nodo->estacion;
            delete nodo;

            nodo = nodoTemp;

        };
    }

    delete[] this->baldes;

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

int TablaHash::funcionHash(std::string codigo) {

    // se llama pos para hacer referencia a su posicion en el array de baldes
    int pos = 0;

    for ( unsigned char letra : codigo) {

        pos = ( pos * 31 + letra ) % this->tamanio ;

    }

    return pos;

}

Estacion* TablaHash::buscar(std::string codigo) {

    NodoHash* nodo = this->baldes[funcionHash(codigo)];

    while (nodo != nullptr)
    {
        if( nodo->estacion->getCodigo() == codigo ) {
            return nodo->estacion;
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

        NodoHash* newNodo = new NodoHash;

        newNodo->siguiente = this->baldes[pos];
        newNodo->estacion = estacion;

        this->baldes[pos] = newNodo;
        this->cantidad++;

        return true;

    } else {
        return false;
    }

};

bool TablaHash::eliminar(std::string codigo) {

    int pos = funcionHash(codigo);
    NodoHash* nodo = this->baldes[pos];
    NodoHash* nodoAnterior = nullptr;

    while (nodo != nullptr)
    {
        if (nodo->estacion->getCodigo() == codigo)
        {
            if(nodoAnterior == nullptr) {
                this->baldes[pos] = nodo->siguiente;
            } else {
                nodoAnterior->siguiente = nodo->siguiente;
            }
            
            delete nodo->estacion;
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

        NodoHash* nodo = this->baldes[i];

        if (nodo != nullptr)
        {
            cout << "[" << i << "]";

            while (nodo != nullptr)
            {

                cout << " -> " << nodo->estacion->getCodigo();

                nodo = nodo->siguiente;
                
            }

            cout << endl;
        }
        
        
    }

}