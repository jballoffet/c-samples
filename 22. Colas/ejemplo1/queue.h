/**
 * \file            queue.h
 * \brief           22. Colas - Ejemplo 1 - Implementación sencilla de una cola
 * \author          Javier Balloffet
 * \date            Mar 16, 2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#ifndef QUEUE_H_
#define QUEUE_H_

typedef struct QueueNode {
    int value;
    struct QueueNode* next;
} QueueNode;

typedef enum {
    QS_SUCCESS = 0,
    QS_MEMORY_ERROR,
    QS_EMPTY_QUEUE
} QueueStatus;

QueueStatus enqueue(QueueNode** queue, int value);
QueueStatus dequeue(QueueNode** queue, int* value);
QueueStatus peek(QueueNode* queue, int* value);
void free_queue(QueueNode** queue);
void print_queue(QueueNode* queue);

#endif /* QUEUE_H_ */

