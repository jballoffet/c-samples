#!/bin/bash

set -ex

find 01-Introduccion-a-C -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 02-Variables-y-Tipos-de-Datos -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 03-Operadores -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
find 04-Estructuras-de-Control-Decision -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
