/*!
 * @file   main.c
 * @brief  06. Funciones - Argumentos por Valor - 01. Función definida por el
 *   usuario
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

// Declaración de la función "add". También se le conoce como "prototipo".
int add(int a, int b);

int main(void)
{
    int number1, number2, sum;

    printf("Ingrese un numero: ");
    scanf("%d", &number1);
    printf("Ingrese otro numero: ");
    scanf("%d", &number2);

    // Invoco a la función "add", pasándole "number1" y "number2" como
    // parámetros. Almaceno el valor que retorna la función en la variable "sum"
    sum = add(number1, number2);

    printf("Sumatoria = %d\n", sum);

    return 0;
}

// Definición de la función "add".
int add(int a, int b)
{
    // Recibo "a" y "b" como argumentos de la función y retorno el contenido de
    // "result".
    int result;
    result = a + b;
    return result;
}
