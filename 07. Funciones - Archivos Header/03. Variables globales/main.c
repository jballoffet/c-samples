/*!
 * @file   main.c
 * @brief  07. Funciones - Archivos Header - 03. Variables globales
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>
#include "functions.h"

int main() {
  // Invoco a "increment" y muestro el valor de "number" antes y después de llamar a la función.
  printf("Valor de \"number\" en main() antes de incrementar = %d\n", number); 
  increment();
  printf("Valor de \"number\" en main() despues de incrementar = %d\n", number);
  number++;
  printf("Valor de \"number\" en main() despues de incrementar nuevamente = %d\n", number);

	return 0;
}
