/*!
 * @file   main.c
 * @brief  14. Memoria Dinamica - 04. Uso de realloc()
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Declaro un puntero a entero (int*) donde guardar la dirección de memoria
    // asignada.
    int* pointer;
    // Declaro un puntero auxiliar para la re-alocación de memoria.
    int* aux;
    int length, i;

    // Largo inicial del arreglo dinámico.
    length = 5;
    printf("Largo del array = %d\n", length);

    // Solicito memoria al SO equivalente a N variables de tipo int (length).
    pointer = (int*)malloc(length * sizeof(int));

    // Chequeo si la asignación de memoria fue exitosa.
    if (pointer == NULL)
    {
        printf("Error! Memoria no asignada.\n");
        return -1;
    }

    printf("Memoria asignada correctamente en la posicion de memoria %p.\n",
           pointer);

    // Cargo el arreglo.
    for (i = 0; i < length; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", pointer + i);
    }

    // Imprimo el contenido del arreglo.
    for (i = 0; i < length; i++)
    {
        printf("Valor de array[%d] = %d\n", i, *(pointer + i));
    }

    // Modifico el largo del arreglo dinámico.
    length = 10;
    printf("Largo del array = %d\n", length);

    // Solicito memoria al SO equivalente a N variables de tipo int (length).
    aux = (int*)realloc(pointer, length * sizeof(int));

    // Chequeo si la asignacion de memoria fue exitosa.
    if (aux == NULL)
    {
        printf("Error! Memoria no asignada.\n");

        // Debo liberar la anterior alocación de memoria.
        free(pointer);
        return -1;
    }

    pointer = aux;
    printf("Memoria asignada correctamente en la posicion de memoria %p.\n",
           pointer);

    // Cargo las nuevas posiciones agregadas al arreglo dinámico.
    for (i = 5; i < length; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", pointer + i);
    }

    // Imprimo el contenido del arreglo.
    for (i = 0; i < length; i++)
    {
        printf("Valor de array[%d] = %d\n", i, *(pointer + i));
    }

    // Modifico el largo del arreglo dinámico.
    length = 3;
    printf("Largo del array = %d\n", length);

    // Solicito memoria al SO equivalente a N variables de tipo int (length).
    aux = (int*)realloc(pointer, length * sizeof(int));

    // Chequeo si la asignacion de memoria fue exitosa.
    if (aux == NULL)
    {
        printf("Error! Memoria no asignada.\n");

        // Debo liberar la anterior alocación de memoria.
        free(pointer);
        return -1;
    }

    pointer = aux;
    printf("Memoria asignada correctamente en la posicion de memoria %p.\n",
           pointer);

    // Imprimo el contenido del arreglo.
    for (i = 0; i < length; i++)
    {
        printf("Valor de array[%d] = %d\n", i, *(pointer + i));
    }

    // Devuelvo la memoria solicitada.
    free(pointer);

    return 0;
}
