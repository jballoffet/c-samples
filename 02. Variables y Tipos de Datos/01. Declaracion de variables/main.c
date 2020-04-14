/*!
 * @file   main.c
 * @brief  02. Variables y Tipos de Datos - 01. Declaración de variables
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main() {
  // Declaro las variables.
  char myCharacterVariable;
  int myIntegerVariable;
  float myRealVariable;
  double myDoublePrecisionRealVariable;

  // Asigno las variables.
  myCharacterVariable = 'J';
  myIntegerVariable = 5;
  myRealVariable = 2.5;
  myDoublePrecisionRealVariable = 3.14159;

  // Imprimo el contenido de las variables en pantalla.
  printf("El contenido de myCharacterVariable es %c\n", myCharacterVariable);
  printf("El contenido de myIntegerVariable es %d\n", myIntegerVariable);
  printf("El contenido de myRealVariable es %f\n", myRealVariable);
  printf("El contenido de myDoublePrecisionRealVariable es %lf\n", myDoublePrecisionRealVariable);

  // ¿Cuánta memoria ocupa cada tipo de variable?
  printf("Una variable caracter (char) tiene %ld bytes de largo\n", sizeof(char));
  printf("Una variable entera (int) tiene %ld bytes de largo\n", sizeof(int));
  printf("Una variable real (float) tiene %ld bytes de largo\n", sizeof(float));
  printf("Una variable real de doble precision (double) tiene %ld bytes de largo\n", sizeof(double));

  return 0;
}
