/**
 * \file            main.c
 * \brief           3. Operadores Aritmeticos y Logicos - Ejemplo 1 - Operadores Aritmeticos
 * \author          Javier Balloffet
 * \date            09-SEP-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    // 1. Declaracion de variables
    int operando1 = 9, operando2 = 6, resultadoEntero;
    float resultadoReal;

    // 2. Muestro el valor de las variables en pantalla
    printf("operando1 = %d\n", operando1);
    printf("operando2 = %d\n", operando2);

    // 3. Realizo varias operaciones aritmeticas e imprimo el resultado en pantalla
    // 3.1. Suma (+)
    resultadoEntero = operando1 + operando2;
    printf("operando1 + operando2 = %d\n", resultadoEntero);
    
    // 3.2. Resta (-)
    resultadoEntero = operando1 - operando2;
    printf("operando1 - operando2 = %d\n", resultadoEntero);

    // 3.3. Multiplicacion (*)
    resultadoEntero = operando1 * operando2;
    printf("operando1 * operando2 = %d\n", resultadoEntero);

    // 3.4. Division (/)
    resultadoEntero = operando1 / operando2;
    printf("operando1 / operando2 = %d\n", resultadoEntero);

    // 3.5. Resto (%) - Nota: Sólo puede usarse con variables enteras!  
    resultadoEntero = operando1 % operando2;
    printf("El resto resultante de la division de operando1 sobre operando2 = %d\n", resultadoEntero);

    /* 4. ¿Y si quiero el resultado como un numero real? Debo castear! 
          Nota: Castear antes de realizar la operacion! */
    // 4.1. Asi no!
    resultadoReal = (float) (operando1 / operando2);
    printf("El resultado real (erroneo) de la division es: %f\n", resultadoReal);
    
    // 4.2. Asi si!
    resultadoReal = ((float) operando1) / operando2;
    printf("El resultado real (correcto) de la division es: %f\n", resultadoReal);

	return 0;
}
