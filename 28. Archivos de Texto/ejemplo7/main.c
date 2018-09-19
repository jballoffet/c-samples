/**
 * \file            main.c
 * \brief           28. Archivos de Texto - Ejemplo 7 - my_cp
 * \author          Javier Balloffet
 * \date            18-SEP-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    FILE* fpInput;
    FILE* fpOutput;
    char character;

    // 1. Abro el archivo origen en modo lectura (r)
    fpInput = fopen("archivo.txt", "r");

    // 2. Chequeo si hubo un error al abrir el archivo
    if (fpInput == NULL) {
        printf("Error abriendo el archivo origen!\n");
        return -1;
    }

    // 3. Abro el archivo destino en modo escritura (w)
    fpOutput = fopen("archivo_copia.txt", "w");

    // 4. Chequeo si hubo un error al abrir el archivo
    if (fpOutput == NULL) {
        printf("Error abriendo el archivo destino!\n");
        return -1;
    }

    // 5. Leo el archivo origen caracter por caracter y lo voy escribiendo en el archivo destino
    character = fgetc(fpInput);

    while (feof(fpInput) == 0) {
        fputc(character, fpOutput);
        character = fgetc(fpInput);
    }

    printf("Archivo copiado correctamente!\n");

    // 6. Cierro los archivos
    fclose(fpInput);
    fclose(fpOutput);

	return 0;
}
