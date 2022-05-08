/*!
 * @file   main.c
 * @brief  07. Funciones - Archivos Header - 02. Funciones 'static'
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

#include "functions.h"

int main(void)
{
    int number1, number2, sum;

    printf("Ingrese un numero: ");
    scanf("%d", &number1);
    printf("Ingrese otro numero: ");
    scanf("%d", &number2);

    // Invoco a la función "add", pasándole "number1" y "number2" como
    // parámetros. Almaceno el valor que retorna la función en la variable
    // "sum".
    sum = add(number1, number2);

    printf("Sumatoria = %d\n", sum);

    return 0;
}
