/**
 * \file            main.c
 * \brief           03. Operadores - Ejemplo 3 - Operadores de Asignación
 * \author          Javier Balloffet
 * \date            Sep 9, 2018
 * \details         Ver README para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    /* 1. Declaración de variables */
    int a = 5, b;

    /* 2. Realizo varias operaciones de asignación */
    /* 2.1. Asignación simple (=) */
    b = a;
    printf("b = %d\n", b);

    /* 2.2. Suma y asignación (+=) */
    b += a;
    printf("b = %d\n", b);

    /* 2.3. Resta y asignación (-=) */
    b -= a;
    printf("b = %d\n", b);

    /* 2.4. Multiplicación y asignación (*=) */
    b *= a;
    printf("b = %d\n", b);

    /* 2.5. División y asignación (/=) */
    b /= a;
    printf("b = %d\n", b);

    /* 2.6. Resto y asignación (%=) */
    b %= a;
    printf("b = %d\n", b);

	return 0;
}
