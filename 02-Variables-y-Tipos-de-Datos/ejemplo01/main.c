/*!
 * @file   main.c
 * @brief  02. Variables y Tipos de Datos - 01. Declaración de variables
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main(void)
{
    // Declaro las variables.
    char char_value;
    int int_value;
    float float_value;
    double double_value;

    // Asigno las variables.
    char_value = 'J';
    int_value = 5;
    float_value = 2.5;
    double_value = 3.14159;

    // Imprimo el contenido de las variables en pantalla.
    printf("El contenido de char_value es %c\n", char_value);
    printf("El contenido de int_value es %d\n", int_value);
    printf("El contenido de float_value es %f\n", float_value);
    printf("El contenido de double_value es %lf\n", double_value);

    // ¿Cuánta memoria ocupa cada tipo de variable?
    printf("Una variable caracter (char) tiene %ld bytes de largo\n",
           sizeof(char));
    printf("Una variable entera (int) tiene %ld bytes de largo\n", sizeof(int));
    printf("Una variable real (float) tiene %ld bytes de largo\n",
           sizeof(float));
    printf(
        "Una variable real de doble precision (double) tiene %ld bytes de "
        "largo\n",
        sizeof(double));

    return 0;
}
