#include "entreeSortieLC.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void simulationRechercheLivreAvecNum()
{
    clock_t temps_initial;
    clock_t temps_final;
    float temps_cpu;
    Biblio *biblio_hash;
    int random_value;
    char *nom_fichier = "GdeBiblio.txt";
    FILE *file_recherche_hashtable_livre_avec_num = fopen("rechercherListeChaineRechercheLivreAvecNum.txt", "w");
    int k = 0;

    for (int i = 1000; i < 50000; i += 100)
    {
        biblio_hash = charger_n_entrees(nom_fichier, i);
        random_value = rand() % i;
        temps_initial = clock();
        recherche_ouvrage_num(biblio_hash, random_value);
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
    Biblio *biblio_hash;
    char *nom_fichier = "GdeBiblio.txt";
    FILE *file_recherche_hashtable_livre_avec_titre = fopen("rechercherListeChaineRechercheLivreAvecTitre.txt", "w");
    int k = 0;
    for (int i = 1000; i < 50000; i += 100)
    {
        biblio_hash = charger_n_entrees(nom_fichier, i);
        temps_initial = clock();
        recherche_ouvrage_titre(biblio_hash, "BOMEOE");
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
    Biblio *biblio_hash;
    char *nom_fichier = "GdeBiblio.txt";
    FILE *file_recherche_hashtable_livre_avec_auteur = fopen("rechercherListeChaineRechercheLivreAvecAuteur.txt", "w");
    int k = 0;
    for (int i = 1000; i < 50000; i += 100)
    {
        biblio_hash = charger_n_entrees(nom_fichier, i);
        temps_initial = clock();
        recherche_ouvrage_titre(biblio_hash, "mqprory");
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
    Biblio *biblio_liste;
    char *nom_fichier = "GdeBiblio.txt";
    FILE *file_recherche_liste = fopen("rechercherListe.txt", "w");
    int k = 0;
    for (int i = 1000; i < 50000; i += 100)
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
    fclose(file_recherche_liste);
}
int main()
{
    srand(time(NULL));
    simulationRechercheLivreAvecAuteur();
    simulationRechercheLivreAvecNum();
    simulationRechercheLivreAvecTitre();
}