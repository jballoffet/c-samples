/**
 * \file            main.c
 * \brief           10. Arreglos - Ejemplo 5 - Pasaje de un valor del array a una función
 * \author          Javier Balloffet
 * \date            17-OCT-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

void display(int a);

int main() {
    /* 1. Declaro un arreglo (array) de enteros (int) de 5 posiciones */
    int array[5];
    int i;

    /* 2. Cargo el arreglo */
    for (i = 0; i < 5; i++) {
        printf("Ingrese un numero: ");
        scanf("%d", &array[i]);
    }

    /* 3. Paso el contenido del array a la función "display" posición a posición */
    for (i = 0; i < 5; i++) {
        display(array[i]);
    }

	return 0;
}

void display(int a) {
    printf("[Display] = %d\n", a);
}
