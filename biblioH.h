#ifndef _BIBLIO_H_
#define _BIBLIO_H_
#include <math.h>

#define NOMBRE_OR (sqrt(5) - 1) / 2

// Linked list
typedef struct livreh
{
    int clef;
    int num;
    char *titre;
    char *auteur;
    struct livreh *suivant;
} LivreH;

typedef struct table
{
    int nE;     /*nombre d’elements contenus dans la table de hachage */
    int m;      /*taille de la table de hachage */
    LivreH **T; /*table de hachage avec resolution des collisions par chainage */
} BiblioH;

int fonctionClef(char *auteur);
LivreH *creer_livre(int num, char *titre, char *auteur);
void liberer_livre(LivreH *l);
BiblioH *creer_biblio(int m);
int fonctionHachage(int cle, int m);
void inserer(BiblioH *b, int num, char *titre, char *auteur);
void affichage_livre_hashtable(LivreH *l);
void affichage_biblio_hashtable(BiblioH *b);
#endif