/**
 * \file            main.c
 * \brief           38. Audio - Ejemplo 1 - Reproducción de un archivo wav
 * \author          Javier Balloffet
 * \date            Aug 23, 2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <linux/soundcard.h>

#define SAMPLE_BITS     16          /* Tamaño de muestra. Típicamente 8 o 16 bits */
#define CHANNELS        2           /* Cantidad de canales. mono(1) o stereo(2) */
#define RATE            48000       /* Sampling rate = Velocidad de muestreo del audio */
#define MSEG            10          /* Duración de la porción de audio a cargar en el buffer */
#define BUFFER_SIZE     SAMPLE_BITS*CHANNELS*RATE/8/1000

void set_audio_params(int fd, int bits, int channels, int rate);

int main() {
	/* 1. Declaro descriptores para los archivos/periféricos */
    int dspfd;	        /* Descriptor de archivo de dispositivo de sonido (Sound device file descriptor) */
	int fd;             /* Descriptor de archivo (File descriptor) */
	int status;
    char* buf;

    /* 2. Solicito memoria para el buffer de audio */
    buf = malloc(BUFFER_SIZE);
    if (buf == NULL) {
        printf("Error allocando memoria.\n");
        return 1;
    } 

	/* 3. Abrimos el archivo de audio en modo de sólo lectura */
    fd = open("Marooned.raw", O_RDONLY);
	if (fd < 0)	{
	  	printf("Error abriendo el archivo de audio.\n"); 
		return 1;
	}

	/* 4. Abrimos el dispositivo de audio en modo lectura-escritura */
    dspfd = open("/dev/dsp", O_RDWR);
	if (dspfd < 0) { 
		printf("Error abriendo el dispositivo de audio.\n"); 
		return 1;
	}

	/* 5. Seteamos los parámetros de audio */
	set_audio_params(dspfd, SAMPLE_BITS, CHANNELS, RATE);

    /* 6. Sacamos el contenido del archivo de audio por la salida de audio */
    printf("Reproduciendo archivo de audio...\n");
	while (1) { 
        /* 7. Leo el archivo de audio */
	    status = read(fd, buf, BUFFER_SIZE);
		if (status != BUFFER_SIZE) {
			printf("Error en función read.\n");
			return 1;
		}

        /* 8. Escribo en el dispositivo de audio */
		status = write(dspfd, buf, BUFFER_SIZE); 
		if (status != BUFFER_SIZE) {
			printf("Error en función write.\n"); 
            return 1;
		}
    }

    /* 9. Cierro los archivos y libero memoria solicitada */
    close(dspfd);
    close(fd);
	free(buf);
}

void set_audio_params(int fd, int bits, int channels, int rate) {
	int status;

    /* 1. Seteo el tamaño de muestra en bits */
    status = ioctl(fd, SOUND_PCM_WRITE_BITS, &bits); 
    if (status == -1)  {
        printf("Error con comando SOUND_PCM_WRITE_BITS\n");
    }
    printf("Tamaño de muestras seteado: %d\n", bits);
	
    /* 2. Seteo el número de canales */
	status = ioctl(fd, SOUND_PCM_WRITE_CHANNELS, &channels);
	if (status == -1) {
		printf("Error en comando SOUND_PCM_WRITE_CHANNELS");
    }
	printf("Cantidad de canales seteado: %d\n", channels);

    /* 3. Seteo la velocidad de muestreo */
	status = ioctl(fd, SOUND_PCM_WRITE_RATE, &rate);
	if (status == -1) {
		printf("Error en comando SOUND_PCM_WRITE_RATE");
    }
	printf("Velocidad de muestreo seteada: %d\n", rate);
}
