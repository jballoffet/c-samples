/*!
 * @file   main.c
 * @brief  11. Arreglos Multidimensionales - 08. Alocación en memoria de un arreglo multidimensional
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main() {
  // Declaro un arreglo multidimensional (2D array) de caracteres (char) de 2x3 elementos.
  char array2D[2][3];
  int i, j;

  // Imprimo las direcciones de memoria de cada elemento del arreglo.
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++) {
      printf("Direccion de array2D[%d][%d] = %p\n", i, j, &array2D[i][j]);
    }
  }

  // Imprimo el contenido de array2D.
  printf("Contenido de array2D = %p\n", array2D);

  // Imprimo el contenido de array2D[i] (se comporta como un arreglo de punteros).
  for (i = 0; i < 2; i++) {
    printf("Contenido de array2D[%d] = %p\n", i, array2D[i]);
  }

  return 0;
}
