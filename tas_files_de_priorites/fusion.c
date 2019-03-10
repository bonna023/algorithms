#include <stdio.h>
#include <stdlib.h>
#include "fusion.h"

void fusion(int* tab, int taille, int p, int q, int r) {
	int i, j, k;

	// calcul de la longueur des sous tableaux
	int long_ss_tab_1 = q-p+1,
		long_ss_tab_2 = r-q;

	// création des sous tableaux
	int sous_tab_1[long_ss_tab_1+1];
	int sous_tab_2[long_ss_tab_2+1];

	// copie du premier sous tableau
	for(i=1; i<long_ss_tab_1; i++) {
		sous_tab_1[i] = tab[p+i-1];
	}

	// copie du second sous tableau
	for(j=1; j<long_ss_tab_2; j++) {
		sous_tab_2[j] = tab[q+j];
	}

	// à revoir !!!!
	sous_tab_1[long_ss_tab_1+1] = -1;
	sous_tab_2[long_ss_tab_2+1] = -1;

	i = 1;
	j = 1;

	for(k=p; k<r; k++) {
		if(sous_tab_1[i] <= sous_tab_2[i]) {
			tab[k] = sous_tab_1[i];
			i++;
		}
		else {
			tab[k] = sous_tab_2[j];
			j++;
		}
	}
}
