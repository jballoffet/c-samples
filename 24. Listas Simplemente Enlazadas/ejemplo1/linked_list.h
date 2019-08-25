/**
 * \file            linked_list.h
 * \brief           24. Listas Simplemente Enlazadas - Ejemplo 1 - Implementación sencilla de una lista simplemente enlazada
 * \author          Javier Balloffet
 * \date            Mar 16, 2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct LinkedListNode {
    int value;
    struct LinkedListNode* next;
} LinkedListNode;

typedef enum {
    LL_SUCCESS = 0,
    LL_MEMORY_ERROR,
    LL_EMPTY_LIST,
    LL_INVALID_INDEX,
    LL_INVALID_VALUE
} LinkedListStatus;

LinkedListStatus insert_head(LinkedListNode** linkedList, int value);
LinkedListStatus insert_tail(LinkedListNode** linkedList, int value);
LinkedListStatus insert_at(LinkedListNode** linkedList, int value, int index);
LinkedListStatus remove_head(LinkedListNode** linkedList, int* value);
LinkedListStatus remove_tail(LinkedListNode** linkedList, int* value);
LinkedListStatus remove_at(LinkedListNode** linkedList, int* value, int index);
LinkedListStatus search(LinkedListNode* linkedList, int value, int* index);
LinkedListStatus peek(LinkedListNode* linkedList, int* value, int index);
void free_list(LinkedListNode** linkedList);
void print_list(LinkedListNode* linkedList);

#endif /* LINKED_LIST_H_ */
