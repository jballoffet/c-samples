/*!
 * @file   main.c
 * @brief  29. Comunicacion entre Procesos - 03. Signals - 01. Trapea la señal
 *   SIGINT (CTRL-C) hijo
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Oct 28, 2018
 */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int sigint_counter = 0;

void sigint_handler();

int main(void)
{
    // Defino los handlers de las señales.
    signal(SIGINT, sigint_handler);

    // Trapeo la señal SIGINT (CTRL-C) hasta 5 veces.
    printf("Pulsa varias veces CTRL-C!\n");
    while (sigint_counter < 5)
    {
    }

    printf("SIGINT recibida %d veces\n", sigint_counter);
    return 0;
}

void sigint_handler()
{
    // Ignoro si llega una nueva SIGINT mientras estoy en el handler (también la
    // ignora el default).
    signal(SIGINT, SIG_IGN);

    // Incremento contador.
    printf("Recibi SIGINT. Presionaste CTRL-C!\n");
    sigint_counter++;

    // Vuelvo a setear el handler para SIGINT (sino se asigna automáticamente al
    // handler default).
    signal(SIGINT, sigint_handler);
}
