/*!
 * @file   main.c
 * @brief  11. Arreglos Multidimensionales - 05. Pasaje de un elemento del
 * arreglo multidimensional a una función
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

void print(int a);

int main(void)
{
    // Declaro un arreglo multidimensional (2D array) de enteros (int) de 2x3
    // elementos.
    int array2D[2][3];
    int i, j;

    // Cargo el arreglo.
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Ingrese un numero: ");
            scanf("%d", &array2D[i][j]);
        }
    }

    // Paso el contenido del arreglo a la función "print" elemento a elemento.
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            print(array2D[i][j]);
        }
    }

    return 0;
}

void print(int a) { printf("[Print] = %d\n", a); }
