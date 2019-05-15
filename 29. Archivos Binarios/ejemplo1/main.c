/**
 * \file            main.c
 * \brief           29. Archivos Binarios - Ejemplo 1 - Escribir un archivo binario
 * \author          Javier Balloffet
 * \date            Sep 28, 2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    FILE* fp;
    int array[5] = {1, 2, 3, 4, 5};
	
    /* 1. Abro el archivo en modo escritura binaria (wb). Si no existe, el mismo es creado */
    fp = fopen("archivo", "wb");

    /* 2. Chequeo si hubo un error al abrir el archivo */
    if (fp == NULL) {
        printf("Error abriendo el archivo!\n");
        return -1;
    }

    /* 3. Escribo el archivo (de a bloques de bytes) */
    fwrite(array, sizeof(int), 5, fp);

    /* 4. Cierro el archivo */
    fclose(fp);

	return 0;
}
