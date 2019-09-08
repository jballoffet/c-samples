/**
 * \file            main.c
 * \brief           38. Audio - Ejemplo 2 - VLC - Reproducción de un archivo mp3
 * \author          Javier Balloffet
 * \date            Sep 1, 2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <vlc/vlc.h>

int main(int argc, char* argv[]) {
    libvlc_instance_t* instance;
    libvlc_media_player_t* media_player;
    libvlc_media_t* media;

    /* 1. Cargo el engine de VLC */
    instance = libvlc_new(0, NULL);

    /* 2. Creo un nuevo item */
    media = libvlc_media_new_path(instance, "sample.mp3");

    /* 3. Creo un entorno de reproducción de media play */
    media_player = libvlc_media_player_new_from_media(media);

    // no need to keep the media now
    libvlc_media_release(media);

    // play the media_player
    libvlc_media_player_play(media_player);

    sleep(10);

    // stop playing
    libvlc_media_player_stop(media_player);

    // free the media_player
    libvlc_media_player_release(media_player);

    libvlc_release(instance);

    return 0;
}
