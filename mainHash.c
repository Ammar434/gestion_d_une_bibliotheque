#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entreeSortieH.h"

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
    BiblioH *b = charger_n_entrees_hashtable(argv[1], arg);

    int rep;
    int num;
    int cpt, cpt2, nb1, nb2;
    char buff[BUFFER_SIZE];
    char buff2[BUFFER_SIZE];
    char titre[BUFFER_SIZE];
    char auteur[BUFFER_SIZE];
    char fichier1[BUFFER_SIZE];
    char fichier2[BUFFER_SIZE];
    BiblioH *bexe = NULL;
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
            affichage_biblio_hashtable(b);
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
                inserer(b, num, titre, auteur);
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
                LivreH *l = recherche_ouvrage_num_hashtable(b, num);
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
                    affichage_livre_hashtable(l);
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

                LivreH *l = recherche_ouvrage_titre_hashtable(b, titre);
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
                    affichage_livre_hashtable(l);
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
                BiblioH *bauteur = recherche_livres_auteur_hashtable(b, auteur);
                printf("Voici les ouvrages ecrits par %s\n", auteur);
                affichage_biblio_hashtable(bauteur);
                liberer_biblio(bauteur);
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
                supprimer_ouvrage_hashtable(b, num, titre, auteur);
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
            bexe = recherche_exemplaires_hashtable(b);
            printf("Voici une liste de tous les ouvrages avec plusieurs exemplaires:\n");
            affichage_biblio_hashtable(bexe);
            liberer_biblio(bexe);
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
                    BiblioH *b1 = charger_n_entrees_hashtable(fichier1, nb1);
                    BiblioH *b2 = charger_n_entrees_hashtable(fichier2, nb2);
                    if ((b1 != NULL) && (b2 != NULL))
                    {
                        fusion_hashtable(b1, b2);
                        printf("Fusion avec succes\n");
                        printf("Affichage des livres\n");
                        affichage_biblio_hashtable(b1);
                        liberer_biblio(b);
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
                enregistrer_biblio_hashtable(b, fichier1);
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
    liberer_biblio(b);
    return 0;
}