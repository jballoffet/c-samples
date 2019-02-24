/**
 * \file            main.c
 * \brief           04. Estructuras de Control - Decisión - Ejemplo 3 - Estructura "if...else" anidada
 * \author          Javier Balloffet
 * \date            29-SEP-2018
 * \details         Ver README para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    int number;
	
    /* 1. Solicito un número por consola */
    printf("Ingrese un numero: ");
    scanf("%d", &number);

    /* 2. Informo por pantalla si el número ingresado es negativo, positivo o cero */
    if (number < 0) {
        printf("El numero ingresado es negativo\n");
    } else {
        if (number > 0) {
            printf("El numero ingresado es positivo\n");
        } else {
            printf("El numero ingresado es cero\n");
        }
    }

	return 0;
}
