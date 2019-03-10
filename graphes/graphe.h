#ifndef GRAPHE_H_
#define GRAPHE_H_

#include "liste.h"

typedef struct graphe_t {
	int nSommets;
	int oriente;
	int value;
	int complet;
	struct liste_t** adj;	// tableau de liste
	int** mat;						// tableau d'entiers à deux dimensions
}graphe_t;

graphe_t* creerGraphe(char* fichier);
void detruireGraphe(graphe_t** graphe);	

#endif
