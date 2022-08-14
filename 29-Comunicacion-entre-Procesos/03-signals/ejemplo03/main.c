/*!
 * @file   main.c
 * @brief  29. Comunicacion entre Procesos - 03. Signals - 03. Trapper genérico
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Oct 28, 2018
 */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void signals_handler(int signal_number);

int main(void)
{
    int i;

    // Asigno todas las señales al handler (menos SIGKILL y SIGSTOP que no
    // pueden ser trapeadas ni ignoradas).
    for (i = 1; i <= 64; i++)
    {
        signal(i, signals_handler);
    }

    // Informo el PID del proceso para poder enviarle señales con "kill -n PID".
    printf("PID del proceso: %d\n", getpid());

    // Espero hasta que llega una señal y salgo.
    printf("Esperando una señal...\n");
    pause();

    printf("Chau!\n");
    return 0;
}

void signals_handler(int signal_number)
{
    // Vuelvo a setear el handler para la señal recibida (sino se asigna
    // automáticamente al handler default).
    printf("Recibida la señal %d!\n", signal_number);
    signal(signal_number, signals_handler);
}
