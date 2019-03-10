#ifndef LISTE_H_
#define LISTE_H_

#include "cellule.h"

typedef struct liste_t {
	struct cellule_t* tete;
}liste_t;

liste_t* creerListe();
void detruireListe(liste_t** liste);
void insererListe(liste_t* liste, cellule_t* cellule);
cellule_t* rechercherListe(liste_t* liste, char* mot);
void supprimerListe(liste_t* liste, cellule_t* cellule);

#endif
