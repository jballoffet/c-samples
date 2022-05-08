/*!
 * @file   main.c
 * @brief  08. Punteros - 01. Operador referencia
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main(void)
{
    int number = 5;

    // Imprimo valor y dirección de memoria de la variable "number".
    printf("Valor de \"number\" = %d\n", number);
    printf("Direccion en memoria de \"number\" = %p\n", &number);

    return 0;
}
