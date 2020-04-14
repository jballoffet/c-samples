/*!
 * @file   main.c
 * @brief  03. Operadores - 08. Operador sizeof()
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main() {
  int a;
  float b;
  double c;
  char d;

  // Realizo la operación sizeof().
  printf("Tamanio de variable entera (int) = %ld bytes\n", sizeof(a));
  printf("Tamanio de variable real (float) = %ld bytes\n", sizeof(b));
  printf("Tamanio de variable real de doble precision (double) = %ld bytes\n", sizeof(c));
  printf("Tamanio de variable caracter (char) = %ld byte\n", sizeof(d));

  return 0;
}
