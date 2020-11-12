/**
 * \file            main.c
 * \brief           35. Sockets - Ejemplo 4 - Cliente - Servidor TCP Concurrente (usando fork)
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
#include <netdb.h>

#define BUFFER_MAX 100      /* Tamaño del buffer de datos en bytes */

int main(int argc, char* argv[]) {
    int server_port, status, message_size, clientOnline, sentBytes;
    char buffer[BUFFER_MAX];
    /* 1. Declaro el file descriptor para el socket de la conexión */
    int client_socket_fd;
    /* 2. Declaro estructura para la informacion de direccion del servidor */
    struct sockaddr_in server_data;
    /* 3. Declaro un puntero a una estructura donde gethostbyname() me retornara la IP */
    struct hostent* host_data;

    /* 4. Obtengo el número de IP y de puerto pasados como parámetros del main */
    if (argc < 3) {
        printf("Debe ingresar la IP y el puerto como parametros\n");
        printf("Uso: %s <IP> <PUERTO>\n", argv[0]);
        return -1;
    } else {
        host_data = gethostbyname(argv[1]);
        if (host_data == NULL) {
            printf("Error en gethostbyname()\n");
            return -1;
        }

        server_port = atoi(argv[2]);
    }

    /* 5. Creo el socket, con configuración para IPv4 y TCP */
    client_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket_fd == -1) {
        printf("Error en socket()\n");
        return -1;
    }

    /* 6. Cargo información del servidor */
    server_data.sin_family = AF_INET;
    memcpy(&(server_data.sin_addr), host_data->h_addr_list[0], host_data->h_length);
    server_data.sin_port = htons(server_port);
    memset(&(server_data.sin_zero), 0, 8);
    
    /* 7. Conecto el socket al servidor */
    status = connect(client_socket_fd, (struct sockaddr *) &server_data, sizeof(struct sockaddr));
    if (status == -1) {
        printf("Error en connect()\n");
        return -1;
    }

    /* 8. Cliente conectado al servidor */
    printf("Cliente conectado al servidor\n");
    clientOnline = 1;

    /* 9. Recibe mensaje de bienvenida y coloco el último caracter recibido como NULL, por si acaso */
    message_size = recv(client_socket_fd, buffer, BUFFER_MAX, 0);
    if (message_size == -1) {
        printf("Error en recv()\n");
        return -1; 
    }
    buffer[message_size] = '\0';

    /* 10. Muestro mensaje recibido del servidor */
    printf("Servidor: %s\n", buffer);

    while (clientOnline) {
        /* 11. Envia mensajes al servidor hasta recibir "exit" */
        printf("Escriba mensaje a enviar (o \"exit\" para salir): ");
        fgets(buffer, BUFFER_MAX, stdin);
        buffer[strlen(buffer) - 1] = '\0';

        if (!strcmp(buffer, "exit")) {
            clientOnline = 0;
        } else {
            sentBytes = send(client_socket_fd, buffer, strlen(buffer), 0);

            if (sentBytes <= 0) {
                printf("Error en send()");
                clientOnline = 0;
            }
        }
    }

    /* 12. Cierro conexión */
    close(client_socket_fd);
    printf("Conexion con servidor finalizada\n");

    return 0;
}
