#include <iostream>
#include "ArbolBicicletas.h"

using namespace std;

// Constructor y destructor.

ArbolBicicletas::ArbolBicicletas() {
    raiz = nullptr;
}

ArbolBicicletas::~ArbolBicicletas() {
    liberar(raiz);
}

void ArbolBicicletas::insertarBicicletas(Bicicleta* bici) {
    insertarRecursivo(raiz, bici);
}

// Al utilizar el simbolo '&' en el parametro, estoy modificando directamente al puntero original, 
// quedando asignado correctamente la nueva bicicleta. Sin el simbolo, esto no funcionaria.
void ArbolBicicletas::insertarRecursivo(NodoArbol<Bicicleta*>* &nodo, Bicicleta* bici) {

    if (nodo == nullptr) {
        nodo = new NodoArbol<Bicicleta*>;
        nodo->dato = bici;
        nodo->izquierdo = nullptr;
        nodo->derecho = nullptr;
    }
    else if (bici->getId() < nodo->dato->getId()) {
        insertarRecursivo(nodo->izquierdo, bici);
    }
    else if (bici->getId() > nodo->dato->getId()) {
        insertarRecursivo(nodo->derecho, bici);
    }
}

Bicicleta* ArbolBicicletas::buscar(int id) {
    return buscarRecursivo(raiz, id);
}

Bicicleta* ArbolBicicletas::buscarRecursivo(NodoArbol<Bicicleta*>* nodo, int id) {
    if (nodo == nullptr) {
        return nullptr;
    }

    if (nodo->dato->getId() == id) {
        return nodo->dato;
    } else {
        if (id < nodo->dato->getId()) {
            return buscarRecursivo(nodo->izquierdo, id);
        } else {
            return buscarRecursivo(nodo->derecho, id);
        }
    }
}

void ArbolBicicletas::listarInorder() {
    listarInorderRecursivo(raiz);
}

// Inorder -> Recorre primero subarbol izquierdo, despues nodo actual, despues subarbol derecho.
void ArbolBicicletas::listarInorderRecursivo(NodoArbol<Bicicleta*> *nodo) {
    
    if (nodo == nullptr) {
        return;
    }

    listarInorderRecursivo(nodo->izquierdo);
    nodo->dato->mostrar();
    listarInorderRecursivo(nodo->derecho);
}

int ArbolBicicletas::contarAveriadas() {
    return contarAveriadasRecursivo(raiz);   
}

// Recorre inorder el arbol, contando 1 en donde haya una bici averiada.
int ArbolBicicletas::contarAveriadasRecursivo(NodoArbol<Bicicleta*> *nodo) {
    if (nodo == nullptr) {
        return 0;
    }

    int cantidadAveriadas = 0;

    if (nodo->dato->estaAveriada()) {
        cantidadAveriadas++;
    }

    cantidadAveriadas += contarAveriadasRecursivo(nodo->izquierdo);
    cantidadAveriadas += contarAveriadasRecursivo(nodo->derecho);

    return cantidadAveriadas;
}

int ArbolBicicletas::calcularAltura() {
    return calcularAlturaRecursivo(raiz);
}

int ArbolBicicletas::calcularAlturaRecursivo(NodoArbol<Bicicleta*> *nodo) {
    if (nodo == nullptr) {
        return 0;
    }

    int alturaIzquierda = calcularAlturaRecursivo(nodo->izquierdo);
    int alturaDerecha = calcularAlturaRecursivo(nodo->derecho);

    if (alturaIzquierda > alturaDerecha) {
        return alturaIzquierda + 1;
    } else {
        return alturaDerecha + 1;
    }
}

void ArbolBicicletas::listarConMasKm(int km) {
    listarConMasKmRecursivo(raiz, km);
}

void ArbolBicicletas::listarConMasKmRecursivo(NodoArbol<Bicicleta*> *nodo, int km) {
    if (nodo == nullptr) {
        return;
    }

    listarConMasKmRecursivo(nodo->izquierdo, km);
    
    if (nodo->dato->getKilometros() > km) {
        nodo->dato->mostrar();
    }

    listarConMasKmRecursivo(nodo->derecho, km);
}

void ArbolBicicletas::eliminar(int id) {
    cout << "Hago algo!";
    // COMPLETAR COMPLETAR COMPLETAR COMPLETAR COMPLETAR COMPLETAR COMPLETAR COMPLETAR COMPLETAR
}

void ArbolBicicletas::liberar(NodoArbol<Bicicleta*>* nodo) {
    if (nodo == nullptr) {
        return;
    }

    liberar(nodo->izquierdo);
    liberar(nodo->derecho);

    delete nodo;
}