#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "capteur.h"
#include <string.h>
#include <stdio.h>

int radiox=1;
int r=0;

void
on_gotoajoutercapt_clicked_capteur             (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_Ajouter_un_capteur();
  gtk_widget_show(x);
  a= lookup_widget(button,"Espace_technicien");
  gtk_widget_destroy(a);
}


void
on_gotomodifiercapteur_clicked_capteur         (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_modifier_un_capteur();
  gtk_widget_show(x);
  a= lookup_widget(button,"Espace_technicien");
  gtk_widget_destroy(a);
}


void
on_afftouver_clicked_capteur                   (GtkButton       *button,
                                        gpointer         user_data)
{
  fileload_capteur();
  int i;
  char sid[30];
  GtkWidget *liste, *id;
  id=lookup_widget(button,"gettrouver");
  liste=lookup_widget(button,"liste");
  strcpy(sid, gtk_entry_get_text(GTK_ENTRY(id)));

  i=isid_capteur(sid);
  if(i!=-1){
    viderliste_capteur(liste);
    afftrouver_capteur(liste, i);
  }
  else{
    viderliste_capteur(liste);
  }
}


void
on_affsupprimer_clicked_capteur                (GtkButton       *button,
                                        gpointer         user_data)
{
char x[100];
fileload_capteur();


GtkWidget * id, * inc, * inc2, *conf;

id = lookup_widget(button,"affsupprimercapt");
inc = lookup_widget(button,"affsupperror");
inc2 = lookup_widget(button,"label59");

strcpy(x, gtk_entry_get_text(GTK_ENTRY(id)));



if(isid_capteur(x)!=-1 && r==1){
supprimer_capteur(x);
filesave_capteur();
gtk_label_set_text(GTK_LABEL(inc), "succes.");
r=0;
}
if(isid_capteur(x)==-1 && r==1){
gtk_label_set_text(GTK_LABEL(inc), "capteur inexistant.");
r=0;
}
if (r==0);
{
gtk_label_set_text(GTK_LABEL(inc2), "confirmé la suppression");
r=1;
}
}



void
on_ajoutervalider_clicked_capteur              (GtkButton       *button,
                                        gpointer         user_data)
{
capteur x;
fileload_capteur();


GtkWidget * id, * type, * position, * etat, * valeur, * inc;


id = lookup_widget(button,"ajouterid");
type = lookup_widget(button,"ajoutertype");
position = lookup_widget(button,"ajouterposition");
etat = lookup_widget(button,"ajouteretat");
valeur=lookup_widget(button,"spinbutton1");
inc = lookup_widget(button,"ajoutererror");

  char a[20];
  sprintf(a, "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(valeur)));

strcpy(x.id, gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(x.type, gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
strcpy(x.position, gtk_entry_get_text(GTK_ENTRY(position)));
strcpy(x.etat, gtk_entry_get_text(GTK_ENTRY(etat)));
strcpy(x.valeur, a);



if((isid_capteur(x.id)==-1)&&(isint_capteur(x.id)==1)&&(nospace_capteur(x.id)==1)&&(isalphabet_capteur(x.type)==1)&&(isalphabet_capteur(x.position)==1)&&(isint_capteur(x.etat)==1)&&(isint_capteur(x.valeur)==1)){
ajout_capteur(x);
filesave_capteur();
gtk_label_set_text(GTK_LABEL(inc), "ajouter avec succes.");
}
else{
gtk_label_set_text(GTK_LABEL(inc), "Verifier vos données.");
}
}


void
on_modifvalider_clicked_capteur               (GtkButton       *button,
                                        gpointer         user_data)
{
capteur x;
fileload_capteur();


GtkWidget * id, * type, * position, * etat, * valeur, * inc;
  

id = lookup_widget(button,"modifid");
type = lookup_widget(button,"modiftype");
position = lookup_widget(button,"modifposition");
etat = lookup_widget(button,"modifetat");
inc = lookup_widget(button,"affmodifiererror");
valeur=lookup_widget(button,"spinbutton2");

  char a[20];
  sprintf(a, "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(valeur)));


strcpy(x.id, gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(x.type, gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
strcpy(x.position, gtk_entry_get_text(GTK_ENTRY(position)));
strcpy(x.etat, gtk_entry_get_text(GTK_ENTRY(etat)));
strcpy(x.valeur, a);





if((isid_capteur(x.id)!=-1)&&(isint_capteur(x.id)==1)&&(nospace_capteur(x.id)==1)&&(isalphabet_capteur(x.type)==1)&&(isalphabet_capteur(x.position)==1)&&(isint_capteur(x.etat)==1)&&(isint_capteur(x.valeur)==1)){
modifier_capteur(x);
filesave_capteur();
gtk_label_set_text(GTK_LABEL(inc), "Modification affectuer avec succes.");
}
else{
gtk_label_set_text(GTK_LABEL(inc), "Verifier vos données.");
}
}


void
on_liste_row_activated_capteur                 (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkWidget *val, *supp,*low,*modifid;
  GtkTreeIter iter;
  gchar * id, * type, * position, * etat, * valeur;
  GtkTreeModel *model= gtk_tree_view_get_model(treeview);
  char x[100];

  if(gtk_tree_model_get_iter(model, &iter, path)){

    gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1, &type,2, &position,3,&type,4,&valeur,-1);
    strcpy(x,id);}
    low=create_modifier_un_capteur();
    gtk_widget_show(low);
    modifid=lookup_widget(low,"modifid");
    gtk_entry_set_text(GTK_LABEL(modifid),x);
}


void
on_afficher_clicked_capteur                    (GtkButton       *button,
                                        gpointer         user_data)
{
fileload_capteur();
GtkWidget *liste;
liste=lookup_widget(button,"liste");
afficher_capteur(liste);
}


void
on_gotoalarme_clicked_capteur                  (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_afficher_alarme();
  gtk_widget_show(x);
  a= lookup_widget(button,"Espace_technicien");
  gtk_widget_destroy(a);
}


void
on_afficheralarme_clicked_capteur              (GtkButton       *button,
                                        gpointer         user_data)
{
int nb,nb1;
char chnb[30];
char chnb1[30];
GtkWidget *nbResultat,*message,*window1=lookup_widget(GTK_WIDGET(button),"afficher_alarme");
GtkWidget *p1=lookup_widget(window1,"treeview2");
GtkWidget *p2=lookup_widget(window1,"treeview3");
nb=chercheralarmemouvement_capteur(p1,"mouvement.txt");
nb1=chercheralarmefumee_capteur(p2,"fumee.txt");
sprintf(chnb,"%d",nb);
sprintf(chnb1,"%d",nb1);
}


void
on_button1_clicked_capteur                     (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *a,*togglebutton1,*togglebutton2;
if(radiox==2)
{
gtk_toggle_button_set_active(GTK_RADIO_BUTTON (togglebutton2),TRUE);
a= lookup_widget(button,"confirmation_capteur");
gtk_widget_destroy(a);
radiox=1;}
else
{gtk_toggle_button_set_active(GTK_RADIO_BUTTON(togglebutton1),TRUE);
exit(1);
radiox=2;}
}


void
on_radiobutton1_toggled_capteur                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
radiox=1;
}


void
on_radiobutton2_toggled_capteur                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
radiox=2;
}





void
on_buttonsortie_clicked_capteur                (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x;
  x=create_confirmation_capteur ();
  gtk_widget_show(x);
}


void
on_checkbutton1_toggled_capteur                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
r=1;
else
r=0;
}


void
on_buttonacc1_clicked_capteur                  (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_Espace_technicien ();
  gtk_widget_show(x);
  a= lookup_widget(button,"Ajouter_un_capteur");
  gtk_widget_destroy(a);
}


void
on_buttonacc2_clicked_capteur                  (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_Espace_technicien ();
  gtk_widget_show(x);
  a= lookup_widget(button,"modifier_un_capteur");
  gtk_widget_destroy(a);
}


void
on_buttonacc3_clicked_capteur                  (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_Espace_technicien ();
  gtk_widget_show(x);
  a= lookup_widget(button,"afficher_alarme");
  gtk_widget_destroy(a);
}

