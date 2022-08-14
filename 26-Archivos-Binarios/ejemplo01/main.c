/*!
 * @file   main.c
 * @brief  26. Archivos Binarios - 01. Escribir un archivo binario
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 28, 2018
 */
#include <stdio.h>

int main(void)
{
    FILE* fp;
    int array[5] = {1, 2, 3, 4, 5};

    // Abro el archivo en modo escritura binaria (wb). Si no existe, el mismo es
    // creado.
    fp = fopen("archivo", "wb");

    // Chequeo si hubo un error al abrir el archivo.
    if (fp == NULL)
    {
        printf("Error abriendo el archivo!\n");
        return -1;
    }

    // Escribo el archivo (de a bloques de bytes).
    fwrite(array, sizeof(int), 5, fp);

    // Cierro el archivo.
    fclose(fp);

    return 0;
}
