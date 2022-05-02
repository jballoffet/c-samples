/*!
 * @file   main.c
 * @brief  03. Operadores - 02. Operadores de incremento y decremento
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main(void)
{
    int a = 9;

    // Realizo varias operaciones de incremento y decremento e imprimo el
    // resultado en pantalla. Incremento (++) prefijo.
    printf("Incremento (++) prefijo:\n");
    printf("a = %d\n", a);
    printf("++a = %d\n", ++a);
    printf("a = %d\n", a);

    // Decremento (--) prefijo.
    printf("Decremento (--) prefijo:\n");
    printf("a = %d\n", a);
    printf("--a = %d\n", --a);
    printf("a = %d\n", a);

    // Incremento (++) postfijo.
    printf("Incremento (++) postfijo:\n");
    printf("a = %d\n", a);
    printf("a++ = %d\n", a++);
    printf("a = %d\n", a);

    // Decremento (--) postfijo.
    printf("Decremento (--) postfijo:\n");
    printf("a = %d\n", a);
    printf("a-- = %d\n", a--);
    printf("a = %d\n", a);

    return 0;
}
