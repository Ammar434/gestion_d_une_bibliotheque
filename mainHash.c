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
    // inserer(biblio, 2, "Le livrz", "ammar");
    // inserer(biblio, 3, "ammar", "aaedaz");
    // inserer(biblio, 3, "ammars", "aaedazsdfs");
    // inserer(biblio, 3, "ammadr", "aaedazsdfsd");
    // affichage_biblio_hashtable(biblio);

    int number_line_to_read = atoi(argv[2]);
    BiblioH *b = charger_n_entrees_hashtable(argv[1], number_line_to_read);
    affichage_biblio_hashtable(b);
    enregistrer_biblio_hashtable(b, "tazez.txt");

    return 0;
}