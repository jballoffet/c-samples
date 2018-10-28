/**
 * \file            main.c
 * \brief           34. IPC - Comunicacion entre Procesos - Signals - Ejemplo 1 - Trapea la señal SIGINT (CTRL-C)
 * \author          Javier Balloffet
 * \date            28-OCT-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int sigintCounter = 0;

void sigint_handler();

int main() {
    // 1. Defino los handlers de las señales
    signal(SIGINT, sigint_handler);

    // 2. Trapeo la señal SIGINT (CTRL-C) hasta 5 veces
    printf("Pulsa varias veces CTRL-C!\n");
    while (sigintCounter < 5);

    printf("SIGINT recibida %d veces\n", sigintCounter);
    return 0;
}

void sigint_handler() {
    // 3. Ignoro si llega una nueva SIGINT mientras estoy en el handler (tambien la ignora el default)
    signal(SIGINT, SIG_IGN);

    // 4. Incremento contador
    printf("Recibi SIGINT. Presionaste CTRL-C!\n");
    sigintCounter++;

    // 5. Vuelvo a setear el handler para SIGINT (sino se asigna automaticamente al handler default)
    signal(SIGINT, sigint_handler);
}
