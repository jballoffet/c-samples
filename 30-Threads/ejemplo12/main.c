/*!
 * @file   main.c
 * @brief  30. Threads - 12. Creación de un detached thread usando atributos
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
    // Declaro una variable para el atributo.
    pthread_attr_t attribute;

    // Inicializo el atributo.
    pthread_attr_init(&attribute);

    // Asigno el estado detached al atributo.
    pthread_attr_setdetachstate(&attribute, PTHREAD_CREATE_DETACHED);

    // Creo los threads pasando la configuración deseada.
    pthread_create(&thread1, &attribute, task, NULL);
    pthread_create(&thread2, &attribute, task, NULL);

    // Destruyo el atributo.
    pthread_attr_destroy(&attribute);

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
