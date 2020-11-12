/**
 * \file            main.c
 * \brief           35. Sockets - Ejemplo 2 - Servidor - Servidor TCP (2)
 * \author          Javier Balloffet
 * \date            Nov 4, 2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define CONNECTIONS_MAX 5       /* El número máximo de conexiones en cola de espera permitidas */
#define BUFFER_MAX 100          /* Tamaño del buffer de datos en bytes */

int main(int argc, char* argv[]) {
    int port, status, client_length, enable, message_size, clientOnline;
    char buffer[BUFFER_MAX];
    /* 1. Declaro el file descriptor para el socket que escucha conexiones entrantes */
    int listen_socket_fd;
    /* 2. Declaro el file descriptor para el socket de la conexión */
    int client_socket_fd;
    /* 3. Declaro estructura para la informacion de direccion del servidor */
    struct sockaddr_in server_data;
    /* 4. Declaro estructura para la informacion de direccion del cliente */
    struct sockaddr_in client_data;

    /* 5. Obtengo el número de puerto pasado como parámetro del main */
    if (argc < 2) {
        printf("Debe ingresar el puerto como parámetro\n");
        printf("Uso: %s <PUERTO>\n", argv[0]);
        return -1;
    } else {
        port = atoi(argv[1]);
    }

    /* 6. Creo el socket, con configuración para IPv4 y TCP */
    listen_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket_fd == -1) {
        printf("Error en socket()\n");
        return -1;
    }

    /* 7. Cargo información del servidor */
    server_data.sin_family = AF_INET;
    server_data.sin_addr.s_addr = INADDR_ANY;
    server_data.sin_port = htons(port);
    memset(&(server_data.sin_zero), 0, 8);

    /* 8. Agrego una opción al socket para evitar que el puerto quede bloqueado al cerrar el servidor */
    enable = 1;
    setsockopt(listen_socket_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable));

    /* 9. Enlazo el socket a la configuracion deseada (IP:PORT) */
    status = bind(listen_socket_fd, (struct sockaddr*) &server_data, sizeof(server_data));
    if (status == -1) {
        printf("Error en bind()\n");
        return -1;
    }

    /* 10. Escucho con el socket usando listen() */
    status = listen(listen_socket_fd, CONNECTIONS_MAX);
    if (status == -1) {
        printf("Error en listen()\n");
        return -1;
    }

    /* 11. Server corriendo esperando conexiones */
    printf("Server corriendo en el puerto: %d\n", port);

    while (1) {
        /* 12. Acepto la conexión entrante */
        client_length = sizeof(struct sockaddr_in);
        client_socket_fd = accept(listen_socket_fd, (struct sockaddr*) &client_data, (socklen_t*) &client_length);
        if (client_socket_fd == -1) {
            printf("Error en accept()\n");
            return -1;
        }

        /* 13. Muestra la IP del cliente */
        printf("Se obtuvo una conexion desde la IP: %s\n", inet_ntoa((struct in_addr) client_data.sin_addr));

        /* 14. Envía mensaje de bienvenida al cliente */
        send(client_socket_fd, "Bienvenido! Conectado al servidor!", 34, 0);
        clientOnline = 1;

        while (clientOnline) {
            /* 15. Recibe mensaje del cliente a imprimir en pantalla */
            printf("Esperando mensaje...\n");
            message_size = recv(client_socket_fd, buffer, BUFFER_MAX, 0);

            if (message_size > 0) {
                /* 16. Muestra mensaje recibido */
                buffer[message_size] = '\0';
                printf("Cliente: %s\n", buffer);
            } else {
                clientOnline = 0;
            }
        }

        /* 17. Cierra el socket del cliente */
        close(client_socket_fd);
        printf("Conexion con cliente finalizada\n");
    }

    /* 18. Cierra el socket de escucha */
    close(listen_socket_fd);
    printf("Servidor finalizado\n");

    return 0;
}
