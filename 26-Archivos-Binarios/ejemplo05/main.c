/*!
 * @file   main.c
 * @brief  26. Archivos Binarios - 05. my_cp
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 28, 2018
 */
#include <stdio.h>

int main(void)
{
    FILE* fp_input;
    FILE* fp_output;
    char array[100];
    int bytes_read;

    // Abro el archivo origen en modo lectura binaria (rb).
    fp_input = fopen("lena.png", "rb");

    // Chequeo si hubo un error al abrir el archivo.
    if (fp_input == NULL)
    {
        printf("Error abriendo el archivo origen!\n");
        return -1;
    }

    // Abro el archivo destino en modo escritura binaria (wb).
    fp_output = fopen("lena_copia.png", "wb");

    // Chequeo si hubo un error al abrir el archivo.
    if (fp_output == NULL)
    {
        printf("Error abriendo el archivo destino!\n");
        return -1;
    }

    // Leo el archivo origen de a bloques de 100 bytes y lo voy escribiendo en
    // el archivo destino.
    while (feof(fp_input) == 0)
    {
        bytes_read = fread(array, sizeof(char), 100, fp_input);
        fwrite(array, sizeof(char), bytes_read, fp_output);
    }

    printf("Archivo copiado correctamente!\n");

    // Cierro los archivos.
    fclose(fp_input);
    fclose(fp_output);

    return 0;
}
