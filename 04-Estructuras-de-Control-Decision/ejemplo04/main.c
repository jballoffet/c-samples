/*!
 * @file   main.c
 * @brief  04. Estructuras de Control - Decisión - 04. Estructura "else-if"
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

    // Informo por pantalla si el número ingresado es negativo, positivo o cero.
    if (number < 0)
    {
        printf("El numero ingresado es negativo\n");
    }
    else if (number > 0)
    {
        printf("El numero ingresado es positivo\n");
    }
    else
    {
        printf("El numero ingresado es cero\n");
    }

    return 0;
}
