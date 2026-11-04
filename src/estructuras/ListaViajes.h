#include <stdexcept>
using namespace std;

template <typename T>
struct NodoViaje {
    Viaje* viaje;
    NodoViaje* siguiente;
};

template <typename T>
class ListaViajes {
    private:
    NodoViaje* primero;
    NodoViaje* ultimo;

    public:

    // Constructor y destructor.
    ListaViajes() {
        primero = nullptr;
        ultimo = nullptr;
    }

    ~ListaViajes(){
        NodoViaje* auxiliar;

        while (!estaVacia()) {
            auxiliar = primero;
            primero = primero->siguiente;
            delete auxiliar;
        }

        ultimo = nullptr;
    };

    void agregar(Viaje* viaje) {
        NodoViaje* nuevo = new NodoViaje;
        nuevo->viaje = viaje;
        nuevo->siguiente = nullptr;

        // Funcionamiento cuando la cola esta vacia
        if (estaVacia()) {
            primero = nuevo;
            ultimo = nuevo;
        } else {
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
        }
    }

    int contarSalidas(string codigo, int desde, int hasta) {
        //COMPLETAR
    }

    int mostrarViajesDeUsuario(int dni) {
        //COMPLETAR
    }

    bool estaVacia() {
        return (frente == nullptr);
    }
};