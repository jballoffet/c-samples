/**
 * \file            main.c
 * \brief           05. Estructuras de Control - Repetición - Ejemplo 6 - Sentencia "continue"
 * \author          Javier Balloffet
 * \date            Oct 2, 2018
 * \details         Ver README para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    int number, i;
    int sum = 0;

    /* 1. Solicito 10 números por consola. Calculo la sumatoria total. 
        Si se ingresa un número negativo, vuelve al inicio del for */
    for (i = 0; i < 10; i++) {
        printf("Ingrese un numero: ");
        scanf("%d", &number);

        if (number < 0) {
            continue;
        }

        sum += number;
    }
    printf("Sumatoria = %d\n", sum);

	return 0;
}
