/**
 * \file            main.c
 * \brief           9. Funciones - Argumentos por Referencia - Ejemplo 1 - Incrementar variable
 * \author          Javier Balloffet
 * \date            05-OCT-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

void increment(int* number_pointer);

int main() {
    int number = 1;

    // 1. Invoco a "increment" y muestro el valor de "number" antes y después de llamar a la función
    printf("Valor de \"number\" antes de incrementar = %d\n", number); 
    increment(&number);
    printf("Valor de \"number\" despues de incrementar = %d\n", number); 

	return 0;
}

void increment(int* number_pointer) {
    // 2. Incremento el contenido de lo apuntado por "number_pointer"
    (*number_pointer)++;
}
