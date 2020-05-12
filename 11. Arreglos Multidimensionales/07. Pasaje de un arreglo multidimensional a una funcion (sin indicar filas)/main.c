/*!
 * @file   main.c
 * @brief  11. Arreglos Multidimensionales - 07. Pasaje de un arreglo multidimensional a una función (sin indicar filas)
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

float average(int arr[][3], int rows, int columns);

int main() {
  // Declaro un arreglo multidimensional (2D array) de enteros (int) de 2x3 elementos.
  int array2D[2][3];
  int i, j;
  float avg;

  // Cargo el arreglo.
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++) {
      printf("Ingrese un numero: ");
      scanf("%d", &array2D[i][j]);
    }
  }

  /* Paso el arreglo a la función "average" para calcular el promedio.
     Nota: En los arreglos numéricos DEBO pasar la longitud para saber donde finaliza el mismo. */
  avg = average(array2D, 2, 3);

  // Imprimo el promedio.
  printf("Promedio del array = %.2f\n", avg);

  return 0;
}

float average(int arr[][3], int rows, int columns) {
  int i, j, sum = 0;
  float avg;

  // Recorro el array recibido, sumando el valor de todos los elementos y luego calculo el promedio.
  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      sum += arr[i][j];
    }
  }
  avg = (float) sum / (rows * columns);

  return avg;
}
