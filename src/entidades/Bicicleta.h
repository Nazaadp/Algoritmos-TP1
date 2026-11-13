#ifndef BICICLETA_H
#define BICICLETA_H

#include <string>
using namespace std;

enum TipoBicicleta {
    MECANICA,
    ELECTRICA
};

enum EstadoBicicleta {
    OK,
    AVERIADA
};

class Bicicleta
{
    private:
        int idBici;
        string codigoEstacion;
        TipoBicicleta tipo;
        EstadoBicicleta estado;
        int kilometros;

    public:
        // Constructor
        Bicicleta(int idBici, string codigoEstacion, TipoBicicleta tipo, EstadoBicicleta estado, int kilometros);
        
        // Getters y setters
        int getId();
        int getKilometros();
        bool esElectrica();
        bool estaAveriada();
        void mostrar();
};

#endif