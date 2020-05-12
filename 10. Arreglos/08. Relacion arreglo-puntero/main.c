/*!
 * @file   main.c
 * @brief  10. Arreglos - 08. Relación arreglo-puntero
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main() {
  // Declaro un arreglo (array) de caracteres (char) de 5 elementos inicializado.
  char array[] = {12, 22, 43, 24, 63};
  int i;

  // Imprimo las direcciones de cada elemento del arreglo, usando índices y punteros.
  for (i = 0; i < 5; i++) {
    printf("Direccion de array[%d] = %p\n", i, &array[i]);
    printf("Valor de (array + %d) = %p\n", i, (array + i));
  }

  // Imprimo los contenidos de cada elemento del arreglo, usando índices y punteros.
  for (i = 0; i < 5; i++) {
    printf("Contenido de array[%d] = %d\n", i, array[i]);
    printf("Valor de *(array + %d) = %d\n", i, *(array + i));
  }

  return 0;
}
