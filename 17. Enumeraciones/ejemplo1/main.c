/**
 * \file            main.c
 * \brief           17. Enumeraciones - Ejemplo 1 - Definición, declaración y uso
 * \author          Javier Balloffet
 * \date            Ago 19, 2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

/* 1. Declaro un tipo enumerativo llamado "enum WeekDay" para definir los posibles días de la semana */
enum WeekDay {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

int main() {
    /* 2. Declaro una variable de tipo "enum WeekDay" para almacenar el día de la semana */
    enum WeekDay day;

    for (day = MONDAY; day <= SUNDAY; day++) {
        switch (day) {
            case MONDAY:
                printf("Valor de day: %d - Representado por MONDAY\n", day);
                break;

            case TUESDAY:
                printf("Valor de day: %d - Representado por TUESDAY\n", day);
                break;

            case WEDNESDAY:
                printf("Valor de day: %d - Representado por WEDNESDAY\n", day);
                break;

            case THURSDAY:
                printf("Valor de day: %d - Representado por THURSDAY\n", day);
                break;

            case FRIDAY:
                printf("Valor de day: %d - Representado por FRIDAY\n", day);
                break;

            case SATURDAY:
                printf("Valor de day: %d - Representado por SATURDAY\n", day);
                break;

            case SUNDAY:
                printf("Valor de day: %d - Representado por SUNDAY\n", day);
                break;
            
            default:
                break;
        }
    }

	return 0;
}
