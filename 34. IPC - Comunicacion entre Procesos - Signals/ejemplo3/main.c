/**
 * \file            main.c
 * \brief           34. IPC - Comunicacion entre Procesos - Signals - Ejemplo 3 - Trapper genérico
 * \author          Javier Balloffet
 * \date            28-OCT-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void signals_handler(int signalNumber);

int main() {
    int i;

    // 1. Asigno todas las señales al handler (menos SIGKILL y SIGSTOP que no pueden ser trapeadas ni ignoradas)
    for (i = 1; i <= 64; i++) {
        signal(i, signals_handler);
    }

    // 2. Informo el PID del proceso para poder enviarle señales con "kill -n PID"
    printf("PID del proceso: %d\n", getpid());

    // 3. Espero hasta que llega una señal y salgo
    printf("Esperando una señal...\n");
    pause();

    printf("Chau!\n");
    return 0;
}

void signals_handler(int signalNumber) {
    // 4. Vuelvo a setear el handler para la señal recibida (sino se asigna automaticamente al handler default)
    printf("Recibida la señal %d!\n", signalNumber);
    signal(signalNumber, signals_handler);
}
