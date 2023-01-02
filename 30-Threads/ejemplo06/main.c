/*!
 * @file   main.c
 * @brief  30. Threads - 06. Pasaje de múltiples parámetros a threads
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Jan 1, 2023
 */
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

typedef struct Data
{
    int a;
    int b;
} Data;

void* task(void* input);

int main(void)
{
    pthread_t thread;
    Data data;

    // Creo un thread y paso una estructura por referencia como argumento.
    data.a = 1;
    data.b = 2;
    pthread_create(&thread, NULL, task, (void*)&data);

    // Espero hasta que el thread haya terminado antes de continuar.
    pthread_join(thread, NULL);

    return 0;
}

void* task(void* input)
{
    Data value = *((Data*)input);

    printf("Dato 1 pasado como argumento: %d\n", value.a);
    printf("Dato 2 pasado como argumento: %d\n", value.b);
    printf("Ejecutando tarea...\n");
    sleep(1);
    printf("Ejecucion de tarea finalizada\n");

    return NULL;
}
