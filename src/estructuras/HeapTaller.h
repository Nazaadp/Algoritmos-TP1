#ifndef HEAPTALLER_H
#define HEAPTALLER_H

#include "../entidades/Bicicleta.h"

struct EntradaTaller {
    Bicicleta* bici;
    int prioridad;
};

class HeapTaller {
    
    private:
        EntradaTaller* datos;
        int cantidad;
        int capacidad;

        // Estas dos funciones sirven para reacomodar el arbol de prioridad, cuando se
        // agrega una nueva bici, o cuando se extrae la mas urgente.
        void subirNodo(int indice);
        void bajarNodo(int indice);

        // Se encarga de aumentar la capacidad del Heap cuando se llena.
        void redimensionar();

    public:
        HeapTaller();
        ~HeapTaller();
        void insertar(Bicicleta* bici);
        Bicicleta* extraerMasUrgente();
        bool contiene(int idBici);
};

#endif