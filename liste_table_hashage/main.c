#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "outilsListe.h"
#include "outilsTableHachage.h"

void testListe();
void testListeFichier(char* fichierTexte);
void testTableHachage(char* fichierTexte);

int main(int argc, char const *argv[])
{
	if(argc == 2 && strcmp(argv[1], "liste") == 0) {
		testListe();
	}
	else if(argc == 3 && strcmp(argv[1], "listeFichier") == 0) {
		testListeFichier((char*)argv[2]);
	}
	else if(argc == 3 && strcmp(argv[1], "tableHachage") == 0) {
		testTableHachage((char*)argv[2]);
	}
	else {
		printf("Utilisation du programme.\n");
		printf("\t./main liste\n");
		printf("\t./main listeFichier texte1.txt\n");
		printf("\t./main tableHachage texte1.txt\n");
	}

	return 0;
}

void testListe() {
	int choix = 0, i;
	char* mot = (char*) malloc(sizeof(char)*50);
	liste_t* liste = creerListe();
	cellule_t* celluleTmp;

	printf("\nUne liste doublement chaînée est disponible.\n");

	for(i=0; i<100; i++)
		printf("\n");

	while(choix != -1) {
		printf("\n\t1 Afficher / 2 Insérer / 3 Rechercher / 4 Supprimer / -1 Quitter\n");
		printf("\n\tVotre choix : ");
		if(scanf("%d", &choix) == EOF) printf("Erreur saisie...\n");

		switch(choix) {
			case 1 :
				afficherListe(liste);
			break;

			case 2 :
				printf("\n\tVeuillez entrer un mot (50 caractères max) : ");
				if(scanf("%s", mot) == EOF) printf("Erreur saisie...\n");
				cellule_t* cellule = creerCellule(mot);
				insererListe(liste, cellule);
				afficherListe(liste);
			break;

			case 3 :
				printf("\n\tVeuillez entrer un mot (50 caractères max) : ");
				if(scanf("%s", mot) == EOF) printf("Erreur saisie...\n");
				celluleTmp = rechercherListe(liste, mot);
				
				if(celluleTmp != NULL)
					printf("\nLa liste contient le mot \"%s\"\n", celluleTmp->mot);
				else
					printf("\nLa liste ne contient pas le mot \"%s\"\n", mot);
			break;

			case 4 :
				printf("\n\tVeuillez entrer un mot (50 caractères max) : ");
				if(scanf("%s", mot) == EOF) printf("Erreur saisie...\n");
				supprimerListe(liste, (cellule_t*) rechercherListe(liste, mot));
				afficherListe(liste);
			break;
		}
	}

	detruireListe(&liste);
	printf("\nListe détruite, programme arrêté.\n\n");
}

void testListeFichier(char* fichierTexte) {
	FILE* fichier;
	liste_t* liste = creerListe();
	cellule_t* cellule;
	char motTmp[27];
	int nbMots = 0,
		nbMotsDiff = 0;
	clock_t t0, t1;
	
	t0 = clock();
	if((fichier = fopen(fichierTexte, "r")) != NULL) {
		while(fscanf(fichier, "%s", motTmp) != EOF) {
			nbMots++;
			if(rechercherListe(liste, motTmp) == NULL)	{
				cellule = creerCellule(motTmp);
				insererListe(liste, cellule);
				nbMotsDiff++;
			}	
		}
	}
	t1 = clock();

	printf("Le fichier contient %d mots différents (%d au total)\n", nbMotsDiff, nbMots);
	printf("Temps d'exécution de %.6f secondes\n", (float)(t1 - t0)/CLOCKS_PER_SEC);

	detruireListe(&liste);
	if(fclose(fichier) == EOF)
		printf("Erreur lors de la fermeture du fichier \"%s\"\n", fichierTexte);
}

void testTableHachage(char* fichierTexte) {
	FILE* fichier;
	tableHachage_t* tableH = creerTableHachage(11);
	cellule_t* celluleTmp;
	char mot[27];
	int nbMots = 0,
		nbMotsDiff = 0;
	clock_t t0, t1;

	t0 = clock();
	if((fichier = fopen(fichierTexte, "r")) != NULL) {
		while(fscanf(fichier, "%s", mot) != EOF) {
			nbMots++;
			if(rechercherHachage(tableH, mot) == NULL) {
				celluleTmp = creerCellule(mot);
				insererHachage(tableH, celluleTmp);
				nbMotsDiff++;
			}
		}
	}
	t1 = clock();

	printf("Le fichier contient %d mots différents (%d au total)\n", nbMotsDiff, nbMots);
	printf("Temps d'exécution de %.6f secondes\n", (float)(t1 - t0)/CLOCKS_PER_SEC);

	detruireTableHachage(&tableH);
	if(fclose(fichier) == EOF)	printf("Erreur lors de la fermeture du fichier \"%s\"\n", fichierTexte);
}
