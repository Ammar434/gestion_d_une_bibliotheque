#include <stdio.h>
#include <stdlib.h>
#include "entreeSortieH.h"

BiblioH *charger_n_entrees_hashtable(char *nomfic, int n)
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

    BiblioH *b = creer_biblio(n);
    for (int i = 0; i < n; i++)
    {
        fgets(buff, BUFFER_SIZE, f);
        if (sscanf(buff, "%d %s %s", &num, titre, auteur) != 3)
        {
            printf("erreur lecture\n");
            return NULL;
        }
        inserer(b, num, titre, auteur);
    }
    fclose(f);
    return b;
}

void enregistrer_biblio_hashtable(BiblioH *b, char *nomfic)
{
    FILE *f = fopen(nomfic, "w");
    LivreH *crawler;
    if (f == NULL)
    {
        printf("erreur lors de l'ouverture");
        return;
    }
    for (int i = 0; i < b->m; i++)
    {
        if ((b->T)[i] != NULL)
        {
            crawler = (b->T)[i];
            while (crawler != NULL)
            {
                fprintf(f, "%d %s %s\n", crawler->num, crawler->titre, crawler->auteur);
                crawler = crawler->suivant;
            }
        }
    }

    fclose(f);
}