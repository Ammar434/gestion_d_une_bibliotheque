#ifndef _BIBLIOLC_H_
#define _BIBLIOLC_H_

typedef struct livre
{
    int num;
    char *titre;
    char *auteur;
    struct livre *suiv;
} Livre;

typedef struct
{
    Livre *L;
} Biblio;

Livre *creer_livre(int num, char *titre, char *auteur);
void liberer_livre(Livre *l);
Biblio *creer_biblio();
void liberer_biblio(Biblio *b);
void inserer_en_tete(Biblio *b, int num, char *titre, char *auteur);

void affichage_Livre(Livre *l);
void affichage_Biblio(Biblio *b);
Livre *recherche_ouvrage_num(Biblio *b, int num);
Livre *recherche_ouvrage_titre(Biblio *b, char *titre);
Biblio *recherche_livres_auteur(Biblio *b, char *auteur);
void supprimer_ouvrage(Biblio *b, int num, char *titre, char *auteur);
void fusion(Biblio *b1, Biblio *b2);
Biblio *recherche_exemplaires(Biblio *b);

#endif