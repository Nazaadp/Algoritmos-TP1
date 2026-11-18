# Sistema de gestión de bicicletas públicas

## 1. Descripción del proyecto

El proyecto consiste en desarrollar un sistema de gestión de estaciones de bicicletas públicas de la Ciudad de Buenos Aires, utilizando programación orientada a objetos y estructuras de datos dinámicas implementadas manualmente en C++.

El sistema permite administrar estaciones, bicicletas y viajes, además de gestionar solicitudes de bicicletas, recorridos entre estaciones, el mantenimiento de bicicletas averiadas y redistribucion de bicicletas a estaciones.

## 2. Compilación y ejecución

### Requisitos
- Compilador g++ compatible con C++17.
- Git Bash, PowerShell o una terminal compatible.

### Compilación

#### Paso 1: Ubicarse en la carpeta del proyecto

Luego de clonar o descargar el repositorio, abrir una terminal en la carpeta raíz del proyecto.

#### Paso 2: Ingresar a la carpeta `src`

Desde la raíz del proyecto, ejecutar:

```bash
cd src
```

#### Paso 3: Compilar el programa

Una vez dentro de `src`, ejecutar:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp Sistema.cpp estructuras/*.cpp entidades/*.cpp algoritmos/*.cpp -o TPBici.exe
```

#### Paso 4: Ejecutar el programa

```bash
./TPBici.exe
```


## 3. Organización del proyecto

### Entidades

Contiene las clases que representan los elementos principales del sistema:

- **Bicicleta:** representa una bicicleta y almacena sus atributos, como identificador, estación, tipo, estado y kilometraje.
- **Estacion:** representa una estación de bicicletas, con información sobre su ubicación, capacidad y bicicletas disponibles.
- **Viaje:** representa un viaje realizado.

### Estructuras

Contiene las implementaciones propias de las estructuras de datos utilizadas:

- **`Nodo<T>`:** nodo genérico de lista enlazada, con `dato` y `siguiente`. Se usa como `Nodo<Estacion*>` en TablaHash, `Nodo<Viaje*>` en ListaViajes y `Nodo<int>` en Cola y RedCiclovias.
- **TablaHash:** implementa una tabla hash para almacenar y buscar estaciones mediante sus códigos. Utiliza baldes que contienen listas enlazadas para gestionar las colisiones.
- **ArbolBicicletas:** árbol binario de búsqueda ordenado por identificador de bicicleta.
- **Cola:** estructura FIFO de integers utilizada para administrar solicitudes de bicicletas y estaciones.
- **HeapTaller:** montículo mínimo (min-heap) utilizado para organizar las bicicletas que requieren reparación según su prioridad.
- **ListaViajes:** lista enlazada que permite almacenar y administrar los viajes realizados. Incluye funcionalidades para contar las salidas de una estación dentro de un período determinado y mostrar los viajes de un usuario.
- **RedCiclovias:** representa la red de ciclovías mediante un grafo no dirigido implementado con listas de adyacencia. Permite agregar y eliminar vértices, agregar conexiones entre estaciones y calcular el camino de menos tramos mediante BFS.

### Algoritmos

Contiene la implementación propia del algoritmo de backtracking:

- **Redistribucion:** resuelve la redistribución de bicicletas mediante backtracking. Busca todos los subconjuntos de estaciones cuyos faltantes (capacidad menos bicicletas disponibles) suman exactamente la capacidad del camión. La crea `Sistema::redistribuir` como variable local y apunta a las estaciones de la `TablaHash`: las consulta sin modificarlas y no las libera.


### Sistema

La clase `Sistema` integra las distintas entidades y estructuras de datos, coordinando las operaciones generales del programa.

### Main

Contiene el punto de entrada del programa y permite iniciar la ejecución del sistema. Muestra por consola el menú principal con un submenú por parte del enunciado.


### Datos

Contiene los archivos de texto utilizados para almacenar la información inicial del sistema, como estaciones, bicicletas, ciclovías y otros datos necesarios para su funcionamiento.
Estos archivos son leídos por el programa al iniciar su ejecución, permitiendo cargar la información y construir las estructuras de datos correspondientes.


## 4. Estructuras de datos y decisiones de implementación

Las estructuras de datos fueron implementadas manualmente mediante memoria dinámica.

Se utilizan estructuras específicas según las necesidades de cada funcionalidad:

- **Árbol binario de búsqueda:** permite organizar las bicicletas por su identificador y realizar operaciones de búsqueda, inserción y eliminación.
- **Cola:** permite gestionar información respetando el orden de llegada (FIFO).
- **Heap mínimo:** permite organizar las bicicletas que ingresan al taller según su prioridad de reparación, atendiendo primero las más urgentes.
- **Tabla hash:** utiliza una función hash basada en acumulación polinómica para calcular la posición de cada estación a partir de su código. Las colisiones se resuelven mediante encadenamiento separado, utilizando listas enlazadas en cada balde. También permite consultar la cantidad de colisiones y calcular el factor de carga.
- **Lista enlazada:** se utiliza para almacenar los viajes realizados y facilitar su recorrido, consulta y administración.
- **Grafo:** representa la red de ciclovías mediante listas de adyacencia, permitiendo modelar las conexiones entre estaciones y encontrar el camino de menos tramos entre dos puntos.


## 5. Consignas de análisis
### A. Gestión de estaciones
Con los datos de prueba utilizados, correspondientes a 21 estaciones y una capacidad de 41 baldes en la tabla hash, se obtuvieron los siguientes resultados:

- **Factor de carga:** 0,51 (51,2 %).
- **Cantidad total de colisiones:** 4.

### B. Viajes y colas de espera

#### 1. Calcular la cantidad de viajes que salieron de una estación dentro de un rango de fechas. 

**Complejidad temporal:** `O(n)`

La función tiene una complejidad temporal O(n), donde *n* representa la cantidad total de viajes almacenados. Esto se debe a que se recorre la lista enlazada completa, verificando para cada viaje si corresponde a la estación de origen y si su fecha se encuentra dentro del rango solicitado.

**Estructura elegida: Lista enlazada**

Se eligió una lista enlazada porque permite almacenar los viajes dinámicamente, sin necesidad de mantener un orden específico entre ellos. Además, como la consulta requiere recorrer los registros para verificar las condiciones solicitadas, no resulta necesario utilizar estructuras orientadas a búsquedas más específicas, como un ABB o una tabla hash.

---

#### 2. Buscar todos los viajes de un usuario dado su DNI y mostrar el total de minutos pedaleados. 

**Complejidad temporal:** `O(n)`

La función tiene una complejidad temporal O(n), donde *n* representa la cantidad total de viajes almacenados. Esto se debe a que es necesario recorrer la lista completa para identificar los viajes correspondientes al DNI ingresado, mostrarlos y acumular sus duraciones.

**Estructura elegida: Lista enlazada**

Se eligió una lista enlazada porque permite almacenar los viajes dinámicamente y no requiere mantenerlos ordenados por DNI. Como la operación necesita revisar todos los registros para encontrar los viajes de un usuario determinado, una búsqueda secuencial resulta suficiente.

---

#### 3. Listar las bicicletas con más de X kilómetros, donde X lo ingresa el usuario, para enviarlas a revisión. 

**Complejidad temporal:** `O(n)`

La función tiene una complejidad temporal O(n), donde *n* representa la cantidad total de bicicletas almacenadas en el árbol. Esto se debe a que se realiza un recorrido completo de todos los nodos para comparar el kilometraje de cada bicicleta con el valor ingresado por el usuario.

**Estructura elegida: Árbol binario de búsqueda (ABB)**

Se eligió un árbol binario de búsqueda (ABB) porque era necesario organizar las bicicletas según su identificador, facilitando otras operaciones como la búsqueda, inserción y eliminación. Sin embargo, para esta funcionalidad en particular, ese ordenamiento no permite reducir el recorrido, ya que es necesario evaluar el kilometraje de todas las bicicletas.

---

#### 4. Implementar una cola de espera por estación: si un usuario quiere retirar una bici y no hay disponibles, se encola. Cuando se devuelve una bici en esa estación, se le asigna al primero de la cola. 

**Complejidad temporal:** 
 - Retirar una bici: `O(n)` donde n es el tamaño de colaEspera
 - Devolver una bici: `O(1)`

La operación de retiro tiene una complejidad de O(n), ya que la operación de retiro en el peor caso debe recorrer toda la `colaEspera` para verificar que el DNI que pide retirar no se repita. Devolución tiene una complejidad temporal O(1), ya que la operación de desencolar se realiza directamente sobre el extremo de la cola, sin necesidad de recorrer sus elementos.

**Estructura elegida: Cola enlazada**

Se eligió una cola porque permite administrar las solicitudes de los usuarios respetando el orden de llegada (FIFO). De esta manera, cuando una bicicleta vuelve a estar disponible, se asigna al usuario que lleva más tiempo esperando.

---

#### 5. Implementar una cola de prioridad (min-heap) para el taller de reparaciones. Cada bicicleta averiada entra con una prioridad del 1 (más urgente) al 3; las eléctricas entran siempre con prioridad 1. Solo se piden dos operaciones: insertar una bici y extraer la más urgente. 

**Prioridad de bicicletas**

Las bicicletas eléctricas ingresan siempre con prioridad 1 (más urgente). Las mecánicas ingresan con prioridad 1 a 3 dependiendo los km recorridos:

 - `km >= 6000`: prioridad 1
 - `4000 <= km < 6000`: prioridad 2
 - `km < 4000`: prioridad 3

**Complejidad temporal:** `O(log n)`

Ambas operaciones tienen una complejidad temporal O(log n), ya que después de insertar o extraer una bicicleta se debe reorganizar el heap para mantener la propiedad de min-heap. Este proceso puede requerir recorrer los niveles del árbol, cuya altura es logarítmica respecto de la cantidad de elementos.

**Estructura elegida: Min-Heap**

Se eligió un min-heap porque permite organizar las bicicletas según su prioridad de reparación, manteniendo en la raíz aquella que debe atenderse primero. Esta estructura permite insertar nuevas bicicletas y extraer la más urgente de manera eficiente, sin necesidad de ordenar todos los elementos.

### C. Registro de bicicletas con árbol binario de búsqueda

#### ¿Qué altura tendría el árbol si las bicicletas se cargaran ordenadas por ID? ¿Cómo afecta eso al costo de la búsqueda? Responder con un ejemplo de 5 bicicletas. 

Si las bicicletas se cargaran ordenadas por ID, el ABB quedaría completamente desbalanceado, formando una estructura similar a una lista enlazada.

Por ejemplo, si se insertan las bicicletas con los ID 1, 2, 3, 4 y 5, cada nuevo nodo se ubicaría como hijo derecho del anterior. El árbol tendría una altura de 5 niveles.

Esto afecta negativamente el costo de búsqueda, ya que en lugar de tener una complejidad O(log n), como ocurriría en un árbol equilibrado, pasaría a ser O(n) en el peor caso. Esto se debe a que sería necesario recorrer los nodos uno por uno hasta encontrar la bicicleta buscada.


### D. Redistribución con backtracking

#### Encontrar todos los subconjuntos de estaciones cuyos faltantes suman exactamente la capacidad C del camión. Si no hay ninguno, informarlo.

**Resolución**

El faltante de cada estación se calcula como su capacidad menos las bicicletas disponibles, y solo participan las estaciones con faltante mayor a 0. La función recursiva `explorar` recorre las estaciones en orden de ingreso y, para cada una, prueba dos caminos: llevarla en la combinación o no llevarla. Si la suma llega exactamente a C, se muestra la solución, si la supera, se descarta ese camino. Al volver de una rama, la estación se desmarca para que no aparezca en las combinaciones siguientes.

**Complejidad temporal:** `O(2^n)`

La búsqueda tiene una complejidad temporal O(2^n), donde *n* representa la cantidad de estaciones con faltante mayor a 0. Esto se debe a que cada estación duplica la cantidad de caminos posibles, por lo que el árbol de decisiones tiene 2^n hojas y 2^(n+1) − 1 llamadas en total, cada una con un costo constante. El peor caso ocurre cuando C es mayor o igual que la suma de todos los faltantes, porque ninguna suma parcial lo supera y ninguna rama se corta antes de llegar a la ultima estacion. Si además se cuenta mostrar cada solución, que recorre las *n* estaciones, la cota es O(n · 2^n).

**Estructura elegida: Array**

Se eligieron dos array del mismo tamaño: uno de punteros a `Estacion` y otro de `bool` que marca las estaciones de la combinación que se está armando. Los array permiten acceder a cada estación por su posición en O(1), que es lo que necesita la recursión, y su tamaño se conoce de antemano a partir de la cantidad de estaciones de la tabla. Se guardan punteros en lugar de copias porque la `Redistribucion` solo consulta las estaciones: no es dueña de ellas y no las libera. 

## Presentacion
En la carpeta raíz del proyecto se encuentra el archivo "Presentacion TPBici Grupo1.pdf", en el cual se explican paso a paso algunas de las funcionalidades más interesantes del programa. Además, se incluyen datos de ejemplo que permiten realizar pruebas y comprobar su funcionamiento.
