/**
 * \file            stack.h
 * \brief           23. Pilas - Ejemplo 2 - Implementación sencilla de una pila (2)
 * \author          Javier Balloffet
 * \date            Mar 16, 2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#ifndef STACK_H_
#define STACK_H_

typedef struct StackNode {
    int value;
    struct StackNode* next;
} StackNode;

typedef enum {
    SS_SUCCESS = 0,
    SS_MEMORY_ERROR,
    SS_EMPTY_STACK
} StackStatus;

StackStatus push(StackNode** stack, int value);
StackStatus pop(StackNode** stack, int* value);
StackStatus peek(StackNode* stack, int* value);
void free_stack(StackNode** stack);
void print_stack(StackNode* stack);

#endif /* STACK_H_ */
