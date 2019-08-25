/**
 * \file            main.c
 * \brief           02. Variables y Tipos de Datos - Ejemplo 2 - Ingreso por consola
 * \author          Javier Balloffet
 * \date            Sep 7, 2018
 * \details         Ver README para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    /* 1. Puedo declarar varias variables en una misma linea */
    char myCharacterVariable;
    int myIntegerVariable1, myIntegerVariable2;
    float myDecimalVariable;
    double myDoublePrecisionDecimalVariable;

    /* 2. Ingreso los valores de las variables por consola */
    printf("Ingrese el valor a almacenar en myCharacterVariable1\n");
    scanf("%c", &myCharacterVariable);
    printf("Ingrese el valor a almacenar en myIntegerVariable1\n");
    scanf("%d", &myIntegerVariable1);
    printf("Ingrese el valor a almacenar en myIntegerVariable2\n");
    scanf("%d", &myIntegerVariable2);
    printf("Ingrese el valor a almacenar en myDecimalVariable\n");
    scanf("%f", &myDecimalVariable);
    printf("Ingrese el valor a almacenar en myDoublePrecisionDecimalVariable\n");
    scanf("%lf", &myDoublePrecisionDecimalVariable);

    /* 3. Imprimo el contenido de las variables en pantalla */
    printf("El contenido de myCharacterVariable1 es %c\n", myCharacterVariable);
    printf("El contenido de myIntegerVariable1 es %d\n", myIntegerVariable1);
    printf("El contenido de myIntegerVariable2 es %d\n", myIntegerVariable2);
    printf("El contenido de myDecimalVariable es %f\n", myDecimalVariable);
    printf("El contenido de myDoublePrecisionDecimalVariable es %lf\n", myDoublePrecisionDecimalVariable);

	return 0;
}
