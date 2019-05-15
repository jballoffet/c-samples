/**
 * \file            main.c
 * \brief           04. Estructuras de Control - Decisión - Ejemplo 8 - Estructura "switch...case" (2)
 * \author          Javier Balloffet
 * \date            Sep 30, 2018
 * \details         Ver README para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    char option;
	
    /* 1. Solicito una opción por consola */
    printf("Ingrese la opcion deseada:\n");
    printf("a) Opcion 1\n");
    printf("b) Opcion 2\n");
    scanf("%c", &option);

    /* 2. Informo por pantalla la opción elegida */
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
