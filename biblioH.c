#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "biblioH.h"

int fonctionClef(char *auteur)
{
    int length = strlen(auteur);
    int hash_value = 0;
    for (int i = 0; i < length; i++)
    {
        hash_value += auteur[i];
    }
    printf("clef  %d\n", hash_value);

    return hash_value;
}

// Create new node
LivreH *creer_livre(int num, char *titre, char *auteur)
{
    LivreH *livre;
    livre = (LivreH *)malloc(sizeof(LivreH));
    livre->clef = fonctionClef(auteur);
    livre->num = num;
    livre->titre = strdup(titre);
    livre->auteur = strdup(auteur);
    livre->suivant = NULL;
    return livre;
}

void liberer_livre(LivreH *l)
{
    if (l == NULL)
        return;
    free(l->titre);
    free(l->auteur);
    free(l);
}

BiblioH *creer_biblio(int m)
{
    BiblioH *biblio;
    LivreH **hash_table;

    biblio = (BiblioH *)malloc(sizeof(BiblioH));
    hash_table = malloc(sizeof(LivreH *) * m);
    for (int i = 0; i < m; i++)
    {
        hash_table[i] = malloc(sizeof(LivreH));
        hash_table[i] = NULL;
    }
    biblio->nE = 0;
    biblio->m = m;
    biblio->T = hash_table;
    return biblio;
}

void liberer_biblio(BiblioH *b)
{
    LivreH *tmp;
    LivreH *tmp2;

    if (b->T == NULL)
        free(b);
    else
    {
        for (int n = 0; n < b->m; n++)
        {
            if (b->T[n] != NULL)
            {
                tmp2 = b->T[n];
                while (tmp2 != NULL)
                {
                    tmp = tmp2->suivant;
                    free(tmp2);
                    tmp2 = tmp;
                }
            }
        }
    }
}

int fonctionHachage(int cle, int m)
{
    return (m * (cle * NOMBRE_OR - (int)(cle * NOMBRE_OR)));
}

void inserer(BiblioH *b, int num, char *titre, char *auteur)
{
    LivreH *livre_to_insert;
    int location;

    livre_to_insert = creer_livre(num, titre, auteur);
    location = fonctionHachage(livre_to_insert->clef, b->m);
    printf("insert at %d\n", location);
    printf("taille hashtable %d\n", b->m);

    if ((b->T)[location] == NULL)
    {
        (b->T)[location] = livre_to_insert;
    }
    else
    {
        // else already something in this case add next
        livre_to_insert->suivant = (b->T)[location];
        (b->T)[location] = livre_to_insert;
    }
    b->nE = b->nE + 1;
}

void affichage_livre_hashtable(LivreH *l)
{
    // Check if need to print clef
    if (l == NULL)
        return;
    printf("%d %s %s\n", l->num, l->titre, l->auteur);
}

void affichage_biblio_hashtable(BiblioH *b)
{
    // Ask question about the efficiency of hashtable
    LivreH *crawler;

    if (b == NULL)
        return;

    for (int i = 0; i < b->m; i++)
    {
        if ((b->T)[i] != NULL)
        {
            crawler = (b->T)[i];
            while (crawler != NULL)
            {
                printf("Pos %d ", i);
                affichage_livre_hashtable(crawler);
                crawler = crawler->suivant;
            }
        }
        else
        {
            printf("Pos %d\t--------------\n", i);
        }
    }
}
