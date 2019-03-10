#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "outilsArbre.h"

/* ---- TODO ----
 - afficherArbreIteratif
 - un programme de test correct
*/


int main(int argc, char const *argv[])
{
	// test des structures neoud et arbres
	noeud_t *noeud1, *noeud6, *noeud5, *noeud2, *noeud3, *noeud4, *noeud7, *noeud8;//, *noeud_rech;
	arbre_t *arbre;

	noeud1 = creerNoeud("bobard");
	noeud2 = creerNoeud("bobo");
	noeud3 = creerNoeud("gogo");
	noeud4 = creerNoeud("toto");
	noeud5 = creerNoeud("bea");
	noeud6 = creerNoeud("alo");
	noeud7 = creerNoeud("tata");
	noeud8 = creerNoeud("gogo");

	arbre = creerArbre();

	insererArbre(arbre, noeud2);
	insererArbre(arbre, noeud4);
	insererArbre(arbre, noeud3);
	insererArbre(arbre, noeud7);
	insererArbre(arbre, noeud6);
	insererArbre(arbre, noeud8);
	insererArbre(arbre, noeud1);
	insererArbre(arbre, noeud5);
	// printf("\n -> test\n\n");

	//afficherArbreIteratif(arbre);
	afficherArbreRecurssif(arbre->racine);

	// test rechercher et supprimer
	// if((noeud_rech = rechercherArbreIteratif(arbre, "bea")) != NULL) {
	// 	printf("Mot trouvé ! \t-> %s\n", noeud_rech->mot);
	// 	printf("On va le supprimer...\n");
	// 	supprimerArbre(arbre, noeud6);
	// 	supprimerArbre(arbre, noeud_rech);
	// 	if((noeud_rech = rechercherArbreIteratif(arbre, "bea")) != NULL)
	// 		printf("Mot pas supprimé... \t(%s)\n", noeud_rech->mot);
	// 	else
	// 		printf("Mot bien supprimé !\n");
	// }
	// else {
	// 	printf("Mot non trouvé ! \n");
	// }

	detruireArbre(arbre);
	
	return 0;
}
