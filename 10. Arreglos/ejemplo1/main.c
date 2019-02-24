/**
 * \file            main.c
 * \brief           10. Arreglos - Ejemplo 1 - Declaración de arrays
 * \author          Javier Balloffet
 * \date            12-OCT-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    /* 1. Declaro un arreglo (array) de enteros (int) de 5 posiciones */
    int array[5];
    
    /* 2. Inicializo el arreglo */
    array[0] = 3;
    array[1] = 24;
    array[2] = 12;
    array[3] = 5;
    array[4] = 76;

    /* 3. Imprimo el contenido del arreglo */
    printf("Valor de array[0] = %d\n", array[0]);
    printf("Valor de array[1] = %d\n", array[1]);
    printf("Valor de array[2] = %d\n", array[2]);
    printf("Valor de array[3] = %d\n", array[3]);
    printf("Valor de array[4] = %d\n", array[4]);

    /* 4. Imprimo el tamaño del arreglo (en bytes) */
    printf("Tamanio del arreglo (en bytes) = %ld\n", sizeof(array));

    /* 5. Imprimo el tamaño del arreglo (en posiciones) */
    printf("Tamanio del arreglo (en posiciones) = %ld\n", sizeof(array) / sizeof(int));

	return 0;
}
