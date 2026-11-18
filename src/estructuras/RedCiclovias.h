#ifndef REDCICLOVIAS_H
#define REDCICLOVIAS_H

#include <string>
#include "Nodo.h"
using namespace std;

class RedCiclovias
{
    private:
        int cantidad;
        int capacidad;

        string* codigos;
        bool* activos;
        Nodo<int>** adyacencia;
        
        int buscarIndice(string codigo);
        void agrandar();
        void agregarVecino(int vertice, int vecino);

    public:
        RedCiclovias();
        ~RedCiclovias();

        void agregarVertice(string codigo);
        void agregarArista(string a, string b);
        void eliminarVertice(string codigo);
        bool mostrarCaminoMasCorto(string origen, string destino);
};


#endif