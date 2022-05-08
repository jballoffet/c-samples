/*!
 * @file   functions.c
 * @brief  07. Funciones - Archivos Header - 03. Variables globales
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include "functions.h"

#include <stdio.h>

// Declaro la variable "number" como global.
int number = 1;

void increment()
{
    // Muestro el valor de "number" antes y después de incrementar.
    printf("Valor de \"number\" en increment() antes de incrementar = %d\n",
           number);
    number++;
    printf("Valor de \"number\" en increment() despues de incrementar = %d\n",
           number);
}
