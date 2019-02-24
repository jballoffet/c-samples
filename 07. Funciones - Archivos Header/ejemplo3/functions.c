/**
 * \file            functions.c
 * \brief           07. Funciones - Archivos Header - Ejemplo 3 - Variables globales
 * \author          Javier Balloffet
 * \date            04-OCT-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include "functions.h"

/* 1. Declaro la variable "number" como global */
int number = 1;

void increment() {
    /* 2. Muestro el valor de "number" antes y después de incrementar */
    printf("Valor de \"number\" en increment() antes de incrementar = %d\n", number);
    number++;
    printf("Valor de \"number\" en increment() despues de incrementar = %d\n", number); 
}
