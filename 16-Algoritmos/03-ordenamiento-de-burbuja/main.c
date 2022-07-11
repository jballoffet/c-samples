/*!
 * @file   main.c
 * @brief  16. Algoritmos - 03. Ordenamiento de Burbuja (Bubble Sort)
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

#define FALSE 0
#define TRUE 1

void bubble_sort(int* array, int length);
void print_array(const int* array, int length);
void swap(int* x, int* y);

int main(void)
{
    int array[] = {5, 2, 7, 4, 1, 6, 3, 0};

    printf("Contenido del arreglo (original): ");
    print_array(array, 8);

    // Ordeno el arreglo utilizando el método de Ordenamiento de Burbuja (Bubble
    // Sort).
    bubble_sort(array, 8);

    printf("Contenido del arreglo (obtenido): ");
    print_array(array, 8);

    return 0;
}

void bubble_sort(int* array, int length)
{
    int i, j, swapped;

    for (i = 0; i < length - 1; i++)
    {
        swapped = FALSE;
        for (j = 0; j < length - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                swapped = TRUE;
            }
        }

        // Si no intercambió nunca, entonces el arreglo ya está ordenado!
        if (swapped == FALSE)
        {
            break;
        }
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
