/**
 * \file            main.c
 * \brief           32. IPC - Comunicacion entre Procesos - Pipes - Ejemplo 2 - Dos pipes entre padre e hijo
 * \author          Javier Balloffet
 * \date            20-OCT-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define READ_END 0
#define WRITE_END 1

int main() {
    // 1. Declaro un entero para almacenar el PID (Process ID)
    int pid;
    // 2. Declaro dos descriptores de pipes
    int pipefd1[2];
    int pipefd2[2];
    // 3. Declaro un arreglo de caracteres para almacenar el mensaje a enviar por el pipe
    char msg[25];

    // 4. Creo los pipes y verifico que no devuelva error
    if ((pipe(pipefd1) == -1) || (pipe(pipefd2) == -1)) {
        perror("Error al crear los pipes\n");
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
        // 8. Cierro el extremo de escritura del primer pipe y el extremo del lectura del segundo pipe (que el hijo no usa)
        close(pipefd1[WRITE_END]);
        close(pipefd2[READ_END]);

        // 9. Escucha por el primer pipe hasta que llegue un mensaje (bloqueante)
        printf("Hijo: Hola!\n");
        read(pipefd1[READ_END], msg, 22);
        printf("Hijo: Mi padre dijo \"%s\"\n", msg);

        // 10. Cierra el extremo de lectura del primer pipe
        close(pipefd1[READ_END]);

        // 11. Escribe en el segundo pipe
        write(pipefd2[WRITE_END], "Nooooooo!!!", 12);

        // 12. Cierra el extremo de escritura del segundo pipe
        close(pipefd2[WRITE_END]);

        printf("Hijo: Chau!\n");

    } else if (pid > 0) {
        // 13. Proceso padre
        // 14. Cierro el extremo de lectura del primer pipe y el extremo de escritura del segundo pipe (que el padre no usa)
        close(pipefd1[READ_END]);
        close(pipefd2[WRITE_END]);

        // 15. Escribe en el primer pipe
        printf("Padre: Hola!\n");
        write(pipefd1[WRITE_END], "Luke, yo soy tu padre", 22);

        // 16. Cierra el extremo de escritura del primer pipe
        close(pipefd1[WRITE_END]);

        // 17. Escucha por el segundo pipe hasta que llegue el mensaje de respuesta (bloqueante)
        read(pipefd2[READ_END], msg, 12);
        printf("Padre: Mi hijo dijo \"%s\"\n", msg);

        // 18. Cierra el extremo de lectura del segundo pipe
        close(pipefd2[READ_END]);

        // 19. Hago que el padre espere a que su hijo muera antes de morir él
        printf("Padre: Esperando a que mi hijo muera...\n");
        wait(NULL);
        printf("Padre: Chau!\n");
    }

    return 0; 
}
