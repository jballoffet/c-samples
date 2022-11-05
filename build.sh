#!/bin/bash

set -ex

find 01-Introduccion-a-C -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 02-Variables-y-Tipos-de-Datos -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 03-Operadores -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 04-Estructuras-de-Control-Decision -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 05-Estructuras-de-Control-Repeticion -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 06-Funciones-Argumentos-por-Valor -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 07-Funciones-Archivos-Header -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 08-Punteros -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 09-Funciones-Argumentos-por-Referencia -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 10-Arreglos -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 11-Strings -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 12-Arreglos-Multidimensionales -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 13-Argumentos-del-Main -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 14-Recursividad -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 15-Memoria-Dinamica -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 16-Algoritmos -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 17-Punteros-a-Funcion -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 18-Estructuras -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 19-Uniones -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 20-Campos-de-Bits -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 21-Enumeraciones -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 22-Estructuras-Autorreferenciadas -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 23-Tipo-de-Dato-Abstracto -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 24-Estructuras-de-Datos -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 25-Archivos-de-Texto -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 26-Archivos-Binarios -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 27-System-calls-de-Entrada-y-Salida -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 28-Procesos -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 29-Comunicacion-entre-Procesos -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 30-Threads -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 31-Sockets -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
# find 32-Audio -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
# find 33-Imagenes -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
# find 34-Video -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
