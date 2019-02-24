/**
 * \file            main.c
 * \brief           06. Funciones - Argumentos por Valor - Ejemplo 6 - Variables estáticas
 * \author          Javier Balloffet
 * \date            04-OCT-2018
 * \details         Ver README para compilar, linkear y ejecutar
 */

#include <stdio.h>

void increment1();
void increment2();

int main() {
    /* 1. Invoco a "increment1" dos veces seguidas */
    increment1();
    increment1();

    /* 2. Invoco a "increment2" dos veces seguidas */
    increment2();
    increment2(); 

	return 0;
}

void increment1() {
    /* 3. Declaro la variable "number" */
    int number = 1;

    /* 4. Muestro el valor de "number" antes y después de incrementar */
    printf("Valor de \"number\" en increment1() antes de incrementar = %d\n", number);
    number++;
    printf("Valor de \"number\" en increment1() despues de incrementar = %d\n", number); 
}

void increment2() {
    /* 5. Declaro la variable "number" como estática */
    static int number = 1;

    /* 6. Muestro el valor de "number" antes y después de incrementar */
    printf("Valor de \"number\" en increment2() antes de incrementar = %d\n", number);
    number++;
    printf("Valor de \"number\" en increment2() despues de incrementar = %d\n", number); 
}
