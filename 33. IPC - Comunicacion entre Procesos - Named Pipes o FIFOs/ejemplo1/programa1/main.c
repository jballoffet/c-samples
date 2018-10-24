/**
 * \file            main.c
 * \brief           33. IPC - Comunicacion entre Procesos - Named Pipes o FIFOs - Ejemplo 1 - Programa 1 - Named Pipe entre dos programas
 * \author          Javier Balloffet
 * \date            23-OCT-2018
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
    // 3. Declaro un arreglo de caracteres para almacenar el mensaje a enviar por la FIFO
    char msg[50];

    // 4. Creo el archivo FIFO
    mkfifo(myfifo, 0666);
    
    while (1) {
        // 5. Abre la FIFO como sólo escritura
        fd = open(myfifo, O_WRONLY);

        // 6. Toma un mensaje a enviar por consola
        fgets(msg, sizeof(msg), stdin);

        // 7. Escribe el mensaje a enviar en la FIFO y cierra la FIFO
        write(fd, msg, strlen(msg) + 1);
        close(fd);

        // 8. Abre la FIFO como sólo lectura
        fd = open(myfifo, O_RDONLY);

        // 9. Lee la FIFO hasta que llega un mensaje y cierra la FIFO
        read(fd, msg, sizeof(msg));
        close(fd);

        // 10. Imprime el mensaje recibido por pantalla
        printf("User2: %s\n", msg);
    }

    return 0;
}
