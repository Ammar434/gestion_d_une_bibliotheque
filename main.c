#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entreeSortieLC.h"

void menu()
{
    printf("0 - Sortie du programme\n");
    printf("1 - Affichage\n");
    printf("2 - Inserer un ouvrage\n");
    printf("3 - Rechercher un ouvrage par son numero\n");
    printf("4 - Rechercher un ouvrage par son titre\n");
    printf("5 - Rechercher tous les livres d'un meme auteur\n");
    printf("6 - Fusionner deux bibliotheques\n");
    printf("7 - Liste de tous les ouvrages avec plusieurs exemplaires\n");
}

int main(int argc, char **argv)
{
    long arg = strtol(argv[2], NULL, 10);
    Biblio *b = charger_n_entrees(argv[1], arg);
    Biblio *b2 = charger_n_entrees(argv[1], arg);

    /*jeux de tests
    // Lecture d'un fichier
    // Biblio *b = charger_n_entrees("GdeBiblio.txt", 10);

    // affichage d'un livre
    // affichage_Livre(b->L);

    // affichage d'une bibliothèque
    // affichage_Biblio(b);

    // recherche d'un ouvrage par son numéro
    // Livre *l1 = recherche_ouvrage_num(b, 1);
    // affichage_Livre(l1);

    // recherche d'un ouvrage par son titre
    // Livre *l2 = recherche_ouvrage_titre(b, "JYBLD");
    // affichage_Livre(l2);

    // recherche de tous les livres d'un même auteur
    // inserer_en_tete(b, 10, "allo", "owfrx");
    // Biblio *b2 = recherche_livres_auteur(b, "owfrx");
    // affichage_Biblio(b2);

    // suppression d'un ouvrage
    // supprimer_ouvrage(b, 3, "KEZXDU", "xdrwv");
    // affichage_Biblio(b);

    // fusion de 2 bibliothèques
    // Biblio *b3 = charger_n_entrees("GdeBiblio.txt", 5);
    // fusion(b, b3);
    // affichage_Biblio(b);

    // Recherche ouvrage avec plusieurs exemplaires
    // inserer_en_tete(b, 10, "KEZXDU", "xdrwv");
    // Biblio *b4 = recherche_exemplaires(b);
    // affichage_Biblio(b4);

    // Ecriture d'un fichier
    // enregistrer_biblio(b, "test.txt");
    */

    int rep;
    int num;
    int cpt;
    char buff[BUFFER_SIZE];
    char titre[BUFFER_SIZE];
    char auteur[BUFFER_SIZE];
    Biblio *bexe = NULL;
    do
    {
        printf("--------------------------------Que voulez-vous faire ?------------------------------------\n");
        menu();
        scanf("%d", &rep);
        switch (rep)
        {
        case 1:
            printf("Affichage\n");
            affichage_Biblio(b);
            printf("\n");
            printf("-------------------------------------------------------------------------------------------\n");
            printf("\n");
            break;

        case 2:
            printf("Veuillez ecrire le numero , le titre et l'auteur de l'ouvrage\n");
            fgets(buff, BUFFER_SIZE, stdin);
            cpt = sscanf(buff, "%d %s %s", &num, titre, auteur);
            if (cpt == 3)
            {
                inserer_en_tete(b, num, titre, auteur);
                printf("Ajout fait\n");
                printf("\n");
                printf("-------------------------------------------------------------------------------------------\n");
                printf("\n");
            }
            else
            {
                printf("Erreur format\n");
                printf("\n");
                printf("-------------------------------------------------------------------------------------------\n");
                printf("\n");
            }
            break;

        case 3:
            printf("Veuillez saisir le numero de l'ouvrage recherche\n");
            if (scanf("%d", &num) == 1)
            {
                Livre *l = recherche_ouvrage_num(b, num);
                printf("Voici l'ouvrage recherche\n");
                affichage_Livre(l);
                printf("\n");
                printf("-------------------------------------------------------------------------------------------\n");
                printf("\n");
            }
            else
            {
                printf("Erreur format\n");
                printf("\n");
                printf("-------------------------------------------------------------------------------------------\n");
                printf("\n");
            }
            break;

        case 4:
            printf("Veuillez saisir le titre de l'ouvrage recherche\n");
            if (scanf("%s", titre) == 1)
            {
                Livre *l = recherche_ouvrage_titre(b, titre);
                printf("Voici l'ouvrage recherche\n");
                affichage_Livre(l);
                printf("\n");
                printf("-------------------------------------------------------------------------------------------\n");
                printf("\n");
            }
            else
            {
                printf("Erreur format\n");
                printf("\n");
                printf("-------------------------------------------------------------------------------------------\n");
                printf("\n");
            }
            break;

        case 5:
            printf("Veuillez saisir l'auteur des livres recherchees\n");
            if (scanf("%s", auteur) == 1)
            {
                Biblio *bauteur = recherche_livres_auteur(b, auteur);
                printf("Voici les ouvrages ecrits par %s\n", auteur);
                affichage_Biblio(bauteur);
                printf("\n");
                printf("-------------------------------------------------------------------------------------------\n");
                printf("\n");
            }
            else
            {
                printf("Erreur format\n");
                printf("\n");
                printf("-------------------------------------------------------------------------------------------\n");
                printf("\n");
            }
            break;

        case 6:
            printf("Voici une liste des bibliotheques fusionnes:\n");
            fusion(b, b2);
            affichage_Biblio(b);
            printf("\n");
            printf("-------------------------------------------------------------------------------------------\n");
            printf("\n");
            break;

        case 7:
            bexe = recherche_exemplaires(b);
            printf("Voici une liste de tous les ouvrages avec plusieurs exemplaires:\n");
            affichage_Biblio(bexe);
            printf("\n");
            printf("-------------------------------------------------------------------------------------------\n");
            printf("\n");
            break;
        }
    } while (rep != 0);
    printf("Merci , et au revoir.\n");
    return 0;
}
