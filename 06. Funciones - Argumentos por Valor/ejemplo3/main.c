/**
 * \file            main.c
 * \brief           06. Funciones - Argumentos por Valor - Ejemplo 3 - Variables locales
 * \author          Javier Balloffet
 * \date            04-OCT-2018
 * \details         Ver README para compilar, linkear y ejecutar
 */

#include <stdio.h>

void increment();

int main() {
    /* 1. Declaro una variable "number" local a la funcion main */
    int number = 1;

    /* 2. Invoco a "increment" y muestro el valor de "number" antes y después de llamar a la función */
    printf("Valor de \"number\" en main() antes de incrementar = %d\n", number); 
    increment();
    printf("Valor de \"number\" en main() despues de incrementar = %d\n", number);

	return 0;
}

void increment() {
    /* 3. Declaro una variable "number" local a la funcion increment */
    int number = 1;

    /* 4. Muestro el valor de "number" antes y después de incrementar */
    printf("Valor de \"number\" en increment() antes de incrementar = %d\n", number);
    number++;
    printf("Valor de \"number\" en increment() despues de incrementar = %d\n", number); 
}