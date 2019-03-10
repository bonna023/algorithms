#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "outilsGraphe.h"
#include "outilsListe.h"

void afficherListesAdjacences(graphe_t* graphe) {
	int i;
	printf("\n\tAffichage des listes d'adjacences :\n");
	printf("\t-----------------------------------\n");
	for(i=0; i<graphe->nSommets; i++) {
		printf("\t");
		printf("[%d]\t", i);
		afficherListe(graphe->adj[i]);
	}
	printf("\n");
}

void afficherMatricesAdjacences(graphe_t* graphe) {
	int i, j;
	printf("\n\tAffichage de la matrice du graphe :\n");
	printf("\t-----------------------------------\n");
	for(i = 0; i < graphe->nSommets; i++) {
		printf("\t");
		for(j = 0; j < graphe->nSommets; j++) {
			printf(" %d ", graphe->mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
