/*!
 * @file   linked_list.h
 * @brief  24. Estructuras de Datos - 02. Listas Enlazadas - 01. Lista
 *   Simplemente Enlazada
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Jan 7, 2023
 */
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct Element
{
    int data;
} Element;

typedef struct Node
{
    Element element;
    struct Node* next;
} Node;

typedef struct LinkedList
{
    Node* head;
} LinkedList;

typedef enum Status
{
    SUCCESS = 0,
    ERROR_MEMORY_ERROR,
    ERROR_EMPTY_LIST,
    ERROR_INVALID_INDEX,
    ERROR_INVALID_VALUE
} Status;

// @brief Crea una lista enlazada.
LinkedList* linked_list_create();

// @brief Agrega un elemento al comienzo de la lista enlazada.
Status linked_list_insert_head(LinkedList* linked_list, Element element);

// @brief Agrega un elemento al final de la lista enlazada.
Status linked_list_insert_tail(LinkedList* linked_list, Element element);

// @brief Quita el elemento presente al comienzo de la lista enlazada.
Status linked_list_remove_head(LinkedList* linked_list, Element* element);

// @brief Quita el elemento presente al final de la lista enlazada.
Status linked_list_remove_tail(LinkedList* linked_list, Element* element);

// @brief Chequea si la lista se encuentra vacía.
int linked_list_is_empty(const LinkedList* linked_list);

// @brief Imprime el contenido de la lista enlazada.
void linked_list_print(const LinkedList* linked_list);

// @brief Destruye la lista enlazada.
void linked_list_destroy(LinkedList* linked_list);

#endif  // LINKED_LIST_H_
