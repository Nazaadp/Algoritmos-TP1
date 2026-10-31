#include <stdexcept>
using namespace std;

template <typename T>
struct NodoCola {
    T dato;
    NodoCola<T>* siguiente;
};

template <typename T>
class Cola {
    private:
    NodoCola<T>* frente;
    NodoCola<T>* fin;

    public:

    // Constructor y destructor.
    Cola() {
        frente = nullptr;
        fin = nullptr;
    }

    ~Cola(){
        NodoCola<T>* auxiliar;

        while (!estaVacia()) {
            auxiliar = frente;
            frente = frente->siguiente;
            delete auxiliar;
        }

        fin = nullptr;
    };

    void encolar(T dato) {
        NodoCola<T>* nuevo = new NodoCola<T>;
        nuevo->dato = dato;
        nuevo->siguiente = nullptr;

        // Funcionamiento cuando la cola esta vacia
        if (estaVacia()) {
            frente = nuevo;
            fin = nuevo;
        } else {
            fin->siguiente = nuevo;
            fin = nuevo;
        }
    }

    T desencolar() {
        
        if (estaVacia()) {
            throw runtime_error("Error: no se puede desencolar una cola vacia.");
        }

        NodoCola<T>* auxiliar = frente;
        T datoReturn = frente->dato;
        
        if (frente->siguiente == nullptr) {
            frente = nullptr;
            fin = nullptr;
        } else {
            frente = frente->siguiente;
        }
        delete auxiliar;
        return(datoReturn);    
    }

    bool estaVacia() {
        return (frente == nullptr);
    }
};