/*!
 * @file   algorithms.c
 * @brief  16. Algoritmos - 03. Bubble Sort
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include "algorithms.h"
#include "utils.h"

enum {
  FALSE = 0,
  TRUE
};

void bubble_sort(int array[], int length) {
  int i, j, swapped;

  for (i = 0; i < length - 1; i++) {
    swapped = FALSE;
    for (j = 0; j < length - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        swap(&array[j], &array[j + 1]);
        swapped = TRUE;
      }
    }

    // Si no intercambió nunca, entonces el arreglo ya está ordenado!
    if (swapped == FALSE) {
      break;
    }
  }
}
