/*!
 * @file   time.c
 * @brief  23. Tipo de Dato Abstracto - 02. Definición y declaración de un TDA
 *   (Time)
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Dic 29, 2022
 */
#include "time.h"

#include <stdio.h>
#include <stdlib.h>

// Defino un tipo de datos estructura llamado "struct Time". Al estar
// definido en el archivo fuente (.c), su contenido no es accesible por otros
// módulos (se vuelve un tipo de datos abstracto). En el archivo header (.h) se
// encuentra definido el tipo "Time" a partir de "struct Time".
struct Time
{
    int hours;
    int minutes;
    int seconds;
};

Time* time_create(int hours, int minutes, int seconds)
{
    Time* time = NULL;

    // Solicito memoria para almacenar la estructura de datos.
    time = malloc(sizeof(Time));
    if (time == NULL)
    {
        return NULL;
    }

    // Inicializo la estructura conforme los valores pasados como argumentos.
    time->hours = hours;
    time->minutes = minutes;
    time->seconds = seconds;
    return time;
}

void time_destroy(Time* time)
{
    // Libero la memoria previamente solicitada.
    free(time);
}

int time_get_hours(const Time* time)
{
    return time->hours;
}

int time_get_minutes(const Time* time)
{
    return time->minutes;
}

int time_get_seconds(const Time* time)
{
    return time->seconds;
}

void time_set_hours(Time* time, int hours)
{
    time->hours = hours;
}

void time_set_minutes(Time* time, int minutes)
{
    time->minutes = minutes;
}

void time_set_seconds(Time* time, int seconds)
{
    time->seconds = seconds;
}

void time_print_12(const Time* time)
{
    if (time->hours <= 12)
    {
        printf("%02d:%02d:%02d AM", time->hours, time->minutes, time->seconds);
    }
    else
    {
        printf("%02d:%02d:%02d PM", time->hours - 12, time->minutes,
               time->seconds);
    }
}

void time_print_24(const Time* time)
{
    printf("%02d:%02d:%02d", time->hours, time->minutes, time->seconds);
}
