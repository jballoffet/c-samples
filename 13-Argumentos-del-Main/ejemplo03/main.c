/*!
 * @file   main.c
 * @brief  13. Argumentos del main - 03. Declaración de main con argumentos
 * numéricos
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   May 15, 2019
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int a, b;

    // Chequeo la cantidad de argumentos pasados.
    if (argc != 3)
    {
        // Cantidad errónea de argumentos :(.
        printf("Cantidad erronea de argumentos\n");
    }
    else
    {
        // Cantidad correcta de argumentos :).
        a = atoi(argv[1]);
        b = atoi(argv[2]);

        // Calculo la suma de ambos argumentos numéricos.
        printf("%d + %d = %d\n", a, b, a + b);
    }

    return 0;
}
