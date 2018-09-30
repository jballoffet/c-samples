/**
 * \file            main.c
 * \brief           4. Estructuras de Control - Decisión - Ejemplo 2 - Estructura "if...else"
 * \author          Javier Balloffet
 * \date            29-SEP-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    int number;
	
    // 1. Solicito un número por consola
    printf("Ingrese un numero: ");
    scanf("%d", &number);

    // 2. Informo por pantalla si el numero ingresado es negativo o no
    if (number < 0) {
        printf("El numero ingresado es negativo\n");
    } else {
        printf("El numero ingresado no es negativo\n");
    }

	return 0;
}
