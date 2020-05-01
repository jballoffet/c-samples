/*!
 * @file   main.c
 * @brief  06. Funciones - Argumentos por Valor - 07. Variables 'static'
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

void increment1();
void increment2();

int main() {
  // Invoco a "increment1()" dos veces seguidas.
  increment1();
  increment1();

  // Invoco a "increment2()" dos veces seguidas.
  increment2();
  increment2(); 

	return 0;
}

void increment1() {
  // Declaro la variable "number".
  int number = 1;

  // Muestro el valor de "number" antes y después de incrementar.
  printf("Valor de \"number\" en increment1() antes de incrementar = %d\n", number);
  number++;
  printf("Valor de \"number\" en increment1() despues de incrementar = %d\n", number); 
}

void increment2() {
  // Declaro la variable "number" como static.
  static int number = 1;

  // Muestro el valor de "number" antes y después de incrementar.
  printf("Valor de \"number\" en increment2() antes de incrementar = %d\n", number);
  number++;
  printf("Valor de \"number\" en increment2() despues de incrementar = %d\n", number); 
}
