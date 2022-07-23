/*!
 * @file   main.c
 * @brief  12. Arreglos Multidimensionales - 08. Pasaje de un arreglo
 * multidimensional a una función (usando punteros)
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

float average(int* array2D_pointer, int rows, int columns);

int main(void)
{
    // Declaro un arreglo multidimensional (2D array) de enteros (int) de 2x3
    // elementos.
    int array2D[2][3];
    int i, j;
    float avg;

    // Cargo el arreglo.
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Ingrese un numero: ");
            scanf("%d", &array2D[i][j]);
        }
    }

    // Paso el arreglo multidimensional a la función "average" para calcular el
    // promedio. En los arreglos numéricos debo pasar las longitudes para saber
    // donde finaliza el mismo.
    avg = average(&array2D[0][0], 2, 3);

    // Imprimo el promedio.
    printf("Promedio del arreglo 2D = %.2f\n", avg);

    return 0;
}

float average(int* array2D_pointer, int rows, int columns)
{
    int i, j, sum = 0;
    float avg;

    // Recorro el arreglo recibido, sumando el valor de todos los elementos y
    // luego calculo el promedio.
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            sum += *(array2D_pointer + i * columns + j);
        }
    }
    avg = (float)sum / (rows * columns);

    return avg;
}
