#ifndef TABLEHACHAGE_H_
#define TABLEHACHAGE_H_

#include "liste.h"

typedef struct tableHachage_t {
	struct liste_t** tabListes;
	int tailleTableH;
}tableHachage_t;

tableHachage_t* creerTableHachage(int tailleTabListes);
void detruireTableHachage(tableHachage_t** tableH);
int puissance(int base, int exposant);
int convertirChEntier(char* chaine);
int hachage(tableHachage_t* tableH, int k);	// méthode de la division
void insererHachage(tableHachage_t* tableH, cellule_t* cellule);
cellule_t* rechercherHachage(tableHachage_t* tableH, char* mot);
void supprimerHachage(tableHachage_t* tableH, cellule_t* cellule);

#endif
