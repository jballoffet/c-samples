/*!
 * @file   main.c
 * @brief  02. Variables y Tipos de Datos - 02. Ingreso por consola
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main(void)
{
    // Puedo declarar varias variables en una misma línea.
    char char_value;
    int int_value1, int_value2;
    float float_value;
    double double_value;

    // Ingreso los valores de las variables por consola.
    printf("Ingrese el valor a almacenar en char_value\n");
    scanf("%c", &char_value);
    printf("Ingrese el valor a almacenar en int_value1\n");
    scanf("%d", &int_value1);
    printf("Ingrese el valor a almacenar en int_value2\n");
    scanf("%d", &int_value2);
    printf("Ingrese el valor a almacenar en myDecimalVariable\n");
    scanf("%f", &float_value);
    printf("Ingrese el valor a almacenar en double_value\n");
    scanf("%lf", &double_value);

    // Imprimo el contenido de las variables en pantalla.
    printf("El contenido de char_value es %c\n", char_value);
    printf("El contenido de int_value1 es %d\n", int_value1);
    printf("El contenido de int_value2 es %d\n", int_value2);
    printf("El contenido de float_value es %f\n", float_value);
    printf("El contenido de double_value es %lf\n", double_value);

    return 0;
}
