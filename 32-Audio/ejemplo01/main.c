/*!
 * @file   main.c
 * @brief  38. Audio - 01. Reproducción de un archivo wav
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Aug 23, 2019
 */
#include <fcntl.h>
#include <linux/soundcard.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <unistd.h>

// Tamaño de muestra. Típicamente 8 o 16 bits.
#define SAMPLE_BITS 16

// Cantidad de canales: mono(1) o stereo(2).
#define CHANNELS 2

// Sampling rate (velocidad de muestreo del audio).
#define RATE 48000

// Duración de la porción de audio a cargar en el buffer.
#define MSEG 10

#define BUFFER_SIZE SAMPLE_BITS* CHANNELS* RATE / 8 / 1000

void set_audio_params(int fd, int bits, int channels, int rate);

int main(void)
{
    // Declaro descriptores para los archivos/periféricos.
    // Descriptor de archivo de dispositivo de sonido (sound device file
    // descriptor).
    int dspfd;
    // Descriptor de archivo (file descriptor).
    int fd;
    int status;
    char* buf;

    // Solicito memoria para el buffer de audio.
    buf = malloc(BUFFER_SIZE);
    if (buf == NULL)
    {
        printf("Error allocando memoria.\n");
        return 1;
    }

    // Abrimos el archivo de audio en modo de sólo lectura.
    fd = open("Marooned.raw", O_RDONLY);
    if (fd < 0)
    {
        printf("Error abriendo el archivo de audio.\n");
        return 1;
    }

    // Abrimos el dispositivo de audio en modo lectura-escritura.
    dspfd = open("/dev/dsp", O_RDWR);
    if (dspfd < 0)
    {
        printf("Error abriendo el dispositivo de audio.\n");
        return 1;
    }

    // Seteamos los parámetros de audio.
    set_audio_params(dspfd, SAMPLE_BITS, CHANNELS, RATE);

    // Sacamos el contenido del archivo de audio por la salida de audio.
    printf("Reproduciendo archivo de audio...\n");
    while (1)
    {
        // Leo el archivo de audio.
        status = read(fd, buf, BUFFER_SIZE);
        if (status != BUFFER_SIZE)
        {
            printf("Error en función read.\n");
            return 1;
        }

        // Escribo en el dispositivo de audio.
        status = write(dspfd, buf, BUFFER_SIZE);
        if (status != BUFFER_SIZE)
        {
            printf("Error en función write.\n");
            return 1;
        }
    }

    // Cierro los archivos y libero la memoria solicitada.
    close(dspfd);
    close(fd);
    free(buf);
}

void set_audio_params(int fd, int bits, int channels, int rate)
{
    int status;

    // Seteo el tamaño de muestra en bits.
    status = ioctl(fd, SOUND_PCM_WRITE_BITS, &bits);
    if (status == -1)
    {
        printf("Error con comando SOUND_PCM_WRITE_BITS\n");
    }
    printf("Tamaño de muestras seteado: %d\n", bits);

    // Seteo el número de canales.
    status = ioctl(fd, SOUND_PCM_WRITE_CHANNELS, &channels);
    if (status == -1)
    {
        printf("Error en comando SOUND_PCM_WRITE_CHANNELS");
    }
    printf("Cantidad de canales seteado: %d\n", channels);

    // Seteo la velocidad de muestreo.
    status = ioctl(fd, SOUND_PCM_WRITE_RATE, &rate);
    if (status == -1)
    {
        printf("Error en comando SOUND_PCM_WRITE_RATE");
    }
    printf("Velocidad de muestreo seteada: %d\n", rate);
}
