/*!
 * @file   rectangle.h
 * @brief  23. Tipo de Dato Abstracto - 01. Definición y declaración de un TDA
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Dic 29, 2022
 */
#ifndef RECTANGLE_H_
#define RECTANGLE_H_

// Defino un tipo de datos incompleto llamado "Rectangle" a partir del tipo
// "struct Rectangle". Al completar su definición en el archivo fuente (.c), su
// contenido no es accesible por otros módulos (se vuelve un tipo de datos
// abstracto).
typedef struct Rectangle Rectangle;

// API (interfaz de programación de aplicaciones) del tipo de dato abstracto
// Rectangle.
Rectangle* rectangle_create(double width, double height);
void rectangle_destroy(Rectangle* rectangle);
double rectangle_get_width(const Rectangle* rectangle);
double rectangle_get_height(const Rectangle* rectangle);
void rectangle_set_width(Rectangle* rectangle, double width);
void rectangle_set_height(Rectangle* rectangle, double height);
double rectangle_perimeter(const Rectangle* rectangle);
double rectangle_area(const Rectangle* rectangle);

#endif  // RECTANGLE_H_
