/*!
 * @file   main.c
 * @brief  30. Threads - 07. Retorno de valores desde threads
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Jan 1, 2023
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
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
    int* sum = NULL;

    // Creo un thread y paso una estructura por referencia como argumento.
    data.a = 1;
    data.b = 2;
    pthread_create(&thread, NULL, task, (void*)&data);

    // Espero hasta que el thread haya terminado antes de continuar.
    pthread_join(thread, (void**)&sum);

    // Imprimo el resultado obtenido.
    printf("Resultado obtenido: %d\n", *sum);

    // Libero la memoria pedida por el thread para almacenar el resultado
    // obtenido.
    free(sum);

    return 0;
}

void* task(void* input)
{
    Data* value = (Data*)input;
    int* result = NULL;

    printf("Dato 1 pasado como argumento: %d\n", value->a);
    printf("Dato 2 pasado como argumento: %d\n", value->b);
    printf("Ejecutando tarea...\n");

    // Reservo memoria para poder almacenar el resultado obtenido.
    result = malloc(sizeof(int));
    if (result == NULL)
    {
        return NULL;
    }

    *result = value->a + value->b;
    sleep(1);

    printf("Ejecucion de tarea finalizada\n");

    pthread_exit(result);
}
