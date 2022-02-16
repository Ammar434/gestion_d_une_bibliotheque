#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "biblioLC.h"

// Q1.2
Livre *creer_livre(int num, char *titre, char *auteur)
{
    Livre *l = (Livre *)malloc(sizeof(Livre));
    assert(l);
    l->num = num;
    l->titre = strdup(titre);
    l->auteur = strdup(auteur);
    l->suiv = NULL;
    return l;
}

void liberer_livre(Livre *l)
{
    if (l == NULL)
    {
        return;
    }
    free(l->titre);
    free(l->auteur);
    free(l);
}

Biblio *creer_biblio()
{
    Biblio *b = (Biblio *)malloc(sizeof(Biblio));
    assert(b);
    b->L = NULL;
    return b;
}

void liberer_biblio(Biblio *b)
{
    if (b == NULL)
    {
        return;
    }
    if (b->L == NULL)
    {
        free(b);
        return;
    }

    Livre *tmp = NULL;
    while (b->L != NULL)
    {
        tmp = (b->L)->suiv;
        liberer_livre(b->L);
        b->L = tmp;
    }
    free(b);
}

void inserer_en_tete(Biblio *b, int num, char *titre, char *auteur)
{
    Livre *l = creer_livre(num, titre, auteur);
    l->suiv = b->L;
    b->L = l;
}

// Q1.6
void affichage_Livre(Livre *l)
{
    if (l == NULL)
    {
        return;
    }
    printf("%d %s %s\n", l->num, l->titre, l->auteur);
}

void affichage_Biblio(Biblio *b)
{
    if (b == NULL)
    {
        return;
    }

    Livre *l = b->L;
    while (l != NULL)
    {
        affichage_Livre(l);
        l = l->suiv;
    }
}

Livre *recherche_ouvrage_num(Biblio *b, int num)
{
    if ((b == NULL) || (b->L == NULL))
    {
        return NULL;
    }

    Livre *tmp = b->L;
    while (tmp)
    {
        if (tmp->num == num)
        {
            return tmp;
        }
        tmp = tmp->suiv;
    }
    return NULL;
}

Livre *recherche_ouvrage_titre(Biblio *b, char *titre)
{
    if ((b == NULL) || (b->L == NULL))
    {
        return NULL;
    }

    Livre *tmp = b->L;
    while (tmp)
    {
        if (strcmp(titre, tmp->titre) == 0)
        {
            return tmp;
        }
        tmp = tmp->suiv;
    }
    return NULL;
}

Biblio *recherche_livres_auteur(Biblio *b, char *auteur)
{
    if (b == NULL)
    {
        return NULL;
    }

    Biblio *ptr = creer_biblio();
    Livre *tmp = b->L;
    while (tmp)
    {
        if (strcmp(tmp->auteur, auteur) == 0)
        {
            inserer_en_tete(ptr, tmp->num, tmp->titre, tmp->auteur);
        }
        tmp = tmp->suiv;
    }
    return ptr;
}

void supprimer_ouvrage(Biblio *b, int num, char *titre, char *auteur)
{
    Livre *pred = NULL;
    Livre *ptr = b->L;
    if (b == NULL)
    {
        return;
    }

    while ((ptr != NULL) && (ptr->num != num) && (strcmp(ptr->titre, titre) != 0) && (strcmp(ptr->auteur, auteur) != 0))
    {
        pred = ptr;
        ptr = ptr->suiv;
    }

    if (ptr != NULL) // vérification que ptr existe
    {
        if (pred == NULL) // s'il faut supprimer la tete de la liste
        {
            b->L = b->L->suiv;
        }
        else // s'il faut supprimer autre que la tete de la liste
        {
            pred->suiv = ptr->suiv;
        }
        liberer_livre(ptr);
    }
    return;
}

void fusion(Biblio *b1, Biblio *b2)
{
    if ((b1 == NULL) && (b2 == NULL))
    {
        return;
    }

    Livre *ptr1 = b1->L;
    Livre *ptr2 = b2->L;
    while (ptr1->suiv != NULL)
    {
        ptr1 = ptr1->suiv;
    }
    while (ptr2 != NULL)
    {
        ptr1->suiv = creer_livre(ptr2->num, ptr2->titre, ptr2->auteur);
        ptr2 = b2->L->suiv;
        liberer_livre(b2->L);
        b2->L = ptr2;
        ptr1 = ptr1->suiv;
    }
    liberer_biblio(b2);
}

Biblio *recherche_exemplaires(Biblio *b)
{
    if (b == NULL)
    {
        return NULL;
    }

    Livre *ptr1 = b->L;
    Livre *ptr2 = NULL;
    Biblio *tmp = creer_biblio();
    while (ptr1 != NULL)
    {
        ptr2 = ptr1->suiv;
        while (ptr2 != NULL)
        {
            if ((strcmp(ptr1->titre, ptr2->titre) == 0) && (strcmp(ptr1->auteur, ptr2->auteur) == 0))
            {
                if (recherche_ouvrage_num(tmp, ptr1->num) == NULL)
                {
                    inserer_en_tete(tmp, ptr1->num, ptr1->titre, ptr1->auteur);
                }
                if (recherche_ouvrage_num(tmp, ptr2->num) == NULL)
                {
                    inserer_en_tete(tmp, ptr2->num, ptr2->titre, ptr2->auteur);
                }
            }
            ptr2 = ptr2->suiv;
        }
        ptr1 = ptr1->suiv;
    }
    return tmp;
}