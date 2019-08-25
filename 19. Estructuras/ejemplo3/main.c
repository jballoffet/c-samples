/**
 * \file            main.c
 * \brief           19. Estructuras - Ejemplo 3 - Arreglos
 * \author          Javier Balloffet
 * \date            Ago 19, 2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

typedef struct Person {
    char first_name[20];
    char last_name[20];
    int age;
} Person;

#define PEOPLE_MAX 5

int main() {
    int i;
    /* 1. Declaro un arreglo del tipo de dato "Person" de largo "PEOPLE_MAX" */
    Person people[PEOPLE_MAX];

    /* 2. Cargo los datos de las personas en el arreglo */
    for (i = 0; i < PEOPLE_MAX; i++) {
        printf("Ingrese el nombre de la persona %d: ", i);
        scanf("%s", people[i].first_name);

        printf("Ingrese el apellido de la persona %d: ", i);
        scanf("%s", people[i].last_name);

        printf("Ingrese la edad de la persona %d: ", i);
        scanf("%d", &people[i].age);
    }

    /* 3. Imprimo los datos de la persona */
    for (i = 0; i < PEOPLE_MAX; i++) {
        printf("Nombre de la persona %d: %s\n", i, people[i].first_name);
        printf("Apellido de la persona %d: %s\n", i, people[i].last_name);
        printf("Edad de la persona %d: %d\n", i, people[i].age);
    }

	return 0;
}
