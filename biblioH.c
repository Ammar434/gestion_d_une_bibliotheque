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
    return hash_value;
}

LivreH *creer_livre(int num, char *titre, char *auteur)
{
    LivreH *livre = (LivreH *)malloc(sizeof(LivreH));
    assert(livre);
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
    {
        return;
    }
    free(l->titre);
    free(l->auteur);
    free(l);
    l = NULL;
}

// a checker
BiblioH *creer_biblio(int m)
{
    BiblioH *biblio = (BiblioH *)malloc(sizeof(BiblioH));
    LivreH **hash_table = malloc(sizeof(LivreH *) * m);

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

// fuite de memoire
void liberer_biblio(BiblioH *b)
{
    if (b == NULL)
    {
        return;
    }
    if (b->T == NULL)
    {
        free(b);
        return;
    }

    LivreH **hash_table = b->T;
    LivreH *tmp;

    for (int i = 0; i < b->m; i++)
    {
        if (hash_table[i] != NULL)
        {
            while (hash_table[i] != NULL)
            {
                tmp = hash_table[i];
                hash_table[i] = hash_table[i]->suivant;
                liberer_livre(tmp);
            }
        }
    }
    // free(b);
}

int fonctionHachage(int cle, int m)
{
    return (int)(m * (cle * NOMBRE_OR - (int)(cle * NOMBRE_OR)));
}

void inserer(BiblioH *b, int num, char *titre, char *auteur)
{
    LivreH *l = creer_livre(num, titre, auteur);
    int i = fonctionHachage(fonctionClef(auteur), b->m);

    if ((b->T)[i] == NULL)
    {
        (b->T)[i] = l;
    }
    else
    {
        l->suivant = (b->T)[i];
        (b->T)[i] = l;
    }
    b->nE = (b->nE) + 1;
}

void affichage_livre_hashtable(LivreH *l)
{
    if (l == NULL)
    {
        return;
    }
    printf("%d %d %s %s\n", l->clef, l->num, l->titre, l->auteur);
}

// a checker mais OK
void affichage_biblio_hashtable(BiblioH *b)
{
    if (b == NULL)
    {
        return;
    }

    LivreH *l;
    for (int i = 0; i < b->m; i++)
    {
        if ((b->T)[i] != NULL) //???
        {
            l = (b->T)[i];
            while (l != NULL)
            {
                printf("Pos %d ", i);
                affichage_livre_hashtable(l);
                l = l->suivant;
            }
        }
        else
        {
            // case contenant NULL
            printf("Pos %d\t--------------\n", i);
        }
    }
}

LivreH *recherche_ouvrage_num_hashtable(BiblioH *b, int num)
{
    LivreH *tmp;

    if ((b == NULL) || (b->T == NULL))
    {
        return NULL;
    }

    for (int i = 0; i < b->m; i++)
    {
        if ((b->T)[i] != NULL)
        {
            tmp = b->T[i];
            while (tmp != NULL)
            {
                if (tmp->num == num)
                {
                    return tmp;
                }
                tmp = tmp->suivant;
            }
        }
    }
    return NULL;
}

LivreH *recherche_ouvrage_titre_hashtable(BiblioH *b, char *titre)
{
    LivreH *tmp;

    if ((b == NULL) || (b->T == NULL))
    {
        return NULL;
    }
    for (int i = 0; i < b->m; i++)
    {
        if ((b->T)[i] != NULL)
        {
            tmp = b->T[i];
            while (tmp != NULL)
            {
                if (strcmp(titre, tmp->titre) == 0)
                {
                    return tmp;
                }
                tmp = tmp->suivant;
            }
        }
    }
    return NULL;
}

BiblioH *recherche_livres_auteur_hashtable(BiblioH *b, char *auteur)
{
    BiblioH *biblio = creer_biblio(1);
    int clef = fonctionClef(auteur);
    int hash_value = fonctionHachage(clef, b->m);
    LivreH *l = (b->T)[hash_value];
    if (b == NULL)
    {
        return NULL;
    }
    l = (b->T)[hash_value];
    while (l)
    {
        if (clef == l->clef)
        {
            inserer(biblio, l->num, l->titre, l->auteur);
        }
        l = l->suivant;
    }

    return biblio;
}

void supprimer_ouvrage_hashtable(BiblioH *b, int num, char *titre, char *auteur)
{
    if (b == NULL)
    {
        return;
    }
    LivreH *tmp = NULL;
    LivreH *pred = NULL;

    int position = fonctionHachage(fonctionClef(auteur), b->m);
    tmp = b->T[position];
    while (tmp && (tmp->num != num) && (strcmp(tmp->titre, titre) != 0) && (strcmp(tmp->auteur, auteur) != 0))
    {
        pred = tmp;
        tmp = tmp->suivant;
    }
    if (!pred)
    {
        b->T[position] = (b->T[position])->suivant;
        return;
    }
    else
        pred->suivant = tmp->suivant;

    liberer_livre(tmp);
}

void fusion_hashtable(BiblioH *b1, BiblioH *b2)
{
    if ((b1 == NULL) && (b2 == NULL))
    {
        return;
    }

    LivreH *tmp = NULL;
    int i;
    for (i = 0; i < b2->m; i++)
    {
        tmp = b2->T[i];
        while (tmp)
        {
            inserer(b1, tmp->num, tmp->titre, tmp->auteur);
            tmp = tmp->suivant;
        }
    }
    liberer_biblio(b2);
}

BiblioH *recherche_exemplaires_hashtable(BiblioH *b)
{
    if ((b->T == NULL) || (b->T == NULL))
    {
        return NULL;
    }
    BiblioH *biblio = creer_biblio(1);
    LivreH *livreListe;
    LivreH *tmp;

    for (int i = 0; i < b->m; i++)
    {
        livreListe = *(b->T + i);
        while (livreListe)
        {
            tmp = *(b->T + i);
            while (tmp)
            {
                if ((strcmp(livreListe->titre, tmp->titre) == 0) && (strcmp(livreListe->auteur, tmp->auteur) == 0) && (livreListe->num != tmp->num))
                {
                    inserer(biblio, livreListe->num, livreListe->titre, livreListe->auteur);
                    break;
                }
                tmp = tmp->suivant;
            }
            livreListe = livreListe->suivant;
        }
        // if (livreListe)
        // {
        //     while (livreListe->suivant)
        //     {
        //         precedent = livreListe;
        //         suivant = livreListe->suivant;
        //         if (strcmp(precedent->auteur, suivant->auteur) == 0)
        //         {
        //             if (strcmp(precedent->titre, suivant->titre) == 0)
        //             {
        //                 inserer(biblio, precedent->num, precedent->titre, precedent->auteur);
        //             }
        //         }
        //         livreListe = livreListe->suivant;
        //     }
        //     if (strcmp(precedent->auteur, livreListe->auteur) == 0)
        //         if (strcmp(precedent->titre, livreListe->titre) == 0)
        //             inserer(biblio, livreListe->num, livreListe->titre, livreListe->auteur);
        // }
    }
    return biblio;
}