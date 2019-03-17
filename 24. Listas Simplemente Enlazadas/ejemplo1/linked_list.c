/**
 * \file            linked_list.c
 * \brief           24. Listas Simplemente Enlazadas - Ejemplo 1 - Implementación sencilla de una lista simplemente enlazada
 * \author          Javier Balloffet
 * \date            16-MAR-2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

LinkedListStatus insert_head(LinkedListNode** linkedList, int value) {
    /* 1. Declaro un puntero a LinkedListNode (LinkedListNode*) para almacenar la direccion de comienzo de la lista */
    LinkedListNode* head = *linkedList;
    /* 2. Declaro un puntero a LinkedListNode (LinkedListNode*) para almacenar la direccion del nuevo nodo */
    LinkedListNode* new_node = NULL;

    /* 3. Solicito memoria al SO equivalente a un nodo (LinkedListNode) */
    new_node = (LinkedListNode*) malloc(sizeof(LinkedListNode));
    if (new_node == NULL) {
        printf("Error! Memoria no asignada.\n");
        return LL_MEMORY_ERROR;
    }

    /* 4. Cargo el nuevo valor en el nodo. Asigno un valor nulo al puntero por ahora */
    new_node->value = value;
    new_node->next = NULL;

    /* 5. Inserto el nuevo nodo al principio de la lista */
    *linkedList = new_node;
    new_node->next = head;

    return LL_SUCCESS;
}

LinkedListStatus insert_tail(LinkedListNode** linkedList, int value) {
    /* 1. Declaro un puntero a LinkedListNode (LinkedListNode*) para almacenar la direccion de comienzo de la lista */
    LinkedListNode* head = *linkedList;
    /* 2. Declaro un puntero a LinkedListNode (LinkedListNode*) para almacenar la direccion del nuevo nodo */
    LinkedListNode* new_node = NULL;

    /* 3. Solicito memoria al SO equivalente a un nodo (LinkedListNode) */
    new_node = (LinkedListNode*) malloc(sizeof(LinkedListNode));
    if (new_node == NULL) {
        printf("Error! Memoria no asignada.\n");
        return LL_MEMORY_ERROR;
    }

    /* 4. Cargo el nuevo valor en el nodo. Asigno un valor nulo al puntero por ahora */
    new_node->value = value;
    new_node->next = NULL;

    /* 5. Inserto el nuevo nodo al final de la lista */
    /* 6. Chequeo si la lista está vacía */
    if (head == NULL) {
        /* 7. ¡La lista está vacía! Agrego el nuevo nodo */
        *linkedList = new_node;
    } else { 
        /* 8. ¡La lista no está vacía! La recorro hasta encontrar el final */
        while (head->next != NULL) {
            head = head->next;
        }

        /* 9. Encontré el último nodo. Lo hago apuntar al nuevo nodo */
        head->next = new_node;
    }

    return LL_SUCCESS;
}

LinkedListStatus insert_at(LinkedListNode** linkedList, int value, int index) {
    // TODO
}

LinkedListStatus remove_head(LinkedListNode** linkedList, int* value) {
    /* 1. Declaro un puntero a LinkedListNode (LinkedListNode*) para almacenar la direccion de comienzo de la lista */
    LinkedListNode* head = *linkedList;

    /* 2. Chequeo si la lista está vacía */
    if (head == NULL) {
        printf("Error! La lista esta vacia.\n");
        return LL_EMPTY_LIST;
    }

    /* 3. Remuevo un nodo del principio de la lista */
    /* 4. Obtengo el valor almacenado en el nodo */
    *value = head->value;

    /* 5. Modifico la dirección de comienzo de la lista a la del próximo nodo */
    *linkedList = head->next;

    /* 6. Libero la memoria solicitada al SO para el nodo que se está removiendo */
    free(head);

    return LL_SUCCESS;
}

LinkedListStatus remove_tail(LinkedListNode** linkedList, int* value) {
    /* 1. Declaro un puntero a LinkedListNode (LinkedListNode*) para almacenar la direccion de comienzo de la lista */
    LinkedListNode* head = *linkedList;
    /* 2. Declaro un puntero a LinkedListNode (LinkedListNode*) para almacenar la direccion del anteúltimo nodo de la lista */
    LinkedListNode* previous = NULL;

    /* 3. Chequeo si la lista está vacía */
    if (head == NULL) {
        printf("Error! La lista esta vacia.\n");
        return LL_EMPTY_LIST;
    }

    /* 4. Remuevo un nodo del final de la lista */ 
    /* 5. Recorro la lista hasta encontrar el final */
    while (head->next != NULL) {
        previous = head;
        head = head->next;
    }

    /* 6. Encontré el último nodo. Obtengo el valor almacenado en el nodo */
    *value = head->value;

    /* 7. Modifico el campo next del anteúltimo nodo de la lista a un valor nulo */
    previous->next = NULL;

    /* 8. Libero la memoria solicitada al SO para el nodo que se está removiendo */
    free(head);

    return LL_SUCCESS;
}

LinkedListStatus remove_at(LinkedListNode** linkedList, int* value, int index) {
    // TODO
}

LinkedListStatus search(LinkedListNode* linkedList, int value, int* index) {
    // TODO
}

LinkedListStatus peek(LinkedListNode* linkedList, int* value, int index) {
    /* 1. Declaro un puntero a LinkedListNode (LinkedListNode*) para almacenar la direccion de comienzo de la lista */
    LinkedListNode* head = linkedList;
    int i;

    /* 2. Chequeo si la lista está vacía */
    if (head == NULL) {
        printf("Error! La lista esta vacia.\n");
        return LL_EMPTY_LIST;
    }

    /* 3. Recorro la lista hasta llegar al índice requerido */
    for (i = 0; i < index; i++) {
        if (head->next == NULL) {
            printf("Error! Indice invalido.\n");
            return LL_INVALID_INDEX;
        }
        head = head->next;
    }

    /* 4. Obtengo el valor almacenado en el nodo */
    *value = head->value;

    return LL_SUCCESS;
}

void free_list(LinkedListNode** linkedList) {
    /* 1. Declaro un puntero a LinkedListNode (LinkedListNode*) para almacenar la direccion de comienzo de la lista */
    LinkedListNode* head = *linkedList;

    /* 2. Libero la memoria solicitada al SO nodo a nodo hasta vaciar la lista */
    while (head != NULL) {
        *linkedList = head->next;
        free(head);
        head = *linkedList;
    }
}

void print_list(LinkedListNode* linkedList) {
    /* 1. Declaro un puntero a LinkedListNode (LinkedListNode*) para almacenar la direccion de comienzo de la lista */
    LinkedListNode* head = linkedList;

    /* 2. Imprimo el contenido de la lista nodo a nodo */
    printf("Contenido de la lista: ");
    printf("HEAD --> ");

    while (head != NULL) {
        printf("%d --> ", head->value);
        head = head->next;
    }

    printf("NULL\n");
}
