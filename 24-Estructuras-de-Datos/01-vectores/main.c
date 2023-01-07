/*!
 * @file   main.c
 * @brief  24. Estructuras de Datos - 01. Vectores
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Jan 4, 2023
 */
#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

int main(void)
{
    Vector* vector = NULL;
    Element element;
    int i;

    // Creo un vector como un tipo de dato abstracto.
    vector = vector_create();
    if (vector == NULL)
    {
        printf("Error! Vector no creado.\n");
        return -1;
    }

    // Agrego los números del 1 al 10 al vector.
    for (i = 1; i <= 10; i++)
    {
        element.data = i;
        vector_add(vector, element);
        vector_print(vector);
    }

    // Remuevo el elemento en la sexta posición del vector.
    vector_remove(vector, 6, &element);
    printf("Valor removido de la posicion 6: %d\n", element.data);
    vector_print(vector);

    // Obtengo el valor del elemento en la tercera posición del vector (sin
    // removerlo).
    vector_get(vector, 3, &element);
    printf("Valor obtenido de la posicion 3: %d\n", element.data);
    vector_print(vector);

    // Destruyo el vector.
    vector_destroy(vector);
    return 0;
}
