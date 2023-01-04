/*!
 * @file   main.c
 * @brief  30. Threads - 11. Creación de un detached thread
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Jan 3, 2023
 */
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* task();

int main(void)
{
    pthread_t thread1, thread2;

    // Creo los threads y los "detacheo".
    pthread_create(&thread1, NULL, task, NULL);
    pthread_detach(thread1);
    pthread_create(&thread2, NULL, task, NULL);
    pthread_detach(thread2);

    // Espero hasta que todos los threads hayan terminado antes de continuar
    // utilizando la función "pthread_exit". No puedo utilizar la función join
    // ya que los threads al estar "detacheados" ya no son "joineables".
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
