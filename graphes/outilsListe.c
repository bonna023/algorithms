#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "outilsListe.h"

void afficherListe(liste_t* liste) {
	if(liste->tete != NULL) {
		int compteur = 1;
		element_liste_t* elementTmp = liste->tete;

		do {
			printf(" %d ", elementTmp->numSommet);
			elementTmp = elementTmp->succ;
			compteur++;
		}while(elementTmp != NULL);
		printf("\n");

		detruireElementListe(&elementTmp);
	}
	else {
		printf(" La liste est vide\n");
	}
}
