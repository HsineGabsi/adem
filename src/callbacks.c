#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"

#include "fonction.h"
int type=1;
void
on_ajouterUser_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *espritId, *nom, *prenom, *jour, *mois, *annee, *email, *tel, *cin, *sexe, *role ;
char sexa[20];
char password[20];
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;

espritId = lookup_widget (button, "espritIda");
nom = lookup_widget (button, "noma");
prenom = lookup_widget (button, "prenoma");
jour = lookup_widget (button, "joura");
mois = lookup_widget (button, "moisa");
annee = lookup_widget (button, "anneea");
email = lookup_widget (button, "emaila");
tel = lookup_widget (button, "tela");
cin = lookup_widget (button, "cina");
role = lookup_widget (button, "rolea");

inscription(type,sexa);
genererPassword(password);
user u;
date d;
strcpy(u.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(u.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(u.espritId, gtk_entry_get_text(GTK_ENTRY(espritId)));
strcpy(u.email, gtk_entry_get_text(GTK_ENTRY(email)));
strcpy(u.tel, gtk_entry_get_text(GTK_ENTRY(tel)));
strcpy(u.cin, gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(u.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)));
d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(u.password,password);
strcpy(u.sexe,sexa);
u.dateN=d;
ajouter_user(u);
fenetre_ajout=lookup_widget(button,"ajouter_user");
gtk_widget_destroy(fenetre_ajout);
fenetre_afficher=lookup_widget(button,"gestion_des_utilisateurs");
fenetre_afficher=create_gestion_des_utilisateurs();
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"treeview1");
afficher_user(treeview1);


 char cmd[100];  // to hold the command.
        char to[] = "hsine.gabsi@esprit.tn"; // email id of the recepient.
        char body[] = "SO rocks";    // email body.
        char tempFile[100];     // name of tempfile.

        strcpy(tempFile,tempnam("/tmp","sendmail")); // generate temp file name.

        FILE *fp = fopen(tempFile,"w"); // open it for writing.
        fprintf(fp,"%s\n",body);        // write body to it.
        fclose(fp);             // close it.

        sprintf(cmd,"sendmail %s < %s",to,tempFile); // prepare command.
        system(cmd);     // execute it.

        return 0;


}


void
on_homme_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active (GTK_RADIO_BUTTON(togglebutton)))
type=1;
}


void
on_femme_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if (gtk_toggle_button_get_active (GTK_RADIO_BUTTON(togglebutton)))
type=2;
}


void
on_actualiser_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*w1;
GtkWidget *treeview1;
w1=lookup_widget(objet,"gestion_des_utilisateurs");
fenetre_afficher=create_gestion_des_utilisateurs();
gtk_widget_show(fenetre_afficher);
gtk_widget_hide(w1);
treeview1=lookup_widget(fenetre_afficher,"treeview1");

afficher_user(treeview1);
}




void
on_afficher_user_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;
fenetre_ajout=lookup_widget(objet,"ajouter_user");
gtk_widget_destroy(fenetre_ajout);
fenetre_afficher=lookup_widget(objet,"gestion_des_utilisateurs");
fenetre_afficher=create_gestion_des_utilisateurs();
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"treeview1");
afficher_user(treeview1);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* espritId;

char id[20];
GtkTreeModel *model= gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model, &iter, path)){
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,3,&espritId,-1);

strcpy(id,espritId); 
   g_print("%s\n",id); 
 g_free(espritId); 
 supprimer_user(id);
gtk_list_store_remove(GTK_LIST_STORE(model), &iter);

afficher_user(treeview);

}

}


void
on_ajouterUtilisateur_clicked          (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;

fenetre_afficher=lookup_widget(objet,"gestion_des_utilisateurs");

gtk_widget_destroy(fenetre_afficher);
fenetre_ajout=lookup_widget(objet,"ajouter_user");
fenetre_ajout=create_ajouter_user();
gtk_widget_show(fenetre_ajout);

}





//////////////////////////////////////////////////////

void
  view_popup_menu_onDoSomething (GtkWidget *menuitem, gpointer userdata)
  {
    /* we passed the view as userdata when we connected the signal */
    GtkTreeView *treeview = GTK_TREE_VIEW(userdata);

GtkWidget *fenetre_afficher;
GtkWidget *fenetre_modif;
gchar* espritId;
GtkWidget *espritId1;
char id[20];
fenetre_afficher=lookup_widget(treeview,"gestion_des_utilisateurs");

gtk_widget_destroy(fenetre_afficher);
fenetre_modif=create_modifier_user();
gtk_widget_show(fenetre_modif);
const gchar *str = gtk_entry_get_text(userdata);
    g_print ("%s\n",str);
  }


  void
  view_popup_menu (GtkWidget *treeview, GdkEventButton *event, gpointer userdata)
  {
    GtkWidget *menu, *menuitem;

    menu = gtk_menu_new();

    menuitem = gtk_menu_item_new_with_label("Modifier");

    g_signal_connect(menuitem, "activate",
                     (GCallback) view_popup_menu_onDoSomething, treeview);

    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);

    gtk_widget_show_all(menu);

    /* Note: event can be NULL here when called from view_onPopupMenu;
     *  gdk_event_get_time() accepts a NULL argument */
    gtk_menu_popup(GTK_MENU(menu), NULL, NULL, NULL, NULL,
                   (event != NULL) ? event->button : 0,
                   gdk_event_get_time((GdkEvent*)event));
  }


  gboolean
on_treeview1_button_press_event         (GtkWidget *treeview, GdkEventButton *event, gpointer userdata)
  {
    /* single click with the right mouse button? */
    if (event->type == GDK_BUTTON_PRESS  &&  event->button == 3)
    {
      g_print ("Single right click on the tree view.\n");

      /* optional: select row if no row is selected or only
       *  one other row is selected (will only do something
       *  if you set a tree selection mode as described later
       *  in the tutorial) */
      if (1)
      {
        GtkTreeSelection *selection;

        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));

        /* Note: gtk_tree_selection_count_selected_rows() does not
         *   exist in gtk+-2.0, only in gtk+ >= v2.2 ! */
        if (gtk_tree_selection_count_selected_rows(selection)  <= 1)
        {
           GtkTreePath *path;

           /* Get tree path for row that was clicked */
           if (gtk_tree_view_get_path_at_pos(GTK_TREE_VIEW(treeview),
                                             (gint) event->x, 
                                             (gint) event->y,
                                             &path, NULL, NULL, NULL))
           {
             gtk_tree_selection_unselect_all(selection);
             gtk_tree_selection_select_path(selection, path);
             gtk_tree_path_free(path);
           }
        }
      } /* end of optional bit */

      view_popup_menu(treeview, event, userdata);

      return TRUE; /* we handled this */
    }

    return FALSE; /* we did not handle this */
  }


  gboolean
  on_treeview1_popup_menu(GtkWidget *treeview, gpointer userdata)
  {
    view_popup_menu(treeview, NULL, userdata);

    return TRUE; /* we handled this */
  }


  void
  create_view (void)
  {
    GtkWidget *view;

    view = gtk_tree_view_new();



    g_signal_connect(view, "button-press-event", (GCallback) on_treeview1_button_press_event, NULL);
    g_signal_connect(view, "popup-menu", (GCallback) on_treeview1_popup_menu, NULL);


  }

 
////////////////////////////////////////////////////////////
void
on_rechercherUser_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_rechercher;
GtkWidget *fenetre_afficher;
GtkWidget *espritId;
GtkWidget *treeview1;
char rech[20];
espritId = lookup_widget (objet, "esId");
strcpy(rech, gtk_entry_get_text(GTK_ENTRY(espritId)));
fenetre_afficher=lookup_widget(objet,"gestion_des_utilisateurs");
gtk_widget_destroy(fenetre_afficher);
fenetre_rechercher=lookup_widget(objet,"gestion_des_utilisateurs");
fenetre_rechercher=create_gestion_des_utilisateurs();
gtk_widget_show(fenetre_rechercher);
treeview1=lookup_widget(fenetre_rechercher,"treeview1");
rechercher_user(treeview1,rech);
}


void
on_retourU_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_modifierUser_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_hommem_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_femmem_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}

