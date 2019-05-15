/**
 * \file            main.c
 * \brief           10. Arreglos - Ejemplo 4 - Carga y lectura de arrays
 * \author          Javier Balloffet
 * \date            Oct 17, 2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    /* 1. Declaro un arreglo (array) de enteros (int) de 5 posiciones */
    int array[5];
    int i;

    /* 2. Cargo el arreglo */
    for (i = 0; i < 5; i++) {
        printf("Ingrese un numero: ");
        scanf("%d", &array[i]);
    }

    /* 3. Imprimo el contenido del arreglo */
    for (i = 0; i < 5; i++) {
        printf("Valor de array[%d] = %d\n", i, array[i]);
    }

	return 0;
}
