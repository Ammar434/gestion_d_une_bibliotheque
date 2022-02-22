#ifndef _ENTREESORTIELC_H_
#define _ENTREESORTIELC_H_

#include "biblioLC.h"
#define BUFFER_SIZE 256

Biblio *charger_n_entrees(char *nomfic, int n);
void enregistrer_biblio(Biblio *b, char *nomfic);

#endif