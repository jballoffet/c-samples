/*!
 * @file   main.c
 * @brief  17. Punteros a Función - 01. Declaración de punteros a función
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 30, 2022
 */
#include <stdio.h>

int add(int a, int b);

int main(void)
{
    int number1 = 2, number2 = 5, sum;
    // Declaro un puntero a función para apuntar a una función que recibe dos
    // valores enteros y devuelve un valor entero.
    int (*function_pointer)(int, int) = NULL;

    // Asigno al puntero la dirección de la función "add".
    function_pointer = add;

    // Invoco a la función apuntada por el puntero "function_pointer".
    sum = (*function_pointer)(number1, number2);
    printf("Sumatoria = %d\n", sum);

    return 0;
}

int add(int a, int b)
{
    int result;
    result = a + b;
    return result;
}
