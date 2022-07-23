/*!
 * @file   main.c
 * @brief  14. Recursividad - 01. Función sumatoria
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Oct 5, 2018
 */
#include <stdio.h>

int recursive_sum(int number);

int main(void)
{
    int number, sum;

    // Solicito un número por consola.
    printf("Ingrese un numero: ");
    scanf("%d", &number);

    // Calculo la sumatoria de todos los números desde cero hasta el número
    // ingresado (incluído), usando una funcion recursiva.
    sum = recursive_sum(number);
    printf("Sumatoria de 0 a %d = %d\n", number, sum);

    return 0;
}

int recursive_sum(int number)
{
    if (number != 0)
    {
        // La función se llama a si misma!
        return number + recursive_sum(number - 1);
    }
    else
    {
        // Condición de salida, siempre debe estar!
        return 0;
    }
}
