#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "tableHachage.h"
#include "outilsTableHachage.h"


tableHachage_t* creerTableHachage(int tailleTableH) {
	int i;
	tableHachage_t* tableH;
	tableH = (tableHachage_t*) malloc(sizeof(tableHachage_t));
	tableH->tabListes = (liste_t**) malloc(sizeof(liste_t*)*tailleTableH);

	for(i=0; i<tailleTableH; i++)
		tableH->tabListes[i] = creerListe();

	tableH->tailleTableH = tailleTableH;

	return tableH;
}

void detruireTableHachage(tableHachage_t** tableH) {
	free((*tableH)->tabListes);
	free((*tableH));
	*tableH = NULL;
}

int hachage(tableHachage_t* tableH, int k) {
	int res = k % tableH->tailleTableH;
	return res;
}

void insererHachage(tableHachage_t* tableH, cellule_t* cellule) {
	insererListe(tableH->tabListes[hachage(tableH, convertirChEntier(cellule->mot))], cellule);
}

cellule_t* rechercherHachage(tableHachage_t* tableH, char* mot) {
	return  rechercherListe(tableH->tabListes[hachage(tableH, convertirChEntier(mot))], mot);
}

void supprimerHachage(tableHachage_t* tableH, cellule_t* cellule) {
	if(cellule != NULL)
		supprimerListe(tableH->tabListes[hachage(tableH, convertirChEntier(cellule->mot))], cellule);
}
