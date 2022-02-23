#include "entreeSortieH.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define BIBLIO_TOTAL_SIZE 99999

void simulationRechercheLivreAvecNum()
{
    clock_t temps_initial;
    clock_t temps_final;
    float temps_cpu;
    BiblioH *biblio_hash;
    int random_value;
    char *nom_fichier = "GdeBiblio.txt";
    FILE *file_recherche_hashtable_livre_avec_num = fopen("rechercherHashtableRechercheLivreAvecNum.txt", "w");
    int k = 0;

    for (int i = 1000; i < 50000; i += 100)
    {
        biblio_hash = charger_n_entrees_hashtable(nom_fichier, i);
        random_value = rand() % i;
        temps_initial = clock();
        recherche_ouvrage_num_hashtable(biblio_hash, random_value);
        temps_final = clock();
        temps_cpu = (temps_final - temps_initial) * pow(10, -6);
        fprintf(file_recherche_hashtable_livre_avec_num, "%d %f\n", i, temps_cpu);
        printf("Iteration %d Pour %d livres Duree %f\n", k, i, temps_cpu);
        liberer_biblio(biblio_hash);
        k++;
    }
    fclose(file_recherche_hashtable_livre_avec_num);
}

void simulationRechercheLivreAvecTitre()
{
    clock_t temps_initial;
    clock_t temps_final;
    float temps_cpu;
    BiblioH *biblio_hash;
    char *nom_fichier = "GdeBiblio.txt";
    FILE *file_recherche_hashtable_livre_avec_titre = fopen("rechercherHashtableRechercheLivreAvecTitre.txt", "w");
    int k = 0;
    for (int i = 1000; i < 50000; i += 100)
    {
        biblio_hash = charger_n_entrees_hashtable(nom_fichier, i);
        temps_initial = clock();
        recherche_ouvrage_titre_hashtable(biblio_hash, "BOMEOE");
        temps_final = clock();
        temps_cpu = (temps_final - temps_initial) * pow(10, -6);
        fprintf(file_recherche_hashtable_livre_avec_titre, "%d %f\n", i, temps_cpu);
        printf("Iteration %d Pour %d livres Duree %f\n", k, i, temps_cpu);
        liberer_biblio(biblio_hash);
        k++;
    }
    fclose(file_recherche_hashtable_livre_avec_titre);
}

void simulationRechercheLivreAvecAuteur()
{
    clock_t temps_initial;
    clock_t temps_final;
    float temps_cpu;
    BiblioH *biblio_hash;
    char *nom_fichier = "GdeBiblio.txt";
    FILE *file_recherche_hashtable_livre_avec_auteur = fopen("rechercherHashtableRechercheLivreAvecAuteur.txt", "w");
    int k = 0;
    for (int i = 1000; i < 50000; i += 100)
    {
        biblio_hash = charger_n_entrees_hashtable(nom_fichier, i);
        temps_initial = clock();
        recherche_ouvrage_titre_hashtable(biblio_hash, "mqprory");
        temps_final = clock();
        temps_cpu = (temps_final - temps_initial) * pow(10, -6);
        fprintf(file_recherche_hashtable_livre_avec_auteur, "%d %f\n", i, temps_cpu);
        printf("Iteration %d Pour %d livres Duree %f\n", k, i, temps_cpu);
        liberer_biblio(biblio_hash);
        k++;
    }
    fclose(file_recherche_hashtable_livre_avec_auteur);
}

void simulationRechercheIdentique()
{
    clock_t temps_initial;
    clock_t temps_final;
    float temps_cpu;
    BiblioH *biblio_hash;
    char *nom_fichier = "GdeBiblio.txt";
    FILE *file_recherche_hashtable = fopen("rechercherHashtable.txt", "w");
    int k = 0;
    for (int i = 1000; i < 50000; i += 100)
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
    fclose(file_recherche_hashtable);
}

int main()
{
    srand(time(NULL));
    // simulationRechercheLivreAvecNum();
    // simulationRechercheLivreAvecTitre();
    simulationRechercheLivreAvecAuteur();
    return 0;
}