/*!
 * @file   vector.c
 * @brief  24. Estructuras de Datos - 01. Vectores
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Jan 4, 2023
 */
#include "vector.h"

#include <stdio.h>

Vector* vector_create()
{
    Vector* vector = NULL;
    return vector;
}

Status vector_add(Vector* vector, Element element)
{
    return SUCCESS;
}

Status vector_remove(Vector* vector, int position)
{
    return SUCCESS;
}

Status vector_get(const Vector* vector, int position, Element* element)
{
    return SUCCESS;
}

void vector_print(const Vector* vector) {}

void vector_destroy(Vector* vector) {}
