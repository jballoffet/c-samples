/*!
 * @file   main.c
 * @brief  06. Funciones - Argumentos por Valor - 02. Scope o alcance de una variable
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

void increment(int number);

int main() {
  int number = 1;

  // Invoco a "increment" y muestro el valor de "number" antes y después de llamar a la función.
  printf("Valor de \"number\" en main() antes de incrementar = %d\n", number); 
  increment(number);
  printf("Valor de \"number\" en main() despues de incrementar = %d\n", number); 

	return 0;
}

void increment(int number) {
  printf("Valor de \"number\" en increment() antes de incrementar = %d\n", number);
  number++;
  printf("Valor de \"number\" en increment() despues de incrementar = %d\n", number); 
}
