/*!
 * @file   main.c
 * @brief  24. Estructuras de Datos - 03. Pilas
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Mar 16, 2019
 */
#include <stdio.h>

#include "stack.h"

int main(void)
{
    // Declaro una Pila (Stack). La misma es un puntero al primer nodo.
    StackNode* stack = NULL;
    int i, value;

    // Pusheo los números del 1 al 5.
    for (i = 1; i <= 5; i++)
    {
        if (push(&stack, i) != SS_SUCCESS)
        {
            printf("Error! Memoria no asignada.\n");
            return -1;
        }
        print_stack(stack);
    }

    // Popeo un nodo.
    if (pop(&stack, &value) == SS_SUCCESS)
    {
        printf("Valor obtenido (popeado): %d\n", value);
    }
    else
    {
        printf("Error! La pila esta vacia.\n");
    }
    print_stack(stack);

    // Observo el valor del próximo nodo a popear (sin popearlo).
    if (peek(stack, &value) == SS_SUCCESS)
    {
        printf("Valor obtenido (sin popear): %d\n", value);
    }
    else
    {
        printf("Error! La pila esta vacia.\n");
    }
    print_stack(stack);

    // Popeo un nodo.
    if (pop(&stack, &value) == SS_SUCCESS)
    {
        printf("Valor obtenido (popeado): %d\n", value);
    }
    else
    {
        printf("Error! La pila esta vacia.\n");
    }
    print_stack(stack);

    // Libero la memoria de la pila completa.
    free_stack(&stack);
    print_stack(stack);

    // Intento popear de una pila vacía.
    if (pop(&stack, &value) == SS_SUCCESS)
    {
        printf("Valor obtenido (popeado): %d\n", value);
    }
    else
    {
        printf("Error! La pila esta vacia.\n");
    }
    print_stack(stack);

    return 0;
}
