/**
 * \file            main.c
 * \brief           41. GUI - Ejemplo 4 - GTK - Crear container (box)
 * \author          Javier Balloffet
 * \date            Sep 1, 2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <gtk/gtk.h>

/* 1. Creo un label con el texto "Hola Mundo!" */
GtkWidget* label_count;

void on_button_clicked();

int main(int argc, char* argv[]) {
    GtkWidget* window;
    GtkWidget* box;

    GtkWidget* label_title;
    GtkWidget* button;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
    gtk_window_set_title(GTK_WINDOW(window), "Ejemplo");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 250, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    box = gtk_button_box_new(GTK_ORIENTATION_VERTICAL);
    gtk_container_add(GTK_CONTAINER(window), box);

    label_title = gtk_label_new("Presione el botón para sumar uno");
    gtk_container_add(GTK_CONTAINER(box), label_title);

    label_count = gtk_label_new("0");
    gtk_container_add(GTK_CONTAINER(box), label_count);

    button = gtk_button_new_with_label("QUIT");
    gtk_container_add(GTK_CONTAINER(box), button);  
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

/* 1. Función llamada cuando el botón es presionado (callback) */
void on_button_clicked() {
    static unsigned int count = 0;
    char count_string[30] = {0};
    count++;
    sprintf(count_string, "%d", count);
    gtk_label_set_text(GTK_LABEL(label_count), count_string);
}
