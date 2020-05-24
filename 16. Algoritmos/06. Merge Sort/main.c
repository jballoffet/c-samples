/*!
 * @file   main.c
 * @brief  16. Algoritmos - 06. Merge Sort
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>
#include "algorithms.h"
#include "utils.h"

int main() {
  int array[] = {8, 3, 5, 9, 6, 1, 2, 4, 7};

  printf("Contenido del arreglo (original): ");
  print_array(array, 9);

  // Ordeno el arreglo utilizando el método Merge Sort.
  merge_sort(array, 0, 8);

  printf("Contenido del arreglo (obtenido): ");
  print_array(array, 9);

  return 0;
}
