/*!
 * @file   queue.c
 * @brief  24. Estructuras de Datos - 04. Colas - 02. Cola usando listas
 *   enlazadas
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Jan 8, 2023
 */
#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

Queue* queue_create()
{
    Queue* queue = NULL;

    // Solicito memoria para almacenar los datos de la cola.
    queue = (Queue*)malloc(sizeof(Queue));
    if (queue != NULL)
    {
        queue->head = NULL;
    }

    return queue;
}

Status queue_enqueue(Queue* queue, Element element)
{
    Node* head = queue->head;
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

    // Si la cola está vacía, simplemente inserto el nuevo nodo.
    if (head == NULL)
    {
        // Actualizo la dirección de comienzo de la cola.
        queue->head = node;

        return SUCCESS;
    }

    // Recorro la cola hasta llegar al último nodo.
    while (head->next != NULL)
    {
        head = head->next;
    }

    // Encontré el último nodo, lo hago apuntar al nuevo nodo.
    head->next = node;

    return SUCCESS;
}

Status queue_dequeue(Queue* queue, Element* element)
{
    Node* head = queue->head;

    // Chequeo si la cola está vacía.
    if (head == NULL)
    {
        return ERROR_MEMORY_FAILURE;
    }

    // Retorno por referencia el valor almacenado en el nodo.
    *element = head->element;

    // Modifico la dirección de comienzo de la cola a la del próximo nodo.
    queue->head = head->next;

    // Libero la memoria correspondiente al nodo siendo removido.
    free(head);

    return SUCCESS;
}

Status queue_peek(Queue* queue, Element* element)
{
    Node* head = queue->head;

    // Chequeo si la cola está vacía.
    if (head == NULL)
    {
        return ERROR_MEMORY_FAILURE;
    }

    // Retorno por referencia el valor almacenado en el nodo.
    *element = head->element;

    return SUCCESS;
}

void queue_print(Queue* queue)
{
    Node* head = queue->head;

    // Imprimo el contenido de la cola nodo a nodo.
    printf("Contenido de la cola: ");
    printf("HEAD --> ");

    while (head != NULL)
    {
        printf("%d --> ", head->element.data);
        head = head->next;
    }

    printf("NULL\n");
}

void queue_destroy(Queue* queue)
{
    Node* head = queue->head;

    // Libero la memoria solicitada nodo a nodo hasta vaciar la cola.
    while (head != NULL)
    {
        queue->head = head->next;
        free(head);
        head = queue->head;
    }

    free(queue);
}
