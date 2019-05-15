/**
 * \file            main.c
 * \brief           22. Colas - Ejemplo 2 - Implementación sencilla de una cola (2)
 * \author          Javier Balloffet
 * \date            Mar 16, 2019
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
        if (enqueue(&queue, i) != QS_SUCCESS) {
            printf("Error! Memoria no asignada.\n");
            return -1;
        }
        print_queue(queue);
    }

    /* 3. Desencolo un nodo */
    if (dequeue(&queue, &value) == QS_SUCCESS) {
        printf("Valor obtenido (desencolado): %d\n", value);
    } else {
        printf("Error! La cola esta vacia.\n");
    }
    print_queue(queue);

    /* 4. Observo el valor del próximo nodo a desencolar (sin desencolarlo) */
    if (peek(queue, &value) == QS_SUCCESS) {
        printf("Valor obtenido (sin desencolar): %d\n", value);
    } else {
        printf("Error! La cola esta vacia.\n");
    }
    print_queue(queue);

    /* 5. Desencolo un nodo */
    if (dequeue(&queue, &value) == QS_SUCCESS) {
        printf("Valor obtenido (desencolado): %d\n", value);
    } else {
        printf("Error! La cola esta vacia.\n");
    }
    print_queue(queue);

    /* 6. Libero la memoria de la cola completa */
    free_queue(&queue);
    print_queue(queue);

    /* 7. Intento desencolar de una cola vacía */
    if (dequeue(&queue, &value) == QS_SUCCESS) {
        printf("Valor obtenido (desencolado): %d\n", value);
    } else {
        printf("Error! La cola esta vacia.\n");
    }
    print_queue(queue);

	return 0;
}
