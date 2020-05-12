/*!
 * @file   main.c
 * @brief  11. Arreglos Multidimensionales - 01. Declaración de arreglos multidimensionales
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main() {
  // Declaro un arreglo multidimensional (2D array) de enteros (int) de 2x3 elementos.
  int array2D[2][3];
  
  // Inicializo el arreglo.
  array2D[0][0] = 3;
  array2D[0][1] = 24;
  array2D[0][2] = -12;
  array2D[1][0] = 5;
  array2D[1][1] = 0;
  array2D[1][2] = 36;

  // Imprimo el contenido del arreglo.
  printf("Valor de array[0][0] = %d\n", array2D[0][0]);
  printf("Valor de array[0][1] = %d\n", array2D[0][1]);
  printf("Valor de array[0][2] = %d\n", array2D[0][2]);
  printf("Valor de array[1][0] = %d\n", array2D[1][0]);
  printf("Valor de array[1][1] = %d\n", array2D[1][1]);
  printf("Valor de array[1][2] = %d\n", array2D[1][2]);

  // Imprimo el tamaño del arreglo (en bytes).
  printf("Tamanio del arreglo (en bytes) = %ld\n", sizeof(array2D));

  // Imprimo el tamaño del arreglo (en cantidad de elementos).
  printf("Tamanio del arreglo (en cantidad de elementos) = %ld\n", sizeof(array2D) / sizeof(int));

  return 0;
}
