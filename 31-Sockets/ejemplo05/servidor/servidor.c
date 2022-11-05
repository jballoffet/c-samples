/*!
 * @file   main.c
 * @brief  31. Sockets - 05. Cliente-Servidor TCP
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Nov 11, 2020
 */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "sockets.h"

// Tamaño del buffer de datos en bytes.
#define BUFFER_MAX 100

// Cantidad de caracteres máxima de una dirección IPv4.
#define IP_LENGTH 16

typedef enum ClientStatus
{
    CONNECTED = 0,
    DISCONNECTED
} ClientStatus;

// Variable global para llevar la cuenta de los clientes conectados.
static int clients_count = 0;

void sigchld_handler();
void parent_process();
void child_process(int client_socket_fd, const char* client_ip);

int main(int argc, char* argv[])
{
    int listen_socket_fd, client_socket_fd, pid;
    char client_ip[IP_LENGTH];

    // Capturo la señal SIGCHLD, enviada cuando muere un proceso hijo.
    signal(SIGCHLD, sigchld_handler);

    // Obtengo el número de puerto pasado como argumento del main.
    if (argc < 2)
    {
        printf("Debe ingresar el puerto como parametro.\n");
        printf("Uso: %s <PUERTO>\n", argv[0]);
        return -1;
    }

    // Creo el socket de escucha, con configuración para IPv4 y TCP.
    listen_socket_fd = abrir_socket_tcp_servidor(atoi(argv[1]));
    if (listen_socket_fd < 0)
    {
        printf("Error abriendo el socket: %d.\n", listen_socket_fd);
        return -1;
    }

    // Servidor corriendo esperando conexiones entrantes.
    printf("Servidor corriendo en el puerto: %d.\n", atoi(argv[1]));
    while (1)
    {
        // Acepto la conexión entrante.
        client_socket_fd =
            aceptar_conexion_entrante(listen_socket_fd, client_ip);
        if (client_socket_fd < 0)
        {
            printf("Error aceptando conexión entrante: %d.\n",
                   client_socket_fd);
            continue;
        }

        // Genero un proceso hijo para atender al cliente, el padre se queda
        // atendiendo llamadas.
        pid = fork();
        if (pid < 0)
        {
            // Error! No se pudo generar el proceso hijo.
            printf("Error en fork().\n");
            return -1;
        }
        else if (pid == 0)
        {
            // Proceso hijo.
            cerrar_socket_tcp(listen_socket_fd);
            child_process(client_socket_fd, client_ip);
            return 0;
        }
        else
        {
            // Proceso padre.
            cerrar_socket_tcp(client_socket_fd);
            parent_process();
        }
    }

    // Cierro el socket de escucha.
    cerrar_socket_tcp(listen_socket_fd);
    printf("Servidor finalizado.\n");

    return 0;
}

void parent_process()
{
    clients_count++;
    printf("Nuevo cliente! Total de clientes conectados: %d\n", clients_count);
}

void child_process(int client_socket_fd, const char* client_ip)
{
    int message_size, client_status;
    char buffer[BUFFER_MAX];

    // Muestro la IP del cliente.
    client_status = CONNECTED;
    printf("Se obtuvo una conexion desde la IP: %s.\n", client_ip);

    // Envío mensaje de bienvenida al cliente.
    message_size = enviar_datos_tcp(client_socket_fd,
                                    "Bienvenido! Conectado al servidor!", 34);
    if (message_size < 0)
    {
        printf("Error enviando datos al cliente.\n");
        return;
    }

    while (client_status == CONNECTED)
    {
        // Recibo mensaje del cliente a imprimir en pantalla.
        printf("Esperando mensaje...\n");
        message_size = recibir_datos_tcp(client_socket_fd, buffer, BUFFER_MAX);

        if (message_size > 0)
        {
            // Muestro mensaje recibido.
            buffer[message_size] = '\0';
            printf("Cliente [%s]: %s\n", client_ip, buffer);
        }
        else
        {
            client_status = DISCONNECTED;
        }
    }

    // Cierro el socket del cliente.
    cerrar_socket_tcp(client_socket_fd);
    printf("Conexion con cliente [%s] finalizada.\n", client_ip);
}

void sigchld_handler()
{
    // "Sepulto" al hijo difunto.
    while (waitpid((pid_t)(-1), 0, WNOHANG) > 0)
    {
        clients_count--;
    }
    printf("Cliente desconectado! Total de clientes conectados: %d\n",
           clients_count);
}
