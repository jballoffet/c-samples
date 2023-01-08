/*!
 * @file   queue.c
 * @brief  24. Estructuras de Datos - 04. Colas - 01. Cola usando vectores
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
        queue->elements = NULL;
        queue->size = 0;
    }

    return queue;
}

Status queue_enqueue(Queue* queue, Element element)
{
    Element* aux = NULL;

    // Redimensiono la cola.
    aux =
        (Element*)realloc(queue->elements, (queue->size + 1) * sizeof(Element));
    if (aux == NULL)
    {
        return ERROR_MEMORY_FAILURE;
    }
    queue->elements = aux;

    // Agrego el nuevo elemento e incremento el tamaño de la cola.
    queue->elements[queue->size] = element;
    queue->size++;

    return SUCCESS;
}

Status queue_dequeue(Queue* queue, Element* element)
{
    Element* aux = NULL;
    int i;

    // Chequeo si la cola está vacía.
    if (queue->size == 0)
    {
        return ERROR_EMPTY_QUEUE;
    }

    // Retorno por referencia el elemento a remover.
    *element = queue->elements[0];

    // Desplazo los elementos siguientes para poder redimensionar la cola.
    for (i = 0; i < (queue->size - 1); i++)
    {
        queue->elements[i] = queue->elements[i + 1];
    }

    // Redimensiono la cola.
    aux =
        (Element*)realloc(queue->elements, (queue->size - 1) * sizeof(Element));
    if (aux == NULL)
    {
        return ERROR_MEMORY_FAILURE;
    }
    queue->elements = aux;

    // Decremento el tamaño de la cola.
    queue->size--;

    return SUCCESS;
}

Status queue_peek(Queue* queue, Element* element)
{
    // Chequeo si la cola está vacía.
    if (queue->size == 0)
    {
        return ERROR_EMPTY_QUEUE;
    }

    // Retorno por referencia el elemento a obtener.
    *element = queue->elements[0];

    return SUCCESS;
}

void queue_print(Queue* queue)
{
    int i;

    // Imprimo los datos almacenados en la cola.
    printf("Contenido: [");
    for (i = 0; i < queue->size - 1; i++)
    {
        printf("%d, ", queue->elements[i].data);
    }
    printf("%d]\n", queue->elements[i].data);

    // Imprimo el tamaño de la pila.
    printf("Tamanio: %d\n", queue->size);
}

void queue_destroy(Queue* queue)
{
    // Libero la memoria correspondiente a los elementos agregados.
    if (queue->elements != NULL)
    {
        free(queue->elements);
        queue->elements = NULL;
    }

    // Libero la memoria correspondiente a los datos de la cola.
    free(queue);
}
