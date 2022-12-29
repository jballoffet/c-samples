/*!
 * @file   main.c
 * @brief  23. Tipo de Dato Abstracto - 02. Definición y declaración de un TDA
 *   (Time)
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Dic 29, 2022
 */
#include <stdio.h>

#include "time.h"

int main(void)
{
    Time* time = NULL;

    // Creo una hora e inicializo horas, minutos y segundos.
    time = time_create(14, 16, 29);
    if (time == NULL)
    {
        printf("Error! Hora no creada.\n");
        return -1;
    }

    // Imprimo horas, minutos, segundos y la hora actual en formatos de 12 y 24
    // horas.
    printf("Horas: %d\n", time_get_hours(time));
    printf("Minutos: %d\n", time_get_minutes(time));
    printf("Segundos: %d\n", time_get_seconds(time));
    printf("Hora (formato 12 horas): ");
    time_print_12(time);
    printf("\n");
    printf("Hora (formato 24 horas): ");
    time_print_24(time);
    printf("\n");

    // Seteo nuevos valores para las horas, minutos y segundos de la hora.
    time_set_hours(time, 11);
    time_set_minutes(time, 53);
    time_set_seconds(time, 7);

    // Imprimo nuevamente horas, minutos, segundos y la hora actual en formatos
    // de 12 y 24 horas.
    printf("Horas: %d\n", time_get_hours(time));
    printf("Minutos: %d\n", time_get_minutes(time));
    printf("Segundos: %d\n", time_get_seconds(time));
    printf("Hora (formato 12 horas): ");
    time_print_12(time);
    printf("\n");
    printf("Hora (formato 24 horas): ");
    time_print_24(time);
    printf("\n");

    // Destruyo la hora.
    time_destroy(time);

    return 0;
}
