/*!
 * @file   functions.c
 * @brief  07. Funciones - Archivos Header - 02. Funciones 'static'
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include "functions.h"

#include <stdio.h>

// Declaración o prototipo de la funcion 'static' "print".
static void print(int a);

int add(int a, int b)
{
    int result;
    result = a + b;
    print(result);
    return result;
}

// Definición de la funcion 'static' "print".
static void print(int a)
{
    // Recibo "a" como argumento de la función.
    printf("[Print] = %d\n", a);
}
