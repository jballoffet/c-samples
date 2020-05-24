/*!
 * @file   main.c
 * @brief  16. Algoritmos - 02. Binary Search
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>
#include "algorithms.h"

int main() {
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  printf("El numero %d se encuentra en la ubicacion %d\n", 6, binary_search(array, 0, 8, 6));
  printf("El numero %d se encuentra en la ubicacion %d\n", 15, binary_search(array, 0, 8, 15));

  return 0;
}
