/**
 * \file            main.c
 * \brief           06. Funciones - Argumentos por Valor - Ejemplo 2 - Scope o alcance de una variable
 * \author          Javier Balloffet
 * \date            Oct 2, 2018
 * \details         Ver README para compilar, linkear y ejecutar
 */

#include <stdio.h>

void increment(int number);

int main() {
    int number = 1;

    /* 1. Invoco a "increment" y muestro el valor de "number" antes y después de llamar a la función */
    printf("Valor de \"number\" en main() antes de incrementar = %d\n", number); 
    increment(number);
    printf("Valor de \"number\" en main() despues de incrementar = %d\n", number); 

	return 0;
}

void increment(int number) {
    printf("Valor de \"number\" en increment() antes de incrementar = %d\n", number);
    number++;
    printf("Valor de \"number\" en increment() despues de incrementar = %d\n", number); 
}
