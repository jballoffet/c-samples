/**
 * \file            main.c
 * \brief           14. Argumentos del main - Ejemplo 4 - Uso de getopt()
 * \author          Javier Balloffet
 * \date            May 16, 2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int opt, i;
    int flagA = 0, flagB = 0;
    char* valueC = NULL;

    /* 1. Obtengo los argumentos pasados utilizando getopt() */
    while ((opt = getopt(argc, argv, "abc:")) != -1) {
        switch (opt) {
            case 'a':
                flagA = 1;
                break;
            
            case 'b':
                flagB = 1;
                break;

            case 'c':
                valueC = optarg;
                break;

            case '?':
                printf("Uso: %s [-a] [-b] [-c <algo>]\n", argv[0]);
                return 1;

            default:
                return 1;
        }
    }

    /* 2. Imprimo los argumentos obtenidos con getopt() */
    printf("Argumentos obtenidos: flagA = %d, flagB = %d, valueC = %s\n", flagA, flagB, valueC);

    /* 3. Imprimo los argumentos adicionales recibidos */
    for (i = optind; i < argc; i++) {
        printf("Argumento adicional: %s\n", argv[i]);
    }

	return 0;
}
