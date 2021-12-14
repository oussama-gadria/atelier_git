#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "nutritioniste.h"

#include "string.h"
#include "stdio.h"
int rog;
int radioog=1;

///////////////////////tache ajout ///////////////////////////////////

///////////////////////ajout => menu//////////////////////////////////
void
on_retour1_clicked                     (GtkButton       *button,
                                     gpointer         user_data)
{
GtkWidget *Gestiondemenu;
GtkWidget *Ajouter_menu;

Gestiondemenu=create_Gestiondemenu();
gtk_widget_show(Gestiondemenu);
Ajouter_menu=lookup_widget(button,"Ajouter_menu");
gtk_widget_hide(Ajouter_menu);
}
/////////////////////menu ==> ajout ///////////////////////////////////
void
on_ajouter_menu_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *Gestiondemenu;
GtkWidget *Ajouter_menu;
Ajouter_menu=create_Ajouter_menu();
gtk_widget_show(Ajouter_menu);
Gestiondemenu=lookup_widget(button,"Gestiondemenu");
gtk_widget_hide(Gestiondemenu);

}
/////////////////fontion ajout////////////////////////////////////////
void
on_ajouter_menu_og_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
menu m;
fileload_menu();
GtkWidget*input1;
GtkWidget*input2;
GtkWidget*input3;
GtkWidget*input4;
GtkWidget*input5;
GtkWidget*input6;
GtkWidget*input7;
GtkWidget*input8;
GtkWidget*sortie1;


input2=lookup_widget(button,"entry3");
input1=lookup_widget(button,"entry7");
input3=lookup_widget(button,"combobox1");
input4=lookup_widget(button,"spinbutton1");
input5=lookup_widget(button,"spinbutton2");
input6=lookup_widget(button,"spinbutton3");
input7=lookup_widget(button,"spinbutton9");
input8=lookup_widget(button,"entry22");
sortie1=lookup_widget(button,"label35");

strcpy(m.ds,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(m.idog,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(m.repas,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(m.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
m.d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
m.d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
m.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
m.qd=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(input7));


if(isid_menu(m.idog)==-1)
{
ajouter_menu(m);
gtk_label_set_text(GTK_LABEL(sortie1),"ajout effectué avec succes");
filesave_menu();}
else {
gtk_label_set_text(GTK_LABEL(sortie1),"id existant deja ");
}
}

/////////////////////tache supprimer ////////////////////////////////
////////////////////menu ==> supprimer : par selection////////////////////////////////
void
on_supprimer_menu_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *OGaccueil;
GtkWidget *OGsupprime;
GtkWidget *OGtreeview_menu;
GtkTreeSelection *selection;
GtkTreeModel *model;
GtkTreeIter iter;
	gchar * idog;
	gchar * jour;
	gchar * mois; 
	gchar * annee; 
	gchar * type;
 	gchar *repas;
	gchar *qd; 
        gchar *ds;
        gchar *inc;
        menu m;           
	

GtkWidget *input0;
OGaccueil=lookup_widget(button,"Gestiondemenu");
OGtreeview_menu=lookup_widget(OGaccueil,"treeview_menu");
selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(OGtreeview_menu));

if(gtk_tree_selection_get_selected(selection,&model,&iter))
{
gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0,&idog,1,&jour,2,&mois,3,&annee,4,&type,5,&repas,6,&qd,7,&ds,8,-1);
	
	strcpy(m.idog,idog);
	strcpy(m.type,type);
	strcpy(m.repas,repas);
               strcpy(m.ds,ds);
              m.d.jour=jour;
              m.d.mois=mois;
              m.d.annee=annee;
}
gtk_widget_destroy(OGaccueil);
OGsupprime=create_Supprimer_menu();
gtk_widget_show(OGsupprime);
input0=lookup_widget(OGsupprime,"entry21");
gtk_entry_set_text (GTK_ENTRY(input0),m.idog);
}
////////////////////supprimer => menu////////////////////////////////
void
on_retour3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Gestiondemenu;
GtkWidget *Supprimer_menu;

Gestiondemenu=create_Gestiondemenu();
gtk_widget_show(Gestiondemenu);
Supprimer_menu=lookup_widget(button,"Supprimer_menu");
gtk_widget_hide(Supprimer_menu);
}
///////////////////fonction supprimer /////////////////////////////
void
on_confirmer_menu_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *sortie3;
GtkWidget *outputMsg;
char text[100];
char idog[30];


input1=lookup_widget(button,"entry21");
sortie3=lookup_widget(button,"label37");
strcpy(idog,gtk_entry_get_text(GTK_ENTRY(input1)));
 if(rog)
  {
  supprimer_menu(idog);
  gtk_label_set_text(GTK_LABEL(sortie3),"Suppression effectué avec succes");
 filesave_menu();
 rog=0;
  }
  else 
  { 
   strcpy (text," confirmez d'abord ");
    outputMsg=lookup_widget(button,("label59"));
    gtk_label_set_text(GTK_LABEL(outputMsg),text);
    
  }
    
}

//////////////////confirmer pour supprimer ///////////////////////
void
on_conf_suppr_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if(gtk_toggle_button_get_active(togglebutton))
rog=1;
else
rog=0;
}


///////////////////////////tache de modification //////////////////////

////////////////////////// modif ==> menu //////////////////////////// 
void
on_retour2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Gestiondemenu;
GtkWidget *Modifier_menu;

Gestiondemenu=create_Gestiondemenu();
gtk_widget_show(Gestiondemenu);
Modifier_menu=lookup_widget(button,"Modifier_menu");
gtk_widget_hide(Modifier_menu);
}
//////////////////////fonction modif ///////////////////////////////

void
on_modifier2_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

fileload_menu();
menu m;

GtkWidget * idog, * jour, * mois , * annee, * type, * repas ,*qd,*ds,*inc;


idog=lookup_widget(button,"entry9");
repas=lookup_widget(button,"entry11");
ds=lookup_widget(button,"entry23");
type=lookup_widget(button,"combobox2");
jour=lookup_widget(button,"spinbutton4");
mois=lookup_widget(button,"spinbutton5");
annee=lookup_widget(button,"spinbutton6");
qd=lookup_widget(button,"spinbutton8");
inc=lookup_widget(button,"label52");
strcpy(m.ds, gtk_entry_get_text(GTK_ENTRY(ds)));
strcpy(m.repas, gtk_entry_get_text(GTK_ENTRY(repas)));
strcpy(m.idog, gtk_entry_get_text(GTK_ENTRY(idog)));
strcpy(m.type, gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
m.d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
m.d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
m.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
m.qd=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(qd));


modifier_menu(m);
filesave_menu();
gtk_label_set_text(GTK_LABEL(inc), "Modification affectuer avec succes.");

}


////////////////////////menu => modif : par selection ///////////////
void
on_modifier_menu_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *OGaccueil;
GtkWidget *OGmodif;
GtkWidget *OGtreeview_menu;
GtkTreeSelection *selection;
GtkTreeModel *model;
GtkTreeIter iter;
	gchar * idog;
	gchar * jour;
	gchar * mois; 
	gchar * annee; 
	gchar * type;
 	gchar *repas;
	gchar *qd; 
        gchar *ds;
        gchar *inc;
        menu m;               
	


GtkWidget*input1;
GtkWidget*input2;
GtkWidget*input3;
GtkWidget*input4;
GtkWidget*input5;
GtkWidget*input6;
GtkWidget*input7;
GtkWidget*input8;
GtkWidget*input9;

OGaccueil=lookup_widget(button,"Gestiondemenu");
OGtreeview_menu=lookup_widget(OGaccueil,"treeview_menu");
selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(OGtreeview_menu));

if(gtk_tree_selection_get_selected(selection,&model,&iter))
{
gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0,&idog,1,&jour,2,&mois,3,&annee,4,&type,5,&repas,6,&qd,7,&ds,8,-1);
	
	strcpy(m.idog,idog);
	strcpy(m.type,type);
	strcpy(m.repas,repas);
        strcpy(m.ds,ds);
        m.d.jour=jour;
        m.d.mois=mois;
        m.d.annee=annee; 
}
gtk_widget_hide(OGaccueil);
OGmodif=create_Modifier_menu ();
gtk_widget_show(OGmodif);
input1=lookup_widget(OGmodif,"entry11");
input2=lookup_widget(OGmodif,"entry9");
input3=lookup_widget(OGmodif,"spinbutton4");
input4=lookup_widget(OGmodif,"spinbutton5");
input5=lookup_widget(OGmodif,"spinbutton6");
input6=lookup_widget(OGmodif,"combobox2");
input7=lookup_widget(OGmodif,"spinbutton8");
input8=lookup_widget(OGmodif,"entry23");

gtk_entry_set_text (GTK_ENTRY(input1),m.repas);
gtk_entry_set_text (GTK_ENTRY(input2),m.idog);
gtk_entry_set_text (GTK_ENTRY(input8),m.ds);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input3),m.d.jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input4),m.d.mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input5),m.d.annee);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input7),m.qd);

}





/////////////////////////tache affichage /////////////////////////////
void
on_Afficher_menu_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
fileload_menu();
GtkWidget *treeview_menu;
treeview_menu=lookup_widget(button,"treeview_menu");
afficher_menu(treeview_menu);
filesave_menu();
}





//////////////////////tache rechercher///////////////////////////////
void
on_chercher_menu_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
fileload_menu();
  int i;
  char sid[30];
  GtkWidget *liste, *idog;
  idog=lookup_widget(button,"entry200");
  liste=lookup_widget(button,"treeview_menu");
  strcpy(sid, gtk_entry_get_text(GTK_ENTRY(idog)));

  i=isid_menu(sid);
  if(i!=-1){
    viderliste_menu(liste);
    recherche_une_menu(liste, i);
  }
  else{
    viderliste_menu(liste);
  }
}

//////////////////////meuilleur menu/////////////////////////////////

////////////////////fontion meuilleur////////////////////////////////
void
on_afficher_meuilleur_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *f;
menu T[1000];
f=fopen("menu.txt","r+");
GtkWidget *sortie1;
int index;
int n=0;
index=meuilleur_menu();
sortie1=lookup_widget(button,"label61");
while((fscanf(f,"%s %d %d %d %s %s %f %s \n",T[n].idog,&T[n].d.jour,&T[n].d.mois,&T[n].d.annee,T[n].type,T[n].repas,&T[n].qd,&T[n].ds)!=EOF)&&(n!=index))
    {
        n++;
    }
gtk_label_set_text(GTK_LABEL(sortie1),T[index].repas);
}
/////////////////////welcome = > meuilleur/////////////////////////////
void
on_gotomeuilleur_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *meuilleur;
GtkWidget *WELCOME;

meuilleur=create_meuilleur();
gtk_widget_show(meuilleur);
WELCOME=lookup_widget(button,"WELCOME");
gtk_widget_hide(WELCOME);
}
////////////////////////////////////////////////////////////////////////
void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{


}




void
on_confirmermodification_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


////////////////////////quiter l'application///////////////////////// 
void
on_validermenu_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *a,*welcome,*togglebutton1,*togglebutton2,*Quiter;
if (radioog==2)
{
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(togglebutton2),TRUE);
a=lookup_widget(button,"Gestiondemenu");
gtk_widget_destroy(a);
welcome=create_WELCOME();
Quiter=create_Quiter();
gtk_widget_destroy(Quiter);
gtk_widget_show(welcome);
radioog=1;
}
else 
{gtk_toggle_button_set_active(GTK_RADIO_BUTTON(togglebutton1),TRUE);
exit(1);
radioog=2;
}
}

void
on_quiterapp_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Quiter;
GtkWidget *WELCOME;

Quiter=create_Quiter();
gtk_widget_show(Quiter);
WELCOME=lookup_widget(button,"WELCOME");
gtk_widget_hide(WELCOME);
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
radioog=1;
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
radioog=2;
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void
on_gotogestionmenu_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Gestiondemenu;
GtkWidget *WELCOME;

Gestiondemenu=create_Gestiondemenu();
gtk_widget_show(Gestiondemenu);
WELCOME=lookup_widget(button,"WELCOME");
gtk_widget_hide(WELCOME);
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

void
on_button12_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *WELCOME;
GtkWidget *Gestiondemenu;

WELCOME=create_WELCOME();
gtk_widget_show(WELCOME);
Gestiondemenu=lookup_widget(button,"Gestiondemenu");
gtk_widget_hide(Gestiondemenu);
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

void
on_retourquiter_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *WELCOME;
GtkWidget *Quiter;

WELCOME=create_WELCOME();
gtk_widget_show(WELCOME);
Quiter=lookup_widget(button,"Quiter");
gtk_widget_hide(Quiter);
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

void
on_retourmeuilleur_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *WELCOME;
GtkWidget *meuilleur;

WELCOME=create_WELCOME();
gtk_widget_show(WELCOME);
meuilleur=lookup_widget(button,"meuilleur");
gtk_widget_hide(meuilleur);
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////








void
on_treeview_menu_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
fileload_menu();
GtkTreeIter iter;
	gchar* idog;
	gchar* repas;
	gchar* type;
	gint* jour;
	gint* mois;
	gint* annee;
	gfloat* qd;
        gchar* ds;
	menu m;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model,&iter,path))
	{
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0, &idog,1,&repas,2,&type,3,&jour,4,&mois ,5,&annee ,6,&qd,-1);
	strcpy(m.idog,idog);
	strcpy(m.repas,idog);
	strcpy(m.type,type);
	m.d.jour=*jour;
	m.d.mois=*mois;
	m.d.annee=*annee;
	m.qd=*qd;
	afficher_menu(treeview);
filesave_menu();
	}
}






