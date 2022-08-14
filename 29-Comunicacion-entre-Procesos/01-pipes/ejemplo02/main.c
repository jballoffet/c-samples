/*!
 * @file   main.c
 * @brief  29. Comunicacion entre Procesos - 01. Pipes - 02. Dos pipes entre
 *   padre e hijo
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Oct 19, 2018
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define READ_END 0
#define WRITE_END 1

int main(void)
{
    // Declaro un entero para almacenar el PID (Process ID).
    int pid;
    // Declaro dos descriptores de pipes.
    int pipefd1[2];
    int pipefd2[2];
    // Declaro un arreglo de caracteres para almacenar el mensaje a enviar por
    // el pipe.
    char msg[25];

    // Creo los pipes y verifico que no devuelva error.
    if ((pipe(pipefd1) == -1) || (pipe(pipefd2) == -1))
    {
        perror("Error al crear los pipes\n");
        exit(1);
    }

    // Genero un nuevo proceso utilizando la función "fork".
    pid = fork();

    // Separo la ejecución del padre y del hijo.
    if (pid < 0)
    {
        perror("Error al generar el proceso hijo\n");
        exit(2);
    }
    else if (pid == 0)
    {
        // Proceso hijo.
        // Cierro el extremo de escritura del primer pipe y el extremo del
        // lectura del segundo pipe (que el hijo no usa).
        close(pipefd1[WRITE_END]);
        close(pipefd2[READ_END]);

        // Escucho por el primer pipe hasta que llegue un mensaje (bloqueante).
        printf("Hijo: Hola!\n");
        read(pipefd1[READ_END], msg, 22);
        printf("Hijo: Mi padre dijo \"%s\"\n", msg);

        // Cierro el extremo de lectura del primer pipe.
        close(pipefd1[READ_END]);

        // Escribo en el segundo pipe.
        write(pipefd2[WRITE_END], "Nooooooo!!!", 12);

        // Cierro el extremo de escritura del segundo pipe.
        close(pipefd2[WRITE_END]);

        printf("Hijo: Chau!\n");
    }
    else if (pid > 0)
    {
        // Proceso padre.
        // Cierro el extremo de lectura del primer pipe y el extremo de
        // escritura del segundo pipe (que el padre no usa).
        close(pipefd1[READ_END]);
        close(pipefd2[WRITE_END]);

        // Escribo en el primer pipe.
        printf("Padre: Hola!\n");
        write(pipefd1[WRITE_END], "Luke, yo soy tu padre", 22);

        // Cierro el extremo de escritura del primer pipe.
        close(pipefd1[WRITE_END]);

        // Escucho por el segundo pipe hasta que llegue el mensaje de respuesta
        // (bloqueante).
        read(pipefd2[READ_END], msg, 12);
        printf("Padre: Mi hijo dijo \"%s\"\n", msg);

        // Cierro el extremo de lectura del segundo pipe.
        close(pipefd2[READ_END]);

        // Hago que el padre espere a que su hijo muera antes de morir él.
        printf("Padre: Esperando a que mi hijo muera...\n");
        wait(NULL);
        printf("Padre: Chau!\n");
    }

    return 0;
}
