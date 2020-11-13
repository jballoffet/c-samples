/*!
 * @file   main.c
 * @brief  35. Sockets - 03. Cliente-Servidor TCP
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Nov 11, 2020
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sockets.h"

#define BUFFER_MAX 100  // Tamaño del buffer de datos en bytes.

typedef enum ClientStatus {
    CONNECTED = 0,
    DISCONNECTED
} ClientStatus;

int main(int argc, char* argv[]) {
    int socket_fd, message_size, client_status;
    char buffer[BUFFER_MAX];

    // Obtengo el número de IP y de puerto pasados como argumentos del main.
    if (argc < 3) {
        printf("Debe ingresar la IP y el puerto como parametros.\n");
        printf("Uso: %s <IP> <PUERTO>\n", argv[0]);
        return -1;
    }

    // Abro el socket, con configuración para IPv4 y TCP.
    socket_fd = abrir_socket_tcp_cliente(argv[1], atoi(argv[2]));
    if (socket_fd < 0) {
        printf("Error abriendo el socket: %d.\n", socket_fd);
        return -1;
    }

    // Cliente conectado al servidor.
    client_status = CONNECTED;
    printf("Cliente conectado al servidor.\n");

    // Recibo el mensaje de bienvenida y coloco el último caracter recibido como NULL, por si acaso.
    message_size = recibir_datos_tcp(socket_fd, buffer, BUFFER_MAX);
    if (message_size < 0) {
        printf("Error recibiendo datos del servidor.\n");
        return -1; 
    }
    buffer[message_size] = '\0';

    // Muestro mensaje recibido del servidor.
    printf("Servidor: %s\n", buffer);

    while (client_status == CONNECTED) {
        // Envia mensajes al servidor hasta recibir "/exit".
        printf("Escriba el mensaje a enviar (o \"/exit\" para salir): ");
        fgets(buffer, BUFFER_MAX, stdin);
        buffer[strlen(buffer) - 1] = '\0';

        if (!strcmp(buffer, "/exit")) {
            client_status = DISCONNECTED;
        } else {
            // Envío mensaje de bienvenida al cliente.
            message_size = enviar_datos_tcp(socket_fd, buffer, strlen(buffer));
            if (message_size < 0) {
                printf("Error enviando datos al cliente.\n");
                client_status = DISCONNECTED;
            }
        }
    }

    // Cierro conexión.
    cerrar_socket_tcp(socket_fd);
    printf("Conexion con servidor finalizada.\n");

    return 0;
}
