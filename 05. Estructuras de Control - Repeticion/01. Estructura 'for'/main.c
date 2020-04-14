/*!
 * @file   main.c
 * @brief  05. Estructuras de Control - Repetición - 01. Estructura 'for'
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main() {
  int i;
	
  // Repito el contenido dentro de la estructura 5 veces.
  for (i = 0; i < 5; i++) {
    printf("Mi primer bucle en C! (i = %d)\n", i);
  }

  return 0;
}
