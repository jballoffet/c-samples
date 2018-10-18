/**
 * \file            main.c
 * \brief           10. Arreglos - Ejemplo 8 - Relación puntero-array (2)
 * \author          Javier Balloffet
 * \date            17-OCT-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    // 1. Declaro un arreglo (array) de caracteres (char) de 5 posiciones inicializado
    char array[] = {12, 22, 43, 24, 63};
    int i;

    // 2. Imprimo las direcciones de cada posición del arreglo, usando índices y punteros
    for (i = 0; i < 5; i++) {
        printf("Direccion de array[%d] = %p\n", i, &array[i]);
        printf("Valor de (array + %d) = %p\n", i, (array + i));
    }

    // 3. Imprimo los contenidos de cada posición del arreglo, usando índices y punteros
    for (i = 0; i < 5; i++) {
        printf("Contenido de array[%d] = %d\n", i, array[i]);
        printf("Valor de *(array + %d) = %d\n", i, *(array + i));
    }

	return 0;
}
