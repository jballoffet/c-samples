/*!
 * @file   main.c
 * @brief  25. Archivos de Texto - 02. Leyendo un archivo de texto
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 17, 2018
 */
#include <stdio.h>

int main(void)
{
    FILE* fp;
    char file_line[60];

    // Abro el archivo en modo lectura (r).
    fp = fopen("archivo.txt", "r");

    // Chequeo si hubo un error al abrir el archivo.
    if (fp == NULL)
    {
        printf("Error abriendo el archivo!\n");
        return -1;
    }

    // Leo e imprimo en pantalla la primera línea del archivo.
    fgets(file_line, 60, fp);
    printf("%s", file_line);

    // Cierro el archivo.
    fclose(fp);

    return 0;
}
