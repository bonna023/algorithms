#include <stdio.h>
#include <stdlib.h>
#include "tas.h"

t_tas* initTas(int longueur)
{
	int i=0;
	t_tas* tas;
	tas = (t_tas*) malloc(sizeof(t_tas));

	tas->longueur = longueur;
	tas->taille = 0;
	tas->tableau = (int*) malloc(sizeof(int)*longueur);

	tas->taches =  (char**) malloc(sizeof(char*)*longueur);
	for(i = 0; i < longueur; i++) {
		tas->taches[i] = (char*) malloc(sizeof(char*));
		tas->taille++;
	}

	return tas;
}
t_tas_p* initTasP(int longueur) {
	int i;
	
	t_tas_p* tas;
	tas = (t_tas_p*)malloc(sizeof(t_tas_p));

	tas->longueur = longueur;
	tas->taille = 0;
	tas->pointeurs = (void**) malloc(sizeof(void*)*longueur);

	for(i = 0; i < longueur; i++) {
		tas->pointeurs[i] = (void*) malloc(sizeof(void*));
	}

	return tas;
}

void detruireTas(t_tas** tas)
{
	free((*tas)->tableau);
	free((*tas)->taches);
	free(*tas);
	*tas = NULL;
}

// retourne le parent du noeud "i"
int parent(int i) {
	return (i-1)/2;
}

// retourne le fils gauche du noeud "i"
int gauche(int i) {
	return i*2+1;
}

// retourne le fils droit du noeud "i"
int droite(int i) {
	return i*2+2;
}

void echanger(t_tas* tas, int i, int j)
{
	int tmp = tas->tableau[i];
	tas->tableau[i] = tas->tableau[j];
	tas->tableau[j] = tmp;

	char* c ="";
	c = tas->taches[i];
	tas->taches[i] = tas->taches[j];
	tas->taches[j] =c;
}
void echangerP(t_tas_p* tas, int i, int j) {
	void* tmp = tas->pointeurs[i];
	tas->pointeurs[i] = tas->pointeurs[j];
	tas->pointeurs[j] = tmp;
}

void entasserMax(t_tas* tas, int i)
{
	int g = gauche(i),
		d = droite(i),
		max = 0;

	if(g < tas->taille && tas->tableau[g] > tas->tableau[i])
		max = g;
	else
		max = i;

	if(d < tas->taille && tas->tableau[d] > tas->tableau[max])
		max = d;

	if(max != i)
	{
		echanger(tas, i, max);
		entasserMax(tas, max);
	}
}


void construireTasMax(t_tas* tas)
{
	int i = 0;

	for(i = (tas->taille-1)/2; i >= 0; i--) {
		entasserMax(tas, i);
	}
}

int maximumTas(t_tas* tas)
{
	// printf("longueur : %d\ntaille : %d\n", tas->longueur, tas->taille);
	return tas->tableau[0];
}

// prend en paramètre la file de priorité,
// ainsi qu'un pointeur sur un entier et une chaine de caractere pour récupérer la tâche prioritaire
void extraireMaxTas(t_tas* tas, int* cleMax, char** tacheMax)
{
	*cleMax = tas->tableau[0];
	*tacheMax = tas->taches[0];

	if(tas->taille == 0) {
		printf("Erreur débordement négatif\n");
	}
	else {
		tas->taille--;
		tas->tableau[0] = tas->tableau[tas->taille];
		tas->taches[0] = tas->taches[tas->taille];
		entasserMax(tas, 0);
	}
}

// augment la valeur de la cle à l'indice i du TAS
void augmenterCleTas(t_tas* tas, int i, int cle)
{
	if(cle < tas->tableau[i])
		printf("Erreur : nouvelle clé plus petite que l'actuelle.\n");
	else {
		tas->tableau[i] = cle;
		while(i > 0 && tas->tableau[parent(i)] < tas->tableau[i]) {
			echanger(tas, i, parent(i));
			i = parent(i);
		}
	}
}

// insere une nouvelle CLE dans un TAS
void insererTasMax(t_tas* tas, int cle, char* tache)
{
	if(tas->taille < tas->longueur) {
		tas->taille++;
		tas->tableau[tas->taille-1] = 0;
		tas->taches[tas->taille-1] = tache;
		augmenterCleTas(tas, tas->taille-1, cle);
	}
}
