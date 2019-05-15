/**
 * \file            main.c
 * \brief           33. IPC - Comunicacion entre Procesos - Named Pipes o FIFOs - Ejemplo 1 - Transmisor - Named Pipe entre dos programas
 * \author          Javier Balloffet
 * \date            Oct 28, 2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main() {
    /* 1. Declaro un entero para almacenar el file descriptor del named pipe (FIFO). Es un archivo especial */
    int fd;
    /* 2. Declaro un arreglo de caracteres para almacenar el path de la FIFO */
    char myfifo[] = "/tmp/myfifo";
    /* 3. Declaro un arreglo de caracteres para almacenar el mensaje a enviar por la FIFO */
    char msg[50];

    /* 4. Creo el archivo FIFO */
    mkfifo(myfifo, 0666);
    
    /* 5. Abre la FIFO como sólo escritura */
    fd = open(myfifo, O_WRONLY);

    while (strncmp(msg, "exit", 4)) {
        /* 6. Toma un mensaje a enviar por consola */
        printf("Escriba el mensaje a enviar por la FIFO o \"exit\" para salir: ");
        fgets(msg, sizeof(msg), stdin);

        /* 7. Escribe el mensaje a enviar en la FIFO */
        write(fd, msg, strlen(msg) + 1);
    }

    /* 8. Cierra la FIFO */
    close(fd);

    return 0;
}
