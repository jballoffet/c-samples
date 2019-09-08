/**
 * \file            main.c
 * \brief           41. GUI - Ejemplo 2 - GTK - Crear label
 * \author          Javier Balloffet
 * \date            Sep 1, 2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <gtk/gtk.h>

int main(int argc, char* argv[]) {
    /* 1. Declaro punteros para los widgets */
    GtkWidget* window;
    GtkWidget* label;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Ejemplo");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 250, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* 2. Creo un label con el texto "Hola Mundo!" */
    label = gtk_label_new("Hola Mundo!");

    /* 3. Imprimo la label en la ventana principal */
    gtk_container_add(GTK_CONTAINER(window), label);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
