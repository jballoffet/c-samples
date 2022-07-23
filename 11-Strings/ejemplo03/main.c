/*!
 * @file   main.c
 * @brief  11. Strings - 03. Uso de fgets() y puts()
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Mar 6, 2019
 */
#include <stdio.h>

int main(void)
{
    // Declaro un string sin inicializar.
    char name[25];

    // Ingreso el contenido del string por consola.
    printf("Ingrese su nombre: ");
    fgets(name, 25, stdin);

    // Imprimo el contenido del string.
    printf("Su nombre es: ");
    puts(name);

    return 0;
}
