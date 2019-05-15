/**
 * \file            main.c
 * \brief           11. Arreglos Multidimensionales - Ejemplo 8 - Relación puntero-array multidimensional
 * \author          Javier Balloffet
 * \date            Feb 26, 2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    /* 1. Declaro un arreglo multidimensional (2D array) de caracteres (char) de 2x3 posiciones */
    char array2D[2][3];
    int i, j;

    /* 2. Imprimo las direcciones de memoria de cada posición del arreglo */
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("Direccion de array2D[%d][%d] = %p\n", i, j, &array2D[i][j]);
        }
    }

    /* 3. Imprimo el contenido de array2D */
    printf("Contenido de array2D = %p\n", array2D);

    /* 4. Imprimo el contenido de array2D[i] (se comporta como un arreglo de punteros) */
    for (i = 0; i < 2; i++) {
        printf("Contenido de array2D[%d] = %p\n", i, array2D[i]);
    }

	return 0;
}
