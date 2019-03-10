#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util.h"
#include "types.h"

void afficherTableauEntier(int* tab, int taille)
{
	int i;
	for(i=0; i<taille; i++) {
		printf("tab[%d] : %d\n", i, tab[i]);
	}
	printf("\n");
}

void remplirTableauAleatoire(int* tab, int taille)
{
	int i;
	srand(time(NULL));
	for(i=0; i<taille; i++)
		tab[i] = rand()/1000000;
}

void copierTableau(int origine[], int copie[], int taille)
{
	int i;
	for(i=0; i<taille; i++)
		copie[i] = origine[i];
}

void afficherFilePriorite(t_tas* filePriorite)
{
	int i = 0;
	// printf("\tlongueur : %d / taille : %d\n", filePriorite->longueur, filePriorite->taille);
	for(i=0; i < filePriorite->taille ; i++) {
		printf("\t[%d] %s\n", filePriorite->tableau[i], filePriorite->taches[i]);
	}
	printf("\n");
}
