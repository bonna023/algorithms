#ifndef OUTILSARBRE_H_
#define OUTILSARBRE_H_

#include "arbre.h"

// permet de déplacer des sous-arbre dans l'arbre binaire de recherche
void transplanter(arbre_t* T, noeud_t* u, noeud_t* v);

// retourne le noeud ayant la plus petite clé à partir d'un noeud donné, ce noeud se trouve le plus à gauche dans l'arbre
noeud_t* minimumArbre(noeud_t* noeud);

// affiche l'arbre de manière itérative
void afficherArbreIteratif(arbre_t* arbre);

// affiche l'arbre de manière recurssive
void afficherArbreRecurssif(noeud_t* racine);

#endif
