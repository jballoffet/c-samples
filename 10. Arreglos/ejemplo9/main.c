/**
 * \file            main.c
 * \brief           10. Arreglos - Ejemplo 9 - Pasaje de un array a una función (usando punteros)
 * \author          Javier Balloffet
 * \date            19-OCT-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

float average(int* array_pointer, int length);

int main() {
    // 1. Declaro un arreglo (array) de enteros (int) de 5 posiciones
    int array[5];
    int i;
    float avg;

    // 2. Cargo el arreglo
    for (i = 0; i < 5; i++) {
        printf("Ingrese un numero: ");
        scanf("%d", &array[i]);
    }

    // 3. Paso el puntero al comienzo del arreglo a la función "average" para calcular el promedio
    avg = average(array, 5);

    // 4. Imprimo el promedio
    printf("Promedio del array = %.2f\n", avg);

	return 0;
}

float average(int* array_pointer, int length) {
    int i, sum = 0;
    float avg;

    for (i = 0; i < length; i++) {
        sum += *(array_pointer + i);
    }
    avg = (float) sum / length;

    return avg;
}
