/*!
 * @file   main.c
 * @brief  29. Comunicacion entre Procesos - 03. Signals - 04. Señales entre
 *   padre e hijo
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Oct 28, 2018
 */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int loop_flag = 1;

void signals_handler(int signal_number);

int main(void)
{
    // Declaro un entero para almacenar el PID (Process ID).
    int pid, status;

    // Genero un nuevo proceso utilizando la función "fork".
    pid = fork();

    // Separo la ejecución del padre y del hijo.
    if (pid < 0)
    {
        perror("Error al generar el proceso hijo\n");
        exit(1);
    }
    else if (pid == 0)
    {
        // Proceso hijo.
        printf("Hijo: Hola! Mi PID es: %d\n", getpid());

        // Define el handler para SIGUSR1 y se queda esperando una señal del
        // padre (SIGUSR1).
        signal(SIGUSR1, signals_handler);
        printf("Hijo: Estoy esperando una señal de mi padre...\n");
        while (loop_flag)
        {
        }

        // Llegó la señal! El hijo ahora envía una señal al padre (SIGUSR2).
        kill(getppid(), SIGUSR2);
        printf("Hijo: Señal enviada a mi padre!\n");
        printf("Hijo: Chau!\n");
    }
    else if (pid > 0)
    {
        // Proceso padre.
        printf("Padre: Hola! Mi PID es: %d\n", getpid());

        // Define el handler para SIGUSR2.
        signal(SIGUSR2, signals_handler);

        // Espera 3 segundos.
        printf("Padre: Esperando 3 segundos...\n");
        sleep(3);

        // Envía señal al hijo (SIGUSR1).
        kill(pid, SIGUSR1);
        printf("Padre: Señal enviada a mi hijo!\n");

        // Hago que el padre espere a que su hijo muera antes de morir él.
        printf("Padre: Esperando a que mi hijo muera...\n");
        wait(&status);
        printf("Padre: Mi hijo termino con status: %d\n", status);
        printf("Padre: Chau!\n");
    }

    return 0;
}

void signals_handler(int signal_number)
{
    // Separo según señal recibida.
    if (signal_number == SIGUSR1)
    {
        printf("Hijo: Recibi esta señal de mi padre: %d\n", signal_number);
    }
    else if (signal_number == SIGUSR2)
    {
        printf("Padre: Recibi esta señal de mi hijo: %d\n", signal_number);
    }

    // Limpio flag para cortar ejecución del bucle.
    loop_flag = 0;

    // Vuelvo a setear el handler para la señal recibida (sino se asigna
    // automáticamente al handler default).
    signal(signal_number, signals_handler);
}
