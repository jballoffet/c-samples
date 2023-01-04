/*!
 * @file   main.c
 * @brief  30. Threads - 09. Sincronización de threads usando Mutex
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Jan 3, 2023
 */
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int g_counter = 0;

pthread_mutex_t mutex;

void* task();
int get_counter(void);
void set_counter(int value);

int main(void)
{
    pthread_t thread1, thread2;

    // Inicializo el mutex.
    pthread_mutex_init(&mutex, NULL);

    // Creo los threads.
    pthread_create(&thread1, NULL, task, NULL);
    pthread_create(&thread2, NULL, task, NULL);

    // Espero hasta que los threads hayan terminado antes de continuar.
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destruyo el mutex.
    pthread_mutex_destroy(&mutex);

    printf("Contador: %d\n", get_counter());

    return 0;
}

void* task()
{
    int counter;

    // Tomo el mutex al comienzo de la zona crítica.
    pthread_mutex_lock(&mutex);

    counter = get_counter();
    counter++;
    set_counter(counter);

    // Libero el mutex al final de la zona crítica.
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int get_counter(void)
{
    // Agrego demoras para forzar la condición de carrera (race condition).
    usleep(1000);
    return g_counter;
}

void set_counter(int value)
{
    // Agrego demoras para forzar la condición de carrera (race condition).
    usleep(1000);
    g_counter = value;
}
