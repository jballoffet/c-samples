/**
 * \file            main.c
 * \brief           03. Operadores - Ejemplo 7 - Operadores de Shifteo
 * \author          Javier Balloffet
 * \date            Sep 10, 2018
 * \details         Ver README para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    /* 1. Declaración de variables */
    int a = 8;

    /* 2. Realizo varias operaciones de shifteo */
    /* 2.1. Shift Derecho (>>). Nota: 00001000 (8) >> 1 = 00000100 (4) */
    printf("%d >> %d = %d\n", a, 1, a >> 1);
    printf("%d >> %d = %d\n", a, 3, a >> 3);

    /* 2.2. Shift Izquierdo (<<). Nota:  00001000 (8) << 1 = 00010000 (16) */
    printf("%d << %d = %d\n", a, 1, a << 1);
    printf("%d << %d = %d\n", a, 2, a << 2);

	return 0;
}
