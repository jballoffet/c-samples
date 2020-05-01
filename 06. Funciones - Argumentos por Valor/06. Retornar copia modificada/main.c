/*!
 * @file   main.c
 * @brief  06. Funciones - Argumentos por Valor - 06. Retornar copia modificada
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int increment(int a);

int main() {
  int number = 1;

  // Invoco a "increment" y muestro el valor de "number" antes y después de llamar a la función.
  printf("Valor de \"number\" en main() antes de incrementar = %d\n", number); 
  number = increment(number);
  printf("Valor de \"number\" en main() despues de incrementar = %d\n", number); 

	return 0;
}

int increment(int a) {
  return ++a;
}
