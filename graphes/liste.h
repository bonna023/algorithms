#ifndef LISTE_H_
#define LISTE_H_

typedef struct element_liste_t {
	int numSommet;
	struct element_liste_t* pred;
	struct element_liste_t* succ;
}element_liste_t;

typedef struct liste_t {
	struct element_liste_t* tete;
}liste_t;

liste_t* creerListe();
void insererListe(liste_t* liste, struct element_liste_t* element); // insertion en fin de liste 
void detruireListe(liste_t** liste);

element_liste_t* creerElementListe(int numSommet);
void detruireElementListe(element_liste_t** element);

#endif
