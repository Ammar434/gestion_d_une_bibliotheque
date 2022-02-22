#include "entreeSortieH.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    clock_t temps_initial;
    clock_t temps_final;
    float temps_cpu;
    BiblioH *biblio_hash;
    char *nom_fichier = "GdeBiblio.txt";
    FILE *file_recherche_hashtable = fopen("rechercherHashtable.txt", "w");
    int k = 0;
    for (int i = 1000; i < 50000; i++)
    {
        biblio_hash = charger_n_entrees_hashtable(nom_fichier, i);
        temps_initial = clock();
        recherche_exemplaires_hashtable(biblio_hash);
        temps_final = clock();
        temps_cpu = (temps_final - temps_initial) * pow(10, -6);
        fprintf(file_recherche_hashtable, "%d %f\n", i, temps_cpu);
        printf("Iteration %d Pour %d livres Duree %f\n", k, i, temps_cpu);
        liberer_biblio(biblio_hash);
        k++;
    }
}