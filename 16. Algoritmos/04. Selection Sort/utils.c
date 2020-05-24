/*!
 * @file   utils.c
 * @brief  16. Algoritmos - 04. Selection Sort
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>
#include "utils.h"

void print_array(int array[], int length) {
  int i;

  printf("[");
  for (i = 0; i < length - 1; i++) {
    printf("%d, ", array[i]);
  }
  printf("%d]\n", array[i]);
}

void swap(int* x, int* y) {
  int aux = *x;
  *x = *y;
  *y = aux;
}
