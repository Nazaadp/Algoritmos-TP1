#include <iostream>
#include "HeapTaller.h"

using namespace std;

// Constructor y destructor.

HeapTaller::HeapTaller()
{
    capacidad = 10;
    cantidad = 0;
    datos = new EntradaTaller[capacidad];
}

HeapTaller::~HeapTaller()
{
    delete[] datos;
}

void HeapTaller::subirNodo(int indice)
{
    if (indice == 0)
    {
        return;
    }

    int padre = (indice - 1) / 2;

    if (datos[indice].prioridad < datos[padre].prioridad)
    {

        EntradaTaller aux = datos[indice];
        datos[indice] = datos[padre];
        datos[padre] = aux;

        subirNodo(padre);
    }
}

void HeapTaller::bajarNodo(int indice)
{

    int hijoIzquierdo = 2 * indice + 1;
    int hijoDerecho = 2 * indice + 2;
    int menor = indice;

    if (hijoIzquierdo < cantidad && datos[hijoIzquierdo].prioridad < datos[menor].prioridad)
    {
        menor = hijoIzquierdo;
    }

    if (hijoDerecho < cantidad && datos[hijoDerecho].prioridad < datos[menor].prioridad)
    {
        menor = hijoDerecho;
    }

    if (menor != indice)
    {
        EntradaTaller aux = datos[indice];
        datos[indice] = datos[menor];
        datos[menor] = aux;
        bajarNodo(menor);
    }
}

void HeapTaller::redimensionar()
{
    int nuevaCapacidad = capacidad * 2;
    EntradaTaller *nuevoAlmacenamiento = new EntradaTaller[nuevaCapacidad];

    for (int i = 0; i < cantidad; i++)
    {
        nuevoAlmacenamiento[i] = datos[i];
    }

    delete[] datos;

    datos = nuevoAlmacenamiento;
    capacidad = nuevaCapacidad;
}

void HeapTaller::insertar(Bicicleta *bici)
{

    if (cantidad == capacidad)
    {
        redimensionar();
    }

    datos[cantidad].bici = bici;
    datos[cantidad].prioridad = bici->getPrioridad();

    cantidad++;

    subirNodo(cantidad - 1);
}

// Saca del taller la bici mas urgente y la devuelve.
Bicicleta *HeapTaller::extraerMasUrgente()
{

    if (cantidad == 0)
    {
        return nullptr;
    }

    Bicicleta *bici = datos[0].bici;

    datos[0] = datos[cantidad - 1];

    cantidad--;

    if (cantidad > 0)
    {
        bajarNodo(0);
    }

    return bici;
}

bool HeapTaller::contiene(int idBici)
{
    for (int i = 0; i < cantidad; i++)
    {
        if (datos[i].bici->getId() == idBici)
        {
            return true;
        }
    }

    return false;
}