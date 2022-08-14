/*!
 * @file   main.c
 * @brief  25. Archivos de Texto - 07. my_cp
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 17, 2018
 */
#include <stdio.h>

int main(void)
{
    FILE* fp_input;
    FILE* fp_output;
    char character;

    // Abro el archivo origen en modo lectura (r).
    fp_input = fopen("archivo.txt", "r");

    // Chequeo si hubo un error al abrir el archivo.
    if (fp_input == NULL)
    {
        printf("Error abriendo el archivo origen!\n");
        return -1;
    }

    // Abro el archivo destino en modo escritura (w).
    fp_output = fopen("archivo_copia.txt", "w");

    // Chequeo si hubo un error al abrir el archivo.
    if (fp_output == NULL)
    {
        printf("Error abriendo el archivo destino!\n");
        return -1;
    }

    // Leo el archivo origen caracter por caracter y lo voy escribiendo en el
    // archivo destino.
    character = fgetc(fp_input);

    while (feof(fp_input) == 0)
    {
        fputc(character, fp_output);
        character = fgetc(fp_input);
    }

    printf("Archivo copiado correctamente!\n");

    // Cierro los archivos.
    fclose(fp_input);
    fclose(fp_output);

    return 0;
}
