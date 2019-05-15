/**
 * \file            main.c
 * \brief           31. Procesos - Ejemplo 1 - Proceso Padre y Proceso Hijo
 * \author          Javier Balloffet
 * \date            Oct 19, 2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    /* 1. Declaro un entero para almacenar el PID (Process ID) */
    int pid;

    /* 2. Genero un nuevo proceso utilizando la función "fork" */
    pid = fork();

    /* 3. A partir de aca se duplicó la ejecución en dos procesos. Utilizo el valor devuelto por "fork" para saber en qué proceso me encuentro */
    if (pid < 0) {
        /* 4. Error! No se pudo generar el proceso hijo :( */
        printf("Error al generar el proceso hijo\n");
        return 1;

    } else if (pid == 0) {
        /* 5. Esto se ejecuta sólo en el proceso hijo */
        printf("Hijo: Hola, soy el proceso hijo!\n");
        printf("Hijo: Mi PID es %d\n", getpid());
        printf("Hijo: El PID de mi padre es %d\n", getppid());
        printf("Hijo: Chau!\n");

    } else if (pid > 0) {
        /* 6. Esto se ejecuta sólo en el proceso padre */
        printf("Padre: Hola, soy el proceso padre!\n");
        printf("Padre: Mi PID es %d\n", getpid());
        printf("Padre: El PID de mi hijo es %d\n", pid);

        /* 7. Hago que el padre espere a que su hijo muera antes de morir él */
        printf("Padre: Esperando a que mi hijo muera...\n");
        wait(NULL);
        printf("Padre: Chau!\n");
    }

    return 0; 
}
