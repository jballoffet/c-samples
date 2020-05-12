/*!
 * @file   main.c
 * @brief  11. Arreglos Multidimensionales - 04. Escritura y lectura de arreglos multidimensionales
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main() {
  // Declaro un arreglo multidimensional (2D array) de enteros (int) de 2x3 elementos.
  int array2D[2][3];
  int i, j;

  // Cargo el arreglo.
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++) {
      printf("Ingrese un numero: ");
      scanf("%d", &array2D[i][j]);
    }
  }

  // Imprimo el contenido del arreglo.
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++) {
      printf("Valor de array2D[%d][%d] = %d\n", i, j, array2D[i][j]);
    }
  }

  return 0;
}
