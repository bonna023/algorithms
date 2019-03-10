#ifndef UTIL_H_
#define UTIL_H_

#include "types.h"

void afficherTableauEntier(int tab[], int taille);
void remplirTableauAleatoire(int tab[], int taille);
void copierTableau(int origine[], int copie[], int taille);
void afficherFilePriorite(t_tas* filePriorite);

#endif
