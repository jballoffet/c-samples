/*!
 * @file   main.c
 * @brief  21. Enumeraciones - 01. Definición y declaración de enumeraciones
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Aug 19, 2019
 */
#include <stdio.h>

// Defino un tipo de datos enumerativo llamado "enum WeekDay".
enum WeekDay
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

int main(void)
{
    // Declaro una variable de tipo "enum WeekDay".
    enum WeekDay day;

    for (day = MONDAY; day <= SUNDAY; day++)
    {
        switch (day)
        {
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
