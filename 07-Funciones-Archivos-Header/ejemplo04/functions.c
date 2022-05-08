/*!
 * @file   functions.c
 * @brief  07. Funciones - Archivos Header - 04. Variables globales y globales
 * (al módulo)
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include "functions.h"

#include <stdio.h>

// Declaro la variable "number1" como global.
int number1 = 1;

// Declaro la variable "number2" como global (al módulo functions).
static int number2 = 5;

void increment()
{
    // Muestro el valor de "number1" antes y después de incrementar.
    printf("Valor de \"number1\" en increment() antes de incrementar = %d\n",
           number1);
    number1++;
    printf("Valor de \"number1\" en increment() despues de incrementar = %d\n",
           number1);

    // Muestro el valor de "number2" antes y después de incrementar.
    printf("Valor de \"number2\" en increment() antes de incrementar = %d\n",
           number2);
    number2++;
    printf("Valor de \"number2\" en increment() despues de incrementar = %d\n",
           number2);
}
