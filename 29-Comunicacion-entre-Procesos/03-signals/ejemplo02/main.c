/*!
 * @file   main.c
 * @brief  29. Comunicacion entre Procesos - 03. Signals - 02. Cuenta la
 *   cantidad de SIGINT recibidas en 15 segundos
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Oct 28, 2018
 */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int sigint_counter = 0;
int loop_flag = 1;

void sigint_handler();
void sigalrm_handler();

int main(void)
{
    // Defino los handlers de las señales.
    signal(SIGINT, sigint_handler);
    signal(SIGALRM, sigalrm_handler);

    // Programo la alarma para que el SO me envíe SIGALRM a los 15 segundos.
    printf("Alarma seteada para sonar en 15 segundos!\n");
    alarm(15);

    // Trapeo la señal SIGINT (CTRL-C).
    printf("Pulsa varias veces CTRL-C!\n");
    while (loop_flag)
    {
    }

    printf("SIGINT recibida %d veces\n", sigint_counter);
    return 0;
}

void sigalrm_handler()
{
    // Ignoro si llega una nueva SIGALRM mientras estoy en el handler (también
    // la ignora el default).
    signal(SIGALRM, SIG_IGN);

    // Limpio el flag para romper la ejecución del bucle.
    loop_flag = 0;
    printf("Recibi SIGALRM. Riiiiiiiing! Alarma!\n");
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
