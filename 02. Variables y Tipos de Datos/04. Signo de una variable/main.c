/*!
 * @file   main.c
 * @brief  02. Variables y Tipos de Datos - 04. Signo de una variable
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main() {
  // Declaro variables enteras (int) con diferentes modificadores de signo.
  signed int signedNumber;
  unsigned int unsignedNumber;

  // Asigno a ambas variables el número anterior a 0.
  signedNumber = 0 - 1;
  unsignedNumber = 0 - 1;

  // Imprimo el contenido de las variables en pantalla.
  printf("El contenido de signedNumber es %d\n", signedNumber);
  printf("El contenido de unsignedNumber es %u\n", unsignedNumber);

  return 0;
}
