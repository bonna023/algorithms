#ifndef PILE_H_
#define PILE_H_

#include <stdbool.h>

typedef struct {
	int capacite;
	int sommet;
	int* tab;
}pile_t;

// crée une pile vide de capacité maximale fixe en allouant la mémoire nécessaire
pile_t* creerPile(int capacite);

// détruit une pile en libérant ses ressources mémoires
void detruirePile(pile_t** pile);

// retourne la capacité maximale d'une pile (ne pas confondre avec la taille de la pile)
int capacitePile(pile_t* pile);

// retourne VRAI si la pile est vide, FAUX sinon
bool pileVide(pile_t* pile);

// retourne VRAI si la pile est pleine, FAUX sinon
bool pilePleine(pile_t* pile);

// ajoute un élément au sommet de la pile s'il reste de la place 
bool empiler(pile_t* pile, int val);

// retire l'élément du sommet de la pile s'il existe et retourne sa valeur
int depiler(pile_t* pile);

// retourne la valeur de l'élément du sommet de la pile sans modifier ce dernier
int sommetPile(pile_t* pile);

#endif
