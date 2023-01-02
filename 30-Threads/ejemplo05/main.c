/*!
 * @file   main.c
 * @brief  30. Threads - 05. Pasaje de parámetros a threads
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Jan 1, 2023
 */
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* task(void* input);

int main(void)
{
    pthread_t thread;
    int value;

    // Creo un thread y paso un entero por referencia como argumento.
    value = 1;
    pthread_create(&thread, NULL, task, (void*)&value);

    // Espero hasta que el thread haya terminado antes de continuar.
    pthread_join(thread, NULL);

    return 0;
}

void* task(void* input)
{
    int value = *((int*)input);

    printf("Dato pasado como argumento: %d\n", value);
    printf("Ejecutando tarea...\n");
    sleep(1);
    printf("Ejecucion de tarea finalizada\n");

    return NULL;
}
