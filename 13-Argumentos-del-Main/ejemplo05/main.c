/*!
 * @file   main.c
 * @brief  13. Argumentos del Main - 05. Uso de getopt() (2)
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   May 16, 2019
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_usage(void);

int main(int argc, char** argv)
{
    int opt;
    int area_flag = 0, perimeter_flag = 0;
    int length = -1, width = -1;

    // Obtengo los argumentos pasados utilizando getopt().
    while ((opt = getopt(argc, argv, "apl:w:")) != -1)
    {
        switch (opt)
        {
            case 'a':
                area_flag = 1;
                break;

            case 'p':
                perimeter_flag = 1;
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

    // Compruebo haber recibido una operación.
    if ((area_flag == 0) && (perimeter_flag == 0))
    {
        printf("Operacion no especificada\n");
        print_usage();
        return 1;
    }

    // Compruebo haber recibido las dimensiones del rectángulo.
    if ((length < 0) || (width < 0))
    {
        printf("Medidas del rectangulo no especificadas\n");
        print_usage();
        return 1;
    }

    // Realizo el cálculo correspondiente.
    if (area_flag)
    {
        printf("Area del rectangulo: %d * %d = %d\n", length, width,
               length * width);
    }
    else if (perimeter_flag)
    {
        printf("Perimetro del rectangulo: 2 * %d + 2 * %d = %d\n", length,
               width, 2 * length + 2 * width);
    }

    return 0;
}

void print_usage(void)
{
    printf("Uso: ./app [-a | -p] [-l <largo>] [-w <ancho>]\n");
    printf("Opciones:\n");
    printf("    -a              Calcular area\n");
    printf("    -p              Calcular perimetro\n");
    printf("    -l [LARGO]      Largo del rectangulo\n");
    printf("    -w [ANCHO]      Ancho del rectangulo\n");
}
