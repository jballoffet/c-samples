/**
 * \file            main.c
 * \brief           06. Funciones - Argumentos por Valor - Ejemplo 2 - Scope o alcance
 * \author          Javier Balloffet
 * \date            02-OCT-2018
 * \details         Ver README para compilar, linkear y ejecutar
 */

#include <stdio.h>

void increment(int number);

int main() {
    int number = 1;

    /* 1. Invoco a "increment" y muestro el valor de "number" antes y después de llamar a la función */
    printf("Valor de \"number\" antes de incrementar = %d\n", number); 
    increment(number);
    printf("Valor de \"number\" despues de incrementar = %d\n", number); 

	return 0;
}

void increment(int number) {
    number++;
}
