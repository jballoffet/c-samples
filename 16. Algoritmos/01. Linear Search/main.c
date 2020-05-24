/*!
 * @file   main.c
 * @brief  16. Algoritmos - 01. Linear Search
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>
#include "algorithms.h"

int main() {
  int array[] = {8, 3, 5, 9, 6, 1, 2, 4, 7};

  printf("El numero %d se encuentra en la ubicacion %d\n", 6, linear_search(array, 9, 6));
  printf("El numero %d se encuentra en la ubicacion %d\n", 15, linear_search(array, 9, 15));

  return 0;
}
