/*!
 * @file   vector.h
 * @brief  24. Estructuras de Datos - 01. Vectores
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Jan 4, 2023
 */
#ifndef VECTOR_H_
#define VECTOR_H_

typedef struct Element
{
    int data;
} Element;

typedef struct Vector
{
    Element* elements;
    int size;
} Vector;

typedef enum Status
{
    SUCCESS = 0,
    ERROR_MEMORY_FAILURE,
    ERROR_INVALID_POSITION,
    ERROR_EMPTY_VECTOR
} Status;

// @brief Crea un vector.
Vector* vector_create();

// @brief Agrega un elemento en el vector.
Status vector_add(Vector* vector, Element element);

// @brief Quita el elemento presente en la posición indicada.
Status vector_remove(Vector* vector, int position);

// @brief Devuelve el valor del elemento presente en la posición indicada.
Status vector_get(const Vector* vector, int position, Element* element);

// @brief Imprime el contenido del vector.
void vector_print(const Vector* vector);

// @brief Destruye el vector.
void vector_destroy(Vector* vector);

#endif  // VECTOR_H_
