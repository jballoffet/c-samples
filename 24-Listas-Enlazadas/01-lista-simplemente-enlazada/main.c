/*!
 * @file   main.c
 * @brief  24. Listas Enlazadas - 01. Lista Simplemente Enlazada
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Mar 16, 2019
 */
#include <stdio.h>

#include "linked_list.h"

int main(void)
{
    // Declaro una Lista Simplemente Enlazada (LinkedList). La misma es un
    // puntero al primer nodo.
    LinkedListNode* linkedList = NULL;
    int i, value;

    // Inserto los números del 1 al 5 al principio de la lista.
    for (i = 1; i <= 5; i++)
    {
        insert_head(&linkedList, i);
        print_list(linkedList);
    }

    // Inserto los números del 6 al 10 al final de la lista.
    for (i = 6; i <= 10; i++)
    {
        insert_tail(&linkedList, i);
        print_list(linkedList);
    }

    // Inserto el número 11 en la cuarta posición de la lista.
    insert_at(&linkedList, 11, 4);
    print_list(linkedList);

    // Remuevo un nodo del principio de la lista.
    remove_head(&linkedList, &value);
    printf("Valor obtenido (removido): %d\n", value);
    print_list(linkedList);

    // Remuevo un nodo del final de la lista.
    remove_tail(&linkedList, &value);
    printf("Valor obtenido (removido): %d\n", value);
    print_list(linkedList);

    // Remuevo el nodo en la sexta posición de la lista.
    remove_at(&linkedList, &value, 6);
    printf("Valor obtenido (removido): %d\n", value);
    print_list(linkedList);

    // Observo el valor del nodo en la quinta posición de la lista (sin
    // removerlo).
    peek(linkedList, &value, 5);
    printf("Valor obtenido (sin remover): %d\n", value);
    print_list(linkedList);

    // Busco (si existe) el índice correspondiente al nodo de valor 3 en la
    // lista (sin removerlo).
    search(linkedList, 3, &value);
    printf("Indice obtenido (sin remover): %d\n", value);
    print_list(linkedList);

    // Libero la memoria de la lista completa.
    free_list(&linkedList);
    print_list(linkedList);

    return 0;
}
