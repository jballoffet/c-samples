/*!
 * @file   main.c
 * @brief  04. Estructuras de Control - Decisión - 08. Estructura 'switch-case' con caracter
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main() {
  char option;

  // Solicito una opción por consola.
  printf("Ingrese la opcion deseada:\n");
  printf("a) Opcion 1\n");
  printf("b) Opcion 2\n");
  scanf("%c", &option);

  // Informo por pantalla la opción elegida.
  switch (option) {
    case 'a':
      printf("Usted eligio la opcion 1\n");
      break;
    
    case 'b':
      printf("Usted eligio la opcion 2\n");
      break;

    default:
      printf("Usted eligio una opcion incorrecta\n");
      break;
  }

  return 0;
}
