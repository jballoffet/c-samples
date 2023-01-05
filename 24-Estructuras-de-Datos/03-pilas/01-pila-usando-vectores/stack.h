/*!
 * @file   stack.h
 * @brief  24. Estructuras de Datos - 03. Pilas - 01. Pila usando vectores
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Jan 4, 2023
 */
#ifndef STACK_H_
#define STACK_H_

typedef struct Element
{
    int data;
} Element;

typedef struct Stack
{
    Element* elements;
    int size;
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
Status stack_push(Stack* pila, Element element);

// @brief Quita un elemento de la pila.
Status stack_pop(Stack* pila, Element* element);

// @brief Devuelve el valor del próximo elemento a quitar de la pila (sin
// quitarlo).
Status stack_peek(Stack* pila, Element* element);

// @brief Imprime el contenido de la pila.
void stack_print(Stack* pila);

// @brief Destruye la pila.
void stack_destroy(Stack* pila);

#endif  // STACK_H_
