/**
 * \file            main.c
 * \brief           02. Variables y Tipos de Datos - Ejemplo 4
 * \author          Javier Balloffet
 * \date            07-SEP-2018
 * \details         Ver README para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    /* 1. Declaro variables integer con diferentes modificadores de signo */
    signed int myIntegerVariable1;
    unsigned int myIntegerVariable2;

    /* 2. Asigno a ambas variables el número anterior a 0 */
    myIntegerVariable1 = 0 - 1;
    myIntegerVariable2 = 0 - 1;

    /* 3. Imprimo el contenido de las variables en pantalla */
    printf("El contenido de myIntegerVariable1 es %d\n", myIntegerVariable1);
    printf("El contenido de myIntegerVariable2 es %u\n", myIntegerVariable2);

	return 0;
}
