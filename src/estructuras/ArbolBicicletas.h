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
        void insertarRecursivo(NodoArbol<Bicicleta*>* &nodo, Bicicleta* bici);
        Bicicleta* buscarRecursivo(NodoArbol<Bicicleta*>* nodo, int id);
        void listarInorderRecursivo(NodoArbol<Bicicleta*>* nodo);
        int contarAveriadasRecursivo(NodoArbol<Bicicleta*>* nodo);
        int calcularAlturaRecursivo(NodoArbol<Bicicleta*>* nodo);
        void listarConMasKmRecursivo(NodoArbol<Bicicleta*>* nodo, int km);

    public:
        ArbolBicicletas();
        ~ArbolBicicletas();
        void insertarBicicletas(Bicicleta* bici);
        Bicicleta* buscar(int id);
        void listarInorder();
        int contarAveriadas();
        int calcularAltura();
        void listarConMasKm(int km);
        
        // ver si eliminar() se favorece de retornar booleano.
        void eliminar(int id);        
};

#endif