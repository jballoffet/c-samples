/**
 * \file            main.c
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
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <signal.h>
#include "sockets_server.h"

#define BUFFER_MAX 100      // Tamaño del buffer de datos en bytes
#define IP_LENGTH 16

int clientsCount = 0;

void sigchld_handler();
void child_process(int clientSocketFd, struct sockaddr_in clientData);

int main(int argc, char* argv[]) {
    int port, clientLength, pid, listenSocketFd, clientSocketFd;
    struct sockaddr_in clientData;

    // 1. Capturo la señal SIGCHLD, enviada cuando muere un proceso hijo
    signal(SIGCHLD, sigchld_handler);

    // 2. Obtengo el número de puerto pasado como parámetro del main
    if (argc < 2) {
        printf("Debe ingresar el puerto como parámetro\n");
        printf("Uso: %s <PUERTO>\n", argv[0]);
        return -1;
    } else {
        port = atoi(argv[1]);
    }

    // 3. Abro un socket tcp
    listenSocketFd = open_tcp_socket(port);
    if (listenSocketFd == -1) {
        printf("Error en open_tcp_socket()");
        return -1;
    }
    
    // 4. Server corriendo esperando conexiones
    printf("Server corriendo en el puerto: %d\n", port);

    while (1) {
        // 5. Acepto la conexión entrante
        clientLength = sizeof(struct sockaddr_in);
        clientSocketFd = accept(listenSocketFd, (struct sockaddr*) &clientData, (socklen_t*) &clientLength);
        if (clientSocketFd == -1) {
            printf("Error en accept()\n");
            continue;
        }

        // 6. Genero un proceso hijo para atender al cliente, el padre se queda atendiendo llamadas
        pid = fork();
        if (pid < 0) {
            // 7. Error! No se pudo generar el proceso hijo
            printf("Error en fork()\n");
            return -1;

        } else if (pid == 0) {
            // 8. Proceso hijo
            close(listenSocketFd);
            child_process(clientSocketFd, clientData);
            return 0;

        } else {
            // 9. Proceso padre
            close(clientSocketFd);
            clientsCount++;
            printf("Nuevo cliente! Total de clientes conectados: %d\n", clientsCount);
        }
    }

    // 10. Cierra el socket de escucha
    close(listenSocketFd);
    printf("Servidor finalizado\n");

    return 0;
}

void child_process(int clientSocketFd, struct sockaddr_in clientData) {
    int messageSize, clientOnline;
    char clientIp[IP_LENGTH];
    char buffer[BUFFER_MAX];

    // 11. Muestra la IP del cliente
    strcpy(clientIp, inet_ntoa((struct in_addr) clientData.sin_addr));
    printf("Se obtuvo una conexion desde la IP: %s\n", clientIp);

    // 12. Envía mensaje de bienvenida al cliente
    send(clientSocketFd, "Bienvenido! Conectado al servidor!", 34, 0);
    clientOnline = 1;

    while (clientOnline) {
        // 13. Recibe mensaje del cliente a imprimir en pantalla
        printf("Esperando mensaje...\n");
        messageSize = recv(clientSocketFd, buffer, BUFFER_MAX, 0);

        if (messageSize > 0) {
            // 14. Muestra mensaje recibido
            buffer[messageSize] = '\0';
            printf("Cliente [%s]: %s\n", clientIp, buffer);
        } else {
            clientOnline = 0;
        }
    }

    // 15. Cierra el socket del cliente
    close(clientSocketFd);
    printf("Conexion con cliente finalizada\n");
}

void sigchld_handler() {
    // 16. "Sepulto" al hijo
    while (waitpid((pid_t)(-1), 0, WNOHANG) > 0);
    clientsCount--;
    printf("Cliente desconectado! Total de clientes conectados: %d\n", clientsCount);
}
