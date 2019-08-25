/**
 * \file            main.c
 * \brief           14. Argumentos del main - Ejemplo 5 - Uso de getopt() (2)
 * \author          Javier Balloffet
 * \date            May 16, 2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_usage(void);

int main(int argc, char* argv[]) {
    int opt;
    int calculateAreaFlag = 0, calculatePerimeterFlag = 0;
    int length = -1, width = -1;

    /* 1. Obtengo los argumentos pasados utilizando getopt() */
    while ((opt = getopt(argc, argv, "apl:w:")) != -1) {
        switch (opt) {
            case 'a':
                calculateAreaFlag = 1;
                break;
            
            case 'p':
                calculatePerimeterFlag = 1;
                break;

            case 'l':
                length = atoi(optarg);
                break;

            case 'w':
                width = atoi(optarg);
                break;

            case '?':
                print_usage();
                return 1;

            default:
                return 1;
        }
    }

    /* 2. Compruebo haber recibido una operación */
    if ((calculateAreaFlag == 0) && (calculatePerimeterFlag == 0)) {
        printf("Operacion no especificada\n");
        print_usage();
        return 1;
    }

    /* 3. Compruebo haber recibido las dimensiones del rectángulo */
    if ((length < 0) || (width < 0)) {
        printf("Medidas del rectangulo no especificadas\n");
        print_usage();
        return 1;
    }

    /* 4. Realizo el cálculo correspondiente */
    if (calculateAreaFlag) {
        printf("Area del rectangulo: %d * %d = %d\n", length, width, length * width);
    } else if (calculatePerimeterFlag) {
        printf("Perimetro del rectangulo: 2 * %d + 2 * %d = %d\n", length, width, (2 * length) + (2 * width));
    }

	return 0;
}

void print_usage(void) {
    printf("Uso: ./program [-a | -p] [-l <largo>] [-w <ancho>]\n");
    printf("Opciones:\n");
    printf("    -a              Calcular area\n");
    printf("    -p              Calcular perimetro\n");
    printf("    -l [LARGO]      Largo del rectangulo\n");
    printf("    -w [ANCHO]      Ancho del rectangulo\n");
}
