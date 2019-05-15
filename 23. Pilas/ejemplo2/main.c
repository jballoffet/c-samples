/**
 * \file            main.c
 * \brief           23. Pilas - Ejemplo 2 - Implementación sencilla de una pila (2)
 * \author          Javier Balloffet
 * \date            Mar 16, 2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include "stack.h"

int main() {
    /* 1. Declaro una Pila (Stack). La misma es un puntero al primer nodo */
    StackNode* stack = NULL;
    int i, value;

    /* 2. Pusheo los números del 1 al 5 */
    for (i = 1; i <= 5; i++) {
        if (push(&stack, i) != SS_SUCCESS) {
            printf("Error! Memoria no asignada.\n");
            return -1;
        }
        print_stack(stack);
    }

    /* 3. Popeo un nodo */
    if (pop(&stack, &value) == SS_SUCCESS) {
        printf("Valor obtenido (popeado): %d\n", value);
    } else {
        printf("Error! La pila esta vacia.\n");
    }
    print_stack(stack);

    /* 4. Observo el valor del próximo nodo a popear (sin popearlo) */
    if (peek(stack, &value) == SS_SUCCESS) {
        printf("Valor obtenido (sin popear): %d\n", value);
    } else {
        printf("Error! La pila esta vacia.\n");
    }
    print_stack(stack);

    /* 5. Popeo un nodo */
    if (pop(&stack, &value) == SS_SUCCESS) {
        printf("Valor obtenido (popeado): %d\n", value);
    } else {
        printf("Error! La pila esta vacia.\n");
    }
    print_stack(stack);

    /* 6. Libero la memoria de la pila completa */
    free_stack(&stack);
    print_stack(stack);

    /* 7. Intento popear de una pila vacía */
    if (pop(&stack, &value) == SS_SUCCESS) {
        printf("Valor obtenido (popeado): %d\n", value);
    } else {
        printf("Error! La pila esta vacia.\n");
    }
    print_stack(stack);

	return 0;
}
