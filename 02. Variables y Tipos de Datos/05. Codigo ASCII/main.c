/*!
 * @file   main.c
 * @brief  02. Variables y Tipos de Datos - 05. Codigo ASCII
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main() {
  // Declaro una variable char y le asigno el valor 'A'.
  char letter = 'A';

  // Imprimo el contenido de la variable en pantalla.
  printf("El contenido de letter es %c\n", letter);

  // ¿Y si imprimo un char como un entero? Me muestra el codigo ASCII correspondiente!
  printf("El contenido de letter es %d\n", letter);

  return 0;
}
