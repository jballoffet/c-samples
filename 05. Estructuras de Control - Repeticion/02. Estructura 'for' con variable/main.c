/*!
 * @file   main.c
 * @brief  05. Estructuras de Control - Repetición - 02. Estructura 'for' con variable
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main() {
  int number, i;

  // Solicito un número por consola.
  printf("Ingrese un numero: ");
  scanf("%d", &number);
	
  // Repito el contenido dentro de la estructura N veces.
  for (i = 0; i < number; i++) {
    printf("Mi primer bucle en C! (i = %d)\n", i);
  }

  return 0;
}
