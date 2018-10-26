/**
 * \file            main.c
 * \brief           7. Funciones - Archivos Header - Ejemplo 1 - Función definida por el usuario
 * \author          Javier Balloffet
 * \date            02-OCT-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include "functions.h"

int main() {
    int number1, number2, sum;

    // 1. Solicito 2 números por consola
    printf("Ingrese un numero: ");
    scanf("%d", &number1);
    printf("Ingrese otro numero: ");
    scanf("%d", &number2);

    // 2. Invoco a la función "add", pasándole "number1" y "number2" como argumentos. Almaceno el valor que retorna la función en la variable "sum"
    sum = add(number1, number2);

    // 3. Imprimo en pantalla el resultado de la suma
    printf("Sumatoria = %d\n", sum);

	return 0;
}
