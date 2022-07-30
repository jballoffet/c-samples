/*!
 * @file   queue.c
 * @brief  24. Estructuras de Datos - 04. Colas
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Mar 16, 2019
 */
#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

QueueStatus enqueue(QueueNode** queue, int value)
{
    // Declaro un puntero a QueueNode (QueueNode*) para almacenar la direccion
    // de comienzo de la cola.
    QueueNode* head = *queue;
    // Declaro un puntero a QueueNode (QueueNode*) para almacenar la direccion
    // del nuevo nodo.
    QueueNode* new_node = NULL;

    // Solicito memoria al SO equivalente a un nodo (QueueNode).
    new_node = (QueueNode*)malloc(sizeof(QueueNode));
    if (new_node == NULL)
    {
        return QS_MEMORY_ERROR;
    }

    // Cargo el nuevo valor en el nodo. Asigno un valor nulo al puntero por
    // ahora.
    new_node->value = value;
    new_node->next = NULL;

    // Se encola el nuevo nodo. Se encola al final, para que la menor demora sea
    // al desencolar.
    // Chequeo si la cola esta vacía.
    if (head == NULL)
    {
        // ¡La cola está vacía! Agrego el nuevo nodo.
        *queue = new_node;
    }
    else
    {
        // ¡La cola no está vacía! La recorro hasta encontrar el final.
        while (head->next != NULL)
        {
            head = head->next;
        }

        // Encontré el último nodo. Lo hago apuntar al nuevo nodo.
        head->next = new_node;
    }

    return QS_SUCCESS;
}

QueueStatus dequeue(QueueNode** queue, int* value)
{
    // Declaro un puntero a QueueNode (QueueNode*) para almacenar la direccion
    // de comienzo de la cola.
    QueueNode* head = *queue;

    // Chequeo si la cola esta vacía.
    if (head == NULL)
    {
        return QS_EMPTY_QUEUE;
    }

    // Se desencola un nodo. Se desencola del principio para demorar lo menos
    // posible.
    // Obtengo el valor almacenado en el nodo.
    *value = head->value;

    // Modifico la dirección de comienzo de la cola a la del próximo nodo.
    *queue = head->next;

    // Libero la memoria solicitada al SO para el nodo que se está desencolando.
    free(head);

    return QS_SUCCESS;
}

QueueStatus peek(QueueNode* queue, int* value)
{
    // Declaro un puntero a QueueNode (QueueNode*) para almacenar la direccion
    // de comienzo de la cola.
    QueueNode* head = queue;

    // Chequeo si la cola esta vacía.
    if (head == NULL)
    {
        return QS_EMPTY_QUEUE;
    }

    // Obtengo el valor almacenado en el nodo.
    *value = head->value;

    return QS_SUCCESS;
}

void free_queue(QueueNode** queue)
{
    // Declaro un puntero a QueueNode (QueueNode*) para almacenar la direccion
    // de comienzo de la cola.
    QueueNode* head = *queue;

    // Libero la memoria solicitada al SO nodo a nodo hasta vaciar la cola.
    while (head != NULL)
    {
        *queue = head->next;
        free(head);
        head = *queue;
    }
}

void print_queue(QueueNode* queue)
{
    // Declaro un puntero a QueueNode (QueueNode*) para almacenar la direccion
    // de comienzo de la cola.
    QueueNode* head = queue;

    // Imprimo el contenido de la cola nodo a nodo.
    printf("Contenido de la cola: ");
    printf("HEAD --> ");

    while (head != NULL)
    {
        printf("%d --> ", head->value);
        head = head->next;
    }

    printf("NULL\n");
}
