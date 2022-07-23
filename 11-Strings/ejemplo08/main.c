/*!
 * @file   main.c
 * @brief  11. Strings - 08. Uso de strstr()
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Jun 14, 2022
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char string[] = "Foobarbaz";
    char substring[] = "bar";
    char* substring_location = NULL;

    // Busco la primera ocurrencia del substring en el string.
    substring_location = strstr(string, substring);

    // Imprimo la ubicación de la primera ocurrencia encontrada.
    printf("La primera ocurrencia de \"%s\" en \"%s\" es \"%s\"\n", substring,
           string, substring_location);

    return 0;
}
