/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: vostino
 *
 * Created on March 29, 2021, 9:58 PM
 */

#include <stdio.h>
#include <stdlib.h>

#include "Main.h"


/*Initialize functions*/
static void destroy(GtkWidget*, gpointer);
static gboolean delete_event(GtkWidget*, GdkEvent*, gpointer);
static void gtkCsslod();

/*Main*/
int main(int argc, char** argv) {
    /*Declarations*/
    GtkWidget *window, *uivbox;

    /*Create database with table if not exist*/
    createTbl();

    /*Initialize library*/
    gtk_init(&argc, &argv);
    gtkCsslod();

    /*Create window*/
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "S Calculator");
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

    /*Window size*/
    /*gtk_window_set_default_size(GTK_WINDOW(window), 550, 400);*/

    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), NULL);
    g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(delete_event), NULL);

    /*Add UI*/
    uivbox = retVbox();
    gtk_container_add(GTK_CONTAINER(window), uivbox);

    /*Show window*/
    gtk_widget_show_all(window);

    /*Main loop*/
    gtk_main();

    return 0;

}

/*Destroy window on close*/
static void destroy(GtkWidget *window, gpointer data) {
    freemainMem();
    gtk_main_quit();

}

/*Destroy widget*/
static gboolean delete_event(GtkWidget *window, GdkEvent *event, gpointer data) {
    return FALSE;
}

/*Load CSS*/
static void gtkCsslod() {
    /*Load css*/
    GtkCssProvider *cssprovid = gtk_css_provider_new();
    /*gtk_css_provider_load_from_path(cssprovid, "Styles/Unicomb.css", NULL);*/
    gtk_css_provider_load_from_resource(cssprovid, "/com/avintangu/scalculator/Unicomb.css");
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(cssprovid), GTK_STYLE_PROVIDER_PRIORITY_USER);


}

