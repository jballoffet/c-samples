/**
 * \file            main.c
 * \brief           13. Strings - Ejemplo 1 - Declaración de strings
 * \author          Javier Balloffet
 * \date            05-MAR-2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    int i;

    /* 1. Declaro un string (array) de caracteres (char) de varias maneras diferentes */
    char name1[7] = "Javier";
    char name2[] = "Javier";
    char name3[7] = {'J', 'a', 'v', 'i', 'e', 'r', '\0'};
    char name4[] = {'J', 'a', 'v', 'i', 'e', 'r', '\0'};

    /* 2. Imprimo el contenido de los strings */
    printf("Valor de name1 = %s\n", name1);
    printf("Valor de name2 = %s\n", name2);
    printf("Valor de name3 = %s\n", name3);
    printf("Valor de name4 = %s\n", name4);

    /* 3. Imprimo el tamaño de los strings (en bytes) */
    printf("Tamanio de name1 = %ld\n", sizeof(name1));
    printf("Tamanio de name2 = %ld\n", sizeof(name2));
    printf("Tamanio de name3 = %ld\n", sizeof(name3));
    printf("Tamanio de name4 = %ld\n", sizeof(name4));

    /* 4. Imprimo el tamaño de los strings (en cantidad de caracteres) */
    printf("Tamanio de name1 (en cantidad de caracteres) = %ld\n", sizeof(name1) / sizeof(char));
    printf("Tamanio de name2 (en cantidad de caracteres) = %ld\n", sizeof(name2) / sizeof(char));
    printf("Tamanio de name3 (en cantidad de caracteres) = %ld\n", sizeof(name3) / sizeof(char));
    printf("Tamanio de name4 (en cantidad de caracteres) = %ld\n", sizeof(name4) / sizeof(char));

    /* 5. Imprimo un string caracter a caracter */
    for (i = 0; i < 7; i++) {
        printf("Contenido de name1[%d] = %c\n", i, name1[i]);
        printf("Contenido de name1[%d] (codigo ascii decimal) = %d\n", i, name1[i]);
    }

	return 0;
}
