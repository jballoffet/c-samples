/**
 * \file            main.c
 * \brief           07. Funciones - Archivos Header - Ejemplo 3 - Variables globales
 * \author          Javier Balloffet
 * \date            04-OCT-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include "functions.h"

int main() {
    /* 1. Invoco a "increment" y muestro el valor de "number" antes y después de llamar a la función */
    printf("Valor de \"number\" en main() antes de incrementar = %d\n", number); 
    increment();
    printf("Valor de \"number\" en main() despues de incrementar = %d\n", number);
    number++;
    printf("Valor de \"number\" en main() despues de incrementar nuevamente = %d\n", number);

	return 0;
}
