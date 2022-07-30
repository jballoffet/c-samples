/*!
 * @file   linked_list.c
 * @brief  24. Estructuras de Datos - 02. Listas Enlazadas - 01. Lista
 *   Simplemente Enlazada
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Mar 16, 2019
 */
#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

LinkedListStatus insert_head(LinkedListNode** linkedList, int value)
{
    // Declaro un puntero a LinkedListNode (LinkedListNode*) para almacenar la
    // direccion de comienzo de la lista.
    LinkedListNode* head = *linkedList;
    // Declaro un puntero a LinkedListNode (LinkedListNode*) para almacenar la
    // direccion del nuevo nodo.
    LinkedListNode* new_node = NULL;

    // Solicito memoria al SO equivalente a un nodo (LinkedListNode).
    new_node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    if (new_node == NULL)
    {
        printf("Error! Memoria no asignada.\n");
        return LL_MEMORY_ERROR;
    }

    // Cargo el nuevo valor en el nodo. Asigno un valor nulo al puntero por
    // ahora.
    new_node->value = value;
    new_node->next = NULL;

    // Inserto el nuevo nodo al principio de la lista.
    *linkedList = new_node;
    new_node->next = head;

    return LL_SUCCESS;
}

LinkedListStatus insert_tail(LinkedListNode** linkedList, int value)
{
    // Declaro un puntero a LinkedListNode (LinkedListNode*) para almacenar la
    // direccion de comienzo de la lista.
    LinkedListNode* head = *linkedList;
    // Declaro un puntero a LinkedListNode (LinkedListNode*) para almacenar la
    // direccion del nuevo nodo.
    LinkedListNode* new_node = NULL;

    // Solicito memoria al SO equivalente a un nodo (LinkedListNode).
    new_node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    if (new_node == NULL)
    {
        printf("Error! Memoria no asignada.\n");
        return LL_MEMORY_ERROR;
    }

    // Cargo el nuevo valor en el nodo. Asigno un valor nulo al puntero por
    // ahora.
    new_node->value = value;
    new_node->next = NULL;

    // Inserto el nuevo nodo al final de la lista.
    // Chequeo si la lista está vacía.
    if (head == NULL)
    {
        // ¡La lista está vacía! Agrego el nuevo nodo.
        *linkedList = new_node;
    }
    else
    {
        // ¡La lista no está vacía! La recorro hasta encontrar el final.
        while (head->next != NULL)
        {
            head = head->next;
        }

        // Encontré el último nodo. Lo hago apuntar al nuevo nodo.
        head->next = new_node;
    }

    return LL_SUCCESS;
}

LinkedListStatus insert_at(LinkedListNode** linkedList, int value, int index)
{
    // Declaro un puntero a LinkedListNode (LinkedListNode*) para almacenar la
    // direccion de comienzo de la lista.
    LinkedListNode* head = *linkedList;
    // Declaro un puntero a LinkedListNode (LinkedListNode*) para almacenar la
    // direccion del nuevo nodo.
    LinkedListNode* new_node = NULL;
    int i;

    // Solicito memoria al SO equivalente a un nodo (LinkedListNode).
    new_node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    if (new_node == NULL)
    {
        printf("Error! Memoria no asignada.\n");
        return LL_MEMORY_ERROR;
    }

    // Cargo el nuevo valor en el nodo. Asigno un valor nulo al puntero por
    // ahora.
    new_node->value = value;
    new_node->next = NULL;

    // Inserto el nuevo nodo en la posición requerida.
    // Chequeo si la lista está vacía.
    if (head == NULL)
    {
        // ¡La lista está vacía! Agrego el nuevo nodo.
        *linkedList = new_node;
    }
    else
    {
        // ¡La lista no está vacía! Recorro la lista hasta llegar al índice
        // requerido.
        if (index == 0)
        {
            *linkedList = new_node;
            new_node->next = head;
        }
        else
        {
            for (i = 0; i < (index - 1); i++)
            {
                if (head->next == NULL)
                {
                    printf("Error! Indice invalido.\n");
                    return LL_INVALID_INDEX;
                }
                head = head->next;
            }

            // Inserto el nuevo nodo.
            new_node->next = head->next;
            head->next = new_node;
        }
    }

    return LL_SUCCESS;
}

LinkedListStatus remove_head(LinkedListNode** linkedList, int* value)
{
    // Declaro un puntero a LinkedListNode (LinkedListNode*) para almacenar la
    // direccion de comienzo de la lista.
    LinkedListNode* head = *linkedList;

    // Chequeo si la lista está vacía.
    if (head == NULL)
    {
        printf("Error! La lista esta vacia.\n");
        return LL_EMPTY_LIST;
    }

    // Remuevo un nodo del principio de la lista.
    // Obtengo el valor almacenado en el nodo.
    *value = head->value;

    // Modifico la dirección de comienzo de la lista a la del próximo nodo.
    *linkedList = head->next;

    // Libero la memoria solicitada al SO para el nodo que se está removiendo.
    free(head);

    return LL_SUCCESS;
}

LinkedListStatus remove_tail(LinkedListNode** linkedList, int* value)
{
    // Declaro un puntero a LinkedListNode (LinkedListNode*) para almacenar la
    // direccion de comienzo de la lista.
    LinkedListNode* head = *linkedList;
    // Declaro un puntero a LinkedListNode (LinkedListNode*) para almacenar la
    // direccion del anteúltimo nodo de la lista.
    LinkedListNode* previous = NULL;

    // Chequeo si la lista está vacía.
    if (head == NULL)
    {
        printf("Error! La lista esta vacia.\n");
        return LL_EMPTY_LIST;
    }

    // Remuevo un nodo del final de la lista.
    // Recorro la lista hasta encontrar el final.
    while (head->next != NULL)
    {
        previous = head;
        head = head->next;
    }

    // Encontré el último nodo. Obtengo el valor almacenado en el nodo.
    *value = head->value;

    // Modifico el campo next del anteúltimo nodo de la lista (o el comienzo de
    // la lista) a un valor nulo.
    if (previous != NULL)
    {
        previous->next = NULL;
    }
    else
    {
        *linkedList = NULL;
    }

    // Libero la memoria solicitada al SO para el nodo que se está removiendo.
    free(head);

    return LL_SUCCESS;
}

LinkedListStatus remove_at(LinkedListNode** linkedList, int* value, int index)
{
    // Declaro un puntero a LinkedListNode (LinkedListNode*) para almacenar la
    // direccion de comienzo de la lista.
    LinkedListNode* head = *linkedList;
    // Declaro un puntero a LinkedListNode (LinkedListNode*) para almacenar la
    // direccion del anterior nodo de la lista.
    LinkedListNode* previous = NULL;
    int i;

    // Chequeo si la lista está vacía.
    if (head == NULL)
    {
        printf("Error! La lista esta vacia.\n");
        return LL_EMPTY_LIST;
    }

    // Recorro la lista hasta llegar al índice requerido.
    for (i = 0; i < index; i++)
    {
        if (head->next == NULL)
        {
            printf("Error! Indice invalido.\n");
            return LL_INVALID_INDEX;
        }
        previous = head;
        head = head->next;
    }

    // Encontré el nodo. Obtengo el valor almacenado en el nodo.
    *value = head->value;

    // Modifico el campo next del nodo anterior de la lista al nodo siguiente.
    previous->next = head->next;

    // Libero la memoria solicitada al SO para el nodo que se está removiendo.
    free(head);

    return LL_SUCCESS;
}

LinkedListStatus search(LinkedListNode* linkedList, int value, int* index)
{
    // Declaro un puntero a LinkedListNode (LinkedListNode*) para almacenar la
    // direccion de comienzo de la lista.
    LinkedListNode* head = linkedList;
    int i = 0;

    // Chequeo si la lista está vacía.
    if (head == NULL)
    {
        printf("Error! La lista esta vacia.\n");
        return LL_EMPTY_LIST;
    }

    // Recorro la lista hasta encontrar el valor buscado.
    while (head != NULL)
    {
        if (head->value == value)
        {
            printf("Valor hallado!\n");
            *index = i;
            return LL_SUCCESS;
        }
        head = head->next;
        i++;
    }

    printf("Valor ausente!\n");
    return LL_INVALID_VALUE;
}

LinkedListStatus peek(LinkedListNode* linkedList, int* value, int index)
{
    // Declaro un puntero a LinkedListNode (LinkedListNode*) para almacenar la
    // direccion de comienzo de la lista.
    LinkedListNode* head = linkedList;
    int i;

    // Chequeo si la lista está vacía.
    if (head == NULL)
    {
        printf("Error! La lista esta vacia.\n");
        return LL_EMPTY_LIST;
    }

    // Recorro la lista hasta llegar al índice requerido.
    for (i = 0; i < index; i++)
    {
        if (head->next == NULL)
        {
            printf("Error! Indice invalido.\n");
            return LL_INVALID_INDEX;
        }
        head = head->next;
    }

    // Obtengo el valor almacenado en el nodo.
    *value = head->value;

    return LL_SUCCESS;
}

void free_list(LinkedListNode** linkedList)
{
    // Declaro un puntero a LinkedListNode (LinkedListNode*) para almacenar la
    // direccion de comienzo de la lista.
    LinkedListNode* head = *linkedList;

    // Libero la memoria solicitada al SO nodo a nodo hasta vaciar la lista.
    while (head != NULL)
    {
        *linkedList = head->next;
        free(head);
        head = *linkedList;
    }
}

void print_list(LinkedListNode* linkedList)
{
    // Declaro un puntero a LinkedListNode (LinkedListNode*) para almacenar la
    // direccion de comienzo de la lista.
    LinkedListNode* head = linkedList;

    // Imprimo el contenido de la lista nodo a nodo.
    printf("Contenido de la lista: ");
    printf("HEAD --> ");

    while (head != NULL)
    {
        printf("%d --> ", head->value);
        head = head->next;
    }

    printf("NULL\n");
}
