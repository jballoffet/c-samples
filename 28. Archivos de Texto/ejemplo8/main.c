/**
 * \file            main.c
 * \brief           28. Archivos de Texto - Ejemplo 8 - my_cp (con argumentos del main)
 * \author          Javier Balloffet
 * \date            18-SEP-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main(int argc, char* argv[]) {
    FILE* fpInput;
    FILE* fpOutput;
    char character;

    // 1. Chequeo que la cantidad de argumentos pasados sea correcta
    if (argc != 3) {
        printf("Error de uso del programa!\n");
        printf("Modo de uso: ./my_cp ORIGEN DESTINO\n");
        return -1;
    }

    // 2. Abro el archivo origen en modo lectura (r)
    fpInput = fopen(argv[1], "r");

    // 3. Chequeo si hubo un error al abrir el archivo
    if (fpInput == NULL) {
        printf("Error abriendo el archivo origen!\n");
        return -1;
    }

    // 4. Abro el archivo destino en modo escritura (w)
    fpOutput = fopen(argv[2], "w");

    // 5. Chequeo si hubo un error al abrir el archivo
    if (fpOutput == NULL) {
        printf("Error abriendo el archivo destino!\n");
        return -1;
    }

    // 6. Leo el archivo origen caracter por caracter y lo voy escribiendo en el archivo destino
    character = fgetc(fpInput);

    while (feof(fpInput) == 0) {
        fputc(character, fpOutput);
        character = fgetc(fpInput);
    }

    printf("Archivo copiado correctamente!\n");

    // 7. Cierro los archivos
    fclose(fpInput);
    fclose(fpOutput);

	return 0;
}
