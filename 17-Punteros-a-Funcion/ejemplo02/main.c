/*!
 * @file   main.c
 * @brief  17. Punteros a Función - 02. Pasaje de un puntero a función a una
 * función (callbacks)
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 30, 2022
 */
#include <stdio.h>

// Declaro "function1" como una función que recibe un puntero a función.
void function1(void (*function_pointer)(void));

void function2();

int main(void)
{
    // Invoco a la función "function1", pasando como parámetro la dirección de
    // la función "function2" (la cual es recibida en un puntero a función).
    function1(function2);

    return 0;
}

void function1(void (*function_pointer)(void))
{
    printf("La funcion function1 fue invocada\n");
    (*function_pointer)();
}

void function2()
{
    printf("La funcion function2 fue invocada\n");
}
