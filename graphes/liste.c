#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

void insererListe(liste_t* liste, element_liste_t* element) {
	if(element != NULL)	 {
		element->succ = liste->tete;
		
		if(liste->tete != NULL)
			liste->tete->pred = element;
		
		liste->tete = element;
		element->pred = NULL;
	}
}

element_liste_t* creerElementListe(int numSommet) {
	element_liste_t* element;
	element = (element_liste_t*)malloc(sizeof(element_liste_t));
	element->numSommet = numSommet;
	element->pred = NULL;
	element->succ = NULL;

	return element;
}

void detruireElementListe(element_liste_t** element) {
	free((*element));
	*element = NULL;
}
