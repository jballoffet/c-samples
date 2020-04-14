/*!
 * @file   main.c
 * @brief  05. Estructuras de Control - Repetición - 05. Sentencia 'break'
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main() {
  int number, i;

  // Solicito 10 números por consola. Si se ingresa un número negativo, sale del bucle.
  for (i = 0; i < 10; i++) {
    printf("Ingrese un numero: ");
    scanf("%d", &number);

    if (number < 0) {
      break;
    }
  }

  return 0;
}
