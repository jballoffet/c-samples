/*!
 * @file   main.c
 * @brief  12. Memoria Dinamica - 04. Uso de realloc()
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declaro un puntero a entero (int*) donde guardar la direccion de memoria asignada.
  int* pointer;
  // Declaro un puntero auxiliar para la re-alocación de memoria.
  int* aux;
  int length1, length2, length3, i;

  // Largo inicial del arreglo dinámico.
  length1 = 5;
  printf("Largo del array = %d\n", length1);

  // Solicito memoria al SO equivalente a N variables de tipo int (length).
  pointer = (int*) malloc(length1 * sizeof(int));

  // Chequeo si la asignacion de memoria fue exitosa.
  if (pointer == NULL) {
    printf("Error! Memoria no asignada.\n");
    return -1;
  }

  printf("Memoria asignada correctamente en la posición de memoria %p.\n", pointer);

  // Cargo el arreglo.
  for (i = 0; i < length1; i++) {
    printf("Ingrese un numero: ");
    scanf("%d", pointer + i);
  }

  // Imprimo el contenido del arreglo.
  for (i = 0; i < length1; i++) {
    printf("Valor de array[%d] = %d\n", i, *(pointer + i));
  }

  // Modifico el largo del arreglo dinámico.
  length2 = 10;
  printf("Largo del array = %d\n", length2);

  // Solicito memoria al SO equivalente a N variables de tipo int (length).
  aux = (int*) realloc(pointer, length2 * sizeof(int));

  // Chequeo si la asignacion de memoria fue exitosa.
  if (aux == NULL) {
    printf("Error! Memoria no asignada.\n");

    // Debo liberar la anterior alocación de memoria.
    free(pointer);
    return -1;
  }

  pointer = aux;
  printf("Memoria asignada correctamente en la posición de memoria %p.\n", pointer);

  // Cargo las nuevas posiciones agregadas al arreglo dinámico.
  for (i = length1; i < length2; i++) {
    printf("Ingrese un numero: ");
    scanf("%d", pointer + i);
  }

  // Imprimo el contenido del arreglo.
  for (i = 0; i < length2; i++) {
    printf("Valor de array[%d] = %d\n", i, *(pointer + i));
  }

  // Modifico el largo del arreglo dinámico.
  length3 = 3;
  printf("Largo del array = %d\n", length3);

  // Solicito memoria al SO equivalente a N variables de tipo int (length).
  aux = (int*) realloc(pointer, length3 * sizeof(int));

  // Chequeo si la asignacion de memoria fue exitosa.
  if (aux == NULL) {
    printf("Error! Memoria no asignada.\n");

    // Debo liberar la anterior alocación de memoria.
    free(pointer);
    return -1;
  }

  pointer = aux;
  printf("Memoria asignada correctamente en la posición de memoria %p.\n", pointer);

  // Imprimo el contenido del arreglo.
  for (i = 0; i < length3; i++) {
    printf("Valor de array[%d] = %d\n", i, *(pointer + i));
  }

  // Devuelvo la memoria solicitada.
  free(pointer);

  return 0;
}
