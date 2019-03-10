#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "pl.h"
#include "graphe.h"
#include "outilsGraphe.h"

void menu();
void pl();

int main(int argc, char const *argv[])
{
	if(argc == 2) {
		char* fichier = (char*)argv[1];

		graphe_t* graphe;
		graphe = creerGraphe(fichier);

		if(graphe != NULL) {
			int choix = -1;
			int origine,
				affChemin = 1,
				arrivee,
				i;
			sommet_t* parcours;

			do {
				menu();
				if(scanf("%d", &choix) == EOF) printf("Erreur saisie...\n");

				switch(choix) {
					case 1:
						if(system("clear") == -1) printf("erreur système\n");
						printf("\n\n");
						afficherListesAdjacences(graphe);
						break;

					case 2:
						if(system("clear") == -1) printf("erreur système\n");
						printf("\n\n");
						afficherMatricesAdjacences(graphe);
						break;

					case 3:
						if(system("clear") == -1) printf("erreur système\n");
						printf("\n\n");
						
						do{
							printf("\tNuméro du sommet de départ du parcours en largeur : ");
							if(scanf("%d", &origine) == EOF) printf("Erreur saisie...\n");
						}while(origine < 0 || origine >= graphe->nSommets);

						parcours = parcoursEnLargeur(graphe, origine);

						while(affChemin != 0) {
							do{
								printf("\tPlus court chemin entre l'origine du parcours et un sommet. ");
								printf("Numéro du sommet ? ");
								if(scanf("%d", &arrivee) == EOF) printf("Erreur saisie...\n");
							}while(arrivee < 0 || arrivee >= graphe->nSommets);

							if(system("clear") == -1) printf("erreur système\n");

							printf("\n\n\n\n\t");
							printf("Plus court chemin entre l'origine %d et le sommet %d : \n\n", origine, arrivee);
							afficherChemin(parcours[origine], parcours[arrivee]);

							printf("\n\n\n\n\t");
							printf("Plus court chemin entre l'origine et chaque sommet du graphe : \n");
							for(i=0; i<graphe->nSommets; i++) {
								if(i!=origine) {
									printf("\n\tSommet %d : ", i);
									afficherChemin(parcours[origine], parcours[i]);
								}
							}

							printf("\n\n\t0 - Retour\n");
							printf("\t1 - Recommencer avec un autre sommet\n");
							printf("\n\n\tVotre choix : ");
							if(scanf("%d", &affChemin) == EOF) printf("Erreur saisie...\n");
						}
						affChemin = 1;
						break;

					case 4:
						if(system("clear") == -1) printf("erreur système\n");
						printf("Provoque un core dump..\n");
						break;
					default :
						break;
				}
			}while(choix != 0);
		}

		detruireGraphe(&graphe);
	}
	else {
		printf("\nUtilisez la commande : ./progGraphe fichier.txt\n\n");
	}

	printf("\n\nFin du programme.\n");
	return 0;
}

void menu() {
	printf("\n\n\n\t------------------\n\t------ Menu ------\n\t------------------\n");
	printf("\t1 - Affichage de la liste d'adjacence\n");
	printf("\t2 - Affichage de la matrice d'adjacence\n");
	printf("\t3 - Parcours en largeur\n");
	printf("\t4 - Parcours en profondeur\n");
	printf("\n");
	printf("\t0 - Quitter\n");

	printf("\n\n\tVotre choix : ");
}

