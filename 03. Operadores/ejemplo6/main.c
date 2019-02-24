/**
 * \file            main.c
 * \brief           03. Operadores - Ejemplo 6 - Operadores a Nivel de Bits
 * \author          Javier Balloffet
 * \date            10-SEP-2018
 * \details         Ver README para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    /* 1. Declaracion de variables */
    int a = 12, b = 25;

    /* 2. Realizo varias operaciones a nivel de bits. */
    /* 2.1. AND (&). Nota: 00001100 (12) AND 00011001 (25) = 00001000 (8) */
    printf("%d & %d = %d\n", a, b, a & b);

    /* 2.2. OR (|). Nota: 00001100 (12) OR 00011001 (25) = 00011101 (29) */
    printf("%d | %d = %d\n", a, b, a | b);

    /* 2.3. XOR (^). Nota: 00001100 (12) XOR 00011001 (25) = 00010101 (21) */
    printf("%d ^ %d = %d\n", a, b, a ^ b);

    /* 2.4. Complemento (~). Nota: ~00001100 (12) = 11110011 (-13) (El signo es interpretado en CA2) */
    printf("~%d = %d\n", a, ~a);

	return 0;
}
