/*!
 * @file   main.c
 * @brief  11. Arreglos Multidimensionales - 09. Relacion arreglo multidimensional-puntero
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main() {
  // Declaro un arreglo multidimensional (2D array) de caracteres (char) de 2x3 elementos.
  char array2D[2][3] = {{3, 24, -12}, {5, 0, 36}};
  int i, j;

  // Imprimo las direcciones de cada elemento del arreglo, usando índices y punteros.
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++) {
      printf("Direccion de array[%d][%d] = %p\n", i, j, &array2D[i][j]);
      printf("Valor de (array2D[%d] + %d) = %p\n", i, j, (array2D[i] + j));
      printf("Valor de (*(array2D + %d) + %d) = %p\n", i, j, (*(array2D + i) + j));
    }
  }

  // Imprimo los contenidos de cada elemento del arreglo, usando índices y punteros.
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++) {
      printf("Contenido de array[%d] = %d\n", i, array2D[i][j]);
      printf("Valor de *(array2D[%d] + %d) = %d\n", i, j, *(array2D[i] + j));
      printf("Valor de *(*(array2D + %d) + %d) = %d\n", i, j, *(*(array2D + i) + j));
    }
  }

  return 0;
}
