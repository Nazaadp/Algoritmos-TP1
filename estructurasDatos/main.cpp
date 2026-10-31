#include <iostream>
#include "Cola.h"

using namespace std;

int main() {
    Cola<int> cola;

    cola.encolar(10);
    cola.encolar(20);
    cola.encolar(30);

    cout << cola.desencolar() << endl;
    cout << cola.desencolar() << endl;

    cout << cola.estaVacia() << endl;

    return 0;
}