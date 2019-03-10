#ifndef CELLULE_H_
#define CELLULE_H_

typedef struct cellule_t {
	char* mot;
	struct cellule_t* pred;
	struct cellule_t* succ;
}cellule_t;

// alloue la mémoire pour une cellule, l'initialise avec un mot passé en paramètre
cellule_t* creerCellule(char* mot);

// libère la mémoire alloué à la création de la cellule
void detruireCellule(cellule_t** cellule);

#endif
