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
