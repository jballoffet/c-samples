/*!
 * @file   stack.c
 * @brief  24. Estructuras de Datos - 03. Pilas - 01. Pila usando vectores
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Jan 4, 2023
 */
#include "stack.h"

#include <stdio.h>

Stack* stack_create()
{
    Stack* stack = NULL;
    return stack;
}

Status stack_push(Stack* pila, Element element)
{
    return SUCCESS;
}

Status stack_pop(Stack* pila, Element* element)
{
    return SUCCESS;
}

Status stack_peek(Stack* pila, Element* element)
{
    return SUCCESS;
}

void stack_print(Stack* pila) {}

void stack_destroy(Stack* pila) {}
