/*!
 * @file   main.c
 * @brief  30. Threads - 04. Uso de pthread_exit()
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Dec 29, 2022
 */
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* task();

int main(void)
{
    pthread_t thread1, thread2;

    // Creo los threads.
    pthread_create(&thread1, NULL, task, NULL);
    pthread_create(&thread2, NULL, task, NULL);

    // Espero hasta que todos los threads hayan terminado antes de continuar
    // utilizando la función "pthread_exit".
    pthread_exit(NULL);

    return 0;
}

void* task()
{
    printf("Ejecutando tarea...\n");
    sleep(1);
    printf("Ejecucion de tarea finalizada\n");

    return NULL;
}
