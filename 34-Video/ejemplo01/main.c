/*!
 * @file   main.c
 * @brief  34. Video - 01. VLC y GTK - Reproductor de video
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Aug 24, 2019
 */
#include <gdk/gdkx.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <vlc/vlc.h>

#define BORDER_WIDTH 6

// Callbacks.
void on_player_window_realize(GtkWidget* widget);
gboolean on_player_window_draw(GtkWidget* widget, cairo_t* cr);
void on_menu_file_open_click(GtkWidget* widget, gpointer data);
void on_menu_file_exit_click(GtkWidget* widget);
void on_menu_help_about_click(GtkWidget* widget, gpointer data);
void on_playpause_click(GtkWidget* widget);
void on_stop_click(GtkWidget* widget);
void on_destroy(GtkWidget* widget);

void media_open(const char* uri);
void media_play(void);
void media_pause(void);

libvlc_instance_t* vlc_instance;
libvlc_media_player_t* media_player;
GtkWidget* playpause_button;

int main(int argc, char* argv[])
{
    GtkWidget* window;
    GtkWidget* box;
    GtkWidget* menu_bar;
    GtkWidget* file_menu;
    GtkWidget* help_menu;
    GtkWidget* menu_item;
    GtkWidget* player_window;
    GtkWidget* button_box;
    GtkWidget* stop_button;

    char const* vlc_argv[] = {//"--no-audio",
                              "--no-xlib", "-q",
                              //"-vvv",
                              "--no-video-title-show", "--quiet",
                              "--ignore-config", "--vout", "vmem", "-I",
                              "dumy"};
    int vlc_argc = sizeof(vlc_argv) / sizeof(*vlc_argv);

    gtk_init(&argc, &argv);

    // Creo ventana.
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Ejemplo GTK y libVLC");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 640, 360);
    gtk_container_set_border_width(GTK_CONTAINER(window), 0);
    g_signal_connect(window, "destroy", G_CALLBACK(on_destroy), NULL);

    // Creo container.
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), box);

    // Creo menú principal.
    // Creo barra de menú.
    menu_bar = gtk_menu_bar_new();

    // Creo menúes.
    file_menu = gtk_menu_new();
    help_menu = gtk_menu_new();

    // Creo items.
    menu_item = gtk_menu_item_new_with_label("File");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), file_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item);

    menu_item = gtk_menu_item_new_with_label("Help");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), help_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item);

    // Creo subitems y seteo sus callbacks.
    menu_item = gtk_menu_item_new_with_label("Open");
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), menu_item);
    g_signal_connect(menu_item, "activate", G_CALLBACK(on_menu_file_open_click),
                     window);

    menu_item = gtk_menu_item_new_with_label("Exit");
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), menu_item);
    g_signal_connect(menu_item, "activate", G_CALLBACK(on_menu_file_exit_click),
                     NULL);

    menu_item = gtk_menu_item_new_with_label("About");
    gtk_menu_shell_append(GTK_MENU_SHELL(help_menu), menu_item);
    g_signal_connect(menu_item, "activate",
                     G_CALLBACK(on_menu_help_about_click), window);

    // Agrego la barra de menú al container.
    gtk_box_pack_start(GTK_BOX(box), menu_bar, FALSE, FALSE, 0);

    // Creo drawing area para el reproductor.
    player_window = gtk_drawing_area_new();
    gtk_box_pack_start(GTK_BOX(box), player_window, TRUE, TRUE, 0);
    g_signal_connect(G_OBJECT(player_window), "realize",
                     G_CALLBACK(on_player_window_realize), NULL);
    g_signal_connect(G_OBJECT(player_window), "draw",
                     G_CALLBACK(on_player_window_draw), NULL);

    // Creo los botones de control de reproducción.
    // Creo container para los botones.
    button_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_container_set_border_width(GTK_CONTAINER(button_box), BORDER_WIDTH);
    gtk_button_box_set_layout(GTK_BUTTON_BOX(button_box), GTK_BUTTONBOX_START);

    // Creo botones.
    playpause_button = gtk_button_new_from_icon_name("media-playback-pause",
                                                     GTK_ICON_SIZE_BUTTON);
    stop_button = gtk_button_new_from_icon_name("media-playback-stop",
                                                GTK_ICON_SIZE_BUTTON);
    g_signal_connect(playpause_button, "clicked",
                     G_CALLBACK(on_playpause_click), NULL);
    g_signal_connect(stop_button, "clicked", G_CALLBACK(on_stop_click), NULL);

    // Agrego los botones al container.
    gtk_box_pack_start(GTK_BOX(button_box), playpause_button, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(button_box), stop_button, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), button_box, FALSE, FALSE, 0);

    // Inicializo libvlc.
    vlc_instance = libvlc_new(vlc_argc, vlc_argv);
    media_player = libvlc_media_player_new(vlc_instance);

    gtk_widget_show_all(window);
    gtk_main();

    libvlc_media_player_release(media_player);
    libvlc_release(vlc_instance);

    return 0;
}

void on_player_window_realize(GtkWidget* widget)
{
    libvlc_media_player_set_xwindow(
        media_player, GDK_WINDOW_XID(gtk_widget_get_window(widget)));
}

// Esta funcion es llamada cada vez que la ventana de video necesita ser
// redibujada (debido a daño, exposición, cambio de tamaño, etc). Simplemente
// dibujamos un rectángulo negro para evitar que aparezca basura.
gboolean on_player_window_draw(GtkWidget* widget, cairo_t* cr)
{
    GtkAllocation allocation;

    // Cairo es una biblioteca gráfica 2D que usamos para limpiar la ventana de
    // video.
    gtk_widget_get_allocation(widget, &allocation);
    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_rectangle(cr, 0, 0, allocation.width, allocation.height);
    cairo_fill(cr);

    return FALSE;
}

void on_menu_file_open_click(GtkWidget* widget, gpointer data)
{
    GtkWidget* dialog;
    dialog = gtk_file_chooser_dialog_new(
        "Choose Media", data, GTK_FILE_CHOOSER_ACTION_OPEN, "Cancel",
        GTK_RESPONSE_CANCEL, "Open", GTK_RESPONSE_ACCEPT, NULL);
    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
        char* uri;
        uri = gtk_file_chooser_get_uri(GTK_FILE_CHOOSER(dialog));
        media_open(uri);
        g_free(uri);
    }
    gtk_widget_destroy(dialog);
}

void on_menu_file_exit_click(GtkWidget* widget)
{
    gtk_main_quit();
}

void on_playpause_click(GtkWidget* widget)
{
    if (libvlc_media_player_is_playing(media_player))
    {
        media_pause();
    }
    else
    {
        media_play();
    }
}

void on_stop_click(GtkWidget* widget)
{
    media_pause();
    libvlc_media_player_stop(media_player);
}

void on_destroy(GtkWidget* widget)
{
    gtk_main_quit();
}

void media_open(const char* uri)
{
    libvlc_media_t* media;
    media = libvlc_media_new_location(vlc_instance, uri);
    libvlc_media_player_set_media(media_player, media);
    media_play();
    libvlc_media_release(media);
}

void media_play(void)
{
    GtkWidget* button_icon = gtk_image_new_from_icon_name(
        "media-playback-pause", GTK_ICON_SIZE_BUTTON);
    gtk_button_set_image(GTK_BUTTON(playpause_button), button_icon);
    libvlc_media_player_play(media_player);
}

void media_pause(void)
{
    GtkWidget* button_icon = gtk_image_new_from_icon_name(
        "media-playback-start", GTK_ICON_SIZE_BUTTON);
    gtk_button_set_image(GTK_BUTTON(playpause_button), button_icon);
    libvlc_media_player_pause(media_player);
}

void on_menu_help_about_click(GtkWidget* widget, gpointer data)
{
    const gchar* authors[] = {"Javier Balloffet", NULL};
    const gchar* documenters[] = {"Javier Balloffet", NULL};
    gtk_show_about_dialog(
        GTK_WINDOW(data), "program-name", "GTK and libVLC usage example",
        "version", "1.0.0", "copyright", "\xc2\xa9 2019 Javier F. Balloffet",
        "license-type", GTK_LICENSE_MIT_X11, "website",
        "https://github.com/jballoffet/programando-c-en-linux", "website-label",
        "Git Repository", "comments",
        "Program to demonstrate GTK and libVLC functions.", "authors", authors,
        "documenters", documenters, "logo-icon-name", "media-playback-start",
        NULL);
}
