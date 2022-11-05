/*!
 * @file   main.c
 * @brief  31. Sockets - 04. Cliente-Servidor TCP
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Nov 11, 2020
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
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

int main(int argc, char* argv[])
{
    int listen_socket_fd, client_socket_fd, message_size, client_status, pid;
    char buffer[BUFFER_MAX];
    char client_ip[IP_LENGTH];

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
            // Cierro socket de escucha.
            cerrar_socket_tcp(listen_socket_fd);

            // Muestro la IP del cliente.
            client_status = CONNECTED;
            printf("Se obtuvo una conexion desde la IP: %s.\n", client_ip);

            // Envío mensaje de bienvenida al cliente.
            message_size = enviar_datos_tcp(
                client_socket_fd, "Bienvenido! Conectado al servidor!", 34);
            if (message_size < 0)
            {
                printf("Error enviando datos al cliente.\n");
                return -1;
            }

            while (client_status == CONNECTED)
            {
                // Recibo mensaje del cliente a imprimir en pantalla.
                printf("Esperando mensaje...\n");
                message_size =
                    recibir_datos_tcp(client_socket_fd, buffer, BUFFER_MAX);

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

            return 0;
        }
        else
        {
            // Proceso padre.
            // Cierro socket de cliente.
            cerrar_socket_tcp(client_socket_fd);
        }
    }

    // Cierro el socket de escucha.
    cerrar_socket_tcp(listen_socket_fd);
    printf("Servidor finalizado.\n");

    return 0;
}
