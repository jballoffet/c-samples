/**
 * \file            main.c
 * \brief           07. Funciones - Archivos Header - Ejemplo 4 - Variables globales (2)
 * \author          Javier Balloffet
 * \date            Oct 4, 2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include "functions.h"

/* 1. Declaro la variable "number2" como global (al archivo main.c) */
static int number2 = 10;

int main() {
    /* 2. Invoco a "increment" y muestro el valor de "number1" antes y después de llamar a la función */
    printf("Valor de \"number1\" en main() antes de incrementar = %d\n", number1); 
    increment();
    printf("Valor de \"number1\" en main() despues de incrementar = %d\n", number1);
    number1++;
    printf("Valor de \"number1\" en main() despues de incrementar nuevamente = %d\n", number1);

    /* 3. Muestro el valor de "number2" antes y después de incrementar */
    printf("Valor de \"number2\" en main() antes de incrementar = %d\n", number2);
    number2++;
    printf("Valor de \"number2\" en main() despues de incrementar = %d\n", number2);

	return 0;
}
