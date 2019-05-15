/**
 * \file            main.c
 * \brief           03. Operadores - Ejemplo 1 - Operadores Aritmeticos
 * \author          Javier Balloffet
 * \date            Sep 9, 2018
 * \details         Ver README para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    /* 1. Declaracion de variables */
    int a = 9, b = 6, c;
    float d;

    /* 2. Muestro el valor de las variables en pantalla */
    printf("Operadores:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    /* 3. Realizo varias operaciones aritmeticas e imprimo el resultado en pantalla */
    printf("Operaciones aritmeticas:\n");

    /* 3.1. Suma (+) */
    c = a + b;
    printf("a + b = %d\n", c);
    
    /* 3.2. Resta (-) */
    c = a - b;
    printf("a - b = %d\n", c);

    /* 3.3. Multiplicacion (*) */
    c = a * b;
    printf("a * b = %d\n", c);

    /* 3.4. Division (/) */
    c = a / b;
    printf("a / b = %d\n", c);

    /* 3.5. Resto (%) - Nota: Sólo puede usarse con variables enteras! */
    c = a % b;
    printf("Resto de a / b = %d\n", c);

    /* 4. ¿Y si quiero el resultado como un numero decimal? Debo castear! 
          Nota: Castear antes de realizar la operacion! */
    /* 4.1. Asi no! */
    d = (float) (a / b);
    printf("El resultado decimal (erroneo) de la division es: %f\n", d);
    
    /* 4.2. Asi si! */
    d = ((float) a) / b;
    printf("El resultado real (correcto) de la division es: %f\n", d);

    return 0;
}
