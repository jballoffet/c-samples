/*!
 * @file   main.c
 * @brief  13. Argumentos del Main - 04. Uso de getopt()
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   May 16, 2019
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    int opt, i;
    int flag_a = 0, flag_b = 0;
    char* value_c = NULL;

    // Obtengo los argumentos pasados utilizando getopt().
    while ((opt = getopt(argc, argv, "abc:")) != -1)
    {
        switch (opt)
        {
            case 'a':
                flag_a = 1;
                break;

            case 'b':
                flag_b = 1;
                break;

            case 'c':
                value_c = optarg;
                break;

            case '?':
                printf("Uso: %s [-a] [-b] [-c <algo>]\n", argv[0]);
                return 1;

            default:
                return 1;
        }
    }

    // Imprimo los argumentos obtenidos con getopt().
    printf("Argumentos obtenidos: flag_a = %d, flag_b = %d, value_c = %s\n",
           flag_a, flag_b, value_c);

    // Imprimo los argumentos adicionales recibidos.
    for (i = optind; i < argc; i++)
    {
        printf("Argumento adicional: %s\n", argv[i]);
    }

    return 0;
}
