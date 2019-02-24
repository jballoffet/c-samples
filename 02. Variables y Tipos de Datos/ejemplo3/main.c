/**
 * \file            main.c
 * \brief           02. Variables y Tipos de Datos - Ejemplo 3
 * \author          Javier Balloffet
 * \date            07-SEP-2018
 * \details         Ver README para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    /* 1. Puedo asignarles un valor a las variables en el mismo momento de la declaracion */
    int myIntegerVariable = 5;

    /* 2. Imprimo el contenido de la variable en pantalla */
    printf("El contenido de myIntegerVariable es %d\n", myIntegerVariable);

    /* 3. Modifico el contenido de la variable */
    myIntegerVariable = 10;

    /* 4. Imprimo el contenido de la variable en pantalla */
    printf("El contenido de myIntegerVariable es %d\n", myIntegerVariable);

	return 0;
}
