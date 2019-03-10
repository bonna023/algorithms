#ifndef PL_H_
#define PL_H_

#include "graphe.h"

typedef struct sommet_t {
	struct sommet_t* pere;
	int couleur;
	int distanceSommetOrigine;
	int numSommet;
}sommet_t;

#define BLANC 	0
#define GRIS 	1
#define NOIR 	2

sommet_t creerSommet(int numSommet);
void detruireSommet(sommet_t** sommet);
void afficherSommet(sommet_t* sommet);

void afficherChemin(sommet_t origine, sommet_t arrivee);
sommet_t* parcoursEnLargeur(graphe_t* graphe, int numSommet);

// void parcoursEnProfondeurRecursif(graphe_t* graphe, int origin);

#endif
