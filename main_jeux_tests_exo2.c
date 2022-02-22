#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entreeSortieH.h"

int main()
{
    // Lecture de 10 livres du fichier GdeBiblio.txt
    BiblioH *b = charger_n_entrees_hashtable("GdeBiblio.txt", 10);

    // creation d'un livre de numero ; 0, de titre : avare et d'auteur : moliere
    printf("creation d'un livre de numero ; 0, de titre : avare et d'auteur : moliere\n");
    LivreH *l = creer_livre(0, "avare", "moliere");
    affichage_livre_hashtable(l);
    printf("\n");
    printf("\n");

    // liberation du livre de numero ; 0, de titre : avare et d'auteur : moliere
    liberer_livre(l);
    printf("\n");
    printf("\n");

    // affichage du premier livre de la bibliothèque b
    printf("affichage du premier livre de la bibliotheque b\n");
    affichage_livre_hashtable(*(b->T + 0));
    printf("\n");
    printf("\n");

    // affichage de la bibliothèque b
    printf("affichage de la bibliothèque b\n");
    affichage_biblio_hashtable(b);
    printf("\n");
    printf("\n");

    // insertion d'un livre de numero : 10, de titre allo et d'auteur owfrx
    printf("insertion d'un livre de numero : 10, de titre allo et d'auteur owfrx\n");
    printf("affichage de la bibliothèque avant insertion\n");
    affichage_biblio_hashtable(b);
    printf("--------------------------------------------------------------------\n");
    inserer(b, 10, "allo", "owfrx");
    printf("affichage de la bibliothèque apres insertion\n");
    affichage_biblio_hashtable(b);
    printf("\n");
    printf("\n");

    // recherche d'un ouvrage par son numéro (1)
    printf("recherche d'un ouvrage par son numéro (1)\n");
    LivreH *l1 = recherche_ouvrage_num_hashtable(b, 1);
    affichage_livre_hashtable(l1);
    printf("\n");
    printf("\n");

    // recherche d'un ouvrage par son titre (JYBLD)
    printf("recherche d'un ouvrage par son titre (JYBLD)\n");
    LivreH *l2 = recherche_ouvrage_titre_hashtable(b, "JYBLD");
    affichage_livre_hashtable(l2);
    printf("\n");
    printf("\n");

    // recherche de tous les livres d'un même auteur (owfrx)
    printf("recherche de tous les livres d'un même auteur (owfrx)\n");
    BiblioH *b2 = recherche_livres_auteur_hashtable(b, "owfrx");
    affichage_biblio_hashtable(b2);
    liberer_biblio(b2);
    printf("\n");
    printf("\n");

    // suppression d'un ouvrage (numéro : 3, titre : KEZXDU, auteur : xdrwv)
    printf("suppression d'un ouvrage (numéro : 3, titre : KEZXDU, auteur : xdrwv)\n");
    printf("affichage de la bibliotheque avant suppression :\n");
    affichage_biblio_hashtable(b);
    printf("--------------------------------------------------------------------\n");
    supprimer_ouvrage_hashtable(b, 3, "KEZXDU", "xdrwv");
    printf("affichage de la bibliotheque apres suppression :\n");
    affichage_biblio_hashtable(b);
    printf("\n");
    printf("\n");

    // fusion de 2 bibliothèques
    printf("fusion de 2 bibliothèques (b et b3)\n");
    BiblioH *b3 = charger_n_entrees_hashtable("GdeBiblio4.txt", 5);
    printf("affichage de la bibliotheque b avant la fusion :\n");
    affichage_biblio_hashtable(b);
    printf("--------------------------------------------------------------------\n");
    printf("affichage de la bibliotheque b3 avant la fusion :\n");
    affichage_biblio_hashtable(b3);
    printf("--------------------------------------------------------------------\n");
    printf("affichage de la bibliotheque apres la fusion :\n");
    fusion_hashtable(b, b3);
    affichage_biblio_hashtable(b);
    printf("\n");
    printf("\n");

    // Recherche ouvrage avec plusieurs exemplaires
    // Nous avons inserer dans la bibliotheque un autre ouvrage de titre KEZXDU et d'auteur xdrwv mais de numero different
    inserer(b, 100, "allo", "owfrx");
    BiblioH *b4 = recherche_exemplaires_hashtable(b);
    printf("affichage d'une bibliotheque comprenant des ouvrages en plusieurs exemplaires :\n");
    affichage_biblio_hashtable(b4);
    liberer_biblio(b4);
    printf("\n");
    printf("\n");
    // Ecriture de la bibliotheque b sur un fichier test.txt
    enregistrer_biblio_hashtable(b, "test_exo2.txt");

    // liberation de la bibliotheque b
    liberer_biblio(b);
}