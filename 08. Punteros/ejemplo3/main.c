/**
 * \file            main.c
 * \brief           08. Punteros - Ejemplo 3 - Tipos y tamaños de los punteros
 * \author          Javier Balloffet
 * \date            05-OCT-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    char* char_pointer;
    int* int_pointer;
    float* float_pointer;
    double* double_pointer;

    /* 1. ¿Cuánto espacio ocupa en memoria cada tipo de puntero? */
    printf("Un puntero a char (char*) tiene %ld bytes de largo\n", sizeof(char_pointer));
    printf("Un puntero a int (int*) tiene %ld bytes de largo\n", sizeof(int_pointer));
    printf("Un puntero a float (float*) tiene %ld bytes de largo\n", sizeof(float_pointer));
    printf("Un puntero a double (double*) tiene %ld bytes de largo\n", sizeof(double_pointer));

	return 0;
}
