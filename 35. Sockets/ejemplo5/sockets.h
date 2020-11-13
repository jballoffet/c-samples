/*!
 * @file   sockets.h
 * @brief  Funciones utilitarias para el manejo de sockets UNIX.
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Nov 11, 2020
 */
#ifndef SOCKETS_H_
#define SOCKETS_H_

// TCP - Protocolo de control de transmisión.

typedef enum TcpErrors {
    INVALID_IP = -1,
    INVALID_PORT = -2,
    SOCKET_ERROR = -3,
    BIND_ERROR = -4,
    LISTEN_ERROR = -5,
    ACCEPT_ERROR = -6,
    CONNECT_ERROR = -7,
    SEND_ERROR = -8,
    RECEIVE_ERROR = -9
} TcpErrors;

// Lado servidor.

#define CONNECTIONS_MAX 5  // Número máximo de conexiones en cola de espera permitidas.

/*!
 * @brief Abre un socket INET TCP como servidor.
 *
 * @param[in] server_port Puerto donde se desea abrir el socket.
 * @return    Descriptor del socket servidor en caso de éxito, o código de error en caso contrario.
 */
int abrir_socket_tcp_servidor(int server_port);

/*!
 * @brief Acepta una conexión INET TCP entrante desde un cliente.
 *
 * @param[in]  socket_fd Descriptor del socket servidor.
 * @param[out] client_ip Dirección IP del cliente.
 * @return     Descriptor del socket cliente en caso de éxito, o código de error en caso contrario.
 */
int aceptar_conexion_entrante(int socket_fd, char* client_ip);

// Lado cliente.

/*!
 * @brief Abre un socket INET TCP como cliente.
 *
 * @param[in] server_ip   Direccion IP del servidor.
 * @param[in] server_port Puerto al que se quiere conectar.
 * @return    Descriptor del socket en caso de éxito, o código de error en caso contrario.
 */
int abrir_socket_tcp_cliente(const char* server_ip, int server_port);

// Ambos lados.

/*!
 * @brief Envía datos por un socket INET TCP.
 *
 * @param[in] socket_fd Descriptor del socket.
 * @param[in] buffer Buffer donde están almacenados los datos a enviar.
 * @param[in] size Cantidad de bytes a enviar.
 * @return    Cantidad de bytes enviados, o código de error en caso contrario.
 */
int enviar_datos_tcp(int socket_fd, char* buffer, int size);

/*!
 * @brief Recibe datos desde un socket INET TCP.
 *
 * @param[in]  socket_fd Descriptor del socket.
 * @param[out] buffer Buffer donde almacenar los datos recibidos.
 * @param[in]  size Tamaño del buffer en bytes.
 * @return     Cantidad de bytes recibidos, o código de error en caso contrario.
 */
int recibir_datos_tcp(int socket_fd, char* buffer, int size);

/*!
 * @brief Cierra un socket INET TCP.
 *
 * @param[in] socket_fd Descriptor del socket.
 */
void cerrar_socket_tcp(int socket_fd);

#endif // SOCKETS_H_
