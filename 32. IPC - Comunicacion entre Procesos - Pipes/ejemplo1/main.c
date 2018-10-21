/**
 * \file            main.c
 * \brief           32. IPC - Comunicacion entre Procesos - Pipes - Ejemplo 1 - Pipe entre Padre e Hijo
 * \author          Javier Balloffet
 * \date            19-OCT-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    // 1. Declaro un entero para almacenar el PID (Process ID)
    int pid;
    // 2. Declaro un arreglo de dos enteros para almacenar el descriptor del pipe (tubería), donde pipefd[0] es el extremo de lectura y pipefd[1] es el extremo de escritura
    int pipefd[2];
    // 3. Declaro un arreglo de caracteres para almacenar el mensaje a enviar por el pipe
    char msg[25];

    // 4. Creo el pipe y verifico que no devuelva error
    if (pipe(pipefd) == -1) {
        perror("Error al crear el pipe\n");
        exit(1);
    }

    // 5. Genero un nuevo proceso utilizando la función "fork"
    pid = fork();

    // 6. Separo la ejecución del padre y del hijo
    if (pid < 0) {
        perror("Error al generar el proceso hijo\n");
        exit(2);        

    } else if (pid == 0) {
        // 7. Proceso hijo
        // 8. Cierro el extremo de escritura (que el hijo no usa)
        close(pipefd[1]);

        // 9. Escucha por el pipe hasta que llegue un mensaje (bloqueante)
        printf("Hijo: Hola!\n");
        read(pipefd[0], msg, 22);
        printf("Hijo: Mi padre dijo \"%s\"\n", msg);

        // 10. Cierra el extremo de lectura
        close(pipefd[0]);
        printf("Hijo: Chau!\n");

    } else if (pid > 0) {
        // 11. Proceso padre
        // 12. Cierro el extremo de lectura (que el padre no usa)
        close(pipefd[0]);

        // 13. Escribe en el pipe.
        printf("Padre: Hola!\n");
        write(pipefd[1], "Luke, yo soy tu padre", 22);

        // 14. Cierra el extremo de escritura
        close(pipefd[1]);

        // 15. Hago que el padre espere a que su hijo muera antes de morir él
        printf("Padre: Esperando a que mi hijo muera...\n");
        wait(NULL);
        printf("Padre: Chau!\n");
    }

    return 0; 
}
