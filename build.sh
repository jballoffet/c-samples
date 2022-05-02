#!/bin/bash

set -ex

#find -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
pushd "01-Introduccion-a-C/ejemplo01" && make && popd

pushd "02-Variables-y-Tipos-de-Datos/ejemplo01" && make && popd
pushd "02-Variables-y-Tipos-de-Datos/ejemplo02" && make && popd
pushd "02-Variables-y-Tipos-de-Datos/ejemplo03" && make && popd
pushd "02-Variables-y-Tipos-de-Datos/ejemplo04" && make && popd
pushd "02-Variables-y-Tipos-de-Datos/ejemplo05" && make && popd
pushd "02-Variables-y-Tipos-de-Datos/ejemplo06" && make && popd
pushd "02-Variables-y-Tipos-de-Datos/ejemplo07" && make && popd

pushd "03-Operadores/ejemplo01" && make && popd
pushd "03-Operadores/ejemplo02" && make && popd
pushd "03-Operadores/ejemplo03" && make && popd
pushd "03-Operadores/ejemplo04" && make && popd
pushd "03-Operadores/ejemplo05" && make && popd
pushd "03-Operadores/ejemplo06" && make && popd
pushd "03-Operadores/ejemplo07" && make && popd
pushd "03-Operadores/ejemplo08" && make && popd
