#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "liste.h"

liste_t* creerListe() {
	liste_t* liste;
	liste = (liste_t*) malloc(sizeof(liste_t));
	liste->tete = NULL;

	return liste;
}

void detruireListe(liste_t** liste) {
	free((*liste)->tete);
	free((*liste));
	*liste = NULL;
}

void insererListe(liste_t* liste, cellule_t* cellule) {
	if(cellule != NULL)	 {
		cellule->succ = liste->tete;
		
		if(liste->tete != NULL)
			liste->tete->pred = cellule;
		
		liste->tete = cellule;
		cellule->pred = NULL;
	}
}

cellule_t* rechercherListe(liste_t* liste, char* mot) {
	cellule_t* cellule = liste->tete;

	while(cellule != NULL && strcmp(cellule->mot, mot) != 0)
		cellule = cellule->succ;
	
	return cellule;
}

void supprimerListe(liste_t* liste, cellule_t* cellule) {
	if(cellule != NULL) {
		if(cellule->pred != NULL)
			cellule->pred->succ = cellule->succ;
		else
			liste->tete = cellule->succ;

		if(cellule->succ != NULL)
			cellule->succ->pred = cellule->pred;
	}
}
