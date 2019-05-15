/**
 * \file            main.c
 * \brief           06. Funciones - Argumentos por Valor - Ejemplo 1 - Función definida por el usuario
 * \author          Javier Balloffet
 * \date            Oct 2, 2018
 * \details         Ver README para compilar, linkear y ejecutar
 */

#include <stdio.h>

/* Declaración de la función "add". También se le conoce como "prototipo" */
int add(int a, int b);

int main() {
    int number1, number2, sum;

    /* 1. Solicito 2 números por consola */
    printf("Ingrese un numero: ");
    scanf("%d", &number1);
    printf("Ingrese otro numero: ");
    scanf("%d", &number2);

    /* 2. Invoco a la función "add", pasándole "number1" y "number2" como argumentos. 
        Almaceno el valor que retorna la función en la variable "sum" */
    sum = add(number1, number2);

    /* 3. Imprimo en pantalla el resultado de la suma */
    printf("Sumatoria = %d\n", sum);

	return 0;
}

/* Definicion de la funcion "add" */
int add(int a, int b) {
    /* Recibo "a" y "b" como parámetros de la función y retorno el contenido de "result" */
    int result;
    result = a + b;
    return result;
}
