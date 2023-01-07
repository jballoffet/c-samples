/*!
 * @file   vector.c
 * @brief  24. Estructuras de Datos - 01. Vectores
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Jan 4, 2023
 */
#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

Vector* vector_create()
{
    Vector* vector = NULL;

    // Solicito memoria para almacenar los datos del vector.
    vector = (Vector*)malloc(sizeof(Vector));
    if (vector != NULL)
    {
        vector->elements = NULL;
        vector->size = 0;
    }

    return vector;
}

Status vector_add(Vector* vector, Element element)
{
    Element* aux = NULL;

    // Redimensiono el vector.
    aux = (Element*)realloc(vector->elements,
                            (vector->size + 1) * sizeof(Element));
    if (aux == NULL)
    {
        return ERROR_MEMORY_FAILURE;
    }
    vector->elements = aux;

    // Agrego el nuevo elemento e incremento el tamaño del vector.
    vector->elements[vector->size] = element;
    vector->size++;

    return SUCCESS;
}

Status vector_remove(Vector* vector, int position, Element* element)
{
    int i;
    Element* aux = NULL;

    // Chequeo si el vector está vacío.
    if (vector->size == 0)
    {
        return ERROR_EMPTY_VECTOR;
    }

    // Chequeo si la posición es inválida.
    if (position < 0 || position >= vector->size)
    {
        return ERROR_INVALID_POSITION;
    }

    // Retorno por referencia el elemento a remover.
    *element = vector->elements[position];

    // Desplazo los elementos siguientes para poder redimensionar el vector.
    for (i = position; i < (vector->size - 1); i++)
    {
        vector->elements[i] = vector->elements[i + 1];
    }

    // Redimensiono el vector.
    aux = (Element*)realloc(vector->elements,
                            (vector->size - 1) * sizeof(Element));
    if (aux == NULL)
    {
        return ERROR_MEMORY_FAILURE;
    }
    vector->elements = aux;

    // Decremento el tamaño del vector.
    vector->size--;

    return SUCCESS;
}

Status vector_get(const Vector* vector, int position, Element* element)
{
    // Chequeo si el vector está vacío.
    if (vector->size == 0)
    {
        return ERROR_EMPTY_VECTOR;
    }

    // Chequeo si la posición es inválida.
    if (position < 0 || position >= vector->size)
    {
        return ERROR_INVALID_POSITION;
    }

    // Retorno por referencia el elemento a obtener.
    *element = vector->elements[position];

    return SUCCESS;
}

void vector_print(const Vector* vector)
{
    int i;

    // Imprimo los datos almacenados en el vector.
    printf("Contenido: [");
    for (i = 0; i < vector->size - 1; i++)
    {
        printf("%d, ", vector->elements[i].data);
    }
    printf("%d]\n", vector->elements[i].data);

    // Imprimo el tamaño del vector.
    printf("Tamanio: %d\n", vector->size);
}

void vector_destroy(Vector* vector)
{
    // Libero la memoria correspondiente a los elementos agregados.
    if (vector->elements != NULL)
    {
        free(vector->elements);
        vector->elements = NULL;
    }

    // Libero la memoria correspondiente a los datos del vector.
    free(vector);
}
