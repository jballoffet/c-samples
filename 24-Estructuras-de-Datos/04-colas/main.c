/*!
 * @file   main.c
 * @brief  24. Estructuras de Datos - 04. Colas
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Mar 16, 2019
 */
#include <stdio.h>

#include "queue.h"

int main(void)
{
    // Declaro una Cola (Queue). La misma es un puntero al primer nodo.
    QueueNode* queue = NULL;
    int i, value;

    // Encolo los números del 1 al 5.
    for (i = 1; i <= 5; i++)
    {
        if (enqueue(&queue, i) != QS_SUCCESS)
        {
            printf("Error! Memoria no asignada.\n");
            return -1;
        }
        print_queue(queue);
    }

    // Desencolo un nodo.
    if (dequeue(&queue, &value) == QS_SUCCESS)
    {
        printf("Valor obtenido (desencolado): %d\n", value);
    }
    else
    {
        printf("Error! La cola esta vacia.\n");
    }
    print_queue(queue);

    // Observo el valor del próximo nodo a desencolar (sin desencolarlo).
    if (peek(queue, &value) == QS_SUCCESS)
    {
        printf("Valor obtenido (sin desencolar): %d\n", value);
    }
    else
    {
        printf("Error! La cola esta vacia.\n");
    }
    print_queue(queue);

    // Desencolo un nodo.
    if (dequeue(&queue, &value) == QS_SUCCESS)
    {
        printf("Valor obtenido (desencolado): %d\n", value);
    }
    else
    {
        printf("Error! La cola esta vacia.\n");
    }
    print_queue(queue);

    // Libero la memoria de la cola completa.
    free_queue(&queue);
    print_queue(queue);

    // Intento desencolar de una cola vacía.
    if (dequeue(&queue, &value) == QS_SUCCESS)
    {
        printf("Valor obtenido (desencolado): %d\n", value);
    }
    else
    {
        printf("Error! La cola esta vacia.\n");
    }
    print_queue(queue);

    return 0;
}
