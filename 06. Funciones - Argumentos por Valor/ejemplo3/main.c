/**
 * \file            main.c
 * \brief           6. Funciones - Argumentos por Valor - Ejemplo 3 - Variables locales
 * \author          Javier Balloffet
 * \date            04-OCT-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

void display();

int main() {
    // 1. Declaro una variable "number" local a la funcion main
    int number = 1;

    // 2. Invoco a "display" y muestro el valor de "number" después de llamar a la función
    display();
    printf("Valor de \"number\" en la función main = %d\n", number); 

	return 0;
}

void display() {
    // 3. Declaro una variable "number" local a la funcion display
    int number = 2;
    printf("Valor de \"number\" en la función display = %d\n", number);
}
