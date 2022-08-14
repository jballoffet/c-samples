/*!
 * @file   main.c
 * @brief  29. Comunicacion entre Procesos - 02. FIFOs - 01. FIFO (Named Pipe)
 *   entre dos programas
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Oct 19, 2018
 */
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    // Declaro un entero para almacenar el file descriptor del named pipe
    // (FIFO). Es un archivo especial.
    int fd;
    // Declaro un arreglo de caracteres para almacenar el path de la FIFO.
    char myfifo[] = "/tmp/myfifo";
    // Declaro un arreglo de caracteres para almacenar el mensaje a recibir por
    // la FIFO.
    char msg[50];

    // Creo el archivo FIFO.
    mkfifo(myfifo, 0666);

    // Abre la FIFO como sólo lectura.
    fd = open(myfifo, O_RDONLY);

    while (strncmp(msg, "exit", 4))
    {
        // Lee la FIFO hasta que llega un mensaje.
        read(fd, msg, sizeof(msg));

        // Imprime el mensaje recibido por pantalla.
        printf("Mensaje recibido: %s", msg);
    }

    // Cierra la FIFO.
    close(fd);

    return 0;
}
