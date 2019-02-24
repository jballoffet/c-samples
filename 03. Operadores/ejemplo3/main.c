/**
 * \file            main.c
 * \brief           03. Operadores - Ejemplo 3 - Operadores de Asignación
 * \author          Javier Balloffet
 * \date            09-SEP-2018
 * \details         Ver README para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    /* 1. Declaracion de variables */
    int a = 5, b;

    /* 2. Realizo varias operaciones de asignacion */
    /* 2.1. Asignacion simple (=) */
    b = a;
    printf("b = %d\n", b);

    /* 2.2. Suma y asignacion (+=) */
    b += a;
    printf("b = %d\n", b);

    /* 2.3. Resta y asignacion (-=) */
    b -= a;
    printf("b = %d\n", b);

    /* 2.4. Multiplicación y asignacion (*=) */
    b *= a;
    printf("b = %d\n", b);

    /* 2.5. División y asignacion (/=) */
    b /= a;
    printf("b = %d\n", b);

    /* 2.6. Resto y asignacion (*=) */
    b %= a;
    printf("b = %d\n", b);

	return 0;
}
