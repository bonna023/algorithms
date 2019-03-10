#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "outilsPile.h"

void afficherPile(pile_t* pile) {
	int i,
		val_tmp;

	pile_t* pile_tmp;
	pile_tmp = creerPile(pile->capacite);

	printf("\t----------------------------------\n");
	printf("\tAffichage de la pile de capacité %d\n", pile->capacite);

	// affiche la pile originale et empile les valeurs dans une pile temporaire
	if(pileVide(pile)) {
		printf("\tLa pile est vide.\n");
		printf("\t----------------------------------\n");
	}
	else {
		for(i=0; i<pile->capacite; i++) {
			if(!pileVide(pile)) {
				val_tmp = depiler(pile);
				empiler(pile_tmp, val_tmp);
				printf("\t\t[%d]\n", val_tmp);
			}
		}

		printf("\t----------------------------------\n");

		// depile la pile temporaire pour rempiler la pile originale
		while(!pileVide(pile_tmp))
			empiler(pile, depiler(pile_tmp));
	}

	detruirePile(&pile_tmp);
}

pile_t* copierPile(pile_t* pileOrigine) {
	int i, intTmp, taille;
	pile_t *pileCopie, *pileTmp;

	pileCopie = creerPile(capacitePile(pileOrigine));
	pileTmp = creerPile(capacitePile(pileOrigine));

	taille = taillePile(pileOrigine);

	for(i=0; i<taille; i++) {
		empiler(pileTmp, depiler(pileOrigine));
	}

	for(i=0; i<taille; i++ ) {
		intTmp = depiler(pileTmp);

		empiler(pileOrigine, intTmp);
		empiler(pileCopie, intTmp);
	}

	detruirePile(&pileTmp);

	return pileCopie;
}

int taillePile(pile_t* pile) {
	return pile->sommet;
}
