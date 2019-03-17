/**
 * \file            stack.c
 * \brief           23. Pilas - Ejemplo 1 - Implementación sencilla de una pila
 * \author          Javier Balloffet
 * \date            16-MAR-2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

StackStatus push(StackNode** stack, int value) {
    /* 1. Declaro un puntero a StackNode (StackNode*) para almacenar la direccion de comienzo de la pila */
    StackNode* head = *stack;
    /* 2. Declaro un puntero a StackNode (StackNode*) para almacenar la direccion del nuevo nodo */
    StackNode* new_node = NULL;

    /* 3. Solicito memoria al SO equivalente a un nodo (StackNode) */
    new_node = (StackNode*) malloc(sizeof(StackNode));
    if (new_node == NULL) {
        printf("Error! Memoria no asignada.\n");
        return SS_MEMORY_ERROR;
    }

    /* 4. Cargo el nuevo valor en el nodo. Asigno un valor nulo al puntero por ahora */
    new_node->value = value;
    new_node->next = NULL;

    /* 5. Se pushea el nuevo nodo. Se pushea y popea al principio, para tener la menor demora */
    *stack = new_node;
    new_node->next = head;

    return SS_SUCCESS;
}

StackStatus pop(StackNode** stack, int* value) {
    /* 1. Declaro un puntero a StackNode (StackNode*) para almacenar la direccion de comienzo de la pila */
    StackNode* head = *stack;

    /* 2. Chequeo si la pila está vacía */
    if (head == NULL) {
        printf("Error! La pila esta vacia.\n");
        return SS_EMPTY_STACK;
    }

    /* 3. Se popea un nodo. Se popea del principio para demorar lo menos posible */
    /* 4. Obtengo el valor almacenado en el nodo */
    *value = head->value;

    /* 5. Modifico la dirección de comienzo de la pila a la del próximo nodo */
    *stack = head->next;

    /* 6. Libero la memoria solicitada al SO para el nodo que se está popeando */
    free(head);

    return SS_SUCCESS;
}

StackStatus peek(StackNode* stack, int* value) {
    /* 1. Declaro un puntero a StackNode (StackNode*) para almacenar la direccion de comienzo de la pila */
    StackNode* head = stack;

    /* 2. Chequeo si la pila está vacía */
    if (head == NULL) {
        printf("Error! La pila esta vacia.\n");
        return SS_EMPTY_STACK;
    }

    /* 3. Obtengo el valor almacenado en el nodo */
    *value = head->value;

    return SS_SUCCESS;
}

void free_stack(StackNode** stack) {
    /* 1. Declaro un puntero a StackNode (StackNode*) para almacenar la direccion de comienzo de la pila */
    StackNode* head = *stack;

    /* 2. Libero la memoria solicitada al SO nodo a nodo hasta vaciar la pila */
    while (head != NULL) {
        *stack = head->next;
        free(head);
        head = *stack;
    }
}

void print_stack(StackNode* stack) {
    /* 1. Declaro un puntero a StackNode (StackNode*) para almacenar la direccion de comienzo de la pila */
    StackNode* head = stack;

    /* 2. Imprimo el contenido de la pila nodo a nodo */
    printf("Contenido de la pila: ");
    printf("HEAD --> ");

    while (head != NULL) {
        printf("%d --> ", head->value);
        head = head->next;
    }

    printf("NULL\n");
}
