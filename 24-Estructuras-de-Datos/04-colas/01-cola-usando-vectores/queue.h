/*!
 * @file   queue.h
 * @brief  24. Estructuras de Datos - 04. Colas - 01. Cola usando vectores
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Jan 4, 2023
 */
#ifndef QUEUE_H_
#define QUEUE_H_

typedef struct Element
{
    int data;
} Element;

typedef struct Queue
{
    Element* elements;
    int size;
} Queue;

typedef enum Status
{
    SUCCESS = 0,
    ERROR_MEMORY_FAILURE,
    ERROR_EMPTY_QUEUE
} Status;

// @brief Crea una cola.
Queue* queue_create();

// @brief Inserta un elemento en la cola.
Status queue_enqueue(Queue* queue, Element element);

// @brief Quita un elemento de la cola.
Status queue_dequeue(Queue* queue, Element* element);

// @brief Devuelve el valor del próximo elemento a quitar de la cola (sin
// quitarlo).
Status queue_peek(Queue* queue, Element* element);

// @brief Imprime el contenido de la cola.
void queue_print(Queue* queue);

// @brief Destruye la cola.
void queue_destroy(Queue* queue);

#endif  // QUEUE_H_
