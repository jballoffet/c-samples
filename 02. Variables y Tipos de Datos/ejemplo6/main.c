/**
 * \file            main.c
 * \brief           02. Variables y Tipos de Datos - Ejemplo 6
 * \author          Javier Balloffet
 * \date            07-SEP-2018
 * \details         Ver README para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    /* 1. Declaro una variable float y le asigno el valor 3.14159265359 */
    float myDecimalVariable = 3.14159265359;

    /* 2. ¿Si quiero mostrar sólo dos decimales de mi variable decimal? */
    printf("El contenido de myDecimalVariable es %.2f\n", myDecimalVariable);

	return 0;
}
