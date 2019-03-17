/**
 * \file            main.c
 * \brief           22. Colas - Ejemplo 1 - Implementación sencilla de una cola
 * \author          Javier Balloffet
 * \date            16-MAR-2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include "queue.h"

int main() {
    /* 1. Declaro una Cola (Queue). La misma es un puntero al primer nodo */
    QueueNode* queue = NULL;
    int i, value;

    /* 2. Encolo los números del 1 al 5 */
    for (i = 1; i <= 5; i++) {
        enqueue(&queue, i);
        print_queue(queue);
    }

    /* 3. Desencolo un nodo */
    dequeue(&queue, &value);
    printf("Valor obtenido (desencolado): %d\n", value);
    print_queue(queue);

    /* 4. Observo el valor del próximo nodo a desencolar (sin desencolarlo) */
    peek(queue, &value);
    printf("Valor obtenido (sin desencolar): %d\n", value);
    print_queue(queue);

    /* 5. Desencolo un nodo */
    dequeue(&queue, &value);
    printf("Valor obtenido (desencolado): %d\n", value);
    print_queue(queue);

    /* 6. Libero la memoria de la cola completa */
    free_queue(&queue);
    print_queue(queue);

    /* 7. Intento desencolar de una cola vacía */
    dequeue(&queue, &value);
    print_queue(queue);

	return 0;
}
