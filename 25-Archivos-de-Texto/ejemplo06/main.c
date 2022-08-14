/*!
 * @file   main.c
 * @brief  25. Archivos de Texto - 06. my_cat (otra forma)
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 17, 2018
 */
#include <stdio.h>

int main(void)
{
    FILE* fp;
    char character;

    // Abro el archivo en modo lectura (r).
    fp = fopen("archivo.txt", "r");

    // Chequeo si hubo un error al abrir el archivo.
    if (fp == NULL)
    {
        printf("Error abriendo el archivo!\n");
        return -1;
    }

    // Leo e imprimo en pantalla el archivo caracter por caracter hasta llegar
    // al EOF.
    character = fgetc(fp);

    while (character != EOF)
    {
        printf("%c", character);
        character = fgetc(fp);
    }

    printf("\n");

    // Cierro el archivo.
    fclose(fp);

    return 0;
}
