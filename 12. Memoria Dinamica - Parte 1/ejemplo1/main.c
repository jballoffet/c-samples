/**
 * \file            main.c
 * \brief           12. Memoria Dinamica - Parte 1 - Ejemplo 1 - Uso de malloc() y free()
 * \author          Javier Balloffet
 * \date            Feb 28, 2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    /* 1. Declaro puntero a entero (int*) donde guardare la direccion de memoria asignada */
    int* pointer;

    /* 2. Solicito memoria al SO equivalente a una variable de tipo int */
    pointer = (int*) malloc(sizeof(int));

    /* 3. Chequeo si la asignacion de memoria fue exitosa */
    if (pointer == NULL) {
        printf("Error! Memoria no asignada.\n");
    } else {
        printf("Memoria asignada correctamente en la posición de memoria %p\n", pointer);
    }

    /* 4. Devuelvo la memoria solicitada */
    free(pointer);

	return 0;
}
