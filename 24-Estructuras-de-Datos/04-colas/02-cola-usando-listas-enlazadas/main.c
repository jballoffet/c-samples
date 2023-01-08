/*!
 * @file   main.c
 * @brief  24. Estructuras de Datos - 04. Colas - 02. Cola usando listas
 *   enlazadas
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Jan 8, 2023
 */
#include <stdio.h>

#include "queue.h"

int main(void)
{
    Queue* queue = NULL;
    Element element;
    int i;

    // Creo una cola como un tipo de dato abstracto.
    queue = queue_create();
    if (queue == NULL)
    {
        printf("Error! Cola no creada.\n");
        return -1;
    }

    // Encolo los números del 1 al 5.
    for (i = 1; i <= 5; i++)
    {
        element.data = i;
        if (queue_enqueue(queue, element) != SUCCESS)
        {
            printf("Error! Memoria no asignada.\n");
            return -1;
        }
        queue_print(queue);
    }

    // Desencolo un nodo.
    if (queue_dequeue(queue, &element) == SUCCESS)
    {
        printf("Valor obtenido (desencolado): %d\n", element.data);
    }
    else
    {
        printf("Error! La cola esta vacia.\n");
    }
    queue_print(queue);

    // Observo el valor del próximo nodo a desencolar (sin desencolarlo).
    if (queue_peek(queue, &element) == SUCCESS)
    {
        printf("Valor obtenido (sin desencolar): %d\n", element.data);
    }
    else
    {
        printf("Error! La cola esta vacia.\n");
    }
    queue_print(queue);

    // Desencolo un nodo.
    if (queue_dequeue(queue, &element) == SUCCESS)
    {
        printf("Valor obtenido (desencolado): %d\n", element.data);
    }
    else
    {
        printf("Error! La cola esta vacia.\n");
    }
    queue_print(queue);

    // Destruyo la cola.
    queue_destroy(queue);

    return 0;
}
