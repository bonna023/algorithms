#ifndef FILE_H_
#define FILE_H_

#include <stdbool.h>
#include "graphe.h"
#include "pl.h"

typedef struct element_file_t {
	struct sommet_t* sommet;
	struct element_file_t* suivant;
}element_file_t;

typedef struct file_t {
	int taille; 					// taille courante de la file
	int taille_max;					// taille maximale de la file
	struct element_file_t* tete;	// pointeur sur le premier élément 
	struct element_file_t* queue;	// pointeur sur le dernier élément  
} file_t;

file_t* creerFile(int taille);
void detruireFile(file_t** file);
bool fileVide(file_t* file);
bool filePleine(file_t* file);
void enfiler(file_t* file, sommet_t* sommet);
sommet_t* defiler(file_t* file);

#endif
