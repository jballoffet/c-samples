/*!
 * @file   main.c
 * @brief  26. Archivos Binarios - 04. Leyendo una estructura de un archivo
 *   binario
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 28, 2018
 */
#include <stdio.h>

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

    // Abro el archivo en modo lectura binaria (rb).
    fp = fopen("archivo", "rb");

    // Chequeo si hubo un error al abrir el archivo.
    if (fp == NULL)
    {
        printf("Error abriendo el archivo!\n");
        return -1;
    }

    // Leo e imprimo en pantalla la estructura presente en el archivo.
    fread(&person, sizeof(Person), 1, fp);
    printf("%s\n", person.first_name);
    printf("%s\n", person.last_name);
    printf("%d\n", person.age);

    // Cierro el archivo.
    fclose(fp);

    return 0;
}
