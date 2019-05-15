/**
 * \file            main.c
 * \brief           12. Memoria Dinamica - Parte 1 - Ejemplo 2 - Arreglo dinámico
 * \author          Javier Balloffet
 * \date            Feb 28, 2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    /* 1. Declaro un puntero a entero (int*) donde guardare la direccion de memoria asignada */
    int* pointer;
    int length, i;

    /* 2. Cargo cantidad de elementos a ingresar (largo del arreglo dinámico) */
    printf("Ingrese cantidad de elementos: ");
    scanf("%d", &length);

    /* 3. Solicito memoria al SO equivalente a N variables de tipo int (length) */
    pointer = (int*) malloc(length * sizeof(int));

    /* 4. Chequeo si la asignacion de memoria fue exitosa */
    if (pointer == NULL) {
        printf("Error! Memoria no asignada.\n");
    } else {
        printf("Memoria asignada correctamente en la posición de memoria %p\n", pointer);

        /* 5. Inicializo el array en cero (no es obligatorio en este caso pero es una buena práctica) */
        memset(pointer, 0, length * sizeof(int));

        /* 6. Cargo el arreglo */
        for (i = 0; i < length; i++) {
            printf("Ingrese un numero: ");
            scanf("%d", pointer + i);
        }

        /* 7. Imprimo el contenido del arreglo */
        for (i = 0; i < length; i++) {
            printf("Valor de array[%d] = %d\n", i, *(pointer + i));
        }

        /* 8. Devuelvo la memoria solicitada */
        free(pointer);
    }

	return 0;
}
