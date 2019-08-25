/**
 * \file            main.c
 * \brief           14. Argumentos del main - Ejemplo 3 - Declaración de main con argumentos numéricos
 * \author          Javier Balloffet
 * \date            May 15, 2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int a, b;

    /* 1. Chequeo la cantidad de argumentos pasados */
    if (argc != 3) {
        /* 2. Cantidad errónea de argumentos :( */
        printf("Cantidad erronea de argumentos\n");
    } else {
        /* 3. Cantidad correcta de argumentos :) */
        a = atoi(argv[1]);
        b = atoi(argv[2]);

        /* 4. Calculo la suma de ambos argumentos numéricos */
        printf("%d + %d = %d\n", a, b, a + b);
    }

	return 0;
}
