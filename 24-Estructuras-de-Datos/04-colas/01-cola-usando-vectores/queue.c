/*!
 * @file   queue.c
 * @brief  24. Estructuras de Datos - 04. Colas - 01. Cola usando vectores
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Jan 8, 2023
 */
#include "queue.h"

#include <stdio.h>

Queue* queue_create()
{
    Queue* queue = NULL;
    return queue;
}

Status queue_enqueue(Queue* queue, Element element)
{
    return SUCCESS;
}

Status queue_dequeue(Queue* queue, Element* element)
{
    return SUCCESS;
}

Status queue_peek(Queue* queue, Element* element)
{
    return SUCCESS;
}

void queue_print(Queue* queue) {}

void queue_destroy(Queue* queue) {}
