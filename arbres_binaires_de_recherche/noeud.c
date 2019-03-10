#include <stdlib.h>
#include <string.h>

#include "noeud.h"

noeud_t* creerNoeud(char* mot) {
	noeud_t* noeud;
	noeud = (noeud_t*) malloc(sizeof(noeud_t));
	noeud->mot = (char*) malloc(sizeof(char*));

	strcpy(noeud->mot, mot);
	noeud->fils_gauche = NULL;
	noeud->fils_droite = NULL;
	noeud->pere = NULL;

	return noeud;
}

void detruireNoeud(noeud_t** noeud) {
	free(*noeud);
	*noeud = NULL;
}
