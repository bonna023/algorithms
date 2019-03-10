#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pl.h"
#include "graphe.h"
#include "file.h"

sommet_t creerSommet(int numSommet) {
	sommet_t sommet;
	
	sommet.pere = NULL;
	sommet.couleur = BLANC;
	sommet.distanceSommetOrigine = 0;
	sommet.numSommet = numSommet;

	return sommet;
}

void detruireSommet(sommet_t** sommet) {
	free(*sommet);
	*sommet = NULL;
}

void afficherSommet(sommet_t* sommet) {
	if(sommet != NULL) {
		printf("\n----\n");
		printf("Couleur : %d\nDistance : %d", sommet->couleur, sommet->distanceSommetOrigine);
		printf("\n----\n");
	}
	else {
		printf("\n----\n");
		printf("le sommet est nul");
		printf("\n----\n");
	}
}

sommet_t* parcoursEnLargeur(graphe_t* graphe, int numSommetOrigine) {
	
	sommet_t* parcours;			// tableau contenant tous les sommets du graphe
	file_t* file;				// file contenant les sommets GRIS du PL
	sommet_t *u, *v, *s;		// sommets temporaires
	int i;
	
	// initialisation du tableau
	parcours = (sommet_t*) malloc(sizeof(sommet_t)*graphe->nSommets);
	for(i=0; i < graphe->nSommets; i++) {
		parcours[i] = creerSommet(i);
	}

	// initialisation de la file
	file = creerFile(graphe->nSommets);

	//--------------------------------------------------------------------------------------

	s = &parcours[numSommetOrigine];
	u = NULL;
	v = NULL;

	s->couleur = GRIS;
	s->distanceSommetOrigine = 0;
	s->pere = NULL;

	enfiler(file, s);

	while(!fileVide(file)) {
		element_liste_t* eTmp;

		u = defiler(file);

		//parcours de la liste u->numSommet de la liste d'adj du graphe
		eTmp = graphe->adj[u->numSommet]->tete;
		while(eTmp != NULL) {
			
			v = &parcours[eTmp->numSommet];
			
			if(v->couleur == BLANC) {
				v->couleur = GRIS;
				v->distanceSommetOrigine = u->distanceSommetOrigine+1;
				v->pere = u;
				enfiler(file, v);
			}

			eTmp = eTmp->succ;
		}

		u->couleur = NOIR;
	}

	free(parcours);
	detruireFile(&file);

	return parcours;
}

void afficherChemin(sommet_t origine, sommet_t arrivee) {

	if(origine.numSommet == arrivee.numSommet) {
		printf("\t(%d)", origine.numSommet);
	}
	else if(arrivee.pere == NULL) {
		printf("\tIl n'existe aucun chemin.");
	}
	else {
		afficherChemin(origine, *arrivee.pere);
		printf(" (%d)", arrivee.numSommet);
	}
}
