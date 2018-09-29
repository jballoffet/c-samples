/**
 * \file            main.c
 * \brief           29. Archivos Binarios - Ejemplo 5 - my_cp
 * \author          Javier Balloffet
 * \date            28-SEP-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    FILE* fpInput;
    FILE* fpOutput;
    char array[100];
    int bytesRead;

    // 1. Abro el archivo origen en modo lectura binaria (rb)
    fpInput = fopen("lena.png", "rb");

    // 2. Chequeo si hubo un error al abrir el archivo
    if (fpInput == NULL) {
        printf("Error abriendo el archivo origen!\n");
        return -1;
    }

    // 3. Abro el archivo destino en modo escritura binaria (wb)
    fpOutput = fopen("lena_copia.png", "wb");

    // 4. Chequeo si hubo un error al abrir el archivo
    if (fpOutput == NULL) {
        printf("Error abriendo el archivo destino!\n");
        return -1;
    }

    // 5. Leo el archivo de a bloques de 100 bytes y lo voy escribiendo en el archivo destino
    while (feof(fpInput) == 0) {
        bytesRead = fread(array, sizeof(char), 100, fpInput);
        fwrite(array, sizeof(char), bytesRead, fpOutput);
    }

    printf("Archivo copiado correctamente!\n");

    // 6. Cierro los archivos
    fclose(fpInput);
    fclose(fpOutput);

	return 0;
}
