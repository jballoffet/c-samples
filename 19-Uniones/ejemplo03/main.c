/*!
 * @file   main.c
 * @brief  19. Uniones - 03. Operador flecha
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 16, 2022
 */
#include <stdio.h>

typedef union Number
{
    int x;
    int y;
} Number;

int main(void)
{
    // Declaro una variable de tipo "Number" y un puntero a "Number".
    Number number;
    Number* number_pointer = NULL;

    // Asigno al puntero la dirección de la variable.
    number_pointer = &number;

    // Asigno 2 al campo X, utilizando el operador flecha.
    number_pointer->x = 2;
    printf("Campo X: %d\n", number_pointer->x);
    printf("Campo Y: %d\n", number_pointer->y);

    // Asigno 5 al campo Y, utilizando el operador flecha.
    number_pointer->y = 5;
    printf("Campo X: %d\n", number_pointer->x);
    printf("Campo Y: %d\n", number_pointer->y);

    return 0;
}
