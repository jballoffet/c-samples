/*!
 * @file   main.c
 * @brief  28. Procesos - 01. Proceso Padre y Proceso Hijo
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Oct 19, 2018
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    // Declaro un entero para almacenar el PID (Process ID).
    int pid;

    // Genero un nuevo proceso utilizando la función "fork".
    pid = fork();

    // A partir de aca se duplicó la ejecución en dos procesos. Utilizo el valor
    // devuelto por "fork" para saber en qué proceso me encuentro.
    if (pid < 0)
    {
        // Error! No se pudo generar el proceso hijo :(.
        printf("Error al generar el proceso hijo\n");
        return 1;
    }
    else if (pid == 0)
    {
        // Esto se ejecuta sólo en el proceso hijo.
        printf("Hijo: Hola, soy el proceso hijo!\n");
        printf("Hijo: Mi PID es %d\n", getpid());
        printf("Hijo: El PID de mi padre es %d\n", getppid());
        printf("Hijo: Chau!\n");
    }
    else if (pid > 0)
    {
        // Esto se ejecuta sólo en el proceso padre.
        printf("Padre: Hola, soy el proceso padre!\n");
        printf("Padre: Mi PID es %d\n", getpid());
        printf("Padre: El PID de mi hijo es %d\n", pid);

        // Hago que el padre espere a que su hijo muera antes de morir él.
        printf("Padre: Esperando a que mi hijo muera...\n");
        wait(NULL);
        printf("Padre: Chau!\n");
    }

    return 0;
}
