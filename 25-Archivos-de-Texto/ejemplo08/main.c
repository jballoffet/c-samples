/*!
 * @file   main.c
 * @brief  25. Archivos de Texto - 08. my_cp (con argumentos del main)
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 17, 2018
 */
#include <stdio.h>

int main(int argc, char** argv)
{
    FILE* fp_input;
    FILE* fp_output;
    char character;

    // Chequeo que la cantidad de argumentos pasados sea correcta.
    if (argc != 3)
    {
        printf("Error de uso del programa!\n");
        printf("Modo de uso: ./my_cp ORIGEN DESTINO\n");
        return -1;
    }

    // Abro el archivo origen en modo lectura (r).
    fp_input = fopen(argv[1], "r");

    // Chequeo si hubo un error al abrir el archivo.
    if (fp_input == NULL)
    {
        printf("Error abriendo el archivo origen!\n");
        return -1;
    }

    // Abro el archivo destino en modo escritura (w).
    fp_output = fopen(argv[2], "w");

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
