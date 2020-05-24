/*!
 * @file   algorithms.c
 * @brief  16. Algoritmos - 06. Merge Sort
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <string.h>
#include "algorithms.h"

void merge(int array[], int min, int mid, int max);

void merge_sort(int array[], int min, int max) {
  int mid;

  // Max debe ser mayor a min, sino el arreglo está ordenado (tiene un solo elemento).
  if (min < max) {
    mid = (max - min) / 2 + min;

    // Ordeno ambas mitades del arreglo por separado (Algoritmo del tipo "Divide y Conquistarás").
    merge_sort(array, min, mid);
    merge_sort(array, mid + 1, max);

    // Combino ambas mitades preordenadas de forma ordenada.
    merge(array, min, mid, max);
  }
}

void merge(int array[], int min, int mid, int max) {
  int i = 0, j = 0, k = min;
  int length1 = mid - min + 1;
  int length2 = max - mid;
  
  // Creo arreglos temporales.
  int array1[length1], array2[length2];

  // Cargo los arreglos temporales.
  memcpy(array1, &array[min], length1 * sizeof(int));
  memcpy(array2, &array[mid + 1], length2 * sizeof(int));

  // Combino ambos arreglos de forma ordenada.
  while (i < length1 && j < length2) {
    if (array1[i] <= array2[j]) {
      array[k] = array1[i];
      i++;
    } else {
      array[k] = array2[j];
      j++;
    }
    k++;
  }

  // Si los arreglos son de distinto largo, copio los elementos faltantes.
  memcpy(&array[k], &array1[i], (length1 - i) * sizeof(int));
  memcpy(&array[k], &array2[j], (length2 - j) * sizeof(int));
}
