/**
 * \file            main.c
 * \brief           5. Estructuras de Control - Repetición - Ejemplo 5 - Sentencia "break"
 * \author          Javier Balloffet
 * \date            02-OCT-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    int number, i;
    int sum = 0;

    // 1. Solicito 10 números por consola. Calculo la sumatoria total. Si se ingresa un número negativo, sale del for
    for (i = 0; i < 10; i++) {
        printf("Ingrese un numero: ");
        scanf("%d", &number);

        if (number < 0) {
            break;
        }

        sum += number;
    }
    printf("Sumatoria = %d\n", sum);

	return 0;
}
