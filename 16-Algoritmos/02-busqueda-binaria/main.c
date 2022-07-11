/*!
 * @file   main.c
 * @brief  16. Algoritmos - 02. Búsqueda Binaria (Binary Search)
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int binary_search(const int* array, int min, int max, int value);

int main(void)
{
    int array[] = {0, 2, 4, 5, 6, 7, 8};

    printf("El numero %d se encuentra en la ubicacion %d\n", 6,
           binary_search(array, 0, 6, 6));
    printf("El numero %d se encuentra en la ubicacion %d\n", 9,
           binary_search(array, 0, 6, 9));

    return 0;
}

int binary_search(const int* array, int min, int max, int value)
{
    int mid;

    // max debe ser mayor o igual a min, sino el valor no se encuentra en el
    // arreglo.
    if (max >= min)
    {
        mid = (max - min) / 2 + min;

        // Si el valor a buscar es igual al del medio, lo retorno.
        if (array[mid] == value)
        {
            return mid;
        }

        // Si el valor a buscar es menor al del medio, busco en la mitad
        // inferior.
        if (array[mid] > value)
        {
            return binary_search(array, min, mid - 1, value);
        }

        // Sino, busco en la mitad superior.
        return binary_search(array, min + 1, max, value);
    }

    // Retorno -1 si el valor a buscar no se encuentra en el arreglo.
    return -1;
}
