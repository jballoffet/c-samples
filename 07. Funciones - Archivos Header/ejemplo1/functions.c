/**
 * \file            functions.c
 * \brief           07. Funciones - Archivos Header - Ejemplo 1 - Función definida por el usuario
 * \author          Javier Balloffet
 * \date            Oct 2, 2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include "functions.h"

/* 1. Definicion de la funcion "add" */
int add(int a, int b) {
    /* 2. Recibo "a" y "b" como parámetros de la función y retorno el contenido de "result" */
    int result;
    result = a + b;
    return result;
}
