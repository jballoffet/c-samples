/*!
 * @file   main.c
 * @brief  25. Archivos de Texto - 04. Leyendo un número de un archivo de texto
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 17, 2018
 */
#include <stdio.h>

int main(void)
{
    FILE* fp;
    int number;

    // Abro el archivo en modo lectura (r).
    fp = fopen("archivo.txt", "r");

    // Chequeo si hubo un error al abrir el archivo.
    if (fp == NULL)
    {
        printf("Error abriendo el archivo!\n");
        return -1;
    }

    // Leo e imprimo en pantalla el número presente en el archivo.
    fscanf(fp, "%d", &number);
    printf("%d\n", number);

    // Cierro el archivo.
    fclose(fp);

    return 0;
}
