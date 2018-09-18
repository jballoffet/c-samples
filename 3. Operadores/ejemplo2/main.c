/**
 * \file            main.c
 * \brief           3. Operadores Aritmeticos y Logicos - Ejemplo 2 - Operadores de Incremento y Decremento
 * \author          Javier Balloffet
 * \date            09-SEP-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    // 1. Declaracion de variables
    int operando1 = 9;
    float operando2 = 6.5;

    // 2. Muestro el valor de las variables en pantalla
    printf("operando1 = %d\n", operando1);
    printf("operando2 = %f\n", operando2);

    // 3. Realizo varias operaciones de incremento y decremento e imprimo el resultado en pantalla
    // 3.1. Incremento (++) Prefijo
    printf("++operando1 = %d\n", ++operando1);
    printf("++operando2 = %f\n", ++operando2);
    
    // 3.2. Decremento (--) Prefijo
    printf("--operando1 = %d\n", --operando1);
    printf("--operando2 = %f\n", --operando2);

    // 3.3. Incremento (++) Postfijo
    printf("operando1++ = %d\n", operando1++);
    printf("operando2++ = %f\n", operando2++);
    
    // 3.4. Decremento (--) Postfijo
    printf("operando1-- = %d\n", operando1--);
    printf("operando2-- = %f\n", operando2--);

    // 4. Muestro valor final
    printf("operando1 = %d\n", operando1);
    printf("operando2 = %f\n", operando2);

	return 0;
}
