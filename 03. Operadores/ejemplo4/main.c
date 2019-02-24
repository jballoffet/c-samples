/**
 * \file            main.c
 * \brief           03. Operadores - Ejemplo 4 - Operadores Relacionales
 * \author          Javier Balloffet
 * \date            10-SEP-2018
 * \details         Ver README para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    /* 1. Declaracion de variables */
    int a = 5, b = 5, c = 10;

    /* 2. Realizo varias operaciones relacionales. Nota: true = 1, false = 0. */
    /* 2.1. Igual (==) */
    printf("%d == %d = %d\n", a, b, a == b);
    printf("%d == %d = %d\n", a, c, a == c);

    /* 2.2. Distinto (!=) */
    printf("%d != %d = %d\n", a, b, a != b);
    printf("%d != %d = %d\n", a, c, a != c);

    /* 2.3. Mayor (>) */
    printf("%d > %d = %d\n", a, b, a > b);
    printf("%d > %d = %d\n", a, c, a > c);

    /* 2.4. Menor (<) */
    printf("%d < %d = %d\n", a, b, a < b);
    printf("%d < %d = %d\n", a, c, a < c);

    /* 2.5. Mayor o Igual (>=) */
    printf("%d >= %d = %d\n", a, b, a >= b);
    printf("%d >= %d = %d\n", a, c, a >= c);

    /* 2.6. Menor o Igual (<=) */
    printf("%d <= %d = %d\n", a, b, a <= b);
    printf("%d <= %d = %d\n", a, c, a <= c);

	return 0;
}
