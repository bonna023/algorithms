#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "graphe.h"
#include "file.h"

file_t* creerFile(int taille) {
	file_t* file;
	file = (file_t*) malloc(sizeof(file_t));

	file->taille = 0;
	file->taille_max = taille;
	file->tete = NULL;
	file->queue = NULL;

	return file;
}

void detruireFile(file_t** file) {
	free(*file);
	*file = NULL;
}

bool fileVide(file_t* file) {
	if(file->taille == 0 || file->tete == NULL)
		return true;
	
	return false;
}

bool filePleine(file_t* file) {
	return (file->taille == file->taille_max);
}

void enfiler(file_t* file, sommet_t* sommet) {
	if(!filePleine(file)) {
		element_file_t* element;
		element = (element_file_t*) malloc(sizeof(element_file_t));
		element->sommet = sommet;

		element->suivant = file->tete;
		file->tete = element;

		if(fileVide(file))
			file->queue = element;

		file->taille++;
	}
}

sommet_t* defiler(file_t* file) {
	sommet_t* retour = NULL;
	if(!fileVide(file)) {
		retour = file->tete->sommet;
		file->tete = file->tete->suivant;
		file->taille--;
	}
	return retour;
}
