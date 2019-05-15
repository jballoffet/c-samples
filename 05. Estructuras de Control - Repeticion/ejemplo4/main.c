/**
 * \file            main.c
 * \brief           05. Estructuras de Control - Repetición - Ejemplo 4 - Estructura "do...while"
 * \author          Javier Balloffet
 * \date            Oct 2, 2018
 * \details         Ver README para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    /* 1. No hace falta inicializar el valor de "number" ya que primero asigno y luego pregunto */
    int number;
    int sum = 0;

    /* 2. Solicito números por consola hasta que se ingrese cero. Calculo la sumatoria total */
    do {
        printf("Ingrese un numero (ingrese 0 para salir): ");
        scanf("%d", &number);
        sum += number;
    } while (number != 0);
    printf("Sumatoria total = %d\n", sum);

	return 0;
}
