/*!
 * @file   algorithms.c
 * @brief  16. Algoritmos - 05. Insertion Sort
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include "algorithms.h"

void insertion_sort(int array[], int length) {
  int i, j, current_value;

  for (i = 1; i < length; i++) {
    current_value = array[i];
    j = i - 1;

    // Desplazo todos los elementos mayores al actual una posición adelante.
    while (j >= 0 && array[j] > current_value) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = current_value;
  }
}
