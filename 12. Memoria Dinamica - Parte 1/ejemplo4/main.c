/**
 * \file            main.c
 * \brief           12. Memoria Dinamica - Parte 1 - Ejemplo 4 - Uso de realloc()
 * \author          Javier Balloffet
 * \date            05-MAR-2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    /* 1. Declaro un puntero a entero (int*) donde guardare la direccion de memoria asignada */
    int* pointer;
    int length1, length2, length3, i;

    /* 2. Largo inicial del arreglo dinámico */
    length1 = 5;
    printf("Largo del array = %d\n", length1);

    /* 3. Solicito memoria al SO equivalente a N variables de tipo int (length) */
    pointer = (int*) malloc(length1 * sizeof(int));

    /* 4. Chequeo si la asignacion de memoria fue exitosa */
    if (pointer == NULL) {
        printf("Error! Memoria no asignada.\n");
        return -1;
    }

    printf("Memoria asignada correctamente en la posición de memoria %p\n", pointer);

    /* 5. Cargo el arreglo */
    for (i = 0; i < length1; i++) {
        printf("Ingrese un numero: ");
        scanf("%d", pointer + i);
    }

    /* 6. Imprimo el contenido del arreglo */
    for (i = 0; i < length1; i++) {
        printf("Valor de array[%d] = %d\n", i, *(pointer + i));
    }

    /* 7. Modifico el largo del arreglo dinámico */
    length2 = 10;
    printf("Largo del array = %d\n", length2);

    /* 8. Solicito memoria al SO equivalente a N variables de tipo int (length) */
    pointer = (int*) realloc(pointer, length2 * sizeof(int));

    /* 9. Chequeo si la asignacion de memoria fue exitosa */
    if (pointer == NULL) {
        printf("Error! Memoria no asignada.\n");
        return -1;
    }

    printf("Memoria asignada correctamente en la posición de memoria %p\n", pointer);

    /* 10. Cargo las nuevas posiciones agregadas al arreglo dinámico */
    for (i = length1; i < length2; i++) {
        printf("Ingrese un numero: ");
        scanf("%d", pointer + i);
    }

    /* 11. Imprimo el contenido del arreglo */
    for (i = 0; i < length2; i++) {
        printf("Valor de array[%d] = %d\n", i, *(pointer + i));
    }

    /* 12. Modifico el largo del arreglo dinámico */
    length3 = 3;
    printf("Largo del array = %d\n", length3);

    /* 13. Solicito memoria al SO equivalente a N variables de tipo int (length) */
    pointer = (int*) realloc(pointer, length3 * sizeof(int));

    /* 14. Chequeo si la asignacion de memoria fue exitosa */
    if (pointer == NULL) {
        printf("Error! Memoria no asignada.\n");
        return -1;
    }

    printf("Memoria asignada correctamente en la posición de memoria %p\n", pointer);

    /* 15. Imprimo el contenido del arreglo */
    for (i = 0; i < length3; i++) {
        printf("Valor de array[%d] = %d\n", i, *(pointer + i));
    }

    /* 16. Devuelvo la memoria solicitada */
    free(pointer);

	return 0;
}
