/**
 * \file            main.c
 * \brief           5. Estructuras de Control - Repetición - Ejemplo 1 - Estructura "for"
 * \author          Javier Balloffet
 * \date            30-SEP-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    int i;
	
    // 1. Repito el contenido dentro del for 5 veces
    for (i = 0; i < 5; i++) {
        printf("Mi primer bucle en C! (i = %d)\n", i);
    }

	return 0;
}
