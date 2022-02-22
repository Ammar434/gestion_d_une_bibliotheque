#include "entreeSortieLC.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// void simultaion()
// {
//     clock_t temps_initial;
//     clock_t temps_final;
//     float temps_cpu;
//     Biblio *biblio_liste;
//     // BiblioH biblio_hashtable;
//     char *nom_fichier = "GdeBiblio.txt";
//     FILE *file_recherche_liste = fopen("data/rechercherListe.txt", "w");
//     // FILE *file_recherche_hashtable = fopen("data\\rechercherHashtable.txt", 'w');
//     int k = 0;
//     // Simultaion partie 1
//     for (int i = 1000; i < 50000; i++)
//     {
//         biblio_liste = charger_n_entrees(argv[2], i);
//         temps_initial = clock();
//         recherche_exemplaires(biblio_liste);
//         temps_final = clock();
//         temps_cpu = (temps_final - temps_initial) * pow(10, -6);
//         fprintf(file_recherche_liste, "%d %d %f\n", k, i, temps_cpu);
//         printf("Iteration %d Pour %d livres Duree %f\n", k, i, temps_cpu);
//         k++;
//     }
//     // k = 0;
//     // for (int i = 1000; i < 50000; i++)
//     // {
//     //     biblio_liste = charger_n_entrees_hashtable(biblio_hashtable, i);
//     //     temps_initial = clock();
//     //     recherche_exemplaires_hashtable(biblio_hashtable);
//     //     temps_final = clock();
//     //     temps_cpu = (temps_final - temps_initial) * pow(10, -6);
//     //     fprintf(file_recherche_hashtable, "%d %d %f\n", k, i, temps_cpu);
//     //     printf("Iteration %d Pour %d livres Duree %f\n", k, i, temps_cpu);
//     //     k++;
//     // }
//     // // Simultaion partie 2
// }

int main()
{
    clock_t temps_initial;
    clock_t temps_final;
    float temps_cpu;
    Biblio *biblio_liste;
    char *nom_fichier = "GdeBiblio.txt";
    FILE *file_recherche_liste = fopen("rechercherListe.txt", "w");
    int k = 0;
    for (int i = 1000; i < 50000; i++)
    {
        biblio_liste = charger_n_entrees(nom_fichier, i);
        temps_initial = clock();
        recherche_exemplaires(biblio_liste);
        temps_final = clock();
        temps_cpu = (temps_final - temps_initial) * pow(10, -6);
        fprintf(file_recherche_liste, " %d %f\n", i, temps_cpu);
        printf("Iteration %d Pour %d livres Duree %f\n", k, i, temps_cpu);
        liberer_biblio(biblio_liste);
        k++;
    }
}