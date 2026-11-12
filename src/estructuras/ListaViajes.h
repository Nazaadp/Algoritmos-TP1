#include <stdexcept>
#include "../entidades/Viaje.h"
using namespace std;

struct NodoViaje {

    Viaje* viaje;
    NodoViaje* siguiente;

};


class ListaViajes {

    private:
        NodoViaje* primero;
        NodoViaje* ultimo;

    public:
        ListaViajes();
        ~ListaViajes();

        void agregar(Viaje* viaje);
        bool estaVacia();

        int contarSalidas(string codigo, int desde, int hasta);
        int mostrarViajesDeUsuario(int dni);
};