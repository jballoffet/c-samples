/*!
 * @file   main.c
 * @brief  03. Operadores - 07. Operadores de shifteo
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main(void)
{
    int a = 8;

    // Realizo varias operaciones de shifteo.
    // Shift derecho (>>). Nota: 00001000 (8) >> 1 = 00000100 (4).
    printf("%d >> %d = %d\n", a, 1, a >> 1);
    printf("%d >> %d = %d\n", a, 3, a >> 3);

    // Shift izquierdo (<<). Nota:  00001000 (8) << 1 = 00010000 (16).
    printf("%d << %d = %d\n", a, 1, a << 1);
    printf("%d << %d = %d\n", a, 2, a << 2);

    return 0;
}
