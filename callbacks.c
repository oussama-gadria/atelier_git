#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"

int radio=1;
int check=1;

void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}
void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *modifc, *x;
  modifc = create_modifc ();
  gtk_widget_show (modifc);
  x= lookup_widget(button,"ajoutc");
  gtk_widget_destroy(x);
}


void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *x,*y,*z,*a,*modifc,*e,*togglebutton123,*togglebutton321;
if(radio==1)
{
  exit(1);
  radio=2;
}
else if (radio==2)
{
  x= lookup_widget(button,"confirmation");
  gtk_widget_destroy(x);
  radio=1;

}
}




void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button7_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button8_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button9_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_ajout                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget * ajoutc;
	ajoutc = create_ajoutc ();
 	gtk_widget_show (ajoutc);

}


void
on_button_confirmer                    (GtkButton       *button,
                                        gpointer         user_data)
{
  char x[100];
fileload();


GtkWidget * club, * inc;

club = lookup_widget(button,"entry_id");
inc = lookup_widget(button,"label36");

strcpy(x, gtk_entry_get_text(GTK_ENTRY(club)));


if(isid(x)!=-1)
{
supprimer(x);
filesave();
gtk_label_set_text(GTK_LABEL(inc), "succes.");
}
else{
gtk_label_set_text(GTK_LABEL(inc), "utilisateur inexistant.");
}
}


void
on_button_modifier                     (GtkButton       *button,
                                        gpointer         user_data)
{

  GtkWidget * modifc;
  modifc = create_modifc ();
  gtk_widget_show (modifc);
}


void
on_button_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{

}



void
on_button_sortir0                      (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * modifc,*a;
  modifc = create_confirmation ();
  gtk_widget_show (modifc);

}


void
on_button_actualise                    (GtkButton       *button,
                                        gpointer         user_data)
{


}


void
on_button_aenre                        (GtkButton       *button,
                                        gpointer         user_data)
{
	club x;

	int i;
	char nome[20],id[20],nomb[20],even[20];
	GtkWidget * ajoutc;
	GtkWidget * nom, * ide, *nombre, * evenement, * error;
	nom=lookup_widget(button,"entry_anom");
 	ide=lookup_widget(button,"entry_aid");
	nombre=lookup_widget(button,"spinbutton1");
	evenement=lookup_widget(button,"spinbutton2");
	error=lookup_widget(button,"entry_error");
  char a[20],b[20];
  sprintf(a, "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nombre)));
  sprintf(b,"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(evenement)));

	strcpy(x.clubname, gtk_entry_get_text(GTK_ENTRY(nom)));
  strcpy(x.clubid, gtk_entry_get_text(GTK_ENTRY(ide)));
	strcpy(x.clubmembers, a);
	strcpy(x.eventnum, b);
	if( (isalphabet(x.clubname)==1)&&(isint(x.clubid)==1)&&(isint(x.eventnum)==1)&&(isint(x.clubmembers)==1)&&(isid(x.clubid)==-1)&&(nospace(x.eventnum)==1)&&(strlen(x.clubid)==4))
	{
  fileload();
	ajout(x);
	filesave();
	gtk_label_set_text(GTK_LABEL(error), "Ajout avec succes.");
	}
	else{
	gtk_label_set_text(GTK_LABEL(error), "verifier vos données.");
	}
}
void
on_button_asortir                      (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget * ajoutc;
	ajoutc=lookup_widget(button,"ajoutc");
	gtk_widget_destroy(ajoutc);
}
void
on_button_menre                        (GtkButton       *button,
                                        gpointer         user_data)
{
  club x;
  fileload();
  int i;
  char nome[20],id[20],nomb[20],even[20];
  GtkWidget * ajoutc;
  GtkWidget * nom, * ide, *nombre, * evenement, * error;
  nom=lookup_widget(button,"entry_mnom");
  ide=lookup_widget(button,"entry_mid");
  nombre=lookup_widget(button,"entry_mnombre");
  evenement=lookup_widget(button,"entry_meven");
  error=lookup_widget(button,"label37");

  strcpy(x.clubname, gtk_entry_get_text(GTK_ENTRY(nom)));
  strcpy(x.clubid, gtk_entry_get_text(GTK_ENTRY(ide)));
  strcpy(x.clubmembers, gtk_entry_get_text(GTK_ENTRY(nombre)));
  strcpy(x.eventnum, gtk_entry_get_text(GTK_ENTRY(evenement)));
  if( (isint(x.clubid)==1)&&(isint(x.eventnum)==1)&&(isint(x.clubmembers)==1)&&(isid(x.clubid)!=-1)&&(nospace(x.eventnum)==1)&&(strlen(x.clubid)==4))
  {
  modifier(x);
  filesave();
  gtk_label_set_text(GTK_LABEL(error), "Modification avec succe.");

  }
  else{
  gtk_label_set_text(GTK_LABEL(error), "verifier vos données.");
  }
  if (check==0)
  {GtkWidget * modifc;
   modifc=lookup_widget(button,"modifc");
   gtk_widget_destroy(modifc);}
}


void
on_button_msortir                      (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget * modifc;
	modifc=lookup_widget(button,"modifc");
	gtk_widget_destroy(modifc);
}

void
on_button_list_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * aff;
  aff=lookup_widget(button,"treeview1");
  listclr(aff);
  afficherc(aff);
}

void
retour_menumodif1                      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button1_retour1                     (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * clubc, *x;
  clubc = create_clubs0 ();
  gtk_widget_show (clubc);
  x= lookup_widget(button,"ajoutc");
  gtk_widget_destroy(x);

}


void
on_button2_ajout                       (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *modifc, *x;
 modifc = create_ajoutc ();
 gtk_widget_show (modifc);
 x= lookup_widget(button,"modifc");
 gtk_widget_destroy(x);
}

void
on_retour_menuclub2_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * clubc, *x;
  clubc = create_clubs0 ();
  gtk_widget_show (clubc);
  x= lookup_widget(button,"modifc");
  gtk_widget_destroy(x);
}

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
}

void
on_button5_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
  fileload();
    int i;
    char clubname[30];
    GtkWidget *liste, *user;
    user=lookup_widget(button,"entry123");
    liste=lookup_widget(button,"treeview1");
    strcpy(clubname, gtk_entry_get_text(GTK_ENTRY(user)));
    i=isid(clubname);
    if(i!=-1){
      viderliste(liste);
      afftrouver(liste, i);
    }
    else{
      viderliste(liste);
    }
}




void
on_button_click_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

  fileload();
    club y;
  char h[100];
  GtkWidget *x,*comboboxentry1,*objet_graphique;
  comboboxentry1=lookup_widget(button,"comboboxentry1");
  strcpy(h,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry1)));
  if (strcmp(h,"Par nombre des etudiants ")==0)
  {
  x = lookup_widget(button,"label_actif");
  y=getactiveclub();
  gtk_label_set_text(GTK_LABEL(x), y.clubname );
}
else if (strcmp(h,"Par evenement")==0)
{
x = lookup_widget(button,"label_actif");
y=getactivecluba();
gtk_label_set_text(GTK_LABEL(x), y.clubname);}
}

void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
check=0;
}
void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
check=1;
}

void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
}

void
on_radiobutton123_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  {radio=2;}


}


void
on_radiobutton321_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  {radio=1;}
}

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
  GtkWidget *val, *supp,*low,*entry_mid;
  GtkTreeIter iter;
  gchar *clubname,*clubid,*clubmembers,*eventnum;
  GtkTreeModel *model= gtk_tree_view_get_model(treeview);
  char x[100];

  if(gtk_tree_model_get_iter(model, &iter, path)){

    gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&clubname,1, &clubid,2, &clubmembers,3,&eventnum,-1);
    strcpy(x,clubid);}
    low=create_modifc();
    gtk_widget_show(low);
    supp=lookup_widget(treeview,"entry_id");
    entry_mid=lookup_widget(low,"entry_mid");
    gtk_entry_set_text(GTK_LABEL(entry_mid),x);
    gtk_entry_set_text(GTK_LABEL(supp),x);

}
