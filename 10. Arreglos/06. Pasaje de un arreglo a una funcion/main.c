/*!
 * @file   main.c
 * @brief  10. Arreglos - 06. Pasaje de un arreglo a una función
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

float average(int arr[], int length);

int main() {
  // Declaro un arreglo (array) de enteros (int) de 5 elementos.
  int array[5];
  int i;
  float avg;

  // Cargo el arreglo.
  for (i = 0; i < 5; i++) {
    printf("Ingrese un numero: ");
    scanf("%d", &array[i]);
  }

  /* Paso el arreglo (puntero) a la función "average" para calcular el promedio.
     Nota: En los arreglos numéricos DEBO pasar la longitud para saber donde finaliza el mismo. */
  avg = average(array, 5);

  // Imprimo el promedio.
  printf("Promedio del arreglo = %.2f\n", avg);

  return 0;
}

float average(int arr[], int length) {
  int i, sum = 0;
  float avg;

  // Recorro el arreglo recibido, sumando el valor de todas las posiciones y luego calculo el promedio.
  for (i = 0; i < length; i++) {
    sum += arr[i];
  }
  avg = (float) sum / length;

  return avg;
}
