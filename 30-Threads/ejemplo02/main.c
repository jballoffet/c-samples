/*!
 * @file   main.c
 * @brief  30. Threads - 02. Creación de múltiples threads
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Dec 29, 2022
 */
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* task();

int main(void)
{
    // Declaro variables de tipo pthread_t para almacenar el TID (Thread ID).
    pthread_t thread1, thread2;

    // Creo los threads.
    pthread_create(&thread1, NULL, task, NULL);
    pthread_create(&thread2, NULL, task, NULL);

    // Espero hasta que los threads hayan terminado antes de continuar.
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

void* task()
{
    printf("Ejecutando tarea...\n");
    sleep(1);
    printf("Ejecucion de tarea finalizada\n");

    return NULL;
}
