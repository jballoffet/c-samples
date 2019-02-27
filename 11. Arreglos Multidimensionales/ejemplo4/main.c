/**
 * \file            main.c
 * \brief           11. Arreglos Multidimensionales - Ejemplo 4 - Carga y lectura de arrays multidimensionales
 * \author          Javier Balloffet
 * \date            26-FEB-2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    /* 1. Declaro un arreglo multidimensional (2D array) de enteros (int) de 2x3 posiciones */
    int array2D[2][3];
    int i, j;

    /* 2. Cargo el arreglo */
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("Ingrese un numero: ");
            scanf("%d", &array2D[i][j]);
        }
    }

    /* 3. Imprimo el contenido del arreglo */
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("Valor de array2D[%d][%d] = %d\n", i, j, array2D[i][j]);
        }
    }

	return 0;
}
