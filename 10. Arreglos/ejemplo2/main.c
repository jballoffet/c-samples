/**
 * \file            main.c
 * \brief           10. Arreglos - Ejemplo 2 - Declaración de arrays (2)
 * \author          Javier Balloffet
 * \date            Oct 12, 2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    /* 1. Declaro un arreglo (array) de enteros (int) de 5 posiciones e inicializo el arreglo */
    int array[5] = {3, 24, 12, 5, 76};

    /* 2. Imprimo el contenido del arreglo */
    printf("Valor de array[0] = %d\n", array[0]);
    printf("Valor de array[1] = %d\n", array[1]);
    printf("Valor de array[2] = %d\n", array[2]);
    printf("Valor de array[3] = %d\n", array[3]);
    printf("Valor de array[4] = %d\n", array[4]);

    /* 3. Imprimo el tamaño del arreglo (en bytes) */
    printf("Tamanio del arreglo (en bytes) = %ld\n", sizeof(array));

    /* 4. Imprimo el tamaño del arreglo (en posiciones) */
    printf("Tamanio del arreglo (en posiciones) = %ld\n", sizeof(array) / sizeof(int));

	return 0;
}
