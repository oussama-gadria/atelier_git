#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "reclamation.h"
#include <string.h>
#include <stdio.h>

int radio_rec=1;
int trec[2]={0,0};


void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
}

void
on_recfinal_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *rec, *jour,*mois,*annee;

  reclamation x[5000];
  date y;
  int k=0,i,foyer=0,tech=0,rest=0;
  FILE *f=NULL;
  f=fopen("reclamation.txt","r+");
  while(fscanf(f,"%d %d %d %s %s %s %s\n",&x[k].date.jour,&x[k].date.mois,&x[k].date.annee,x[k].nom,x[k].id,x[k].categorie,x[k].description)
    !=EOF)
 {
      k++;
  }
  fclose(f);
  rec = lookup_widget(button,"affres");
  jour=lookup_widget(button,"recjour");
  mois=lookup_widget(button,"recmois");
  annee=lookup_widget(button,"recannee");

  y.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
  y.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
  y.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

 
  for(i=0;i<k;i++){
    
    if(datecmp_rec(x[i].date,y)==1){
      if(strcmp(x[i].categorie,"Foyer")==0)
      foyer++;
      else
      if(strcmp(x[i].categorie,"Technique")==0)
      tech++;
      else
      if(strcmp(x[i].categorie,"Restaurant")==0)
      rest++;
    }

    }
    if ((foyer==0)&&(rest==0)&&(tech==0))
{ gtk_label_set_text(GTK_LABEL(rec), "Aucun service réclamé depuis cette date");}
else
{
    if(radio_rec==1){
    if((foyer>tech)&&(foyer>rest))
    gtk_label_set_text(GTK_LABEL(rec), "Le service le plus reclamé est:\n Foyer.");
    else
    if((tech>foyer)&&(tech>rest))
    gtk_label_set_text(GTK_LABEL(rec), "Le service le plus reclamé est:\n Technique.");
    else
    if((rest>=foyer)&&(rest>=tech))
    gtk_label_set_text(GTK_LABEL(rec), "Le service le plus reclamé est:\n Restaurant.");
    }
    if(radio_rec==2){
    if(!((foyer>tech)&&(foyer>rest)))
    gtk_label_set_text(GTK_LABEL(rec), "Le service le moins reclamé est:\n Foyer.");
    else
    if(!((tech>foyer)&&(tech>rest)))
    gtk_label_set_text(GTK_LABEL(rec), "Le service le moins reclamé est:\n Technique.");
    else
    if(!((rest>=foyer)&&(rest>=tech)))
    gtk_label_set_text(GTK_LABEL(rec), "Le service le moins reclamé est:\n Restaurant.");
    }
}
}


void
on_button_ordre_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x;
  x=create_recordre();
  gtk_widget_show(x);
  radio_rec=1;
}


void
on_button_save1_rec_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
reclamation x;
fileload_rec();


GtkWidget * nom, * id, * description, * categorie, * jour, * mois , * annee , * inc;


nom = lookup_widget(button,"entry_nom_rec");
id = lookup_widget(button,"entry_id_rec");
description = lookup_widget(button,"entry_desc_rec");
categorie = lookup_widget(button,"comboboxentry1_rec");
inc = lookup_widget(button,"label_mess");
jour=lookup_widget(button,"spin_jour_rec");
mois=lookup_widget(button,"spin_mois_rec");
annee=lookup_widget(button,"spin_annee_rec");

strcpy(x.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(x.id, gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(x.description, gtk_entry_get_text(GTK_ENTRY(description)));
strcpy(x.categorie, gtk_combo_box_get_active_text(GTK_COMBO_BOX(categorie)));
x.date.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
x.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
x.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

if( (isalphabet_rec(x.nom)==1)&&(isid_rec(x.id)==-1)&&(nospace_rec(x.id)==1)&&(nospace_rec(x.nom)==1))
{
ajout_rec(x);
filesave_rec();
gtk_label_set_text(GTK_LABEL(inc), "ajout avec succès.");
}
else
{
gtk_label_set_text(GTK_LABEL(inc), "Vérifier vos données.");
}
}


void
on_button_retoura_rec_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget * rectab;
	rectab = create_rectab ();
 	gtk_widget_show (rectab);
}


void
on_button_save2_rec_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
reclamation x;
fileload_rec();


GtkWidget * nom, * id, * categorie, * description, * inc , *jour , *mois , *annee ;


nom = lookup_widget(button,"entry_nomdeja_rec");
id = lookup_widget(button,"entry_identif_rec");
description = lookup_widget(button,"nouvdesc_rec");
categorie = lookup_widget(button,"comboboxentry2_rec");
inc = lookup_widget(button,"label16");
jour=lookup_widget(button,"spin_jour1_rec");
mois=lookup_widget(button,"spin_mois1_rec");
annee=lookup_widget(button,"spin_annee1_rec");

strcpy(x.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(x.id, gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(x.description, gtk_entry_get_text(GTK_ENTRY(description)));
strcpy(x.categorie, gtk_combo_box_get_active_text(GTK_COMBO_BOX(categorie)));
x.date.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
x.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
x.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));


if( (isalphabet_rec(x.nom)==1)&&(isid_rec(x.id)!=-1)&&(nospace_rec(x.id)==1)&&(nospace_rec(x.nom)==1))
{
modifier_rec(x);
filesave_rec();
gtk_label_set_text(GTK_LABEL(inc), "Modification effectuée avec succès.");
}
else
{
gtk_label_set_text(GTK_LABEL(inc), "Vérifier vos données.");
}

}


void
on_button_retour2_rec_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget * rectab;
	rectab = create_rectab ();
 	gtk_widget_show (rectab);
}


void
on_button10_rec_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
char x[100];
fileload_rec();


GtkWidget * id, * errorsupp, * inc;

id = lookup_widget(button,"entry_idasupp_rec");
inc = lookup_widget(button,"label_res");

strcpy(x, gtk_entry_get_text(GTK_ENTRY(id)));



if(isid_rec(x)!=-1)
{
supprimer_rec(x);

filesave_rec();
gtk_label_set_text(GTK_LABEL(inc), "succès");
}
else
{
gtk_label_set_text(GTK_LABEL(inc), "utilisateur inexistant.");
}

}


void
on_button_retour_supp_rec_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget * rectab;
	rectab = create_rectab ();
 	gtk_widget_show (rectab);  
}


void
on_radiobutton2_rec_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
radio_rec=1;
}


void
on_radiobutton3_rec_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
radio_rec=2;
}


void
on_button_affiche_rec_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
fileload_rec();
GtkWidget * aff;
  aff=lookup_widget(button,"treeview1_rec");
  afficher_rec(aff);
}


void
on_button_recherche_rec_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
fileload_rec();
  int i;
  char sid[30];
  GtkWidget *liste, *id;
  id=lookup_widget(button,"gettrouver_rec");
  liste=lookup_widget(button,"treeview1_rec");
  strcpy(sid, gtk_entry_get_text(GTK_ENTRY(id)));

  i=isid_rec(sid);
  if(i!=-1)
  {
    viderliste_rec(liste);
    rechercher_rec(liste, i);
  }
  else
  {
    viderliste_rec(liste);
  }
}


void
on_button_ajout_rec_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * ajoutrec;
  ajoutrec = create_ajoutrec ();
  gtk_widget_show (ajoutrec);  
}


void
on_button_modif_rec_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * modif_rec;
  modif_rec = create_modif_rec ();
  gtk_widget_show (modif_rec); 
}


void
on_button_rec_supression_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * supression;
  supression = create_supression ();
  gtk_widget_show (supression);

}


void
on_buttonorderrec_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x;
  x=create_recordre();
  gtk_widget_show(x);
  radio_rec=1;

}


void
on_button1_rec_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * inc;
inc = lookup_widget(button,"label_incc");
if (trec[0]==1)
{
gtk_label_set_text(GTK_LABEL(inc), "Cliquez sur bouton ***Voir*** à droite de la page ");
}
if (trec[1]==1)
{
gtk_label_set_text(GTK_LABEL(inc), "D'accord");
}
}


void
on_checkbutton2_rec_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
trec[1]=1;
}


void
on_checkbutton1_rec_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
trec[0]=1;
}

