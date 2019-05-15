/**
 * \file            main.c
 * \brief           15. Recursividad - Ejemplo 2 - Función factorial
 * \author          Javier Balloffet
 * \date            Oct 5, 2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int recursive_factorial(int num);

int main() {
    int number, factorial;

    /* 1. Solicito un número por consola */
    printf("Ingrese un numero: ");
    scanf("%d", &number);
	
    /* 2. Calculo el factorial del número ingresado, usando una funcion recursiva */
    factorial = recursive_factorial(number);
    printf("Factorial de %d = %d\n", number, factorial);

	return 0;
}

int recursive_factorial(int num) {
    if (num > 0) {
        return num * recursive_factorial(num - 1);  /* La función se llama a si misma! */
    } else {
        return 1;                                   /* Condición de salida (siempre debe estar!) */
    }
}
