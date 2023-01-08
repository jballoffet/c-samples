/*!
 * @file   stack.c
 * @brief  24. Estructuras de Datos - 03. Pilas - 01. Pila usando vectores
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Jan 8, 2023
 */
#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

Stack* stack_create()
{
    Stack* stack = NULL;

    // Solicito memoria para almacenar los datos de la pila.
    stack = (Stack*)malloc(sizeof(Stack));
    if (stack != NULL)
    {
        stack->elements = NULL;
        stack->size = 0;
    }

    return stack;
}

Status stack_push(Stack* stack, Element element)
{
    Element* aux = NULL;

    // Redimensiono la pila.
    aux =
        (Element*)realloc(stack->elements, (stack->size + 1) * sizeof(Element));
    if (aux == NULL)
    {
        return ERROR_MEMORY_FAILURE;
    }
    stack->elements = aux;

    // Agrego el nuevo elemento e incremento el tamaño de la pila.
    stack->elements[stack->size] = element;
    stack->size++;

    return SUCCESS;
}

Status stack_pop(Stack* stack, Element* element)
{
    Element* aux = NULL;

    // Chequeo si la pila está vacía.
    if (stack->size == 0)
    {
        return ERROR_EMPTY_STACK;
    }

    // Retorno por referencia el elemento a remover.
    *element = stack->elements[stack->size - 1];

    // Redimensiono la pila.
    aux =
        (Element*)realloc(stack->elements, (stack->size - 1) * sizeof(Element));
    if (aux == NULL)
    {
        return ERROR_MEMORY_FAILURE;
    }
    stack->elements = aux;

    // Decremento el tamaño de la pila.
    stack->size--;

    return SUCCESS;
}

Status stack_peek(Stack* stack, Element* element)
{
    // Chequeo si la pila está vacía.
    if (stack->size == 0)
    {
        return ERROR_EMPTY_STACK;
    }

    // Retorno por referencia el elemento a obtener.
    *element = stack->elements[stack->size - 1];

    return SUCCESS;
}

void stack_print(Stack* stack)
{
    int i;

    // Imprimo los datos almacenados en la pila.
    printf("Contenido: [");
    for (i = 0; i < stack->size - 1; i++)
    {
        printf("%d, ", stack->elements[i].data);
    }
    printf("%d]\n", stack->elements[i].data);

    // Imprimo el tamaño de la pila.
    printf("Tamanio: %d\n", stack->size);
}

void stack_destroy(Stack* stack)
{
    // Libero la memoria correspondiente a los elementos agregados.
    if (stack->elements != NULL)
    {
        free(stack->elements);
        stack->elements = NULL;
    }

    // Libero la memoria correspondiente a los datos de la pila.
    free(stack);
}
