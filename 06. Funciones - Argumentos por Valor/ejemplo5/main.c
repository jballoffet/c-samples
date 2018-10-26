/**
 * \file            main.c
 * \brief           6. Funciones - Argumentos por Valor - Ejemplo 5 - Variables estáticas
 * \author          Javier Balloffet
 * \date            04-OCT-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

void display();

int main() {
    // 1. Invoco a "display" dos veces seguidas
    display();
    display(); 

	return 0;
}

void display() {
    // 2. Declaro la variable "number" como estática, muestro su valor y la incremento
    static int number = 1;
    printf("Valor de \"number\" en la función display = %d\n", number);
    number++;
}
