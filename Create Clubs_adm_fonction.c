#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "fonction.h"


club tc[10000];
int nc=0;

enum
{
	Eclubname,
	Eclubid,
	Eclubmembers,
	Eeventnum,
	COLUMNS
};


club getactiveclub(){
	int i,max=0;
	club r;
	for (i=0;i<nc;i++){
		if(atoi(tc[i].clubmembers)>max){
			max=atoi(tc[i].clubmembers);
			r=tc[i];
		}
	}
	return r;
}
club getactivecluba(){
	int i,max=0;
	club r;
	for (i=0;i<nc;i++){
		if(atoi(tc[i].eventnum)>max){
			max=atoi(tc[i].eventnum);
			r=tc[i];
		}
	}
	return r;
}


char find(char id)
{
int i;
    for(i=0;i<nc;i++)

    {
        if(strcmp(id,tc[i].clubid)==0)
        { strcpy(id,tc[i].clubmembers);}
        return id; }}

char find1(char id)
{
int i;
    for(i=0;i<nc;i++)

    {
        if(strcmp(id,tc[i].clubid)==0)
        { strcpy(id,tc[i].eventnum);}
        return id; }
}


void listclr(GtkWidget *liste){

	fileload();

GtkCellRenderer *renderer=NULL;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	store=NULL;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL){
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("clubname", renderer, "text", Eclubname, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("clubid", renderer, "text", Eclubid, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("clubmembers", renderer, "text", Eclubmembers, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("eventnum", renderer, "text", Eeventnum, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);


		gtk_list_store_append(store, &iter);


	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
}

void viderliste(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;


	store=NULL;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL){
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Clubname", renderer, "text", Eclubname, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Club_id", renderer, "text", Eclubid, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Club_members", renderer, "text", Eclubmembers, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Club_events", renderer, "text", Eeventnum, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

		gtk_list_store_append(store, &iter);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
}
void afftrouver(GtkWidget* liste, int i){



	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	store=NULL;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL){
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Clubname", renderer, "text", Eclubname, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Club_id", renderer, "text", Eclubid, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Club_members", renderer, "text", Eclubmembers, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Club_events", renderer, "text", Eeventnum, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store, &iter, Eclubname, tc[i].clubname, Eclubid, tc[i].clubid, Eclubmembers, tc[i].clubmembers, Eeventnum, tc[i].eventnum,-1);

	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);

}

void afficherc(GtkWidget* liste)
{
	int i;
	fileload();

GtkCellRenderer *renderer=NULL;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	store=NULL;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL){
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("clubname", renderer, "text", Eclubname, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("clubid", renderer, "text", Eclubid, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("clubmembers", renderer, "text", Eclubmembers, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("eventnum", renderer, "text", Eeventnum, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	for(i=0;i<nc;i++)
	{
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, Eclubname, tc[i].clubname, Eclubid, tc[i].clubid, Eclubmembers, tc[i].clubmembers, Eeventnum, tc[i].eventnum,-1);
	}
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
}

void ajout(club x)
{
	tc[nc]=x;
	nc++;
}
int nospace(char s[])
{
int i=0;
  do{
    if(s[i]==' '){return 0;}
    i++;
  }while (s[i]!='\0') ;
  return 1;
}
int isalphabet(char t[])
{
  int i=0;
  do{
    if(((t[i]<'a')||(t[i]>'z'))&&((t[i]<'A')||(t[i]>'Z'))){return 0;}
    i++;
  }while (t[i]!='\0') ;
  return 1;
}

int isid(char t[])
{
  int i=0,b=0;
  while(t[b]!='\0'){
    if((t[b]<'0')||(t[b]>'9')){return -1;}
    b++;
  }
  for(i=0;i<nc;i++)
  {
      if(strcmp(t,tc[i].clubid)==0)
      {

          return i;
      }
  }
  return -1;
}

int isint(char t[])
{
    int i=0;
  while (t[i]!='\0'){
    if((t[i]<'0')||(t[i]>'9')){return 0;}
    i++;
  }
  return 1;
}

int supprimer(char id[])
{
    int i,j;
    for(i=0;i<nc;i++)
    {
        if(strcmp(id,tc[i].clubid)==0)
        {
            for(j=i;j<nc;j++)
            {
                tc[j]=tc[j+1];

            }
						nc--;
            return 1;
        }
    }
    return 0;
}



int modifier(club x)
{
    int i;
    for(i=0;i<nc;i++)
    {
        if(strcmp(x.clubid,tc[i].clubid)==0)
        {
            tc[i]=x;
            return 1;
        }
    }
    return 0;
}


void clubactif(club x)
{
    int i,max=0;
    char r[100];
    for(i=0;i<nc;i++)
    {
        if(atoi(tc[i].clubmembers)>max)
        {
            max=atoi(tc[i].clubmembers);
            strcpy(r,tc[i].clubid);
        }
}

printf("Le club le plus actif est d'identifiant : \n %s",r);
}


int filesave()
{
    int i;
    FILE *f;
    f=fopen("clubs.txt","w+");
    if(f==NULL){printf("error reading file"); return 0;}
    for(i=0;i<nc;i++)
    {
        fprintf(f,"%s %s %s %s\n",tc[i].clubname,tc[i].clubid,tc[i].clubmembers,tc[i].eventnum);
    }
    fclose(f);
    return 1;

}
int fileload()
{
    nc=0;
    FILE *f=NULL;
    f=fopen("clubs.txt","r+");
    if(f==NULL){printf("error reading file"); return 0;}
    while(fscanf(f,"%s %s %s %s\n",tc[nc].clubname,tc[nc].clubid,tc[nc].clubmembers,tc[nc].eventnum)!=EOF){
        nc++;
    }
    fclose(f);
    return nc;
	}
