/*!
 * @file   main.c
 * @brief  02. Variables y Tipos de Datos - 07. Tamaño de una variable
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main(void)
{
    // Declaro distintos tipos de variables.
    char char_value;
    int int_value1;
    short int int_value2;  // Nota: "short int" es igual a escribir "short".
    long int int_value3;   // Nota: "long int" es igual a escribir "long".
    long long int
        int_value4;  // Nota: "long long int" es igual a escribir "long long".
    float float_value;
    double double_value1;
    long double double_value2;

    // ¿Cuánto puedo almacenar en cada tipo de variable?
    printf("Variables enteras:\n");
    printf("-> sizeof(char) = %ld bytes\n", sizeof(char_value));
    printf("-> sizeof(int) = %ld bytes\n", sizeof(int_value1));
    printf("-> sizeof(short int) = %ld bytes\n", sizeof(int_value2));
    printf("-> sizeof(long int) = %ld bytes\n", sizeof(int_value3));
    printf("-> sizeof(long long int) = %ld bytes\n", sizeof(int_value4));

    printf("Variables reales:\n");
    printf("-> sizeof(float) = %ld bytes\n", sizeof(float_value));
    printf("-> sizeof(double) = %ld bytes\n", sizeof(double_value1));
    printf("-> sizeof(long double) = %ld bytes\n", sizeof(double_value2));

    return 0;
}
