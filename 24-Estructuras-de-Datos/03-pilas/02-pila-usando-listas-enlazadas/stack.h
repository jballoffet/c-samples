/*!
 * @file   stack.h
 * @brief  24. Estructuras de Datos - 03. Pilas - 02. Pila usando listas
 *   enlazadas
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Jan 8, 2023
 */
#ifndef STACK_H_
#define STACK_H_

typedef struct Element
{
    int data;
} Element;

typedef struct Node
{
    Element element;
    struct Node* next;
} Node;

typedef struct Stack
{
    Node* head;
} Stack;

typedef enum Status
{
    SUCCESS = 0,
    ERROR_MEMORY_FAILURE,
    ERROR_EMPTY_STACK
} Status;

// @brief Crea una pila.
Stack* stack_create();

// @brief Inserta un elemento en la pila.
Status stack_push(Stack* stack, Element element);

// @brief Quita un elemento de la pila.
Status stack_pop(Stack* stack, Element* element);

// @brief Devuelve el valor del próximo elemento a quitar de la pila (sin
// quitarlo).
Status stack_peek(Stack* stack, Element* element);

// @brief Imprime el contenido de la pila.
void stack_print(Stack* stack);

// @brief Destruye la pila.
void stack_destroy(Stack* stack);

#endif  // STACK_H_
