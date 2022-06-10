#include <stdlib.h>
#include <gtk/gtk.h>
#include <data_structure.h>
#include <functiion_Gtk.h>
#include <string.h>

GtkBuilder *builder;
GtkWidget *window;

//Function display window
void btn_list_clicked()
{
    gtk_widget_hide(window);
    window = GTK_WIDGET(gtk_builder_get_object(builder, "Second"));
    gtk_widget_show_all (window);
    printf("List data FA is clicked.\n");
}
void btn_design_clicked()
{
    gtk_widget_hide(window);
    window = GTK_WIDGET(gtk_builder_get_object(builder, "Third"));
    gtk_widget_show_all (window);
    printf("Design is clicked.\n");
}
void btn_Mini_clicked()
{
    gtk_widget_hide(window);
    window = GTK_WIDGET(gtk_builder_get_object(builder, "Minimize"));
    gtk_widget_show_all (window);
    printf("Minimize FA is clicked.\n");
}
void btn_testFA_clicked()
{
    gtk_widget_hide(window);
    window = GTK_WIDGET(gtk_builder_get_object(builder, "test_fa"));
    gtk_widget_show_all (window);
    printf("Test FA is clicked.\n");
}
void btn_tstring_clicked()
{
    gtk_widget_hide(window);
    window = GTK_WIDGET(gtk_builder_get_object(builder, "test_string"));
    gtk_widget_show_all (window);
    printf("Test String is clicked.\n");
}
void btn_con_clicked()
{
    gtk_widget_hide(window);
    window = GTK_WIDGET(gtk_builder_get_object(builder, "convert"));
    gtk_widget_show_all (window);
    printf("Convert is clicked.\n");
}

//Function btn_back
void btn_back1_clicked()
{
    gtk_widget_hide(window);
    window = GTK_WIDGET(gtk_builder_get_object(builder, "First"));
    gtk_widget_show_all (window);
    printf("Back is clicked.\n");
}
void btn_back2_clicked()
{
    gtk_widget_hide(window);
    window = GTK_WIDGET(gtk_builder_get_object(builder, "First"));
    gtk_widget_show_all (window);
    printf("Back is clicked.\n");
}
void btn_back3_clicked()
{
    gtk_widget_hide(window);
    window = GTK_WIDGET(gtk_builder_get_object(builder, "First"));
    gtk_widget_show_all (window);
    printf("Back is clicked.\n");
}
void btn_back4_clicked()
{
    gtk_widget_hide(window);
    window = GTK_WIDGET(gtk_builder_get_object(builder, "First"));
    gtk_widget_show_all (window);
    printf("Back is clicked.\n");
}
void btn_back5_clicked()
{
    gtk_widget_hide(window);
    window = GTK_WIDGET(gtk_builder_get_object(builder, "First"));
    gtk_widget_show_all (window);
    printf("Back is clicked.\n");
}
void btn_back6_clicked()
{
    gtk_widget_hide(window);
    window = GTK_WIDGET(gtk_builder_get_object(builder, "First"));
    gtk_widget_show_all (window);
    printf("Back is clicked.\n");
}

//Function btn_exit
void btn_exit1_clicked()
{
    exit(1);
}
void btn_exit2_clicked()
{
    exit(1);
}
void btn_exit3_clicked()
{
    exit(1);
}
void btn_exit4_clicked()
{
    exit(1);
}
void btn_exit5_clicked()
{
    exit(1);
}
void btn_exit6_clicked()
{
    exit(1);
}

//Test
    GtkWidget *input;
    GtkWidget *input1;
    GtkWidget *input2;
    GtkWidget *input3;
    GtkWidget *input4;
    GtkWidget *input5;
    GtkWidget *input6;
    GtkWidget *input7;
    GtkWidget *input8;
    GtkWidget *input9;
    GtkWidget *input10;
    GtkWidget *input11;
    GtkWidget *input12;
    GtkWidget *label;
    GtkWidget *label1;

void btn_teststring_clicked()
{
    gchar *numfa;
    gchar *fastring;
    char *value;
    numfa = gtk_entry_get_text(input);
    fastring = gtk_entry_get_text(input1);
    int id = atoi(numfa);
    printf("\nSelected number %d for FA.\n ",id);
    printf("String of FA is %s \n",fastring);
    value = test_string(id,fastring);
    printf("%s",&value);
    gtk_label_set_text(GTK_LABEL(label),&value);
}
void btn_ok_clicked()
{
    gchar *numfa;
    numfa = gtk_entry_get_text(input2);
    int id = atoi(numfa);
    printf("\nSelected number %d for FA.\n",id);
}
void btn_tFA_clicked()
{
    gchar *numfa;
    int value;
    numfa = gtk_entry_get_text(input3);
    int id = atoi(numfa);
    printf("\nSelected number %d for FA.\n",id);
    value = testFA(id);
    char *r;
    if (value == 1)
    {
        strcpy(&r,"Non-deterministic.");
    }
    else
    {
        strcpy(&r,"Deterministic.");
    }
    gtk_label_set_text(GTK_LABEL(label1),&r);
}
void btn_convert_clicked()
{
    gchar *numfa;
    numfa = gtk_entry_get_text(input4);
    int id = atoi(numfa);
    printf("\nSelected number %d for FA.\n",id);
}
void btn_minimize_clicked()
{
    gchar *numfa;
    numfa = gtk_entry_get_text(input5);
    int id = atoi(numfa);
    printf("\nSelected number %d for FA.\n",id);
}
void btn_save_clicked()
{
    gchar *fatype;
    gchar *fades;
    gchar *state;
    gchar *sstate;
    gchar *fstate;
    gchar *alpha;
    gchar *tran;

    fatype = gtk_entry_get_text(input6);
    printf("FA type: %s.\n",fatype);
    fades = gtk_entry_get_text(input7);
    printf("FA description: %s.\n",fades);
    state = gtk_entry_get_text(input8);
    printf("State: %s.\n",state);
    sstate = gtk_entry_get_text(input9);
    int ss = atoi(sstate);
    printf("Start State: %d.\n",ss);
    fstate = gtk_entry_get_text(input10);
    int fs = atoi(fstate);
    printf("Final State: %d.\n",fs);
    alpha = gtk_entry_get_text(input11);
    printf("Alphabet: %s.\n",alpha);
    tran = gtk_entry_get_text(input12);
    printf("Transition: %s.\n",tran);
}

int main (int argc, char *argv[])
{
  /* Initialize GTK+ */
  g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, (GLogFunc) gtk_false, NULL);
  gtk_init (&argc, &argv);
  g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, g_log_default_handler, NULL);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "Finally_FA.glade", NULL);
    window = GTK_WIDGET(gtk_builder_get_object(builder, "First"));
    gtk_builder_connect_signals(builder, NULL);

    //  Callback
    GtkWidget *g_btn_list;
    GtkWidget *g_btn_design;
    GtkWidget *g_btn_Mini;
    GtkWidget *g_btn_testFA;
    GtkWidget *g_btn_tstring;
    GtkWidget *g_btn_con;
    GtkWidget *g_btn_exit1;
    GtkWidget *g_btn_exit2;
    GtkWidget *g_btn_exit3;
    GtkWidget *g_btn_exit4;
    GtkWidget *g_btn_exit5;
    GtkWidget *g_btn_exit6;
    GtkWidget *g_btn_back1;
    GtkWidget *g_btn_back2;
    GtkWidget *g_btn_back3;
    GtkWidget *g_btn_back4;
    GtkWidget *g_btn_back5;
    GtkWidget *g_btn_back6;
    GtkWidget *g_btn_teststring;
    GtkWidget *g_btn_ok;
    GtkWidget *g_btn_tFA;
    GtkWidget *g_btn_convert;
    GtkWidget *g_btn_minimize;
    GtkWidget *g_btn_save;

    g_btn_list = GTK_WIDGET(gtk_builder_get_object(builder, "but_list"));
    g_signal_connect (G_OBJECT (g_btn_list), "clicked", G_CALLBACK(btn_list_clicked), (gpointer) window);

    g_btn_design = GTK_WIDGET(gtk_builder_get_object(builder, "but_design"));
    g_signal_connect (G_OBJECT (g_btn_design), "clicked", G_CALLBACK(btn_design_clicked), (gpointer) window);

    g_btn_testFA = GTK_WIDGET(gtk_builder_get_object(builder, "but_tFA"));
    g_signal_connect (G_OBJECT (g_btn_testFA), "clicked", G_CALLBACK(btn_testFA_clicked), (gpointer) window);

    g_btn_tstring = GTK_WIDGET(gtk_builder_get_object(builder, "but_tstring"));
    g_signal_connect (G_OBJECT (g_btn_tstring), "clicked", G_CALLBACK(btn_tstring_clicked), (gpointer) window);

    g_btn_con = GTK_WIDGET(gtk_builder_get_object(builder, "but_con"));
    g_signal_connect (G_OBJECT (g_btn_con), "clicked", G_CALLBACK(btn_con_clicked), (gpointer) window);

    g_btn_Mini = GTK_WIDGET(gtk_builder_get_object(builder, "but_Mini"));
    g_signal_connect (G_OBJECT (g_btn_Mini), "clicked", G_CALLBACK(btn_Mini_clicked), (gpointer) window);

    //Back
    g_btn_back1 = GTK_WIDGET(gtk_builder_get_object(builder, "but_back1"));
    g_signal_connect (G_OBJECT (g_btn_back1), "clicked", G_CALLBACK(btn_back1_clicked), (gpointer) window);

    g_btn_back2 = GTK_WIDGET(gtk_builder_get_object(builder, "but_back2"));
    g_signal_connect (G_OBJECT (g_btn_back2), "clicked", G_CALLBACK(btn_back2_clicked), (gpointer) window);

    g_btn_back3 = GTK_WIDGET(gtk_builder_get_object(builder, "but_back3"));
    g_signal_connect (G_OBJECT (g_btn_back3), "clicked", G_CALLBACK(btn_back3_clicked), (gpointer) window);

    g_btn_back4 = GTK_WIDGET(gtk_builder_get_object(builder, "but_back4"));
    g_signal_connect (G_OBJECT (g_btn_back4), "clicked", G_CALLBACK(btn_back4_clicked), (gpointer) window);

    g_btn_back5 = GTK_WIDGET(gtk_builder_get_object(builder, "but_back5"));
    g_signal_connect (G_OBJECT (g_btn_back5), "clicked", G_CALLBACK(btn_back5_clicked), (gpointer) window);

    g_btn_back6 = GTK_WIDGET(gtk_builder_get_object(builder, "but_back6"));
    g_signal_connect (G_OBJECT (g_btn_back6), "clicked", G_CALLBACK(btn_back6_clicked), (gpointer) window);

    //Exit
    g_btn_exit1 = GTK_WIDGET(gtk_builder_get_object(builder, "but_ex1"));
    g_signal_connect (G_OBJECT (g_btn_exit1), "clicked", G_CALLBACK(btn_exit2_clicked), (gpointer) window);

    g_btn_exit2 = GTK_WIDGET(gtk_builder_get_object(builder, "but_ex2"));
    g_signal_connect (G_OBJECT (g_btn_exit2), "clicked", G_CALLBACK(btn_exit2_clicked), (gpointer) window);

    g_btn_exit3 = GTK_WIDGET(gtk_builder_get_object(builder, "but_ex3"));
    g_signal_connect (G_OBJECT (g_btn_exit3), "clicked", G_CALLBACK(btn_exit3_clicked), (gpointer) window);

    g_btn_exit4 = GTK_WIDGET(gtk_builder_get_object(builder, "but_ex4"));
    g_signal_connect (G_OBJECT (g_btn_exit4), "clicked", G_CALLBACK(btn_exit4_clicked), (gpointer) window);

    g_btn_exit5 = GTK_WIDGET(gtk_builder_get_object(builder, "but_ex5"));
    g_signal_connect (G_OBJECT (g_btn_exit5), "clicked", G_CALLBACK(btn_exit5_clicked), (gpointer) window);

    g_btn_exit6 = GTK_WIDGET(gtk_builder_get_object(builder, "but_ex6"));
    g_signal_connect (G_OBJECT (g_btn_exit6), "clicked", G_CALLBACK(btn_exit6_clicked), (gpointer) window);

    //Test and input data
    g_btn_teststring = GTK_WIDGET(gtk_builder_get_object(builder, "btn_teststring"));
        input = GTK_WIDGET(gtk_builder_get_object(builder, "in_num5"));
        input1 = GTK_WIDGET(gtk_builder_get_object(builder, "in_string"));
        label = GTK_WIDGET(gtk_builder_get_object(builder, "result1"));
    g_signal_connect (G_OBJECT (g_btn_teststring), "clicked", G_CALLBACK(btn_teststring_clicked), NULL);

    g_btn_ok = GTK_WIDGET(gtk_builder_get_object(builder, "but_ok1"));
        input2 = GTK_WIDGET(gtk_builder_get_object(builder, "in_num1"));
    g_signal_connect (G_OBJECT (g_btn_ok), "clicked", G_CALLBACK(btn_ok_clicked), NULL);

    g_btn_tFA = GTK_WIDGET(gtk_builder_get_object(builder, "but_test1"));
        input3 = GTK_WIDGET(gtk_builder_get_object(builder, "in_num2"));
        label1 = GTK_WIDGET(gtk_builder_get_object(builder, "result2"));
    g_signal_connect (G_OBJECT (g_btn_tFA), "clicked", G_CALLBACK(btn_tFA_clicked), NULL);

    g_btn_convert = GTK_WIDGET(gtk_builder_get_object(builder, "but_convert"));
        input4 = GTK_WIDGET(gtk_builder_get_object(builder, "in_mun3"));
    g_signal_connect (G_OBJECT (g_btn_convert), "clicked", G_CALLBACK(btn_convert_clicked), NULL);

    g_btn_minimize = GTK_WIDGET(gtk_builder_get_object(builder, "but_minimize"));
        input5 = GTK_WIDGET(gtk_builder_get_object(builder, "in_num4"));
    g_signal_connect (G_OBJECT (g_btn_minimize), "clicked", G_CALLBACK(btn_minimize_clicked), NULL);

    g_btn_save = GTK_WIDGET(gtk_builder_get_object(builder, "but_save"));
        input6 = GTK_WIDGET(gtk_builder_get_object(builder, "fa_type"));
        input7 = GTK_WIDGET(gtk_builder_get_object(builder, "fa_des"));
        input8 = GTK_WIDGET(gtk_builder_get_object(builder, "state"));
        input9 = GTK_WIDGET(gtk_builder_get_object(builder, "sstate"));
        input10 = GTK_WIDGET(gtk_builder_get_object(builder, "fstate"));
        input11 = GTK_WIDGET(gtk_builder_get_object(builder, "alphabet"));
        input12 = GTK_WIDGET(gtk_builder_get_object(builder, "transition"));
    g_signal_connect (G_OBJECT (g_btn_save), "clicked", G_CALLBACK(btn_save_clicked), NULL);

  /* Enter the main loop */
  gtk_widget_show_all (window);
  gtk_main ();
  return 0;
}
