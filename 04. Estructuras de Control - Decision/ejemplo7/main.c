/**
 * \file            main.c
 * \brief           04. Estructuras de Control - Decisión - Ejemplo 7 - Estructura "switch...case"
 * \author          Javier Balloffet
 * \date            Sep 30, 2018
 * \details         Ver README para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    int option;
	
    /* 1. Solicito una opción por consola */
    printf("Ingrese la opcion deseada:\n");
    printf("1) Opcion 1\n");
    printf("2) Opcion 2\n");
    scanf("%d", &option);

    /* 2. Informo por pantalla la opción elegida */
    switch (option) {
        case 1:
            printf("Usted eligio la opcion 1\n");
            break;
    
        case 2:
            printf("Usted eligio la opcion 2\n");
            break;

        default:
            printf("Usted eligio una opcion incorrecta\n");
            break;
    }

	return 0;
}
