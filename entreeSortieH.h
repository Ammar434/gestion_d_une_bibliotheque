#ifndef _ENTREESORTIEH_H_
#define _ENTREESORTIEH_H_

#include "biblioH.h"
#define BUFFER_SIZE 256
BiblioH *charger_n_entrees_hashtable(char *nomfic, int n);
void enregistrer_biblio_hashtable(BiblioH *b, char *nomfic);

#endif