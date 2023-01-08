/*!
 * @file   main.c
 * @brief  24. Estructuras de Datos - 02. Listas Enlazadas - 01. Lista
 *   Simplemente Enlazada
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Jan 7, 2023
 */
#include <stdio.h>

#include "linked_list.h"

int main(void)
{
    LinkedList* linked_list = NULL;
    Element element;
    int i;

    // Creo una lista enlazada como un tipo de dato abstracto.
    linked_list = linked_list_create();
    if (linked_list == NULL)
    {
        printf("Error! Lista Enlazada no creado.\n");
        return -1;
    }

    // Inserto los números del 1 al 5 al principio de la lista.
    for (i = 1; i <= 5; i++)
    {
        element.data = i;
        linked_list_insert_head(linked_list, element);
        linked_list_print(linked_list);
    }

    // Inserto los números del 6 al 10 al final de la lista.
    for (i = 6; i <= 10; i++)
    {
        element.data = i;
        linked_list_insert_tail(linked_list, element);
        linked_list_print(linked_list);
    }

    // Remuevo un nodo del principio de la lista.
    linked_list_remove_head(linked_list, &element);
    printf("Valor obtenido (removido): %d\n", element.data);
    linked_list_print(linked_list);

    // Remuevo un nodo del final de la lista.
    linked_list_remove_tail(linked_list, &element);
    printf("Valor obtenido (removido): %d\n", element.data);
    linked_list_print(linked_list);

    // Destruyo la lista.
    linked_list_destroy(linked_list);

    return 0;
}
