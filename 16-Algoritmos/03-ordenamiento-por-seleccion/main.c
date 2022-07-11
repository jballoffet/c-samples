/*!
 * @file   main.c
 * @brief  16. Algoritmos - 03. Ordenamiento por Selección (Selection Sort)
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

void selection_sort(int* array, int length);
void print_array(const int* array, int length);
void swap(int* x, int* y);

int main(void)
{
    int array[] = {5, 2, 7, 4, 1, 6, 3, 0};

    printf("Contenido del arreglo (original): ");
    print_array(array, 8);

    // Ordeno el arreglo utilizando el método de Ordenamiento por Selección
    // (Selection Sort).
    selection_sort(array, 8);

    printf("Contenido del arreglo (obtenido): ");
    print_array(array, 8);

    return 0;
}

void selection_sort(int* array, int length)
{
    int i, j, min_index;

    // El límite del arreglo desordenado se corre uno a uno.
    for (i = 0; i < length - 1; i++)
    {
        // Encuentro el menor elemento en el arreglo desordenado.
        min_index = i;
        for (j = i + 1; j < length; j++)
        {
            if (array[j] < array[min_index])
            {
                min_index = j;
            }
        }

        // Intercambio el mínimo elemento encontrado con el primer elemento del
        // arreglo desordenado.
        swap(&array[min_index], &array[i]);
    }
}

void print_array(const int* array, int length)
{
    int i;

    printf("[");
    for (i = 0; i < length - 1; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("%d]\n", array[i]);
}

void swap(int* x, int* y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}
