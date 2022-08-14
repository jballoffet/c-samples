/*!
 * @file   main.c
 * @brief  26. Archivos Binarios - 03. Escribiendo una estructura en un archivo
 *   binario
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 28, 2018
 */
#include <stdio.h>
#include <string.h>

typedef struct Person
{
    char first_name[20];
    char last_name[20];
    int age;
} Person;

int main(void)
{
    FILE* fp;
    Person person;

    // Cargo la estructura con información.
    strcpy(person.first_name, "John");
    strcpy(person.last_name, "Doe");
    person.age = 27;

    // Abro el archivo en modo escritura binaria (wb). Si no existe, el mismo es
    // creado.
    fp = fopen("archivo", "wb");

    // Chequeo si hubo un error al abrir el archivo.
    if (fp == NULL)
    {
        printf("Error abriendo el archivo!\n");
        return -1;
    }

    // Escribo la estructura en el archivo.
    fwrite(&person, sizeof(Person), 1, fp);

    // Cierro el archivo.
    fclose(fp);

    return 0;
}
