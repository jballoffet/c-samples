/*!
 * @file   main.c
 * @brief  02. Variables y Tipos de Datos - 02. Ingreso por consola
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main() {
  // Puedo declarar varias variables en una misma línea.
  char myCharacterVariable;
  int myIntegerVariable1, myIntegerVariable2;
  float myRealVariable;
  double myDoublePrecisionRealVariable;

  // Ingreso los valores de las variables por consola.
  printf("Ingrese el valor a almacenar en myCharacterVariable1\n");
  scanf("%c", &myCharacterVariable);
  printf("Ingrese el valor a almacenar en myIntegerVariable1\n");
  scanf("%d", &myIntegerVariable1);
  printf("Ingrese el valor a almacenar en myIntegerVariable2\n");
  scanf("%d", &myIntegerVariable2);
  printf("Ingrese el valor a almacenar en myDecimalVariable\n");
  scanf("%f", &myRealVariable);
  printf("Ingrese el valor a almacenar en myDoublePrecisionRealVariable\n");
  scanf("%lf", &myDoublePrecisionRealVariable);

  // Imprimo el contenido de las variables en pantalla.
  printf("El contenido de myCharacterVariable es %c\n", myCharacterVariable);
  printf("El contenido de myIntegerVariable1 es %d\n", myIntegerVariable1);
  printf("El contenido de myIntegerVariable2 es %d\n", myIntegerVariable2);
  printf("El contenido de myRealVariable es %f\n", myRealVariable);
  printf("El contenido de myDoublePrecisionRealVariable es %lf\n", myDoublePrecisionRealVariable);

  return 0;
}
