/**
 * \file            main.c
 * \brief           15. Recursividad - Ejemplo 1 - Función sumatoria
 * \author          Javier Balloffet
 * \date            05-OCT-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int recursive_sum(int num);

int main() {
    int number, sum;

    // 1. Solicito un número por consola
    printf("Ingrese un numero: ");
    scanf("%d", &number);
	
    // 2. Calculo la sumatoria de todos los números desde cero hasta el número ingresado (incluido) usando una funcion recursiva
    sum = recursive_sum(number);
    printf("Sumatoria de 0 a %d = %d\n", number, sum);

	return 0;
}

int recursive_sum(int num) {
    if (num != 0) {
        return num + recursive_sum(num - 1);    // La función se llama a si misma!
    } else {
        return 0;                               // Condición de salida (siempre debe estar!)
    }
}
