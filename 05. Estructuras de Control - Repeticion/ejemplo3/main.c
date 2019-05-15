/**
 * \file            main.c
 * \brief           05. Estructuras de Control - Repetición - Ejemplo 3 - Estructura "while"
 * \author          Javier Balloffet
 * \date            Oct 2, 2018
 * \details         Ver README para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    /* 1. Debo inicializar el valor de "number" antes de preguntar en el while! */
    int number = 1;
    int sum = 0;

    /* 2. Solicito números por consola hasta que se ingrese cero. Calculo la sumatoria total */
    while (number != 0) {
        printf("Ingrese un numero (ingrese 0 para salir): ");
        scanf("%d", &number);
        sum += number;
    }
    printf("Sumatoria total = %d\n", sum);

	return 0;
}
