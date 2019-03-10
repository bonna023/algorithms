#ifndef ARBRE_H_
#define ARBRE_H_

#include "noeud.h"

// arbre binaire de recherche
typedef struct arbre_t {
	struct noeud_t* racine;
}arbre_t;

// crée un arbre vide
arbre_t* creerArbre();

// détruit un arbre en libérant ses ressources mémoires
void detruireArbre(arbre_t* arbre);

// prend en paramètre un pointeur sur un noeud et insère ce noeud au bon endroit dans l'arbre
void insererArbre(arbre_t* arbre, noeud_t* noeud);

// recherche un mot dans un arbre et retourne soit un pointeur sur le noeud qui contient le mot soit NULL
noeud_t* rechercherArbreIteratif(arbre_t* arbre, char* mot);

// prend en paramètre un pointeur sur un noeud d'un arbre et supprime ce noeud de l'arbre
void supprimerArbre(arbre_t* T, noeud_t* noeud);

#endif
