/**
 * \file            main.c
 * \brief           41. GUI - Ejemplo 1 - GTK - Crear ventana
 * \author          Javier Balloffet
 * \date            Sep 1, 2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <gtk/gtk.h>

int main(int argc, char* argv[]) {
    /* 1. Declaro un puntero para la ventana. Todos los widgets son accedidos vía punteros */
    GtkWidget* window;

    /* 2. Inicializo GTK */
    gtk_init(&argc, &argv);

    /* 3. Creo la ventana principal (main top level window) */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    /* 4. Coloco el titulo "Hola Mundo!" */
    gtk_window_set_title(GTK_WINDOW(window), "Hola Mundo!");

    /* 5. Centro la ventana */
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    /* 6. Seteo el tamaño default de la ventana */
    gtk_window_set_default_size(GTK_WINDOW(window), 250, 200);

    /* 7. Mapeo la señal "destroy" de la ventana a gtk_main_quit.
     * Cuando la señal se destruye, recibimos una notificación y se para 
     * el loop principal de GTK, retornando 0 */
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* 8. Seteo la ventana como visible */
    gtk_widget_show_all(window);

    /* 9. Inicio el loop principal, y hago nada (bloqueante) hasta que la aplicación se cierra */
    gtk_main();

    return 0;
}
