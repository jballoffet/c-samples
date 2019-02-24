/**
 * \file            main.c
 * \brief           02. Variables y Tipos de Datos - Ejemplo 1
 * \author          Javier Balloffet
 * \date            07-SEP-2018
 * \details         Ver README para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    /* 1. Declaro las variables */
    char myCharacterVariable;
    int myIntegerVariable;
    float myDecimalVariable;
    double myDoublePrecisionDecimalVariable;

    /* 2. Asigno las variables */
    myCharacterVariable = 'J';
    myIntegerVariable = 5;
    myDecimalVariable = 2.5;
    myDoublePrecisionDecimalVariable = 3.14159;

    /* 3. Imprimo el contenido de las variables en pantalla */
    printf("El contenido de myCharacterVariable es %c\n", myCharacterVariable);
    printf("El contenido de myIntegerVariable es %d\n", myIntegerVariable);
    printf("El contenido de myDecimalVariable es %f\n", myDecimalVariable);
    printf("El contenido de myDoublePrecisionDecimalVariable es %lf\n", myDoublePrecisionDecimalVariable);

    /* 4. ¿Cuánto puedo almacenar en cada tipo de variable? */
    printf("Una variable caracter (char) tiene %ld bytes de largo\n", sizeof(char));
    printf("Una variable entera (int) tiene %ld bytes de largo\n", sizeof(int));
    printf("Una variable decimal (float) tiene %ld bytes de largo\n", sizeof(float));
    printf("Una variable decimal de doble precision (double) tiene %ld bytes de largo\n", sizeof(double));

	return 0;
}
