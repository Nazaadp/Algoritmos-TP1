#ifndef ARBOLBICICLETAS_H
#define ARBOLBICICLETAS_H

#include "../entidades/Bicicleta.h"

template <typename T>
struct NodoArbol {
    T dato;
    NodoArbol<T>* izquierdo;
    NodoArbol<T>* derecho;

};

class ArbolBicicletas {
    
    private:
        NodoArbol<Bicicleta*>* raiz;

        void liberar(NodoArbol<Bicicleta*>* nodo);
        bool insertarRecursivo(NodoArbol<Bicicleta*>* &nodo, Bicicleta* bici);
        Bicicleta* buscarRecursivo(NodoArbol<Bicicleta*>* nodo, int id, int& visitados);
        void listarInorderRecursivo(NodoArbol<Bicicleta*>* nodo);
        int contarAveriadasRecursivo(NodoArbol<Bicicleta*>* nodo);
        int calcularAlturaRecursivo(NodoArbol<Bicicleta*>* nodo);
        int listarConMasKmRecursivo(NodoArbol<Bicicleta*>* nodo, int km);
        bool eliminarRecursivo(NodoArbol<Bicicleta*>* &nodo, int id);

    public:
        ArbolBicicletas();
        ~ArbolBicicletas();
        bool insertarBicicletas(Bicicleta* bici);
        Bicicleta* buscar(int id, int& visitados);
        void listarInorder();
        int contarAveriadas();
        int calcularAltura();
        int listarConMasKm(int km);
        bool eliminar(int id);
};

#endif