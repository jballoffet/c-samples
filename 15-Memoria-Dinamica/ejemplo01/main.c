/*!
 * @file   main.c
 * @brief  15. Memoria Dinamica - 01. Uso de malloc() y free()
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

    // Solicito memoria al SO equivalente a una variable de tipo int.
    pointer = (int*)malloc(sizeof(int));

    // Chequeo si la asignación de memoria fue exitosa.
    if (pointer == NULL)
    {
        printf("Error! Memoria no asignada.\n");
    }
    else
    {
        printf("Memoria asignada correctamente en la posición de memoria %p.\n",
               pointer);
    }

    // Devuelvo la memoria solicitada.
    free(pointer);

    return 0;
}
