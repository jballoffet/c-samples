/*!
 * @file   main.c
 * @brief  03. Operadores - 06. Operadores a nivel de bits
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main(void)
{
    int a = 12, b = 25;

    // Realizo varias operaciones a nivel de bits.
    // AND (&). Nota: 00001100 (12) AND 00011001 (25) = 00001000 (8).
    printf("%d & %d = %d\n", a, b, a & b);

    // OR (|). Nota: 00001100 (12) OR 00011001 (25) = 00011101 (29).
    printf("%d | %d = %d\n", a, b, a | b);

    // XOR (^). Nota: 00001100 (12) XOR 00011001 (25) = 00010101 (21).
    printf("%d ^ %d = %d\n", a, b, a ^ b);

    // Complemento (~). Nota: ~00001100 (12) = 11110011 (-13) (El signo es
    // interpretado en CA2).
    printf("~%d = %d\n", a, ~a);

    return 0;
}
