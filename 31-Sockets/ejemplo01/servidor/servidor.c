/*!
 * @file   main.c
 * @brief  31. Sockets - 01. Cliente-Servidor TCP
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Nov 11, 2020
 */
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

// Número máximo de conexiones en cola de espera permitidas.
#define CONNECTIONS_MAX 5

int main(int argc, char* argv[])
{
    int port, status, client_length, enable;
    // Declaro el file descriptor para el socket que escucha conexiones
    // entrantes.
    int listen_socket_fd;
    // Declaro el file descriptor para el socket de la conexión.
    int client_socket_fd;
    // Declaro una estructura para la información de dirección del servidor.
    struct sockaddr_in server_data;
    // Declaro una estructura para la información de dirección del cliente.
    struct sockaddr_in client_data;

    // Obtengo el número de puerto pasado como argumento del main.
    if (argc < 2)
    {
        printf("Debe ingresar el puerto como parametro.\n");
        printf("Uso: %s <PUERTO>\n", argv[0]);
        return -1;
    }

    port = atoi(argv[1]);
    if (port == 0)
    {
        printf("Puerto invalido.\n");
        return -1;
    }

    // Creo el socket de escucha, con configuración para IPv4 y TCP.
    listen_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket_fd == -1)
    {
        printf("Error en socket().\n");
        return -1;
    }

    // Cargo la información del servidor.
    server_data.sin_family = AF_INET;
    server_data.sin_addr.s_addr = INADDR_ANY;
    server_data.sin_port = htons(port);
    memset(&(server_data.sin_zero), 0, 8);

    // Agrego una opción al socket para evitar que el puerto quede bloqueado al
    // cerrar el servidor.
    enable = 1;
    setsockopt(listen_socket_fd, SOL_SOCKET, SO_REUSEADDR, &enable,
               sizeof(enable));

    // Enlazo el socket a la configuracion deseada (IP:PORT).
    status = bind(listen_socket_fd, (struct sockaddr*)&server_data,
                  sizeof(server_data));
    if (status == -1)
    {
        printf("Error en bind().\n");
        return -1;
    }

    // Configuro el socket de escucha para escuchar conexiones entrantes.
    status = listen(listen_socket_fd, CONNECTIONS_MAX);
    if (status == -1)
    {
        printf("Error en listen().\n");
        return -1;
    }

    // Servidor corriendo esperando conexiones entrantes.
    printf("Servidor corriendo en el puerto: %d.\n", port);
    while (1)
    {
        // Acepto la conexión entrante.
        client_length = sizeof(struct sockaddr_in);
        client_socket_fd =
            accept(listen_socket_fd, (struct sockaddr*)&client_data,
                   (socklen_t*)&client_length);
        if (client_socket_fd == -1)
        {
            printf("Error en accept().\n");
            return -1;
        }

        // Muestro la IP del cliente.
        printf("Se obtuvo una conexion desde la IP: %s.\n",
               inet_ntoa((struct in_addr)client_data.sin_addr));

        // Envío mensaje de bienvenida al cliente.
        send(client_socket_fd, "Bienvenido! Conectado al servidor!", 34, 0);

        // Cierro el socket del cliente.
        close(client_socket_fd);
        printf("Conexion con cliente finalizada.\n");
    }

    // Cierro el socket de escucha.
    close(listen_socket_fd);
    printf("Servidor finalizado.\n");

    return 0;
}
