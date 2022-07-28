/*!
 * @file   main.c
 * @brief  18. Estructuras - 04. Operador flecha
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Jul 23, 2022
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
    // Declaro una variable de tipo "Person" y un puntero a "Person".
    Person person;
    Person* person_pointer = NULL;

    // Asigno al puntero la dirección de la variable.
    person_pointer = &person;

    // Cargo los datos de una persona.
    strcpy(person.first_name, "John");
    strcpy(person.last_name, "Doe");
    person.age = 27;

    // Imprimo los datos de la persona mediante la variable, utilizando el
    // operador punto.
    printf("Nombre de la persona: %s\n", person.first_name);
    printf("Apellido de la persona: %s\n", person.last_name);
    printf("Edad de la persona: %d\n", person.age);

    // Imprimo los datos de la persona mediante el puntero, utilizando el
    // operador punto (debo desreferenciar el puntero previamente).
    printf("Nombre de la persona: %s\n", (*person_pointer).first_name);
    printf("Apellido de la persona: %s\n", (*person_pointer).last_name);
    printf("Edad de la persona: %d\n", (*person_pointer).age);

    // Imprimo los datos de la persona mediante el puntero, utilizando el
    // operador flecha.
    printf("Nombre de la persona: %s\n", person_pointer->first_name);
    printf("Apellido de la persona: %s\n", person_pointer->last_name);
    printf("Edad de la persona: %d\n", person_pointer->age);

    return 0;
}
