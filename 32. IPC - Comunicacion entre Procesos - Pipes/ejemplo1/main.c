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
    // 2. Declaro un arreglo de dos enteros para almacenar el descriptor del pipe (tubería)
    int fd[2];
    // 3. Declaro un arreglo de caracteres para almacenar el mensaje a enviar por el pipe
    char msg[25];

    // 4. Creo el pipe y verifico que no devuelva error
    if (pipe(fd) == -1) {
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
        // 7. Proceso hijo. Escucha por el pipe hasta que llegue un mensaje (bloqueante)
        printf("Hijo: Hola!\n");
        read(fd[0], msg, 22);
        printf("Hijo: Mi padre dijo \"%s\"\n", msg);
        printf("Hijo: Chau!\n");

    } else if (pid > 0) {
        // 8. Proceso padre. Escribe en el pipe.
        printf("Padre: Hola!\n");
        write(fd[1], "Luke, yo soy tu padre", 22);

        // 9. Hago que el padre espere a que su hijo muera antes de morir él
        printf("Padre: Esperando a que mi hijo muera...\n");
        wait(NULL);
        printf("Padre: Chau!\n");
    }

    return 0; 
}
