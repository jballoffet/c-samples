/*!
 * @file   rectangle.c
 * @brief  23. Tipo de Dato Abstracto - 01. Definición y declaración de un TDA
 *   (Rectangle)
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Dic 29, 2022
 */
#include "rectangle.h"

#include <stdlib.h>

// Defino un tipo de datos estructura llamado "struct Rectangle". Al estar
// definido en el archivo fuente (.c), su contenido no es accesible por otros
// módulos (se vuelve un tipo de datos abstracto). En el archivo header (.h) se
// encuentra definido el tipo "Rectangle" a partir de "struct Rectangle".
struct Rectangle
{
    double width;
    double height;
};

Rectangle* rectangle_create(double width, double height)
{
    Rectangle* rectangle = NULL;

    // Solicito memoria para almacenar la estructura de datos.
    rectangle = malloc(sizeof(Rectangle));
    if (rectangle == NULL)
    {
        return NULL;
    }

    // Inicializo la estructura conforme los valores pasados como argumentos.
    rectangle->width = width;
    rectangle->height = height;
    return rectangle;
}

void rectangle_destroy(Rectangle* rectangle)
{
    // Libero la memoria previamente solicitada.
    free(rectangle);
}

double rectangle_get_width(const Rectangle* rectangle)
{
    // Devuelvo el ancho del rectángulo.
    return rectangle->width;
}

double rectangle_get_height(const Rectangle* rectangle)
{
    // Devuelvo el alto del rectángulo.
    return rectangle->height;
}

void rectangle_set_width(Rectangle* rectangle, double width)
{
    // Seteo el ancho del rectángulo conforme al valor recibido.
    rectangle->width = width;
}

void rectangle_set_height(Rectangle* rectangle, double height)
{
    // Seteo el alto del rectángulo conforme al valor recibido.
    rectangle->height = height;
}

double rectangle_perimeter(const Rectangle* rectangle)
{
    // Computo el perímetro del rectángulo.
    return rectangle->width * 2 + rectangle->height * 2;
}

double rectangle_area(const Rectangle* rectangle)
{
    // Computo el área del rectángulo.
    return rectangle->width * rectangle->height;
}
