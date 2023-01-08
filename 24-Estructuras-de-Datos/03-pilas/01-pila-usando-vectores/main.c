/*!
 * @file   main.c
 * @brief  24. Estructuras de Datos - 03. Pilas - 01. Pila usando vectores
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Jan 8, 2023
 */
#include <stdio.h>

#include "stack.h"

int main(void)
{
    Stack* stack = NULL;
    Element element;
    int i;

    // Creo una pila como un tipo de dato abstracto.
    stack = stack_create();
    if (stack == NULL)
    {
        printf("Error! Pila no creada.\n");
        return -1;
    }

    // Pusheo los números del 1 al 5.
    for (i = 1; i <= 5; i++)
    {
        element.data = i;
        if (stack_push(stack, element) != SUCCESS)
        {
            printf("Error! Memoria no asignada.\n");
            return -1;
        }
        stack_print(stack);
    }

    // Popeo un nodo.
    if (stack_pop(stack, &element) == SUCCESS)
    {
        printf("Valor obtenido (popeado): %d\n", element.data);
    }
    else
    {
        printf("Error! La pila esta vacia.\n");
    }
    stack_print(stack);

    // Observo el valor del próximo nodo a popear (sin popearlo).
    if (stack_peek(stack, &element) == SUCCESS)
    {
        printf("Valor obtenido (sin popear): %d\n", element.data);
    }
    else
    {
        printf("Error! La pila esta vacia.\n");
    }
    stack_print(stack);

    // Popeo un nodo.
    if (stack_pop(stack, &element) == SUCCESS)
    {
        printf("Valor obtenido (popeado): %d\n", element.data);
    }
    else
    {
        printf("Error! La pila esta vacia.\n");
    }
    stack_print(stack);

    // Destruyo la pila.
    stack_destroy(stack);

    return 0;
}
