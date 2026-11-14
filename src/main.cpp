#include <iostream>
#include "entidades/Estacion.h"
#include "estructuras/ListaViajes.h"

using namespace std;

int main()
{

    // Estacion* plz = new Estacion("PLZ", "PlazaDeMayo", "Monserrat", 30, 12);
    // plz->mostrar();
    // delete plz;
    // return 0;

    ListaViajes lista;

    // Crear viajes de prueba
    Viaje *v1 = new Viaje(1, 101, 12345678, "PAL", "CAB", 20261110, 20);
    Viaje *v2 = new Viaje(2, 102, 87654321, "PLZ", "PAL", 20261111, 15);
    Viaje *v3 = new Viaje(3, 103, 12345678, "PAL", "PLZ", 20261112, 30);
    Viaje *v4 = new Viaje(4, 104, 12345678, "CAB", "PAL", 20261113, 25);
    Viaje *v5 = new Viaje(5, 105, 87654321, "PAL", "CAB", 20261114, 10);

    // Agregar viajes a la lista
    lista.agregar(v1);
    lista.agregar(v2);
    lista.agregar(v3);
    lista.agregar(v4);
    lista.agregar(v5);

    // PRUEBA 1: Contar salidas de una estación
    int cantidad = lista.contarSalidas("PAL", 20261110, 20261112);

    cout << "Cantidad de viajes desde PAL: " << cantidad << endl;

    // PRUEBA 2: Minutos pedaleados por un usuario
    int minutos = lista.mostrarViajesDeUsuario(12345678);

    cout << "Minutos pedaleados por el usuario: " << minutos << endl;

    return 0;
}