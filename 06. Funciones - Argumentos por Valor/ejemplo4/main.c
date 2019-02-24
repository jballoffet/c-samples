/**
 * \file            main.c
 * \brief           06. Funciones - Argumentos por Valor - Ejemplo 4 - Variables globales
 * \author          Javier Balloffet
 * \date            04-OCT-2018
 * \details         Ver README para compilar, linkear y ejecutar
 */

#include <stdio.h>

/* 1. Declaro la variable "number" como global */
int number = 1;

void display();

int main() {
    /* 2. Invoco a "display" y luego incremento "number" y muestro su valor */
    display();
    number++;
    printf("Valor de \"number\" en la función main = %d\n", number); 

	return 0;
}

void display() {
    /* 3. Incremento "number" y muestro su valor */
    number++;
    printf("Valor de \"number\" en la función display = %d\n", number);
}
