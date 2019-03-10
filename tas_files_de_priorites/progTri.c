#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "util.h"
#include "tri.h"
#include "tas.h"

int main(int argc, char const *argv[])
{
// EXERCICE 1
	FILE* f_donneesTab1 = NULL;
	int i = 0,			// boucle for
		longueur = 0,		// longueur des tableaux (EXERCICE 1)
		t = 0,			// longueur entree par l'utilisateur
		recommencer = 0;

	// (1) ouverture du fichier
	f_donneesTab1 = fopen("donneesTab1.txt", "r+");
	
	// lecture du nombre de valeurs presentent dans le fichier
	if(fscanf(f_donneesTab1,"%d",&longueur) == EOF)
		printf("Erreur lecture\n");
	
	int tab_insertion[longueur];
	
	t_tas* tas;
	tas = initTas(longueur);

	// recuperation des valeurs du fichier dans les tableaux
	// ainsi que dans la structure de tas t_tas
	if(f_donneesTab1 != NULL)
	{
		for(i=0; i<longueur; i++)
		{
			if(fscanf(f_donneesTab1,"%d",&tas->tableau[i]) == EOF)
				printf("Erreur lecture\n");
			tab_insertion[i] = tas->tableau[i];
		}
		fclose(f_donneesTab1);
	}
	else {
		printf("Erreur lors de l'ouverture du fichier\n");
	}

	// affichage du tableau d'origine (avant l'appel des fonctions de tri)
	printf("EXERCICE 1\nTableau origine :\n");
	afficherTableauEntier(tab_insertion, longueur);

	// (2) affichage du premier tableau aprés l'appel de "triParInsertion"
	printf("Tableau après tri par insertion :\n");
	triParInsertion(tab_insertion, longueur);
	afficherTableauEntier(tab_insertion, longueur);

	// (3) affichage du second tableau après l'appel de "triParTas"
	printf("Tableau après tri par tas :\n");
	triParTas(tas);
	afficherTableauEntier(tas->tableau, tas->longueur);

	// (4)
	// Mesure du temps d'éxecution des tris par Tas et par Insertion
	do
	{
		printf("\nEntrez longueur du tableau : ");
		if(scanf("%d", &t) == EOF)
			printf("Erreur saisie\n");
		int tab1[t];
		t_tas* tas2;
		tas2 = initTas(t);
		remplirTableauAleatoire(tab1, t);
		copierTableau(tab1, tas2->tableau, t);

		clock_t t0_ins, t1_ins, t0_tas, t1_tas;

		t0_ins = clock();			// debut mesure par Insertion
		triParInsertion(tab1, t);	// éxecution...
		t1_ins = clock();			// fin mesure par Insertion
		printf("\nTemps du tri par insertion :\t %.6f secondes\n", (float)(t1_ins - t0_ins)/CLOCKS_PER_SEC);
		
		t0_tas = clock();	// debut mesure par Tas
		triParTas(tas2);	// éxecution...
		t1_tas = clock();	// fin mesure par Tas
		printf("Temps du tri par tas :\t\t %.6f secondes\n", (float)(t1_tas - t0_tas)/CLOCKS_PER_SEC);

		printf("\nRecommencer ? (0 ou 1) : ");
		if(scanf("%d", &recommencer) == EOF)
			printf("Erreur saisie\n");
	} while(recommencer == 1);

// EXERCICE 2
	printf("\nEXERCICE 2\n");

	FILE* f_listeTaches1 = NULL;
	int nbTaches = 0,	// nombres de taches dans le fichier (EXERCICE 2)
		ii = 0;			// boucle for
	//char test[100];		// chaine de caractere (TACHE)

	f_listeTaches1 = fopen("listeTaches1.txt", "r+");

	if(fscanf(f_listeTaches1,"%d",&nbTaches) == EOF)
		printf("Erreur lecture\n");

	t_tas* fileP;
	fileP = initTas(nbTaches);

	// creation de la file de priorites à partir des donnees du fichier
	for(ii = 0; ii < nbTaches; ii++) {
		if(fscanf(f_listeTaches1, "%s %d", fileP->taches[ii], &fileP->tableau[ii]) == EOF)
			printf("Erreur lecture.\n");
		fileP->longueur++;
	}
	fclose(f_listeTaches1);

	// affichage de la File de priorités non triée
	printf("\nFile de priorités construite à partir du fichier :\n");
	afficherFilePriorite(fileP);

	// tri de la File de priorités et affichage
	printf("\nFile de priorités triée sous forme de \"TAS MAX\" :\n");
	construireTasMax(fileP);
	// triParTas(fileP);
	afficherFilePriorite(fileP);

	// MAXIMUM TAS
	printf("Clé de plus haute priorité :\n\t%d\n", maximumTas(fileP));

	// extraction de la tache prioritaire et affichage
	printf("\nExtraction de la tache prioritaire : \n");
	int cleTachePrio = 0;
	char* descTachePrio = "";

	extraireMaxTas(fileP, &cleTachePrio, &descTachePrio);
	printf("\n\tTache prioritaire extraite : [%d] %s\n\n", cleTachePrio, descTachePrio);
	afficherFilePriorite(fileP);
	
	// insertion d'une nouvelle tache
	printf("Ajout d'une nouvelle tache à la file de priorité : ([30] faire_une_sieste)\n");
	insererTasMax(fileP, 30, "faire_une_sieste");
	afficherFilePriorite(fileP);

	// changement priorité d'une tache
	printf("Changement de priorité de la tache \"Dormir\" : \n");
	int indice_tache = 0;
	while(indice_tache <= fileP->taille) {
		if(strcmp("Dormir", fileP->taches[indice_tache]) == 0) {
			augmenterCleTas(fileP, indice_tache, 12);
			indice_tache = fileP->taille;
		}
		indice_tache++;
	}
	afficherFilePriorite(fileP);

// insertion d'une nouvelle tache
	printf("Ajout d'une nouvelle tache à la file de priorité : ([1] Embeter_mon_binome)\n");
	insererTasMax(fileP, 1, "Embeter_mon_binome");
	afficherFilePriorite(fileP);	

// Tri par fusion
	

	return EXIT_SUCCESS;
}
