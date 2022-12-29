/*!
 * @file   time.h
 * @brief  23. Tipo de Dato Abstracto - 02. Definición y declaración de un TDA
 *   (Time)
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Dic 29, 2022
 */
#ifndef TIME_H_
#define TIME_H_

// Defino un tipo de datos incompleto llamado "Time" a partir del tipo
// "struct Time". Al completar su definición en el archivo fuente (.c), su
// contenido no es accesible por otros módulos (se vuelve un tipo de datos
// abstracto).
typedef struct Time Time;

// API (interfaz de programación de aplicaciones) del tipo de dato abstracto
// Time.
Time* time_create(int hours, int minutes, int seconds);
void time_destroy(Time* time);
int time_get_hours(const Time* time);
int time_get_minutes(const Time* time);
int time_get_seconds(const Time* time);
void time_set_hours(Time* time, int hours);
void time_set_minutes(Time* time, int minutes);
void time_set_seconds(Time* time, int seconds);
void time_print_12(const Time* time);
void time_print_24(const Time* time);

#endif  // TIME_H_
