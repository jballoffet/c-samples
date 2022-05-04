/*!
 * @file   main.c
 * @brief  04. Estructuras de Control - Decisión - 01. Estructura "if"
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main(void)
{
    int number;

    // Solicito un número por consola.
    printf("Ingrese un numero: ");
    scanf("%d", &number);

    // Si el número ingresado es negativo, lo informo por pantalla.
    if (number < 0)
    {
        printf("El numero ingresado es negativo\n");
    }

    return 0;
}
