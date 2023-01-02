/*!
 * @file   main.c
 * @brief  30. Threads - 03. Creación de múltiples threads con distintas tareas
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Dec 29, 2022
 */
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* task1();
void* task2();

int main(void)
{
    // Declaro variables de tipo pthread_t para almacenar el TID (Thread ID).
    pthread_t thread1, thread2;

    // Creo los threads.
    pthread_create(&thread1, NULL, task1, NULL);
    pthread_create(&thread2, NULL, task2, NULL);

    // Espero hasta que los threads hayan terminado antes de continuar.
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

void* task1()
{
    printf("Ejecutando tarea 1...\n");
    sleep(1);
    printf("Ejecucion de tarea 1 finalizada\n");

    return NULL;
}

void* task2()
{
    printf("Ejecutando tarea 2...\n");
    sleep(1);
    printf("Ejecucion de tarea 2 finalizada\n");

    return NULL;
}
