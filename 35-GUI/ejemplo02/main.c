/*!
 * @file   main.c
 * @brief  35. GUI - 02. GTK - Crear label
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 1, 2019
 */
#include <gtk/gtk.h>

int main(int argc, char* argv[])
{
    // Declaro punteros para los widgets.
    GtkWidget* window;
    GtkWidget* label;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Ejemplo");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 250, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Creo un label con el texto "Hola Mundo!".
    label = gtk_label_new("Hola Mundo!");

    // Imprimo la label en la ventana principal.
    gtk_container_add(GTK_CONTAINER(window), label);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
