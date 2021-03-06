#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "admin.h"
#include "clubs.h"
#include "capteur.h"
#include <string.h>
#include <stdio.h>

int radio=1,token=1;
users w;
GtkTreeView *L;
char x[100];
int check=1;
int radiox=1;
int r=0;
GtkTreeView *treec;
void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_logconnect_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * user, *pw, *auth, *afflist, *error, *aff;
  GtkWidget *clubs0;
  char suser[30], spw[30];
  users s;
  int i;
  fileload();

  user=lookup_widget(button,"authuser");
  pw=lookup_widget(button,"authpw");
  auth=lookup_widget(button,"Authentification");
  error=lookup_widget(button,"logerror");

  strcpy(suser, gtk_entry_get_text(GTK_ENTRY(user)));
  strcpy(spw, gtk_entry_get_text(GTK_ENTRY(pw)));
  i=isid(suser);
  if((strcmp(suser,"a")==0)&&(strcmp(spw,"a")==0))
  {
    afflist = create_Espace_d_administrateur ();
    gtk_widget_show (afflist);
    gtk_widget_destroy(auth);

    aff=lookup_widget(afflist,"liste");
    afficher(aff);
    L=aff;
  }
  else if(checkauth(spw,i)==1){
    s=getuser(i);
    if(strcmp(s.role,"Admin")==0)
    {
      afflist = create_Espace_d_administrateur ();
      gtk_widget_show (afflist);
      gtk_widget_destroy(auth);
      aff=lookup_widget(afflist,"liste");
      afficher(aff);
    }
    else
    if(strcmp(s.role,"Gestion_des_clubs")==0)
    {

      clubs0 = create_clubs0 ();
      gtk_widget_show (clubs0);
    }
    if(strcmp(s.role,"Technicien")==0)
    {

      clubs0 = create_Espace_technicien ();
      gtk_widget_show (clubs0);
    }


  }
  else{
    gtk_label_set_text(GTK_LABEL(error), "verifier vos données.");



  }
}


void
on_gotoinsc_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x,*y;
  y=create_Inscription();
  gtk_widget_show(y);
  x= lookup_widget(button,"Authentification");
  gtk_widget_destroy(x);
}


void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

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
on_checkbutton1_activate               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_inscvalider_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

users x;
fileload();


GtkWidget * nom, * prenom, * user, * pw, * role, * inc;


nom = lookup_widget(button,"inscnom");
prenom = lookup_widget(button,"inscprenom");
user = lookup_widget(button,"inscuser");
pw = lookup_widget(button,"inscpw");
role = lookup_widget(button,"inscrole");
inc = lookup_widget(button,"inscerror");

strcpy(x.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(x.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(x.user, gtk_entry_get_text(GTK_ENTRY(user)));
strcpy(x.pw, gtk_entry_get_text(GTK_ENTRY(pw)));
strcpy(x.role, gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)));



if( (isalphabet(x.nom)==1)&&(isalphabet(x.prenom)==1)&&(isid(x.user)==-1)&&(nospace(x.user)==1)&&(nospace(x.pw)==1)){
ajout(x,0);
filesave();
gtk_label_set_text(GTK_LABEL(inc), "inscription avec succes.");
}
else{
gtk_label_set_text(GTK_LABEL(inc), "Verifier vos données.");
}
}


void
on_gotomodif_clicked                   (GtkButton     *button,
                                        gpointer         user_data)
{
  GtkWidget *y;
  y= create_modifier ();
  gtk_widget_show(y);
}


void
on_afftrouver_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_modifvalider_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
users x;
fileload();


GtkWidget * nom, * prenom, * user, * pw, * role, * inc,*modif;


nom = lookup_widget(button,"modifnom");
prenom = lookup_widget(button,"modifprenom");
pw = lookup_widget(button,"modifpw");
role = lookup_widget(button,"modifrole");
inc = lookup_widget(button,"modiferror");
user=lookup_widget(button,"modifuser");

strcpy(x.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(x.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(x.user, gtk_entry_get_text(GTK_ENTRY(user)));
strcpy(x.pw, gtk_entry_get_text(GTK_ENTRY(pw)));
strcpy(x.role, gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)));



if( (isalphabet(x.nom)==1)&&(isalphabet(x.prenom)==1)&&(isid(x.user)!=-1)&&(nospace(x.user)==1)&&(nospace(x.pw)==1)){
modifier(x);
filesave();
gtk_label_set_text(GTK_LABEL(inc), "Modification affectuer avec succes.");
modif=lookup_widget(button,"modifier");
gtk_widget_destroy(modif);
afficher(L);
}
else{
gtk_label_set_text(GTK_LABEL(inc), "Verifier vos données.");
}
}

void
on_rec_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x;
  x=create_services();
  gtk_widget_show(x);
  radio=1;
}


void
on_actualiser_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
  fileload();
 GtkWidget *liste;
 liste= lookup_widget(button,"liste");
 viderliste(liste);
 afficher(liste);

}


void
on_deconnexion_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *auth, *afflist;

  auth = create_Authentification ();
  afflist = lookup_widget(button,"Espace_d_administrateur");

  gtk_widget_show (auth);
  gtk_widget_destroy(afflist);
}

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
radio=1;

}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
radio=2;
}

void
on_recaffiche_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *affrec, *jour,*mois,*annee;

  rec x[5000];
  date y;
  int k=0,i,foyer=0,tech=0,rest=0;
  FILE *f=NULL;
  f=fopen("reclamations.txt","r+");
  while(fscanf(f,"%s %d %d %d %s\n",x[k].service,&x[k].date.jour,&x[k].date.mois,&x[k].date.annee,x[k].commentaire)!=EOF){
      k++;
  }
  fclose(f);
  affrec = lookup_widget(button,"affservice");
  jour=lookup_widget(button,"recjour");
  mois=lookup_widget(button,"recmois");
  annee=lookup_widget(button,"recannee");

  y.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
  y.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
  y.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));


  for(i=0;i<k;i++){
    if(datecmp(x[i].date,y)==1){
      if(strcmp(x[i].service,"Agent_du_foyer")==0)
      foyer++;
      else
      if(strcmp(x[i].service,"Technicien")==0)
      tech++;
      else
      if(strcmp(x[i].service,"Agent_du_restaurent")==0)
      rest++;
    }
    if(radio==1){
    if((foyer>tech)&&(foyer>rest))
    gtk_label_set_text(GTK_LABEL(affrec), "La service la plus reclamee est:\n Agents du foyer.");
    else
    if((tech>foyer)&&(tech>rest))
    gtk_label_set_text(GTK_LABEL(affrec), "La service la plus reclamee est:\n Techniciens.");
    else
    if((rest>=foyer)&&(rest>=tech))
    gtk_label_set_text(GTK_LABEL(affrec), "La service la plus reclamee est:\n Service restauration.");
    }
    if(radio==2){
    if(!((foyer>tech)&&(foyer>rest)))
    gtk_label_set_text(GTK_LABEL(affrec), "La service la plus reclamee est:\n Agents du foyer.");
    else
    if(!((tech>foyer)&&(tech>rest)))
    gtk_label_set_text(GTK_LABEL(affrec), "La service la plus reclamee est:\n Techniciens.");
    else
    if(!((rest>=foyer)&&(rest>=tech)))
    gtk_label_set_text(GTK_LABEL(affrec), "La service la plus reclamee est:\n Service restauration.");
    }




  }



}

void
on_insctoauth_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *y, *x;
    y = create_Authentification ();
    gtk_widget_show (y);
    x= lookup_widget(button,"Inscription");
    gtk_widget_destroy(x);
}


void
on_gotomain_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x;
  x= lookup_widget(button,"modifier");
  gtk_widget_destroy(x);


  viderliste(L);
  afficher(L);

}

void
on_liste_row_activated                 (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
  GtkWidget *val, *supp,*op,*valider;
  GtkTreeIter iter;
  gchar *nom,*prenom,*user,*role,*valid;
  GtkTreeModel *model= gtk_tree_view_get_model(treeview);


  if(gtk_tree_model_get_iter(model, &iter, path)){
    gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0, &nom,1, &prenom,2,&user,3,&role,4,&valid,-1);
    strcpy(w.nom,nom);
    strcpy(w.prenom,prenom);
    strcpy(w.user,user);
    strcpy(w.role,role);
    strcpy(w.valid,valid);
    op=create_options();
    gtk_widget_show(op);
    valider=lookup_widget(op,"opvalid");
    if(strcmp(w.valid,"valide")==0)
    gtk_button_set_label(GTK_BUTTON(valider), "invalider");
    else if(strcmp(w.valid,"nonvalide")==0)
    gtk_button_set_label(GTK_BUTTON(valider), "valider");
  }

L=treeview;
val=lookup_widget(treeview,"affvaliduser");
supp=lookup_widget(treeview,"affsupprimeruser");

gtk_entry_set_text(GTK_LABEL(val),w.user);
gtk_entry_set_text(GTK_LABEL(supp),w.user);




}

void
on_capteures_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *afflist;
  GtkTextView *aff;
  afflist=create_captdef();
  gtk_widget_show(afflist);
  aff=lookup_widget(afflist,"textview1");

  int flagid[5000];
   capteur2 T[5000];
   int n=0,k=0,i;
   char msg[1000],temp[100];
   FILE *f=NULL;
   f=fopen("temperature.txt","r+");
   if(f==NULL){printf("error reading file\n");}
   while(fscanf(f,"%d %d %d %f\n",&T[n].jour,&T[n].heure,&T[n].id,&T[n].val)!=EOF){
       n++;
   }
   fclose(f);
strcpy(msg,"\n");
  for(i=0;i<n;i++)
 {

     if((T[i].val<10)||(T[i].val>30))
     {

         if(isnotflagged(T[i].id,flagid,k))
         {

             sprintf(temp,"le capteur avec ID: %d est défectueux.\n",T[i].id);
             strcat(msg,temp);
             flagid[k]=T[i].id;
             k++;
         }
     }
 }
 GtkTextBuffer *buff;

buff=gtk_text_view_get_buffer(GTK_TEXT_VIEW(aff));
gtk_text_buffer_set_text(buff,msg,-1);





}

void
on_opmodif_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x,*y,*z;
  y= create_modifier ();
  gtk_widget_show(y);
  x= lookup_widget(button,"options");
  gtk_widget_destroy(x);
  z=lookup_widget(y,"modifuser");
  gtk_entry_set_text(z,w.user);

}


void
on_opsupp_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
  fileload();
  supprimer(w.user);
  GtkWidget *x;
  x= lookup_widget(button,"options");
  gtk_widget_destroy(x);
  afficher(L);
  filesave();
}


void
on_opvalid_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{fileload();

if(strcmp(w.valid,"nonvalide")==0){
  setvalide(isid(w.user),1);
}else
if(strcmp(w.valid,"valide")==0){
  setvalide(isid(w.user),0);
}
filesave();
GtkWidget *x,*aff;
x= lookup_widget(button,"options");
gtk_widget_destroy(x);
aff=lookup_widget(L,"liste");
afficher(aff);
}

void
on_ajoutvalider_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
  users x;
  fileload();

  int i=0;
  GtkWidget * nom, * prenom, * user, * pw, * role, * inc,*check;


  nom = lookup_widget(button,"ajoutnom");
  prenom = lookup_widget(button,"ajoutprenom");
  user = lookup_widget(button,"ajoutuser");
  pw = lookup_widget(button,"ajoutpw");
  role = lookup_widget(button,"ajoutrole");
  inc = lookup_widget(button,"ajouterror");
  check=lookup_widget(button,"ajoutval");
  strcpy(x.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
  strcpy(x.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
  strcpy(x.user, gtk_entry_get_text(GTK_ENTRY(user)));
  strcpy(x.pw, gtk_entry_get_text(GTK_ENTRY(pw)));
  strcpy(x.role, gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)));

  if(gtk_toggle_button_get_active(check))i=1;

  if( (isalphabet(x.nom)==1)&&(isalphabet(x.prenom)==1)&&(isid(x.user)==-1)&&(nospace(x.user)==1)&&(nospace(x.pw)==1)){
  ajout(x,i);
  filesave();
  gtk_label_set_text(GTK_LABEL(inc), "ajout avec succes.");
  }
  else{
  gtk_label_set_text(GTK_LABEL(inc), "Verifier vos données.");
  }
}

void
on_affajouter_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x;
  x=create_Ajout ();
  gtk_widget_show(x);
}

void
on_gettrouver_changed                  (GtkEditable     *editable,
                                        gpointer         user_data)
{

  fileload();

  char suser[30];
  GtkWidget *liste, *user, *crtr;
  user=lookup_widget(editable,"gettrouver");
  liste=lookup_widget(editable,"liste");
  crtr=lookup_widget(editable,"searchtype");
  strcpy(suser, gtk_entry_get_text(GTK_ENTRY(user)));



  viderliste(liste);
  afftrouver(liste, suser,gtk_combo_box_get_active_text(GTK_COMBO_BOX(crtr)));

}

void
on_affmodif_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *y;
    y= create_modifier ();
    gtk_widget_show(y);
}


void
on_checkvalid_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_affsupprimer_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
  char x[100];
  fileload();


  GtkWidget * user, * errorsupp, * inc;

  user = lookup_widget(button,"affsupprimeruser");
  inc = lookup_widget(button,"affsupperror");

  strcpy(x, gtk_entry_get_text(GTK_ENTRY(user)));



  if(isid(x)!=-1){
  supprimer(x);

  filesave();
  gtk_label_set_text(GTK_LABEL(inc), "succes.");
  }
  else{
  gtk_label_set_text(GTK_LABEL(inc), "utilisateur inexistant.");
  }
}

void
on_affvalider_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

  int i;
  char x[100];
  fileload();

  GtkWidget * user, * errorsupp, * inc, * check;

  user = lookup_widget(button,"affvaliduser");
  check = lookup_widget(button,"checkvalid");
  inc = lookup_widget(button,"affvaliderror");

  strcpy(x, gtk_entry_get_text(GTK_ENTRY(user)));


  i=isid(x);
  if(i!=-1){
  	if(gtk_toggle_button_get_active(check)){

  		setvalide(i,1);
  	}
  	else{

  		setvalide(i,0);
  	}
  	filesave();
  	gtk_label_set_text(GTK_LABEL(inc), "succes.");
  }
  else{
  	gtk_label_set_text(GTK_LABEL(inc), "utilisateur inexistant.");
  }
}

///////////////////////////////////////////////PARTIE CLUBS /////////////////////////////////////////////////////////////////////////////////////

void
on_treeview1_row_activated_clubs       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
  GtkWidget *val, *supp,*low,*entry_mid;
  GtkTreeIter iter;
  gchar *clubname,*clubid,*clubmembers,*eventnum;
  GtkTreeModel *model= gtk_tree_view_get_model(treeview);

  if(gtk_tree_model_get_iter(model, &iter, path)){

    gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&clubname,1, &clubid,2, &clubmembers,3,&eventnum,-1);
    strcpy(x,clubid);}
    low=create_options_clubs();
    gtk_widget_show(low);
    supp=lookup_widget(treeview,"entry124");
    gtk_entry_set_text(GTK_LABEL(supp),x);
}


void
on_button10_clicked_clubs              (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * ajoutc;
  ajoutc = create_ajoutc ();
  gtk_widget_show (ajoutc);
}


void
on_button11_clicked_clubs              (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * ajoutc;
 ajoutc = create_modifc ();
 gtk_widget_show (ajoutc);

}


void
on_button12_clicked_clubs              (GtkButton       *button,
                                        gpointer         user_data)
{
  char x[100];
  fileload_clubs();


  GtkWidget * club, * inc,*error;

  club = lookup_widget(button,"entry124");
  inc = lookup_widget(button,"label36");

  strcpy(x, gtk_entry_get_text(GTK_ENTRY(club)));


  if(isid_clubs(x)!=-1)
  {
  supprimer_clubs(x);
  filesave_clubs();
  GtkWidget * low;
  low=create_message();
  gtk_widget_show(low);
  error=lookup_widget(low,"label51");
  gtk_label_set_text(GTK_LABEL(error), "succes.");
  listclr_clubs(treec);
  afficherc_clubs(treec);
  }
  else{
    GtkWidget * low;
    low=create_message();
    gtk_widget_show(low);
    error=lookup_widget(low,"label51");
  gtk_label_set_text(GTK_LABEL(error), "utilisateur inexistant.");
}
}


void
on_button13_clicked_clubs              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_click_clicked_clubs          (GtkButton       *button,
                                        gpointer         user_data)
{
  fileload_clubs();
    club y;
  char h[100];
  GtkWidget *x,*comboboxentry1,*objet_graphique;
  comboboxentry1=lookup_widget(button,"comboboxentry1");
  strcpy(h,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry1)));
  if (strcmp(h,"Par nombre des etudiants ")==0)
  {
  x = lookup_widget(button,"label_actif");
  y=getactiveclub_clubs();
  gtk_label_set_text(GTK_LABEL(x), y.clubname );
  }
  else if (strcmp(h,"Par evenement")==0)
  {
  x = lookup_widget(button,"label_actif");
  y=getactivecluba_clubs();
  gtk_label_set_text(GTK_LABEL(x), y.clubname);}
  }

  void
  on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
  {
  check=0;
}


void
on_button5_clicked_clubs               (GtkButton       *button,
                                        gpointer         user_data)
{
  fileload_clubs();
    int i;
    char clubname[30];
    GtkWidget *liste, *user;
    user=lookup_widget(button,"entry123");
    liste=lookup_widget(button,"treeview1");
    strcpy(clubname, gtk_entry_get_text(GTK_ENTRY(user)));
    i=isid_clubs(clubname);
    if(i!=-1){
      viderliste_clubs(liste);
      afftrouver_clubs(liste, i);
    }
    else{
      viderliste_clubs(liste);
    }
}


void
on_checkbutton1_toggled_clubs          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
check=1;
}


void
on_checkbutton2_toggled_clubs          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
check=0;
}


void
on_retour_menuclub2_clicked_clubs      (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * clubc, *x;
  clubc = create_clubs0 ();
  gtk_widget_show (clubc);
  x= lookup_widget(button,"modifc");
  gtk_widget_destroy(x);
}


void
on_button2_ajout_clubs                 (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *modifc, *x;
  modifc = create_ajoutc ();
  gtk_widget_show (modifc);
  x= lookup_widget(button,"modifc");
  gtk_widget_destroy(x);
}


void
on_button_menre_clubs                  (GtkButton       *button,
                                        gpointer         user_data)
{
  club y;
  fileload_clubs();
  int i;
  char nome[20],id[20],nomb[20],even[20];
  GtkWidget * ajoutc;
  GtkWidget * nom, * ide, *nombre, * evenement, * error,*entry_mid,*modifc,*label51;


  nom=lookup_widget(button,"entry_mnombre");
  ide=lookup_widget(button,"entry_mid");
  nombre=lookup_widget(button,"entry_mnom");
  evenement=lookup_widget(button,"entry_meven");
  error=lookup_widget(button,"label37");

  strcpy(y.clubname, gtk_entry_get_text(GTK_ENTRY(nom)));
  strcpy(y.clubid, gtk_entry_get_text(GTK_ENTRY(ide)));
  strcpy(y.clubmembers, gtk_entry_get_text(GTK_ENTRY(nombre)));
  strcpy(y.eventnum, gtk_entry_get_text(GTK_ENTRY(evenement)));
  if( (isalphabet_clubs(y.clubname)==1)&&(isint_clubs(y.clubid)==1)&&(isint_clubs(y.eventnum)==1)&&(isint_clubs(y.clubmembers)==1)&&(isid_clubs(y.clubid)!=-1)&&(nospace(y.eventnum)==1)&&(strlen(y.clubid)==4))
  {
  modifier_clubs(y);
  filesave_clubs();
  GtkWidget * low;
  low=create_message();
  gtk_widget_show(low);
  error=lookup_widget(low,"label51");
  gtk_label_set_text(GTK_LABEL(error), "Modification avec succee.");
  listclr_clubs(treec);
  afficherc_clubs(treec);

  }
  else{
    GtkWidget * low;
    low=create_message();
    gtk_widget_show(low);
    error=lookup_widget(low,"label51");
    gtk_label_set_text(GTK_LABEL(error), "verifier vos données.");
  }
  if (check==0)
  {GtkWidget * modifc;
   modifc=lookup_widget(button,"modifc");
   gtk_widget_destroy(modifc);}
}


void
on_button_asortir_clubs                (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * ajoutc;
  ajoutc=lookup_widget(button,"ajoutc");
  gtk_widget_destroy(ajoutc);
}


void
on_button1_retour1_clubs               (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * clubc, *x;
  clubc = create_clubs0 ();
  gtk_widget_show (clubc);
  x= lookup_widget(button,"ajoutc");
  gtk_widget_destroy(x);
}


void
on_button3_clicked_clubs               (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *modifc, *x;
  modifc = create_modifc ();
  gtk_widget_show (modifc);
  x= lookup_widget(button,"ajoutc");
  gtk_widget_destroy(x);
}


void
on_button_aenre_clubs                  (GtkButton       *button,
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

  char a[20],b[20];
  sprintf(a, "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nombre)));
  sprintf(b,"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(evenement)));

  strcpy(x.clubname, gtk_entry_get_text(GTK_ENTRY(nom)));
  strcpy(x.clubid, gtk_entry_get_text(GTK_ENTRY(ide)));
  strcpy(x.clubmembers, a);
  strcpy(x.eventnum, b);
  if( (isalphabet_clubs(x.clubname)==1)&&(isint_clubs(x.clubid)==1)&&(isint_clubs(x.eventnum)==1)&&(isint_clubs(x.clubmembers)==1)&&(isid_clubs(x.clubid)==-1)&&(nospace(x.eventnum)==1)&&(strlen(x.clubid)==4))
  {
  fileload_clubs();
  ajout_clubs(x);
  filesave_clubs();
  GtkWidget * low;
  low=create_message();
  gtk_widget_show(low);
  error=lookup_widget(low,"label51");
  gtk_label_set_text(GTK_LABEL(error),"Ajout avec succes.");
  listclr_clubs(treec);
  afficherc_clubs(treec);
  }
  else{
    GtkWidget * low;
    low=create_message();
    gtk_widget_show(low);
    error=lookup_widget(low,"label51");
  gtk_label_set_text(GTK_LABEL(error), "verifier vos données.");
  }
}


void
on_radiobutton321_toggled_clubs        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  {radio=1;}
}


void
on_radiobutton123_toggled_clubs        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  {radio=2;}
}


void
on_button4_clicked_clubs               (GtkButton       *button,
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
on_button7_clicked_clubs               (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * modifc,*entry_mid,*low;
  low=create_modifc();
  gtk_widget_show(low);
  entry_mid=lookup_widget(low,"entry_mid");
  gtk_entry_set_text(GTK_LABEL(entry_mid),x);
}


void
on_button8_clicked_clubs               (GtkButton       *button,
                                        gpointer         user_data)
{
  char y[100];
  fileload_clubs();


  GtkWidget * club, * inc,*error;
  GtkWidget * low;


  strcpy(y, x);
  if(isid_clubs(x)!=-1)
  {
  supprimer_clubs(y);
  filesave_clubs();
  GtkWidget * low;
  low=create_message();
  gtk_widget_show(low);
  error=lookup_widget(low,"label51");
  gtk_label_set_text(GTK_LABEL(error),"succes");
  listclr_clubs(treec);
  afficherc_clubs(treec);

  }
  else{
    GtkWidget * low,*a;
    low=create_message();
    gtk_widget_show(low);
    error=lookup_widget(low,"label51");
  gtk_label_set_text(GTK_LABEL(error), "utilisateur inexistant.");
  a= lookup_widget(button,"clubs0");
  gtk_widget_destroy(a);
  }
}


void
on_button99_clicked_clubs              (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x;
  x= lookup_widget(button,"options");
  gtk_widget_destroy(x);
}

void
on_entry123_changed_clubs              (GtkEditable     *editable,
                                        gpointer         user_data)
{
  fileload_clubs();
  int i;
  char clubname[30];
  GtkWidget *liste;
  liste=lookup_widget(editable,"treeview1");
  strcpy(clubname, gtk_entry_get_text(GTK_ENTRY(editable)));
  i=isid_clubs(clubname);
  if(1){
    viderliste_clubs(liste);
    afftrouver_clubs(liste,clubname);
  }
  else{
    viderliste_clubs(liste);
  }
}

void
on_button_sortir0_clubs                (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * modifc,*a;
  modifc = create_confirmation ();
  gtk_widget_show (modifc);
}

void
on_button_list_clicked_clubs           (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkTreeView *aff;
  aff=lookup_widget(button,"treeview1");
  treec=aff;
  listclr_clubs(treec);
  afficherc_clubs(treec);
}

void
on_button_msortir_clubs                (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * modifc;
  modifc=lookup_widget(button,"modifc");
  gtk_widget_destroy(modifc);
}
///////////////////////////////////////////////PARTIE CAPTEURS /////////////////////////////////////////////////////////////////////////////////////






void
on_gotoajoutercapt_clicked_capteur     (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_Ajouter_un_capteur();
  gtk_widget_show(x);
  a= lookup_widget(button,"Espace_technicien");
  gtk_widget_destroy(a);
}


void
on_liste_row_activated_capteur         (GtkTreeView     *treeview,
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
on_afftouver_clicked_capteur           (GtkButton       *button,
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
on_gotomodifiercapteur_clicked_capteur (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_modifier_un_capteur();
  gtk_widget_show(x);
  a= lookup_widget(button,"Espace_technicien");
  gtk_widget_destroy(a);
}


void
on_affsupprimer_clicked_capteur        (GtkButton       *button,
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
on_afficher_clicked_capteur            (GtkButton       *button,
                                        gpointer         user_data)
{
fileload_capteur();
GtkWidget *liste;
liste=lookup_widget(button,"liste");
afficher_capteur(liste);
}


void
on_gotoalarme_clicked_capteur          (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_afficher_alarme();
  gtk_widget_show(x);
  a= lookup_widget(button,"Espace_technicien");
  gtk_widget_destroy(a);
}


void
on_buttonsortie_clicked_capteur        (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x;
  x=create_confirmation_capteur ();
  gtk_widget_show(x);
}


void
on_ajoutervalider_clicked_capteur      (GtkButton       *button,
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
on_buttonacc1_clicked_capteur          (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_Espace_technicien ();
  gtk_widget_show(x);
  a= lookup_widget(button,"Ajouter_un_capteur");
  gtk_widget_destroy(a);
}


void
on_modifvalider_clicked_capteur        (GtkButton       *button,
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
on_buttonacc2_clicked_capteur          (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_Espace_technicien ();
  gtk_widget_show(x);
  a= lookup_widget(button,"modifier_un_capteur");
  gtk_widget_destroy(a);
}


void
on_afficheralarme_clicked_capteur      (GtkButton       *button,
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
on_buttonacc3_clicked_capteur          (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_Espace_technicien ();
  gtk_widget_show(x);
  a= lookup_widget(button,"afficher_alarme");
  gtk_widget_destroy(a);
}


void
on_radiobutton1_toggled_capteur        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
radiox=1;
}


void
on_radiobutton2_toggled_capteur        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
radiox=2;
}


void
on_button1_clicked_capteur             (GtkButton       *button,
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
on_checkbutton1_toggled_capteur        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
r=1;
else
r=0;
}

