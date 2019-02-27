/**
 * \file            main.c
 * \brief           11. Arreglos Multidimensionales - Ejemplo 9 - Relación puntero-array multidimensional (2)
 * \author          Javier Balloffet
 * \date            26-FEB-2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    /* 1. Declaro un arreglo multidimensional (2D array) de caracteres (char) de 2x3 posiciones */
    char array2D[2][3] = {{3, 24, -12}, {5, 0, 36}};
    int i, j;

    /* 2. Imprimo las direcciones de cada posición del arreglo, usando índices y punteros */
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("Direccion de array[%d][%d] = %p\n", i, j, &array2D[i][j]);
            printf("Valor de (array2D[%d] + %d) = %p\n", i, j, (array2D[i] + j));
            printf("Valor de (*(array2D + %d) + %d) = %p\n", i, j, (*(array2D + i) + j));
        }
    }

    /* 3. Imprimo los contenidos de cada posición del arreglo, usando índices y punteros */
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("Contenido de array[%d] = %d\n", i, array2D[i][j]);
            printf("Valor de *(array2D[%d] + %d) = %d\n", i, j, *(array2D[i] + j));
            printf("Valor de *(*(array2D + %d) + %d) = %d\n", i, j, *(*(array2D + i) + j));
        }
    }

	return 0;
}
