/**
 * \file            main.c
 * \brief           03. Operadores - Ejemplo 5 - Operadores Lógicos
 * \author          Javier Balloffet
 * \date            10-SEP-2018
 * \details         Ver README para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    /* 1. Declaracion de variables */
    int a = 5, b = 5, c = 10, result;

    /* 2. Realizo varias operaciones lógicas. Nota: true = 1, false = 0. */
    /* 2.1. AND Lógica (&&) */
    result = (a == b) && (c > b);
    printf("(%d == %d) && (%d > %d) = %d\n", a, b, c, b, result);
    result = (a == b) && (c < b);
    printf("(%d == %d) && (%d < %d) = %d\n", a, b, c, b, result);

    /* 2.2. OR Lógica (||) */
    result = (a == b) || (c < b);
    printf("(%d == %d) || (%d < %d) = %d\n", a, b, c, b, result);
    result = (a != b) || (c > b);
    printf("(%d != %d) || (%d > %d) = %d\n", a, b, c, b, result);

    /* 2.3. NOT Lógica (&&) */
    result = !(a != b);
    printf("!(%d != %d) = %d\n", a, b, result);
    result = !(a == b);
    printf("!(%d == %d) = %d\n", a, b, result);

	return 0;
}
