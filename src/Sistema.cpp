#include <iostream>
#include <fstream>
#include "Sistema.h"
#include "entidades/Estacion.h"
#include "entidades/Bicicleta.h"
#include "entidades/Viaje.h"
#include "estructuras/TablaHash.h"

using namespace std;

Sistema::Sistema() : estaciones(41) {};

void Sistema::cargarEstaciones(string ruta) {

    ifstream archivo(ruta);

    if(!archivo.is_open()) {
        cout << "No se pudo abrir el archivo " << ruta << endl;
        return;
    }

    string codigo, nombre, barrio;
    int capacidad, bicisDisponibles;

    while ( archivo >> codigo >> nombre >> barrio >> capacidad >> bicisDisponibles ) 
    {

        Estacion* estacionNew = new Estacion(codigo, nombre, barrio, capacidad, bicisDisponibles);

        bool resultado = this->estaciones.insertar(estacionNew);

        if (resultado)
        {
            this->ciclovias.agregarVertice(codigo);
        } else
        {
            delete estacionNew;
        }

    }

    cout << "Carga completada" << endl;

    archivo.close();

}

void Sistema::cargarCiclovias(string ruta) {

    ifstream archivo(ruta);

    if(!archivo.is_open()) {
        cout << "No se pudo abrir el archivo " << ruta << endl;
        return;
    }

    string estacionA, estacionB;

    // agregarArista descarta la ciclovia si alguna de las dos estaciones no esta en el grafo.
    while ( archivo >> estacionA >> estacionB )
    {
        this->ciclovias.agregarArista(estacionA, estacionB);
    }

    archivo.close();

}

void Sistema::cargarBicicletas(string ruta) {

    ifstream archivo(ruta);

    if(!archivo.is_open()) {
        cout << "No se pudo abrir el archivo " << ruta << endl;
        return;
    }

    int id, kilometros;
    string codigoEstacion, tipo, estado;

    while ( archivo >> id >> codigoEstacion >> tipo >> estado >> kilometros )
    {
        Bicicleta* biciNew = new Bicicleta(id, codigoEstacion, tipo == "Electrica",
                                            estado == "Averiada", kilometros);

        if (!this->bicicletas.insertarBicicletas(biciNew))
        {
            delete biciNew;
        }
    }

    archivo.close();

}

void Sistema::cargarViajes(string ruta) {

    ifstream archivo(ruta);

    if(!archivo.is_open()) {
        cout << "No se pudo abrir el archivo " << ruta << endl;
        return;
    }

    int id, idBici, dni, fecha, duracion;
    string origen, destino;

    while ( archivo >> id >> idBici >> dni >> origen >> destino >> fecha >> duracion )
    {
        Viaje* viajeNew = new Viaje(id, idBici, dni, origen, destino, fecha, duracion);

        this->viajes.agregar(viajeNew);
    }

    archivo.close();

}

void Sistema::cargarDatos(string carpeta) {


    this->cargarEstaciones(carpeta + "/estaciones.txt");
    this->cargarCiclovias(carpeta + "/ciclovias.txt");
    this->cargarBicicletas(carpeta + "/bicicletas.txt");
    this->cargarViajes(carpeta + "/viajes.txt");

};

void Sistema::mostrarEstacion(string codigo) {

    Estacion* estacion = this->estaciones.buscar(codigo);

    if(estacion) {
        estacion->mostrar();
    } else
    {
        cout << "Estacion no existe" << endl;
    }
    
}

void Sistema::agregarEstacion(string codigo, string nombre, string barrio,
                                int capacidad, int bicisDisponibles) {

    if (capacidad <= 0 || bicisDisponibles < 0 || bicisDisponibles > capacidad) {
        cout << "Datos invalidos: la capacidad tiene que ser mayor a 0 y las bicis, entre 0 y la capacidad" << endl;
        return;
    }

    Estacion* estacionNew = new Estacion(codigo, nombre, barrio, capacidad, bicisDisponibles);

    if (this->estaciones.insertar(estacionNew)) {

        this->ciclovias.agregarVertice(codigo);
        cout << "Estacion agregada" << endl;

    } else
    {
        delete estacionNew;
        cout << "Estacion ya existe, no se puede agregar" << endl;
    };
    
}

void Sistema::eliminarEstacion(string codigo) {

    if (this->estaciones.eliminar(codigo)) {

        this->ciclovias.eliminarVertice(codigo);
        cout << "Estacion eliminada" << endl;

    } else
    {
        cout << "No se encuentra la estacion [" << codigo << "]" << endl;
    };

}

int Sistema::valorParaOrdenar(Estacion* estacion, bool porCapacidad) {

    if (porCapacidad)
    {
        return estacion->getCapacidad();
    } else
    {
        return estacion->getBicisDisponibles();
    }
}

void Sistema::listarEstacionesOrdenadas(bool porCapacidad) {

    int cantidad = this->estaciones.getCantidad();
    Estacion** arrayEstaciones = new Estacion*[cantidad];
    this->estaciones.copiarEstaciones(arrayEstaciones);

    Estacion* estacionAux = nullptr;
    
    for (int i=0; i<cantidad-1; i++)
    {
        for (int j=0; j<cantidad-1-i; j++)
        {
            if (valorParaOrdenar(arrayEstaciones[j], porCapacidad) < 
                    valorParaOrdenar(arrayEstaciones[j+1], porCapacidad))
            {
                estacionAux = arrayEstaciones[j];
                arrayEstaciones[j] = arrayEstaciones[j+1];
                arrayEstaciones[j+1] = estacionAux;
            }
        }
    }

    for (int i = 0; i < cantidad; i++)
    {
        arrayEstaciones[i]->mostrar();
    }
    
    delete[] arrayEstaciones;

}

void Sistema::listarBajaOcupacion() {

    int cantidad = this->estaciones.getCantidad();
    Estacion** arrayEstaciones = new Estacion*[cantidad];

    this->estaciones.copiarEstaciones(arrayEstaciones);

    for (int i=0; i<cantidad; i++) {

        if (arrayEstaciones[i]->tieneBajaOcupacion()) {
            arrayEstaciones[i]->mostrar();
        }

    }

    delete[] arrayEstaciones;
}

void Sistema::mostrarTablaHash() {

    this->estaciones.mostrarBaldes();

    cout << "Cantidad de estaciones: " << this->estaciones.getCantidad() << endl;
    cout << "Colisiones: " << this->estaciones.getColisiones() << endl;
    cout << "Factor de carga: " << this->estaciones.factorDeCarga() << endl;

}

void Sistema::mostrarRecorrido(string origen, string destino) {

    if (this->estaciones.buscar(origen) == nullptr) {
        cout << "La estacion " << origen << " no existe" << endl;
        return;
    }

    if (this->estaciones.buscar(destino) == nullptr) {
        cout << "La estacion " << destino << " no existe" << endl;
        return;
    }

    if(!this->ciclovias.mostrarCaminoMasCorto(origen, destino)) {
        cout << "No existe recorrido entre " << origen << " y " << destino << endl;
    }

}

//  B Viajes y colas de espera

void Sistema::mostrarSalidas(string codigo, int desde, int hasta) {

    if (desde > hasta) {
        cout << "La fecha inicial es posterior a la final" << endl;
        return;
    }

    if (this->estaciones.buscar(codigo) == nullptr) {
        cout << "La estacion " << codigo << " no esta actualmente en el sistema, se cuentan igualmente sus viajes registrados." << endl;
    }

    int cantidad = this->viajes.contarSalidas(codigo, desde, hasta);

    if (cantidad == 0) {
        cout << "Ningun viaje salio de " << codigo << " entre " << desde << " y " << hasta << endl;
    } else {
        cout << "Viajes que salieron de " << codigo << " entre " << desde
            << " y " << hasta << ": " << cantidad << endl;
    }
}

void Sistema::mostrarViajesDeUsuario(int dni) {

    int minutos = this->viajes.mostrarViajesDeUsuario(dni);

    if (minutos == -1) {
        cout << "El usuario " << dni << " no tiene viajes" << endl;
    } else {
        cout << "Minutos pedaleados en total: " << minutos << endl;
    }

}

void Sistema::listarBicisParaRevision(int km) {

    int cantidad = this->bicicletas.listarConMasKm(km);

    if (cantidad == 0) {
        cout << "Ninguna bici tiene mas de " << km << " km" << endl;
    } else {
        cout << "Bicis para revision: " << cantidad << endl;
    }

}

void Sistema::retirarBici(string codigo, int dni) {

    Estacion* estacion = this->estaciones.buscar(codigo);

    if (estacion == nullptr) {
        cout << "La estacion " << codigo << " no existe" << endl;
        return;
    }

    if (dni <= 0) {
        cout << "DNI invalido" << endl;
        return;
    }

    if (estacion->estaEnEspera(dni))
    {
        cout << "El usuario " << dni << " ya se encuentra en espera en la estacion " << codigo << endl;
        return;
    }
    

    if (estacion->retirarBici(dni)) {
        cout << "El usuario " << dni << " retiro una bici de " << codigo
             << ". Quedan " << estacion->getBicisDisponibles() << endl;
    } else {
        cout << "No hay bicis en " << codigo << ": el usuario " << dni
             << " queda en la cola de espera" << endl;
    }

}

void Sistema::devolverBici(string codigo) {

    Estacion* estacion = this->estaciones.buscar(codigo);

    if (estacion == nullptr) {
        cout << "La estacion " << codigo << " no existe" << endl;
        return;
    }

    int dni = estacion->devolverBici();

    if (dni > 0) {
        cout << "La bici se asigna a " << dni << ", el primero de la cola. "
             << codigo << " sigue con " << estacion->getBicisDisponibles() << endl;
    } else if (dni == 0) {
        cout << "Bici devuelta en " << codigo << ". Ahora tiene "
             << estacion->getBicisDisponibles() << endl;
    } else {
        cout << codigo << " esta llena (" << estacion->getBicisDisponibles() << "/"
             << estacion->getCapacidad() << "): no se puede devolver la bici" << endl;
    }

}

void Sistema::enviarAlTaller(int idBici) {

    int visitados = 0;
    Bicicleta* bici = this->bicicletas.buscar(idBici, visitados);

    if (bici == nullptr) {
        cout << "No existe la bici " << idBici << endl;
        return;
    }

    if (!bici->estaAveriada()) {
        cout << "La bici " << idBici << " no esta averiada" << endl;
        return;
    }

    if (this->taller.contiene(idBici)) {
        cout << "La bici " << idBici << " ya esta en el taller" << endl;
        return;
    }

    this->taller.insertar(bici);

    cout << "Bici " << idBici << " enviada al taller con prioridad "
         << bici->getPrioridad() << endl;

}

void Sistema::repararMasUrgente() {

    Bicicleta* bici = this->taller.extraerMasUrgente();

    if (bici == nullptr) {
        cout << "El taller esta vacio" << endl;
        return;
    }

    bici->reparar();

    cout << "Se reparo la bici " << bici->getId() << " (prioridad "
         << bici->getPrioridad() << ")" << endl;

}

// C Bicicletas

void Sistema::agregarBici(int id, string codigoEstacion, string tipo,
                            string estado, int kilometros) {

    if (this->estaciones.buscar(codigoEstacion) == nullptr) {
        cout << "La estacion " << codigoEstacion << " no existe" << endl;
        return;
    }

    if (tipo != "Mecanica" && tipo != "Electrica") {
        cout << "El tipo tiene que ser Mecanica o Electrica" << endl;
        return;
    }

    if (estado != "OK" && estado != "Averiada") {
        cout << "El estado tiene que ser OK o Averiada" << endl;
        return;
    }

    if (kilometros < 0) {
        cout << "Los kilometros no pueden ser negativos" << endl;
        return;
    }

    Bicicleta* biciNew = new Bicicleta(id, codigoEstacion, tipo == "Electrica",
                                        estado == "Averiada", kilometros);

    if (this->bicicletas.insertarBicicletas(biciNew)) {
        cout << "Bici agregada" << endl;
    } else {
        delete biciNew;
        cout << "Ya existe una bici con ID " << id << endl;
    }

}

void Sistema::mostrarBici(int id) {

    int visitados = 0;
    Bicicleta* bici = this->bicicletas.buscar(id, visitados);

    if (bici) {
        bici->mostrar();
    } else {
        cout << "No existe la bici " << id << endl;
    }

    cout << "Nodos visitados: " << visitados << endl;

}

void Sistema::listarBicis() {

    this->bicicletas.listarInorder();

}

void Sistema::mostrarCantidadAveriadas() {

    cout << "Bicis averiadas: " << this->bicicletas.contarAveriadas() << endl;

}

void Sistema::mostrarAltura() {

    cout << "Altura del arbol (contando niveles): " << this->bicicletas.calcularAltura() << endl;

}

void Sistema::eliminarBici(int id) {

    if (this->taller.contiene(id)) {
        cout << "La bici " << id << " esta en el taller: primero hay que repararla" << endl;
        return;
    }

    if (this->bicicletas.eliminar(id)) {
        cout << "Bici eliminada" << endl;
    } else {
        cout << "No existe la bici " << id << endl;
    }

}