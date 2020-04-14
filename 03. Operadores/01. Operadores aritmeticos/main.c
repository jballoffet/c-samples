/*!
 * @file   main.c
 * @brief  03. Operadores - 01. Operadores aritméticos
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main() {
  int a = 9, b = 6, c;
  float d;

  printf("Operadores:\n");
  printf("a = %d\n", a);
  printf("b = %d\n", b);

  // Realizo varias operaciones aritmeticas e imprimo el resultado en pantalla.
  printf("Operaciones aritmeticas:\n");

  // Suma (+).
  c = a + b;
  printf("a + b = %d\n", c);
  
  // Resta (-).
  c = a - b;
  printf("a - b = %d\n", c);

  // Multiplicacion (*).
  c = a * b;
  printf("a * b = %d\n", c);

  // Division (/).
  c = a / b;
  printf("a / b = %d\n", c);

  // Resto (%) - Nota: Sólo puede usarse con variables enteras!
  c = a % b;
  printf("Resto de a / b = %d\n", c);

  // ¿Y si quiero el resultado como un numero real? Debo castear! (¡Castear antes de realizar la operacion!)
  // ¡Asi no!
  d = (float) (a / b);
  printf("El resultado real (erroneo) de la division es: %f\n", d);
    
  // ¡Asi si!
  d = ((float) a) / b;
  printf("El resultado real (correcto) de la division es: %f\n", d);

  return 0;
}
