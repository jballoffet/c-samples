/*!
 * @file   main.c
 * @brief  35. Sockets - 01. Cliente-Servidor TCP
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Nov 11, 2020
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

#define BUFFER_MAX 100  // Tamaño del buffer de datos en bytes.

int main(int argc, char* argv[]) {
    int server_port, status, message_size;
    char buffer[BUFFER_MAX];
    // Declaro el file descriptor para el socket de la conexión.
    int client_socket_fd;
    // Declaro una estructura para la información de dirección del servidor.
    struct sockaddr_in server_data;
    // Declaro un puntero a una estructura donde gethostbyname() me retornará la IP.
    struct hostent* host_data;

    // Obtengo el número de IP y de puerto pasados como argumentos del main.
    if (argc < 3) {
        printf("Debe ingresar la IP y el puerto como parametros.\n");
        printf("Uso: %s <IP> <PUERTO>\n", argv[0]);
        return -1;
    } 

    host_data = gethostbyname(argv[1]);
    if (host_data == NULL) {
        printf("IP invalida.\n");
        return -1;
    }

    server_port = atoi(argv[2]);
    if (server_port == 0) {
        printf("Puerto invalido.\n");
        return -1;
    }

    // Creo el socket, con configuración para IPv4 y TCP.
    client_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket_fd == -1) {
        printf("Error en socket().\n");
        return -1;
    }

    // Cargo la información del servidor.
    server_data.sin_family = AF_INET;
    memcpy(&(server_data.sin_addr), host_data->h_addr_list[0], host_data->h_length);
    server_data.sin_port = htons(server_port);
    memset(&(server_data.sin_zero), 0, 8);

    // Conecto el socket al servidor.
    status = connect(client_socket_fd, (struct sockaddr *) &server_data, sizeof(server_data));
    if (status == -1) {
        printf("Error en connect().\n");
        return -1;
    }

    // Cliente conectado al servidor.
    printf("Cliente conectado al servidor.\n");

    // Recibo el mensaje de bienvenida y coloco el último caracter recibido como NULL, por si acaso.
    message_size = recv(client_socket_fd, buffer, BUFFER_MAX, 0);
    if (message_size == -1) {
        printf("Error en recv().\n");
        return -1; 
    }
    buffer[message_size] = '\0';

    // Muestro el mensaje recibido del servidor.
    printf("Servidor: %s\n", buffer);

    // Cierro conexión.
    close(client_socket_fd);
    printf("Conexion con servidor finalizada.\n");

    return 0;
}
