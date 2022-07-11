/*!
 * @file   main.c
 * @brief  16. Algoritmos - 06. Ordenamiento por Mezcla (Merge Sort)
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge_sort(int* array, int min, int max);
void merge(int* array, int min, int mid, int max);
void print_array(const int* array, int length);

int main(void)
{
    int array[] = {5, 2, 7, 4, 1, 6, 3, 0};

    printf("Contenido del arreglo (original): ");
    print_array(array, 8);

    // Ordeno el arreglo utilizando el método de Ordenamiento por Mezcla
    // (Merge Sort).
    merge_sort(array, 0, 7);

    printf("Contenido del arreglo (obtenido): ");
    print_array(array, 8);

    return 0;
}

void merge_sort(int* array, int min, int max)
{
    int mid;

    // max debe ser mayor a min, sino el arreglo está ordenado (tiene un solo
    // elemento).
    if (min < max)
    {
        mid = (max - min) / 2 + min;

        // Ordeno ambas mitades del arreglo por separado (algoritmo del tipo
        // "Divide y Conquistarás").
        merge_sort(array, min, mid);
        merge_sort(array, mid + 1, max);

        // Combino ambas mitades preordenadas de forma ordenada.
        merge(array, min, mid, max);
    }
}

void merge(int* array, int min, int mid, int max)
{
    int i = 0, j = 0, k = min;
    int length1, length2;
    int* array1 = NULL;
    int* array2 = NULL;

    // Creo arreglos temporales.
    length1 = mid - min + 1;
    array1 = malloc(length1 * sizeof(int));
    length2 = max - mid;
    array2 = malloc(length2 * sizeof(int));

    // Cargo los arreglos temporales.
    memcpy(array1, &array[min], length1 * sizeof(int));
    memcpy(array2, &array[mid + 1], length2 * sizeof(int));

    // Combino ambos arreglos de forma ordenada.
    while (i < length1 && j < length2)
    {
        if (array1[i] <= array2[j])
        {
            array[k] = array1[i];
            i++;
        }
        else
        {
            array[k] = array2[j];
            j++;
        }
        k++;
    }

    // Si los arreglos son de distinto largo, copio los elementos faltantes.
    memcpy(&array[k], &array1[i], (length1 - i) * sizeof(int));
    memcpy(&array[k], &array2[j], (length2 - j) * sizeof(int));

    // Libero los arreglos temporales.
    free(array1);
    free(array2);
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
