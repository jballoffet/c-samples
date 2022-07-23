/*!
 * @file   main.c
 * @brief  11. Strings - 06. Uso de strcpy()
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Jun 14, 2022
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char string1[10] = "Foobar";
    char string2[10];

    // Copio string1 en string2.
    strcpy(string2, string1);

    // Imprimo el contenido de los strings.
    printf("String original: %s\n", string1);
    printf("String copiado: %s\n", string2);

    return 0;
}
