/*!
 * @file   main.c
 * @brief  10. Arreglos - 05. Pasaje de un elemento del arreglo a una función
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

void print(int a);

int main() {
  // Declaro un arreglo (array) de enteros (int) de 5 elementos.
  int array[5];
  int i;

  // Cargo el arreglo.
  for (i = 0; i < 5; i++) {
    printf("Ingrese un numero: ");
    scanf("%d", &array[i]);
  }

  // Paso el contenido del arreglo a la función "print" elemento a elemento.
  for (i = 0; i < 5; i++) {
    print(array[i]);
  }

  return 0;
}

void print(int a) {
  printf("[Print] = %d\n", a);
}
