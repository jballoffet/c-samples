/*!
 * @file   main.c
 * @brief  05. Estructuras de Control - Repetición - 03. Estructura 'while'
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main() {
  // ¡Debo inicializar el valor de "number" antes de preguntar en el while!
  int number = 1;

  // Solicito números por consola hasta que se ingrese cero.
  while (number != 0) {
    printf("Ingrese un numero (ingrese 0 para salir): ");
    scanf("%d", &number);
  }

  return 0;
}
