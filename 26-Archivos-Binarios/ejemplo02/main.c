/*!
 * @file   main.c
 * @brief  26. Archivos Binarios - 02. Leer un archivo binario
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 28, 2018
 */
#include <stdio.h>

int main(void)
{
    FILE* fp;
    int array[5];
    int i;

    // Abro el archivo en modo lectura binaria (rb).
    fp = fopen("archivo", "rb");

    // Chequeo si hubo un error al abrir el archivo.
    if (fp == NULL)
    {
        printf("Error abriendo el archivo!\n");
        return -1;
    }

    // Leo e imprimo en pantalla los primeros 5 valores del archivo.
    fread(array, sizeof(int), 5, fp);
    for (i = 0; i < 5; i++)
    {
        printf("%d", array[i]);
    }
    printf("\n");

    // Cierro el archivo.
    fclose(fp);

    return 0;
}
