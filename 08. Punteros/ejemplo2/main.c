/**
 * \file            main.c
 * \brief           08. Punteros - Ejemplo 2 - Operador de-referencia
 * \author          Javier Balloffet
 * \date            Oct 5, 2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    int number;
    int* number_pointer;

    /* 1. Imprimo valor y dirección de memoria de la variable "number" */
	number = 5;
    printf("Valor de \"number\" = %d\n", number);
	printf("Direccion en memoria de \"number\" = %p\n", &number);

    /* 2. Imprimo valor, dirección de memoria y contenido de lo apuntado por "number_pointer" */
	number_pointer = &number;
    printf("Valor del puntero \"number_pointer\" = %p\n", number_pointer);
	printf("Direccion en memoria del puntero \"number_pointer\" = %p\n", &number_pointer);
    printf("Contenido de lo apuntado por el puntero \"number_pointer\" = %d\n", *number_pointer);

    /* 3. Imprimo valor, dirección de memoria y contenido de lo apuntado por "number_pointer" */
    number = 10;
    printf("Valor del puntero \"number_pointer\" = %p\n", number_pointer);
	printf("Direccion en memoria del puntero \"number_pointer\" = %p\n", &number_pointer);
    printf("Contenido de lo apuntado por el puntero \"number_pointer\" = %d\n", *number_pointer);

    /* 4. Imprimo valor y dirección de memoria de la variable "number" */
    *number_pointer = 15;
	printf("Valor de \"number\" = %d\n", number);
	printf("Direccion en memoria de \"number\" = %p\n", &number);

	return 0;
}
