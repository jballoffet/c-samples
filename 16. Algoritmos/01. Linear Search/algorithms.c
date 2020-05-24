/*!
 * @file   algorithms.c
 * @brief  16. Algoritmos - 01. Linear Search
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */

int linear_search(int array[], int length, int value) {
  int i = 0;

  // Busco de forma lineal a lo largo de todo el arreglo el valor solicitado.
  for (i = 0; i < length; i++) {
    if (array[i] == value) {
      // Encontré dónde está el valor a buscar!
      return i;
    }
  }

  // Retorno -1 si el valor a buscar no se encuentra en el arreglo.
  return -1;
}
