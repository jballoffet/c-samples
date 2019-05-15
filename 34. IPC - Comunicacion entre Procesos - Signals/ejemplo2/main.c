/**
 * \file            main.c
 * \brief           34. IPC - Comunicacion entre Procesos - Signals - Ejemplo 2 - Cuenta el numero de SIGINT recibidas en 15 segundos
 * \author          Javier Balloffet
 * \date            Oct 28, 2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int sigintCounter = 0;
int loopFlag = 1;

void sigint_handler();
void sigalrm_handler();

int main() {
    /* 1. Defino los handlers de las señales */
    signal(SIGINT, sigint_handler);
    signal(SIGALRM, sigalrm_handler);

    /* 2. Programo la alarma para que el SO me envíe SIGALRM a los 15 segundos! */
    printf("Alarma seteada para sonar en 15 segundos!\n");
    alarm(15);

    /* 3. Trapeo la señal SIGINT (CTRL-C) */
    printf("Pulsa varias veces CTRL-C!\n");
    while (loopFlag);

    printf("SIGINT recibida %d veces\n", sigintCounter);
    return 0;
}

void sigalrm_handler() {
    /* 4. Ignoro si llega una nueva SIGALRM mientras estoy en el handler (tambien la ignora el default) */
    signal(SIGALRM, SIG_IGN);

    /* 5. Limpio el flag para romper la ejecucion del bucle */
    loopFlag = 0;
    printf("Recibi SIGALRM. Riiiiiiiing! Alarma!\n");
}

void sigint_handler() {
    /* 6. Ignoro si llega una nueva SIGINT mientras estoy en el handler (tambien la ignora el default) */
    signal(SIGINT, SIG_IGN);

    /* 7. Incremento contador */
    printf("Recibi SIGINT. Presionaste CTRL-C!\n");
    sigintCounter++;

    /* 8. Vuelvo a setear el handler para SIGINT (sino se asigna automaticamente al handler default) */
    signal(SIGINT, sigint_handler);
}
