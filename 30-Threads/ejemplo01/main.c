/*!
 * @file   main.c
 * @brief  30. Threads - 01. Creación de un thread
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Dec 29, 2022
 */
#include <pthread.h>
#include <stdio.h>

// Función a ejecutar por el nuevo thread.
void* print_hello();

int main(void)
{
    // Declaro una variable de tipo pthread_t para almacenar el TID (Thread ID).
    pthread_t thread_id;

    // Creo un nuevo thread que ejecutará la función "print_hello".
    pthread_create(&thread_id, NULL, print_hello, NULL);

    // Espero hasta que el nuevo thread haya terminado antes de continuar.
    // Caso contrario, corro el riesgo de que termine el proceso (y el thread
    // nuevo) antes de que el mismo haya terminado.
    pthread_join(thread_id, NULL);

    return 0;
}

void* print_hello()
{
    printf("Hola mundo\n");

    return NULL;
}
