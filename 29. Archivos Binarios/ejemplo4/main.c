/**
 * \file            main.c
 * \brief           29. Archivos Binarios - Ejemplo 4 - Leyendo una estructura de un archivo binario
 * \author          Javier Balloffet
 * \date            Sep 28, 2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

struct person {
    char name[20];
    char surname[20];
    int age;
};

int main() {
    FILE* fp;
    struct person professor;
	
    /* 1. Abro el archivo en modo lectura binaria (rb) */
    fp = fopen("archivo", "rb");

    /* 2. Chequeo si hubo un error al abrir el archivo */
    if (fp == NULL) {
        printf("Error abriendo el archivo!\n");
        return -1;
    }

    /* 3. Leo e imprimo en pantalla la estructura presente en el archivo */
    fread(&professor, sizeof(struct person), 1, fp);
    printf("%s\n", professor.name);
    printf("%s\n", professor.surname);
    printf("%d\n", professor.age);

    /* 4. Cierro el archivo */
    fclose(fp);

	return 0;
}
