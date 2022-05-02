/*!
 * @file   main.c
 * @brief  03. Operadores - 03. Operadores de asignación
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main(void)
{
    int a = 5, b;

    // Realizo varias operaciones de asignación.
    // Asignación simple (=).
    b = a;
    printf("b = %d\n", b);

    // Suma y asignación (+=).
    b += a;
    printf("b = %d\n", b);

    // Resta y asignación (-=).
    b -= a;
    printf("b = %d\n", b);

    // Multiplicación y asignación (*=).
    b *= a;
    printf("b = %d\n", b);

    // División y asignación (/=).
    b /= a;
    printf("b = %d\n", b);

    // Resto y asignación (%=).
    b %= a;
    printf("b = %d\n", b);

    return 0;
}
