#include <iostream>
#include <limits>
#include <string>
#include "Sistema.h"

using namespace std;

int leerEntero(string mensaje) {

    int valor;

    while (true) {

        cout << mensaje;

        if (cin >> valor) {
            return valor;
        }

        if (cin.eof()) {
            return 0;
        }


        cout << "Tiene que ser un numero entero" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

}

string leerTexto(string mensaje) {

    string texto;

    cout << mensaje;
    cin >> texto;

    return texto;

}


void menuEstaciones(Sistema& sistema) {

    int opcion = -1;

    while (opcion != 0) {

        cout << endl << "--- A. Gestion de estaciones ---" << endl;
        cout << "1. Mostrar una estacion" << endl;
        cout << "2. Agregar una estacion" << endl;
        cout << "3. Eliminar una estacion" << endl;
        cout << "4. Listar estaciones ordenadas" << endl;
        cout << "5. Listar estaciones con menos del 20% de ocupacion" << endl;
        cout << "6. Recorrido con menos tramos entre dos estaciones (BFS)" << endl;
        cout << "7. Ver la tabla de hash" << endl;
        cout << "0. Volver" << endl;

        opcion = leerEntero("Opcion: ");

        if (opcion == 1) {

            sistema.mostrarEstacion(leerTexto("Codigo: "));

        } else if (opcion == 2) {

            string codigo = leerTexto("Codigo: ");
            string nombre = leerTexto("Nombre (sin espacios): ");
            string barrio = leerTexto("Barrio (sin espacios): ");
            int capacidad = leerEntero("Capacidad de anclajes: ");
            int bicisDisponibles = leerEntero("Bicis disponibles: ");

            sistema.agregarEstacion(codigo, nombre, barrio, capacidad, bicisDisponibles);

        } else if (opcion == 3) {

            sistema.eliminarEstacion(leerTexto("Codigo: "));

        } else if (opcion == 4) {

            int criterio = leerEntero("Ordenar por 1. capacidad o 2. bicis disponibles: ");

            if (criterio == 1 || criterio == 2) {
                sistema.listarEstacionesOrdenadas(criterio == 1);
            } else {
                cout << "Opcion invalida" << endl;
            }

        } else if (opcion == 5) {

            sistema.listarBajaOcupacion();

        } else if (opcion == 6) {

            string origen = leerTexto("Estacion de origen: ");
            string destino = leerTexto("Estacion de destino: ");

            sistema.mostrarRecorrido(origen, destino);

        } else if (opcion == 7) {

            sistema.mostrarTablaHash();

        } else if (opcion != 0) {

            cout << "Opcion invalida" << endl;

        }
    }

}

void menuViajes(Sistema& sistema) {

    int opcion = -1;

    while (opcion != 0) {

        cout << endl << "--- B. Viajes y colas de espera ---" << endl;
        cout << "1. (B1) Viajes que salieron de una estacion entre dos fechas" << endl;
        cout << "2. (B2) Viajes de un usuario y minutos totales" << endl;
        cout << "3. (B3) Bicis con mas de X km, para revision" << endl;
        cout << "4. (B4) Retirar una bici" << endl;
        cout << "5. (B4) Devolver una bici" << endl;
        cout << "6. (B5) Enviar una bici averiada al taller" << endl;
        cout << "7. (B5) Reparar la bici mas urgente del taller" << endl;
        cout << "0. Volver" << endl;

        opcion = leerEntero("Opcion: ");

        if (opcion == 1) {

            string codigo = leerTexto("Codigo de la estacion: ");
            int desde = leerEntero("Desde (AAAAMMDD): ");
            int hasta = leerEntero("Hasta (AAAAMMDD): ");

            sistema.mostrarSalidas(codigo, desde, hasta);

        } else if (opcion == 2) {

            sistema.mostrarViajesDeUsuario(leerEntero("DNI: "));

        } else if (opcion == 3) {

            sistema.listarBicisParaRevision(leerEntero("Kilometros (X): "));

        } else if (opcion == 4) {

            string codigo = leerTexto("Codigo de la estacion: ");
            int dni = leerEntero("DNI: ");

            sistema.retirarBici(codigo, dni);

        } else if (opcion == 5) {

            sistema.devolverBici(leerTexto("Codigo de la estacion: "));

        } else if (opcion == 6) {

            sistema.enviarAlTaller(leerEntero("ID de la bici: "));

        } else if (opcion == 7) {

            sistema.repararMasUrgente();

        } else if (opcion != 0) {

            cout << "Opcion invalida" << endl;

        }
    }

}

void menuBicicletas(Sistema& sistema) {

    int opcion = -1;

    while (opcion != 0) {

        cout << endl << "--- C. Registro de bicicletas (ABB) ---" << endl;
        cout << "1. Agregar una bici" << endl;
        cout << "2. Buscar una bici por ID" << endl;
        cout << "3. Listar todas las bicis ordenadas por ID (inorder)" << endl;
        cout << "4. Contar bicis averiadas" << endl;
        cout << "5. Altura del arbol" << endl;
        cout << "6. Eliminar una bici" << endl;
        cout << "0. Volver" << endl;

        opcion = leerEntero("Opcion: ");

        if (opcion == 1) {

            int id = leerEntero("ID: ");
            string codigoEstacion = leerTexto("Codigo de la estacion: ");
            string tipo = leerTexto("Tipo (Mecanica o Electrica): ");
            string estado = leerTexto("Estado (OK o Averiada): ");
            int kilometros = leerEntero("Kilometros: ");

            sistema.agregarBici(id, codigoEstacion, tipo, estado, kilometros);

        } else if (opcion == 2) {

            sistema.mostrarBici(leerEntero("ID: "));

        } else if (opcion == 3) {

            sistema.listarBicis();

        } else if (opcion == 4) {

            sistema.mostrarCantidadAveriadas();

        } else if (opcion == 5) {

            sistema.mostrarAltura();

        } else if (opcion == 6) {

            sistema.eliminarBici(leerEntero("ID: "));

        } else if (opcion != 0) {

            cout << "Opcion invalida" << endl;

        }
    }

}

int main() {

    Sistema sistema;
    sistema.cargarDatos("../datos");

    int opcion = -1;

    while (opcion != 0) {

        cout << endl << "=== Sistema de Bicicletas Publicas ===" << endl;
        cout << "1. A. Gestion de estaciones" << endl;
        cout << "2. B. Viajes y colas de espera" << endl;
        cout << "3. C. Registro de bicicletas" << endl;
        cout << "0. Salir" << endl;

        opcion = leerEntero("Opcion: ");

        if (opcion == 1) {
            menuEstaciones(sistema);
        } else if (opcion == 2) {
            menuViajes(sistema);
        } else if (opcion == 3) {
            menuBicicletas(sistema);
        } else if (opcion != 0) {
            cout << "Opcion invalida" << endl;
        }
    }

    return 0;

}
