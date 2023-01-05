/*!
 * @file   stack.c
 * @brief  24. Estructuras de Datos - 03. Pilas - 02. Pila usando listas
 *   enlazadas
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Mar 16, 2019
 */
#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

StackStatus push(StackNode** stack, int value)
{
    // Declaro un puntero a StackNode (StackNode*) para almacenar la direccion
    // de comienzo de la pila.
    StackNode* head = *stack;
    // Declaro un puntero a StackNode (StackNode*) para almacenar la direccion
    // del nuevo nodo.
    StackNode* new_node = NULL;

    // Solicito memoria al SO equivalente a un nodo (StackNode).
    new_node = (StackNode*)malloc(sizeof(StackNode));
    if (new_node == NULL)
    {
        return SS_MEMORY_ERROR;
    }

    // Cargo el nuevo valor en el nodo. Asigno un valor nulo al puntero por
    // ahora.
    new_node->value = value;
    new_node->next = NULL;

    // Se pushea el nuevo nodo. Se pushea y popea al principio, para tener la
    // menor demora.
    *stack = new_node;
    new_node->next = head;

    return SS_SUCCESS;
}

StackStatus pop(StackNode** stack, int* value)
{
    // Declaro un puntero a StackNode (StackNode*) para almacenar la direccion
    // de comienzo de la pila.
    StackNode* head = *stack;

    // Chequeo si la pila está vacía.
    if (head == NULL)
    {
        return SS_EMPTY_STACK;
    }

    // Se popea un nodo. Se popea del principio para demorar lo menos posible.
    // Obtengo el valor almacenado en el nodo.
    *value = head->value;

    // Modifico la dirección de comienzo de la pila a la del próximo nodo.
    *stack = head->next;

    // Libero la memoria solicitada al SO para el nodo que se está popeando.
    free(head);

    return SS_SUCCESS;
}

StackStatus peek(StackNode* stack, int* value)
{
    // Declaro un puntero a StackNode (StackNode*) para almacenar la direccion
    // de comienzo de la pila.
    StackNode* head = stack;

    // Chequeo si la pila está vacía.
    if (head == NULL)
    {
        return SS_EMPTY_STACK;
    }

    // Obtengo el valor almacenado en el nodo.
    *value = head->value;

    return SS_SUCCESS;
}

void free_stack(StackNode** stack)
{
    // Declaro un puntero a StackNode (StackNode*) para almacenar la direccion
    // de comienzo de la pila.
    StackNode* head = *stack;

    // Libero la memoria solicitada al SO nodo a nodo hasta vaciar la pila.
    while (head != NULL)
    {
        *stack = head->next;
        free(head);
        head = *stack;
    }
}

void print_stack(StackNode* stack)
{
    // Declaro un puntero a StackNode (StackNode*) para almacenar la direccion
    // de comienzo de la pila.
    StackNode* head = stack;

    // Imprimo el contenido de la pila nodo a nodo.
    printf("Contenido de la pila: ");
    printf("HEAD --> ");

    while (head != NULL)
    {
        printf("%d --> ", head->value);
        head = head->next;
    }

    printf("NULL\n");
}
