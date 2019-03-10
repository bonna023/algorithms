#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "hanoi.h"

hanoi_t* creerHanoi(int tailleTours) {
	int i;
	hanoi_t* hanoi;
	hanoi = (hanoi_t*) malloc(sizeof(hanoi_t));

	hanoi->tailleTours = tailleTours;

	hanoi->tours = (pile_t**) malloc(sizeof(pile_t)*3);
	hanoi->tours[0] = creerPile(tailleTours);
	hanoi->tours[1] = creerPile(tailleTours);
	hanoi->tours[2] = creerPile(tailleTours);

	for(i=tailleTours; i>0; i--)
		empiler(hanoi->tours[0], i);

	return hanoi;
}

void detruireHanoi(hanoi_t** hanoi) {
	detruirePile(&(*hanoi)->tours[0]);
	detruirePile(&(*hanoi)->tours[1]);
	detruirePile(&(*hanoi)->tours[2]);
	free((*hanoi)->tours);
	free(*hanoi);
}

char *afficherDisque(char *chaine, int tailleTours, int valDisque) {
	int i;
	
	strcpy(chaine, "");
	for (i = 0; i < tailleTours - valDisque; i++)
		strcat(chaine, " ");
	for (i = 0; i < valDisque; i++)
		strcat(chaine, "*");
	strcat(chaine, " ");
	for (i = 0; i < valDisque; i++)
		strcat(chaine, "*");
	for (i = 0; i < tailleTours - valDisque; i++)
		strcat(chaine, " ");
		
	return chaine;
} 

void afficherHanoi(hanoi_t *hanoi) {
	int i, j;
	char chaine[50];
	pile_t **toursTemp = (pile_t **) malloc(sizeof(pile_t *) * 3);
	
	for (i = 0; i < 3; i++) {
		toursTemp[i] = copierPile(hanoi->tours[i]);
	}
		
	for (i = 0; i < 100; i++)
		printf("\n");
	for (i = 0; i < hanoi->tailleTours; i++) {
		for (j = 0; j < 3; j++) {
			if (i < hanoi->tailleTours - taillePile(hanoi->tours[j])) {
				printf("%s", afficherDisque(chaine, hanoi->tailleTours, 0));
			}
			else {
				printf("%s", afficherDisque(chaine, hanoi->tailleTours, depiler(toursTemp[j])));
			}
		}
		printf("\n");
	}
	for (i = 0; i < (hanoi->tailleTours * 2 + 1) * 3; i++);
		printf("\n");
	for (i = 0; i < 3; i++) {
		detruirePile(&toursTemp[i]);
	}
	free(toursTemp);
}

void deplacerDisque(hanoi_t* hanoi, int tourDepart, int tourArrivee) {
	int depart, arrivee;
	if(tourDepart > 0 && tourDepart < 4 && tourArrivee > 0 && tourArrivee < 4) {
		depart = tourDepart-1;
		arrivee = tourArrivee-1;
		
		if(pileVide(hanoi->tours[depart])) {
			printf("Déplacement impossible : la tour de départ est vide.\n");
		}
		else {
			if( pileVide(hanoi->tours[arrivee]) || (sommetPile(hanoi->tours[depart]) < sommetPile(hanoi->tours[arrivee])) ) {
				empiler(hanoi->tours[arrivee], depiler(hanoi->tours[depart]));
			}
		}
	}
	else {
		printf("Utiliser les tours 1, 2 et 3 uniquement.\n");
	}
}

bool gagne(hanoi_t* hanoi) {
	return (taillePile(hanoi->tours[1]) == capacitePile(hanoi->tours[1])
		 || taillePile(hanoi->tours[2]) == capacitePile(hanoi->tours[2]));
}
