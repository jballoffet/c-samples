/*!
 * @file   main.c
 * @brief  23. Tipo de Dato Abstracto - 01. Definición y declaración de un TDA
 *   (Rectangle)
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Dic 29, 2022
 */
#include <stdio.h>

#include "rectangle.h"

int main(void)
{
    Rectangle* rectangle = NULL;

    // Creo un rectángulo e inicializo su ancho y alto.
    rectangle = rectangle_create(2.0, 3.0);
    if (rectangle == NULL)
    {
        printf("Error! Rectangulo no creado.\n");
        return -1;
    }

    // Imprimo su ancho, alto, perímetro y área.
    printf("Ancho del rectangulo: %f\n", rectangle_get_width(rectangle));
    printf("Alto del rectangulo: %f\n", rectangle_get_height(rectangle));
    printf("Perimetro del rectangulo: %f\n", rectangle_perimeter(rectangle));
    printf("Area del rectangulo: %f\n", rectangle_area(rectangle));

    // Seteo nuevos valores para el ancho y alto del rectángulo.
    rectangle_set_width(rectangle, 2.5);
    rectangle_set_height(rectangle, 4.0);

    // Imprimo nuevamente ancho, alto, perímetro y área del rectángulo.
    printf("Ancho del rectangulo: %f\n", rectangle_get_width(rectangle));
    printf("Alto del rectangulo: %f\n", rectangle_get_height(rectangle));
    printf("Perimetro del rectangulo: %f\n", rectangle_perimeter(rectangle));
    printf("Area del rectangulo: %f\n", rectangle_area(rectangle));

    // Destruyo el rectángulo.
    rectangle_destroy(rectangle);

    return 0;
}
