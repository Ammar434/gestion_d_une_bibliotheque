#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entreeSortieLC.h"

int main()
{
    // Lecture de 10 livres du fichier GdeBiblio.txt
    Biblio *b = charger_n_entrees("GdeBiblio.txt", 10);

    // creation d'un livre de numero ; 0, de titre : avare et d'auteur : moliere
    printf("creation d'un livre de numero ; 0, de titre : avare et d'auteur : moliere\n");
    Livre *l = creer_livre(0, "avare", "moliere");
    affichage_Livre(l);
    printf("\n");
    printf("\n");

    // liberation du livre de numero ; 0, de titre : avare et d'auteur : moliere
    liberer_livre(l);
    printf("\n");
    printf("\n");

    // affichage du premier livre de la bibliothèque b
    printf("affichage du premier livre de la bibliotheque b\n");
    affichage_Livre(b->L);
    printf("\n");
    printf("\n");

    // affichage de la bibliothèque b
    printf("affichage de la bibliothèque b\n");
    affichage_Biblio(b);
    printf("\n");
    printf("\n");

    // insertion en tete d'un livre de numero : 10, de titre allo et d'auteur owfrx
    printf("insertion en tete d'un livre de numero : 10, de titre allo et d'auteur owfrx\n");
    printf("affichage de la bibliothèque avant insertion en tete\n");
    affichage_Biblio(b);
    printf("--------------------------------------------------------------------\n");
    inserer_en_tete(b, 10, "allo", "owfrx");
    printf("affichage de la bibliothèque apres insertion en tete\n");
    affichage_Biblio(b);
    printf("\n");
    printf("\n");

    // recherche d'un ouvrage par son numéro (1)
    printf("recherche d'un ouvrage par son numéro (1)\n");
    affichage_Livre(recherche_ouvrage_num(b, 1));
    printf("\n");
    printf("\n");

    // recherche d'un ouvrage par son titre (JYBLD)
    printf("recherche d'un ouvrage par son titre (JYBLD)\n");
    affichage_Livre(recherche_ouvrage_titre(b, "JYBLD"));
    printf("\n");
    printf("\n");

    // recherche de tous les livres d'un même auteur (owfrx)
    printf("recherche de tous les livres d'un même auteur (owfrx)\n");
    Biblio *b2 = recherche_livres_auteur(b, "owfrx");
    affichage_Biblio(b2);
    liberer_biblio(b2);
    printf("\n");
    printf("\n");

    // suppression d'un ouvrage (numéro : 3, titre : KEZXDU, auteur : xdrwv)
    printf("suppression d'un ouvrage (numéro : 3, titre : KEZXDU, auteur : xdrwv)\n");
    printf("affichage de la bibliotheque avant suppression :\n");
    affichage_Biblio(b);
    printf("--------------------------------------------------------------------\n");
    supprimer_ouvrage(b, 3, "KEZXDU", "xdrwv");
    printf("affichage de la bibliotheque apres suppression :\n");
    affichage_Biblio(b);
    printf("\n");
    printf("\n");

    // fusion de 2 bibliothèques
    printf("fusion de 2 bibliothèques (b et b3)\n");
    Biblio *b3 = charger_n_entrees("GdeBiblio4.txt", 5);
    printf("affichage de la bibliotheque b avant la fusion :\n");
    affichage_Biblio(b);
    printf("--------------------------------------------------------------------\n");
    printf("affichage de la bibliotheque b3 avant la fusion :\n");
    affichage_Biblio(b3);
    printf("--------------------------------------------------------------------\n");
    printf("affichage de la bibliotheque apres la fusion :\n");
    fusion(b, b3);
    affichage_Biblio(b);
    printf("\n");
    printf("\n");

    // Recherche ouvrage avec plusieurs exemplaires
    // Nous avons inserer dans la bibliotheque un autre ouvrage de titre KEZXDU et d'auteur xdrwv mais de numero different
    inserer_en_tete(b, 100, "allo", "owfrx");

    Biblio *b4 = recherche_exemplaires(b);
    printf("affichage d'une bibliotheque comprenant des ouvrages en plusieurs exemplaires :\n");
    affichage_Biblio(b4);
    liberer_biblio(b4);
    printf("\n");
    printf("\n");

    // Ecriture de la bibliotheque b sur un fichier test_exo1.txt
    enregistrer_biblio(b, "test_exo1.txt");

    // liberation de la bibliotheque b
    liberer_biblio(b);
}