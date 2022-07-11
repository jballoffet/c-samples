/*!
 * @file   main.c
 * @brief  16. Algoritmos - 01. Búsqueda Lineal (Linear Search)
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int linear_search(const int* array, int length, int value);

int main(void)
{
    int array[] = {4, 6, 8, 2, 7, 5, 0};

    printf("El numero %d se encuentra en la ubicacion %d\n", 0,
           linear_search(array, 7, 0));
    printf("El numero %d se encuentra en la ubicacion %d\n", 9,
           linear_search(array, 7, 9));

    return 0;
}

int linear_search(const int* array, int length, int value)
{
    int i = 0;

    // Busco de forma lineal a lo largo de todo el arreglo el valor
    // solicitado.
    for (i = 0; i < length; i++)
    {
        if (array[i] == value)
        {
            // Encontré dónde está el valor buscado!
            return i;
        }
    }

    // Retorno -1 si el valor buscado no se encuentra en el arreglo.
    return -1;
}
