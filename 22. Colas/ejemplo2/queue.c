/**
 * \file            queue.c
 * \brief           22. Colas - Ejemplo 2 - Implementación sencilla de una cola (2)
 * \author          Javier Balloffet
 * \date            Mar 16, 2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

QueueStatus enqueue(QueueNode** queue, int value) {
    /* 1. Declaro un puntero a QueueNode (QueueNode*) para almacenar la direccion de comienzo de la cola */
    QueueNode* head = *queue;
    /* 2. Declaro un puntero a QueueNode (QueueNode*) para almacenar la direccion del nuevo nodo */
    QueueNode* new_node = NULL;

    /* 3. Solicito memoria al SO equivalente a un nodo (QueueNode) */
    new_node = (QueueNode*) malloc(sizeof(QueueNode));
    if (new_node == NULL) {
        return QS_MEMORY_ERROR;
    }

    /* 4. Cargo el nuevo valor en el nodo. Asigno un valor nulo al puntero por ahora */
    new_node->value = value;
    new_node->next = NULL;

    /* 5. Se encola el nuevo nodo. Se encola al final, para que la menor demora sea al desencolar */
    /* 6. Chequeo si la cola esta vacía */
    if (head == NULL) {
        /* 7. ¡La cola está vacía! Agrego el nuevo nodo */
        *queue = new_node;
    } else { 
        /* 8. ¡La cola no está vacía! La recorro hasta encontrar el final */
        while (head->next != NULL) {
            head = head->next;
        }

        /* 9. Encontré el último nodo. Lo hago apuntar al nuevo nodo */
        head->next = new_node;
    }

    return QS_SUCCESS;
}

QueueStatus dequeue(QueueNode** queue, int* value) {
    /* 1. Declaro un puntero a QueueNode (QueueNode*) para almacenar la direccion de comienzo de la cola */
    QueueNode* head = *queue;

    /* 2. Chequeo si la cola esta vacía */
    if (head == NULL) {
        return QS_EMPTY_QUEUE;
    }

    /* 3. Se desencola un nodo. Se desencola del principio para demorar lo menos posible */
    /* 4. Obtengo el valor almacenado en el nodo */
    *value = head->value;

    /* 5. Modifico la dirección de comienzo de la cola a la del próximo nodo */
    *queue = head->next;

    /* 6. Libero la memoria solicitada al SO para el nodo que se está desencolando */
    free(head);

    return QS_SUCCESS;
}

QueueStatus peek(QueueNode* queue, int* value) {
    /* 1. Declaro un puntero a QueueNode (QueueNode*) para almacenar la direccion de comienzo de la cola */
    QueueNode* head = queue;

    /* 2. Chequeo si la cola esta vacía */
    if (head == NULL) {
        return QS_EMPTY_QUEUE;
    }

    /* 3. Obtengo el valor almacenado en el nodo */
    *value = head->value;

    return QS_SUCCESS;
}

void free_queue(QueueNode** queue) {
    /* 1. Declaro un puntero a QueueNode (QueueNode*) para almacenar la direccion de comienzo de la cola */
    QueueNode* head = *queue;

    /* 2. Libero la memoria solicitada al SO nodo a nodo hasta vaciar la cola */
    while (head != NULL) {
        *queue = head->next;
        free(head);
        head = *queue;
    }
}

void print_queue(QueueNode* queue) {
    /* 1. Declaro un puntero a QueueNode (QueueNode*) para almacenar la direccion de comienzo de la cola */
    QueueNode* head = queue;

    /* 2. Imprimo el contenido de la cola nodo a nodo */
    printf("Contenido de la cola: ");
    printf("HEAD --> ");

    while (head != NULL) {
        printf("%d --> ", head->value);
        head = head->next;
    }

    printf("NULL\n");
}
