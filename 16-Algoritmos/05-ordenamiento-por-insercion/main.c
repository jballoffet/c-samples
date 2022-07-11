/*!
 * @file   main.c
 * @brief  16. Algoritmos - 05. Ordenamiento por Inserción (Insertion Sort)
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

void insertion_sort(int* array, int length);
void print_array(const int* array, int length);

int main(void)
{
    int array[] = {5, 2, 7, 4, 1, 6, 3, 0};

    printf("Contenido del arreglo (original): ");
    print_array(array, 8);

    // Ordeno el arreglo utilizando el método de Ordenamiento por Inserción
    // (Insertion Sort).
    insertion_sort(array, 8);

    printf("Contenido del arreglo (obtenido): ");
    print_array(array, 8);

    return 0;
}

void insertion_sort(int* array, int length)
{
    int i, j, current_value;

    for (i = 1; i < length; i++)
    {
        current_value = array[i];
        j = i - 1;

        // Desplazo todos los elementos mayores al actual una posición adelante.
        while (j >= 0 && array[j] > current_value)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = current_value;
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
