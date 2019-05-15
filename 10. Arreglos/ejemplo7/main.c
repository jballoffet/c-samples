/**
 * \file            main.c
 * \brief           10. Arreglos - Ejemplo 7 - Relación puntero-array
 * \author          Javier Balloffet
 * \date            Oct 17, 2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    /* 1. Declaro un arreglo (array) de caracteres (char) de 5 posiciones */
    char array[5];
    int i;

    /* 2. Imprimo las direcciones de memoria de cada posición del arreglo */
    for (i = 0; i < 5; i++) {
        printf("Direccion de array[%d] = %p\n", i, &array[i]);
    }

    /* 3. Imprimo el contenido de array */
    printf("Contenido de array = %p\n", array);

	return 0;
}
