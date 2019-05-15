/**
 * \file            functions.c
 * \brief           07. Funciones - Archivos Header - Ejemplo 4 - Variables globales (2)
 * \author          Javier Balloffet
 * \date            Oct 4, 2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include "functions.h"

/* 1. Declaro la variable "number" como global */
int number1 = 1;

/* 2. Declaro la variable "number" como global (al archivo functions.c) */
static int number2 = 5;

void increment() {
    /* 3. Muestro el valor de "number1" antes y después de incrementar */
    printf("Valor de \"number1\" en increment() antes de incrementar = %d\n", number1);
    number1++;
    printf("Valor de \"number1\" en increment() despues de incrementar = %d\n", number1);

    /* 4. Muestro el valor de "number2" antes y después de incrementar */
    printf("Valor de \"number2\" en increment() antes de incrementar = %d\n", number2);
    number2++;
    printf("Valor de \"number2\" en increment() despues de incrementar = %d\n", number2); 
}
