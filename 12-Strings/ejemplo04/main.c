/*!
 * @file   main.c
 * @brief  12. Strings - 04. Uso de strlen()
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Mar 6, 2019
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Declaro un string sin inicializar.
    char word[20];
    int length;

    // Ingreso el contenido del string por consola.
    printf("Ingrese una palabra: ");
    scanf("%s", word);

    // Imprimo el contenido del string.
    printf("Palabra ingresada: %s\n", word);

    // Imprimo el largo del string.
    length = strlen(word);
    printf("Largo de la palabra ingresada: %d\n", length);

    return 0;
}
