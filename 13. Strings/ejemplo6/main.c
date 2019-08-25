/**
 * \file            main.c
 * \brief           13. Strings - Ejemplo 6 - Uso de strcmp()
 * \author          Javier Balloffet
 * \date            Mar 6, 2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <string.h>

int main() {
    /* 1. Declaro un string sin inicializar */
    char word1[20];
    char word2[20];
    int value;

    /* 2. Ingreso el contenido de los strings por consola */
    printf("Ingrese una palabra: ");
    scanf("%s", word1);
    printf("Ingrese otra palabra: ");
    scanf("%s", word2);

    /* 3. Imprimo el contenido de los strings */
    printf("Primera palabra ingresada: %s\n", word1);
    printf("Segunda palabra ingresada: %s\n", word2);

    /* 4. Comparo ambos strings */
    value = strcmp(word1, word2);

    /* 5. Imprimo resultado de la comparacion */
    if (value == 0) {
        printf("Los strings son iguales\n");
    } else {
        printf("El primer caracter diferente difiere por un valor (en codigo ascii) de: %d\n", value);
    }

	return 0;
}
