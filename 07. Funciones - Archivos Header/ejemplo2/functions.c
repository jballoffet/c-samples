/**
 * \file            functions.c
 * \brief           07. Funciones - Archivos Header - Ejemplo 2 - Funciones estáticas
 * \author          Javier Balloffet
 * \date            04-OCT-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include "functions.h"

/* Declaración o prototipo de la funcion estática "display" */
static void display(int a);

int add(int a, int b) {
    int result;
    result = a + b;
    display(result);
    return result;
}

/* Definición de la funcion estática "display" */
static void display(int a) {
    /* Recibo "a" como parámetro de la función */
    printf("[Display] = %d\n", a);
}
