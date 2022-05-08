/*!
 * @file   main.c
 * @brief  07. Funciones - Archivos Header - 03. Variables globales y globales
 * (al módulo)
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

#include "functions.h"

// Declaro la variable "number2" como global (al módulo main).
static int number2 = 10;

int main(void)
{
    // Invoco a "increment" y muestro el valor de "number1" antes y después de
    // llamar a la función.
    printf("Valor de \"number1\" en main() antes de incrementar = %d\n",
           number1);
    increment();
    printf("Valor de \"number1\" en main() despues de incrementar = %d\n",
           number1);
    number1++;
    printf(
        "Valor de \"number1\" en main() despues de incrementar nuevamente = "
        "%d\n",
        number1);

    // Muestro el valor de "number2" antes y después de incrementar.
    printf("Valor de \"number2\" en main() antes de incrementar = %d\n",
           number2);
    number2++;
    printf("Valor de \"number2\" en main() despues de incrementar = %d\n",
           number2);

    return 0;
}
