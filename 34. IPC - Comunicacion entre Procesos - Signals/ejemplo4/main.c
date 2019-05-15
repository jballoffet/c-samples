/**
 * \file            main.c
 * \brief           34. IPC - Comunicacion entre Procesos - Signals - Ejemplo 4 - Señales entre padre e hijo
 * \author          Javier Balloffet
 * \date            Oct 28, 2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

int loopFlag = 1;

void signals_handler(int signalNumber);

int main() {
    /* 1. Declaro un entero para almacenar el PID (Process ID) */
    int pid, status;

    /* 2. Genero un nuevo proceso utilizando la función "fork" */
    pid = fork();

    /* 3. Separo la ejecución del padre y del hijo */
    if (pid < 0) {
        perror("Error al generar el proceso hijo\n");
        exit(1);        

    } else if (pid == 0) {
        /* 4. Proceso hijo */
        printf("Hijo: Hola! Mi PID es: %d\n", getpid());

        /* 5. Define el handler para SIGUSR1 y se queda esperando una señal del padre (SIGUSR1) */
        signal(SIGUSR1, signals_handler);
        printf("Hijo: Estoy esperando una señal de mi padre...\n");
        while (loopFlag);

        /* 6. Llegó la señal! El hijo ahora envía una señal al padre (SIGUSR2) */
        kill(getppid(), SIGUSR2);
        printf("Hijo: Señal enviada a mi padre!\n");
        printf("Hijo: Chau!\n");

    } else if (pid > 0) {
        /* 7. Proceso padre */
        printf("Padre: Hola! Mi PID es: %d\n", getpid());

        /* 8. Define el handler para SIGUSR2 */
        signal(SIGUSR2, signals_handler);

        /* 9. Espera 3 segundos */
        printf("Padre: Esperando 3 segundos...\n");
        sleep(3);

        /* 10. Envía señal al hijo (SIGUSR1) */
        kill(pid, SIGUSR1);
        printf("Padre: Señal enviada a mi hijo!\n");

        /* 11. Hago que el padre espere a que su hijo muera antes de morir él */
        printf("Padre: Esperando a que mi hijo muera...\n");
        wait(&status);
        printf("Padre: Mi hijo termino con status: %d\n", status);
        printf("Padre: Chau!\n");
    }

    return 0; 
}

void signals_handler(int signalNumber) {
    /* 12. Separo según señal recibida */
    if (signalNumber == SIGUSR1) {
        printf("Hijo: Recibi esta señal de mi padre: %d\n", signalNumber);
    } else if (signalNumber == SIGUSR2) {
        printf("Padre: Recibi esta señal de mi hijo: %d\n", signalNumber);
    }

    /* 13. Limpio flag para cortar ejecución del bucle */
    loopFlag = 0;

    /* 14. Vuelvo a setear el handler para la señal recibida (sino se asigna automáticamente al handler default) */
    signal(signalNumber, signals_handler);
}
