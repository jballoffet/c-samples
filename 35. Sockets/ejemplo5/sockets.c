/*!
 * @file   sockets.c
 * @brief  Funciones utilitarias para el manejo de sockets UNIX.
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Nov 11, 2020
 */
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>
#include "sockets.h"

int abrir_socket_tcp_servidor(int server_port) {
    int listen_socket_fd, enable, status;
    struct sockaddr_in server_data;

    if (server_port == 0) {
        return INVALID_PORT;
    }

    // Creo el socket de escucha, con configuración para IPv4 y TCP.
    listen_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket_fd == -1) {
        return SOCKET_ERROR;
    }

    // Cargo la información del servidor.
    server_data.sin_family = AF_INET;
    server_data.sin_addr.s_addr = INADDR_ANY;
    server_data.sin_port = htons(server_port);
    memset(&(server_data.sin_zero), 0, 8);

    // Agrego una opción al socket para evitar que el puerto quede bloqueado al cerrar el servidor.
    enable = 1;
    setsockopt(listen_socket_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable));

    // Enlazo el socket a la configuracion deseada (IP:PORT).
    status = bind(listen_socket_fd, (struct sockaddr*) &server_data, sizeof(server_data));
    if (status == -1) {
        return BIND_ERROR;
    }

    // Configuro el socket de escucha para escuchar conexiones entrantes.
    status = listen(listen_socket_fd, CONNECTIONS_MAX);
    if (status == -1) {
        return LISTEN_ERROR;
    }

    return listen_socket_fd;
}

int aceptar_conexion_entrante(int socket_fd, char* client_ip) {
    int client_socket_fd, client_length;
    struct sockaddr_in client_data;

    // Acepto la conexión entrante.
    client_length = sizeof(struct sockaddr_in);
    client_socket_fd = accept(socket_fd, (struct sockaddr*) &client_data, (socklen_t*) &client_length);
    if (client_socket_fd == -1) {
        return ACCEPT_ERROR;
    }

    // Copio la dirección IP del cliente.
    strcpy(client_ip, inet_ntoa((struct in_addr) client_data.sin_addr));

    return client_socket_fd;
}

int abrir_socket_tcp_cliente(const char* server_ip, int server_port) {
    int client_socket_fd, status;
    struct sockaddr_in server_data;
    struct hostent* host_data;

    host_data = gethostbyname(server_ip);
    if (host_data == NULL) {
        return INVALID_IP;
    }

    if (server_port == 0) {
        return INVALID_PORT;
    }

    // Creo el socket, con configuración para IPv4 y TCP.
    client_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket_fd == -1) {
        return SOCKET_ERROR;
    }

    // Cargo la información del servidor.
    server_data.sin_family = AF_INET;
    memcpy(&(server_data.sin_addr), host_data->h_addr_list[0], host_data->h_length);
    server_data.sin_port = htons(server_port);
    memset(&(server_data.sin_zero), 0, 8);

    // Conecto el socket al servidor.
    status = connect(client_socket_fd, (struct sockaddr *) &server_data, sizeof(server_data));
    if (status == -1) {
        return CONNECT_ERROR;
    }

    return client_socket_fd;
}

int enviar_datos_tcp(int socket_fd, char* buffer, int size) {
    int bytes_sent;

    bytes_sent = send(socket_fd, buffer, size, 0);
    if (bytes_sent == -1) {
        return SEND_ERROR;
    }

    return bytes_sent;
}

int recibir_datos_tcp(int socket_fd, char* buffer, int size) {
    int bytes_received;
    
    bytes_received = recv(socket_fd, buffer, size, 0);
    if (bytes_received == -1) {
        return RECEIVE_ERROR;
    }

    return bytes_received;
}

void cerrar_socket_tcp(int socket_fd) {
    close(socket_fd);
}
