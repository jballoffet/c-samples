/*!
 * @file   main.c
 * @brief  03. Operadores - 01. Operadores lógicos
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main(void)
{
    int a = 5, b = 5, c = 10, result;

    // Realizo varias operaciones lógicas. Nota: true == 1, false == 0.
    // AND lógica (&&).
    result = (a == b) && (c > b);
    printf("(%d == %d) && (%d > %d) = %d\n", a, b, c, b, result);
    result = (a == b) && (c < b);
    printf("(%d == %d) && (%d < %d) = %d\n", a, b, c, b, result);

    // OR lógica (||).
    result = (a == b) || (c < b);
    printf("(%d == %d) || (%d < %d) = %d\n", a, b, c, b, result);
    result = (a != b) || (c > b);
    printf("(%d != %d) || (%d > %d) = %d\n", a, b, c, b, result);

    // NOT lógica (&&).
    result = !(a != b);
    printf("!(%d != %d) = %d\n", a, b, result);
    result = !(a == b);
    printf("!(%d == %d) = %d\n", a, b, result);

    return 0;
}
