/*!
 * @file   main.c
 * @brief  38. Audio - 02. libVLC - Reproducción de un archivo mp3
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 1, 2019
 */
#include <stdio.h>
#include <unistd.h>
#include <vlc/vlc.h>

int main(void)
{
    libvlc_instance_t* motor = NULL;
    libvlc_media_t* audio = NULL;
    libvlc_media_player_t* reproductor = NULL;

    // Cargo el motor de libVLC.
    motor = libvlc_new(0, NULL);
    if (motor == NULL)
    {
        printf("Error al cargar el motor de libVLC\n");
        return 1;
    }

    // Cargo el archivo de audio.
    audio = libvlc_media_new_path(motor, "sample.mp3");
    if (audio == NULL)
    {
        printf("Error al cargar el archivo de audio\n");
        return 1;
    }

    // Creo un reproductor de media para el archivo de audio.
    reproductor = libvlc_media_player_new_from_media(audio);
    if (reproductor == NULL)
    {
        printf("Error al crear el reproductor de media\n");
        return 1;
    }

    // Libero el archivo de audio (ya no es necesario).
    libvlc_media_release(audio);

    // Reproduzco el reproductor de media.
    libvlc_media_player_play(reproductor);

    // Espero hasta que el archivo de audio termine de reproducirse.
    do
    {
        sleep(1);
    } while (libvlc_media_player_is_playing(reproductor));

    // Detengo el reproductor de media.
    libvlc_media_player_stop(reproductor);

    // Libero el reproductor de media.
    libvlc_media_player_release(reproductor);

    // Libero los recursos.
    libvlc_release(motor);

    return 0;
}
