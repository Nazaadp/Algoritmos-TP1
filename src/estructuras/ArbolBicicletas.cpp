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

bool ArbolBicicletas::insertarBicicletas(Bicicleta* bici) {
    return insertarRecursivo(raiz, bici);
}

// Al utilizar el simbolo '&' en el parametro, estoy modificando directamente al puntero original,
// quedando asignado correctamente la nueva bicicleta. Sin el simbolo, esto no funcionaria.
bool ArbolBicicletas::insertarRecursivo(NodoArbol<Bicicleta*>* &nodo, Bicicleta* bici) {

    if (nodo == nullptr) {
        nodo = new NodoArbol<Bicicleta*>;
        nodo->dato = bici;
        nodo->izquierdo = nullptr;
        nodo->derecho = nullptr;
        return true;
    }
    else if (bici->getId() < nodo->dato->getId()) {
        return insertarRecursivo(nodo->izquierdo, bici);
    }
    else if (bici->getId() > nodo->dato->getId()) {
        return insertarRecursivo(nodo->derecho, bici);
    }

    return false;
}

Bicicleta* ArbolBicicletas::buscar(int id, int& visitados) {
    visitados = 0;
    return buscarRecursivo(raiz, id, visitados);
}

Bicicleta* ArbolBicicletas::buscarRecursivo(NodoArbol<Bicicleta*>* nodo, int id, int& visitados) {
    if (nodo == nullptr) {
        return nullptr;
    }

    visitados++;

    if (nodo->dato->getId() == id) {
        return nodo->dato;
    } else {
        if (id < nodo->dato->getId()) {
            return buscarRecursivo(nodo->izquierdo, id, visitados);
        } else {
            return buscarRecursivo(nodo->derecho, id, visitados);
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

// Recorre el arbol en preorder, contando 1 en donde haya una bici averiada.
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

int ArbolBicicletas::listarConMasKm(int km) {
    return listarConMasKmRecursivo(raiz, km);
}

int ArbolBicicletas::listarConMasKmRecursivo(NodoArbol<Bicicleta*> *nodo, int km) {
    if (nodo == nullptr) {
        return 0;
    }

    int cantidad = listarConMasKmRecursivo(nodo->izquierdo, km);

    if (nodo->dato->getKilometros() > km) {
        nodo->dato->mostrar();
        cantidad++;
    }

    cantidad += listarConMasKmRecursivo(nodo->derecho, km);

    return cantidad;
}

bool ArbolBicicletas::eliminar(int id) {
    return eliminarRecursivo(raiz, id);
}

bool ArbolBicicletas::eliminarRecursivo(NodoArbol<Bicicleta*>* &nodo, int id) {

    if (nodo == nullptr) {
        return false;
    }

    if (id < nodo->dato->getId()) {
        return eliminarRecursivo(nodo->izquierdo, id);
    }
    else if (id > nodo->dato->getId()) {
        return eliminarRecursivo(nodo->derecho, id);
    }

    if (nodo->izquierdo != nullptr && nodo->derecho != nullptr) {

        NodoArbol<Bicicleta*>* sucesor = nodo->derecho;

        while (sucesor->izquierdo != nullptr) {
            sucesor = sucesor->izquierdo;
        }

        Bicicleta* aux = nodo->dato;
        nodo->dato = sucesor->dato;
        sucesor->dato = aux;

        return eliminarRecursivo(nodo->derecho, id);
    }

    NodoArbol<Bicicleta*>* borrar = nodo;

    if (nodo->izquierdo != nullptr) {
        nodo = nodo->izquierdo;
    } else {
        nodo = nodo->derecho;
    }

    delete borrar->dato;
    delete borrar;

    return true;
}

void ArbolBicicletas::liberar(NodoArbol<Bicicleta*>* nodo) {
    if (nodo == nullptr) {
        return;
    }

    liberar(nodo->izquierdo);
    liberar(nodo->derecho);

    delete nodo->dato;
    delete nodo;
}