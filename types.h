#ifndef TYPES_H_
#define TYPES_H_

typedef struct
{
	int longueur;	// longueur total du tableau
	int taille;		// nombre de valeurs effectives rangées dans le tableau
	int* tableau;	// tableau d'entiers
	char** taches;	// tableau des taches
}t_tas;

typedef struct
{
	int longueur;
	int taille;
	void** pointeurs;	//tableau de pointeurs
}t_tas_p;

#endif
