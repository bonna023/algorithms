#ifndef HANOI_H_
#define HANOI_H_

#include "pile.h"
#include "outilsPile.h"

typedef struct hanoi {
	pile_t** tours;
	int tailleTours;
} hanoi_t;

hanoi_t* creerHanoi(int tailleDesTours);
void detruireHanoi(hanoi_t** hanoi);

char *afficherDisque(char *chaine, int tailleTours, int valDisque);
void afficherHanoi(hanoi_t *hanoi);

void deplacerDisque(hanoi_t* hanoi, int tourDepart, int tourArrivee);
bool gagne(hanoi_t* hanoi);

#endif
