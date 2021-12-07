#ifndef FONCTION_H_
#define FONCTION_H_

struct club
{
    char clubname[50];
    char clubid[15];
    char clubmembers[10];
    char eventnum[100];
};
typedef struct club club;

void afftrouver(GtkWidget* liste, int i);
void viderliste(GtkWidget *liste);
club getactiveclub();
void listclr(GtkWidget *liste);
void afficherc(GtkWidget* liste);
void ajout(club x);
int isalphabet(char t[]);
int isid(char t[]);
int isint(char t[]);
int supprimer(char id[]);
int modifier(club x);
int recherche(char id[]);
club getactivecluba();
void clubactif();
int filesave();
int fileload();
char find(char id);
char find1(char id);
#endif
