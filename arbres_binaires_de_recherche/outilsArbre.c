#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "outilsArbre.h"

void transplanter(arbre_t* T, noeud_t* u, noeud_t* v) {
	if(u->pere == NULL) {
		T->racine = v;
	}
	else if(u == u->pere->fils_gauche) {
		u->pere->fils_gauche = v;
	}
	else {
		u->pere->fils_droite = v;
	}

	if(v != NULL) {
		v->pere = u->pere;
	}
}

noeud_t* minimumArbre(noeud_t* noeud) {
	noeud_t* res = NULL;

	while(noeud->fils_gauche != NULL)
		res = noeud->fils_gauche;

	return res;
}

void afficherArbreIteratif(arbre_t* arbre) {
	
}

// parcours infixe 
void afficherArbreRecurssif(noeud_t* racine) {
	noeud_t* x;
	x = racine;

	if(x != NULL) {
		afficherArbreRecurssif(x->fils_gauche);
		printf("(%s)\n", x->mot);
		afficherArbreRecurssif(x->fils_droite);
	}
}
