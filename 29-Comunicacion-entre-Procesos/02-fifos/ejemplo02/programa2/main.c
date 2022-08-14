/*!
 * @file   main.c
 * @brief  29. Comunicacion entre Procesos - 02. FIFOs - 02. Chat entre dos
 *   programas
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
    // Declaro un arreglo de caracteres para almacenar el mensaje a enviar por
    // la FIFO.
    char msg[50];

    // Creo el archivo FIFO.
    mkfifo(myfifo, 0666);

    while (strncmp(msg, "exit", 4))
    {
        // Abre la FIFO como sólo lectura.
        fd = open(myfifo, O_RDONLY);

        // Lee la FIFO hasta que llega un mensaje y cierra la FIFO.
        read(fd, msg, sizeof(msg));
        close(fd);

        // Imprime el mensaje recibido por pantalla.
        printf("Mensaje del User1: %s", msg);

        // Abre la FIFO como sólo escritura.
        fd = open(myfifo, O_WRONLY);

        // Toma un mensaje a enviar por consola.
        printf(
            "Escriba el mensaje a enviar por la FIFO o \"exit\" para salir: ");
        fgets(msg, sizeof(msg), stdin);

        // Escribe el mensaje a enviar en la FIFO y cierra la FIFO.
        write(fd, msg, strlen(msg) + 1);
        close(fd);
    }

    return 0;
}
