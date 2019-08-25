/**
 * \file            main.c
 * \brief           14. Argumentos del main - Ejemplo 1 - Declaración de main con argumentos
 * \author          Javier Balloffet
 * \date            May 15, 2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main(int argc, char* argv[]) {
    int i;

    /* 1. Imprimo argumentos pasados por línea de comandos */
    printf("Cantidad de argumentos pasados: %d\n", argc);
    printf("Argumentos pasados:\n");
    for (i = 0; i < argc; i++) {
        printf("    argv[%d]: %s\n", i, argv[i]);
    }

	return 0;
}
