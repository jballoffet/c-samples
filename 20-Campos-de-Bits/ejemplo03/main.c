/*!
 * @file   main.c
 * @brief  20. Campos de Bits - 03. Operador flecha
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 17, 2022
 */
#include <stdio.h>

typedef struct Date
{
    int day : 5;
    int month : 4;
    int year;
} Date;

int main(void)
{
    // Declaro una variable de tipo "Date" y un puntero a "Date".
    Date date;
    Date* date_pointer = NULL;

    // Asigno al puntero la dirección de la variable.
    date_pointer = &date;

    // Cargo una fecha, utilizando el operador flecha.
    date_pointer->day = 1;
    date_pointer->month = 1;
    date_pointer->year = 1970;

    // Imprimo el tamaño del campo de bits.
    printf("Una variable Date tiene %ld bytes de largo\n", sizeof(Date));

    // Imprimo la fecha, utilizando el operador flecha.
    printf("Dia: %d\n", date_pointer->day);
    printf("Mes: %d\n", date_pointer->month);
    printf("Anio: %d\n", date_pointer->year);

    return 0;
}
