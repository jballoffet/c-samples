/**
 * \file            main.c
 * \brief           13. Strings - Ejemplo 2 - Uso de scanf() con strings
 * \author          Javier Balloffet
 * \date            Mar 6, 2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    /* 1. Declaro un string (array) de caracteres (char) de varias maneras diferentes */
    char name[20];

    /* 2. Ingreso el contenido del string por consola */
    printf("Ingrese su nombre: ");
    scanf("%s", name);

    /* 3. Imprimo el contenido del string */
    printf("Su nombre es %s\n", name);

	return 0;
}
