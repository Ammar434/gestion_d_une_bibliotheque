#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioH.h"
#include "entreeSortieH.h"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Erreur\n");
        return 1;
    }

    // BiblioH *biblio = creer_biblio(10);
    // inserer(biblio, 2, "Le livre", "ammar");
    // affichage_biblio_hashtable(biblio);

    // inserer(biblio, 2, "Le livregf", "ammara");
    // affichage_biblio_hashtable(biblio);

    // inserer(biblio, 3, "Le livre de mathtiax", "mathias");
    // inserer(biblio, 3, "ammars", "aaedazsdfs");
    // inserer(biblio, 3, "ammadr", "aaedazsdfsd");
    // affichage_biblio_hashtable(biblio);

    int number_line_to_read = atoi(argv[2]);
    BiblioH *b = charger_n_entrees_hashtable(argv[1], number_line_to_read);
    // affichage_biblio_hashtable(b);
    LivreH *toFind = recherche_ouvrage_num_hashtable(b, 80);
    LivreH *toFind2 = recherche_ouvrage_titre_hashtable(b, "BHHKICQC");
    affichage_livre_hashtable(toFind);
    affichage_livre_hashtable(toFind2);
    printf("------------------------\n");

    BiblioH *b2 = recherche_livres_auteur_hashtable(b, "efsarcbynecd");
    inserer(b, 19, "fjdiojfd", "hsqmgbbuqcl");
    affichage_biblio_hashtable(b2);
    printf("------------------------\n");

    supprimer_ouvrage_hashtable(b2, 2, "JYBLD", "efsarcbynecd");
    affichage_biblio_hashtable(b2);

    // enregistrer_biblio_hashtable(b, "tazez.txt");

    return 0;
}