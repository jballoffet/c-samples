/**
 * \file            main.c
 * \brief           28. Archivos de Texto - Ejemplo 3
 * \author          Javier Balloffet
 * \date            18-SEP-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    FILE* fp;
    int number = 123456789;
	
    // 1. Abro el archivo en modo escritura (w). Si no existe, el mismo es creado
    fp = fopen("archivo.txt", "w");

    // 2. Chequeo si hubo un error al abrir el archivo
    if (fp == NULL) {
        printf("Error abriendo el archivo!\n");
        return -1;
    }

    // 3. Escribo un numero en el archivo
    fprintf(fp, "%d\n", number);

    // 4. Cierro el archivo
    fclose(fp);

	return 0;
}
