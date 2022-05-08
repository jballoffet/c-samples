/*!
 * @file   main.c
 * @brief  10. Arreglos - 08. Pasaje de un arreglo a una función
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

float average(int* array_pointer, int length);

int main(void)
{
    // Declaro un arreglo (array) de enteros (int) de 5 elementos.
    int array[5];
    int i;
    float avg;

    // Cargo el arreglo.
    for (i = 0; i < 5; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &array[i]);
    }

    // Paso el arreglo (puntero) a la función "average" para calcular el
    // promedio. En los arreglos numéricos debo pasar la longitud para saber
    // donde finaliza el mismo.
    avg = average(array, 5);

    // Imprimo el promedio.
    printf("Promedio del arreglo = %.2f\n", avg);

    return 0;
}

float average(int* array_pointer, int length)
{
    int i, sum = 0;
    float avg;

    // Recorro el arreglo usando el puntero recibido, sumando el valor de todos
    // los elementos y luego calculo el promedio.
    for (i = 0; i < length; i++)
    {
        sum += *(array_pointer + i);
    }
    avg = (float)sum / length;

    return avg;
}
