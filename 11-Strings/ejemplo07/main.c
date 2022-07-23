/*!
 * @file   main.c
 * @brief  11. Strings - 07. Uso de strcat()
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Jun 14, 2022
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char string1[15] = "Foobar";
    char string2[] = "baz";

    // Concateno string2 a string1.
    strcat(string1, string2);

    // Imprimo el contenido del string concatenado.
    printf("String concatenado: %s\n", string1);

    return 0;
}
