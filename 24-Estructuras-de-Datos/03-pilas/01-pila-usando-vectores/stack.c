/*!
 * @file   stack.c
 * @brief  24. Estructuras de Datos - 03. Pilas - 01. Pila usando vectores
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Jan 8, 2023
 */
#include "stack.h"

#include <stdio.h>

Stack* stack_create()
{
    Stack* stack = NULL;
    return stack;
}

Status stack_push(Stack* stack, Element element)
{
    return SUCCESS;
}

Status stack_pop(Stack* stack, Element* element)
{
    return SUCCESS;
}

Status stack_peek(Stack* stack, Element* element)
{
    return SUCCESS;
}

void stack_print(Stack* stack) {}

void stack_destroy(Stack* stack) {}
