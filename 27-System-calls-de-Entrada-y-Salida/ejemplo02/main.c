/*!
 * @file   main.c
 * @brief  27. System calls de Entrada y Salida - 02. Leyendo un archivo usando
 *   system calls
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Dec 29, 2022
 */
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    int fd;
    char message[60];
    int bytes_read = 0;

    // Abro el archivo en modo sólo lectura.
    fd = open("archivo.txt", O_RDONLY);

    // Chequeo si hubo un error al abrir el archivo.
    if (fd == -1)
    {
        printf("Error abriendo el archivo!\n");
        return -1;
    }

    // Leo el archivo e imprimo en pantalla el mensaje obtenido.
    bytes_read = read(fd, message, 60);
    message[bytes_read] = '\0';
    printf("%s", message);

    // Cierro el archivo.
    close(fd);

    return 0;
}
