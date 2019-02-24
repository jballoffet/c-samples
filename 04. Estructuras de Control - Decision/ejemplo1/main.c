/**
 * \file            main.c
 * \brief           04. Estructuras de Control - Decisión - Ejemplo 1 - Estructura "if"
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

    /* 2. Si el numero ingresado es negativo, lo informo por pantalla */
    if (number < 0) {
        printf("El numero ingresado es negativo\n");
    }

	return 0;
}
