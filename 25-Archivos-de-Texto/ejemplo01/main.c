/*!
 * @file   main.c
 * @brief  25. Archivos de Texto - 01. Escribiendo un archivo de texto
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 17, 2018
 */
#include <stdio.h>

int main(void)
{
    FILE* fp;

    // Abro el archivo en modo escritura (w). Si no existe, el mismo es creado.
    fp = fopen("archivo.txt", "w");

    // Chequeo si hubo un error al abrir el archivo.
    if (fp == NULL)
    {
        printf("Error abriendo el archivo!\n");
        return -1;
    }

    // Escribo el archivo.
    fprintf(fp, "%s", "Escribiendo un archivo de texto por primera vez!\n");

    // Cierro el archivo.
    fclose(fp);

    return 0;
}
