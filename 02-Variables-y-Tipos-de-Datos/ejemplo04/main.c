/*!
 * @file   main.c
 * @brief  02. Variables y Tipos de Datos - 04. Signo de una variable
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main(void)
{
    // Declaro variables enteras (int) con diferentes modificadores de signo.
    signed int signed_number;
    unsigned int unsigned_number;

    // Asigno a ambas variables el número anterior a 0.
    signed_number = 0 - 1;
    unsigned_number = 0 - 1;

    // Imprimo el contenido de las variables en pantalla.
    printf("El contenido de signed_number es %d\n", signed_number);
    printf("El contenido de unsigned_number es %u\n", unsigned_number);

    return 0;
}
