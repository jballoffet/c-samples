/*!
 * @file   main.c
 * @brief  13. Argumentos del Main - 01. Declaración de main con argumentos
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   May 15, 2019
 */
#include <stdio.h>

int main(int argc, char** argv)
{
    int i;

    // Imprimo argumentos pasados por línea de comandos.
    printf("Cantidad de argumentos pasados: %d\n", argc);
    printf("Argumentos pasados:\n");
    for (i = 0; i < argc; i++)
    {
        printf("    argv[%d]: %s\n", i, argv[i]);
    }

    return 0;
}
