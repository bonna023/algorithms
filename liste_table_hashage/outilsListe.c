#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "outilsListe.h"

void afficherListe(liste_t* liste) {
	if(liste->tete != NULL) {
		int compteur = 1;
		cellule_t* cellule = liste->tete;

		printf("\nAffichage de la liste\n");
		printf("---------------------\n");

		do {
			printf("élément %d : %s\n", compteur, cellule->mot);
			cellule = cellule->succ;
			compteur++;
		}while(cellule != NULL);
		
		printf("---------------------\n");
	}
	else {
		printf("\nLa liste est vide\n");
	}
}

int compterListe(liste_t* liste) {
	int compteur = 0;
	cellule_t* cellule = liste->tete;

	while(cellule != NULL) {
		compteur++;
		cellule = cellule->succ;
	}

	return compteur;
}
