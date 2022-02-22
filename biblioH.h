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
void liberer_biblio(BiblioH *b);
int fonctionHachage(int cle, int m);
void inserer(BiblioH *b, int num, char *titre, char *auteur);

void affichage_livre_hashtable(LivreH *l);
void affichage_biblio_hashtable(BiblioH *b);
LivreH *recherche_ouvrage_num_hashtable(BiblioH *b, int num);
LivreH *recherche_ouvrage_titre_hashtable(BiblioH *b, char *titre);
BiblioH *recherche_livres_auteur_hashtable(BiblioH *b, char *auteur);
void supprimer_ouvrage_hashtable(BiblioH *b, int num, char *titre, char *auteur);
void fusion_hashtable(BiblioH *b1, BiblioH *b2);
BiblioH *recherche_exemplaires_hashtable(BiblioH *b);

#endif