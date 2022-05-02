/*!
 * @file   main.c
 * @brief  02. Variables y Tipos de Datos - 03. Inicializacion de variables
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main(void)
{
    // Puedo asignarles un valor a las variables en el mismo momento de la
    // declaración.
    int number = 5;

    // Imprimo el contenido de la variable en pantalla.
    printf("El contenido de number es %d\n", number);

    // Modifico el contenido de la variable.
    number = 10;

    // Imprimo el contenido de la variable en pantalla.
    printf("El contenido de number es %d\n", number);

    return 0;
}
