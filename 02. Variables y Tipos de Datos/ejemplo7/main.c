/**
 * \file            main.c
 * \brief           02. Variables y Tipos de Datos - Ejemplo 7 - Tamaño de una variable
 * \author          Javier Balloffet
 * \date            Sep 7, 2018
 * \details         Ver README para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    /* 1. Declaro variables signadas */
    char myCharacterVariable;
    int myIntegerVariable1;
    short int myIntegerVariable2;       /* Nota: "short int" es igual a escribir "short" */
    long int myIntegerVariable3;        /* Nota: "long int" es igual a escribir "long" */
    long long int myIntegerVariable4;   /* Nota: "long long int" es igual a escribir "long long" */

    /* 2. Declaro variables no signadas */
    unsigned char myUnsignedCharacterVariable;
    unsigned int myUnsignedIntegerVariable1;
    unsigned short int myUnsignedIntegerVariable2;
    unsigned long int myUnsignedIntegerVariable3;
    unsigned long long int myUnsignedIntegerVariable4;

    /* 3. Declaro variables decimales */
    float myDecimalVariable;
    double myDoublePrecisionDecimalVariable1;
    long double myDoublePrecisionDecimalVariable2;

    /* 4. ¿Cuánto puedo almacenar en cada tipo de variable? */
    printf("Variables signadas:\n");
    printf("-> sizeof(char) = %ld bytes\n", sizeof(myCharacterVariable));
    printf("-> sizeof(int) = %ld bytes\n", sizeof(myIntegerVariable1));
    printf("-> sizeof(short int) = %ld bytes\n", sizeof(myIntegerVariable2));
    printf("-> sizeof(long int) = %ld bytes\n", sizeof(myIntegerVariable3));
    printf("-> sizeof(long long int) = %ld bytes\n", sizeof(myIntegerVariable4));

    printf("Variables no signadas:\n");
    printf("-> sizeof(unsigned char) = %ld bytes\n", sizeof(myUnsignedCharacterVariable));
    printf("-> sizeof(unsigned int) = %ld bytes\n", sizeof(myUnsignedIntegerVariable1));
    printf("-> sizeof(unsigned short int) = %ld bytes\n", sizeof(myUnsignedIntegerVariable2));
    printf("-> sizeof(unsigned long int) = %ld bytes\n", sizeof(myUnsignedIntegerVariable3));
    printf("-> sizeof(unsigned long long int) = %ld bytes\n", sizeof(myUnsignedIntegerVariable4));

    printf("Variables decimales:\n");
    printf("-> sizeof(float) = %ld bytes\n", sizeof(myDecimalVariable));
    printf("-> sizeof(double) = %ld bytes\n", sizeof(myDoublePrecisionDecimalVariable1));
    printf("-> sizeof(long double) = %ld bytes\n", sizeof(myDoublePrecisionDecimalVariable2));

	return 0;
}
