#ifndef BICICLETA_H
#define BICICLETA_H

#include <string>
using namespace std;

class Bicicleta
{
    private:
        int idBici;
        string codigoEstacion;
        bool electrica;
        bool averiada;
        int kilometros;

    public:
        // Constructor
        Bicicleta(int idBici, string codigoEstacion, bool electrica, bool averiada, int kilometros);
        
        // Getters y setters
        int getId();
        int getKilometros();
        bool esElectrica();
        bool estaAveriada();
        int getPrioridad();
        void mostrar();
};

#endif