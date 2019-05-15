/**
 * \file            main.c
 * \brief           29. Archivos Binarios - Ejemplo 2 - Leer un archivo binario
 * \author          Javier Balloffet
 * \date            Sep 28, 2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    FILE* fp;
    int array[5];
	int i;

    /* 1. Abro el archivo en modo lectura binaria (rb) */
    fp = fopen("archivo", "rb");

    /* 2. Chequeo si hubo un error al abrir el archivo */
    if (fp == NULL) {
        printf("Error abriendo el archivo!\n");
        return -1;
    }

    /* 3. Leo e imprimo en pantalla los primeros 5 valores del archivo */
    fread(array, sizeof(int), 5, fp);
    for (i = 0; i < 5; i++) {
        printf("%d", array[i]);
    }
    printf("\n");
    
    /* 4. Cierro el archivo */
    fclose(fp);

	return 0;
}
