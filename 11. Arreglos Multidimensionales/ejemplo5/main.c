/**
 * \file            main.c
 * \brief           11. Arreglos Multidimensionales - Ejemplo 5 - Pasaje de un valor del array multidimensional a una función
 * \author          Javier Balloffet
 * \date            Feb 26, 2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

void display(int a);

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

    /* 3. Paso el contenido del array a la función "display" posición a posición */
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            display(array2D[i][j]);
        }
    }

	return 0;
}

void display(int a) {
    printf("[Display] = %d\n", a);
}
