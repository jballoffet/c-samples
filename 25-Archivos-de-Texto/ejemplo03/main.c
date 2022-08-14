/*!
 * @file   main.c
 * @brief  25. Archivos de Texto - 03. Escribiendo un número en un archivo de
 *   texto
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 17, 2018
 */
#include <stdio.h>

int main(void)
{
    FILE* fp;
    int number = 123456789;

    // Abro el archivo en modo escritura (w). Si no existe, el mismo es creado.
    fp = fopen("archivo.txt", "w");

    // Chequeo si hubo un error al abrir el archivo.
    if (fp == NULL)
    {
        printf("Error abriendo el archivo!\n");
        return -1;
    }

    // Escribo un número en el archivo.
    fprintf(fp, "%d\n", number);

    // Cierro el archivo.
    fclose(fp);

    return 0;
}
