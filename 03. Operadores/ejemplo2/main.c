/**
 * \file            main.c
 * \brief           03. Operadores - Ejemplo 2 - Operadores de Incremento y Decremento
 * \author          Javier Balloffet
 * \date            Sep 9, 2018
 * \details         Ver README para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    /* 1. Declaración de variables */
    int a = 9;
    float b = 6.5;

    /* 2. Muestro el valor de las variables en pantalla */
    printf("a = %d\n", a);
    printf("b = %f\n", b);

    /* 3. Realizo varias operaciones de incremento y decremento e imprimo el resultado en pantalla */
    /* 3.1. Incremento (++) Prefijo */
    printf("++a = %d\n", ++a);
    printf("++b = %f\n", ++b);
    
    /* 3.2. Decremento (--) Prefijo */
    printf("--a = %d\n", --a);
    printf("--b = %f\n", --b);

    /* 3.3. Incremento (++) Postfijo */
    printf("a++ = %d\n", a++);
    printf("b++ = %f\n", b++);
    
    /* 3.4. Decremento (--) Postfijo */
    printf("a-- = %d\n", a--);
    printf("b-- = %f\n", b--);

    /* 4. Muestro valor final */
    printf("a = %d\n", a);
    printf("b = %f\n", b);

	return 0;
}
