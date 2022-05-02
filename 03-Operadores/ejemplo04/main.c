/*!
 * @file   main.c
 * @brief  03. Operadores - 04. Operadores relacionales
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main(void)
{
    int a = 5, b = 5, c = 10;

    // Realizo varias operaciones relacionales. Nota: true == 1, false == 0.
    // Igual (==).
    printf("%d == %d = %d\n", a, b, a == b);
    printf("%d == %d = %d\n", a, c, a == c);

    // Distinto (!=).
    printf("%d != %d = %d\n", a, b, a != b);
    printf("%d != %d = %d\n", a, c, a != c);

    // Mayor (>).
    printf("%d > %d = %d\n", a, b, a > b);
    printf("%d > %d = %d\n", a, c, a > c);

    // Menor (<).
    printf("%d < %d = %d\n", a, b, a < b);
    printf("%d < %d = %d\n", a, c, a < c);

    // Mayor o Igual (>=).
    printf("%d >= %d = %d\n", a, b, a >= b);
    printf("%d >= %d = %d\n", a, c, a >= c);

    // Menor o Igual (<=).
    printf("%d <= %d = %d\n", a, b, a <= b);
    printf("%d <= %d = %d\n", a, c, a <= c);

    return 0;
}
