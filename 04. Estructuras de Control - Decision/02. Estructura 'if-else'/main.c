/*!
 * @file   main.c
 * @brief  04. Estructuras de Control - Decisión - 02. Estructura 'if-else'
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main() {
  int number;
	
  // Solicito un número por consola.
  printf("Ingrese un numero: ");
  scanf("%d", &number);

  // Informo por pantalla si el número ingresado es negativo o no.
  if (number < 0) {
    printf("El numero ingresado es negativo\n");
  } else {
    printf("El numero ingresado no es negativo\n");
  }

  return 0;
}
