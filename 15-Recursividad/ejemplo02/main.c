/*!
 * @file   main.c
 * @brief  15. Recursividad - 02. Función factorial
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Oct 5, 2018
 */
#include <stdio.h>

int recursive_factorial(int number);

int main(void)
{
    int number, factorial;

    // Solicito un número por consola.
    printf("Ingrese un numero: ");
    scanf("%d", &number);

    // Calculo el factorial del número ingresado, usando una funcion recursiva.
    factorial = recursive_factorial(number);
    printf("Factorial de %d = %d\n", number, factorial);

    return 0;
}

int recursive_factorial(int number)
{
    if (number > 0)
    {
        // La función se llama a si misma!
        return number * recursive_factorial(number - 1);
    }
    else
    {
        // Condición de salida, siempre debe estar!
        return 1;
    }
}
