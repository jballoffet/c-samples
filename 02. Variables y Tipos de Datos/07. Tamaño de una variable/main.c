/*!
 * @file   main.c
 * @brief  02. Variables y Tipos de Datos - 07. Tamaño de una variable
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main() {
  // Declaro distintos tipos de variables.
  char myCharacterVariable;
  int myIntegerVariable1;
  short int myIntegerVariable2;       // Nota: "short int" es igual a escribir "short".
  long int myIntegerVariable3;        // Nota: "long int" es igual a escribir "long".
  long long int myIntegerVariable4;   // Nota: "long long int" es igual a escribir "long long".
  float myRealVariable;
  double myDoublePrecisionRealVariable1;
  long double myDoublePrecisionRealVariable2;

  // ¿Cuánto puedo almacenar en cada tipo de variable?
  printf("Variables enteras:\n");
  printf("-> sizeof(char) = %ld bytes\n", sizeof(myCharacterVariable));
  printf("-> sizeof(int) = %ld bytes\n", sizeof(myIntegerVariable1));
  printf("-> sizeof(short int) = %ld bytes\n", sizeof(myIntegerVariable2));
  printf("-> sizeof(long int) = %ld bytes\n", sizeof(myIntegerVariable3));
  printf("-> sizeof(long long int) = %ld bytes\n", sizeof(myIntegerVariable4));

  printf("Variables reales:\n");
  printf("-> sizeof(float) = %ld bytes\n", sizeof(myRealVariable));
  printf("-> sizeof(double) = %ld bytes\n", sizeof(myDoublePrecisionRealVariable1));
  printf("-> sizeof(long double) = %ld bytes\n", sizeof(myDoublePrecisionRealVariable2));

  return 0;
}
