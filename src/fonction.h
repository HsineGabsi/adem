#include <gtk/gtk.h>
typedef struct
{
int jour;
int mois;
int annee;
}date;

typedef struct
{char espritId[20];
char nom[20];
char prenom[20];
char password[30];
date dateN;
char email[50];
char sexe[20];
char cin[20];
char tel[20];
char role[20];
}user;
void genererPassword(char password[]);
void inscription(int type,char gender[]);
void vider(GtkWidget *liste);
void afficher_user(GtkWidget *liste);
void ajouter_user(user u);
void supprimer_user(char id[]);
void rechercher_user(GtkWidget *liste,char rech[]);
