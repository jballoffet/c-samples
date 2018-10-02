/**
 * \file            main.c
 * \brief           5. Estructuras de Control - Repetición - Ejemplo 4 - Estructura "do...while"
 * \author          Javier Balloffet
 * \date            02-OCT-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    // 1. No hace falta inicializar el valor de "number" ya que primero asigno y luego pregunto
    int number;
    int suma = 0;

    // 2. Solicito números por consola hasta que se ingrese cero. Calculo la sumatoria total.
    do {
        printf("Ingrese un numero (ingrese 0 para salir): ");
        scanf("%d", &number);
        suma += number;
    } while (number != 0);
    printf("Sumatoria total = %d\n", suma);

	return 0;
}
