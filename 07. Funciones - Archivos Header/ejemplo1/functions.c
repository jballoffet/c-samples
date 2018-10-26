/**
 * \file            functions.c
 * \brief           7. Funciones - Archivos Header - Ejemplo 1 - Función definida por el usuario
 * \author          Javier Balloffet
 * \date            02-OCT-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include "functions.h"

// Definicion de la funcion "add"
int add(int a, int b) {
    // Recibo "a" y "b" como parámetros de la función y retorno el contenido de "result"
    int result;
    result = a + b;
    return result;
}
