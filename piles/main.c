#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outilsPile.h"
#include "pile.h"
#include "hanoi.h"


int main(int argc, char const *argv[])
{
	if(argc == 2) {
		if(strcmp(argv[1], "pile") == 0) {
			int capacite = 0,
				choix = 0,
				entier_tmp = 0;

			pile_t* pile;

			// programme de test
			printf("Bienvenue dans le programme de test des piles.\n");
			
			printf("\nCommencez par indiquer la capacité de la pile (entier) : ");
			if(scanf("%d", &capacite) == EOF) printf("Erreur saisie...\n");
			
			pile = creerPile(capacite);

			while(choix != 4) {
				printf("\nQue souhaitez vous faire ?\n\n\t1 Afficher la pile\n\t2 Empiler un entier\n\t3 Dépiler un entier\n\t4 Détruire la pile et quitter\n\n\tVotre choix : ");
				if(scanf("%d", &choix) == EOF) printf("Erreur saisie...\n");

				switch(choix) {
					case 1 :
						afficherPile(pile);
					break;

					case 2 :
						printf("\nVeuillez saisir l'entier à empiler : ");
						if(scanf("%d", &entier_tmp) == EOF) printf("Erreur saisie...\n");
						empiler(pile, entier_tmp);
					break;

					case 3 :
						entier_tmp = depiler(pile);
						printf("\n\t----------------------------------\n");
						printf("\tEntier dépiler : %d\n", entier_tmp);
						printf("\t----------------------------------\n\n");
					break;
						
					case 4 :
						detruirePile(&pile);
						printf("\n\t----------------------------------\n");
						printf("\tPile détruite.\n");
						printf("\t----------------------------------\n\n");
					break;

					default :
						printf("\n\t----------------------------------\n");
						printf("\tMauvais choix !\n");
						printf("\t----------------------------------\n\n");
					break;
				}
			}
		}
		else if(strcmp(argv[1], "hanoi") == 0) {
			printf("Jeu de Hanoi\n");
			
			int tailleTours, tourDepart, tourArrivee;
			hanoi_t* hanoi;

			printf("Taille des tours de Hanoi : ");
			if(scanf("%d", &tailleTours) == EOF) printf("Erreur saisie...\n");

			hanoi = creerHanoi(tailleTours);

			while(!gagne(hanoi)) {
				afficherHanoi(hanoi);

				printf("\nTour de départ : ");
				if(scanf("%d", &tourDepart) == EOF) printf("Erreur saisie...\n");

				printf("\nTour d'arrivée : ");
				if(scanf("%d", &tourArrivee) == EOF) printf("Erreur saisie...\n");

				deplacerDisque(hanoi, tourDepart, tourArrivee);
			}
			afficherHanoi(hanoi);
			printf("Bien joué !\n");

			detruireHanoi(&hanoi);
		}
	}
	else {
		printf("Commandes valides :\n");
		printf("\t./main pile\n");
		printf("\t./main hanoi\n");

		pile_t *pile, *pileCopie;
		
		pile = creerPile(3);
		empiler(pile, 8);
		empiler(pile, 45);
		empiler(pile, 81);

		pileCopie = copierPile(pile);

		afficherPile(pile);
		afficherPile(pileCopie);

		detruirePile(&pile);
		detruirePile(&pileCopie);
	}
	
	return 0;
}
