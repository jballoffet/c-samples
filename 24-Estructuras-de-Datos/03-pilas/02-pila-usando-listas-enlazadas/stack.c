/*!
 * @file   stack.c
 * @brief  24. Estructuras de Datos - 03. Pilas - 02. Pila usando listas
 *   enlazadas
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
        stack->head = NULL;
    }

    return stack;
}

Status stack_push(Stack* stack, Element element)
{
    Node* head = stack->head;
    Node* node = NULL;

    // Solicito memoria para el nuevo nodo.
    node = (Node*)malloc(sizeof(Node));
    if (node == NULL)
    {
        return ERROR_MEMORY_FAILURE;
    }

    // Inicializo el nuevo nodo.
    node->element = element;
    node->next = NULL;

    // Hago que el nuevo nodo apunte al principio de la pila.
    node->next = head;

    // Actualizo la dirección de comienzo de la pila.
    stack->head = node;

    return SUCCESS;
}

Status stack_pop(Stack* stack, Element* element)
{
    Node* head = stack->head;

    // Chequeo si la pila está vacía.
    if (head == NULL)
    {
        return ERROR_EMPTY_STACK;
    }

    // Retorno por referencia el valor almacenado en el nodo.
    *element = head->element;

    // Modifico la dirección de comienzo de la lista a la del próximo nodo.
    stack->head = head->next;

    // Libero la memoria correspondiente al nodo siendo removido.
    free(head);

    return SUCCESS;
}

Status stack_peek(Stack* stack, Element* element)
{
    Node* head = stack->head;

    // Chequeo si la pila está vacía.
    if (head == NULL)
    {
        return ERROR_EMPTY_STACK;
    }

    // Retorno por referencia el valor almacenado en el nodo.
    *element = head->element;

    return SUCCESS;
}

void stack_print(Stack* stack)
{
    Node* head = stack->head;

    // Imprimo el contenido de la pila nodo a nodo.
    printf("Contenido de la pila: ");
    printf("HEAD --> ");

    while (head != NULL)
    {
        printf("%d --> ", head->element.data);
        head = head->next;
    }

    printf("NULL\n");
}

void stack_destroy(Stack* stack)
{
    Node* head = stack->head;

    // Libero la memoria solicitada nodo a nodo hasta vaciar la lista.
    while (head != NULL)
    {
        stack->head = head->next;
        free(head);
        head = stack->head;
    }

    free(stack);
}
