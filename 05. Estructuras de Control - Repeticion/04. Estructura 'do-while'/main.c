/*!
 * @file   main.c
 * @brief  05. Estructuras de Control - Repetición - 04. Estructura 'do-while'
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main() {
  // No hace falta inicializar el valor de "number" ya que primero asigno y luego pregunto.
  int number;

  // Solicito números por consola hasta que se ingrese cero.
  do {
    printf("Ingrese un numero (ingrese 0 para salir): ");
    scanf("%d", &number);
  } while (number != 0);

  return 0;
}
