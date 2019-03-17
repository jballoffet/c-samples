/**
 * \file            main.c
 * \brief           13. Strings - Ejemplo 5 - Uso de strlen()
 * \author          Javier Balloffet
 * \date            06-MAR-2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <string.h>

int main() {
    /* 1. Declaro un string sin inicializar */
    char word[20];
    int length;

    /* 2. Ingreso el contenido del string por consola */
    printf("Ingrese una palabra: ");
    scanf("%s", word);

    /* 3. Imprimo el contenido del string */
    printf("Palabra ingresada: %s\n", word);

    /* 4. Imprimo el largo del string */
    length = strlen(word);
    printf("Largo de la palabra ingresada: %d\n", length);

	return 0;
}
