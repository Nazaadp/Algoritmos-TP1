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
# A. Gestión de estaciones
Con los datos de prueba utilizados, correspondientes a 21 estaciones y una capacidad de 41 baldes en la tabla hash, se obtuvieron los siguientes resultados:

- **Factor de carga:** 0,51 (51,2 %).
- **Cantidad total de colisiones:** 4.

# B. Viajes y colas de espera

### 1. Calcular la cantidad de viajes que salieron de una estación dentro de un rango de fechas. 

**Complejidad temporal:** `O(n)`

La función tiene una complejidad temporal O(n), donde *n* representa la cantidad total de viajes almacenados. Esto se debe a que se recorre la lista enlazada completa, verificando para cada viaje si corresponde a la estación de origen y si su fecha se encuentra dentro del rango solicitado.

**Estructura elegida: Lista enlazada**

Se eligió una lista enlazada porque permite almacenar los viajes dinámicamente, sin necesidad de mantener un orden específico entre ellos. Además, como la consulta requiere recorrer los registros para verificar las condiciones solicitadas, no resulta necesario utilizar estructuras orientadas a búsquedas más específicas, como un ABB o una tabla hash.

---

### 2. Buscar todos los viajes de un usuario dado su DNI y mostrar el total de minutos pedaleados. 

**Complejidad temporal:** `O(n)`

La función tiene una complejidad temporal O(n), donde *n* representa la cantidad total de viajes almacenados. Esto se debe a que es necesario recorrer la lista completa para identificar los viajes correspondientes al DNI ingresado, mostrarlos y acumular sus duraciones.

**Estructura elegida: Lista enlazada**

Se eligió una lista enlazada porque permite almacenar los viajes dinámicamente y no requiere mantenerlos ordenados por DNI. Como la operación necesita revisar todos los registros para encontrar los viajes de un usuario determinado, una búsqueda secuencial resulta suficiente.

---

### 3. Listar las bicicletas con más de X kilómetros, donde X lo ingresa el usuario, para enviarlas a revisión. 

**Complejidad temporal:** `O(n)`

La función tiene una complejidad temporal O(n), donde *n* representa la cantidad total de bicicletas almacenadas en el árbol. Esto se debe a que se realiza un recorrido completo de todos los nodos para comparar el kilometraje de cada bicicleta con el valor ingresado por el usuario.

**Estructura elegida: Árbol binario de búsqueda (ABB)**

Se eligió un árbol binario de búsqueda (ABB) porque era necesario organizar las bicicletas según su identificador, facilitando otras operaciones como la búsqueda, inserción y eliminación. Sin embargo, para esta funcionalidad en particular, ese ordenamiento no permite reducir el recorrido, ya que es necesario evaluar el kilometraje de todas las bicicletas.

---

### 4. Implementar una cola de espera por estación: si un usuario quiere retirar una bici y no hay disponibles, se encola. Cuando se devuelve una bici en esa estación, se le asigna al primero de la cola. 

**Complejidad temporal:** `O(1)`

Las operaciones de retiro y devolución tienen una complejidad temporal O(1), ya que las operaciones de encolar y desencolar se realizan directamente sobre los extremos de la cola, sin necesidad de recorrer sus elementos.

**Estructura elegida: Cola enlazada**

Se eligió una cola porque permite administrar las solicitudes de los usuarios respetando el orden de llegada (FIFO). De esta manera, cuando una bicicleta vuelve a estar disponible, se asigna al usuario que lleva más tiempo esperando.

---

### 5. Implementar una cola de prioridad (min-heap) para el taller de reparaciones. Cada bicicleta averiada entra con una prioridad del 1 (más urgente) al 3; las eléctricas entran siempre con prioridad 1. Solo se piden dos operaciones: insertar una bici y extraer la más urgente. 

**Complejidad temporal:** `O(log n)`

Ambas operaciones tienen una complejidad temporal O(log n), ya que después de insertar o extraer una bicicleta se debe reorganizar el heap para mantener la propiedad de min-heap. Este proceso puede requerir recorrer los niveles del árbol, cuya altura es logarítmica respecto de la cantidad de elementos.

**Estructura elegida: Min-Heap**

Se eligió un min-heap porque permite organizar las bicicletas según su prioridad de reparación, manteniendo en la raíz aquella que debe atenderse primero. Esta estructura permite insertar nuevas bicicletas y extraer la más urgente de manera eficiente, sin necesidad de ordenar todos los elementos.

# C. Registro de bicicletas con árbol binario de búsqueda

### Análisis: efecto de insertar bicicletas ordenadas por ID

Si las bicicletas se cargaran ordenadas por ID, el ABB quedaría completamente desbalanceado, formando una estructura similar a una lista enlazada.

Por ejemplo, si se insertan las bicicletas con los ID 1, 2, 3, 4 y 5, cada nuevo nodo se ubicaría como hijo derecho del anterior. El árbol tendría una altura de 5 niveles.

Esto afecta negativamente el costo de búsqueda, ya que en lugar de tener una complejidad O(log n), como ocurriría en un árbol equilibrado, pasaría a ser O(n) en el peor caso. Esto se debe a que sería necesario recorrer los nodos uno por uno hasta encontrar la bicicleta buscada.
