/**
 * \file            main.c
 * \brief           33. IPC - Comunicacion entre Procesos - Named Pipes o FIFOs - Ejemplo 1 - Receptor - Named Pipe entre dos programas
 * \author          Javier Balloffet
 * \date            26-OCT-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main() {
    // 1. Declaro un entero para almacenar el file descriptor del named pipe (FIFO). Es un archivo especial
    int fd;
    // 2. Declaro un arreglo de caracteres para almacenar el path de la FIFO
    char myfifo[] = "/tmp/myfifo";
    // 3. Declaro un arreglo de caracteres para almacenar el mensaje a recibir por la FIFO
    char msg[50];

    // 4. Creo el archivo FIFO
    mkfifo(myfifo, 0666);

    // 5. Abre la FIFO como sólo lectura
    fd = open(myfifo, O_RDONLY);

    while (strncmp(msg, "exit", 4)) {
        // 6. Lee la FIFO hasta que llega un mensaje
        read(fd, msg, sizeof(msg));

        // 7. Imprime el mensaje recibido por pantalla
        printf("Mensaje recibido: %s", msg);
    }

    // 8. Cierra la FIFO
    close(fd);

    return 0;
}
