#include "entreeSortieH.h"
#include "entreeSortieLC.h"
#include <ctime>

void simultaion()
{
    clock_t temps_initial;
    clock_t temps_final;
    float temps_cpu;
    Biblio biblio_liste;
    BiblioH biblio_hashtable;
    char *nom_fichier = "GdeBiblio.txt";
    FILE *file_recherche_liste = fopen("rechercherListe.txt", 'w');
    FILE *file_recherche_hashtable = fopen("rechercherHashtable.txt", 'w');
    int k = 0;
    // Simultaion partie 1
    for (int i = 1000; i < 50000; i++)
    {
        biblio_liste = charger_n_entrees(biblio_liste, i);
        temps_initial = clock();
        recherche_exemplaires(biblio_liste);
        temps_final = clock();
        temps_cpu = (temps_final - temps_initial) * pow(10, -6);
        fprintf(file_recherche_liste, "%d %d %f\n", k, i, temps_cpu);
        printf("Iteration %d Pour %d livres Duree %f\n", k, i, temps_cpu);
        k++;
    }
    k = 0;
    for (int i = 1000; i < 50000; i++)
    {
        biblio_liste = charger_n_entrees_hashtable(biblio_hashtable, i);
        temps_initial = clock();
        recherche_exemplaires_hashtable(biblio_hashtable);
        temps_final = clock();
        temps_cpu = (temps_final - temps_initial) * pow(10, -6);
        fprintf(file_recherche_hashtable, "%d %d %f\n", k, i, temps_cpu);
        printf("Iteration %d Pour %d livres Duree %f\n", k, i, temps_cpu);
        k++;
    }
    // Simultaion partie 2
}