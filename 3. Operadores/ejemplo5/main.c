/**
 * \file            main.c
 * \brief           3. Operadores - Ejemplo 5 - Operadores Lógicos
 * \author          Javier Balloffet
 * \date            10-SEP-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    // 1. Declaracion de variables
    int a = 5, b = 5, c = 10, resultado;

    // 2. Realizo varias operaciones lógicas. Nota: true = 1, false = 0.
    // 2.1. AND Lógica (&&)
    resultado = (a == b) && (c > b);
    printf("(%d == %d) && (%d > %d) = %d\n", a, b, c, b, resultado);
    resultado = (a == b) && (c < b);
    printf("(%d == %d) && (%d < %d) = %d\n", a, b, c, b, resultado);

    // 2.2. OR Lógica (||)
    resultado = (a == b) || (c < b);
    printf("(%d == %d) || (%d < %d) = %d\n", a, b, c, b, resultado);
    resultado = (a != b) || (c > b);
    printf("(%d != %d) || (%d > %d) = %d\n", a, b, c, b, resultado);

    // 2.3. NOT Lógica (&&)
    resultado = !(a != b);
    printf("!(%d != %d) = %d\n", a, b, resultado);
    resultado = !(a == b);
    printf("!(%d == %d) = %d\n", a, b, resultado);

	return 0;
}
