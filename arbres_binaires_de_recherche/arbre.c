#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "arbre.h"
#include "outilsArbre.h"

arbre_t* creerArbre() {
	arbre_t* arbre;
	arbre = (arbre_t*) malloc(sizeof(arbre_t));

	arbre->racine = NULL;

	return arbre;
}

void detruireArbre(arbre_t* arbre) {
	arbre_t *arbre_droite,
			*arbre_gauche;

	arbre_droite = (arbre_t*) malloc(sizeof(arbre_t));
	arbre_gauche = (arbre_t*) malloc(sizeof(arbre_t));

	if(arbre->racine->fils_gauche != NULL) {
		arbre_gauche->racine = arbre->racine->fils_gauche;
		detruireArbre(arbre_gauche);
	}

	if(arbre->racine->fils_droite != NULL) {
		arbre_droite->racine = arbre->racine->fils_droite;
		detruireArbre(arbre_droite);
	}

	free(&(arbre)->racine);
	(arbre)->racine = NULL;
}

void insererArbre(arbre_t* T, noeud_t* z) {
	noeud_t *y, *x;

	y = NULL;
	x = T->racine;
	
	// on descend le long de l'arbre jusqu'à la bonne place
	while(x != NULL) {
		y = x;

		if(strcmp(z->mot, x->mot) < 0) 
			x = x->fils_gauche;
		else 
			x = x->fils_droite;
	}

	// y devient le pere du noeud à insérer
	z->pere = y;

	// si l'arbre était vide z en devient sa racine
	if(y == NULL) {
		T->racine = z;
	}

	else if(strcmp(z->mot, y->mot) < 0 ) {
		y->fils_gauche = z;
	}
	else {
		y->fils_droite = z;
	}
}

noeud_t* rechercherArbreIteratif(arbre_t* arbre, char* mot) {
	noeud_t* x;
	x = arbre->racine;

	// printf("test\n");

	while(x != NULL && strcmp(x->mot, mot) != 0) {
		if(strcmp(mot, x->mot) < 0) {
			printf("[%s]\n", x->mot);
			(x = x->fils_gauche);
		}
		else {
			printf("[%s]\n", x->mot);
			(x = x->fils_droite);
		}
	}

	return x;
}

void supprimerArbre(arbre_t* T, noeud_t* z) {
	noeud_t* y;

	if(z->fils_gauche == NULL) {
		transplanter(T, z, z->fils_droite);
	}
	else if(z->fils_droite == NULL) {
		transplanter(T, z, z->fils_gauche);
	}
	else {
		y = minimumArbre(z->fils_droite);
		
		if(y->pere != z) {
			transplanter(T, y, y->fils_droite);
			y->fils_droite = z->fils_droite;
		}

		transplanter(T, z, y);
		y->fils_gauche = z->fils_gauche;
		y->fils_gauche->pere = z;
	}
}
