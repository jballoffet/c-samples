/**
 * \file            main.c
 * \brief           19. Estructuras - Ejemplo 1 - Definición, declaración y uso
 * \author          Javier Balloffet
 * \date            Ago 19, 2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <string.h>

/* 1. Declaro un tipo estructura llamado "struct Person" para definir los campos de datos de una persona */
struct Person {
    char first_name[20];
    char last_name[20];
    int age;
};

int main() {
    /* 2. Declaro una variable de tipo "struct Person" para almacenar los datos de una persona */
    struct Person person_1;

    /* 3. Cargo los datos de la persona */
    strcpy(person_1.first_name, "John");
    strcpy(person_1.last_name, "Doe");
    person_1.age = 27;

    /* 4. Imprimo los datos de la persona */
    printf("Nombre de person_1: %s\n", person_1.first_name);
    printf("Apellido de person_1: %s\n", person_1.last_name);
    printf("Edad de person_1: %d\n", person_1.age);

	return 0;
}
