/**
 * \file            main.c
 * \brief           35. Sockets - Ejemplo 3 - Servidor - Servidor TCP Concurrente (usando fork)
 * \author          Javier Balloffet
 * \date            Nov 5, 2018
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
#define IP_LENGTH 16

int main(int argc, char* argv[]) {
    int port, status, clientLength, enable, messageSize, clientOnline, pid;
    char buffer[BUFFER_MAX];
    char clientIp[IP_LENGTH];
    /* 1. Declaro el file descriptor para el socket que escucha conexiones entrantes */
    int listenSocketFd;
    /* 2. Declaro el file descriptor para el socket de la conexión */
    int clientSocketFd;
    /* 3. Declaro estructura para la informacion de direccion del servidor */
    struct sockaddr_in serverData;
    /* 4. Declaro estructura para la informacion de direccion del cliente */
    struct sockaddr_in clientData;

    /* 5. Obtengo el número de puerto pasado como parámetro del main */
    if (argc < 2) {
        printf("Debe ingresar el puerto como parámetro\n");
        printf("Uso: %s <PUERTO>\n", argv[0]);
        return -1;
    } else {
        port = atoi(argv[1]);
    }

    /* 6. Creo el socket, con configuración para IPv4 y TCP */
    listenSocketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenSocketFd == -1) {
        printf("Error en socket()\n");
        return -1;
    }

    /* 7. Cargo información del servidor */
    serverData.sin_family = AF_INET;
    serverData.sin_addr.s_addr = INADDR_ANY;
    serverData.sin_port = htons(port);
    memset(&(serverData.sin_zero), 0, 8);

    /* 8. Agrego una opción al socket para evitar que el puerto quede bloqueado al cerrar el servidor */
    enable = 1;
    setsockopt(listenSocketFd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable));

    /* 9. Enlazo el socket a la configuracion deseada (IP:PORT) */
    status = bind(listenSocketFd, (struct sockaddr*) &serverData, sizeof(serverData));
    if (status == -1) {
        printf("Error en bind()\n");
        return -1;
    }

    /* 10. Escucho con el socket usando listen() */
    status = listen(listenSocketFd, CONNECTIONS_MAX);
    if (status == -1) {
        printf("Error en listen()\n");
        return -1;
    }

    /* 11. Server corriendo esperando conexiones */
    printf("Server corriendo en el puerto: %d\n", port);

    while (1) {
        /* 12. Acepto la conexión entrante */
        clientLength = sizeof(struct sockaddr_in);
        clientSocketFd = accept(listenSocketFd, (struct sockaddr*) &clientData, (socklen_t*) &clientLength);
        if (clientSocketFd == -1) {
            printf("Error en accept()\n");
            continue;
        }

        /* 13. Genero un proceso hijo para atender al cliente, el padre se queda atendiendo llamadas */
        pid = fork();
        if (pid < 0) {
            /* 14. Error! No se pudo generar el proceso hijo */
            printf("Error en fork()\n");
            return -1;

        } else if (pid == 0) {
            /* 15. Proceso hijo */
            /* 16. Cierro socket de escucha */
            close(listenSocketFd);

            /* 17. Muestra la IP del cliente */
            strcpy(clientIp, inet_ntoa((struct in_addr) clientData.sin_addr));
            printf("Se obtuvo una conexion desde la IP: %s\n", clientIp);

            /* 18. Envía mensaje de bienvenida al cliente */
            send(clientSocketFd, "Bienvenido! Conectado al servidor!", 34, 0);
            clientOnline = 1;

            while (clientOnline) {
                /* 19. Recibe mensaje del cliente a imprimir en pantalla */
                printf("Esperando mensaje...\n");
                messageSize = recv(clientSocketFd, buffer, BUFFER_MAX, 0);

                if (messageSize > 0) {
                    /* 20. Muestra mensaje recibido */
                    buffer[messageSize] = '\0';
                    printf("Cliente [%s]: %s\n", clientIp, buffer);
                } else {
                    clientOnline = 0;
                }
            }

            /* 21. Cierra el socket del cliente */
            close(clientSocketFd);
            printf("Conexion con cliente finalizada\n");

            return 0;

        } else {
            /* 22. Proceso padre */
            close(clientSocketFd);
        }
    }

    /* 23. Cierra el socket de escucha */
    close(listenSocketFd);
    printf("Servidor finalizado\n");

    return 0;
}
