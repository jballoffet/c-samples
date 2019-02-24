/**
 * \file            main.c
 * \brief           06. Funciones - Argumentos por Valor - Ejemplo 7 - Una solución a increment()
 * \author          Javier Balloffet
 * \date            04-OCT-2018
 * \details         Ver README para compilar, linkear y ejecutar
 */

#include <stdio.h>

int increment(int a);

int main() {
    int number = 1;

    /* 1. Invoco a "increment" y muestro el valor de "number" antes y después de llamar a la función */
    printf("Valor de \"number\" en main() antes de incrementar = %d\n", number); 
    number = increment(number);
    printf("Valor de \"number\" en main() despues de incrementar = %d\n", number); 

	return 0;
}

int increment(int a) {
    return ++a;
}
