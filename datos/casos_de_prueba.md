# Casos de prueba

Qué tiene cada archivo de prueba y qué resultado tiene que dar tu programa en cada funcionalidad. Si da otra cosa, hay un error o tomaste una decisión de diseño distinta (en ese caso, anotala en el README).

## Qué hay en cada archivo

| Archivo | Registros | Detalle |
|---|---|---|
| `estaciones.txt` | 21 | Códigos de 3 letras. Nombres y barrios sin espacios ni tildes. |
| `bicicletas.txt` | 30 | IDs del 501 al 535, sin 507, 513, 522, 529 ni 533. 10 eléctricas y 9 averiadas. Desordenadas a propósito. |
| `viajes.txt` | 34 | Del 28/12/2025 al 12/05/2026, ordenados por fecha. 11 usuarios distintos. |
| `ciclovias.txt` | 21 | La red tiene tres partes sin conexión entre sí (ver BFS). |
| `bicicletas_ordenadas.txt` | 5 | Solo para la pregunta de análisis de la parte C. |

Aclaraciones:

- `bicis_disponibles` es un número propio de cada estación. No tiene que coincidir con cuántas bicis de `bicicletas.txt` están en esa estación (en el ejemplo de la consigna tampoco coincide).
- Los viajes no necesitan ciclovías: hay viajes entre estaciones que no están unidas por ciclovía.
- Las líneas de ejemplo de la consigna están incluidas tal cual.

## A. Estaciones

### Mostrar, agregar y eliminar (etapa 1)

| Prueba | Resultado esperado |
|---|---|
| Mostrar `PLZ` | PlazaDeMayo, Monserrat, 30 anclajes, 12 bicis |
| Mostrar `XYZ` | Avisa que no existe |
| Agregar `VUR PlazaVillaUrquiza VillaUrquiza 20 5` y después mostrar `VUR` | La encuentra |
| Agregar otra estación con el código `PLZ` | La rechaza porque el código ya existe |
| Eliminar `CAB` y después mostrar `CAB` | Avisa que no existe |
| Eliminar `CAB` otra vez | Avisa que no existe |
| Eliminar una estación que comparte balde con otras | Las otras se siguen encontrando |

Para la última prueba, imprimí la tabla balde por balde y elegí un balde con dos o más estaciones. Probá borrar la primera, una del medio y la última de esa lista.

Pista para la función hash: `CON`/`ONC`, `BOE`/`OBE` y `REC`/`CRE` tienen las mismas letras, y `ALM` suma lo mismo que `REC` en ASCII. Si tu función suma los caracteres, esos códigos chocan sí o sí, sin importar el tamaño de la tabla.

### Listar ordenadas (etapa 2)

Las estaciones con el mismo valor pueden salir en cualquier orden entre sí.

Por capacidad de anclajes:

| Capacidad | Estaciones |
|---|---|
| 15 | BOC, COL |
| 20 | BOE, TEL, ALM, CRE, FLO, DEV, LIN |
| 25 | CAB, REC, NUN, MAD, SAA |
| 30 | PLZ, CON, BEL, ONC |
| 35 | RET |
| 40 | PAL, OBE |

Por bicis disponibles: CON 0, LIN 1, BOC 2, BOE 3, CAB y FLO 4, NUN 6, ALM 7, CRE 8, TEL y COL 9, SAA 10, ONC 11, PLZ 12, DEV 13, REC 18, RET 20, BEL 22, MAD 25, OBE 30, PAL 35.

### Menos del 20 % de ocupación (etapa 2)

Tienen que salir 5: CAB (16 %), CON (0 %), BOE (15 %), BOC (13,3 %) y LIN (5 %).

No tienen que salir: FLO (4/20, exactamente 20 %), NUN (6/25, 24 %) ni PLZ (12/30, 40 %).

Si te salen 20 estaciones, estás dividiendo enteros: en C++, `12 / 30` da `0`.

### Recorrido más corto por ciclovías (etapa 3)

La red tiene tres partes sin conexión entre sí: 18 estaciones conectadas, el par DEV–LIN y SAA sola (no tiene ciclovías).

| Origen → destino | Resultado esperado |
|---|---|
| PLZ → PAL | 2 tramos: PLZ CAB PAL (el camino por OBE RET REC existe, pero es más largo) |
| BOC → NUN | 6 tramos: BOC TEL PLZ CAB PAL BEL NUN |
| FLO → COL | 4 tramos: FLO CAB PAL BEL COL |
| ALM → MAD | 4 tramos: ALM ONC OBE PLZ MAD |
| DEV → LIN | 1 tramo: DEV LIN |
| PLZ → PLZ | 0 tramos |
| PLZ → LIN | No existe recorrido |
| SAA → PLZ | No existe recorrido |
| PLZ → XYZ | La estación no existe |
| PLZ → PAL, después de eliminar CAB | 4 tramos: PLZ OBE RET REC PAL |
| FLO → PLZ, después de eliminar CAB | No existe recorrido (FLO solo se conectaba por CAB) |

En todos estos casos el camino más corto es único, así que el tuyo tiene que coincidir exactamente.

## B. Viajes y colas

### B1. Viajes que salieron de una estación en un rango de fechas (etapa 2)

| Estación | Desde – hasta | Resultado |
|---|---|---|
| PLZ | 20260310 – 20260331 | 3 (9001, 9006, 9013) |
| PLZ | 20260101 – 20261231 | 6 |
| PLZ | 20250101 – 20251231 | 1 (8997) |
| OBE | 20260301 – 20260430 | 4 |
| CON | 20260101 – 20260430 | 0 |

- El primer caso prueba los bordes del rango. Los viajes del 10/03 y del 31/03 tienen que contar; los del 05/03 y del 01/04, no.
- Los viajes que *llegan* a PLZ (8998, 9005, 9016, 9019 y 9030) no cuentan.

### B2. Viajes de un usuario (etapa 2)

| DNI | Viajes | Minutos totales |
|---|---|---|
| 30123456 | 6 (8997, 9001, 9005, 9011, 9020, 9030) | 126 |
| 27654321 | 3 (9002, 9010, 9023) | 71 |
| 41555666 | 1 (9024) | 20 |
| 11111111 | Ninguno | Avisa que no hay viajes |

### B3. Bicis con más de X km (etapa 2)

| X | Resultado |
|---|---|
| 5000 | 7: 509, 510, 515, 519, 527, 530 y 531 |
| 0 | 29: todas menos la 520, que tiene 0 km |
| 20000 | Ninguna |

Con X = 5000, la 503 (5000 km exactos) no entra y la 515 (5001 km) sí.

### B4. Cola de espera (etapa 3)

Seguí estos pasos en orden con LIN, que arranca con 1 bici:

| Paso | Resultado esperado |
|---|---|
| 1. El DNI 11111111 retira | Se lleva la bici y LIN queda con 0 |
| 2. El DNI 22222222 quiere retirar | No hay bici: queda primero en la cola |
| 3. El DNI 33333333 quiere retirar | Queda segundo en la cola |
| 4. Se devuelve una bici en LIN | Se asigna a 22222222 y LIN sigue con 0 |
| 5. Se devuelve otra bici en LIN | Se asigna a 33333333 y la cola queda vacía |
| 6. Se devuelve otra bici en LIN | No espera nadie: LIN pasa a tener 1 |

Otros casos:

- Retirar en CON (0 bicis): el usuario va directo a la cola.
- Devolver en MAD (25/25, llena y sin cola): la consigna no dice qué pasa. Decidilo vos y anotalo en el README.

### B5. Taller (etapa 3)

Hay 9 bicis averiadas:

| Tipo | Bicis | Prioridad |
|---|---|---|
| Eléctricas | 502, 530, 532 | Siempre 1 |
| Mecánicas | 504 (2200 km), 505 (4200), 509 (7420), 519 (5300), 521 (2890), 527 (6120) | La define tu regla |

Insertá las 9 y después extraelas todas. Los números de prioridad que van saliendo nunca pueden achicarse: primero salen todas las de prioridad 1, después las de 2 y al final las de 3. Dentro de una misma prioridad, el orden puede variar.

## C. Árbol de bicicletas (etapa 2)

| Prueba | Resultado esperado |
|---|---|
| Raíz | 518 (la primera línea del archivo) |
| Altura | 6 si contás niveles (nodos) o 5 si contás aristas. Usá la convención de la cátedra. |
| Recorrido inorder | Del 501 al 535 en orden, sin 507, 513, 522, 529 ni 533 |
| Contar averiadas | 9 |
| Buscar 518 | La encuentra en el primer nodo (la raíz) |
| Buscar 517 | La encuentra después de visitar 6 nodos: 518, 506, 512, 515, 516 y 517 |
| Buscar 513 | No existe (es un hueco en el medio del rango) |
| Buscar 600 | No existe (es mayor que todas) |

Para la pregunta de análisis, cargá `bicicletas_ordenadas.txt` en lugar de `bicicletas.txt` y calculá la altura. Después reordená esas 5 líneas para que la 503 quede primera y volvé a medir. Compará en los dos casos cuántos nodos visitás para buscar la 505.

## D. Backtracking (etapa 4)

Faltantes del ejemplo de la consigna: PLZ 3, CAB 7, RET 5, CON 2, BOE 5.

| C | Soluciones |
|---|---|
| 10 | 4: {PLZ, CAB}, {RET, BOE}, {PLZ, RET, CON} y {PLZ, CON, BOE} (el ejemplo de la consigna) |
| 7 | 3: {CAB}, {RET, CON} y {CON, BOE}. Prueba que acepte una sola estación. |
| 12 | 4: {CAB, RET}, {CAB, BOE}, {PLZ, CAB, CON} y {RET, CON, BOE} |
| 22 | 1: las 5 estaciones juntas |
| 1 | Ninguna: tiene que avisarlo |

Las soluciones pueden salir en otro orden.
