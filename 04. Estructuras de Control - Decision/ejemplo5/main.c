/**
 * \file            main.c
 * \brief           04. Estructuras de Control - Decisión - Ejemplo 5 - Estructura "if...else" con condiciones múltiples
 * \author          Javier Balloffet
 * \date            Sep 30, 2018
 * \details         Ver README para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    int number1, number2;
	
    /* 1. Solicito dos números por consola */
    printf("Ingrese un numero: ");
    scanf("%d", &number1);
    printf("Ingrese otro numero: ");
    scanf("%d", &number2);

    /* 2. Informo por pantalla si ambos números ingresados son negativos, positivos o cero */
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
