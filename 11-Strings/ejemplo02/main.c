/*!
 * @file   main.c
 * @brief  11. Strings - 02. Uso de scanf() y printf() con strings
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Mar 6, 2019
 */
#include <stdio.h>

int main(void)
{
    // Declaro un string sin inicializar.
    char name[20];

    // Ingreso el contenido del string por consola.
    printf("Ingrese su nombre: ");
    scanf("%s", name);

    // Imprimo el contenido del string.
    printf("Su nombre es %s\n", name);

    return 0;
}
