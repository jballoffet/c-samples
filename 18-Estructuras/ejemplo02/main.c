/*!
 * @file   main.c
 * @brief  18. Estructuras - 02. Uso de Typedef
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Aug 19, 2019
 */
#include <stdio.h>
#include <string.h>

// Defino un tipo de datos llamado "Person" a partir del tipo "struct Person".
typedef struct Person
{
    char first_name[20];
    char last_name[20];
    int age;
} Person;

int main(void)
{
    // Declaro una variable de tipo "Person".
    Person person;

    // Cargo los datos de una persona.
    strcpy(person.first_name, "John");
    strcpy(person.last_name, "Doe");
    person.age = 27;

    // Imprimo los datos de la persona.
    printf("Nombre de la persona: %s\n", person.first_name);
    printf("Apellido de la persona: %s\n", person.last_name);
    printf("Edad de la persona: %d\n", person.age);

    return 0;
}
