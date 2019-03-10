#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "outilsGraphe.h"

graphe_t* creerGraphe(char* cheminFichier) {
	graphe_t* graphe;
	graphe = (graphe_t*)malloc(sizeof(graphe_t));

	FILE* fichier;
	
	char motLecture[27];
	int entierLecture = 0,
		i = 0;

	if((fichier = fopen(cheminFichier, "r")) != NULL) {
		if(fscanf(fichier, "%s", motLecture) == EOF) printf("erreur lecture\n");
		if(strcmp(motLecture, "nSommets") == 0) {
			if(fscanf(fichier, "%d", &graphe->nSommets) == EOF) printf("erreur lecture\n");
			
			// création de la liste d'adjacence
			graphe->adj = (liste_t**)malloc(sizeof(liste_t)*graphe->nSommets);
			for(i=0; i<graphe->nSommets; i++)
				graphe->adj[i] = creerListe();

			// création de la matrice d'adjacence
			graphe->mat = (int**)malloc(sizeof(int*)*graphe->nSommets);
			for(i=0; i<graphe->nSommets; i++)
				graphe->mat[i] = (int*)malloc(sizeof(int)*graphe->nSommets);
		}

		if(fscanf(fichier, "%s", motLecture) == EOF) printf("erreur lecture\n");
		if(strcmp(motLecture, "oriente") == 0) {
			if(fscanf(fichier, "%d", &graphe->oriente) == EOF) printf("erreur lecture\n");
		}

		if(fscanf(fichier, "%s", motLecture)==EOF) printf("erreur lecture\n");
		if(strcmp(motLecture, "value") == 0) {
			if(fscanf(fichier, "%d", &graphe->value) == EOF) printf("erreur lecture\n");
		}

		if(fscanf(fichier, "%s", motLecture)==EOF) printf("erreur lecture\n");
		if(strcmp(motLecture, "complet") == 0) {
			if(fscanf(fichier, "%d", &graphe->complet) == EOF) printf("erreur lecture\n");
		}

		if(fscanf(fichier, "%s", motLecture)==EOF) printf("erreur lecture\n");
		if(strcmp(motLecture, "debutDefAretes") == 0) {

			if(fscanf(fichier, "%s", motLecture) == EOF) printf("erreur lecture\n");
			while(strcmp(motLecture, "finDefAretes") != 0) {

				if(fscanf(fichier, "%d", &entierLecture) == EOF) printf("erreur lecture\n");
				
				// liste d'adjacence
				element_liste_t* element = creerElementListe(entierLecture);
				insererListe(graphe->adj[atoi(motLecture)], element);
				
				if(graphe->oriente == 0) {
					element_liste_t* element = creerElementListe(atoi(motLecture));
					insererListe(graphe->adj[entierLecture], element);
				}

				// matrice d'adjacence
				graphe->mat[atoi(motLecture)][entierLecture] = 1;
				if(graphe->oriente == 0)
					graphe->mat[entierLecture][atoi(motLecture)] = 1;

				if(fscanf(fichier, "%s", motLecture) == EOF) printf("erreur lecture\n");
			}
		}
		fclose(fichier);
	}
	else {
		graphe = NULL;
	}

	return graphe;
}

void detruireGraphe(graphe_t** graphe) {
	free((*graphe)->adj);
	free((*graphe)->mat);
	free((*graphe));
	*graphe = NULL;
}
