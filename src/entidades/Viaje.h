#ifndef VIAJE_H
#define VIAJE_H

#include <string>
using namespace std;

class Viaje
{
private:
    int id;
    int idBici;
    int dniUsuario;
    string codigoOrigen;
    string codigoDestino;
    int fecha;
    int duracionMin;

public:
    // Constructor
    Viaje(int id, int idBici, int dniUsuario, string codigoOrigen, string codigoDestino, int fecha, int duracionMin);
    
    // Getters y setters
    string getCodigoOrigen();
    int getFecha();
    int getDniUsuario();
    int getDuracionMin();
    void mostrar();
};

#endif