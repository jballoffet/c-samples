/*!
 * @file   algorithms.c
 * @brief  16. Algoritmos - 04. Selection Sort
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include "algorithms.h"
#include "utils.h"

void selection_sort(int array[], int length) {
  int i, j, min_index;

  // El límite del arreglo desordenado se corre uno a uno.
  for (i = 0; i < length - 1; i++) {
    // Encuentro el menor elemento en el arreglo desordenado.
    min_index = i;
    for (j = i + 1; j < length; j++) {
      if (array[j] < array[min_index]) {
        min_index = j;
      }
    }

    // Intercambio el mínimo elemento encontrado con el primer elemento del arreglo desordenado.
    swap(&array[min_index], &array[i]);
  }
}
