/**
 * \file            main.c
 * \brief           28. Archivos de Texto - Ejemplo 1 - Escribiendo un archivo de texto
 * \author          Javier Balloffet
 * \date            Sep 17, 2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    FILE* fp;

    /* 1. Abro el archivo en modo escritura (w). Si no existe, el mismo es creado */
    fp = fopen("archivo.txt", "w");

    /* 2. Chequeo si hubo un error al abrir el archivo */
    if (fp == NULL) {
        printf("Error abriendo el archivo!\n");
        return -1;
    }

    /* 3. Escribo el archivo */
    fprintf(fp, "%s", "Escribiendo un archivo de texto por primera vez!\n");

    /* 4. Cierro el archivo */
    fclose(fp);

	return 0;
}
