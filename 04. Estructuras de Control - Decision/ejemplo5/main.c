/**
 * \file            main.c
 * \brief           4. Estructuras de Control - Decisión - Ejemplo 5 - Estructura "if...else" con condiciones multiples
 * \author          Javier Balloffet
 * \date            30-SEP-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    int number1, number2;
	
    // 1. Solicito dos números por consola
    printf("Ingrese un numero: ");
    scanf("%d", &number1);
    printf("Ingrese otro numero: ");
    scanf("%d", &number2);

    // 2. Informo por pantalla si ambos numeros ingresados son negativos, positivos o cero
    if ((number1 > 0) && (number2 > 0)) {
        printf("Ambos numeros ingresados son positivos\n");
    } else if ((number1 < 0) && (number2 < 0)) {
        printf("Ambos numeros ingresados son negativos\n");
    } else if ((number1 == 0) && (number2 == 0)) {
        printf("Ambos numeros ingresados son cero\n");
    } else {
        if ((number1 > 0) || (number2 > 0)) {
            printf("Uno de los numeros ingresados es positivo\n");
        }
        if ((number1 < 0) || (number2 < 0)) {
            printf("Uno de los numeros ingresados es negativo\n");
        }
        if ((number1 == 0) || (number2 == 0)) {
            printf("Uno de los numeros ingresados es cero\n");
        }
    }

	return 0;
}
