#include <stdio.h>
#include <stdlib.h>

#include "tri.h"
#include "util.h"

void triParInsertion(int tab[], int taille)
{
	int i=0, j=0, cle=0;

	for (j=1; j < taille; j++)
	{
		cle = tab[j];
		i = j-1;
		while(i>=0 && tab[i] > cle)
		{
			tab[i+1] = tab[i];
			i = i-1;
		}
		tab[i+1] = cle;
	}	
}

void triParTas(t_tas* tas)
{
	int i = 0;
	int tailleOrigine = tas->taille;

	construireTasMax(tas);
	
	for(i = tas->taille; i > 1; i--)
	{
		echanger(tas, 0, i-1);
		tas->taille--;
		entasserMax(tas, 0);
	}
	// réafecte la bonne taille au tas
	tas->taille = tailleOrigine;
}

//void triParFusion();
