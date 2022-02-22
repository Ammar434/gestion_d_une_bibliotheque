#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entreeSortieLC.h"

void menu()
{
    printf("0 - Sortie du programme\n");
    printf("1 - Affichage de la bibliotheque\n");
    printf("2 - Inserer un ouvrage\n");
    printf("3 - Rechercher un ouvrage par son numero\n");
    printf("4 - Rechercher un ouvrage par son titre\n");
    printf("5 - Rechercher tous les livres d'un meme auteur\n");
    printf("6 - Supprimer un ouvrage\n");
    printf("7 - Liste de tous les ouvrages avec plusieurs exemplaires\n");
    printf("8 - Fusionner 2 bibliotheques\n");
    printf("9 - Ecrire sur un fichier texte\n");
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Erreur\n");
        return 1;
    }
    int arg = atoi(argv[2]);
    Biblio *b = charger_n_entrees(argv[1], arg);

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
    int cpt, cpt2, nb1, nb2;
    char buff[BUFFER_SIZE];
    char buff2[BUFFER_SIZE];
    char titre[BUFFER_SIZE];
    char auteur[BUFFER_SIZE];
    char fichier1[BUFFER_SIZE];
    char fichier2[BUFFER_SIZE];
    Biblio *bexe = NULL;
    do
    {
        printf("--------------------------------Que voulez-vous faire ?------------------------------------\n");
        menu();
        fgets(buff, BUFFER_SIZE, stdin);
        sscanf(buff, "%d\n", &rep);
        printf("\n");
        switch (rep)
        {
        case 1:
            printf("Affichage de la bibliotheque : \n");
            affichage_Biblio(b);
            printf("\n");
            printf("-------------------------------------------------------------------------------------------\n");
            printf("\n");
            break;

        case 2:
            printf("Veuillez ecrire le numero , le titre et l'auteur de l'ouvrage\n");
            fgets(buff, BUFFER_SIZE, stdin);

            cpt = sscanf(buff, "%d %s %s\n", &num, titre, auteur);
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
            fgets(buff, BUFFER_SIZE, stdin);
            cpt = sscanf(buff, "%d\n", &num);
            if (cpt == 1)
            {
                Livre *l = recherche_ouvrage_num(b, num);
                if (l == NULL)
                {

                    printf("L'ouvrage n'existe pas dans la bibliotheque\n");
                    printf("\n");
                    printf("-------------------------------------------------------------------------------------------\n");
                    printf("\n");
                }
                else
                {
                    printf("Voici l'ouvrage recherche\n");
                    affichage_Livre(l);
                    printf("\n");
                    printf("-------------------------------------------------------------------------------------------\n");
                    printf("\n");
                }
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
            fgets(buff, BUFFER_SIZE, stdin);
            cpt = sscanf(buff, "%s\n", titre);
            if (cpt == 1)
            {

                Livre *l = recherche_ouvrage_titre(b, titre);
                if (l == NULL)
                {

                    printf("L'ouvrage n'existe pas dans la bibliotheque\n");
                    printf("\n");
                    printf("-------------------------------------------------------------------------------------------\n");
                    printf("\n");
                }
                else
                {
                    printf("Voici l'ouvrage recherche\n");
                    affichage_Livre(l);
                    printf("\n");
                    printf("-------------------------------------------------------------------------------------------\n");
                    printf("\n");
                }
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
            fgets(buff, BUFFER_SIZE, stdin);
            cpt = sscanf(buff, "%s\n", auteur);
            if (cpt == 1)
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
            printf("Veuillez ecrire le numero , le titre et l'auteur de l'ouvrage a supprimer\n");
            fgets(buff, BUFFER_SIZE, stdin);
            cpt = sscanf(buff, "%d %s %s\n", &num, titre, auteur);
            if (cpt == 3)
            {
                supprimer_ouvrage(b, num, titre, auteur);
                printf("Suppression effectuee avec succes\n");
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

        case 7:
            bexe = recherche_exemplaires(b);
            printf("Voici une liste de tous les ouvrages avec plusieurs exemplaires:\n");
            affichage_Biblio(bexe);
            printf("\n");
            printf("-------------------------------------------------------------------------------------------\n");
            printf("\n");
            break;

        case 8:
            printf("Veuillez ecrire le nom des fichiers txt des 2 bibliotheques que vous voulez fusionner\n");
            fgets(buff, BUFFER_SIZE, stdin);
            cpt = sscanf(buff, "%s %s\n", fichier1, fichier2);
            if (cpt == 2)
            {

                printf("Veuillez ecrire le nombre d'ouvrage a prendre dans le 1er et 2eme fichier\n");
                fgets(buff2, BUFFER_SIZE, stdin);
                cpt2 = sscanf(buff2, "%d %d\n", &nb1, &nb2);
                if (cpt2 == 2)
                {
                    Biblio *b1 = charger_n_entrees(fichier1, nb1);
                    Biblio *b2 = charger_n_entrees(fichier2, nb2);
                    if ((b1 != NULL) && (b2 != NULL))
                    {
                        fusion(b1, b2);
                        printf("Fusion avec succes\n");
                        printf("Affichage des livres\n");
                        affichage_Biblio(b1);
                        b = b1;
                    }
                    else
                    {
                        printf("La fusion n'a pas abouti\n");
                    }
                    printf("\n");
                    printf("-------------------------------------------------------------------------------------------\n");
                    printf("\n");
                }
                else
                {
                    printf("Echec de la fusion\n");
                    printf("\n");
                    printf("-------------------------------------------------------------------------------------------\n");
                    printf("\n");
                }
            }
            else
            {
                printf("Echec de la fusion\n");
                printf("\n");
                printf("-------------------------------------------------------------------------------------------\n");
                printf("\n");
            }
            break;

        case 9:
            printf("Choisissez le nom du fichier.txt que vous voulez créer\n");
            fgets(buff, BUFFER_SIZE, stdin);

            cpt = sscanf(buff, "%s\n", fichier1);
            if (cpt == 1)
            {
                enregistrer_biblio(b, fichier1);
                printf("Ecriture de la bibliotheque dans le fichier %s.txt avec succes\n", fichier1);
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
        }
    } while (rep != 0);
    printf("Merci , et au revoir.\n");
    return 0;
}
