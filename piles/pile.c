#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "pile.h"

pile_t* creerPile(int capacite) {
	pile_t* pile;
	pile = (pile_t*) malloc(sizeof(pile_t));

	pile->capacite = capacite;
	pile->sommet = 0;
	pile->tab = (int*) malloc(sizeof(int)*capacite);

	return pile;
}

void detruirePile(pile_t** pile) {
	free((*pile)->tab);
	free(*pile);
	*pile = NULL;
}

int sommetPile(pile_t* pile) {
	if(!pileVide(pile))
		return pile->tab[pile->sommet-1];
	return -1;
}

int capacitePile(pile_t* pile) {
	return pile->capacite;
}

bool pileVide(pile_t* pile) {
	return (pile->sommet == 0);
}

bool pilePleine(pile_t* pile) {
	return (pile->sommet == pile->capacite);
}

bool empiler(pile_t* pile, int val) {
	if(pilePleine(pile)) {
		printf("Impossible d'empiler une nouvelle valeur, la pile est pleine.\n");
		return false;
	}
	else {
		pile->tab[pile->sommet] = val;
		pile->sommet++;
		return true;
	}
}

int depiler(pile_t* pile) {
	if(pileVide(pile)) {
		printf("Impossible de dépiler, la pile est vide.\n");
		return -1;
	}
	else {
		pile->sommet--;
		return pile->tab[pile->sommet];
	}
}
