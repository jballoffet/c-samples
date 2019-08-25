/**
 * \file            main.c
 * \brief           28. Archivos de Texto - Ejemplo 7 - my_cp
 * \author          Javier Balloffet
 * \date            Sep 18, 2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    FILE* fp_input;
    FILE* fp_output;
    char character;

    /* 1. Abro el archivo origen en modo lectura (r) */
    fp_input = fopen("archivo.txt", "r");

    /* 2. Chequeo si hubo un error al abrir el archivo */
    if (fp_input == NULL) {
        printf("Error abriendo el archivo origen!\n");
        return -1;
    }

    /* 3. Abro el archivo destino en modo escritura (w) */
    fp_output = fopen("archivo_copia.txt", "w");

    /* 4. Chequeo si hubo un error al abrir el archivo */
    if (fp_output == NULL) {
        printf("Error abriendo el archivo destino!\n");
        return -1;
    }

    /* 5. Leo el archivo origen caracter por caracter y lo voy escribiendo en el archivo destino */
    character = fgetc(fp_input);

    while (feof(fp_input) == 0) {
        fputc(character, fp_output);
        character = fgetc(fp_input);
    }

    printf("Archivo copiado correctamente!\n");

    /* 6. Cierro los archivos */
    fclose(fp_input);
    fclose(fp_output);

	return 0;
}
