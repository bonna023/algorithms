#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "cellule.h"

cellule_t* creerCellule(char* mot) {
	cellule_t* cellule;
	cellule = (cellule_t*) malloc(sizeof(cellule_t));

	if(cellule != NULL) {
		cellule->mot = (char*) malloc(sizeof(char)*(strlen(mot)+1));
		strcpy(cellule->mot, mot);

		cellule->pred = NULL;
		cellule->succ = NULL;
	}

	return cellule;
}

void detruireCellule(cellule_t** cellule) {
	free((*cellule)->mot);
	free((*cellule));
	*cellule = NULL;
}
