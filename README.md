# Sistema de gestión de bicicletas públicas

## 1. Descripción del proyecto

El proyecto consiste en desarrollar un sistema de gestión de estaciones de bicicletas públicas de la Ciudad de Buenos Aires, utilizando programación orientada a objetos y estructuras de datos dinámicas implementadas manualmente en C++.

El sistema permite administrar estaciones, bicicletas y viajes, además de gestionar solicitudes de bicicletas, recorridos entre estaciones y el mantenimiento de bicicletas averiadas.

## 2. Compilación y ejecución

### Requisitos
- Compilador C++ compatible con C++11 o superior.
- Git Bash o una terminal compatible.

### Compilación

### Paso 1: Ubicarse en la carpeta del proyecto

Luego de clonar o descargar el repositorio, abrir una terminal en la carpeta raíz del proyecto.

### Paso 2: Ingresar a la carpeta `src`

Desde la raíz del proyecto, ejecutar:

```bash
cd src
```

### Paso 3: Compilar el programa

Una vez dentro de `src`, ejecutar:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp Sistema.cpp estructuras/*.cpp entidades/*.cpp -o TPBici.exe
```

### Paso 4: Ejecutar el programa

```bash
./TPBici.exe
```


## 3. Organización del proyecto

### Entidades

Contiene las clases que representan los elementos principales del sistema:

- **Bicicleta:** representa una bicicleta y almacena sus atributos, como identificador, estación, tipo, estado y kilometraje.
- **Estacion:** representa una estación de bicicletas, con información sobre su ubicación, capacidad y bicicletas disponibles.
- **Viaje:** representa un viaje realizado o solicitado entre estaciones.

### Estructuras

Contiene las implementaciones propias de las estructuras de datos utilizadas:

- **TablaHash:** implementa una tabla hash para almacenar y buscar estaciones mediante sus códigos. Utiliza baldes que contienen listas enlazadas para gestionar las colisiones.
- **ArbolBicicletas:** árbol binario de búsqueda ordenado por identificador de bicicleta.
- **Cola:** estructura FIFO utilizada para administrar solicitudes de bicicletas.
- **HeapTaller:** montículo mínimo utilizado para organizar las bicicletas que requieren reparación según su prioridad.
- **ListaViajes:** lista enlazada que permite almacenar y administrar los viajes realizados. Incluye funcionalidades para contar las salidas de una estación dentro de un período determinado y mostrar los viajes de un usuario.
- **RedCiclovias:** representa la red de ciclovías mediante un grafo no dirigido implementado con listas de adyacencia. Permite agregar y eliminar vértices, agregar conexiones entre estaciones y calcular el camino más corto mediante BFS.


### Sistema

La clase `Sistema` integra las distintas entidades y estructuras de datos, coordinando las operaciones generales del programa.

### Main

Contiene el punto de entrada del programa y permite iniciar la ejecución del sistema.


### Datos

Contiene los archivos de texto utilizados para almacenar la información inicial del sistema, como estaciones, bicicletas, ciclovías y otros datos necesarios para su funcionamiento.
Estos archivos son leídos por el programa al iniciar su ejecución, permitiendo cargar la información y construir las estructuras de datos correspondientes.


## 4. Estructuras de datos y decisiones de implementación

Las estructuras de datos fueron implementadas manualmente mediante memoria dinámica.

Se utilizan estructuras específicas según las necesidades de cada funcionalidad:

- **Árbol binario de búsqueda:** permite organizar las bicicletas por su identificador y realizar operaciones de búsqueda, inserción y eliminación.
- **Cola:** permite gestionar informacion respetando el orden de llegada (FIFO).
- **Heap mínimo:** permite organizar las bicicletas que ingresan al taller según su prioridad de reparación, atendiendo primero las de mayor prioridad.
- **Tabla hash:** utiliza una función hash basada en acumulación polinómica para calcular la posición de cada estación a partir de su código. Las colisiones se resuelven mediante encadenamiento separado, utilizando listas enlazadas en cada balde. También permite consultar la cantidad de colisiones y calcular el factor de carga.
- **Lista enlazada:** se utiliza para almacenar los viajes realizados y facilitar su recorrido, consulta y administración.
- **Grafo:** representa la red de ciclovías mediante listas de adyacencia, permitiendo modelar las conexiones entre estaciones y encontrar el camino más corto entre dos puntos.


## 5. Consignas de análisis






readme

# A. Gestión de estaciones

- Factor de Carga: 0.51

- Colisiones finales: ?
