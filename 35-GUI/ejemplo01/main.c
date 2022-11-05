/*!
 * @file   main.c
 * @brief  35. GUI - 01. GTK - Crear ventana
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 1, 2019
 */
#include <gtk/gtk.h>

int main(int argc, char* argv[])
{
    // Declaro un puntero para la ventana. Todos los widgets son accedidos vía
    // punteros.
    GtkWidget* window;

    // Inicializo GTK.
    gtk_init(&argc, &argv);

    // Creo la ventana principal (main top level window).
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    // Coloco el titulo "Hola Mundo!".
    gtk_window_set_title(GTK_WINDOW(window), "Hola Mundo!");

    // Centro la ventana.
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    // Seteo el tamaño default de la ventana.
    gtk_window_set_default_size(GTK_WINDOW(window), 250, 200);

    // Mapeo la señal "destroy" de la ventana a gtk_main_quit. Cuando la señal
    // se destruye, recibimos una notificación y se para el loop principal de
    // GTK, retornando 0.
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Seteo la ventana como visible.
    gtk_widget_show_all(window);

    // Inicio el loop principal, y hago nada (bloqueante) hasta que la
    // aplicación se cierra.
    gtk_main();

    return 0;
}
