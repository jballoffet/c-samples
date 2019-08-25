/**
 * \file            main.c
 * \brief           14. Argumentos del main - Ejemplo 2 - Declaración de main con argumentos (2)
 * \author          Javier Balloffet
 * \date            May 15, 2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main(int argc, char* argv[]) {
    int i;

    /* 1. Imprimo nombre del programa */
    printf("Nombre del programa (argv[0]): %s\n", argv[0]);

    /* 2. Chequeo si hay argumentos extra pasados */
    if (argc == 1) {
        /* 3. No hay más argumentos :( */
        printf("No hay argumentos extra pasados\n");
    } else {
        /* 4. Hay más argumentos :) */
        printf("Cantidad de argumentos extra pasados: %d\n", argc - 1);
        printf("Argumentos extra pasados:\n");
        for (i = 1; i < argc; i++) {
            printf("argv[%d]: %s\n", i, argv[i]);
        }
    }

	return 0;
}
