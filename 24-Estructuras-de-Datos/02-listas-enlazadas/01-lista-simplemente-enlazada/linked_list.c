/*!
 * @file   linked_list.c
 * @brief  24. Estructuras de Datos - 02. Listas Enlazadas - 01. Lista
 *   Simplemente Enlazada
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Jan 7, 2023
 */
#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

LinkedList* linked_list_create()
{
    LinkedList* linked_list = NULL;

    // Solicito memoria para almacenar los datos de la lista enlazada.
    linked_list = (LinkedList*)malloc(sizeof(LinkedList));
    if (linked_list != NULL)
    {
        linked_list->head = NULL;
    }

    return linked_list;
}

Status linked_list_insert_head(LinkedList* linked_list, Element element)
{
    Node* head = linked_list->head;
    Node* node = NULL;

    // Solicito memoria para el nuevo nodo.
    node = (Node*)malloc(sizeof(Node));
    if (node == NULL)
    {
        return ERROR_MEMORY_ERROR;
    }

    // Inicializo el nuevo nodo.
    node->element = element;
    node->next = NULL;

    // Hago que el nuevo nodo apunte al principio de la lista.
    node->next = head;

    // Actualizo la dirección de comienzo de la lista.
    linked_list->head = node;

    return SUCCESS;
}

Status linked_list_insert_tail(LinkedList* linked_list, Element element)
{
    Node* head = linked_list->head;
    Node* node = NULL;

    // Solicito memoria para el nuevo nodo.
    node = (Node*)malloc(sizeof(Node));
    if (node == NULL)
    {
        return ERROR_MEMORY_ERROR;
    }

    // Inicializo el nuevo nodo.
    node->element = element;
    node->next = NULL;

    // Si la lista está vacía, simplemente inserto el nuevo nodo.
    if (head == NULL)
    {
        // Actualizo la dirección de comienzo de la lista.
        linked_list->head = node;

        return SUCCESS;
    }

    // Recorro la lista hasta llegar al último nodo.
    while (head->next != NULL)
    {
        head = head->next;
    }

    // Encontré el último nodo, lo hago apuntar al nuevo nodo.
    head->next = node;

    return SUCCESS;
}

Status linked_list_remove_head(LinkedList* linked_list, Element* element)
{
    Node* head = linked_list->head;

    // Chequeo si la lista está vacía.
    if (linked_list_is_empty(linked_list))
    {
        return ERROR_EMPTY_LIST;
    }

    // Retorno por referencia el valor almacenado en el nodo.
    *element = head->element;

    // Modifico la dirección de comienzo de la lista a la del próximo nodo.
    linked_list->head = head->next;

    // Libero la memoria correspondiente al nodo siendo removido.
    free(head);

    return SUCCESS;
}

Status linked_list_remove_tail(LinkedList* linked_list, Element* element)
{
    Node* head = linked_list->head;
    Node* previous_node = NULL;

    // Chequeo si la lista está vacía.
    if (linked_list_is_empty(linked_list))
    {
        return ERROR_EMPTY_LIST;
    }

    // Recorro la lista hasta llegar al último nodo.
    while (head->next != NULL)
    {
        previous_node = head;
        head = head->next;
    }

    // Encontré el último nodo. Obtengo el valor almacenado en el nodo.
    *element = head->element;

    // Modifico el campo next del anteúltimo nodo de la lista (o el comienzo de
    // la lista) a un valor nulo.
    if (previous_node != NULL)
    {
        previous_node->next = NULL;
    }
    else
    {
        linked_list->head = NULL;
    }

    // Libero la memoria correspondiente al nodo siendo removido.
    free(head);

    return SUCCESS;
}

int linked_list_is_empty(const LinkedList* linked_list)
{
    return linked_list->head == NULL;
}

void linked_list_print(const LinkedList* linked_list)
{
    Node* head = linked_list->head;

    // Imprimo el contenido de la lista nodo a nodo.
    printf("Contenido de la lista: ");
    printf("HEAD --> ");

    while (head != NULL)
    {
        printf("%d --> ", head->element.data);
        head = head->next;
    }

    printf("NULL\n");
}

void linked_list_destroy(LinkedList* linked_list)
{
    Node* head = linked_list->head;

    // Libero la memoria solicitada nodo a nodo hasta vaciar la lista.
    while (head != NULL)
    {
        linked_list->head = head->next;
        free(head);
        head = linked_list->head;
    }

    free(linked_list);
}
