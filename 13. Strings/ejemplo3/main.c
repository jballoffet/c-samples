/**
 * \file            main.c
 * \brief           13. Strings - Ejemplo 3 - Uso de gets() y puts()
 * \author          Javier Balloffet
 * \date            06-MAR-2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    /* 1. Declaro un string sin inicializar */
    char name[25];

    /* 2. Ingreso el contenido del string por consola */
    printf("Ingrese su nombre: ");
    gets(name);

    /* 3. Imprimo el contenido del string */
    printf("Su nombre es: ");
    puts(name);

	return 0;
}
