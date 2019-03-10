#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <tgmath.h>

#include "outilsTableHachage.h"

void afficherTableHachage(tableHachage_t* tableH) {
	int i;
	cellule_t* celluleTmp;

	printf("Affichage table de hachage\n");
	printf("--------------------------\n");

	for(i=0; i<tableH->tailleTableH; i++) {
		celluleTmp = tableH->tabListes[i]->tete;

		printf("tableHachage (%d) ", i);
		
		if(celluleTmp != NULL) {
			do {
				printf("[%s] ", celluleTmp->mot);
				celluleTmp = celluleTmp->succ;
			}while(celluleTmp != NULL);
		}
		
		printf("\n");
	}

	printf("--------------------------\n");
}

int puissance(int base, int exposant)
{
	int res = 1, i;
	for(i = 0; i < exposant; i++)
		res*=base;
	return res;
}

int convertirChEntier(char* chaine)
{
	int res = 0,
		i = 0,
		tailleChaine = strlen(chaine);

	for(i = 0; i < tailleChaine; i++)
		res += chaine[i] * puissance(128, tailleChaine-i-1);

	return fabs(res);
}
