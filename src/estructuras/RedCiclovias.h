#ifndef REDCICLOVIAS_H
#define REDCICLOVIAS_H

#include <string>

struct NodoAdyacencia {

    int vecino;
    NodoAdyacencia* siguiente;

};

class RedCiclovias
{
    private:
        std::string* codigos;
        bool* activos;
        NodoAdyacencia** adyacencia;
        int cantidad;
        int capacidad;

        int buscarIndice(std::string codigo);
        void agrandar();    
        void agregarVecino(int vertice, int vecino);

    public:
        RedCiclovias();
        ~RedCiclovias();

        void agregarVertice(std::string codigo);
        void agregarArista(std::string a, std::string b);
        void eliminarVertice(std:: string codigo);
        void mostrarCaminoMasCorto(std::string origen, std::string destino);
};


#endif