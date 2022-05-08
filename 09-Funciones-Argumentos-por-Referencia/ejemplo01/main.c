/*!
 * @file   main.c
 * @brief  09. Funciones - Argumentos por Referencia - 01. Función definida por
 * el usuario
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

void increment(int* number_pointer);

int main(void)
{
    int number = 1;

    // Invoco a "increment" y muestro el valor de "number" antes y después de
    // llamar a la función.
    printf("Valor de \"number\" antes de incrementar = %d\n", number);
    increment(&number);
    printf("Valor de \"number\" despues de incrementar = %d\n", number);

    return 0;
}

void increment(int* number_pointer)
{
    // Incremento el contenido de lo apuntado por "number_pointer".
    (*number_pointer)++;
}
