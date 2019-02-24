/**
 * \file            main.c
 * \brief           04. Estructuras de Control - Decisión - Ejemplo 7 - Estructura "switch...case" (2)
 * \author          Javier Balloffet
 * \date            30-SEP-2018
 * \details         Ver README para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    char option;
	
    /* 1. Solicito una opcion por consola */
    printf("Ingrese la opcion deseada:\n");
    printf("a) Opcion 1\n");
    printf("b) Opcion 2\n");
    scanf("%c", &option);

    /* 2. Informo por pantalla la opcion elegida */
    switch (option) {
        case 'a':
            printf("Usted eligio la opcion 1\n");
            break;
    
        case 'b':
            printf("Usted eligio la opcion 2\n");
            break;

        default:
            printf("Usted eligio una opcion incorrecta\n");
            break;
    }

	return 0;
}
