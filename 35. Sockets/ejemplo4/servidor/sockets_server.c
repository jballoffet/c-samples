/**
 * \file            sockets_server.c
 * \brief           35. Sockets - Ejemplo 4 - Servidor - Servidor TCP Concurrente (usando fork)
 * \author          Javier Balloffet
 * \date            05-NOV-2018
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
#include "sockets_server.h"

#define CONNECTIONS_MAX 5    // El número máximo de conexiones en cola de espera permitidas

int open_tcp_socket(int port) {
    int socketFd, status, enable;
    struct sockaddr_in serverData;

    // 1. Creo el socket, con configuración para IPv4 y TCP
    socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFd == -1) {
        printf("Error en socket()\n");
        return -1;
    }

    // 2. Cargo información del servidor
    serverData.sin_family = AF_INET;
    serverData.sin_addr.s_addr = INADDR_ANY;
    serverData.sin_port = htons(port);
    memset(&(serverData.sin_zero), 0, 8);

    // 3. Agrego una opción al socket para evitar que el puerto quede bloqueado al cerrar el servidor
    enable = 1;
    setsockopt(socketFd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable));

    // 4. Enlazo el socket a la configuracion deseada (IP:PORT)
    status = bind(socketFd, (struct sockaddr*) &serverData, sizeof(serverData));
    if (status == -1) {
        printf("Error en bind()\n");
        return -1;
    }

    // 5. Escucho con el socket usando listen()
    status = listen(socketFd, CONNECTIONS_MAX);
    if (status == -1) {
        printf("Error en listen()\n");
        return -1;
    }

    return socketFd;
}
