/**
 * \file            main.c
 * \brief           09. Funciones - Argumentos por Referencia - Ejemplo 2 - Swapear variables
 * \author          Javier Balloffet
 * \date            Oct 12, 2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

void swap(int* number_p1, int* number_p2);

int main() {
    int number1 = 5, number2 = 10;

    /* 1. Invoco a "swap", función que intercambia el contenido de dos variables */
    printf("Valor de \"number1\" antes del intercambio = %d\n", number1);
    printf("Valor de \"number2\" antes del intercambio = %d\n", number2);
    swap(&number1, &number2);
    printf("Valor de \"number1\" despues del intercambio = %d\n", number1);
    printf("Valor de \"number2\" despues del intercambio = %d\n", number2);

	return 0;
}

void swap(int* number_p1, int* number_p2) {
    /* 2. Intercambio el contenido de las variables */
    int aux;
    aux = *number_p1;
    *number_p1 = *number_p2;
    *number_p2 = aux;
}
