/**
 * \file            main.c
 * \brief           11. Arreglos Multidimensionales - Ejemplo 3 - Declaración de arrays multidimensionales (3)
 * \author          Javier Balloffet
 * \date            24-FEB-2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    /* 1. Declaro un arreglo multidimensional (2D array) de enteros (int) de 2x3 posiciones e inicializo el arreglo (no es necesario indicar la cantidad de posiciones de la primera dimension) */
    int array2D[][3] = {{3, 24, -12}, {5, 0, 36}};

    /* 2. Imprimo el contenido del arreglo */
    printf("Valor de array[0][0] = %d\n", array2D[0][0]);
    printf("Valor de array[0][1] = %d\n", array2D[0][1]);
    printf("Valor de array[0][2] = %d\n", array2D[0][2]);
    printf("Valor de array[1][0] = %d\n", array2D[1][0]);
    printf("Valor de array[1][1] = %d\n", array2D[1][1]);
    printf("Valor de array[1][2] = %d\n", array2D[1][2]);

    /* 3. Imprimo el tamaño del arreglo (en bytes) */
    printf("Tamanio del arreglo (en bytes) = %ld\n", sizeof(array2D));

    /* 4. Imprimo el tamaño del arreglo (en posiciones) */
    printf("Tamanio del arreglo (en posiciones) = %ld\n", sizeof(array2D) / sizeof(int));

	return 0;
}
