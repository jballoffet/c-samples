/**
 * \file            main.c
 * \brief           35. Sockets - Ejemplo 4 - Servidor - Servidor TCP Concurrente (usando fork)
 * \author          Javier Balloffet
 * \date            Nov 5, 2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <signal.h>
#include "sockets_server.h"

#define BUFFER_MAX 100          /* Tamaño del buffer de datos en bytes */
#define IP_LENGTH 16

int clientsCount = 0;

void sigchld_handler();
void child_process(int client_socket_fd, struct sockaddr_in client_data);

int main(int argc, char* argv[]) {
    int port, client_length, pid, listen_socket_fd, client_socket_fd;
    struct sockaddr_in client_data;

    /* 1. Capturo la señal SIGCHLD, enviada cuando muere un proceso hijo */
    signal(SIGCHLD, sigchld_handler);

    /* 2. Obtengo el número de puerto pasado como parámetro del main */
    if (argc < 2) {
        printf("Debe ingresar el puerto como parámetro\n");
        printf("Uso: %s <PUERTO>\n", argv[0]);
        return -1;
    } else {
        port = atoi(argv[1]);
    }

    /* 3. Abro un socket tcp */
    listen_socket_fd = open_tcp_socket(port);
    if (listen_socket_fd == -1) {
        printf("Error en open_tcp_socket()");
        return -1;
    }
    
    /* 4. Server corriendo esperando conexiones */
    printf("Server corriendo en el puerto: %d\n", port);

    while (1) {
        /* 5. Acepto la conexión entrante */
        client_length = sizeof(struct sockaddr_in);
        client_socket_fd = accept(listen_socket_fd, (struct sockaddr*) &client_data, (socklen_t*) &client_length);
        if (client_socket_fd == -1) {
            printf("Error en accept()\n");
            continue;
        }

        /* 6. Genero un proceso hijo para atender al cliente, el padre se queda atendiendo llamadas */
        pid = fork();
        if (pid < 0) {
            /* 7. Error! No se pudo generar el proceso hijo */
            printf("Error en fork()\n");
            return -1;

        } else if (pid == 0) {
            /* 8. Proceso hijo */
            close(listen_socket_fd);
            child_process(client_socket_fd, client_data);
            return 0;

        } else {
            /* 9. Proceso padre */
            close(client_socket_fd);
            clientsCount++;
            printf("Nuevo cliente! Total de clientes conectados: %d\n", clientsCount);
        }
    }

    /* 10. Cierra el socket de escucha */
    close(listen_socket_fd);
    printf("Servidor finalizado\n");

    return 0;
}

void child_process(int client_socket_fd, struct sockaddr_in client_data) {
    int message_size, clientOnline;
    char clientIp[IP_LENGTH];
    char buffer[BUFFER_MAX];

    /* 11. Muestra la IP del cliente */
    strcpy(clientIp, inet_ntoa((struct in_addr) client_data.sin_addr));
    printf("Se obtuvo una conexion desde la IP: %s\n", clientIp);

    /* 12. Envía mensaje de bienvenida al cliente */
    send(client_socket_fd, "Bienvenido! Conectado al servidor!", 34, 0);
    clientOnline = 1;

    while (clientOnline) {
        /* 13. Recibe mensaje del cliente a imprimir en pantalla */
        printf("Esperando mensaje...\n");
        message_size = recv(client_socket_fd, buffer, BUFFER_MAX, 0);

        if (message_size > 0) {
            /* 14. Muestra mensaje recibido */
            buffer[message_size] = '\0';
            printf("Cliente [%s]: %s\n", clientIp, buffer);
        } else {
            clientOnline = 0;
        }
    }

    /* 15. Cierra el socket del cliente */
    close(client_socket_fd);
    printf("Conexion con cliente finalizada\n");
}

void sigchld_handler() {
    /* 16. "Sepulto" al hijo */
    while (waitpid((pid_t)(-1), 0, WNOHANG) > 0);
    clientsCount--;
    printf("Cliente desconectado! Total de clientes conectados: %d\n", clientsCount);
}
