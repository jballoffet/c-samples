/*!
 * @file   main.c
 * @brief  17. Punteros a Función - 03. Arreglos de punteros a función
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 30, 2022
 */
#include <stdio.h>

float add(float a, float b);
float sub(float a, float b);
float mul(float a, float b);
float div(float a, float b);

int main(void)
{
    float number1 = 5.0, number2 = 2.0, result;
    // Declaro un arreglo de punteros a función para apuntar a funciones que
    // reciben dos valores reales y devuelven un valor real y lo inicializo.
    float (*function_pointer[4])(float, float) = {add, sub, mul, div};

    // Invoco a la función apuntada por "function_pointer[0]".
    result = (*function_pointer[0])(number1, number2);
    printf("Suma = %f\n", result);

    // Invoco a la función apuntada por "function_pointer[1]".
    result = (*function_pointer[1])(number1, number2);
    printf("Resta = %f\n", result);

    // Invoco a la función apuntada por "function_pointer[2]".
    result = (*function_pointer[2])(number1, number2);
    printf("Multiplicacion = %f\n", result);

    // Invoco a la función apuntada por "function_pointer[3]".
    result = (*function_pointer[3])(number1, number2);
    printf("Division = %f\n", result);

    return 0;
}

float add(float a, float b)
{
    float result;
    result = a + b;
    return result;
}

float sub(float a, float b)
{
    float result;
    result = a - b;
    return result;
}

float mul(float a, float b)
{
    float result;
    result = a * b;
    return result;
}

float div(float a, float b)
{
    float result;
    result = a / b;
    return result;
}
