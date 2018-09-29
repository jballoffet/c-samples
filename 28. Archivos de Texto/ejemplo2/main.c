/**
 * \file            main.c
 * \brief           28. Archivos de Texto - Ejemplo 2 - Leyendo un archivo de texto
 * \author          Javier Balloffet
 * \date            17-SEP-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    FILE* fp;
    char fileLine[60];
	
    // 1. Abro el archivo en modo lectura (r)
    fp = fopen("archivo.txt", "r");

    // 2. Chequeo si hubo un error al abrir el archivo
    if (fp == NULL) {
        printf("Error abriendo el archivo!\n");
        return -1;
    }

    // 3. Leo e imprimo en pantalla la primera linea del archivo
    fgets(fileLine, 60, fp);
    printf("%s", fileLine);

    // 4. Cierro el archivo
    fclose(fp);

	return 0;
}
