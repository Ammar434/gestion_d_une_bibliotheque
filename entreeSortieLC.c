#include <stdio.h>
#include <stdlib.h>
#include "entreeSortieLC.h"

Biblio *charger_n_entrees(char *nomfic, int n)
{
    char buff[BUFFER_SIZE];
    int num;
    char titre[BUFFER_SIZE];
    char auteur[BUFFER_SIZE];
    FILE *f = fopen(nomfic, "r");

    if (f == NULL)
    {
        printf("erreur lors de la lecture\n");
        return NULL;
    }

    Biblio *b = creer_biblio();
    for (int i = 0; i < n; i++)
    {
        fgets(buff, BUFFER_SIZE, f);
        if (sscanf(buff, "%d %s %s", &num, titre, auteur) != 3)
        {
            printf("erreur lecture\n");
            return NULL;
        }
        inserer_en_tete(b, num, titre, auteur);
    }
    fclose(f);
    return b;
}

void enregistrer_biblio(Biblio *b, char *nomfic)
{
    FILE *f = fopen(nomfic, "w");
    if (f == NULL)
    {
        printf("erreur lors de l'ouverture");
        return;
    }

    Livre *tmp = b->L;
    while (tmp != NULL)
    {
        fprintf(f, "%d %s %s\n", tmp->num, tmp->titre, tmp->auteur);
        tmp = tmp->suiv;
    }
    fclose(f);
}