/**
 * \file            main.c
 * \brief           29. Archivos Binarios - Ejemplo 3 - Escribiendo una estructura en un archivo binario
 * \author          Javier Balloffet
 * \date            28-SEP-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <string.h>

struct person {
    char name[20];
    char surname[20];
    int age;
};

int main() {
    FILE* fp;
    struct person professor;

    // 1. Cargo la estructura con informacion
    strcpy(professor.name, "Javier");
    strcpy(professor.surname, "Balloffet");
    professor.age = 26;

    // 2. Abro el archivo en modo escritura binaria (wb). Si no existe, el mismo es creado
    fp = fopen("archivo", "wb");

    // 3. Chequeo si hubo un error al abrir el archivo
    if (fp == NULL) {
        printf("Error abriendo el archivo!\n");
        return -1;
    }

    // 4. Escribo la estructura en el archivo
    fwrite(&professor, sizeof(struct person), 1, fp);

    // 5. Cierro el archivo
    fclose(fp);

	return 0;
}
