#include <gtk/gtk.h>


void
on_ajouterUser_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_homme_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_femme_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_actualiser_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_afficher_user_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ajouterUtilisateur_clicked         (GtkWidget      *objet,
                                        gpointer         user_data);

gboolean
on_treeview1_popup_menu                (GtkWidget       *widget,
                                        gpointer         user_data);

gboolean
on_treeview1_button_press_event         (GtkWidget *treeview, GdkEventButton *event, gpointer userdata);

void
on_rechercherUser_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retourU_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifierUser_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_hommem_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_femmem_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
