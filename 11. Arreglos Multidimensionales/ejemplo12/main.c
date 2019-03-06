/**
 * \file            main.c
 * \brief           11. Arreglos Multidimensionales - Ejemplo 12 - Arrays de N dimensiones
 * \author          Javier Balloffet
 * \date            05-MAR-2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    /* 1. Declaro un arreglo multidimensional (3D array) de enteros (int) de 2x3x4 posiciones */
    int array3D[2][3][4];
    int i, j, k;

    /* 2. Cargo el arreglo */
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 4; k++) {
                printf("Ingrese un numero: ");
                scanf("%d", &array3D[i][j][k]);
            }
        }
    }

    /* 3. Imprimo el contenido del arreglo */
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 4; k++) {
                printf("Valor de array3D[%d][%d][%d] = %d\n", i, j, k, array3D[i][j][k]);
            }
        }
    }

	return 0;
}
