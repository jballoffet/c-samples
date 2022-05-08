/*!
 * @file   main.c
 * @brief  12. Memoria Dinamica - 03. Uso de calloc()
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
    int length, i;

    // Cargo cantidad de elementos a ingresar (largo del arreglo dinámico).
    printf("Ingrese cantidad de elementos: ");
    scanf("%d", &length);

    // Solicito memoria al SO equivalente a N variables de tipo int (length)
    // inicializada en cero.
    pointer = (int*)calloc(length, sizeof(int));

    // Chequeo si la asignación de memoria fue exitosa.
    if (pointer == NULL)
    {
        printf("Error! Memoria no asignada.\n");
    }
    else
    {
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

        // Devuelvo la memoria solicitada.
        free(pointer);
    }

    return 0;
}
