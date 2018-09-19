/**
 * \file            main.c
 * \brief           28. Archivos de Texto - Ejemplo 4
 * \author          Javier Balloffet
 * \date            18-SEP-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    FILE* fp;
    int number;
	
    // 1. Abro el archivo en modo lectura (r)
    fp = fopen("archivo.txt", "r");

    // 2. Chequeo si hubo un error al abrir el archivo
    if (fp == NULL) {
        printf("Error abriendo el archivo!\n");
        return -1;
    }

    // 3. Leo e imprimo en pantalla el numero presente en el archivo
    fscanf(fp, "%d", &number);
    printf("%d\n", number);

    // 4. Cierro el archivo
    fclose(fp);

	return 0;
}
