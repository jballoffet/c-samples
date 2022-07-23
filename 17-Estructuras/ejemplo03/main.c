/*!
 * @file   main.c
 * @brief  17. Estructuras - 03. Arreglos de estructuras
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Aug 19, 2019
 */
#include <stdio.h>

#define PEOPLE_MAX 5

typedef struct Person
{
    char first_name[20];
    char last_name[20];
    int age;
} Person;

int main(void)
{
    // Declaro un arreglo del tipo de dato "Person" de largo "PEOPLE_MAX".
    Person people[PEOPLE_MAX];
    int i;

    // Cargo los datos de las personas en el arreglo.
    for (i = 0; i < PEOPLE_MAX; i++)
    {
        printf("Ingrese el nombre de la persona %d: ", i);
        scanf("%s", people[i].first_name);

        printf("Ingrese el apellido de la persona %d: ", i);
        scanf("%s", people[i].last_name);

        printf("Ingrese la edad de la persona %d: ", i);
        scanf("%d", &people[i].age);
    }

    // Imprimo los datos de la persona.
    for (i = 0; i < PEOPLE_MAX; i++)
    {
        printf("Nombre de la persona %d: %s\n", i, people[i].first_name);
        printf("Apellido de la persona %d: %s\n", i, people[i].last_name);
        printf("Edad de la persona %d: %d\n", i, people[i].age);
    }

    return 0;
}
