#include "entidades/Estacion.h"

int main() {

    Estacion* plz = new Estacion("PLZ", "PlazaDeMayo", "Monserrat", 30, 12);
    plz->mostrar();
    delete plz;
    return 0;

}